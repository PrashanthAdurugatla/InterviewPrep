#include<iostream>
#include<algorithm>
using namespace std;

void mergefun(int A[], int B[], int C[], int m, int n){
  
  int i=0,j=0,k=0;
  int size=m+n-1;
  

  while(i<m && j<n){
    if(A[i]<B[j])
      C[k++]=A[i++];
    else
      C[k++]=B[j++];
  }
  while(i<m)
    C[k++]=A[i++];
  while(j<n)
    C[k++]=B[j++];


}


void display(int D[], int size){
  for(int i=0; i<size; i++)
    cout<<D[i]<<"|";
}

int main(){
int A[]={33,5,7,1,0,13,96,42};
int B[]={2,71,55,9,56,99};

int m=sizeof(A)/sizeof(A[0]);
int n=sizeof(B)/sizeof(B[0]);

int size=m+n-1;
int C[size];

sort(A,A+m);
display(A,m);
cout<<endl;

sort(B,B+n);
display(B,n);
cout<<endl;

mergefun(A,B,C,m,n);
display(C,size);


}

