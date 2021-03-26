//
// Created by Hydelios on 2021/3/27.
//

#ifndef DESIGNPATTERN_ADAPTER_H
#define DESIGNPATTERN_ADAPTER_H

#include <iostream>

using namespace std;

class origin {
public:
    void realize() { cout << "Realize" << endl; }
};

class Target {
public:
    virtual void request() = 0;
};

class CTarget : public Target {
public:
    void request() override { m_origin.realize(); }

    //采用组合的方式origin作为Target的一部分，优先使用组合而非继承
    origin m_origin;
};

#endif //DESIGNPATTERN_ADAPTER_H
