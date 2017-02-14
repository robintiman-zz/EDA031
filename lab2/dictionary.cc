#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include "word.h"
#include "dictionary.h"
#include <unordered_set>

using namespace std;

Dictionary::Dictionary() {
	const int max_word_length = 25;
	vector<Word> words[max_word_length];
	ifstream word_stream ("words.txt");
	string word_str, line;
	vector<string> trigrams;
	int pos, nbr_of_trigrams;
	string::size_type pos_after_nbr;
	while (getline(word_stream, line) && word_stream.is_open()) {
		// Need trigrams and word from words.txt
		pos = line.find(" ");
		word_str = line.substr(0, pos - 1);
		nbr_of_trigrams = stoi(line.substr(pos + 1, 2), &pos_after_nbr);
		for (int i = 0; i < nbr_of_trigrams; ++i) {
			trigrams.push_back(line.substr(pos_after_nbr + i * 3 + 1, 3));
		}
		words[word_str.length()] =

		word_set.insert(word_str);
	}
	word_stream.close();
}

bool Dictionary::contains(const string& word) const {
	int found = word_set.count(word);
	return found == 1;
}

vector<string> Dictionary::get_suggestions(const string& word) const {
	vector<string> suggestions;
//	add_trigram_suggestions(suggestions, word);
//	rank_suggestions(suggestions, word);
//	trim_suggestions(suggestions);
	return suggestions;
}
