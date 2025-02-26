// ourfuc.cpp -- defining your own function
#include <iostream>
void simon(int);  // function prototype for simon() simon的函数原型

int main()
{
	using namespace std;
	simon(3);  // call the simon() function 调用函数
	cout << "Pick an integer:";
	int count;
	cin >> count;
	simon(count);  // call it again
	cout << "Well Done!" << endl;
	return 0;
}

void simon(int n)
{
	using namespace std;
	cout << "Simon says touch your toes " << n << "times." << endl;
}   // void function don't need return statements
