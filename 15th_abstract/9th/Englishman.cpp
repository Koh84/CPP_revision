#include "Englishman.h"

Englishman::Englishman(){}
Englishman::Englishman(char *name, int age, char *address)
{
	setName(name);
	this->age = age;
	memset(this->address, 0, 100);
	strcpy(this->address, address);
}

void Englishman::eating(void) 
{
	cout<<"use knife to eat"<<endl;
}

void Englishman::wearing(void)
{
	cout<<"wear english style"<<endl;
}

void Englishman::driving(void)
{
	cout<<"drive english car"<<endl;
}

Englishman::~Englishman()
{
	cout<<"~Englishman()"<<endl;
}

Human& CreateEnglishman(char *name, int age, char *address)
{
	return *(new Englishman(name, age, address));
}
