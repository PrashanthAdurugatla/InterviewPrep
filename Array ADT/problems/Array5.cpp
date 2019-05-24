#include<iostream>
using namespace std;


int main(){
  int A[]={6,3,2,8,0,10,0,16,7,5,2,9,14};
  int n=sizeof(A)/sizeof(A[0]);

  int k=10;
  int Hash[100];

  for(int i=0; i<n; i++){
    Hash[A[i]]++;
    if(Hash[k-A[i]]==1)
      cout<<A[i]<<"|"<<k-A[i]<<endl;
  }


}
