#include<iostream>
using namespace std;
struct time {
	int year;
	int month;
	int day;
};
typedef struct time time;
time *build(time *tim1) {
	cout<<"请输入日期：";
	cin>>tim1->year>>tim1->month>>tim1->day;
	return tim1;
} //创建时间点
int exam(time *tim1) {
	if(tim1->month<1||tim1->month>12||tim1->day<1||tim1->year>10000) {
		return 0;
	} else if(tim1->month==1||tim1->month==3||tim1->month==5||tim1->month==7||tim1->month==8||tim1->month==10||tim1->month==12) {
		if(tim1->day<=31)
			return 1;
		else return 0;
	} else if(tim1->month==4||tim1->month==6||tim1->month==9||tim1->month==11) {
		if(tim1->day<=30)
			return 1;
		else return 0;
	} else if(tim1->month==2&&tim1->year%4==0) {
		if(tim1->day<=29)return 1;
		else return 0;
	} else if(tim1->month==2&&tim1->year%4!=0) {
		if(tim1->day<=28)return 1;
		else return 0;
	} else return 0;
}//检查时间是否符合要求；
int exchang(time *tim1) {
	int time;
	time=tim1->year*10000+tim1->month*100+tim1->day;
	return time;
} //转换时间
struct node {
	int data;
	int time;
	node *next;
};
typedef struct node node;
node *creat(node *head,int w) {
	node *p,*p1;
	p=head;
	p1=head;
	int flag=1,m,date;
	cout<<"结束请输入'0'"<<endl;
	while(flag) {
		time *tim1;
		tim1=new time;
		cout<<"请输入数据:";
		cin>>m;
		if(m==0)break;
		int i=0;
		do {

			tim1=build(tim1);
			i=exam(tim1);
			if(i==0) {
				cout<<"日期不合法，请重新输入"<<endl;
			}
		} while(i==0);
		date=exchang(tim1);
		if(m!=0) {
			node *s=new node;
			s->data=m*w;
			s->time=date;
			p->next=s;
			p=s;
		} else {
			flag=0;
		}
	};
	p->next=NULL;
	head=head->next;
	return head;
};//创建链表
void show(node *head) {
	node *p=head;
	while(p!=NULL) {
		if(p->data>0)
		cout<<p->time/10000<<" "<<p->time%10000/100<<" "<<p->time%100<<"  "<<p->data<<endl;
		p=p->next;
	};

}//打印链表
void show1(node *head) {
	node *p=head;
	int date,i;
	time *tim1=new time;
	do {

		tim1=build(tim1);
		i=exam(tim1);
		if(i==0) {
			cout<<"日期不合法，请重新输入"<<endl;
		}
	} while(i==0);
	date=exchang(tim1);
	while(p!=NULL) {
		if(p->time==date)
		cout<<p->time/10000<<" "<<p->time%10000/100<<" "<<p->time%100<<"  "<<p->data<<endl;
		p=p->next;
	};
}
void show2(node *head) {
	node *p=head;
	while(p!=NULL) {
		if(p->data<0)
		cout<<p->time/10000<<" "<<p->time%10000/100<<" "<<p->time%100<<"  "<<p->data<<endl;
		p=p->next;
	};
}
void add(node *head) {
	node *p=head,*s;
	time *tim1;
	tim1=new time;
	int i=0;
	int time,m;
	s=new node;
	cout<<"请输入数据：";
	cin>>m;
	do {

		tim1=build(tim1);
		i=exam(tim1);
		if(i==0) {
			cout<<"日期不合法，请重新输入"<<endl;
		}
	} while(i==0);
	time=exchang(tim1);
	s->data=m;
	s->time=time;
	while(p->next!=NULL) {
		p=p->next;
	};
	p->next=s;
	s->next=NULL;
	p=s;
}//添加结点
node *del(node *head) {
	cout<<"请输入要删除的日期：";
	time *tim1;
	int date;
	tim1=new time;
	int i=0;
	do {

		tim1=build(tim1);
		i=exam(tim1);
		if(i==0) {
			cout<<"日期不合法，请重新输入"<<endl;
		}
	} while(i==0);
	date=exchang(tim1);
	node *p1, *p2;
	p2 = new node;
	p1 = head;

	while (date != p1->time && p1->next != NULL) {
		p2 = p1;
		p1 = p1->next;// p1和p2位置: p2->p1
	}

	if (date == p1->time) {
		if (p1 == head) { // 删除头节点
			head = p1->next;
			delete p1;
		} else {
			p2->next = p1->next;
			delete p1;
		}
	} else {
		cout << " could not been found in the current single linker!" << endl;
	}
	return head;
}//删除结点
node *insertSort( node *head ) {
	node  *p1, *prep1, *p2, *prep2, *temp;
	prep1 = head->next;
	p1 = prep1->next;
	//prep1和p1是否需要手动后移
	bool flag;

	while (p1 != NULL) {
		flag = true;
		temp = p1;
		//由于是单向链表，所以只能从头部开始检索
		for (prep2 = head, p2 = head->next; p2 != p1; prep2 = prep2->next, p2 = p2->next) {
			//发现第一个较大值
			if (p2->time > p1->time) {
				p1 = p1->next;
				prep1->next = p1;
				prep2->next = temp;
				temp->next = p2;
				flag = false;
				break;
			}
		}
		//手动后移prep1和p1
		if (flag) {
			prep1 = prep1->next;
			p1 = p1->next;
		}
	}
	return head;
}
void change(node *head){
	node *p=head;
	if (head->next==NULL)
	cout<<"没有数据";
	int date,i;
	time *tim1=new time;
	do {

		tim1=build(tim1);
		i=exam(tim1);
		if(i==0) {
			cout<<"日期不合法，请重新输入"<<endl;
		}
	} while(i==0);
	date=exchang(tim1);
	while(p->next!=NULL){
		if(p->time==date){
			cout<<"重新输入数据：";
			int m;
			cin>>m;
			p->data=m;
		};
		
	};
}
int main() {
	cout<<"*********主菜单********"<<endl;
	cout<<"    1.输入收入记录"<<endl;
	cout<<"    2.输入支出记录"<<endl;
	cout<<"    3.查看收入记录"<<endl;
	cout<<"    4.查看支出记录"<<endl;
	cout<<"  5.查看收支平衡情况"<<endl;
	cout<<"  6.根据日期查找记录"<<endl;
	cout<<"  7.根据日期修改记录"<<endl;
	cout<<"  8.根据日期删除记录"<<endl;
	cout<<"      0.退出系统"<<endl;
	cout<<"请输入序号：";
	int p;
	char j;
	node *head;
	head=new node;
	head->next=NULL;
	cin>>j;
	switch(j) {
		case'1':
			if(head->next==NULL) {
				p=1;
				head=creat(head,p);
				head=insertSort(head);
				break;
			}
			else{
				int flag=1;
				do{
					add(head);
					head=insertSort(head);
					cout<<"结束请输入0";
					cin>>flag;
				}while(flag);
			}
		case'2':
				if(head->next==NULL) {
				p=-1;
				head=creat(head,p);
				head=insertSort(head);
				break;
			}
			else{
				int flag=1;
				do{
					add(head);
					head=insertSort(head);
					cout<<"结束请输入0";
					cin>>flag;
				}while(flag);
			}
		case'3':
			show(head);
			break;
		case'4':
			show2(head);break;
		case '5':
		case '6':show1(head);break;
		case '7':change(head);break;
	}
	show(head);
	return 0;
}
