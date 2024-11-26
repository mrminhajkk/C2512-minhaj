#include <iostream>
#include <cstdlib>
using std::cout;
using std::cin;
using std::endl;

int main()
{
	int id;
	char name[200];

	cout << "Enter id: ";
	cin >> id;
	cout <<"Enter name: ";
	cin >> name;
	cout << "Hello " <<name << " of id: "<< id <<"!!!" << endl;

	return EXIT_SUCCESS;
}
