#include <stdio.h>
#include <iostream>

using namespace std;

class Person{
private:	
	char *name;
	int age;
	char *work;
public:

	Person(){ cout<<"Person()"<<endl;}
	Person(char *name)
	{
		cout<<"Person(char *name)"<<endl;
		this->name = name;
	}

	Person(char *name, int age, char *work = "none")
	{
		cout<<"Person(char *name, int age)"<<endl;
		this->name = name;
		this->age = age;
		this->work = work;
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

};


int main()
{
	Person per("zhangsan",16);
	Person per2;
	Person per3(); /* wrong - int fun(); function declaration */

	//dynamically allocated
	Person *per4 = new Person;
	Person *per5 = new Person();

	Person *per6 = new Person[2];

	Person *per7 = new Person("lisi",18,"student");
	Person *per8 = new Person("wangwu",18);

	per7->printInfo();
	per8->printInfo();

	per.printInfo();

	//will be automatically delete when program close
	//or you can use delete
	delete per4;
	delete per5;
	delete []per6;
	delete per7;
	delete per8;

	return 0;
}


