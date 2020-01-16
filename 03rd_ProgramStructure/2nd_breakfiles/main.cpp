#include <stdio.h>
#include "person.h"

int main()
{
	Person per;
	per.setName("zhangsan");
	per.setAge(200);
	
	per.printInfo();
	return 0;
}

