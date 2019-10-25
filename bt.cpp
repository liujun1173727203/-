 #include<iostream>
 using namespace std;
 typedef struct bitnode{
    char data;
    bitnode *lchild,*rchild;
  }bitnode;
 class bit{
   bitnode *bt;
   void create(bitnode *&t);
   void inorder(bitnode *t);
   int hight(bitnode *t);
   int countleaf(bitnode *t);
   int countnode(bitnode *t);
   void changetree(bitnode *&t);
  public:
   void createbitree();
   void inorderbitree();
   int hightree();
   int countleaftree();
   int countnodetree();
   void changetreebit();
 };
 void bit::create(bitnode *&t){
    char ch;
    cin>>ch;
    if(ch=='.')t=NULL;
    else{
       t=new bitnode;
       t->data=ch;
       create(t->lchild);
       create(t->rchild);
    }
   }
  void bit::createbitree(){
    bitnode *t;
    create(t);
    bt=t;cout<<bt->data<<endl;
  }
  void bit::inorder(bitnode *t){
    if(t){
      inorder(t->lchild);
      cout<<t->data;
      inorder(t->rchild);
    }    
   }
  int bit::countleaf(bitnode *t){
    if(t){
      int m=countleaf(t->lchild);
      int n=countleaf(t->rchild);
      if(m+n==0)return 1;
      else return m+n;      
    }
    else return 0;
   }
  int bit::countleaftree(){
    bitnode *t=bt;
    return countleaftree();
  }

  void bit::inorderbitree(){
    bitnode *t=bt;
    inorder(t);
  }
  int bit::hight(bitnode *t){
    if(t==NULL)return 0;
    else{
      int m=1+hight(t->lchild);
      int n=1+hight(t->rchild);
      if(m>=n)return m;
      else return n;
    }
   }
  int bit:: hightree(){
    bitnode *t=bt;
    return hight(t);
   } 
  int bit::countnode(bitnode *t){
    if(t==NULL)return 0;
    else{
      int m=countnode(t->lchild);
      int n=countnode(t->rchild);
      return 1+m+n;
    } 
   }
  int bit::countnodetree(){
    bitnode *t=bt;
    return countnode(t);
   }
 void bit::changetree(bitnode *&t){
    bitnode *temp=new bitnode;
    if(t){
      temp=t->lchild;
      t->lchild=t->rchild;
      t->rchild=temp;
      changetree(t->lchild);
      changetree(t->rchild);
    }
   }
 void bit::changetreebit(){
    bitnode *t;
    changetree(t);
    bt=t;
  }
 int main(){
    bit tt;
    tt.createbitree();
    cout<<tt.countnodetree();
  return 0;
  }




