#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

void parse_meminfo() {
    std::ifstream meminfo("/proc/meminfo");
    std::string line;
    long total = 0, free = 0, available = 0;

    while (std::getline(meminfo, line)) {
        std::istringstream iss(line);
        std::string key;
        long value;
        std::string unit;

        iss >> key >> value >> unit;

        if (key == "MemTotal:") total = value;
        else if (key == "MemFree:") free = value;
        else if (key == "MemAvailable:") available = value;
    }

    std::cout << "Memory Statistics (in KB):" << std::endl;
    std::cout << "--------------------------" << std::endl;
    std::cout << "Total:     " << total << " KB" << std::endl;
    std::cout << "Free:      " << free << " KB" << std::endl;
    std::cout << "Available: " << available << " KB" << std::endl;
}

int main() {
    parse_meminfo();
    return 0;
}