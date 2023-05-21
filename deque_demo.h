//deque容器
#include <iostream>
#include <string>
#include <deque>
#include <algorithm>

using namespace std;

void printDeque(deque<int>&d)
{
    for(auto it : d)
    {
        cout<<it<<"  ";
    }
    cout<<endl;
}

void test_17()//deque的四种构造函数
{
    deque<int> d1;
    for (int i = 0; i < 10; i++)//第一种，push_back
    {
        d1.push_back(i);
    }
    printDeque(d1);

    deque<int>d2(d1.begin(),d1.end());
    printDeque(d2);

    deque<int>d3(10,50);//第三种，重复的n个数
    printDeque(d3);

    deque<int>d4(d3);   //第四种，拷贝构造函数
    printDeque(d4);
}

void test_18()
{
    deque<int> d1;
    for (int i = 0; i < 10; i++)
    {
        d1.push_back(i);
    }
    printDeque(d1);

    deque<int> d2;//利用重载的 = 来赋值
    d2 = d1;
    printDeque(d2);

    deque<int>d3(d1.begin(),d1.end());
    printDeque(d3);

    deque<int>d4;
    d4.assign(10,100);
    printDeque(d4);
}

void test_19()//deque的大小操作
{
    deque<int> d1;
    for (int i = 0; i < 10; i++)
    {
        d1.push_back(i);
    }
    if (d1.empty())
    {
        cout<<"d1为空"<<endl;
    }
    else
    {
        cout<<"d1不为空"<<endl;
        cout<<"d1的大小为:"<<d1.size()<<endl;
        //deque容器没有容量的概念
    }
    d1.resize(15);
    printDeque(d1);
    d1.resize(20,1);
    printDeque(d1);
    d1.resize(9);
    printDeque(d1);
}

void test_20()//deque容器的插入和删除
{
    deque<int> d1;
    for (int i = 0; i < 21; i+= 10)
    {
        d1.push_back(i);//尾插法
    }
    printDeque(d1);

    d1.push_front(67);//头插
    printDeque(d1);

    d1.pop_back();
    printDeque(d1);//尾删

    d1.pop_front();//头删
    printDeque(d1);

    d1.insert(d1.cbegin(),1000);//insert迭代器插入
    printDeque(d1);

    d1.insert(d1.begin(),2,500);
    printDeque(d1);
}

void test_21()//deque容器数据存取
{
    deque<int>d;
    d.push_back(10);
    d.push_back(20);
    d.push_back(30);
    d.push_front(100);
    d.push_front(200);
    d.push_front(300);

    //通过[]方式访问元素
    for(int i=0;i<d.size();i++)
    {
        cout<<d[i]<<" ";
    }
    cout<<endl;

    //通过at方式访问元素
    cout<<d.at(1)<<endl;
}

void test_22()
{
    deque<int>d;
    d.push_back(10);
    d.push_back(20);
    d.push_back(30);
    d.push_front(100);
    d.push_front(200);
    d.push_front(300);
    printDeque(d);
    sort(d.begin(),d.end());   //排序 默认排序规则 从小到大 升序
    printDeque(d);
}

