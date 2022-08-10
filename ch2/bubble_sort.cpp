/*
	bubble sort
*/
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

void display (vector<int> vec) {
	for (int i = 0; i<vec.size(); i++)
		cout << vec[i] << ' ';
	cout << endl;
}

void swap (int &val1, int &val2) {
	int tmp = val1;
	val1 = val2;
	val2 = tmp;
}

void bubble_sort (vector<int> &vec) {
	for (int i=0; i<vec.size(); i++) {
		for (int j=i+1; j<vec.size(); j++) {
			if (vec[i] > vec[j])
				swap(vec[i], vec[j]);
		}
	}
}

int main() {
	int num_list[8] = {8, 34, 3, 13, 1, 21, 5, 2};
	vector<int> num_vec(num_list, num_list + 8);

	cout << "vector before sort" << endl;
	display(num_vec);

	cout << "vector after sort" << endl;
	bubble_sort(num_vec);
	display(num_vec);

	return 0;
}
