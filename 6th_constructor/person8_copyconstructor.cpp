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

	Person(){/* cout<<"Person()"<<endl;*/
		name = NULL;
		work = NULL;	
	}
	Person(char *name)
	{
		//cout<<"Person(char *name)"<<endl;
		this->name = new char[strlen(name)+1];
		strcpy(this->name,name);
		this->work = NULL;
	}

	Person(char *name, int age, char *work = "none")
	{
		//cout<<"Person(char *name, int age)"<<endl;
		
		this->age = age;
		
		this->name = new char[strlen(name)+1];
		strcpy(this->name,name);

		this->work = new char[strlen(work)+1];
		strcpy(this->work,work);
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

int main(int argc, char **argv)
{
	Person per("zhangsan",16);
	Person per2(per); //Issue with copy constructor is that it point to the memory location
	per2.printInfo();
	return 0;	
}


