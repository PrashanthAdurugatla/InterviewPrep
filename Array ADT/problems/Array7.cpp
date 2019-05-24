#include<iostream>
using namespace std;

void swap(int *a, int *b){
  int temp=*a;
  *a=*b;
  *b=temp;
}

int main(){

  int A[]={1,1,0,1,0,0,1,1,1,0,0,0,0,1,0,1,1,1,0,0,1,0};
  int n=sizeof(A)/sizeof(A[0]);
 
  int i=0,j=n-1;
  while(i<j){

    while(A[i]<=0) 
      i++;
    
    while(A[j]>0) 
      j--;
    
    if(i<j)
      swap(&A[i],&A[j]);

  }

  for(int i=0; i<n; i++)
    cout<<A[i]<<"|";

}
