#include <iostream>
#include <list>
using namespace std;

void printList(const list<int> &L)
{
    for(auto i:L)
    {
        cout<<i<<"  ";
    }
    cout<<endl;
}

void test_25()//构造函数
{
    //创建List容器
    list<int> L1;
    //添加容器
    L1.push_back(10);
    L1.push_back(20);
    L1.push_back(30);
    L1.push_back(40);
    //遍历容器
    printList(L1);

    //区间方式构造
    list<int> L2(L1.begin(),L1.end());
    printList(L2);

    //拷贝构造
    list<int> L3(L2);
    printList(L3);

    //n个elem
    list<int> L4(5,100);
    printList(L4);
}

void test_26()
{
    list<int> L1;
    L1.push_back(10);
    L1.push_back(20);
    L1.push_back(30);
    L1.push_back(40);
    printList(L1);

    list<int> L2;
    L2 = L1;
    printList(L2);

    list<int> L3;
    L3.assign(L2.begin(),L2.end());
    printList(L3);

    list<int> L4;
    L4.assign(5,100);
    printList(L4);
}

void test_27()
{
    list<int> L1;
    L1.push_back(10);
    L1.push_back(20);
    L1.push_back(30);
    L1.push_back(40);

    list<int> L2;
    L2.assign(5,100);
    cout<<"交换前:"<<endl;
    printList(L1);
    printList(L2);
    L1.swap(L2);
    cout<<"交换后:"<<endl;
    printList(L1);
    printList(L2);
}

void test_28()
{
    list<int> L;
    L.push_back(10);
    L.push_back(20);
    L.push_back(30);
    L.push_front(100);
    L.push_front(200);
    printList(L);
    list<int>::iterator it = L.begin();
    L.insert(++it,5,50);
    printList(L);
    L.remove(30);
    printList(L);
    cout<<L.front()<<" "<<L.back()<<endl;
}

void test_29()
{
    list<int> L;
    L.push_back(20);
    L.push_back(10);
    L.push_back(30);
    L.push_back(50);
    L.push_back(40);
    L.reverse();
    printList(L);
    L.sort();
    printList(L);
}