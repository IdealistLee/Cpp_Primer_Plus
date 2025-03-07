// forstrl.cpp  -- using for with a string
#include <iostream>
#include <string>

int main()
{
	using namespace std;
	cout << "Please enter a word:";
	cin >> string word;
	for (int i = word.size() - 1; i >= 0; i--)
		cout << word[i];
	cout << "\n.End.\nBye!"


	return 0;
}