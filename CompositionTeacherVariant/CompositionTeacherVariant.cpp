
#include <iostream>


// Агрегация, композиция, наследование

// Ассоциация
// Агрегация и Композиция

// Композиция - один класс не существует без другого.
// Например, автомобиль не существует без двигателя.

//class Engine {
//public:
//	Engine(int p) : _power(p) {
//		std::cout << "Parametrized constructor was called (Engine)" << std::endl;
//	}
//	Engine(Engine& e) : _power(e._power) {
//		std::cout << "Copy constructor was called (Engine)" << std::endl;
//	}
//	int getPower() {
//		return _power;
//	}
//private:
//	int _power;
//};
//
//// class IVehicle
//
//class Car {
//public:
//	// композиция
//	Car(int enginePower) : _engine(enginePower) {}
//	// агрегация
//	Car(Engine &e) : _engine(e) {}
//
//	int getPower() {
//		return _engine.getPower();
//		//...
//	}
//private:
//	std::string _model = "Porshe";
//	Engine _engine; // Car ассоциирован с Engine
//
//};
//
//int main()
//{
//
//	Car c(200);
//	
//	Engine e(333);
//	Car c2(e);
//	std::cout << c.getPower() << std::endl;
//	std::cout << c2.getPower() << std::endl;
//
//}
// ^ dz


// Виртуальное наследование
//class Vehicle {
//public:
//	Vehicle(int speed) : _speed(speed) {
//		std::cout << "Vehicle()" << std::endl;
//	}
//	int getSpeed() {
//		return _speed;
//	}
//
//private:
//	int _speed;
//};
//
//enum Transmition {
//	Auto, 
//	Manual
//};
//
//class Car : public virtual Vehicle {
//public:
//	Car(int speed, Transmition transmition) : 
//		Vehicle(speed), _transmition(transmition) {}
//
//private:
//	Transmition _transmition;
//};
//
//enum OriginCountry {
//	Russia,
//	UAE
//};
//
//class Airplane : public virtual Vehicle {
//public:
//	Airplane(int speed, OriginCountry country) :
//		Vehicle(speed), _originCountry(country) {}
//private:
//	OriginCountry _originCountry;
//};
//
//enum FlyingCarMode {
//	Drive,
//	Fly
//};
//
//class FlyingCar : public Car, Airplane {
//public:
//	FlyingCar(int speed, OriginCountry country,
//		Transmition transmition, FlyingCarMode initialMode)
//		: Car(speed, transmition), Airplane(speed, country),
//		_mode(initialMode), Vehicle(speed) {}
//
//private:
//	FlyingCarMode _mode;
//};
//
//int main() {
//	FlyingCar fc(800, OriginCountry::Russia, Transmition::Auto,
//		FlyingCarMode::Fly);
//	std::cout << fc.getSpeed() << std::endl;
//
//	Vehicle* fc2 = new FlyingCar(800, OriginCountry::Russia, Transmition::Auto,
//		FlyingCarMode::Fly);
//
//	delete fc2;
//}

class A {
public:
	// static dispatch / early binding (статический вызов, ранняя привязка)
	void foo() {
		std::cout << "A::foo()" << std::endl;
	}
};

//class B : public A {
//public:
//	void foo() {
//		std::cout << "B::foo()" << std::endl;
//	}
//};



class B { // vptr
public:
	// vtable
	virtual void bar() {
		std::cout << "B::bar()" << std::endl;
	}
	virtual void qux() {
		std::cout << "B::qux()" << std::endl;
	}
};

class C : public B { // vptr 
public:
	//vptr
	void bar() override {
		std::cout << "C::bar()" << std::endl;
	}
};



int main() {
	B* b = new C;
	b->bar();

}