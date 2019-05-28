#include<iostream>
#include<algorithm>
using namespace std;

typedef struct Node{
  int data;
  struct Node *next;
}node;


class LinkedList{
  public:
  node *head=NULL;
  node *tail=NULL;
  int length=0;
  void createlist(int data);
  void displaylist(node *temp);
  bool isSorted(node *temp);

};

void LinkedList::createlist(int data){
  node *newnode=new node();
  newnode->data=data;
  newnode->next=NULL;

  if(head==NULL){
    head=newnode;
    tail=newnode; 
  }
  else{
    tail->next=newnode;
    tail=newnode;
  }
  length++;
}

bool LinkedList::isSorted(node *temp){
  int num=-1;
  while(temp){
    if(temp->data>num){
      num=temp->data;
      temp=temp->next;
    }  
    else
      return false;  
  }
  return true;
}


void LinkedList::displaylist(node *temp){
  while(temp){
    cout<<temp->data<<"|";
    temp=temp->next;
  }
  cout<<endl;
}

int main(){
  LinkedList *list=new LinkedList();
  int A[]={11,22,33,44,55,66,77,88,9};
  int size=sizeof(A)/sizeof(A[0]);
  //sort(A,A+size);

  //Creating a List
  for(int i=0; i<size; i++)
    list->createlist(A[i]);
  list->displaylist(list->head);

  //Check if list is sorted or not
  int res=list->isSorted(list->head);
  (res==1)?cout<<"List is Sorted"<<endl:cout<<"List is not sorted"<<endl;
}
