#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include "std_lib_facilities.h"


using namespace std;

struct Person {
    Person() { }
    Person(string f, string l, int a);

    string first_name() const { return fn; }
    string last_name() const { return ln; }
    int age() const { return ag; }

private:
    string fn;
    string ln;
    int ag;
};

Person::Person(string f, string l, int a) : fn{f}, ln{l}, ag{a}
{
    //dealing with possible errors
    if (a < 0 || 150 < a) 
    error("Invalid age used");
    
    string name = f + l;        
    for (char c : name) {
        switch(c) {
            case ';': case ':': case '"': case '[': case ']': case '*':
            case '&': case '^': case '%': case '$': case '#': case '@':
            case '!':
               error("Invalid character used");
                break;
            default:
                break;
        }
    }
}

ostream& operator<<(ostream& os, const Person& p)
{
        return os << p.first_name() << " " << p.last_name() << "\t" << p.age();
}

istream& operator>>(istream& is, Person& p)
{
	string f;
	string l;
	int a;

	is >> f >> l >> a;
    	p = Person(f, l, a);
   	return is;
}

int main(){

	/*Person person {"Goofy", 63};
	cout << "name: "<< person.name <<"\n"<<"age: "<< person.age << "\n";*/



	/*cout << "Give me a name and an age: " << "\n";
	Person person1;
	cin >> person1;
	cout<< person1 <<"\n";*/
    
   	vector<Person> v;

    	cout << "Enter first names, second names and ages. Exit with firstname and lastname 'end'\n";

    	for (Person p; cin >> p; ) {
        	if (p.first_name() == "end") break;
        	v.push_back(p);
    		}

    	for (Person p : v)
        cout << p << '\n';


}


