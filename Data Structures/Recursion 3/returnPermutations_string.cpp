#include <string>
using namespace std;
int getPermutations(string input,string output[],string str,int &count){
	if(input.length()==1){
		str+=input[0];
		output[count++] = str;
		return count;
	}
	for(int i=0;i<input.length();i++){
		getPermutations(input.substr(0,i)+input.substr(i+1), output,str+input[i],count);
    }
	return count;
}
int returnPermutations(string input, string output[]){
	int count=0;
    getPermutations(input, output, "", count);
	return count;
}
