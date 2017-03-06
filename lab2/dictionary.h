#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <string>
#include <vector>
#include <unordered_set>
#include "word.h"

class Dictionary {
public:
	Dictionary();
	bool contains(const std::string& word) const;
	std::vector<std::string> get_suggestions(const std::string& word) const;
private:
	void add_trigram_suggestions(
	std::vector<std::string>& suggestions, const std::string& word) const;
	void rank_suggestions(std::vector<std::string>& suggestions, const std::string& word) const;
	void trim_suggestions(std::vector<std::string>& suggestions) const;
	std::vector<std::string> word_to_trigrams(const std::string s) const;
	std::vector<std::string> calc_trigrams(const std::string& word) const;
	std::unordered_set<std::string> word_set;
	static const unsigned int max_word_length = 25;
	std::vector< Word > words[max_word_length + 1];
};

#endif
