//write include statements
#include <iostream>
#include "hwexpressions.h"

//write namespace using statement for cout
using std::cout;
using std::cin;

int main()
{
	double meal_amount, tip_rate, tip_amount, tax_amount, total;
	cout<<"Enter Meal Amount: ";
	cin>>meal_amount;
	tax_amount=get_sales_tax(meal_amount);
	cout<<"Enter Tip percentage as decimal: ";
	cin>>tip_rate;
	tip_amount= get_tip_amount(meal_amount, tip_rate);
	total= meal_amount+tax_amount+tip_amount;
	cout<<"Meal Amount:\t$" << meal_amount << "\n";
	cout<<"Sales tax:\t$" << tax_amount << "\n";
	cout<<"Tip Amount:\t$" << tip_amount << "\n";
	cout<<"Total:\t$" << total << "\n";
	


	return 0;
}
