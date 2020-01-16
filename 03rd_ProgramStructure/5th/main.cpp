#include <stdio.h>
#include "person.h"
#include "dog.h"

/* global namespace*/
using namespace A;
using namespace C;

int main()
{
	/* local namespace */
	Person per;
	per.setName("Zhangsan");
	per.setAge(16);
	per.printInfo();

	Dog dog;
	dog.setName("wangcai");
	dog.setAge(1);	
	dog.printInfo();

	A::printVersion();
	C::printVersion();
	return 0;
}

