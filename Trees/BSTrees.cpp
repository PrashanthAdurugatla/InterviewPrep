#include<iostream>
using namespace std;


typedef struct Node{
    int data;
    struct Node *left;
    struct Node *right;    
}node;

class Tree{
    public:
        node *root=NULL;
        node *insert(node *temp, int data);
        void search(node *temp, int key);
        void display(node *temp);
        int height(node *temp);
        int sum(node *temp);
        int totalnodes(node *temp);
        int leafnodes(node *temp);
        int fullnodes(node *temp);
        node *deletenode(node *temp, int key);
        node *Inpre(node *q);
        node *Insuc(node *q);


};

node * Tree::insert(node *temp, int data){
    if(temp==NULL){
        node *newnode = new node();
        newnode->data=data;
        newnode->left=newnode->right=NULL;
        temp=newnode;    
    }
    else if(data<temp->data){
        temp->left = insert(temp->left, data);
    }
    else{
        temp->right = insert(temp->right, data);
    }
    return temp;
}

void Tree::search(node *temp, int key){
  if(temp!=NULL){
    if(temp->data==key)
      cout<<key<<" Is found"<<endl;
    else if(key<temp->data)
      search(temp->left, key);
    else
      search(temp->right, key);    
  }
  else{
      cout<<key<<" Is not found"<<endl;
  }
}

void Tree::display(node *temp){
  if(temp){
    display(temp->left);
    cout<<temp->data<<"|";
    display(temp->right);
  }
}

int Tree::height(node *temp){
  int l, r;
  if(temp){
    l=height(temp->left);
    r=height(temp->right);
    return (l>r)? l+1 : r+1 ;
  }
  else
  return 0;
}

int Tree::sum(node *temp){
  int l, r;
  if(temp){
    l =sum(temp->left);
    r =sum(temp->right);
    return l+r+temp->data;
  }
  else 
    return 0;
}

int Tree::totalnodes(node *temp){
  int l, r;
  if(temp){
    l=totalnodes(temp->left);
    r=totalnodes(temp->right);
    return l+r+1;
  }
  return 0;
}

int Tree::leafnodes(node *temp){
  int l,r;
  if(temp){
    l=leafnodes(temp->left);
    r=leafnodes(temp->right);
    if(temp->left==NULL && temp->right==NULL)
      return l+r+1;
    else
      return l+r;
  }
  return 0;
}

int Tree::fullnodes(node *temp){
  int l,r;
  if(temp){
    l=fullnodes(temp->left);
    r=fullnodes(temp->right);
    if(temp->left!=NULL && temp->right!=NULL)
      return l+r+1;
    else
      return l+r;
  }
  else
    return 0;
}

node* Tree::deletenode(node *temp, int key){
  node *q = NULL;
  if(temp==NULL)
    return NULL;

  if(temp->left==NULL && temp->right==NULL)
  {
    if(temp==root)
      root=NULL;
    delete [] temp;
    return NULL;
  }

  if(key<temp->data){
    temp->left = deletenode(temp->left, key);
  }
  else if(key>temp->data){
    temp->right = deletenode(temp->right, key);
  }
  else{
    if(height(temp->left)>height(temp->right)){
      q=Inpre(temp->left);
      temp->data=q->data;
      temp->left = deletenode(temp->left,q->data);
    }
    else{
      q=Insuc(temp->right);
      temp->data=q->data;
      temp->right = deletenode(temp->right, q->data);
    }
  }
  return temp;
  
}

node* Tree::Inpre(node *q){
  while(q && q->right!=NULL)
    q=q->right;
  return q;
}

node* Tree::Insuc(node *q){
  while(q && q->left!=NULL)
    q=q->left;
  return q;
}

int main(){
    Tree *t = new Tree;

    t->root = t->insert(t->root, 45);
    t->insert(t->root, 55);
    t->insert(t->root, 35);
    t->insert(t->root, 25);
    t->insert(t->root, 65);
    t->insert(t->root, 15);
    
    t->display(t->root);

    cout<<'\n';
    t->search(t->root, 15);

    t->deletenode(t->root, 15);
    t->search(t->root, 15);

    t->display(t->root);

    cout<<"\nThe Height of the Tree: "<<t->height(t->root)<<endl;
    
    cout<<"The Sum of the Tree: "<<t->sum(t->root)<<endl;

    cout<<"The Total Nodes in the Tree: "<<t->totalnodes(t->root)<<endl;

    cout<<"The Leaf Nodes in the Tree: "<<t->leafnodes(t->root)<<endl;

    cout<<"The Full Nodes in the Tree: "<<t->fullnodes(t->root)<<endl;

  
   
}
