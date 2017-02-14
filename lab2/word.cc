#include "word.h"
#include <string>
#include <vector>

using namespace std;

Word::Word(const string &w, const vector<string> &t) {
  word = w;
  trigrams = t;
}

string Word::get_word() const { return word; }

unsigned int Word::get_matches(const vector<string> &t) const {
  int matches = 0;
  int param_count, local_count = 0;
  while (param_count != t.size() && local_count != trigrams.size()) {
    string local_t = trigrams.at(i);
    string param_t = t.at(j);
    if (local_t == param_t) {
      ++matches;
      ++local_count;
      ++param_count;
    } else if (local_t > param_t) {
      ++local_count;
    } else {
      ++param_count;
    }
  }
  return matches;
}
