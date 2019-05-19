#include <iostream>
using namespace std;

int Lsearch(int A[], int size, int key){

for(int i=0; i<size; i++){
 if(A[i]==key)
  return 1; 
}
return 0;
}


int Bsearch(int A[], int l, int h, int key){
if(l<=h)
  {
    int mid=(l+h)/2;

    if(key==A[mid])
      return 1;
    
    else if(key<A[mid])
      return Bsearch(A, l, mid-1, key);
    
    else if(key>A[mid])
      return Bsearch(A, mid+1, h, key);
  }
  return 0;
}




int main() {
int A[]={1,2,4,6,9,44,54,95};
int size=sizeof(A)/sizeof(A[0]);

int key;
cout<<"Enter the number to be searched: "<<endl;
cin>>key;


int Lresult=Lsearch(A,size,key);
(Lresult==0)?cout<<"Number is not in the list":cout<<"Number is Found";


int Bresult=Bsearch(A,0,size-1,key);
(Bresult==0)?cout<<"Number is not in the list":cout<<"Number is Found";
}
