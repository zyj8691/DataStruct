#include<iostream>  

using namespace std;

int a = 10;
int b = 100;
int *q;

void func(int **p)
{
	cout << "func:&p=" << &p << ",p=" << p << endl;  //note:3  
	*p = &b;
	cout << "func:&p=" << &p << ",p=" << p << endl;  //note:4  
}


int main()
{
	cout << "&a=" << &a << ",&b=" << &b << ",&q=" << &q << endl;  //note:1  
	q = &a;
	cout << "*q=" << *q << ",q=" << q << ",&q=" << &q << endl;  //note:2  
	func(&q);
	cout << "*q=" << *q << ",q=" << q << ",&q=" << &q << endl;  //note:5  

	system("pause");
	return 0;
}