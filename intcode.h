#include <vector>

class Intcode {
    private:
        std::vector<int> currentProgram;
        bool calculateProgramRow(int);
        void calculateAddition(int);
        void calculateMultiplication(int);

    public:
        Intcode(std::vector<int>);
        std::vector<int> resetProgram(int, int);
};
