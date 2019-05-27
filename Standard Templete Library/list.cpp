#include<iostream>
#include<list>
#include<algorithm>

using namespace std;

void printlist(list<int> l){
  for(auto it=l.begin(); it!=l.end(); ++it )
    cout<<*it<<"|";
  cout<<endl;
}

int main(){

  list<int> list1={4,10,7,12,91};
  list<int> list2={6,20,3,1,17,13};

  //Sorting takes O(nlogn)
  list1.sort();
  list2.sort();

  //Merging takes;
  list1.merge(list2);  
  cout<<endl<<endl<<"The list after Merging-->";
  printlist(list1);

  //Sizes of a list's
  cout<<endl<<endl<<"The List1 size: "<<list1.size()<<endl;
  cout<<"The List2 size: "<<list2.size()<<endl;
 
  //-----Remove Duplicates (Should be sorted to remove duplicates)----//
  list1.unique();
  cout<<endl<<endl<<"The list after removing Duplicates-->";
  printlist(list1);

  //Inserting an ele by position
  cout<<endl<<endl<<"The list after insert operations-->"<<endl;;
    //Beginning
    list1.push_front(0);
    printlist(list1);

    //At the End
    list1.push_back(100);
    printlist(list1);

    //At some position
    list<int>::iterator ins=list1.begin();
    advance(ins,4);
    list1.insert(ins,150);
    printlist(list1);

//Inserting an ele by position
  cout<<endl<<endl<<"The list after Delete operations-->"<<endl;;
    //Beginning
    list1.pop_front();
    printlist(list1);

    //At the End
    list1.pop_back();
    printlist(list1);

    //At some position
    list<int>::iterator del=list1.begin();
    advance(del,3);
    list1.erase(del);
    printlist(list1);
    //list1.remove(91);  /No position is required just an element that needs to be deleted

  //Reverse a list
  cout<<endl<<endl<<"The list after Reversing-->";
  list1.reverse();
  printlist(list1);

  
  //Clear or destroy the list
  list1.clear();

  //Chect if list is empty
  (list1.empty()==1)?cout<<"Empty"<<endl:cout<<"Not Empty"<<endl;

}
