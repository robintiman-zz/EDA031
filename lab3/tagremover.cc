#include <iostream>
#include <fstream>
#include <ostream>
#include <string>
#include <regex>

using namespace std;

// Removes tags from HTML code
class TagRemover {
public:
  TagRemover(std::istream& cin);
  std::string print(std::ostream& cout);
private:
  std::string parsed;
};

TagRemover::TagRemover (istream& cin) {
  string line, tmp_line;
  smatch match;
  // cin >> file;
  ifstream file ("test.html");
  // Will match everything we want
  regex reg ("<|>|&lt|&gt|&nbsp|&amp");
  std::cerr << "/* error message */" << '\n';
  while (getline(file, line)) {
    for (auto i = sregex_iterator(line.begin(), line.end(), reg); i != sregex_iterator(); ++i) {
      auto index = i->position();
      std::cout << line[index] << '\n';
      switch (line[index]) {
        case '<': line[index] = (char) 0;
        case '>': line[index] = (char) 0;
        case '&': std::cout << "när" << '\n';
      }
    }
    parsed += line;
    // while (regex_search(line, match, reg)) {
    //   for (auto m:match) cout << m << '\n';
    //
    // }
  }
  std::cout << parsed << '\n';
}

int main() {
  TagRemover tr(cin);
}
