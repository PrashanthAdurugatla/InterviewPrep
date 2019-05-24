#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void printvec(vector<int> V){
  for(int i=0; i<V.size();i++)
    cout<<V[i]<<"|";
}

int main(){

  int A[]={1,1,2,3,3,4,4,4,5,7,8,9,12,12,16,18,18};
  int n=sizeof(A)/sizeof(A[0]);

  //Finding duplicates in an array using Hashing
  int Hash[A[n-1]];
  for(int i=0; i<n; i++)
  {
    if(Hash[A[i]]!=1)
      Hash[A[i]]=1;
    else
      cout<<A[i]<<endl;
  }


  //Removing Duplicates in a Vector
  vector<int> V(A,A+n);
  printvec(V);
  cout<<endl;

  V.erase(unique(V.begin(),V.end()),V.end());
  printvec(V);
  cout<<endl;

}
