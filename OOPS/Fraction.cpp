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

    Fraction& operator++(){
        numerator+=denominator;
        simplify();
        return *this;
    }
};