#include "Processor.h"
#include "Operation.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <filesystem>
#include <thread>
#include <cctype>
#include <algorithm>

namespace fs = std::filesystem;

bool isValidInputFilename(const std::string& name) {
    if (name.size() < 8 || name.substr(0, 3) != "in_" || name.substr(name.size() - 4) != ".dat")
        return false;

    std::string numPart = name.substr(3, name.size() - 7);
    if (numPart.empty())
        return false;

    if (numPart[0] == '0' && numPart.size() > 1)
        return false;

    return std::all_of(numPart.begin(), numPart.end(), ::isdigit);
}

std::vector<std::string> Processor::findInputFiles() const {
    std::vector<std::string> files;
    try {
        for (const auto& entry : fs::directory_iterator(directoryPath)) {
            if (entry.is_regular_file()) {
                std::string name = entry.path().filename().string();
                if (isValidInputFilename(name)) {
                    files.push_back(entry.path().string());
                }
            }
        }
    } catch (const fs::filesystem_error& e) {
        std::cerr << "Error reading directory: " << e.what() << std::endl;
    }
    return files;
}

std::unique_ptr<Operation> Processor::createOperation(int opCode) {
    switch (opCode) {
        case 1: return std::make_unique<Addition>();
        case 2: return std::make_unique<Multiplication>();
        case 3: return std::make_unique<SumOfSquares>();
        default: return nullptr;
    }
}

double Processor::processFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Couldn't open file: " << filename << std::endl;
        return 0.0;
    }

    int opCode;
    if (!(file >> opCode)) {
        std::cerr << "Invalid operation code in file: " << filename << std::endl;
        return 0.0;
    }

    file.ignore();

    std::string numbersLine;
    if (!std::getline(file, numbersLine)) {
        std::cerr << "Missing or invalid second line in file: " << filename << std::endl;
        return 0.0;
    }

    std::istringstream iss(numbersLine);
    std::vector<double> numbers;

    double num;
    while (iss >> num) {
        numbers.push_back(num);
    }

    if (numbers.empty()) {
        std::cerr << "No numbers provided in file: " << filename << std::endl;
        return 0.0;
    }

    auto operation = createOperation(opCode);
    if (!operation) {
        std::cerr << "Unknown operation code (" << opCode << ") in file: " << filename << std::endl;
        return 0.0;
    }

    return operation->execute(numbers);
}

Processor::Processor(const std::string& dirPath) : directoryPath(dirPath) {
}

void Processor::process() {
    auto files = findInputFiles();

    std::vector<std::thread> threads;
    threads.reserve(files.size());

    for (const auto& file : files) {
        threads.emplace_back([this, file]() {
            double result = processFile(file);
            {
                std::lock_guard<std::mutex> lock(resultMutex);
                results.push_back(result);
            }
        });
    }

    for (auto& t : threads) {
        if (t.joinable()) {
            t.join();
        }
    }
}

double Processor::getTotalResult() {
    if (!resultComputed) {
        totalResult = 0.0;
        for (double r : results) {
            totalResult += r;
        }
        resultComputed = true;
    }
    return totalResult;
}
