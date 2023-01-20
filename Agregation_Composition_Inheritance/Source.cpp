#include <iostream>
#include<string>
#include<vector>



//агрегация, композиция, наследование

class A {
public:
	
	void public_method(){}

protected:
	void protected_method() {}
private:

	void private_method() {}
};


//public, private, protected - куда мы наследуем
class B : public A{   //protected, public
	void func() {
		protected_method();
	}
};


// Ассоциация - вллючени одного класса в другой

//Агрегация и композиция

//Композиция - один класс не существует без дргого, и один включается в другой
// Например, автомобиль не существует без двигателя

//агрегация - один класс включается в другой, но оба класса могут существовать друг без друга


class Engine {
public:
	Engine(int p) : _power(p) {
		std::cout << "Parametrized constructor was called (Engine)" << std::endl;
	}
	Engine(Engine& other) : _power(other._power) { // поверхностое копирование делается, если мы сами не создали copy constructor
		std::cout << "Copy conctructor was called" << std::endl;
	}
	int getPower() {
		return _power;
	}
private:
	int _power;
};


class  Car
{
public:
	// композиция
	Car(int enginePower) : _engine(enginePower){}
	// агрегация
	Car(Engine &e) : _engine(e){}
	int getPower() {
		return _engine.getPower();
	}

private:
	std::string _model = "Porshe";
	Engine _engine;//Car ассоциирован с Engine
};


int main() {

	A a;
	a.public_method();

	B b;
	b.public_method();
	

	Car c(200); // композиция
	std::cout << c.getPower() << std::endl;
	
	Engine e(333);

	Car c2(e);
	std::cout << c.getPower() << std::endl;
	std::cout << c2.getPower() << std::endl;




	//Виртуально



}