#include "Processor.h"

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <directory_path>" << std::endl;
        return 1;
    }

    std::string dirPath = argv[1];

    Processor processor(dirPath);
    processor.process();
    double total = processor.getTotalResult();

    std::ofstream outFile("out.dat");
    if (!outFile.is_open()) {
        std::cerr << "Couldn't create file: out.dat" << std::endl;
        return 1;
    }

    outFile << std::fixed << std::setprecision(10) << total << std::endl;
    outFile.close();

    std::cout << "The result is recorded in: out.dat" << std::endl;
    return 0;
}
