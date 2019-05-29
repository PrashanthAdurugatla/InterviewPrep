#include<iostream>
using namespace std;

typedef struct Node{
  int data;
  struct Node *prev;
  struct Node *next;
}node;

class DoubleLL{
  public:
  node *head=NULL;
  node *tail=NULL;
  int length=0;

  void createnode(int data);
  void displaylist(node *temp);
  void insertnode(node *temp, int pos, int ele);
  void deletenode(node *temp, int pos);
};

void DoubleLL::createnode(int data){
  node *newnode=new node();
  newnode->data=data;
  newnode->prev=newnode->next=NULL;

  if(head==NULL){
    head=tail=newnode;
    length++;
  }
  else{
    tail->next=newnode;
    newnode->prev=tail;
    tail=newnode;
    length++;
  }
}

void DoubleLL::insertnode(node *temp, int pos, int ele){
  node *newnode=new node();
  newnode->data=ele;
  newnode->prev=newnode->next=NULL;

  if(pos<1 || pos>length+1)
    cout<<"Error in Inserting"<<endl;

  else if(pos==1){
    if(head==NULL){
      head=tail=newnode;
      length++;
    }
    else{
      newnode->next=head;
      head->prev=newnode;
      head=newnode;
      length++;
    }
  }
  else if(pos==length+1){
    if(head!=NULL){
      tail->next=newnode;
      newnode->prev=tail;
      tail=newnode;
      length++;
    }
  }
  else{
    node *p=NULL;
    for(int i=0; i<pos-1; i++){
      p=temp;
      temp=temp->next;
    }
    p->next=newnode;
    newnode->prev=p;
    newnode->next=temp;
    temp->prev=newnode;
    length++;
  }
}

void DoubleLL::deletenode(node *temp, int pos){
  if(pos<1 || pos>length)
    cout<<"Error in deleting"<<endl;

  else if(pos==1){
    head=head->next;
    head->prev=NULL;
    length--;
  }

  else if(pos==length){
    while(temp->next!=tail){
      temp=temp->next;
    }
    tail=temp;
    tail->next=NULL;
    length--;
  }

  else{
    node *p=NULL;
    for(int i=0; i<pos-1; i++){
      p=temp;
      temp=temp->next;
    }
    p->next=temp->next;
    temp->next->prev=p;
    length--;
  }
}

void DoubleLL::displaylist(node *temp){
  while(temp){
    cout<<temp->data<<"|";
    temp=temp->next;
  }
  cout<<endl;
}

int main(){
  DoubleLL *list=new DoubleLL();
  for(int i=0; i<10; i++)
    list->createnode(rand()%100);
  
  list->displaylist(list->head);
  //list->displaylist(list->tail);      //Reverse Display 

  //Inserting a node in List
  list->insertnode(list->head, 11, 11); //Adding in the end
  list->insertnode(list->head, 1, 1);   //Addind at Beginning
  list->displaylist(list->head);

  //Deleting a Node from List
  list->deletenode(list->head, 10);
  list->displaylist(list->head);
}
