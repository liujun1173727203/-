#include <iostream>
using namespace std;
typedef int elemtype;
struct node{
	elemtype data;
	node *next;
};
class linklist{
	private:
		node *head;
		public:
			linklist(){
				head =new node;
				head->next=NULL;
			}
			~linklist(){
				return ;
			};
			void InitLink(int i);
			void Inserte(int e);;
			void Deletee(elemtype e);
			void turn();
			void midnode();
			void rangedelete(elemtype min,elemtype max);
			node *split(elemtype e);
			node *intersection(node *head1,node* head2);
			void ShowLink();
			node* gethead(){
				return head;
			}
};
node* linklist::intersection(node *head1,node* head2){
	node *q=head1,*q1=head->next,*s,*p=head2,*p1=head2->next;
	if(!q||!p){
		return NULL;
	}
	else{ 
		while(q1->next&&p1->next){
			if(q1->data>p1->data){
				p=p1;
				p1=p1->next; 
			}
			else if(q1->data<p1->data){
				q->next=q1->next;
				delete q1;
				q1=q->next;
			}
			else{
				q=q1;
				q1=q1->next;
			}
		}
		q->next=NULL;
		return head1;
	} 
}
node* linklist::split(elemtype e){
	node *p=head,*q=head->next;
	while(q&&q->data!=e){
		p=q;
		q=q->next;
	}
	 if(p->next==NULL){
	 	cout<<"error"; 
	 	return NULL;
	 }
	 else{
	 		node *head1 =new node;
			head1->next=q;
			cout<<"success";
			return head1;
		 }
}
void linklist::rangedelete(elemtype min,elemtype max){
	node *p=head,*q=head->next;
	while(q&&q->data<=min){
		p=q;
		q=q->next;
	}
	while(q&&q->data<max){
		p->next=q->next;
		delete q;
		q=p->next;
	}
	cout<<"删除完成"<<endl; 
}
void linklist::InitLink(int i){
	node *p=head;
	for (int m=0;m<i;m++){
		node *elem = new node;
		cout<<"输入数据："; 
		cin>>elem->data;
		p->next=elem;
		p=elem;
		p->next=NULL;
	};
	cout<<"初始化完成"<<endl; 
}
void linklist::midnode(){
	node *p=head->next,*q=head->next;
	while(q&&q->next){
		p=p->next;
		q=q->next->next;
	}
	cout<<"中间值为："<<p->data;
}
void linklist::turn(){
	node *p=head,*q=head->next,*s=q->next,*r=head->next;
	cout<<endl<<"倒序";
	if(!q->next||!p->next){
		return;
	}
	else{
		cout<<"b";
		q->next=NULL;
		while(s->next){
			p=s->next;
			s->next=q;
			q=s;
			s=p;
		}
		s->next=q;
		head->next=s;
	}
}
void linklist::Deletee(elemtype e){
	node *p=head,*q=head->next;
	while(q->data!=e&&q->next){
		p=q;
		q=q->next; 
	}
	p->next=q->next;
	delete q;
}
void linklist::Inserte(int e){
	node *q=head,*p=head->next;
	node *s;
	s =new node;
	s->data=e;
	if(!q->next){
		q->next=s;
	}
	else{
		while(p->data<e&&p->next){
			q=p;
			p=p->next;
		}
	};
	if(p->data<e){
		p->next=s;
		s->next=NULL;
	} 
	else{
		q->next=s;
		s->next=p;
	};
}
void linklist::ShowLink(){
	node *p=head;
	cout<<"链表展示:"; 
	while(p->next!=NULL){
		
		cout<<p->next->data<<" ";
		p=p->next;
	}
} 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	linklist demo,demo1;
	node *p,*q;
	p=demo.gethead();
	q=demo1.gethead();
	demo.InitLink(5);
	demo1.InitLink(5);
	p=demo.intersection(p,q);
//	demo.split(3);
//	demo.rangedelete(2,4);
//	demo.midnode();
//	demo.turn();
//	demo.Inserte(4);
//	demo.Deletee(2);
	demo.ShowLink();
	return 0;
}
