//
// Created by Hydelios on 2021/3/26.
//

#include "singleton.h"
#include <iostream>

using namespace std;

//初始化静态成员变量
Singleton *singleton = nullptr;
mutex Singleton::mtx;

Singleton *Singleton::getInstance() {
    //  这里使用了两个 if判断语句的技术称为双检锁；好处是，只有判断指针为空的时候才加锁，
    //  避免每次调用 getInstance的方法都加锁，锁的开销毕竟还是有点大的。
    if (singleton == nullptr) {
        unique_lock<mutex> lock(mtx);
        if (singleton == nullptr) {
            singleton = new Singleton;
        }
    }
    return singleton;
}

void Singleton::deleteInstance() {
    unique_lock<mutex> lock(mtx);
    if (singleton) {
        delete singleton;
        singleton = nullptr;
    }
}

void Singleton::Print() {
    cout << "单例内存地址" << this << endl;
}

Singleton::Singleton() {
    cout << "构造函数" << endl;
}

Singleton::~Singleton() {
    cout << "析构函数" << endl;
}