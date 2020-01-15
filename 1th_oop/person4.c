#include <stdio.h>

struct person{
	char *name;
	int age;
	char *work;

	void (*printInfo)(struct person *per); //C program only allow function pointer in struct
};

void printInfo(struct person *per)
{
	printf("name = %s, age = %d, work = %s\n", per->name, per->age, per->work);
}

int main()
{

	struct person persons[] = {
		{"zhangsan",10,"teacher", printInfo},
		{"lisi",16,"doctor", printInfo}
	};


	persons[0].printInfo(&persons[0]);
	persons[1].printInfo(&persons[1]);

	return 0;
}


