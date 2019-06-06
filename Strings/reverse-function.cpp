#include <iostream>
#include<string>
#include<algorithm>

using namespace std;

void swapfun(char *a, char *b){
  int temp=*a;
  *a=*b;
  *b=temp;
  }

int main(){
  string str;
  cout<<"Enter the String:";
  getline(cin, str);

  reverse(str.begin(),str.end());
  cout<<str<<endl;

  int i,j;
  j=str.length();
  
  for(i=0, j=j-1; i<j; i++,j--){
    swapfun(&str[i], &str[j]);
  }
  cout<<str;

}
