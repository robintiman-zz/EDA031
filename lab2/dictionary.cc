#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include "dictionary.h"
#include <unordered_set>

using namespace std;

Dictionary::Dictionary() {
	ifstream word_stream ("words.txt");
	string word_str, line;
	vector<string> trigrams;
	int pos, nbr_of_trigrams, word_size;
	size_t pos_after_nbr;
	while (getline(word_stream, line) && word_stream.is_open()) {
		// Need trigrams and word from words.txt
		pos = line.find_first_of(" ");
		word_str = line.substr(0, pos);
		nbr_of_trigrams = stoi(line.substr(pos + 1, 2), &pos_after_nbr);
		for (int i = 0; i < nbr_of_trigrams; ++i) {
			trigrams.push_back(line.substr(pos_after_nbr + i * 3 + 1, 3));
		}
		word_set.insert(word_str);
		word_size = word_str.size();
		if (word_size < max_word_length) {
			Word w (word_str, trigrams);
			words[word_size].push_back(w);
		}
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

void Dictionary::add_trigram_suggestions(vector<string>& suggestions, const string& word) const{
	int word_size = word.size();
	for (int i = word_size - 1; i <= word_size + 1; ++i) {
		suggestions.insert(suggestions.end(), words[i].begin(), words[i].end());
	}

}
