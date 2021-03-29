//
// Created by Hydelios on 2021/3/29.
//

#ifndef DESIGNPATTERN_STRATEGY_H
#define DESIGNPATTERN_STRATEGY_H
#include <iostream>
using namespace std;

class Strategy
{
public:
    Strategy() {};
    ~Strategy() {};

    virtual float calc(float a, float b) = 0;
};

class AddStrategy:public Strategy
{
public:
    AddStrategy() {};
    ~AddStrategy() {};

    float calc(float a, float b) override{ return a + b; }
};

class SubStrategy :public Strategy
{
public:
    SubStrategy() {};
    ~SubStrategy() {};

    float calc(float a, float b) override{ return a - b; }
};

class Environment
{
public:
    Environment(Strategy* strategy) { this->strategy = strategy; };
    ~Environment() {};

    float calcultate(float a, float b) { return strategy->calc(a, b); }
private:
    Strategy* strategy;
};

/*
int main()
{
	Environment* env_add = new Environment(new AddStrategy);
	Environment* env_sub = new Environment(new SubStrategy);

	cout << env_add->calcultate(10, 5) << endl;
	cout << env_sub->calcultate(10, 5) << endl;
}
*/
#endif //DESIGNPATTERN_STRATEGY_H
