// O(n)<Time<O(n^2)
//No additional Space used

#include <iostream>
using namespace std;

void swap(int *x,int *y)
{
 int temp=*x;
 *x=*y;
 *y=temp;
} 


void Bsort(int A[], int size){
  int flag=0;
  for(int i=0; i<size-1; i++){
    flag=0;
    for(int j=0; j<size-i-1; j++){
      if(A[j]>A[j+1]){
        swap(&A[j], &A[j+1]);
        flag=1;
      }  
    }
    if(flag==0)
      break;
  }

}


void display(int A[], int size){
  for(int i=0; i<size; i++)
    cout<<A[i]<<endl;
}

int main() {
int A[]={11,13,7,12,16,9,24,5,10,3};
int size=sizeof(A)/sizeof(A[0]);
Bsort(A,size);
display(A,size);
}
