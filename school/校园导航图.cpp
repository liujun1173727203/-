#include<iostream>
#include<iomanip>														//���Ƹ�ʽ
#include<string>
#define INF 0x3f3f3f3f													//���������
#define vertexNum 26													//Դ����
using namespace std;
int G[vertexNum][vertexNum]={
		   		/*0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 */
		/*0*/	{INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF},
		/*1*/	{INF,0,  80, INF,INF,400,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF},
		/*2*/	{INF,80, 0,  150,INF,INF,INF,INF,400,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,300,300,INF},
		/*3*/	{INF,INF,150,0,  150,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF},
		/*4*/	{INF,INF,INF,150,0,  INF,INF,INF,300,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,80, 300},
		/*5*/	{INF,400,INF,INF,INF,0,  100,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF},
		/*6*/	{INF,INF,INF,INF,INF,100,0,  100,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF},
		/*7*/	{INF,INF,INF,INF,INF,INF,100,  0,110,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF},
		/*8*/	{INF,INF,400,INF,300,INF,INF,110,0,  80, INF,INF,INF,INF,300,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,300},
		/*9*/	{INF,INF,INF,INF,INF,INF,INF,INF,80, 0,  110,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF},
		/*10*/	{INF,INF,INF,INF,INF,INF,INF,INF,INF,110,0,  50, INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF},
		/*11*/	{INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,50, 0,  150,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF},
		/*12*/	{INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,0,  100,110,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF},
		/*13*/	{INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,150,100,0,  150,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF},
		/*14*/	{INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,110,150,0,  100,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF},
		/*15*/	{INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,100,0,  110,INF,INF,INF,INF,INF,INF,INF,INF,INF},
		/*16*/	{INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,110,0,  INF,INF,INF,INF,INF,INF,INF,400,110},
		/*17*/	{INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,0,  INF, 80,INF,INF,INF,INF,400,INF},
		/*18*/	{INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,0,  100,50,INF, INF,INF,INF,INF},
		/*19*/	{INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,80, 100,0,  INF,INF,INF,INF,INF,INF},
		/*20*/	{INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,50, INF,0,  110,INF,INF,250,INF},
		/*21*/	{INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,110,0,  110,INF,INF,INF},
		/*22*/	{INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,110,0,  110,250,INF},
		/*23*/	{INF,INF,300,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,INF,110,0,  INF,INF},
		/*24*/	{INF,INF,300,INF, 80,INF,INF,INF,INF,INF,INF,INF,INF,INF,500,INF,400,400,INF,INF,250,INF,250,INF,0,  INF},
		/*25*/	{INF,INF,INF,INF,300,INF,INF,INF,300,INF,INF,INF,INF,INF,INF,INF,110,INF,INF,INF,INF,INF,INF,INF,INF,0  }
	};//�ڽӾ���
string vertex[]={"0","����¥","��a","��b","��c","a4","a6","�ۺ�¥","һʳ��","����ʳ��","b5","b6","b7","b10","��ʳ��","c6","c8","d7","d2","d4","d1","�����칫12","ʵb","ʵd","ͼ���","�й���ͨ"}; //����� 
void Floyd(int start,int end)
{
    int dist[vertexNum][vertexNum],i,k,j;								//distΪȨֵ�洢����
    string path[vertexNum][vertexNum];
    for(i=0;i<vertexNum;i++)
        for(j=0;j<vertexNum;j++)
    {
        dist[i][j]=G[i][j];												//��G��ʼ��dist  
        path[i][j]=vertex[i]+"-->"+vertex[j];
    }
    for(k=1;k<vertexNum;k++)
         for(i=1;i<vertexNum;i++)
          for(j=1;j<vertexNum;j++)
    {
        if((dist[i][k]+dist[k][j]<dist[i][j])&&(dist[i][k]!=INF)&&(dist[k][j]!=INF)&&(i!=j))
        {
            dist[i][j]=dist[i][k]+dist[k][j];							//�洢i��j�����·������ 
            path[i][j]=path[i][k]+"-->"+vertex[j];						// ·�� 
        }
    }
    if(start<vertexNum&&end<vertexNum){
       cout<<"����:"<<start<<"������"<<end<<"�����·����Ȩֵ��Ϊ��"<<endl;
          {
              cout<<path[start][end]<<" ";
              if(dist[start][end]!=INF) cout<<dist[start][end]<<endl;
              else cout<<"��"<<endl;
          }
	}else{
		cout<<"�ص㲻����";
	}
}


int main()
{
	int start,end;
    system("map.jpg");
	do{
    cout<<"�����������յ�����(��ֹ������0��0)��"; 
    cin>>start>>end;
		if(start!=0&&end!=0){
    	Floyd(start,end);
		} 
	} while(start!=0&&end!=0); 
    return 0;
}
