#ifndef PROCESSOR_H
#define PROCESSOR_H

#include "Operation.h"

#include <string>
#include <vector>
#include <thread>
#include <mutex>
#include <memory>

class Processor {
public:
    explicit Processor(const std::string& dirPath);

    void process();
    double getTotalResult();

private:
    std::string directoryPath;
    std::vector<double> results;

    mutable std::mutex resultMutex;
    mutable double totalResult  = 0.0;
    mutable bool resultComputed = false;

private:
    std::vector<std::string> findInputFiles() const;
    static double processFile(const std::string& filename);
    static std::unique_ptr<Operation> createOperation(int opCode);
};

#endif // PROCESSOR_H
