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
  void count(node*temp);
  int sum(node *temp);
  int max(node *temp);
  void rdisplay(node *temp);
  void reverseList(node *temp);
  int Lsearch(node *temp, int ele);
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

void LinkedList::count(node *temp){
  int count;
  while(temp!=NULL){
    count++;
    temp=temp->next;
  }
  cout<<"The length of linkedList is: "<<count<<endl;
}

int LinkedList::sum(node *temp){
  if(temp==NULL)
    return 0;
  else{
    return sum(temp->next)+temp->data;
  }

}

int LinkedList::max(node *temp){
  int max = 0;
  while(temp){
    if(temp->data>max)
      max=temp->data;
    temp=temp->next;
  }
  return max;

}

void LinkedList::rdisplay(node *temp){
  if(temp){
    rdisplay(temp->next);
    cout<<temp->data<<"|";
  }
}

void LinkedList::reverseList(node *temp){
  node *prev=NULL;
  node *cur=NULL;

  while(temp){
    prev=cur;
    cur=temp;
    temp=temp->next;
    cur->next=prev;
  }
  head=cur;

  tail=head;
  while(tail->next){
    tail=tail->next;
  }
}

int LinkedList::Lsearch(node *temp, int ele){
  while(temp){
    if(temp->data==ele)
      return ele;
    temp=temp->next;
  }
  return -1;
}




void LinkedList::display(node *temp){
  while(temp!=NULL){
    cout<<temp->data<<"|";
    temp=temp->next;
  }
  cout<<endl;
    
}

int main(){
  LinkedList *list = new LinkedList();
  
  
  //Create and Display the LinkedList
  for(int i=0; i<10; i++)
    list->createnode(rand()%100);
  list->display(list->head);

  //Finding Number of Ele in LinkedList
  list->count(list->head);
  
  //Finding Sum of Ele in LinkedList
  int r1=list->sum(list->head);
  cout<<"The sum of LinkedList is: "<<r1<<endl;

  //Finding Max Ele in LinkedList
  int r2=list->max(list->head);
  cout<<"The Max of LinkedList is: "<<r2<<endl;

  //Reverse the linkedList
  list->reverseList(list->head);
  list->createnode(79); //Checking Tail pointer after reversing the List
  list->display(list->head);
  
  //Display Ele in Reverse Order
  list->rdisplay(list->head);
  cout<<endl;

  //Searching in the List
  int r3=list->Lsearch(list->head,72);
  (r3=-1)?cout<<"Element not found"<<endl:cout<<"Element is in the List"<<endl;





}
