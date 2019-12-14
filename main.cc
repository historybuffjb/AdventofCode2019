#include <iostream>
#include <string>
#include "fuel_requirements.h"

int main () {
    std::string inputFile = "input.txt";
    FuelRequirements* sleigh = new FuelRequirements(inputFile);
    int result = sleigh->calculateTotalRequirements(); 
    std::cout << "Result is: " << result << std::endl; 
    delete sleigh;
}
