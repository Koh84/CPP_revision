#include <stdio.h>
#include "person.h"
#include "dog.h"

int main()
{
	A::Person per;
	per.setName("Zhangsan");
	per.setAge(16);
	per.printInfo();

	C::Dog dog;
	dog.setName("wangcai");
	dog.setAge(1);	
	dog.printInfo();

	A::printVersion();
	C::printVersion();
	return 0;
}

