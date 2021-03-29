//
// Created by Hydelios on 2021/3/29.
//

#ifndef DESIGNPATTERN_TEMPLATE_H
#define DESIGNPATTERN_TEMPLATE_H
#include <iostream>
using namespace std;

class Template
{
public:
    Template() {}
    ~Template(){}

public:
    virtual void Test() = 0;
};

class myTemplate:public Template
{
public:
    myTemplate(){}
    ~myTemplate(){}

    //?????????????,??????????????????????????
    //?????????????????????????????????????????
    virtual void Test() { step1(); step2(); }

protected:
    virtual void step1() = 0;
    virtual void step2() = 0;
};

class myTemplateA:public myTemplate
{
public:
    myTemplateA(){}
    ~myTemplateA(){}

protected:
    virtual void step1() { cout << "A: step 1" << endl; }
    virtual void step2() { cout << "A: step 2" << endl; }
};

class myTemplateB :public myTemplate
{
public:
    myTemplateB() {}
    ~myTemplateB() {}

protected:
    virtual void step1() { cout << "B: step 1" << endl; }
    virtual void step2() { cout << "B: step 2" << endl; }
};

/*
int main()
{
	myTemplate* mytest_A = new myTemplateA;
	myTemplate* mytest_B = new myTemplateB;
	mytest_A->Test();
	mytest_B->Test();
}
*/
#endif //DESIGNPATTERN_TEMPLATE_H
