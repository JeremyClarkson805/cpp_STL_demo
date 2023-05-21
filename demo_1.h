#include <iostream>
using namespace std;
#include<vector>
#include <string>
#include <algorithm>
#pragma once

//STL ����Ԫ�غ�β�巨��ʹ��

void myPrint(int val)
{
    cout<<val<<endl;
}

void test_1()
{
    vector<int> v;//������һ��vector����
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);
    vector<int>::iterator itBegin = v.begin();
    //iterator---������������   v.begin()---��ʼ������ ָ�������еĵ�һ��Ԫ��
    vector<int>::iterator itEnd = v.end();
    //v.end()ָ�����������һ��Ԫ�ص���һ��λ��

    //��һ�ֱ�����ʽ
//    while(itBegin != itEnd)
//    {
//        cout<<*itBegin<<endl;
//        itBegin++;
//    }
    //�ڶ��ֱ�����ʽ
//    for (vector<int>::iterator it = v.begin();it != v.end();it++)
//    {
//        cout<<*it<<endl;
//    }
    //�����ֱ�����ʽ  ����STL�ṩ�ı����㷨
    for_each(v.begin(),v.end(),myPrint);
    //��������ǿ��forѭ��
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
    Person p1("����",18);
    Person p2("����",19);
    Person p3("����",20);
    Person p4("�����",21);
    Person p5("������",22);
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    v.push_back(p5);
    for(vector<Person>::iterator it = v.begin();it != v.end();it++)
    {
        cout<<"����:"<<(*it).m_Name<<"����:"<<it->m_Age<<endl;
        //(*it).m_Name   ������ �� ֱ��->�������ǿ��Ե�
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
    Person p1("����",18);
    Person p2("����",19);
    Person p3("����",20);
    Person p4("�����",21);
    Person p5("������",22);
    v.push_back(&p1);
    v.push_back(&p2);
    v.push_back(&p3);
    v.push_back(&p4);
    v.push_back(&p5);
    for(vector<Person*>::iterator it = v.begin();it != v.end();it++)
    {
        //��ʱ*it�õ�����һ��ָ���ַ����Ҫ����һ��->�����õ�ԭ��������
        cout<<"����:"<<(*it)->m_Name<<"����:"<<(*it)->m_Age<<endl;
        //(*it).m_Name   ������ �� ֱ��->�������ǿ��Ե�
    }
}