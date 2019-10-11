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
			void InitLink(int m);		//初始化表单
			void orderfromId();			//根据id排序
			void orderfromEngscore();	//根据英语成绩排序；
			void orderfromMathscore();	//根据数学成绩排序
			void orderfromDatascore();	//根据数据结构成绩排序 
			void showfromId(elemtype e);	//通过id查找一名学生信息 
			void add();				//插入一名学生信息
			void changefromId(elemtype e);//通过id修改一名同学信息 
			void DeletefromId(elemtype e);		//删除一名学生信息 
			void ShowLink();			//表单输出 
};
void linklist::InitLink(int m){
	flag=m;
	node *p=head,*s;
	for(int i=0;i<m;i++){
			s=new node;
			cout<<"输入学生学号：";
			cin>>s->id;
			cout<<endl; 
			cout<<"输入学生姓名：";
			cin>>s->name;
			cout<<endl; 
			cout<<"输入学生数据结构成绩：";
			cin>>s->datascore;
			cout<<endl;
			cout<<"输入学生英语成绩：";
			cin>>s->engscore; 
			cout<<endl;
			cout<<"输入学生高数成绩：";
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
		cout<<"姓名："<<q->name<<endl<<"学号:"<<q->id<<endl<<"数据结构成绩："<<q->datascore<<endl<<"英语成绩："<<q->engscore<<endl<<"高数成绩："<<q->mathscore<<endl; 
	}else{ 
		cout<<"学号:"<<e<<"不存在"<<endl;
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
		 	cout<<"输入学生学号：";
			cin>>q->id;
			cout<<endl; 
			cout<<"输入学生姓名：";
			cin>>q->name;
			cout<<endl; 
			cout<<"输入学生数据结构成绩：";
			cin>>q->datascore;
			cout<<endl;
			cout<<"输入学生英语成绩：";
			cin>>q->engscore; 
			cout<<endl;
			cout<<"输入学生高数成绩：";
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
		cout<<"输入学生学号：";
			cin>>s->id;
			cout<<endl; 
			cout<<"输入学生姓名：";
			cin>>s->name;
			cout<<endl; 
			cout<<"输入学生数据结构成绩：";
			cin>>s->datascore;
			cout<<endl;
			cout<<"输入学生英语成绩：";
			cin>>s->engscore; 
			cout<<endl;
			cout<<"输入学生高数成绩：";
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
			cout<<"姓名："<<q->name<<endl<<"学号:"<<q->id<<endl<<"数据结构成绩："<<q->datascore<<endl<<"英语成绩："<<q->engscore<<endl<<"高数成绩："<<q->mathscore<<endl; 
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
	cout<<"表单大小为：";
	int m;
	cin>>m;
	cout<<"输入数据："<<endl; 
	link.InitLink(m);
	int mark=1;
	cout<<"0:初始化"<<endl; 
	cout<<"1：根据id排序"<<endl; 
	cout<<"2：根据英语成绩排序；"<<endl;
	cout<<"3：根据数学成绩排序"<<endl;
	cout<<"4：根据数据结构成绩排序 "<<endl;
	cout<<"5：通过id查找一名学生信息"<<endl;
	cout<<"6：插入一名学生信息"<<endl;
	cout<<"7：通过id修改一名同学信息 "<<endl;
	cout<<"8：删除一名学生信息  "<<endl;
	cout<<"9：表单输出 "<<endl;
	cout<<"10:退出"<<endl; 
	while(mark){
		int a;
		cout<<"选择操作：";
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
