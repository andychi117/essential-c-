/*
	Implement a program, store a list of integers and put into array and ventor
	Go through all these two containers and caculate the sum and average value.
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	int input_num, sum = 0, average = 0;
	vector<int> num_list;
	cout << "Please enter 0 to 20 numbers" << endl;

	while (cin >> input_num) {
		num_list.push_back(input_num);
		// check next character is enter
		if (cin.get() == '\n') break;
	}

	for (int i=0; i<num_list.size(); i++)
		sum += num_list[i];

	average = sum / num_list.size();

	cout << "You entered " << num_list.size()
		 << " numbers." << " Average: " << average
		 << " sum: " << sum << endl;

	return 0;
}
