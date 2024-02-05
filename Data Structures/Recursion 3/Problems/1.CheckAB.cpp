bool checkab(char input[], int index) {
  int size = sizeof(input) / sizeof(input[0]);
  if (index == size-1)
    return true;
  if (input[index] == 'a') {
		if(index+1<size&&input[index+1]=='a')
		return checkab(input, index + 1);
		else if(index+2<size&&input[index+2]=='b')
		return checkab(input,index+2);
  }
  else{
	if(index+1<size&&input[index+1]=='a')
		return checkab(input, index + 1);
  else
    return false;
  }
  if(index+1==size-1)
  return true;
  return false;
}
bool checkAB(char input[]) {
	return checkab(input,0);
}



