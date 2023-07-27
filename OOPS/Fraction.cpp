#include<iostream>
using namespace std;
class Fraction{
    int numerator;
    int denominator;
    public:
    Fraction(int num,int den){
        numerator=num;
        denominator=den;
    }
    void print(){
        cout<<numerator<<" / "<<denominator<<endl;
    }
    void simplify(){
        for(int i=denominator;i>0;i--){
            if(denominator%i==0&&numerator%i==0){
                denominator/=i;
                numerator/=i;
            }
        }
    }
    Fraction operator+(Fraction const &f1){
        int num = this->numerator+f1.numerator;
        int den = this->denominator+f1.denominator;
        Fraction fNew(num,den);
        fNew.simplify();
        return fNew;
    }
    //Pre increment
    Fraction& operator++(){
        numerator+=denominator;
        simplify();
        return *this;
    }
    //Post Increment
    Fraction operator++(int){
        Fraction f(numerator,denominator);
        numerator+=denominator;
        simplify();
        f.simplify();
        return f;
    }
    Fraction& operator+=(Fraction const &f1){
        int lcm=f1.denominator*this->denominator;
        int x = lcm/denominator;
        int y = lcm/f1.denominator; 
        int num = x*numerator+y*f1.numerator;
        numerator=num;
        denominator=lcm;
        simplify();
        return *this;
    }
};