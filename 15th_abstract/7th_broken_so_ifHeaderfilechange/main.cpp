#include "Chinese.h"
#include "Englishman.h"
#include "Human.h"

void test_eating(Human *h)
{	
	h->eating();
}

int main(int argc, char **argv)
{
	Englishman e("Bill",10,"abc");
	Chinese c;
	
	Human* h[2] = {&e, &c};
	int i;

	for(i = 0; i<2; i++)
	{
		test_eating(h[i]);	
	}
	return 0;	
}
