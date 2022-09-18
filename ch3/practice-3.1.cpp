/*
  Read a file and put the string into map, make a exclusice set which inlucde words such as "a, an, or, the, but".
  Before put the string into map, please check if the words is in exclusive set.
*/
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;

void initialize_exclusive_set(set<string>&);
void process_file(map<string, int>&, const set<string>&, ifstream&);
void user_query(const map<string, int>&);
void display_word_count(const map<string,int>&, ofstream&);

int main() {
	ifstream ifile("./column.txt");
	ofstream ofile("./column.map");
	if(!ifile || !ofile) {
		cerr << "Unable to open file" << endl;
		return -1;
	}

	set<string> exclusive_set;
	initialize_exclusive_set(exclusive_set);

	map<string, int> word_count;
	process_file(word_count, exclusive_set, ifile);
	user_query(word_count);
	display_word_count(word_count, ofile);

	return 0;
}

void initialize_exclusive_set(set<string> &exs) {
	static string _exclusive_words[25] = {
		"the","and","but","that","then","are","been",
		"can","a","could","did","for","of",
		"had","have","him","his","her","its","is",
		"were","which","when","with","would"
	};

	exs.insert(_exclusive_words, _exclusive_words+25);
}

void process_file(map<string,int> &word_count,
					const set<string> &exclude_set, ifstream &ifile)
{
	string word;
	while(ifile >> word) {
		if(exclude_set.count(word))
			continue;
		word_count[word]++;
	}
}

void user_query(const map<string, int> &word_map) {
	string search_word;
	cout << "please enter a word to search: q for quit ";
	cin >> search_word;

	while(search_word.size() && search_word !="q") {
		map<string, int>::const_iterator it;
		if ((it=word_map.find(search_word)) != word_map.end()) {
			cout << "Found! " << it->first
				 << " Occurs " << it->second
				 << " times" << endl;
		} else cout << search_word
				    << " was not found in the text.\n";
		cout << "\nAnother search? (q to quit) ";
		cin >> search_word;
	}

}

void display_word_count(const map<string, int> &word_map, ofstream &os) {
	map<string, int>::const_iterator
					iter = word_map.begin(),
					end_it = word_map.end();
	while(iter != end_it) {
		os << iter->first << " ( "
		   << iter->second << " ( " << endl;
		++iter;
	}
	os << endl;
}
