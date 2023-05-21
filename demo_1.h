#include <iostream>
using namespace std;
#include<vector>
#include <string>
#include <algorithm>
#pragma once

//STL 遍历元素和尾插法的使用

void myPrint(int val)
{
    cout<<val<<endl;
}

void test_1()
{
    vector<int> v;//创建了一个vector容器
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);
    vector<int>::iterator itBegin = v.begin();
    //iterator---迭代器的名称   v.begin()---起始迭代器 指向容器中的第一个元素
    vector<int>::iterator itEnd = v.end();
    //v.end()指向容器中最后一个元素的下一个位置

    //第一种遍历方式
//    while(itBegin != itEnd)
//    {
//        cout<<*itBegin<<endl;
//        itBegin++;
//    }
    //第二种遍历方式
//    for (vector<int>::iterator it = v.begin();it != v.end();it++)
//    {
//        cout<<*it<<endl;
//    }
    //第三种遍历方式  利用STL提供的遍历算法
    for_each(v.begin(),v.end(),myPrint);
    //第四种增强型for循环
    for(auto i:v)
    {
        cout<<i<<endl;
    }
}

void test_2()
{
    class Person
    {
    public:
        string m_Name;
        int m_Age;
        Person(string name,int age)
        {
            this->m_Name = name;
            this->m_Age = age;
        }
    };
    vector<Person>v;
    Person p1("张三",18);
    Person p2("李四",19);
    Person p3("王五",20);
    Person p4("张昕暄",21);
    Person p5("高子婷",22);
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    v.push_back(p5);
    for(vector<Person>::iterator it = v.begin();it != v.end();it++)
    {
        cout<<"姓名:"<<(*it).m_Name<<"年龄:"<<it->m_Age<<endl;
        //(*it).m_Name   解引用 和 直接->出来都是可以的
    }
}

void test_3()
{
    class Person
    {
    public:
        string m_Name;
        int m_Age;
        Person(string name,int age)
        {
            this->m_Name = name;
            this->m_Age = age;
        }
    };
    vector<Person*>v;
    Person p1("张三",18);
    Person p2("李四",19);
    Person p3("王五",20);
    Person p4("张昕暄",21);
    Person p5("高子婷",22);
    v.push_back(&p1);
    v.push_back(&p2);
    v.push_back(&p3);
    v.push_back(&p4);
    v.push_back(&p5);
    for(vector<Person*>::iterator it = v.begin();it != v.end();it++)
    {
        //此时*it拿到的是一个指针地址，需要在用一个->才能拿到原来的数据
        cout<<"姓名:"<<(*it)->m_Name<<"年龄:"<<(*it)->m_Age<<endl;
        //(*it).m_Name   解引用 和 直接->出来都是可以的
    }
}