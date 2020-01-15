#include <stdio.h>

//C++ added support of function in struct
//function in struct can access its own member variables
//Hence this struct can also be called "class"
class person{
public:	
	char *name;
	int age;
	char *work;

	void printInfo(void)
	{
		printf("name = %s, age = %d, work = %s\n", name, age, work);
	}

};


int main()
{

	struct person persons[] = {
		{"zhangsan",10,"teacher"},
		{"lisi",16,"doctor"}
	};


	persons[0].printInfo();
	persons[1].printInfo();

	return 0;
}


