#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include "dictionary.h"
#include "word.h"
#include <unordered_set>

using namespace std;

Dictionary::Dictionary() {
	ifstream input ("words.txt");
	int nbr_of_trigrams;
	if(input) {
		string word;
		while(input >> word) {
		  word_set.insert(word);
			input >> nbr_of_trigrams;
			vector<string> trigrams;
			for (int i = 0; i < nbr_of_trigrams; ++i) {
				string trigram;
				input >> trigram;
				trigrams.push_back(trigram);
			}
			if (word.size() <= max_word_length) {
				words[word.size()].push_back(Word(word, trigrams));
			}
		}
	} else {
		cout << "No file available";
	}
}

bool Dictionary::contains(const string& word) const {
	int found = word_set.count(word);
	return found == 1;
}

vector<string> Dictionary::get_suggestions(const string& word) const {
	vector<string> suggestions;
	add_trigram_suggestions(suggestions, word);
	rank_suggestions(suggestions, word);
	trim_suggestions(suggestions);
	return suggestions;
}

void Dictionary::rank_suggestions(vector<string>& suggestions, const string& word) const {
	vector<string> ranked_suggestions[max_word_length + max_word_length + 1];

	// Initializing matrix
	int d [max_word_length + 1][max_word_length + 1];
	for(unsigned int i = 0; i < max_word_length + 1; ++i) {
		d[i][0] = i;
		d[0][i] = i;
	}

	// Calculate Levenshtein distance for each suggestion
	for(auto w : suggestions) {
	  // cout << w << endl;
		for(size_t j = 1; j < w.size() + 1; ++j) {
			for(size_t i = 1; i < word.size() + 1; ++i) {
				int value = min(d[i - 1][j] + 1, d[i][j - 1] + 1);
				if(w.at(j - 1) == word.at(i - 1)) {
					value = min(value, d[i - 1][j - 1]);
				}
				else {
					value = min(value, d[i - 1][j - 1] + 1);
				}
				d[i][j] = value;
			}
		}
		int distance = d[word.size()][w.size()];
		ranked_suggestions[distance].push_back(w);

		// Remove empty elements
		vector<string> temp;
		for (vector<string> word_list : ranked_suggestions) {
			// Thought shrink_to_fit() would do the trick here but it didn't
			if (!word_list.empty()) {
				temp.insert(temp.end(), word_list.begin(), word_list.end());
			}
		}
		suggestions.swap(temp);
	}
}

void Dictionary::trim_suggestions(vector<string>& suggestions) const {
	// Keep the 5 first values of suggestions
	suggestions.resize(5);
}

void Dictionary::add_trigram_suggestions(vector<string>& suggestions, const string& word) const {
	if (word.size() > max_word_length) return;

	// Adding words with the same size
	vector<Word> temp;
	const vector<Word>& same_size = words[word.size()];
	temp.insert(temp.end(), same_size.begin(), same_size.end());

	// Adding words with one less letter
	if(word.size() > 0) {
		const vector<Word>& one_less = words[word.size() - 1];
		temp.insert(temp.end(), one_less.begin(), one_less.end());
	}

	// Adding words with one more letter
	if(word.size() < max_word_length - 1) {
		const vector<Word>& one_more = words[word.size() + 1];
		temp.insert(temp.end(), one_more.begin(), one_more.end());
	}

	// Keeping the words with trigrams that match at least half of the written word's trigram
	vector<string> trigrams = calc_trigrams(word);
	string word_str;
	for (Word w : temp) {
	  //cout << w.get_word() << endl;
	  // cout << w.get_matches(trigrams) << "suggest : word " << trigrams.size() << endl;
		if (w.get_matches(trigrams) * 2 >= trigrams.size() ) {
	    // cout << w.get_word() << endl;
			word_str = w.get_word();
			suggestions.push_back(word_str);
		}
	}
}

vector<string> Dictionary::calc_trigrams(const string& word) const {
	vector<string> trigrams;
	string trigram;
	if (word.length() <= 3) {
		trigrams.push_back(word);
	} else {
		for (unsigned i = 0; i < word.length() - 2; ++i) {
			trigram = word.substr(i, 3);
		  // cout << trigram << endl;
			transform(trigram.begin(), trigram.end(), trigram.begin(), ::tolower);
			trigrams.push_back(trigram);
		}
		sort(trigrams.begin(), trigrams.end());
	}
	return trigrams;
}
