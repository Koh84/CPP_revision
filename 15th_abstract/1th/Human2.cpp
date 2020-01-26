#include <stdio.h>
#include <iostream>
#include <string.h>
#include <unistd.h>

using namespace std;

class Human{
private:
	int a;
public:
	virtual void eating(void) = 0; //abstract class
	virtual void wearing(void)= 0; //you can't make an object out of an abstract class
	virtual void driving(void)= 0; //only for inheritance usage
	virtual ~Human(){cout<<"~Human()"<<endl;}
	virtual Human* test(void){cout<<"Human's test"<<endl; return this;}
};

class Englishman: public Human{
public:
	void eating(void) {cout<<"use knife to eat"<<endl;}
	void wearing(void){cout<<"wear english style"<<endl;}
	void driving(void){cout<<"drive english car"<<endl;}
	virtual ~Englishman(){cout<<"~Englishman()"<<endl;}
	virtual Englishman* test(void){cout<<"Englishman's test"<<endl; return this;}
};

class Chinese: public Human{
public:
	void eating(void) {cout<<"use chopsticks to eat"<<endl;}
	void wearing(void){cout<<"wear chinese style"<<endl;}
	//void driving(void){cout<<"drive chinese car"<<endl;}
	virtual ~Chinese(){cout<<"~Chinese()"<<endl;}
	virtual Chinese* test(void){cout<<"Chinese's test"<<endl; return this;}
};

class Guangximan: public Chinese{
public:
	void driving(void){cout<<"drive Guangximan car"<<endl;}
};

int main(int argc, char **argv)
{
	// Human h; //Can't declare object from abstract class
	Englishman e;
	Guangximan c;

	return 0;	
}
