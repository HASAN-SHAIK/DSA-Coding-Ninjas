#include<iostream>
#include "../Fraction.cpp";

using namespace std;
int main(){
    Fraction f1(1,2);
    Fraction f2(13,23);
   
    // Fraction f3 = f1+f2;

    // f1.print();
    // f2.print();
    // f3.print();

    // Fraction f4 = ++f1;
    // f1.print();
    // f4.print();

    Fraction f5 = ++(++f1);
    f1.print();
    f5.print();
    
} 

