#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric> 
using namespace std;

void display(int A[], int size){
  for(int i=0; i<size; i++)
    cout<<A[i]<<" ";
}

int main(){
  int A[]={1, 3, 4, 2, 6, 5, 8, 7};
  int size=sizeof(A)/sizeof(A[0]);
  vector<int> V(A,A+size);

  cout<<"The Array before sorting: "<<endl;
  display(A,size);

  //Sort the List
  sort(A,A+size);
  cout<<"\nThe Array after sorting: "<<endl;
  display(A,size);
  
  //Reverse the List
  //reverse(A,A+size);
  cout<<"\nThe Array after reversing: "<<endl;
  display(A,size);

  
  //Find Max, Min, accumulation(Summation) of the List
  cout<<"\nMax element is:"<<*max_element(A, A+size)<<endl;
  cout<<"\nMin element is:"<<*min_element(A, A+size)<<endl;
  cout<<"\nThe sum of ele: "<<accumulate(A,A+size,0)<<endl;

  //Count occuence of an Ele in the List 
  cout<<"\nThe occurence of element 4 is: "<<count(A,A+size,4)<<endl;

  //find Ele 41 is in list or not which returns pointer to last address if element not present 
  find(V.begin(),V.end(),41)!=V.end()?cout<<"\nElement is found":cout<<"\nElement not found";  

}
