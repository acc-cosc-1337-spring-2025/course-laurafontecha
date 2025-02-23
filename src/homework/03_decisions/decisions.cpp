//write include statement for decisions header
#include <string>
#include <iostream>
#include "decisions.h"

using namespace std; 
//Write code for function(s) code here
string get_letter_grade_using_if(int grade)
{
    if (grade >=90 && grade<=100){
        return "A";
    }
    else if (grade >=80){
        return "B";
    }
    else if(grade>=70){
        return "C";
    }
    else if (grade >= 60)
    {
        return "D";
    }
    else if(grade<=59)
    {
        return "F";
    }

}

string get_letter_grade_using_switch(int grade)
{
    string letter;
    switch (grade/10)
    {
    case 10:
    case 9:

    letter="A";
    break;
    case 8:
    letter= "B";
    break;
    case 7:
    letter= "C";
    break;
    case 6:
    letter= "D";
    break;
    default: 
    letter= "F";
    break;
    
    }
    return letter;
}
