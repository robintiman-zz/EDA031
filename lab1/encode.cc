#include <iostream>
#include <fstream>
#include "coding.cc"
#include <string>

using namespace std;
int main()  {
  char c;
  ifstream inputFile;
  ofstream outputFile ("out.txt");
  inputFile.open("example.txt");
    while (inputFile) {
      inputFile.get(c);
      outputFile << coding::encode(c);
    }
}
