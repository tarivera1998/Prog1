#include "Matrix.h"
#include "MatrixIO.h"
#include "std_lib_facilities.h"
#include <complex>

using namespace Numeric_lib;
using namespace std;

int main ()
{

//1.sizeof function
cout << "sizes: " << sizeof(char) <<' '<<sizeof(short)
<<' '<<sizeof(int)<<' '<<sizeof(long)<<' '<<sizeof(float)
<<' '<<sizeof(double)<<' '<<sizeof(int*)<<' '<<sizeof(double*)
<<' '<< '\n';

//2. size of the matrices
Matrix<int> a(10);
Matrix<int> b(100);
Matrix<double> c(10);
Matrix<int,2> d(10,10);
Matrix<int,3> e(10, 10, 10);

cout << "size of the matrices: "<<'\n'
<<"a: "<<sizeof(a)<<'\n'
<<"b: "<<sizeof(b)<<'\n'<<"c: "<<sizeof(c)<<'\n'
<<"d: "<<sizeof(d)<<'\n'<<"e: "<<sizeof(e)<<'\n';

//3. number of elements in the matrices
cout<<"elements of the matrices: "<<'\n'
<<"a: "<<a.size()<<'\n'
<<"b: "<<b.size()<<'\n'<<"c: "<<c.size()<<'\n'
<<"d: "<<d.size()<<'\n'<<"e: "<<e.size()<<'\n';

//4. square root of ints
cout<<"Enter some ints: \t"<<"To exit from this task enter an invalid int for squareroot such as -1"<<'\n';

int num;

while(cin>> num)

	if (num>=0){
		double res=sqrt(num);
		cout<<"The square root is: "<<res<<'\n';
	}
	else {
		cout<<"Invalid int entered, no square root"<<'\n';
		break;
	}

//5. doubles matrix
cout << "Enter 10 floating numbers for Matrix!"<< '\n';

Matrix<double> d_matrix(10);
for (int i=0; i< 10; i++) {

	cin >> d_matrix[i];
	if (!cin) throw runtime_error("problem with cin for matrix");
}

cout << "The elements of the matrix are: "<<d_matrix << '\n';


//6. creating a 2D matrix, multiplication table"
cout << "Enter the dimensions for matrix: (m x n)\n";

int m;
int n;
cin >> m >> n; 
cout << '\n';

Matrix<double,2> mtable(m,n);

for(int i=0; i<m; ++i) {

	mtable(i,0) = i;
}
for(int i=0; i<n; ++i) {

	mtable(0,i) = i;
}
for(int i= 1; i< m; ++i) {
	for(int j= 1; j< n; ++j)

		mtable(i,j) = i*j;

}

for(int i= 0; i< m; ++i) {

	for(int j= 0; j< n; ++j)

		cout << mtable(i,j) << '\t';

cout << '\n';

}

cout << '\n';


//7.a complex numbers in the matrix
cout << "Enter 10 complex nums for Matrix! (r,i)\n";
cout << '\n';

Matrix<complex<double>> complexd(10);
for (int i=0; i< 10; i++) {

	cin >> complexd[i];
	if (!cin) throw runtime_error("problem with cin for complex matrix");
}

cout << complexd << '\n';
cout << '\n';

//7.b sum of the complex numbers
complex<double> sum;
for (int i= 0; i< complexd.size(); ++i)
	sum+= complexd[i];

cout << "sum: \t" << sum << '\n';
cout << '\n';


//8. 2-dim Matrix with ints
cout << "Enter 6 ints for Matrix! m(2,3)\n";
cout << '\n';

Matrix<int, 2> intm(2,3);
for (int i= 0; i< intm.dim1(); ++i) 
	for (int j= 0; j< intm.dim2(); ++j){

	cin >> intm[i][j];
	if (!cin) throw runtime_error("problem with cin for int matrix");
}
cout << '\n';

cout << intm << '\n';
cout << '\n';

}
