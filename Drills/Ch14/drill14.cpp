#include "std_lib_facilities.h"



//1st task: defining the class with the functions

class B1 {
 public:
 	virtual void vf() 
	{
           cout << "B1::vf()\n";
 	}
	void f()
	{
	   cout << "B1::f()\n";
	}
	virtual void pvf() =0;
};

//2nd task: derived class, overriding

class D1:public B1{
 public:
 	void vf() 
 	{
 	   cout << "D1::vf()\n";
	}
	
//4nd task, it will change the result of calling of f() in main

	void f()
	{
	   cout << "D1::f()\n";
	}
};
 //6th task
 
 class D2 : public D1 {
public:
	void pvf() 
	{ 
           cout << "D2::pvf()\n"; 
	}
};

//7th task

class B2 {
public:
       virtual void pvf() =0;
       
};

class D21 : public B2 {
public:
       void pvf() 
       { 
           cout << st << "\n"; 
       }
       string st;
};

class D22 : public B2 {
public:
        void pvf() 
        { 
        cout << num << "\n";
        }
        int num;
};

void f(B2& b2)
{
    b2.pvf();
}

int main ()
{
	/*B1 b1;
	b1.vf();
	b1.f();
	//b1.pvf(); (abstract class! --> error )*/
	
	/*D1 d1;
	d1.vf();
	cout << "f() in D1:\t";
	d1.f();*/

//3rd task
	/*B1& b1_ref = d1;
	b1_ref.vf();
	b1_ref.f();*/

	D2 d2;
	d2.f();
	d2.vf();
	d2.pvf();


        D21 d21;
    	d21.st = "d21.st";
    	D22 d22;
    	d22.num = 22;
        
        f(d21);
        f(d22);

return 0;
}
