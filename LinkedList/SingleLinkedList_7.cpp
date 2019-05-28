#include <iostream>
using namespace std;

typedef struct Node{
  int data;
  struct Node *next;
}node;

class LinkedList{
  public:
  node *head=NULL;
  void createlist(int data);
  void displaylist(node *temp);
  bool isLoop(node *temp);
};


void LinkedList:: createlist(int data){
  node *newnode=new node();
  newnode->data=data;
  newnode->next=NULL;

  if(head==NULL)
    head=newnode;
  
  else{
    node *temp=head;
    while(temp->next){
      temp=temp->next;
    }
    temp->next=newnode;
    temp=newnode;
    temp->next=head;     //Trying to make list as loop

  }
}

bool LinkedList::isLoop(node *temp){
  node *p=temp;
  node *q=temp->next->next;
  while(temp){
    if(p==q){
      return true;
    }
    temp=temp->next;
  }
  return false;
}


void LinkedList::displaylist(node *temp){
  while(temp){
    cout<<temp->data<<"|";
    temp=temp->next;
  }
  cout<<endl;
}


int main() {
  
  LinkedList *list=new LinkedList();
  for(int i=0; i<2; i++)
    list->createlist(rand()%100);
  // list->displaylist(list->head);

  int res=list->isLoop(list->head);
  (res==1)?cout<<"There is a loop in list"<<endl:cout<<"There is No loop in list"<<endl;


 }
