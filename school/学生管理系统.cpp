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
			void InitLink(int m);
			void orderfromId();			
			void orderfromEngscore();	
			void orderfromMathscore();	
			void orderfromDatascore();	 
			void showfromId(elemtype e);	 
			void add();				
			void changefromId(elemtype e); 
			void DeletefromId(elemtype e);
			void ShowLink();			
};
void linklist::InitLink(int m){
	flag=m;
	node *p=head,*s;
	for(int i=0;i<m;i++){
			s=new node;
			cout<<"学号：";
			cin>>s->id;
			cout<<endl; 
			cout<<"学生姓名：";
			cin>>s->name;
			cout<<endl; 
			cout<<"数据结构成绩：";
			cin>>s->datascore;
			cout<<endl;
			cout<<"英语成绩：";
			cin>>s->engscore; 
			cout<<endl;
			cout<<"数学成绩：";
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
		cout<<"姓名："<<q->name<<endl<<"学号:"<<q->id<<endl<<"数据结构："<<q->datascore<<endl<<"英语成绩："<<q->engscore<<endl<<"数学成绩："<<q->mathscore<<endl; 
	}else{ 
		cout<<"id:"<<e<<"不存在"<<endl;
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
		cout<<"学号:"<<e<<"不存在"<<endl; 
	}
}
void linklist::changefromId(elemtype e){
		node *q=head;
	while(q->next&&q->id!=e){
		q=q->next;
	}
	if(q->id==e){
		 	cout<<"学号：";
			cin>>q->id;
			cout<<endl; 
			cout<<"学生姓名：";
			cin>>q->name;
			cout<<endl; 
			cout<<"数据结构成绩：";
			cin>>q->datascore;
			cout<<endl;
			cout<<"英语成绩：";
			cin>>q->engscore; 
			cout<<endl;
			cout<<"数学成绩：";
			cin>>q->mathscore;
			cout<<"success"<<endl;
	}
	else{
		cout<<"学号:"<<e<<"不存在"<<endl;
	};
}
void linklist::add(){
	node *s,*q=head;
	s=new node;
		cout<<"学号：";
			cin>>s->id;
			cout<<endl; 
			cout<<"学生姓名：";
			cin>>s->name;
			cout<<endl; 
			cout<<"数据结构成绩：";
			cin>>s->datascore;
			cout<<endl;
			cout<<"英语成绩：";
			cin>>s->engscore; 
			cout<<endl;
			cout<<"数学成绩：";
			cin>>s->mathscore;
			cout<<endl;
			s->next=q->next;
			q->next=s;
			flag++;
			orderfromId();
}
void linklist::ShowLink(){
	node *q=head->next;
	float eng=0,math=0,data=0,flag=0,data_g=0,data_p=0,eng_g=0,eng_p=0,math_g=0,math_p=0;
	while(q){
		if(q->engscore>=60)
		eng_g++;
		else
		eng_p++;
		if(q->datascore>=60)
		data_g++;
		else
		data_p++;
		if(q->mathscore>=60)
		math_g++;
		else
		math_p++;		
		eng+=q->engscore;
		math+=q->mathscore;
		data+=q->datascore;
		flag++;
			cout<<"学生姓名："<<q->name<<endl<<"学号:"<<q->id<<endl<<"数据结构成绩："<<q->datascore<<endl<<"英语成绩："<<q->engscore<<endl<<"数学成绩："<<q->mathscore<<endl; 
			q=q->next;
	}
	cout<<endl<<endl<<endl<<"平均分："<<endl<<"英语平均分："<<eng/flag<<endl<<"数学平均分："<<math/flag<<endl<<"数据结构平均分："<<data/flag<<endl;
	cout<<endl<<endl<<endl<<"英语及格人数："<<eng_g<<endl<<"英语不及格人数：" <<eng_p<<endl<<"数学及格人数："<<math_g<<endl<<"数学不及格人数：" <<math_p<<endl; 
	cout<<"数据结构及格人数："<<data_g<<endl<<"数据结构不及格人数：" <<data_p<<endl; 
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
	for(int i=0;i<flag;i++){
	node *q=head,*p=head->next,*s=p->next,*a;
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
	for(int i=0;i<flag;i++){
	node *q=head,*p=head->next,*s=p->next,*a;
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
	for(int i=0;i<flag;i++){
	node *q=head,*p=head->next,*s=p->next,*a;
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
	cout<<"请输入学生数量";
	int m;
	cin>>m;
	cout<<"初始化"<<endl; 
	link.InitLink(m);
	int mark=1;
	cout<<"0:初始化"<<endl; 
	cout<<"1：根据学号进行排序"<<endl; 
	cout<<"2：根据英语成绩排序"<<endl;
	cout<<"3：根据数学成绩排序"<<endl;
	cout<<"4：根据数据结构成绩进行排序"<<endl;
	cout<<"5：根据学号查询"<<endl;
	cout<<"6：添加学生信息"<<endl;
	cout<<"7：根据学号修改学生信息"<<endl;
	cout<<"8：根据学号删除学生信息"<<endl;
	cout<<"9：展示列表"<<endl;
	cout<<"10：退出"<<endl; 
	while(mark){
		int a;
		cout<<"选择序号：";
		cin>>a;
		switch (a){
			case 0: 	link.InitLink(m);break;
			case 1: link.orderfromId();break;
			case 2: link.orderfromEngscore();break;
			case 3: link.orderfromMathscore();break;
			case 4: link.orderfromDatascore();break;
			case 5: cout<<"输入学号：";int b;cin>>b;link.showfromId(b);break;
			case 6: link.add();break;
			case 7: cout<<"输入学号：";int c;cin>>c;link.changefromId(c);break;
			case 8: cout<<"输入学号：";int d;cin>>d;link.DeletefromId(d);break;
			case 9: link.ShowLink();break;
			case 10: mark=0;break;
		}
	}
	return 0;
}
