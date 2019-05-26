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
  int length=0;

  void createnode(int data);
  void display(node *temp);
  void insertele(node *temp, int data, int pos);
 
  node* addnewnode(int data){
    node *newnode=new node();
    newnode->data=data;
    newnode->next=NULL;
    return newnode;
  }
};


void LinkedList::createnode(int data){
  node *newnode;
  newnode=addnewnode(data);

  if(head==NULL){
    head=newnode;
    tail=newnode;
    length++;
  }
  else{
    tail->next=newnode;
    tail=newnode;
    length++;
  }
}

void LinkedList::insertele(node *temp, int data, int pos){
  if(pos<1 || pos>length+1)
    cout<<"Error in Inserting"<<endl;

  //1. Insert Beginning --> Update head pointer & length
  else if(pos==1){
    node* newnode;
    newnode=addnewnode(data);

    if(head==NULL){
      head=newnode;
      tail=newnode;
    }
    else{
      newnode->next=head;
      head=newnode;
    }
    length++;
  }

  //2. Insert in the end --> Update tail pointer & length
  else if(pos==length+1){
    node *newnode;
    newnode=addnewnode(data);

    if(head!=NULL){
      tail->next=newnode;
      tail=newnode;
      length++;
    }
  }

  //3. Insert in between --> update only length
  else{
    node *newnode;
    newnode=addnewnode(data);

    node *prev=NULL;
    for(int i=0; i<pos-1; i++){
      prev=temp;
      temp=temp->next;
    }
    prev->next=newnode;
    newnode->next=temp;
    length++;
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
  for(int i=0; i<10; i++)
    list->createnode(rand()%100);
  list->display(list->head);

  list->insertele(list->head, 11, 11);
  list->display(list->head);
  return 0;
}
