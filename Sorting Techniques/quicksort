#include <iostream>
using namespace std;

void swap(int *x,int *y)
{
 int temp=*x;
 *x=*y;
 *y=temp;
}

int partition(int A[],int l,int h)
{
 int pivot=A[l];
 int i=l,j=h;

 do
 {
 do{i++;}while(A[i]<=pivot);
 do{j--;}while(A[j]>pivot);

 if(i<j)swap(&A[i],&A[j]);
 }while(i<j);

 swap(&A[l],&A[j]);
 return j;
}

void quicksort(int A[], int l,int h){

  if(l<h){
    int j = partition(A, l, h);
    quicksort(A,l,j);
    quicksort(A,j+1,h);
  }
}

void display(int A[], int size){
  for(int i=0; i<size; i++)
    cout<<A[i]<<endl;
}

int main(){

  int A[]={11,13,7,12,16,9,24,5,10,3}; 
  int size=sizeof(A)/sizeof(A[0]);
  quicksort(A,0,size);
  display(A,size);
  return 0;
}
