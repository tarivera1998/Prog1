#include "std_lib_facilities.h"


//6. writing the copy operation
template<typename Iter1, typename Iter2>
// requires Input_iterator<Iter1>() && Output_iterator<Iter2>()
Iter2 new_copy(Iter1 f1, Iter1 e1, Iter2 f2)
{
	while (f1 != e1)
	{
		*f2 = *f1;
		++f2;
		++f1;
	}

	return f2;
}

int main ()
{

//1.defining an array
int arr1 [10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

//2.defining a vector
vector<int> vec1 {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

//3.defining a list
list<int> lis1 {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

//4.copying
int arr2 [10];
std::copy(begin(arr1), end(arr1), begin(arr2));

vector<int> vec2=vec1;

list<int> lis2=lis1;

//5.increasing the values
for (int& i : arr1)
		i += 2;

for (int& i : vec1)
	    i += 3;

for (int& i : lis1)
	    i += 5;

//7.copying using the new copy()
new_copy(begin(arr1), end(arr1),begin(vec1));
new_copy(begin(lis1), end(lis1), begin(arr1));

//8.a finding the position of 3 in the vector
auto vec_search = find(begin(vec1), end(vec1),3);
if (vec_search!= end(vec1))

	cout << "the position of 3 in the vector is: " << distance(vec1.begin(), vec_search) <<'\n';

else
	cout << "3 is not in vector \n";

//8.b finding elements in the list
auto list_search = find(begin(lis1), end(lis1), 27);
if (list_search!= end(lis1))

	cout << "the position of 27 in the list is: " << distance(lis1.begin(), list_search) <<'\n';

else
	cout << "27 is not in list \n";



keep_window_open();
return 0;
}
	


