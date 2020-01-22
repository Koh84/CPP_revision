#include <stdio.h>
#include <iostream>
#include <string.h>
#include <unistd.h>

using namespace std;

class Person{
private:
	char *name;
	int age;
	
public:
	int address;

	Person(){ cout<<"Person()"<<endl;
		name = NULL;
	}
	Person(char *name)
	{
		cout<<"Person(char *name)"<<endl;
		this->name = new char[strlen(name)+1];
		strcpy(this->name,name);
	}

	Person(char *name, int age)
	{
		cout<<"Person(char *name, int age), name ="<<name<<", age = "<<age<<endl;
		
		this->age = age;
		
		this->name = new char[strlen(name)+1];
		strcpy(this->name,name);

	}

	Person(Person &per)
	{
		cout<<"Person(Person &per)"<<endl;
		
		this->age = per.age;
		
		this->name = new char[strlen(per.name)+1];
		strcpy(this->name, per.name);
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

class Student : public Person {
private:
	int grade;
	int getGrade(void)
	{
		return grade;
	}
	void setGrade(int grade)
	{
		this->grade = grade;
	}

public:
	void printInfo(void)
	{
		cout<<"Student = "<<endl;
		Person::printInfo();
	}
};

void test_func(Person &p)
{
	p.printInfo();
}

int main(int argc, char **argv)
{
	Person p("lisi",16);
	
	Student s;
	s.setName("zhangsan");
	s.setAge(16);
	
	test_func(p);
	test_func(s);	/* Person &p = s - this means it will use function in person class */

	s.printInfo();  /* this will use function in student class */

	return 0;	
}


