// sqrt.cpp -- using the sqrt() function

#include <iostream>
#include <cmath>  // or math.h

int main()
{
	using namespace std;
	double area;
	cout << "Enter the floor area,in square feet, of our home:";
	cin >> area;
	double side; // double side = sqrt(area);
	side = sqrt(area);
	cout << "That's the eqivalent of a square " << side
		<< "feet to the side." << endl;
	cout << "How fascinating!" << endl;
	return 0;
}
