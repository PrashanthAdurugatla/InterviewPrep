//Always O(n^2) as Time
//swaps: Only n-1 Swap's are performed. This is the only Technique with Min number of swaps

#include <iostream>
using namespace std;

void swap(int *a, int *b){
  int temp=*a;
  *a=*b;
  *b=temp;

}

void selectionsort(int A[], int size){
  int i,j,k;
  for(i=0; i<size-1; i++){
    for(j=k=i; j<size; j++){
      if(A[j]<A[k])
        k=j;
    }
    swap(&A[i], &A[k]);
  }
}


void display(int A[], int size)
{
  for(int i=0; i<size; i++){
    cout<<A[i]<<endl;
  }
}

int main(){

  int A[]={11,13,7,12,16,9,24,5,10,3}; 
  int size=sizeof(A)/sizeof(A[0]);
  selectionsort(A,size);
  display(A,size);
  return 0;
}
