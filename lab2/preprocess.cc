#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Preprocess {
public:
    vector<string> get_trigrams(string line);
};

vector<string> Preprocess::get_trigrams(string line) {
    vector<string> trigrams;
    string trigram;
    if (line.length() <= 3) {
      trigrams.push_back(line);
    } else {
      for (unsigned i = 0; i < line.length() - 2; ++i) {
        trigram = line.substr(i, 3);
        trigrams.push_back(trigram);
      }
      sort(trigrams.begin(), trigrams.end());
    }
    return trigrams;
}


int main() {
    ofstream out;
    Preprocess pp;
    out.open ("words.txt");
    string line;
    ifstream words ("words");
    vector<string> trigrams;
    if (out.is_open() && words.is_open()) {
        while (getline (words, line)) {
          transform(line.begin(), line.end(), line.begin(), ::tolower);
          trigrams = pp.get_trigrams(line);
          out << line << " " << trigrams.size() << " ";
          for (unsigned i = 0; i != trigrams.size(); ++i) {
            out << trigrams.at(i) << " ";
          }
          out << "\n";
        }
        out.close();
        words.close();
    }

}
