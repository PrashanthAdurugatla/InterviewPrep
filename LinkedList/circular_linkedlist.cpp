#include <iostream>
using namespace std;

typedef struct Node{
  int data;
  struct Node *next;
}node;

class LinkedList{
  public:
  node *head=NULL;
  node *last=NULL;
  int length=0;

  void createlist(int data);
  void displaylist(node *temp);
  void insertnode(node *temp, int pos, int ele);
  void deletenode_pos(node *temp, int pos);
  int deletenode_ele(node *temp, int ele);
  bool isLoop(node *temp);
  void Rdisplaylist(node *temp);
};


void LinkedList:: createlist(int data){
  node *newnode=new node();
  newnode->data=data;
  newnode->next=NULL;

  if(head==NULL){
    head=newnode;
    head->next=head;
    last=head;
  } 
  else{
    last->next=newnode;
    last=newnode;
    last->next=head;  
  }
  length++;
}

void LinkedList::insertnode(node *temp, int pos, int ele){
  node *newnode=new node();
  newnode->data=ele;
  newnode->next=NULL;

  if(pos<1 || pos>length+1)
    cout<<"Error in Inserting"<<endl;

  else if(pos==1){
    if(head==NULL){
      head=newnode;
      head->next=head;
      last=newnode;
    }
    else{
      newnode->next=head;
      head=newnode;
      last->next=newnode;
    }
    length++;
  }

  else if(pos==length+1){
    last->next=newnode;
    last=newnode;
    last->next=head;
    length++;
  }

  else{
    node *prev;
    for(int i=0; i<pos-1; i++){
      prev=temp;
      temp=temp->next;
    }
    prev->next=newnode;
    newnode->next=temp;
    length++;
  }
}

void LinkedList::deletenode_pos(node *temp, int pos){

  if(pos<1 || pos>length)
    cout<<"Error in Deleteing"<<endl;
  
  else if(pos==1){
    head=head->next;
    last->next=head;
    length--;
  }

  else if(pos==length){
    while(temp->next!=last){
      temp=temp->next;
    }
    last=temp;
    last->next=head;
    length--;
  }

  else{
    node *prev;
    for(int i=0; i<pos-1; i++){
      prev=temp;
      temp=temp->next;
    }
    prev->next=temp->next;
    length--;
  }
}

int LinkedList::deletenode_ele(node *temp, int ele){
  int pos=-1;
  for(int i=1; i<=length; i++){
    if(temp->data==ele){
      pos=i;
      return pos;
    }
    else
      temp=temp->next;  
  }
return pos;
}

bool LinkedList::isLoop(node *temp){
  node *p=temp;
  node *q=temp;

  do{
    p=p->next;
    q=q->next;
    q=(q!=NULL)?q->next:NULL;
  }while(p!=q && p && q);
  if(p==q)
    return 1;
  return 0;
}

void LinkedList::displaylist(node *temp){
  do{
    cout<<temp->data<<"|";
    temp=temp->next;
  }while(temp!=head);
  cout<<endl;
}

void LinkedList::Rdisplaylist(node *temp){
  static int flag=0;
  if(temp!=head || flag==0){
    flag=1;
    Rdisplaylist(temp->next);
    cout<<temp->data<<"|";
  }
  flag=0;
}

int main() {
  
  LinkedList *list=new LinkedList();

//Create a Circular List  
  for(int i=0; i<5; i++)
    list->createlist(rand()%100);
  list->displaylist(list->head);

//Insert an element in a particular Position
  list->insertnode(list->head, 1, 10);
  list->displaylist(list->head);

//Delete an element using position
  list->deletenode_pos(list->head, 6);
  list->displaylist(list->head);

//Delete an element with out using position
   int pos=list->deletenode_ele(list->head, 15);
   cout<<"Element Found at Position: "<<pos<<endl;
   list->deletenode_pos(list->head, pos);
   list->displaylist(list->head);

//Check if List has a Loop
  int res=list->isLoop(list->head);
  (res==1)?cout<<"There is a loop in list"<<endl:cout<<"There is No loop in list"<<endl;

//Display list elements in Reverse Order
 list->Rdisplaylist(list->head); //Reverse Display use static flag since it's recursive stop creating multiple flags in each fun call

 }
