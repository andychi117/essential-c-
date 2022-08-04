/*
	Read file and store it in vector. Go through all vector, sort it and print it out.
*/
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main() {
	vector<string> file_input;
	ifstream infile("test.txt");
	if (!infile)
		cerr << "Opps, looks like the file doesn't exist" << endl;

	ofstream outfile("test.sort");
	if (!outfile)
		cerr << "Opps, looks like the file can't create" << endl;

	string word;
	while (infile >> word)
		file_input.push_back(word);

	cout << "unsorted files" << endl;
	for (int i=0; i<file_input.size(); i++)
		cout << file_input[i] << ' ';
	cout << endl;

	sort(file_input.begin(), file_input.end());
	for (int i=0; i<file_input.size(); i++)
		outfile << file_input[i] << ' ';

	// enter in the last line
	outfile << endl;

	return 0;
}
