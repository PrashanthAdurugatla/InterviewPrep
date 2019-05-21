#include<iostream>
using namespace std;

void merge(int A[], int l, int mid, int h){
  int i=l;
  int j=mid+1;
  int k=l;
  int B[h];

  while(i<=mid && j<=h){
    if(A[i]<A[j]) 
      B[k++]=A[i++];
    else
      B[k++]=A[j++];
  }

  while(i<=mid)
    B[k++]=A[i++];
  while(j<=h)
    B[k++]=A[j++];

  for(int i=l; i<=h; i++)
    A[i]=B[i];
}

void mergesort(int A[], int l, int h){
int mid;
if(l<h)
{
  mid=(l+h)/2;
  mergesort(A,l,mid);
  mergesort(A, mid+1,h);
  merge(A,l,mid,h);
}
}


int main(){

int A[]={2,1,44,9,32,21,16,55,20,5};
int size=sizeof(A)/sizeof(A[0]);

mergesort(A,0,size);

cout<<"Array after sorting: "<<endl;
for(int i=0; i<size; i++)
  cout<<A[i]<<" ";
return 0;
}
