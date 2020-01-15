#include <stdio.h>

struct person{
	char *name;
	int age;
	char *work;
};

int main()
{

	struct person persons[] = {
		{"zhangsan",10,"teacher"},
		{"lisi",16,"doctor"}
	};

/*	
	struct person p1,p2;
	p1.name = "zhangsan";
	p1.age = "10";
	p1.work = "teacher";
*/
	for (int i = 0; i < 2; i++)
	{
		printf("name = %s, age = %d, work = %s\n", persons[i].name, persons[i].age, persons[i].work);
	}

	return 0;
}
