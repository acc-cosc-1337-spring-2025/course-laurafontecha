//write include statements
#include<iostream>
#include "data_types.h"


//write namespace using statement for cout
using std::cout;
using std::cin;

int main()
{
	int num;
	cout<<"Enter a number: ";
	cin>> num;
	int product=multiply_numbers(num);
	cout<<"Result: "<<product<< "\n";

	int num1 = 4;
	product=multiply_numbers(num1);
	cout<<"Result: "<<product<< "\n";

	return 0;
}
