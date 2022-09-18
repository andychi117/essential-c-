/*
   filter function
*/
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>

vector<int> filter (const vector<int> &vec, int filter_value, bool (*pred) (int, int)) {
	vector<int> nvec;
	for (int i=0; i<vec.size(); i++) {
		if (pred(vec[i], filter_value)) {
			nvec.push_back(vec[i]);
		}
	}
	return nvec;
}

bool less_than (int v1, int v2)
{ return v1 < v2 ? true : false; }

bool greater_then (int v1, int v2)
{ return v1 > v2 ? true : false; }

using namespace std;
int main() {

	cout << "hello world" << endl;
	return 0;
}
