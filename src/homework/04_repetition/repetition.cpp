//add include statements
#include "repetition.h"
//add function(s) code here
int factorial(int num)
{
    int result = 1;
    for (int i=1; i<=num; i= i+1)
    {
        result = result * i;
    }
    return result;
}
//Function to calculate the greatest common divisor (gcd)
int gcd( int num1, int num2)
{
    while(num1 != num2)
    {
        if (num1 > num2){
            num1=num1-num2;
        }else
        {
            num2= num2 - num1;
        }
    }
    return num1;
}