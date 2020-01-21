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
	char *work;
public:
	static int getCount(void);

	Person(){ cout<<"Person()"<<endl;
		name = NULL;
		work = NULL;
		cnt++;	
	}
	Person(char *name)
	{
		cout<<"Person(char *name)"<<endl;
		this->name = new char[strlen(name)+1];
		strcpy(this->name,name);
		this->work = NULL;
		cnt++;
	}

	Person(char *name, int age, char *work = "none")
	{
		cout<<"Person(char *name, int age), name ="<<name<<", age = "<<age<<endl;
		
		this->age = age;
		
		this->name = new char[strlen(name)+1];
		strcpy(this->name,name);

		this->work = new char[strlen(work)+1];
		strcpy(this->work,work);

		cnt++;
	}

	Person(Person &per)
	{
		cout<<"Person(Person &per)"<<endl;
		
		this->age = per.age;
		
		this->name = new char[strlen(per.name)+1];
		strcpy(this->name, per.name);

		this->work = new char[strlen(per.work)+1];
		strcpy(this->work, per.work);

		cnt++;
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

int Person::cnt=0;
int Person::getCount(void)
{
	return cnt;
}

int main(int argc, char **argv)
{
	Person per[10];

	cout<<"Person number = "<<Person::getCount()<<endl;
	cout<<"Person number = "<<per[0].getCount()<<endl;
	cout<<"Person number = "<<per[1].getCount()<<endl;

	return 0;	
}


