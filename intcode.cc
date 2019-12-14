#include "intcode.h"
#include <iostream>


Intcode::Intcode(std::vector<int> vec) {
    currentProgram = vec;
}

bool Intcode::calculateProgramRow(int index) {
    int startRow = currentProgram[index];
    if (startRow == 99) {
        return false;
    } else if (startRow == 1) {
        calculateAddition(index);
    } else if (startRow == 2) {
        calculateMultiplication(index);
    } else {
        std::cout << "An error has occured that is unrecoverable" << std::endl;
        return false;
    }
    return true;
}

void Intcode::calculateAddition(int index) {
    int resultIndex = currentProgram[index + 3];
    int leftIndex = currentProgram[index + 1];
    int rightIndex = currentProgram[index + 2];
    currentProgram[resultIndex] = currentProgram[leftIndex] + currentProgram[rightIndex];
}

void Intcode::calculateMultiplication(int index) {
    int resultIndex = currentProgram[index + 3];
    int leftIndex = currentProgram[index + 1];
    int rightIndex = currentProgram[index + 2];
    currentProgram[resultIndex] = currentProgram[leftIndex] * currentProgram[rightIndex];
}

std::vector<int> Intcode::resetProgram() {
    currentProgram[1] = 12;
    currentProgram[2] = 2;
    int index = 0;
    while (index < currentProgram.size()) {
       bool result = calculateProgramRow(index);
       if (!result)
           break;
       index += 4;
    }
    return currentProgram; 
}
