#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

int main(int argc, char **argv) {
    if (argc != 4) {
        std::cerr << "ERROR: Correct usage appName n maxVal outputFile" << std::endl;
        return -1;
    }

    int n = std::atoi(argv[1]);
    float maxVal = std::atof(argv[2]);

    std::ofstream outFile(argv[3]);
    if (!outFile) {
        std::cerr << "ERROR: Unable to open file" << std::endl;
        return -1;
    }

    std::srand(100);
    // std::srand(static_cast<unsigned int>(std::time(0))); // the usual way to call srand
    std::rand(); // i like to call it once

    for (int i = 0; i < n; ++i) {
        float float1 = (static_cast<float>(std::rand()) / static_cast<float>(RAND_MAX)) * maxVal;
        float float2 = (static_cast<float>(std::rand()) / static_cast<float>(RAND_MAX)) * maxVal;
        outFile << i << ", " << float1 << ", " << float2 << std::endl;
    }

    outFile.close();

    return 0;
}
