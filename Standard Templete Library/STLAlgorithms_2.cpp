#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

void printvec(vector<int> V){
  for(int i=0; i<V.size(); i++)
    cout<<V[i]<<"|";
}

int main() {
 
  int A[]={12, 3, 4, 22,22,22,22,22, 6, 51,51,51, 8, 7,3};
  int size=sizeof(A)/sizeof(A[0]);

  //Initializing Vector
  vector<int> V(A,A+size);

  //Sort the vector/list
  sort(V.begin(),V.end());
  cout<<"\nThe Vector after sorting: ";
  printvec(V);

  //Accessing the Vector position
  cout<<"\nThe Element at position is:"<<V.at(4); 

  //Binary Search returns either True or False
  binary_search(V.begin(),V.end(),7) !=0 ? cout<<"\nElement Found (Binary_Search)"<<endl : cout<<"\nElement not Found (Binary_Search)"<<endl;

  //LowerBound(First_Equalsto_or_Greaterthan) returns pointer pointing to first element
  //UpperBound(First_Greaterthan) returns pointer point to first element
  auto lp =lower_bound(V.begin(), V.end(),11);
  auto up =upper_bound(V.begin(), V.end(),51);

  cout<<(lp!=V.end() ? to_string(*lp):"Lower Bound Not Found")<<endl;
  cout<<(up!=V.end() ? to_string(*lp):"Upper Bound Not Found")<<endl;

  //Delete an ele from Vector. Find the position of element and then delete
  auto pos = find(V.begin(),V.end(),3);
  if(pos!=V.end())
  {
    V.erase(pos);
    printvec(V); 
  }
  else{
    cout<<"\nElement is Not in the List"<<endl;
  }
    
  //Delete Duplicates in the List
  V.erase(unique(V.begin(),V.end()),V.end());
  cout << "\nVector after deleting duplicates: "; 
  printvec(V);

}

