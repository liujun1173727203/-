#include <iostream>
#include <cmath>
using namespace std;
class shape
{
	public:
	virtual void shapename() const =0;
	virtual float add() const {return 0.0;}
	virtual void printarea() const =0;
 };
 class circle:public shape
 {
 	int r;
 	public:
 		circle(int a):r(a){}
		 float add() const{ return r*r*3.1415;}
		 void shapename() const {cout<<"circle";}
		 void printarea() const { cout<<circle::add()<<endl;}

 };
 class rectangle:public shape
 {
 	int length;
 	int width;
 	public:
 		rectangle(int a,int b){length=a;
		width=b;
		 }
		 float add() const{ return length*width;}
		 void shapename() const {cout<<"rectangle";}
		 void printarea() const { cout<<rectangle::add()<<endl;}
 };
 class triangle:public shape
 {
 	int a,b,c;
 	public:
 		triangle(int q,int w,int e):a(q),b(w),c(e){
		 } 
		 float add() const{  int p=a*b*c; return sqrt(p*(p-a)*(p-b)*(p-c));}
		 void shapename() const {cout<<"triangle";}
		 void printarea() const{ cout<<triangle::add()<<endl;}
 };
 int main()
 {
	 shape *p;
 	circle s1(10);
 	rectangle s2(10,10);
 	triangle s3(3,4,5);
	p=&s1;
	p->shapename();
	p->printarea();
	p=&s2;
	p->shapename();
	p->printarea();
	p=&s3;
	p->shapename();
	p->printarea();
 	return 0;
 }
