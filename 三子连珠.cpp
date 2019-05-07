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
	cout<<"请选择先手持O或者X：";
	cin>>chess;
	return chess;
} 																								//初始化棋盘
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
}  																					//输出棋盘
int judge::ChoiceOfChar() {
	cout<<"是否再来一局(Y/N):";
	char choice;
	cin>>choice;
	if(choice=='Y') {
		cout<<"棋盘宽度为：";
		cin>>size;
		flashboard(size);
		return 1;
	} else {
		PrintBoard(size);
		PrintStats();
		return 0;
	};
}																						//判断是否重新开始
void judge::PrintStats() {
	cout<<"先手胜出："<<FirstPlayer<<endl;
	cout<<"后手胜出："<<SecondPlayer<<endl;
	cout<<"平局："<<Draws<<endl;
}
class  PromptTurnX {
	private:
		int a,b;
	public:
		void getab(int x,int y) {
			a=x;
			b=y;
		};																							//获取落子坐标
		void Onboard(char chess) {
			board[a][b]=chess;
		}
		void IfError() {
			int flag=0;
			do {
				int x,y;
				if(a>size||b>size||a<1||b<1) {
					flag=-1;
					cout<<"棋子不在棋盘内，请重新输入：";
					cin>>x>>y;
					getab(x,y);
				} else if(board[a][b]!='-') {
					flag=-1;
					cout<<"该位置已经落子，请重新输入：";
					cin>>x>>y;
					getab(x,y);
				}
				else
				{
					flag=0;
				};
			}while(flag==-1);
		}																//判断出错
		int judgesuccess(char chess) {
			if(board[a][b]==board[a-1][b]==board[a+1][b]==chess)
				return 1;
			else if(board[a][b]==board[a][b-1]==board[a][b+1]==chess)
				return 1;
			else if(board[a][b]==board[a-1][b-1]==board[a+1][b+1]==chess)
				return 1;
			else if(board[a][b]==board[a-1][b+1]==board[a+1][b-1]==chess)
				return 1;
			else
				return 0;
		}																	//判断输赢
		void tips(char chess) {
			cout<<"请持"<<chess<<"落子:"<<endl;
		}																//提示落子
};
class  PromptTurnY {
	private:
		int a,b;
	public:
		void getab(int x,int y) {
			a=x;
			b=y;
		}																					//获取落子坐标
		void Onboard(char chess) {
			board[a][b]=chess;
		}
		void IfError() {
			int flag=0;
			do {
				int x,y;
				if(a>4||b>4||a<1||b<1) {
					flag=-1;
					cout<<"棋子不在棋盘内，请重新输入：";
					cin>>x>>y;
					getab(x,y);
				} else if(board[a][b]!='-') {
					flag=-1;
					cout<<"该位置已经落子，请重新输入：";
					cin>>x>>y;
					getab(x,y);
				}
				else
				{
					flag=0;
				};
			}while(flag==-1);
		}																//判断出错
		int judgesuccess(char chess1) {
			if(board[a][b]==board[a-1][b]==board[a+1][b]==chess1)
				return 1;
			else if(board[a][b]==board[a][b-1]==board[a][b+1]==chess1)
				return 1;
			else if(board[a][b]==board[a-1][b-1]==board[a+1][b+1]==chess1)
				return 1;
			else if(board[a][b]==board[a-1][b+1]==board[a+1][b-1]==chess1)
				return 1;
			else
				return 0;
		}																	//判断输赢
		void tips(char chess) {
			cout<<"请持"<<chess<<"落子:"<<endl;
		}	                                                              //提示落子
};
int main() {
	char chess,chess1;
	PromptTurnX first;
	PromptTurnY second;
	judge j;
	int m=0;
	cout<<"棋盘宽度为：";
	cin>>size;
	chess=flashboard(size);
	if(chess=='O') {
		chess1='X';
	} else {
		chess1='O';
	}; 
	j.PrintBoard(size);
	do {
		int flag=0;			//确定落子几次
		int flag1=0;       //确定输赢
		while(flag<size*size) {
			int x,y;
			cout<<"请输入落棋坐标："; 
			cin>>x>>y;
			if(flag%2==0) {
				first.getab(x,y);
				first.IfError();
				first.Onboard(chess);
				flag1=first.judgesuccess(chess);
				if(flag1==1) {
					j.FirstP();
					cout<<"持"<<chess<<"获胜"<<endl;
					break;
				}
				first.tips(chess);
			} else {
				second.getab(x,y);
				second.IfError();
				second.Onboard(chess1);
				flag1=first.judgesuccess(chess1);
				if(flag1==1) {
					j.SecondP();
					cout<<"持"<<chess1<<"获胜"<<endl; 
					break;
				}
				second.tips(chess1);
			}
			j.PrintBoard(size);
			flag++;
		};
		if (flag==size*size) {
			cout<<"持平"<<endl;
			j.Draw();
		};
		m=j.ChoiceOfChar(); //决定是否重新开始
	}while(m==1);
	j.PrintBoard(size);
	j.PrintStats();
	return 0;
}
