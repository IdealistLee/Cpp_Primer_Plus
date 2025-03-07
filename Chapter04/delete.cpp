// delete.cpp --using the delete operator
#include <iostream>
#include <cstring>
using namespace std;
char * getname(void); // function prototype
int main()
{
	char * name; // create pointer but no storage
	name = getname(); // assign address of string to name
	cout << name << " at " << (int *) name << "\n";
	delete [] name; // memory freed
	name = getname(); // reuse freed memory
	cout << name << " at " << (int *) name << "\n";
	delete [] name; // memory freed again
	return 0;
}

char * getname() // return pointer to new string
{
	char temp[80]; // temporary storage
	cout << "Enter last name: ";
	cin >> temp;
	char * pn = new char[strlen(temp) + 1];
	strcpy(pn, temp); // copy string into smaller space
	return pn; // temp would go out of scope herea
}
// The function getname() creates a temporary array to store the input string,
// then creates a new array of the appropriate size to store the string, 
// copies the string from the temporary array to the new array, 
// and returns a pointer to the new array.
// The main() function uses this pointer to store the address of the new array in the pointer name.
// The program then displays the string and the address of the array, and frees the memory. 
// The program then reuses the memory and displays the string and the address of the array again, 
// and frees the memory again. The output of the program is: