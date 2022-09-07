/*
  insertion sort implementation
*/
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

void display (vector<int> vec) {
	for (int i=0; i<vec.size(); i++) {
		cout << vec[i] << ' ';
	}
	cout << endl;
}

void insertion_sort (vector<int> &vec) {
	int key=0;
	for (int i=1; i<vec.size();i++) {
		key = vec[i];
		int j = i - 1;
		while (j>=0 && (vec[j]>key)) {
			vec[j+1] = vec[j];
			j--;
		}
		vec[j+1] = key;
	}
}

int main() {

	int num_list[8] = {6, 5, 3, 1, 8, 7, 2, 4};
	vector<int> num_vec(num_list, num_list + 8);

	cout << "vector before sort" << endl;
	display(num_vec);

	cout << "vector after sort" << endl;
	insertion_sort(num_vec);
	display(num_vec);
	return 0;
}
