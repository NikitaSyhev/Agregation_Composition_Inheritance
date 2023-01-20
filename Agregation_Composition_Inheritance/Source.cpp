#include <iostream>
#include<string>
#include<vector>



//���������, ����������, ������������

class A {
public:
	
	void public_method(){}

protected:
	void protected_method() {}
private:

	void private_method() {}
};


//public, private, protected - ���� �� ���������
class B : public A{   //protected, public
	void func() {
		protected_method();
	}
};


// ���������� - �������� ������ ������ � ������

//��������� � ����������

//���������� - ���� ����� �� ���������� ��� ������, � ���� ���������� � ������
// ��������, ���������� �� ���������� ��� ���������

//��������� - ���� ����� ���������� � ������, �� ��� ������ ����� ������������ ���� ��� �����


class Engine {
public:
	Engine(int p) : _power(p) {
		std::cout << "Parametrized constructor was called (Engine)" << std::endl;
	}
	Engine(Engine& other) : _power(other._power) { // ������������ ����������� ��������, ���� �� ���� �� ������� copy constructor
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
	// ����������
	Car(int enginePower) : _engine(enginePower){}
	// ���������
	Car(Engine &e) : _engine(e){}
	int getPower() {
		return _engine.getPower();
	}

private:
	std::string _model = "Porshe";
	Engine _engine;//Car ������������ � Engine
};


int main() {

	A a;
	a.public_method();

	B b;
	b.public_method();
	

	Car c(200); // ����������
	std::cout << c.getPower() << std::endl;
	
	Engine e(333);

	Car c2(e);
	std::cout << c.getPower() << std::endl;
	std::cout << c2.getPower() << std::endl;




	//����������



}