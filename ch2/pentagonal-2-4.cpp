/*
    Pn=n*(3n - 1)/2
*/
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

inline bool check_validity(int pos) {
	return ( (pos < 0 || pos > 64) ? false : true);
}

const vector<int>* pentagonal_series(int pos) {

	static vector<int> _elems;

	if (check_validity(pos) && pos > _elems.size()) {
		for (int i=_elems.size()+1; i<=pos; i++)
			_elems.push_back(i * (3*i - 1) / 2);
	}

	return &_elems;
}

bool pentagonal_elem(int pos, int &elem) {

	if (! check_validity(pos)) {
		cout << "error, invalid position" << endl;
		elem = 0;
		return false;
	}

	const vector<int> *pent = pentagonal_series(pos);
	elem = (*pent)[pos - 1];

	return true;

}

int main() {

	int elem;
	if (pentagonal_elem(8, elem))
		cout << "element 8 is " << elem << endl;

	if (pentagonal_elem(88, elem))
		cout << "element 88 is " << elem << endl;

	if (pentagonal_elem(12, elem))
		cout << "element 12 is " << elem << endl;

	if (pentagonal_elem(64, elem))
		cout << "element 64 is " << elem << endl;
	return 0;
}

