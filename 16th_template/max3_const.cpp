#include <iostream>
#include <string.h>
#include <unistd.h>

using namespace std;
/*
using namespace std;

int& max(int&a, int&b)
{
	return (a<b)? b:a;
}

double& max(double&a, double&b)
{
	return (a<b)? b:a;
}

float& max(float&a, float&b)
{
	return (a<b)? b:a;
}
*/

template<typename T>
const T& mymax(const T& a, const T& b)
{
	cout<<__PRETTY_FUNCTION__<<endl;
	return (a<b)? b:a;
}

void add(int a, int b)
{
	cout<<"add(int a, int b) = "<<(a+b)<<endl;
}

int main(int argc, char **argv)
{
 	int a = 1;
	int b = 2;

	mymax(a,b);

	return 0;
}
























