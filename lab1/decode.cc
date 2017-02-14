#include <iostream>
#include <fstream>
#include "coding.cc"
#include <string>

using namespace std;
int main()  {
  char c;
  ifstream inputFile;
  ofstream outputFile ("out2.txt");
  inputFile.open("out.txt");
    while (inputFile) {
      inputFile.get(c);
      outputFile << coding::decode(c);
    }
}
