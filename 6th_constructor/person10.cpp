#include <stdio.h>
#include <iostream>
#include <string.h>
#include <unistd.h>

using namespace std;

class Person{
private:	
	char *name;
	int age;
	char *work;
public:

	Person(){ cout<<"Person()"<<endl;
		name = NULL;
		work = NULL;	
	}
	Person(char *name)
	{
		cout<<"Person(char *name)"<<endl;
		this->name = new char[strlen(name)+1];
		strcpy(this->name,name);
		this->work = NULL;
	}

	Person(char *name, int age, char *work = "none")
	{
		cout<<"Person(char *name, int age), name ="<<name<<", age = "<<age<<endl;
		
		this->age = age;
		
		this->name = new char[strlen(name)+1];
		strcpy(this->name,name);

		this->work = new char[strlen(work)+1];
		strcpy(this->work,work);
	}

	Person(Person &per)
	{
		cout<<"Person(Person &per)"<<endl;
		
		this->age = per.age;
		
		this->name = new char[strlen(per.name)+1];
		strcpy(this->name, per.name);

		this->work = new char[strlen(per.work)+1];
		strcpy(this->work, per.work);
	}

	void setName(char *name)
	{
		this->name = name;
	}
	
	int setAge(int age)
	{
		if(age<0 || age>150)
		{
			this->age = 0;
			return -1;
		}
		this->age = age;
		return 0;
	}

	void printInfo(void)
	{
		cout<<"name = "<<name<<", age = "<<age<<", work = "<<work<<endl;
	}

	~Person()
	{
		cout<<"~Person()"<<endl;
		if(this->name)
		{
			cout<<"name = "<<name<<endl;
			delete this->name;
		}
		if(this->work)
		{
			cout<<"work = "<<work<<endl;
			delete this->work;
		}
	}
};

Person per_g("per_g",10);

void func()
{
	Person per_func("per_func",11);
	static Person per_func_s("per_func_s",11);
}

int main(int argc, char **argv)
{
	Person per_main("per_main",11);
	static Person per_main_s("per_main_s",11);

	for(int i = 0; i<2; i++)
	{
		func();
		Person per_for("per_for",i);
	}
	return 0;	
}


