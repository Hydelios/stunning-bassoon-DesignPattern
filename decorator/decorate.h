//
// Created by Hydelios on 2021/3/29.
//

#ifndef DESIGNPATTERN_DECORATE_H
#define DESIGNPATTERN_DECORATE_H
#include <iostream>
using namespace std;

class Drink
{
public:
    Drink() {}
    ~Drink() {}

    virtual float cost() = 0;
    void setDescription(string description) { this->description = description; }
    void setPrice(float price) { this->price = price; }

    string getDescription() { return this->description; }
    float getPrice() { return this->price; }

public:
    string description;
private:
    float price = 0;
};

class Coffee:public Drink
{
public:
    Coffee() {}
    ~Coffee() {}

    float cost() { return getPrice(); }
};

class Decafe:public Coffee
{
public:
    Decafe(){ this->setDescription("Decafe"); this->setPrice(2.5); }
    ~Decafe() {};
};

class Decorator:public Drink
{
    Drink* obj;
public:
    Decorator(Drink* obj):Drink() { this->obj = obj; }
    ~Decorator() {}

    float cost() { return obj->getPrice()+Drink::getPrice(); }
    string getDescription() { return obj->getDescription() + "+" + Drink::getDescription(); }

private:

};

class Milk:public Decorator
{
public:
    Milk(Drink* obj):Decorator(obj) { this->setDescription("Milk"); this->setPrice(2.0); }
    ~Milk() {}

};

/*
int main()
{
	Drink* order;
	order = new Decafe();
	cout << order->cost() << endl;
	cout << order->getDescription() << endl;

	Decorator* diff_flavor;
	diff_flavor = new Milk(order);
	cout << diff_flavor->cost() << endl;
	cout << diff_flavor->getDescription() << endl;
}
*/
#endif //DESIGNPATTERN_DECORATE_H
