#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

int main(int argc, char **argv) {
    if (argc != 3) {
        std::cerr << "ERROR: Correct usage appName n maxVal" << std::endl;
        return -1;
    }

    int n = std::atoi(argv[1]);
    float maxVal = std::atof(argv[2]);
    float *theVector = new float[n];

    std::ofstream fileBinaryPtr("file4.out", std::ios::binary);
    std::ofstream fileAsciiPtr("file4Ascii.out");

    if (!fileBinaryPtr || !fileAsciiPtr) {
        std::cerr << "ERROR: Unable to open file" << std::endl;
        delete[] theVector;
        return -1;
    }

    std::srand(100);
    // std::srand(static_cast<unsigned int>(std::time(0))); // the usual way to call srand
    std::rand(); // i like to call it once

    for (int i = 0; i < n; ++i) {
        theVector[i] = (static_cast<float>(std::rand()) / static_cast<float>(RAND_MAX)) * maxVal;
    }

    // Write them one at a time to the ascii file
    for (int i = 0; i < n; ++i) {
        fileAsciiPtr << theVector[i] << " ";
    }
    fileAsciiPtr << std::endl;

    // Write the array to the binary file in a single call
    fileBinaryPtr.write((char *)theVector, n * sizeof(float));

    fileBinaryPtr.close();
    fileAsciiPtr.close();
    delete[] theVector;

    return 0;
}
