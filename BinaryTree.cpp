#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
 struct node{
	int data;
	node *lnode,*rnode;
};
 class BiTree{
	private:
		node *bt;
		void Create(node *&t);
		int countleaf(node *&t);
		void over(node *t); 
		int height(node *&t);
		void changetree(node *&t,int e);
		int countnodeOne(node *&t); 
		int countLarge(node* &t,int e);
		void add(node* &t,int x,int y,int z); 
		int countnode(node* &t);
	public:
		void BTadd();
		void BTcountLarge();
		void BTnode();
		void BTchangeTree(); 
		void BTheight();
		void BTnodeOne();
		void BTcountleaf();
		void BCreate();
		void overBT();
};
void BiTree::BTchangeTree(){
	node *t=bt;
	int e;
	cout<<"输入参数：";
	cin>>e;
	changetree(t,e);
	cout<<"finish"<<endl;
}
void BiTree::changetree(node *&t,int e){
	if(t){
		if(t->data>e){
		node *temp =new node;
		temp=t->lnode;
		t->lnode=t->rnode;
		t->rnode=temp;
		};
		changetree(t->lnode,e);
		changetree(t->rnode,e);	
	}
}
void BiTree::BTheight(){
	node *t=bt;
	cout<<"树高："<<height(bt)<<endl; 
}
int BiTree::height(node *&t){
	if(t==NULL) return 0;
	else{
		int m=height(t->lnode);
		int n=height(t->rnode);
		return m>n?m+1:n+1;
	} 
}
void BiTree::BTcountLarge(){
	int e;
	cout<<"输入比较值:";
	cin>>e; 
	cout<<"个数为："<<countLarge(bt,e)<<endl;
	cout<<"finish";
}
int BiTree::countLarge(node* &t,int e){
if(!t)return 0;
else{	
int m=countLarge(t->lnode,e);
int n=countLarge(t->rnode,e);
if(t->data>e)return 1+m+n;
		else return m+n;
}
}
void BiTree::BTadd(){
	cout<<"依次输入参数：";
	int x,y,z;
	cin>>x>>y>>z;
	add(bt,x,y,z);
}
void BiTree::add(node* &t,int x,int y,int z){
	if(t){
	if(t->data>x)t->data+=y;
	else t->data+=z;
		add(t->lnode,x,y,z);
		add(t->rnode,x,y,z);
	}
}
void BiTree::BTnodeOne(){
	cout<<"度数为1的节点数为："<<countnodeOne(bt)<<endl;
}
int BiTree::countnodeOne(node* &t){
	if(t){
		int m=countnodeOne(t->lnode);
		int n=countnodeOne(t->rnode);
		if((t->lnode==NULL&&t->rnode!=NULL)||(t->lnode!=NULL&&t->rnode==NULL))return 1+n+m;
		else return m+n;
	}
}
void BiTree::BTnode(){
	cout<<"节点数为："<<countnode(bt)<<endl;
}
int BiTree::countnode(node* &t){
	if(!t) return 0;
	else{
		int m=countnode(t->lnode);
		int n=countnode(t->rnode);
		return 1+m+n;
	}
}
void BiTree::BTcountleaf(){
	cout<<"叶子数："<<countleaf(bt)<<endl;
}
int BiTree::countleaf(node *&t){
	if(t){
		int m=countleaf(t->lnode);
		int n=countleaf(t->rnode);
		if(m+n==0)return 1;
		else return m+n;
	}
	else return 0;
}
void BiTree::overBT(){
	node *t=bt;
	over(t);
		cout<<"finish"<<endl;
}
void BiTree::over(node *t){
	if(t){
		over(t->lnode);
		cout<<t->data;
		over(t->rnode);
	}
	cout<<endl;
}
void BiTree::BCreate(){
	node *t;
		Create(t);
		bt=t;
		cout<<"finish"<<endl;
}
void BiTree::Create(node *&t){
	int val;
	cout<<"输入数据：";
	cin>>val;
	if(val==0)t=NULL;
	else{
		t =new node;
		t->data=val;
		Create(t->lnode);
		Create(t->rnode);
	};
}



int main(int argc, char** argv) {
	return 0;
}
