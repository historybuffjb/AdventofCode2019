#include <string>


class FuelRequirements {
    private:
        std::string path;
        int calculateIndividualModule(int n);

    public:
        FuelRequirements(std::string);
        int calculateTotalRequirements();

};
