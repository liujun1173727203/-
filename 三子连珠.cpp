#include <iostream>
#include<stdlib>
using namespce std;

static string board[10]10];
string flashboard(int);
string flashboard(int a,string *p) {
	string choice;
	for (int ROW=0; ROW<=a; ROW++) {
		for(int COLUMN=0; COLUMN<=a; COLUMN++) {
			if (ROW==0) {
				*(*p+COLUMN)=COLUMN;
				continue;
			};
			if(COLUMN==0) {
				**(p+row)=ROW;
			} else {
				board[ROW][COLUMN]=NULL;
			};
		}
	}
	cout<<"��ѡ�����ֳ�O����X��";
	cin>>choice;
	return choice;
} //��ʼ������
class judge {
	private:
		int FirstPlayer=0;
		int SecondPlayer=0;
		int Draws=0;
	public:
		void FirstPlayer() {
			FirstPlayer++;
		}
		void SecondPlayer() {
			SecondPlayer++;
		}
		void PrintBoard(int&);  //�������
		void ChoiceOfChar(char&);//�ж��Ƿ����¿�ʼ
		void PrintStats(); //�����Ӯ���
};
class  PromptTurnX {
	private:
		int a,b;
	public:
		void getab(int x,int y) {
			a=x;
			b=y;
		};	//��ȡ��������
		void Onboard();
		void IfError(int&,int&); //�жϳ���
		int judgesuccess(int&,int&); //�ж���Ӯ
		void tips(); //��ʾ����
};
class  PromptTurnY {
	private:
		int a,b;
	public:
		void getab(int x,int y) {
			a=x;
			b=y;
		}	//��ȡ��������
		void IfError(int&,int&); //�жϳ���
		int judgesuccess(int&,int&); //�ж���Ӯ
		void tips(); //��ʾ����
};
int main() {
	int size;
	string choice;
	cout<<"���̿��Ϊ��";
	cin>>size;
	choice=flashboard(size,&board);
	PromptTurnX first;
	PromptTurnY second;
	judge j;
	int flag=0;			//ȷ�����Ӽ���
	int flag1=0;       //ȷ����Ӯ
	while(flag<size*size) {
		int x,y;
		cin>>x>>y;
		if(flag%2==0) {
			first.getab(x,y);
			first.IfError(x,y);
			flag1=first.judgesuccess(x,y);
			if(flage1==1)
				j.FirstPlayer();
			first.tips();
		} else {
			second.getab(x,y);
			second.IfError(x,y);
			flag1=first.judgesuccess(x,y);
			if(flage1==1)
				j.SeconPlayer();
			Second.tips();
		}
	}
}
