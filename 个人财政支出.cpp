#include<iostream>
using namespace std;
struct time {
	int year;
	int month;
	int day;
};
typedef struct time time;
time *build(time *tim1) {
	cout<<"���������ڣ�";
	cin>>tim1->year>>tim1->month>>tim1->day;
	return tim1;
} //����ʱ���
int exam(time *tim1) {
	if(tim1->month<1||tim1->month>12||tim1->day<1||tim1->year>10000)return 0;
	if(tim1->month==1||tim1->month==3||tim1->month==5||tim1->month==7||tim1->month==8||tim1->month==10||tim1->month==12) {
		if(tim1->day<=31)return 1;
	};
	if(tim1->month==4||tim1->month==6||tim1->month==9||tim1->month==11) {
		if(tim1->day<=30)return 1;
	};
	if(tim1->month==2&&tim1->year%4==0) {
		if(tim1->day<=29)return 1;
		else return 0;
	};
	if(tim1->month==2&&tim1->year%4!=0) {
		if(tim1->day<=28)return 1;
		else return 0;
	}

}//���ʱ���Ƿ����Ҫ��
int exchang(time *tim1) {
	int time;
	time=tim1->year*10000+tim1->month*100+tim1->day;
	return time;
} //ת��ʱ��
struct node {
	int data;
	int time;
	node *next;
};
typedef struct node node;
node *creat() {
	node *head,*p;
	head=new node;
	p=head;
	int flag=1,m,date;
	cout<<"����������'0'"<<endl;
	while(flag) {
		time *tim1;
		tim1=new time;
		cout<<"���������ݣ�֧�����-��ʾ:";
		cin>>m;
		if(m==0)break;
		int i=0;
		do {

			tim1=build(tim1);
			i=exam(tim1);
			if(i==0) {
				cout<<"���ڲ��Ϸ�������������"<<endl;
			}
		} while(i==0);
		date=exchang(tim1);
		if(m!=0) {
			node *s=new node;
			s->data=m;
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
};//��������
node *show(node *head) {
	node *p=head;
	while(p!=NULL) {
		cout<<p->time/10000<<" "<<p->time%10000/100<<" "<<p->time%100<<"  "<<p->data<<endl;
		p=p->next;
	};

}//��ӡ����
node *add(node *head) {
	node *p=head,*s,*p2;
	time *tim1;
	tim1=new time;
	int i=0;
	int m;
	int time;
	s=new node;
	cout<<"������������ݣ�";
	cin>>m;
	do {

		tim1=build(tim1);
		i=exam(tim1);
		if(i==0) {
			cout<<"���ڲ��Ϸ�������������"<<endl;
		}
	} while(i==0);
	time=exchang(tim1);
		s->data=m;
	s->time=time;
	if(p->time<=s->time){
		p2=p;
		p=p->next;
	}
	else if(p->time>s->time){
		p2->next=s;
		s->next=p->next; 
	} 
	else if(p->next==NULL){
		p->next=s;
		s->next=NULL;
	}
}//��ӽ��

node *del(node *head) {
	cout<<"������Ҫɾ��������";
	int num;
	cin>>num;
	node *p1, *p2;
	p2 = new node;
	p1 = head;

	while (num != p1->data && p1->next != NULL) {
		p2 = p1;
		p1 = p1->next;// p1��p2λ��: p2->p1
	}

	if (num == p1->data) {
		if (p1 == head) { // ɾ��ͷ�ڵ�
			head = p1->next;
			delete p1;
		} else {
			p2->next = p1->next;
			delete p1;
		}
	} else {
		cout << num << " could not been found in the current single linker!" << endl;
	}
	return head;
}//ɾ�����

int main() {
	node *head=creat();
	add(head);
	head=del(head);
	show(head);
	return 0;
}
