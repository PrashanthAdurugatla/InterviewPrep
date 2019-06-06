#include <iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(){
  string str;

  cout<<"Enter the String: "<<endl;
  getline(cin, str);


  //Capacity Functions
  int length=str.length();
  cout<<"The Length of the String-->"<<str.length()<<endl;
  cout<<"The Capacity of the String-->"<<str.capacity()<<endl;

  str.shrink_to_fit();
  cout<<"Decreasing the capacity of string to its length-->"<<str.capacity()<<endl;

  str.resize(5);
  cout<<"String after resizing operation: "<<str<<endl;


  //Iterator Functions(Declare the iterator and rev iterator using string class)
  string::iterator it1;
  string::reverse_iterator it2;

  cout<<"Printing string using forward iterator: ";
  for(it1=str.begin(); it1!=str.end(); it1++)
  cout<<*it1;
  cout<<endl; 

  cout<<"Printing string using reverse iterator: ";
  for(it2=str.rbegin(); it2!=str.rend(); it2++)
  cout<<*it2;
  cout<<endl;

  //Reverse the string
  cout<<"The String before Reversing: "<<str<<endl;
  reverse(str.begin(), str.end());
  cout<<"The String after Reversing: "<<str<<endl;

  //Manipulating Functions
  string str1="Adurugatla";
  string str2="Prashanth";

  char ch[25];
  str1.copy(ch,5,0);
  str1.swap(str2);

  cout<<"The new copied Character Array: "<<ch<<endl;
  cout<<"The String str1 after swapping: "<<str1<<endl;
  cout<<"The String str2 after swapping: "<<str2<<endl;


  //Insert Function
  string str3="Masters";
  str3.insert(str3.length()," in CS");
  cout<<str3<<endl;

  //Clear Function
  cout<<"Clearing the string str3"<<endl;
  str3.clear();

  //Comparition Functions
  int diff=str1.compare(str2);
  (diff==0)?cout<<"Strings are Equal"<<endl:cout<<"Strings are not Equal"<<endl;
    
  //Find Function
  string str4="California";
  cout<<str4.find("nia")<<endl;


}
