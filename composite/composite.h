//
// Created by Hydelios on 2021/3/29.
//

#ifndef DESIGNPATTERN_COMPOSITE_H
#define DESIGNPATTERN_COMPOSITE_H
#include <iostream>
#include <vector>
using namespace std;

/*
抽象构件（Component）角色：它的主要作用是为树叶构件和树枝构件声明公共接口，
并实现它们的默认行为。在透明式的组合模式中抽象构件还声明访问和管理子类的接口；
在安全式的组合模式中不声明访问和管理子类的接口，管理工作由树枝构件完成。
*/
class Component
{
public:
    Component(){}
    ~Component(){}

public:
    void Add(Component* pElem) {};
    void Remove(Component* pElem) {};
    void RemoveAll() {};
    Component* GetChild(int nIndex) {};

    virtual void test() {};
};

/*
树叶构件（Leaf）角色：是组合中的叶节点对象，它没有子节点，用于实现抽象构件角色中
声明的公共接口。
*/
class LeafA:public Component
{
public:
    LeafA() {}
    ~LeafA() {}

public:
    void test() override{ cout << "Leaf A:test()" << endl; }
};

class LeafB :public Component
{
public:
    LeafB() {}
    ~LeafB() {}

public:
    void test() override{ cout << "Leaf B:test()" << endl; }
};

/*
树枝构件（Composite）角色：是组合中的分支节点对象，它有子节点。它实现了抽象构件角色中声明
的接口，它的主要作用是存储和管理子部件，通常包含 Add()、Remove()、GetChild() 等方法
*/
class Composite:Component
{
public:
    Composite() {}
    ~Composite();

public:
    void Add(Component* pElem);
    void Remove(Component* pElem);
    void RemoveAll();
    Component* GetChild(int nIndex);

public:
    void test() override;

private:
    vector<Component*> m_vecElem;
};

Composite::~Composite()
{
    RemoveAll();
}

void Composite::Add(Component* pElem)
{
    m_vecElem.push_back(pElem);
}

void Composite::Remove(Component* pElem)
{
    auto iter = m_vecElem.begin();
    while (iter != m_vecElem.end())
    {
        if (*iter == pElem)
        {
            delete pElem;
            m_vecElem.erase(iter);
            return;
        }
        iter++;
    }
}

void Composite::RemoveAll()
{
    for (int i = 0; i < m_vecElem.size(); i++)
    {
        delete m_vecElem[i];
    }
    m_vecElem.clear();
}

void Composite::test()
{
    for (int i = 0; i < m_vecElem.size(); i++)
    {
        m_vecElem[i]->test();
    }
}

/*
int main()
{
	Composite box;
	LeafA* A = new LeafA;
	LeafB* B = new LeafB;
	box.Add(A);
	box.Add(B);
	box.test();
}
*/
#endif //DESIGNPATTERN_COMPOSITE_H
