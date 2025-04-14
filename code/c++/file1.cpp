
// program to write string "Hello World" to a file named file1.out
// written: fmk

#include <fstream>
using namespace std;
int main(void)
{
  ofstream outFile("file1.out", ios::out);
  outFile << "Hello World\n";
  outFile.close();
  return 0;
}


