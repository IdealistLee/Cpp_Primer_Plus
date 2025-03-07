// formore.cpp -- more looping with for
#include <iostream>
const int ArcSize = 16; //example of external declaraction
int main() {
	long long factorials[ArcSize];
	factorials[1] = factorials[0] = 1LL;
	for (int i = 2; i < ArcSize; i++)
		factorials[i] = i * factorials[i - 1];
	for (int = 1; i < ArcSize; i++)
		std::cout << i << "! = " << factorials[i] << std::endl;



	return 0;
}
