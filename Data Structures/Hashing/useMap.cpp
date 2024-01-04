#include<iostream>
#include "ourmap.h"
using namespace std;

int main(){
    ourmap<int> m;
    cout<<m.getLoadFactor()<<endl;
    m.insert("a",1);
    m.insert("b",1);
    m.insert("c",1);
    cout<<m.getValue("a")<<endl;
    cout<<m.remove("a")<<endl;
    m.insert("d",1);
    m.insert("e",1);
    cout<<m.getValue("a")<<endl;
    cout<<m.getSize()<<endl;
    cout<<m.getLoadFactor()<<endl;
    m.insert("f",1);
    m.insert("g",1);
    m.insert("h",1);
    m.insert("i",1);
    m.insert("j",1);
    cout<<m.getLoadFactor()<<endl;
    m.insert("k",1);
    cout<<m.getSize()<<endl;
    m.insert("f",1);
    m.insert("g",1);
    cout<<m.getLoadFactor()<<endl;
    cout<<m.getSize()<<endl;
    return 0;
}
