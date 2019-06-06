#include<iostream>
#include<string>
#define MAX 256       //There are 256 Chars in Ascii representation 
using namespace std;

int main(){
  string str="Prashanth1113";
  int Hash[MAX]={0};

  int length=str.length();

  for(int i=0; i<length; i++)
    Hash[str[i]]+=1;

  for(int i=0; i<length; i++)
    {
      if(Hash[str[i]]>1)
      {
        cout<<str[i]<<" repeated "<<Hash[str[i]]<<" Times"<<endl;
        Hash[str[i]]=0;
      }          
    }
}
