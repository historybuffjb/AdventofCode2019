#include "fuel_requirements.h"
#include <fstream>
#include <iostream>
#include <math.h>


FuelRequirements::FuelRequirements(std::string storagePath) {
   path = storagePath; 
}

int FuelRequirements::calculateIndividualModule(int moduleSize) {
    int result = 0;
    do {
        moduleSize = floor(moduleSize / 3 - 2);
        result += moduleSize;
    } while (floor(moduleSize / 3 - 2) > 0);
    return result;
}

int FuelRequirements::calculateTotalRequirements() {
    std::ifstream moduleFile;
    std::string moduleSize;
    int result = 0;
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
