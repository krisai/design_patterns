#include <iostream>
using namespace std;
class obersver{
public:
	virtual void doff()=0;
};
class father : public obersver{
public:
	void doff(){cout<<" feed muilk"<<endl;}
};
class mother:public obersver{
public:
	void doff(){cout<<" dressing"<<endl;}
};
class child{

};

int main(int argc, char const *argv[])
{
	obersver* o = new mother();
	o->doff();
	return 0;
}


