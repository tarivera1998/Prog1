#include "std_lib_facilities.h"


//1.template
template<typename T>  struct S { 
//2.constructor initializing T
	 S(): val(T()) { }
	 S(T init): val(init) { }
	 
//11.constans and nonconstans versions of get
	 T& get();
	 const T& get() const;

//void set(T new) { val = new; }

	 T& operator= (const T&);


	
//7. making val private
	private:
	T val;

};

//5. get function template returning a reference to val, 6. definition is outside of the class
template<typename T> T& S<T>::get() {

    return val;
}

//8. get function template
template<typename T> const T& S<T>::get() const {

    return val;
}

template<typename T> istream& operator>>(istream& is, S<T>& s) {

    T v;
    cin >> v;
    if (!is) return is;
    s = v;
    return is;
}
//13. read_val used to read in variables
template<typename T> void read_val(T& v) {

    cin >> v;
}

//10. replacing set()
template<typename T> T& S<T>::operator=(const T& n) {

    val = n;
    return val;
}

template<typename T> ostream& operator<<(ostream& os, vector<T>& v) {

    os << "{ ";
    for (int i = 0; i < v.size(); ++i) {
        os << v[i] << (i < v.size() - 1 ? ", " : " ");
    }
    os << "}\n";

    return os;
}

template<typename T> istream& operator>>(istream& is, vector<T>& v) {

    char ch = 0;
    is >> ch;
    if (ch != '{') {
        is.unget();
        return is;
    }

    for (T val; is >> val; ) {
        v.push_back(val);
        is >> ch;
        if (ch != ',') break;
    }

    return is;
}



int main() {


try {

//3.defining variable types in main
S<int> my_int {88};
S<char> my_char {'f'};
S<double> my_double {4.82};
S<string> my_string {"example"};
S<vector<int>> my_vector {vector<int> {1, 2, 3, 4, 5}};

/*
cout 	<< "S<int> : " << my_int.val << '\n'
<< "S<char> : " << my_char.val << '\n'
<< "S<double> : " << my_double.val << '\n'
<< "S<string> : " << my_string.val << '\n'
<< "S<vector<int>> : ";
for (int i= 0; i< my_vector.val.size(); i++)		
		cout  << my_vector.val[i] << '\t';
cout << '\n';
*/

cout 	<< "S<int> : " << my_int.get() << '\n'
<< "S<char> : " << my_char.get() << '\n'
<< "S<double> : " << my_double.get() << '\n'
<< "S<string> : " << my_string.get() << '\n'
<< "S<vector<int>> : "; 

for (int i= 0; i< my_vector.get().size(); i++)		
		cout  << my_vector.get()[i] << '\t';

cout << '\n';
cout << "Give me a/an: \n";
cout << "int: ";
read_val(my_int);
cout << "char: ";
read_val(my_char);
cout << "double: ";
read_val(my_double);
cout << "string: ";
read_val(my_string);

/*
cout << '\n';
cout << "int: " << my_int.get() << '\n';
cout << "char: " << my_char.get() << '\n';
cout << "double: " << my_ouble.get() << '\n';
cout << "string: " << my_string.get() << '\n';
*/

}

catch (exception& e) {
	cerr << "exception: " << e.what() << endl;
	return 1;
}

catch (...) {
	cerr << "some exception\n";
	return 2;
}

}
