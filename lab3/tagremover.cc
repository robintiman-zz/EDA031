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
  string line;
  smatch match;
  // cin >> file;
  ifstream file ("test.html");
  // Will match everything we want
  regex reg ("<|>|&\\w*");
  while (getline(file, line)) {
    for (auto i = sregex_iterator(line.begin(), line.end(), reg); i != sregex_iterator(); ++i) {
      auto item = i->str();
      auto index = i->position();
      // For some reason it only matches every other of the special chars.
      // That's not how regex work. I blame c++
      if (item == "<") {
        line.replace(index, 1, "");
      } else if (item == ">") {
        line.replace(index, 1, "");
      } else if (item == "&lt") {
        line.replace(index, 3, "<");
      } else if (item == "&gt") {
        line.replace(index, 3, ">");
      } else if (item == "&nbsp") {
        line.replace(index, 5, " ");
      } else if (item == "&amp") {
        line.replace(index, 4, "&");
      }
    }
    parsed += line + "\n";
  }
  std::cout << parsed << endl;
}

int main() {
  TagRemover tr(cin);
}
