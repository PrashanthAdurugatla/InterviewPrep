//Time O(d*n)-----Space O(1)
//Time O(n)-----Space O(n) --- Can implement using another array 
#include<iostream>
using namespace std;

void shiftarray(int A[], int n){
  for(int i=0;i<n-1;i++){
    A[i]=A[i+1];
  }
}



void display(int A[], int n){
  for(int i=0; i<n; i++)
    cout<<A[i]<<"|";
  cout<<endl;
}
int main(){
  int A[]={11,42,6,9,1,3,0,24,15,62};
  int n =sizeof(A)/sizeof(A[0]);

  cout<<"Displaying Array: ";
  display(A,n);

  int d;
  cout<<"Enter Num of ele to be shifted: "<<endl;
  cin>>d;


  int B[d];
  for(int i=0; i<d; i++)
    B[i]=A[i];

  int i;
  for(i=0; i<n-d; i++)
    A[i]=A[i+d];
  
  int j=0;
  while(j<d)
  A[i++]=B[j++];

  display(A, n);
  

  // for(int i=0; i<d; i++){
  //   int temp = A[0];
  //   shiftarray(A, n);
  //   A[n-1]=temp;

  //   cout<<"shift "<<i+1<<":";
  //   display(A,n);
    

  // }
  


}
