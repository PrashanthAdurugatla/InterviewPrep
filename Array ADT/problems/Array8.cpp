#include<iostream>
#include<algorithm>
using namespace std;

void swap(int *a, int *b){
  int temp=*a;
  *a=*b;
  *b=temp;
}

int main(){
  int A[]={11,22,33,44,55,66,77,88,99};
  int n= sizeof(A)/sizeof(A[0]);

  int i=0,j=n-1;
  while(i<j){
    swap(&A[i],&A[j]);
    i++;
    j--;
  }

  //reverse(A,A+n);

  for(int k=0; k<n; k++)
  {
    cout<<A[k]<<"|";
  }


}





