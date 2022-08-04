/*
	write down a program to ask user to enter their name. Read the input and make sure
	the length of name is greater than 2 characters. If user input a correct name, then give some
	positive feedback.
	1. Use c-style to implement your code
	2. Use String object to implement your code
*/

#include <iostream>
#include <string>
using namespace std;

int main() {

	string user_name;
	cout << "Please enter your full name: \n";
	cin >> user_name;
	if (user_name.size() >=2 )
		cout << "Hello, " << user_name << endl;
	else
		cout << "Hey! oooh no!!" << endl;

	return 0;
}
