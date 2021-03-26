//
// Created by Hydelios on 2021/3/26.
//

#include <iostream>
#include "singleton.h"

int main() {
    Singleton *p;
    p = Singleton::getInstance();
    Singleton::deleteInstance();
    p = nullptr;

    return 0;
}