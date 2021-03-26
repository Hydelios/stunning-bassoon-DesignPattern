//
// Created by Hydelios on 2021/3/27.
//

#include <iostream>
#include "adapter.h"

int main() {
    Target* pTarget = new CTarget;
    pTarget->request();
    return 0;
}
