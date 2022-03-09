#include "std_lib_facilities.h"


struct Person {
Person(): name(""), age(0) {}
string name;
int age;

private:
string first_name;
string second_name;
int age;

}

istream& operator>>(istream& is, Person& person)
{



return is;
}


ostream& operator<<(ostream& os, const Person& person) //referencia szerinti átadás
{
return os << "name: "<<person.name<<"\n"<<"age: "<<person.age;

}

int main () {

/*Person person {"Goofy", 63};
cout << "name: "<< person.name <<"\n"<<"age: "<< person.age << "\n";*/



/*cout << "Give me a name and an age: " << "\n";
Person person1;
cin >> person1;
cout<< person1 <<"\n";*/

}

  
  
