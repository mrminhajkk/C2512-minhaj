#include <iostream>
#include <cstdlib>
using std::cout;
using std::cin;
using std::endl;

int main(){
	int id1;
	char name1[200];
	
	int id2;
	char name2[200];
	
	cout << "Enter first student details." << endl;
	cout << "Enter id: ";
	cin >> id1;
	cout <<"Enter name: ";
	cin >> name1;
	
	cout << "Enter second student details." << endl;
	cout << "Enter id: ";
	cin >> id2;
	cout <<"Enter name: ";
	cin >> name2;


	cout << "Hello " <<name1 << " of ID "<< id1 <<"!!!" << endl;
	cout << "Hello " <<name2 << " of ID "<< id2 <<"!!!" << endl;

	return EXIT_SUCCESS;
}
