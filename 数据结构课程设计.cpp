#include <iostream>
using namespace std;
typedef int elemtype;
struct node{
	string name;
	elemtype datascore;
	elemtype engscore;
	elemtype mathscore; 
	elemtype id;
	node *next;
};
class linklist{
	private:
		node *head;
		int flag;
		public:
			linklist(){
				head =new node;
				flag=0;
				head->next=NULL;
			};
			void InitLink(int m);		//��ʼ������
			void orderfromId();			//����id����
			void orderfromEngscore();	//����Ӣ��ɼ�����
			void orderfromMathscore();	//������ѧ�ɼ�����
			void orderfromDatascore();	//�������ݽṹ�ɼ����� 
			void showfromId(elemtype e);	//ͨ��id����һ��ѧ����Ϣ 
			void add();				//����һ��ѧ����Ϣ
			void changefromId(elemtype e);//ͨ��id�޸�һ��ͬѧ��Ϣ 
			void DeletefromId(elemtype e);		//ɾ��һ��ѧ����Ϣ 
			void ShowLink();			//������� 
};
void linklist::InitLink(int m){
	flag=m;
	node *p=head,*s;
	for(int i=0;i<m;i++){
			s=new node;
			cout<<"����ѧ��ѧ�ţ�";
			cin>>s->id;
			cout<<endl; 
			cout<<"����ѧ��������";
			cin>>s->name;
			cout<<endl; 
			cout<<"����ѧ�����ݽṹ�ɼ���";
			cin>>s->datascore;
			cout<<endl;
			cout<<"����ѧ��Ӣ��ɼ���";
			cin>>s->engscore; 
			cout<<endl;
			cout<<"����ѧ�������ɼ���";
			cin>>s->mathscore;
			cout<<endl;
			s->next=NULL;
			p->next=s; 
			p=s;
	}
	cout<<"finish"<<endl;
}
void linklist::showfromId(elemtype e){
	node *q=head;
	while(q->next&&q->id!=e){
		q=q->next;
	}; 
	if(q->id==e){
		cout<<"������"<<q->name<<endl<<"ѧ��:"<<q->id<<endl<<"���ݽṹ�ɼ���"<<q->datascore<<endl<<"Ӣ��ɼ���"<<q->engscore<<endl<<"�����ɼ���"<<q->mathscore<<endl; 
	}else{ 
		cout<<"ѧ��:"<<e<<"������"<<endl;
		} 
}
void linklist::DeletefromId(elemtype e){
	node *q=head,*p=head->next;
	while(p->next&&p->id!=e){
		q=p;
		p=p->next; 
	}
	if(p->id==e){
		q->next=p->next;
		delete p;
		flag--;
		cout<<"success"<<endl;
	}
	else{
		cout<<"ѧ��:"<<e<<"������"<<endl; 
	}
}
void linklist::changefromId(elemtype e){
		node *q=head;
	while(q->next&&q->id!=e){
		q=q->next;
	}
	if(q->id==e){
		 	cout<<"����ѧ��ѧ�ţ�";
			cin>>q->id;
			cout<<endl; 
			cout<<"����ѧ��������";
			cin>>q->name;
			cout<<endl; 
			cout<<"����ѧ�����ݽṹ�ɼ���";
			cin>>q->datascore;
			cout<<endl;
			cout<<"����ѧ��Ӣ��ɼ���";
			cin>>q->engscore; 
			cout<<endl;
			cout<<"����ѧ�������ɼ���";
			cin>>q->mathscore;
			cout<<"success"<<endl;
	}
	else{
		cout<<"ѧ��:"<<e<<"������"<<endl;
	};
}
void linklist::add(){
	node *s,*q=head;
	s=new node;
		cout<<"����ѧ��ѧ�ţ�";
			cin>>s->id;
			cout<<endl; 
			cout<<"����ѧ��������";
			cin>>s->name;
			cout<<endl; 
			cout<<"����ѧ�����ݽṹ�ɼ���";
			cin>>s->datascore;
			cout<<endl;
			cout<<"����ѧ��Ӣ��ɼ���";
			cin>>s->engscore; 
			cout<<endl;
			cout<<"����ѧ�������ɼ���";
			cin>>s->mathscore;
			cout<<endl;
			s->next=q->next;
			q->next=s;
			flag++;
			orderfromId();
}
void linklist::ShowLink(){
	node *q=head->next;
	while(q){
			cout<<"������"<<q->name<<endl<<"ѧ��:"<<q->id<<endl<<"���ݽṹ�ɼ���"<<q->datascore<<endl<<"Ӣ��ɼ���"<<q->engscore<<endl<<"�����ɼ���"<<q->mathscore<<endl; 
			q=q->next;
	}
	cout<<"finish"<<endl;
}
void linklist::orderfromId(){
	for(int i=0;i<flag;i++){
		node *q=head,*p=head->next,*s=p->next,*a;
		for(int j=i+1;j<flag;j++){
			if(p->id>=s->id){
				p->next=s->next;
				s->next=p;
				q->next=s;
				q=q->next;
				s=p->next;
			}
			else{
				q=q->next;
				p=p->next;
				s=s->next;
			}
			
		}
	}
		cout<<"success"<<endl; 
}
void linklist::orderfromEngscore(){
	node *q=head,*p=head->next,*s=p->next,*a;
	for(int i=0;i<flag;i++){
		for(int j=i+1;j<flag;j++){
			if(p->engscore>=s->engscore){
				p->next=s->next;
				s->next=p;
				q->next=s;
				q=q->next;
				s=p->next;
			}
			else{
				q=q->next;
				p=p->next;
				s=s->next;
			}
			
		}
	}
		cout<<"success"<<endl; 
}
void linklist::orderfromDatascore(){
	node *q=head,*p=head->next,*s=p->next,*a;
	for(int i=0;i<flag;i++){
		for(int j=i+1;j<flag;j++){
			if(p->datascore>=s->datascore){
				p->next=s->next;
				s->next=p;
				q->next=s;
				q=q->next;
				s=p->next;
			}
			else{
				q=q->next;
				p=p->next;
				s=s->next;
			}
			
		}
	}
		cout<<"success"<<endl; 
}
void linklist::orderfromMathscore(){
	node *q=head,*p=head->next,*s=p->next,*a;
	for(int i=0;i<flag;i++){
		for(int j=i+1;j<flag;j++){
			if(p->mathscore>=s->mathscore){
				p->next=s->next;
				s->next=p;
				q->next=s;
				q=q->next;
				s=p->next;
			}
			else{
				q=q->next;
				p=p->next;
				s=s->next;
			}
			
		}
	}
		cout<<"success"<<endl; 
}

int main(int argc, char** argv) {
	linklist link;
	cout<<"������СΪ��";
	int m;
	cin>>m;
	cout<<"�������ݣ�"<<endl; 
	link.InitLink(m);
	int mark=1;
	cout<<"0:��ʼ��"<<endl; 
	cout<<"1������id����"<<endl; 
	cout<<"2������Ӣ��ɼ�����"<<endl;
	cout<<"3��������ѧ�ɼ�����"<<endl;
	cout<<"4���������ݽṹ�ɼ����� "<<endl;
	cout<<"5��ͨ��id����һ��ѧ����Ϣ"<<endl;
	cout<<"6������һ��ѧ����Ϣ"<<endl;
	cout<<"7��ͨ��id�޸�һ��ͬѧ��Ϣ "<<endl;
	cout<<"8��ɾ��һ��ѧ����Ϣ  "<<endl;
	cout<<"9��������� "<<endl;
	cout<<"10:�˳�"<<endl; 
	while(mark){
		int a;
		cout<<"ѡ�������";
		cin>>a;
		switch (a){
			case 0: 	link.InitLink(m);break;
			case 1: link.orderfromId();break;
			case 2: link.orderfromEngscore();break;
			case 3: link.orderfromMathscore();break;
			case 4: link.orderfromDatascore();break;
			case 5: cout<<"����ѧ�ţ�";int b;cin>>b;link.showfromId(b);break;
			case 6: link.add();break;
			case 7: cout<<"����ѧ�ţ�";int c;cin>>c;link.changefromId(c);break;
			case 8: cout<<"����ѧ�ţ�";int d;cin>>d;link.DeletefromId(d);break;
			case 9: link.ShowLink();break;
			case 10: mark=0;break;
		}
	}
	return 0;
}
