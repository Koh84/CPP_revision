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
		//cout<<"name = "<<name<<", age = "<<age<<", work = "<<work<<endl;
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


void test_fun()
{
	Person per("zhangsan",16);

	Person *per7 = new Person("lisi",18,"student");
	//delete per7; //if we use new to create object, we must ideally use delete to delete them
}

int main(int argc, char **argv)
{
	test_fun();
	cout<<"Run test_fun end"<<endl;
	sleep(10);
	return 0;	
}


