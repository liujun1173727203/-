#include <iostream>
#include<string>
using namespace std;
static int size;
static char board[10][10];
char flashboard(int);
char flashboard(int a) {
	char chess;
	for (int ROW=0; ROW<=a; ROW++) {
		for(int COLUMN=0; COLUMN<=a; COLUMN++) {
			if (ROW==0) {
				board[0][COLUMN]=COLUMN+48;
				continue;
			};
			if(COLUMN==0) {
				board[ROW][0]=ROW+48;
			} else {
				board[ROW][COLUMN]='-';
			};
		}
	}
	do {
		cout<<"��ѡ�����ֳ�O����X��";
		cin>>chess;
	} while(chess!='O'&&chess!='X');
	return chess;
} 																								//��ʼ������
class judge {
	private:
		int FirstPlayer;
		int SecondPlayer;
		int Draws;
	public:
		judge(int a=0,int b=0,int c=0): FirstPlayer(a),SecondPlayer(b),Draws(0) {
		}
		void FirstP();
		void SecondP();
		void Draw();
		void PrintBoard(int a);
		int ChoiceOfChar();
		void PrintStats();
};
void judge:: FirstP() {
	FirstPlayer++;
}
void judge::SecondP() {
	SecondPlayer++;
}
void judge::Draw() {
	Draws++;
}
void judge::PrintBoard(int a) {
	for (int ROW=0; ROW<=a; ROW++) {
		for(int COLUMN=0; COLUMN<=a; COLUMN++) {
			cout<<board[ROW][COLUMN]<<" ";
			if(COLUMN==a)
				cout<<endl;
		}
	}
}  																					//�������
int judge::ChoiceOfChar() {
	cout<<"�Ƿ�����һ��(Y/N):";
	char choice;
	cin>>choice;
	if(choice=='Y') {
		cout<<"���̿��Ϊ��";
		cin>>size;
		flashboard(size);
		return 1;
	} else {
		PrintBoard(size);
		PrintStats();
		return 0;
	};
}																						//�ж��Ƿ����¿�ʼ
void judge::PrintStats() {
	cout<<"����ʤ����"<<FirstPlayer<<endl;
	cout<<"����ʤ����"<<SecondPlayer<<endl;
	cout<<"ƽ�֣�"<<Draws<<endl;
}
class  PromptTurnX {
	private:
		int a,b;
	public:
		void getab(int x,int y) {
			a=x;
			b=y;
		};																							//��ȡ��������
		void Onboard(char chess) {
			board[a][b]=chess;
		}
		void IfError() {
			int flag=0;
			do {
				int x,y;
				if(a>size||b>size||a<1||b<1) {
					flag=-1;
					cout<<"���Ӳ��������ڣ����������룺";
					cin>>x>>y;
					getab(x,y);
				} else if(board[a][b]!='-') {
					flag=-1;
					cout<<"��λ���Ѿ����ӣ����������룺";
					cin>>x>>y;
					getab(x,y);
				} else {
					flag=0;
				};
			} while(flag==-1);
		}																//�жϳ���
			int judgesuccess(char chess) {
			int flag=0;
			for (int ROW=0; ROW<=size; ROW++) {
				for(int COLUMN=0; COLUMN<=size; COLUMN++) {
					if(board[ROW][COLUMN]==chess) {
						if(board[ROW][COLUMN+1]==chess) {
							if(board[ROW][COLUMN+2]==chess) {
								return 1;
								flag=1;
								break;
							};
						} else if(board[ROW+1][COLUMN+1]==chess) {
							if(board[ROW+2][COLUMN+2]==chess) {
								return 1;
								flag=1;
								break;
							};
						} else if(board[ROW+1][COLUMN]==chess) {
							if(board[ROW+2][COLUMN]==chess) {
								return 1;
								flag=1;
								break;
							};
						} else if(board[ROW-1][COLUMN+1]==chess) {
							if(board[ROW-2][COLUMN+2]==chess) {
								return 1;
								flag=1;
								break;
							};
						};
					};
				};
				if(flag==1)break;
			};
		}																//�ж���Ӯ
		void tips(char chess) {
			cout<<"���"<<chess<<"����:"<<endl;
		}																//��ʾ����
};
class  PromptTurnY {
	private:
		int a,b;
	public:
		void getab(int x,int y) {
			a=x;
			b=y;
		}																					//��ȡ��������
		void Onboard(char chess) {
			board[a][b]=chess;
		}
		void IfError() {
			int flag=0;
			do {
				int x,y;
				if(a>4||b>4||a<1||b<1) {
					flag=-1;
					cout<<"���Ӳ��������ڣ����������룺";
					cin>>x>>y;
					getab(x,y);
				} else if(board[a][b]!='-') {
					flag=-1;
					cout<<"��λ���Ѿ����ӣ����������룺";
					cin>>x>>y;
					getab(x,y);
				} else {
					flag=0;
				};
			} while(flag==-1);
		}																//�жϳ���
		int judgesuccess(char chess) {
			int flag=0;
			for (int ROW=0; ROW<=size; ROW++) {
				for(int COLUMN=0; COLUMN<=size; COLUMN++) {
					if(board[ROW][COLUMN]==chess) {
						if(board[ROW][COLUMN+1]==chess) {
							if(board[ROW][COLUMN+2]==chess) {
								return 1;
								flag=1;
								break;
							};
						} else if(board[ROW+1][COLUMN+1]==chess) {
							if(board[ROW+2][COLUMN+2]==chess) {
								return 1;
								flag=1;
								break;
							};
						} else if(board[ROW+1][COLUMN]==chess) {
							if(board[ROW+2][COLUMN]==chess) {
								return 1;
								flag=1;
								break;
							};
						} else if(board[ROW-1][COLUMN+1]==chess) {
							if(board[ROW-2][COLUMN+2]==chess) {
								return 1;
								flag=1;
								break;
							};
						};
					};
				};
				if(flag==1)break;
			};
		}																		//�ж���Ӯ
		void tips(char chess) {
			cout<<"���"<<chess<<"����:"<<endl;
		}	                                                              //��ʾ����
};
int main() {
	char chess,chess1;
	PromptTurnX first;
	PromptTurnY second;
	judge j;
	int m=0;

	cout<<"���̿��Ϊ��";
	do {
		cin>>size;
		if(size<3)
			cout<<"���̴�С��СΪ3�����������룺";
	} while(size<3);
	chess=flashboard(size);
	if(chess=='O') {
		chess1='X';
	} else {
		chess1='O';
	};
	do {
		int flag=0;			//ȷ�����Ӽ���
		int flag1=0;       //ȷ����Ӯ
		while(flag<size*size) {
			int x,y;
			j.PrintBoard(size);
			cout<<"�������������꣺";
			cin>>x>>y;
			if(flag%2==0) {
				first.getab(x,y);
				first.IfError();
				first.Onboard(chess);
				flag1=first.judgesuccess(chess);
				if(flag1==1) {
					j.FirstP();
						j.PrintBoard(size);
					cout<<"��"<<chess<<"��ʤ"<<endl;
					break;
				}
				first.tips(chess1);
			} else {
				second.getab(x,y);
				second.IfError();
				second.Onboard(chess1);
				flag1=first.judgesuccess(chess1);
				if(flag1==1) {
					j.SecondP();
						j.PrintBoard(size);
					cout<<"��"<<chess1<<"��ʤ"<<endl;
					break;
				}
				second.tips(chess);
			}
			flag++;
		};
		if (flag==size*size) {
			cout<<"��ƽ"<<endl;
			j.Draw();
		};
		m=j.ChoiceOfChar(); //�����Ƿ����¿�ʼ
	} while(m==1);
	return 0;
}
