#include "hwexpressions.h"

//example
int add_numbers(int num1, int num2)
{
	return num1 + num2;
}

//write function code here

double get_sales_tax(double meal_amount)
{
	double tax_rate = 0.0675;
	double product=meal_amount*tax_rate;
	return product;
}

double get_tip_amount (double meal_amount, double tip_rate)
{
	double tip_amount =meal_amount*tip_rate;
	return tip_amount;
}



