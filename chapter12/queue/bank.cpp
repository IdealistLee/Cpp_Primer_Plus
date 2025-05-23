// bank.cpp -- using the Queue interface
// compile with queue.cpp
#include <iostream>
#include <cstdlib>  // for rand() and srand()
#include <ctime>  // for time()
#include "queue.h"
const int MIN_PER_HR = 60;
bool newcustomer(double x);  // is there a new customer?

int main()
{
	using std::cin;
	using std::cout;
	using std::endl;
	using std::ios_base;
	// setting things up
	std::srand(std::time(0)); // random initializing of rand()

	cout << "Case Study: Bank of Heather Automatic Teller\n"
		<< "Enter maximum size of queue:";
	int qs;
	cin >> qs;
	Queue line(qs); // line queue holds up to qs people

	cout << "Enter the number of simulation hours: ";
	int hours;
	cin >> hours;
	// simulation will run 1 cycle per minute
	long cyclelimit = MIN_PER_HR * hours; // # of cycles
	cout << "Enter the average number of customer per hours: ";
	double perhour;   // average # of arrival per hour
	cin >> perhour;
	double min_per_cust;  // average time between arrivals
	min_per_cust = MIN_PER_HR / perhour;

	Item temp;  // new custmoer data
	long turnaways = 0;  // turned away by full queue
	long customers = 0;  // joined the queue
	long served = 0;  // served during the simulation
	long sum_line = 0; // cumulative line length
	int wait_time = 0;  // time until autoteller is free
	long line_wait = 0;  // cumulative time in line

	// running the simulation
	for (int cycle = 0; cycle < cyclelimit; cycle++)  // have newcomer
	{
		if (line.isfull())
			turnaways++;
		else
		{
			customers++;
			temp.set(cycle); // cycle =time of arrival
			line.enqueue(temp);  // add newcomer to line
		}
		if (wait_time <= 0 && !line.isempty())
		{
			line.dequeue(temp);  // attend next customer
			wait_time = temp.ptime(); // add newcomer to line
			line_wait += cycle - temp.when();
			served++;
		}
		if (wait_time > 0)
			wait_time--;
		sum_line += line.queuecount();
	}

	// reporting results
	if (customers > 0)
	{
		cout << "Custmoers accepted: " << customers << endl
			<< "Customers served: " << served << endl
			<< "turnaways: " << turnaways << endl
			<< "averages queue size: ";
		cout.precision(2);
		cout.setf(ios_base::fixed, ios_base::floatfield);
		cout << (double)sum_line / cyclelimit << endl
			<< "average wait time: " << (double)line_wait / served << " minutes\n";
	}
	else
		cout << "No customers!\n";
	cout << "Done!\n";
	return 0;
}
// x = average time, in minutes,between customers
// return value is true if customers shows up this minute 
bool newcustomers(double x)
{
	return (std::rand() * x / RAND_MAX < 1);
}
