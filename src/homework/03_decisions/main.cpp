//write include statements
#include <string>
#include <iostream>
#include "decisions.h"

using namespace std;
using std::cout;
using std::cin;

int main()
{
    int option;
    int grade;
    cout<< "MAIN MENU"<<"\n";
    cout<<"1-Letter grade using if"<<"\n";
    cout<<"2-Letter grade using switch"<<"\n";
    cout<<"3-Exit"<<"\n";
    cout<<"Enter your option: ";
    cin>> option;
    cout << "\n";


    if (option == 1 || option == 2){
        cout<<"Enter a number between 1-100 ";
        cin>> grade;
        if (grade < 0 || grade > 100){
            cout<<" Grade is out of range";
        }
        else{
            if (option == 1){
                cout<<"Letter grade using if: "<< get_letter_grade_using_if(grade)<<"\n";

            }
            if (option == 2){
                cout<<"Letter grade using switch: "<<  get_letter_grade_using_switch(grade)<<"\n";

            }
            
        
        }
    }
    else if( option == 3){
        cout<<"Exit program"<<"\n";

    }
    else{
        cout<<"Invalid Choice"<<"\n";
    }

}

