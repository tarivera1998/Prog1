#include "std_lib_facilities.h"

template<typename T>
struct S
{
  
	S() {}
	
	S(T t)
	: val(t)
	{}

	S& operator=(const T& newValue) { val = newValue; return *this; }
	istream operator>>(T t) { cin >> val; }

	void set(T t) { val = t; }
	const T& get() const { return val; }

	T& getRef() {return val;}	

private:
	// ---- variables
	T val;

};

template<typename T>
const T& get(S<T>& s)
{
	return s.get;
}

template<typename T>
void read_val(T& v)
{
	cin >> v;
}

int main()
{

    /*S<int> si(88);
    si.set(15);
	cout << get(si) << endl;
	

	S<char> sc('f');
	sc.set('v');
	cout << get(sc) << endl;

	S<double> sd(10.4f);
	sd.set(83.3f);
	cout << get(sd) << endl;
	
	S<string> ss("an example string.");
	ss.set("another string");
	cout << get(ss) << endl;

	S<vector<int>> svi(vector<int>(10, 100));
	svi.set(vector<int>(10, 77));
	for (int i : get(svi))
		cout << i << ", ";*/

	S<int> si;
	cout << "Give me an int: "; read_val(si.getRef());
	cout << si.get() << endl;

	S<char> sc;
	cout << "Give me a char: "; read_val(sc.getRef());
	cout << sc.get() << endl;

	S<double> sd;
	cout << "Give me a double: "; read_val(sd.getRef());
	cout << sd.get() << endl;

	S<string> ss;
	cout << "Give me a string: "; read_val(ss.getRef());
	cout << ss.get() << endl;

	S<vector<int>> svi(vector<int>(10,8));
	cout << "Give me 10 ints: ";
	for (int i = 0; i < 10; ++i)
		read_val(svi.getRef()[i]);
	for (int i : svi.get())
		cout << i << ", ";
	cout << endl;

	keep_window_open();
	return 0;
}