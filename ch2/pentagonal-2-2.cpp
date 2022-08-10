/*
    Pn=n*(3n - 1)/2
*/
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

bool cacl_elements(vector<int> &vec, int pos);
void display_elements(vector<int> &vec, const string &msg, ostream &os=cout);

int main() {

	vector<int> pent;
	const string title("Pentagonal Numeric Series.");

	if ( cacl_elements(pent, 0) )
		display_elements(pent, title);

	if ( cacl_elements(pent, 8) )
		display_elements(pent, title);

	if ( cacl_elements(pent, 14) )
		display_elements(pent, title);

	if ( cacl_elements(pent, 138) )
		display_elements(pent, title);

	return 0;
}

bool cacl_elements(vector<int> &vec, int pos) {

	if (pos > 64 || pos < 0) {
		cout << "You're enterning a invalid number scope" << endl;
		return false;
	}

	for (int i=vec.size()+1; i<=pos; i++)
		vec.push_back(i * (3*i - 1) / 2);

	return true;
}

void display_elements(vector<int> &vec, const string &msg, ostream &os) {

	os << '\n' << msg << "\n\t";

	for (int i=0; i<vec.size(); i++)
		os << vec[i] << ' ';

	os << endl;

}
