/*binary tree*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <string>
#include "Tree.h"

using namespace std;

void Enter(string* con) {
	cout << "1:Insert\n2:Delete\n3:Find\n4:Show\n5:Exit\nEnter the action:";
	cin >> *con;
	while ((*con).length() != 1 || ((*con)[0] != '1' && (*con)[0] != '2' && (*con)[0] != '3' && (*con)[0] != '4' && (*con)[0] != '5')) {
		cout << "\nPlease enter again!\n1:Insert\n2:Delete\n3:Find\n4:Show\n5:Exit\nEnter the action:";
		cin >> *con;
	}
	
}

int main(void) {
	ifstream fin;
	int number;
	int state;
	Tree tree;
	string con;

	fin.open("number.txt", ios::in);

	while (fin >> number) {
		tree.Insert(number);
	}

	 
	Enter(&con);
	while (true) {
		switch (con[0]) {
		case '1':
			cin >> number;
			cout << "Enter the key you want to insert: ";
			tree.Insert(number);
			break;
		case '2':
			cin >> number;
			cout << "Enter the key you want to delete: ";
			tree.Delete(number);
		case '3':
			cin >> number;
			cout << "Enter the key you want to find: ";
			cout << number << " is No." << tree.Find(number) << "\n";
		case '4':
			tree.Show();
		case'5':
			cout << "Exit...\n";
			break;
		default:
			break;
		}
		if (con[0] == '5') {
			break;
		}
		Enter(&con);

		cout << "\n";
	}


	system("PAUSE");
	return 0;
}