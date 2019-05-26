#include<iostream>
#include<cstdlib>
using namespace std;

typedef struct Node{
  int data;
  struct Node *next;
}node;

class LinkedList{
  public:
  node *head=NULL;
  node *tail=NULL;
  void createnode(int data);
  void display(node *temp);
  void insertbegin(node *temp, int data);
  void insertend(node *temp, int data);
  void insertpos(node *temp, int data, int pos);
  

};

void LinkedList::createnode(int data){
  node *temp=new node;
  temp->data=data;
  temp->next=NULL;

  if(head==NULL){
    head=temp;
    tail=temp;
  }
  else{
    tail->next=temp;
    tail=temp;
  }

}

void LinkedList::insertbegin(node *temp, int data){
  node *start=new node();
  start->data=data;
  start->next=NULL;

  if(temp==NULL){
    head=start;
    tail=start;
  }
  else{
    start->next=temp;
    head=start;
  }
}
void LinkedList::insertend(node *temp, int data){
  node *end=new node();
  end->data=data;
  end->next=NULL;

  if(head==NULL){
    head=end;
    tail=end;
  }
  else{
    tail->next=end;
    tail=end;
  }
}
void LinkedList::insertpos(node *temp, int data, int pos){
  node *newnode=new node();
  newnode->data=data;
  newnode->next=NULL;

  if(pos>1){
    node *pre=NULL;
    for(int i=0; i<pos-1; i++){
      pre=temp;
      temp=temp->next;
    }
    pre->next=newnode;
    newnode->next=temp;
  }
}



void LinkedList::display(node *temp){
  while(temp){
    cout<<temp->data<<"|";
    temp=temp->next;
  }
  cout<<endl;

}
int main(){

  LinkedList *list = new LinkedList();
  
  //Creating a LinkedList
  for(int i=0; i<10; i++)
    list->createnode(rand()%100);
  list->display(list->head);


  //Insert an ele 
  //1. At begining
  list->insertbegin(list->head, 0);
  list->display(list->head);

  //2.At end
  list->insertend(list->head,1);
  list->display(list->head);

  //3.At some position
  list->insertpos(list->head, 50, 4);
  list->display(list->head);


  return 0;
}
