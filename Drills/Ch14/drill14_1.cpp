#include "std_lib_facilities.h"


struct B1 {

	virtual void vf() 
	{
	std::cout << "B1::vf()\n";
	}
	void f()
	{
	std::cout << "B1::f()\n";
	}
	virtual void pvf()= 0;

};

struct D1: B1 {

	void vf() override
	{
 	   cout << "D1::vf()\n";
	}
	void f()
	{
	   cout << "D1::f()\n";
	}
};

struct D2: D1 {

	void pvf() override
	{ 
           cout << "D2::pvf()\n"; 
	}

};

struct B2 {

	virtual void pvf()= 0;

};

struct D21: B2 {

	string st= "example";
	void pvf() override
	{
	cout << st << "\n";
	}

};

struct D22: B2 {

	int num= 88;
	void pvf() override
	{
	cout << num << "\n";
	}

};

void f(B2& b2) {

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
        d21.pvf();
        
    	D22 d22;
    	d22.pvf();
        
        f(d21);
        f(d22);

return 0;
}
