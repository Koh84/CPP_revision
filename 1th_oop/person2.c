#include <stdio.h>

int main()
{
	char *name[] = {"zhangsan","lisi"};
	int age[] = {10,6};
	char *work[] = {"teacher","doctor"};

	for (int i = 0; i < 2; i++)
	{
		printf("name = %s, age = %d\n",	name[i], age[i]);
	}

	return 0;
}
