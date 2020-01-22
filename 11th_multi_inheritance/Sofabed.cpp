#include <stdio.h>
#include <iostream>
#include <string.h>
#include <unistd.h>

using namespace std;


class Sofa{
private:
public:
	void watchTV(void) { cout<<"watch TV"<<endl; }
};

class Bed{
private:
public:
	void sleep(void) { cout<<"sleep"<<endl; }
};

class Sofabed : public Sofa, public Bed {
	
};


int main(int argc, char **argv)
{
	Sofabed s;
	s.watchTV();
	s.sleep();
	return 0;	
}

