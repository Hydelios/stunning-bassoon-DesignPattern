//
// Created by Hydelios on 2021/4/13.
//

#ifndef DESIGNPATTERN_BRIDGE_H
#define DESIGNPATTERN_BRIDGE_H
#include <iostream>
using namespace std;

class OS {
public:
    string OSname;

    virtual void InstallOS() = 0;
};

class Linux : public OS {
public:
    virtual void InstallOS() override {
        OSname = "Linux";
        cout << "Install Linux." << endl;
    }
};

class Windows : public OS {
public:
    virtual void InstallOS() override {
        OSname = "Windows";
        cout << "Install Windows." << endl;
    }
};

class Computer {
protected:
    OS *m_os;
public:
    virtual void ShowOS() = 0;
};

class DellComputer : public Computer {
public:
    DellComputer(OS *os) {
        os->InstallOS();
        m_os = os;
    }

    virtual void ShowOS() override { cout << m_os->OSname << endl; }
};

class AppleComputer : public Computer {
public:
    AppleComputer(OS *os) {
        os->InstallOS();
        m_os = os;
    }

    virtual void ShowOS() override { cout << m_os->OSname << endl; }
};

/*
int main() {
    OS *os1 = new Linux;
    OS *os2 = new Windows;
    Computer *computer1 = new DellComputer(os1);
    Computer *computer2 = new DellComputer(os2);
    computer1->ShowOS();
    computer2->ShowOS();
    return 1;
}
*/

#endif //DESIGNPATTERN_BRIDGE_H
