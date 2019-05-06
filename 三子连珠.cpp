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
	cout<<"请选择先手持O或者X：";
	cin>>choice;
	return choice;
} //初始化棋盘
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
		void PrintBoard(int&);  //输出棋盘
		void ChoiceOfChar(char&);//判断是否重新开始
		void PrintStats(); //输出输赢情况
};
class  PromptTurnX {
	private:
		int a,b;
	public:
		void getab(int x,int y) {
			a=x;
			b=y;
		};	//获取落子坐标
		void Onboard();
		void IfError(int&,int&); //判断出错
		int judgesuccess(int&,int&); //判断输赢
		void tips(); //提示落子
};
class  PromptTurnY {
	private:
		int a,b;
	public:
		void getab(int x,int y) {
			a=x;
			b=y;
		}	//获取落子坐标
		void IfError(int&,int&); //判断出错
		int judgesuccess(int&,int&); //判断输赢
		void tips(); //提示落子
};
int main() {
	int size;
	string choice;
	cout<<"棋盘宽度为：";
	cin>>size;
	choice=flashboard(size,&board);
	PromptTurnX first;
	PromptTurnY second;
	judge j;
	int flag=0;			//确定落子几次
	int flag1=0;       //确定输赢
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
