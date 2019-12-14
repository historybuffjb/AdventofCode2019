#include "fuel_requirements.h"
#include <fstream>
#include <iostream>
#include <math.h>


FuelRequirements::FuelRequirements(std::string storagePath) {
   path = storagePath; 
}

int FuelRequirements::calculateIndividualModule(int module_size) {
    return floor(module_size/3 - 2);
}

int FuelRequirements::calculateTotalRequirements() {
    std::ifstream moduleFile;
    std::string moduleSize;
    int result;
    moduleFile.open(path);
    if (moduleFile.is_open()) {
        while (getline(moduleFile, moduleSize)) {
            if (moduleSize != "")
                result += calculateIndividualModule(std::stoi(moduleSize)); 
        }
    } else {
        std::cout << "Failed to open file for reading" << std::endl;
        return -1;
    }
    return result;
}
