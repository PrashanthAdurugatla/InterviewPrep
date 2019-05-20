//O(n)<T<O(n^2)
//Swaps: Min = 0(If array is already sorted ,  Max = n^2
//No additional space is used

#include<iostream>
using namespace std;


void insertionsort(int A[], int size){
  for(int i=1; i<size; i++){
    int j=i-1;
    int x=A[i]; 
    while(j>-1 && A[j]>x){
      A[j+1]=A[j];
      j--;
    }
    A[j+1]=x;

  }
}

void display(int A[], int size){
  for(int i=0; i<size; i++)
    cout<<A[i]<<endl;
}

int main(){

  int A[]={11,13,7,12,16,9,24,5,10,3}; 
  int size=sizeof(A)/sizeof(A[0]);

  insertionsort(A,size);
  display(A,size);



  return 0;
}
