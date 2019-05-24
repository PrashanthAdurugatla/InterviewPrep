#include<iostream>
#include<algorithm>
#include<numeric>
using namespace std;

void swap(int *a, int *b){
  int temp=*a;
  *a=*b;
  *b=temp;
}


void reversefun(int A[], int size){
int i,j;
for(i=0,j=size-1; i<j; i++,j--)
  swap(&A[i],&A[j]);
}

int findmax(int A[], int size){
  int temp = 0;
  for(int i=0; i<size; i++){
    if(A[i]>temp)
      temp=A[i];
  }
  return temp;
}

int findavg(int A[], int size){
  int sum = 0;
  for(int i=0; i<size; i++)
    sum=sum+A[i]; 
  return sum/size;
}

int findelement(int A[], int size, int ele){
  for(int i=0; i<size; i++){
    if(A[i]==ele)
      return i;
  }
  return -1;
}

int bfindelement(int A[], int l, int h, int ele){
  int mid = (l+h)/2;

  if(l<h)
  {
    if(A[mid]==ele)
    return mid;

    else if(A[mid]>ele)
    return bfindelement(A,l,mid-1,ele);

    else if(A[mid]<ele)
    return bfindelement(A,mid+1,h,ele);
  }
  return -1;
}


void display(int A[], int size){
   cout<<endl;
  for(int i=0; i<size; i++) 
    cout<<A[i]<<"|";
}
int main(){
  int A[]={34,65,1,0,8,34,2,11,72,16,21};
  int size=sizeof(A)/sizeof(A[0]);
  
  //Sorting an Array
  sort(A,A+size);
  display(A,size);
 
  //Finding Reverse of an Array
  reversefun(A,size);
  //reverse(A,A+size);
  display(A,size);

  //Finding Max and Min
  cout<<"\n"<<*max_element(A,A+size)<<endl;
  cout<<findmax(A,size)<<endl;
  cout<<*min_element(A,A+size)<<endl;

  //Finding Average of an Array
  cout<<findavg(A,size)<<endl;
  int sum = accumulate(A,A+size,0);
  cout<<sum/size<<endl;

  //Find an elem index
  int index = findelement(A,size,72);
  if(index==-1)
  cout<<"Ele not found"<<endl;
  else
  cout<<"Ele is at index: "<<index<<endl;
  
  //Find an elem index using Binary search
  int bindex = bfindelement(A, 0, size-1, 72);  
  //cout<<bindex;
  if(bindex==-1)
  cout<<"Ele not found"<<endl;
}



