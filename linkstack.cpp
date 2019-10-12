#include <iostream>
#include<string>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct node{
	int data;
	node *next;
};
class linkstack{
	private:
	node *top;
	public:
	linkstack(){top=NULL;
	};
	int getTop();
	void push(int e);
	void pull();
	int isEmpty();
	int judge(string e);
};
int linkstack::getTop(){
	return top->data;
}
int linkstack::judge(string e){
	if(e=="("||e=="£¨")
	return 1;
	if(e==")"||e=="£©") 
	return -1;	
	if(e=="{")
	return 2;
	if(e=="}")
	return -2;
	if(e=="["||e=="¡¾")
	return 3;
	if(e=="]"||e=="¡¿")
	return -3;
}
void linkstack::push(int e){
	node *item =new node;
	item->data=e;
	item->next=top;
	top=item;
}
void linkstack::pull(){
	node *q;
	q=top;
	top=top->next;
	delete q;	
}
int linkstack::isEmpty(){
	if(top==NULL)
	return 1;
	else return 0;
}
int main(int argc, char** argv) {
	string aim="1";
		linkstack run;
	cout<<"ÊäÈë'/'½áÊøÅÐ¶Ï"<<endl; 
	while(aim!="/"){
		cout<<"ÇëÒÀ´ÎÊäÈë½øÐÐÅÐ¶Ï£º";
		cin>>aim;
		int flag=0;
		flag=run.judge(aim);
		if(flag>0){
			run.push(flag);
		}else{
			int empty=run.isEmpty();
			if(empty==1){
				
				cout<<"error,¿ÕÕ»,²»Æ¥Åä"<<endl;
				break;
			}else{
				if(run.getTop()+flag==0){
					run.pull();
					continue;
				}else{
					cout<<"error,²»Æ¥Åä£¡"<<endl;break;
				}
			}
		}
	}
}
