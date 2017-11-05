#include <stdio.h>


class Car
{
private:
	Car(){};
	static Car *car;
public:
	virtual ~Car(){
		delete car;
	};
	static Car* getInstance(){
		if(car == nullptr){
			car = new Car;
		}
		return car;
	}	
};

Car* Car::car = nullptr;

int main(int argc, char const *argv[])
{
	// Car *cc = new Car;
	Car *c1 = Car::getInstance();
	Car *c2 = Car::getInstance();
	printf("%p\n",c1 );
	printf("%p\n",c2 );
	return 0;
}

