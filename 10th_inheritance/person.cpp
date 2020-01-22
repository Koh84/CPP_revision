#include <stdio.h>
#include <iostream>
#include <string.h>
#include <unistd.h>

using namespace std;

class Person{
private:
	static int cnt;	
	char *name;
	int age;
	
public:
	static int getCount(void);

	Person(){ cout<<"Person()"<<endl;
		name = NULL;
		cnt++;	
	}
	Person(char *name)
	{
		cout<<"Person(char *name)"<<endl;
		this->name = new char[strlen(name)+1];
		strcpy(this->name,name);
		cnt++;
	}

	Person(char *name, int age)
	{
		cout<<"Person(char *name, int age), name ="<<name<<", age = "<<age<<endl;
		
		this->age = age;
		
		this->name = new char[strlen(name)+1];
		strcpy(this->name,name);

		cnt++;
	}

	Person(Person &per)
	{
		cout<<"Person(Person &per)"<<endl;
		
		this->age = per.age;
		
		this->name = new char[strlen(per.name)+1];
		strcpy(this->name, per.name);

		cnt++;
	}

	void setName(char *name)
	{
		if(this->name)
		{
			delete this->name;
		}

		this->name = new char[strlen(name)+1];
		strcpy(this->name, name);
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
		cout<<"name = "<<name<<", age = "<<age<<endl;
	}

	~Person()
	{
		cout<<"~Person()"<<endl;
		if(this->name)
		{
			delete this->name;
		}
	}
};

int Person::cnt=0;
int Person::getCount(void)
{
	return cnt;
}

class Student : public Person {
};

int main(int argc, char **argv)
{
	Student s;
	s.setName("zhangsan");
	s.setAge(16);
	s.printInfo();

	return 0;	
}


