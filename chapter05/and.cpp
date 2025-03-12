// and.cpp -- using the logical AND operator
#include <iostream>
const int ArSize = 6; 
int main() 
{
	using namespace std;
	float naaq[ArSize];
	cout << "Enter the NAAQs (New age Awareness Quotients)"
		<< " of\nyour neighbors. Program terminates "
		<< "when you make\n" << ArSize << " entries "
		<< "or enter a negative value.\n";
	int i = 0;
	float temp;
	cout << "First value:";
	cin >> temp;
	while (i<ArSize && temp > 0)  // 2 quitting criteria
	{
		naaq[i] = temp;
		++i;
		if (i < ArSize)   // room left in the array
		{
			cout << "Next value: "; // so get next value
			cin >> temp;
		}
	}
	if (i == 0)
		cout << " NO data--bye.\n";
	else
	{
		cout << "Enter your NAAQ: ";
		float you;
		cin >> you;
		int count = 0;
		for (int j = 0; j < i; j++)
			if (naaq[j] > you)
				++count;
		cout << count;
		cout << " of your neigehbors have greater awareness of\n"
			<< "the New Age than you do.\n";
	}


	return 0;
}
