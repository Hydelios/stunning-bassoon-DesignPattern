//
// Created by Hydelios on 2021/3/26.
//

#ifndef DESIGNPATTERN_SINGLETON_H
#define DESIGNPATTERN_SINGLETON_H
#include <mutex>
using namespace std;

class Singleton {
public:
    // 获取单实例对象
    static Singleton *getInstance();

    //释放单实例，进程退出时调用
    static void deleteInstance();

    // 打印实例地址
    void Print();

private:
    // 将其构造和析构成为私有的, 禁止外部构造和析构
    Singleton();
    ~Singleton();

    Singleton(Singleton &signal) = delete;//删除拷贝构造
    const Singleton operator=(const Singleton &signal) = delete;//删除运算符拷贝

    static mutex mtx;
    static Singleton *singleton;
};

#endif //DESIGNPATTERN_SINGLETON_H
