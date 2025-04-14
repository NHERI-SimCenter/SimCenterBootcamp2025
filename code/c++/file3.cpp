#include <iostream>
#include <fstream>
#include <cstdlib>

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "ERROR: Correct usage appName inputFile" << std::endl;
        return -1;
    }

    std::ifstream inFile(argv[1]);
    if (!inFile) {
        std::cerr << "ERROR: Unable to open file" << std::endl;
        return -1;
    }

    int i = 0;
    float float1, float2;
    int maxVectorSize = 100;
    double *vector1 = new double[maxVectorSize];
    double *vector2 = new double[maxVectorSize];
    int vectorSize = 0;

    while (inFile >> i >> std::ws && inFile.get() == ',' && inFile >> float1 >> std::ws && inFile.get() == ',' && inFile >> float2) {
        vector1[vectorSize] = float1;
        vector2[vectorSize] = float2;
        std::cout << i << ", " << vector2[vectorSize] << ", " << vector1[vectorSize] << std::endl;
        vectorSize++;

        if (vectorSize == maxVectorSize) {
            // some code needed here .. programming exercise
        }
    }

    inFile.close();
    delete[] vector1;
    delete[] vector2;

    return 0;
}
