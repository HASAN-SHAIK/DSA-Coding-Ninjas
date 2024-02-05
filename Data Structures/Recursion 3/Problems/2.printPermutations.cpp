#include <iostream>
#include <string>
using namespace std;

void printPermutations(string input,string str=""){
	if(input.length()==1){
		cout<<str+input[0]<<endl;
		return;
	}
	for(int i=0;i<input.length();i++){
		printPermutations(input.substr(0,i)+input.substr(i+1),str+input[i]);
	}
}
