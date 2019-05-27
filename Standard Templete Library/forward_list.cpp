#include <iostream>
#include<forward_list>
#include<algorithm>

using namespace std;

void displaylist(forward_list<int> list){
  for(auto it=list.begin(); it!=list.end(); ++it)
    cout<<*it<<"|";
  cout<<endl;
}

int main(){
  forward_list<int> list1={25,89,11,0,22,45};
  forward_list<int> list2={5,9,11,20,12,4,23};
  

  //----sort both the lists--->O(nlogn)----//
  list1.sort();
  list2.sort();
  displaylist(list1);
  displaylist(list2);

  //----Merging the lists--->----//
  list1.merge(list2);
  cout<<endl<<endl<<"The list after Merging-->";
  displaylist(list1);

  
  //-----Remove Duplicates (Should be sorted to remove duplicates)----//
  list1.unique();
  cout<<endl<<endl<<"The list after removing Duplicates-->";
  displaylist(list1);


  //----Insert anywhere in sequence--->O(1)----//
  cout<<endl<<endl<<"The list after insert operations-->"<<endl;;
    //Beginning
    list1.push_front(100);
    displaylist(list1);

    //At some position
    forward_list<int>::iterator ins = list1.before_begin();
    advance(ins,2);   //insert in 3rd Position.  
    list1.insert_after(ins, 200);
    displaylist(list1);
    


  //Delete anywhere from sequence--->O(1)----//
  cout<<endl<<endl<<"The list after Delete operations-->"<<endl;;   
     //Beginning
     list1.pop_front();
     displaylist(list1);

     //At some position
     forward_list<int>::iterator rem = list1.before_begin();
     advance(rem,1);   //removes int in 2nd Position
     list1.erase_after(rem);
     displaylist(list1);
    // list1.remove(89); //No position is required just an element that needs to be deleted

  //reverse the list
  cout<<endl<<endl<<"The list after Reversing-->";
  list1.reverse();
  displaylist(list1);


  //Clear or destroy the list
  list1.clear();

  //Chect if list is empty
  (list1.empty()==1)?cout<<"Empty"<<endl:cout<<"Not Empty"<<endl;
}
