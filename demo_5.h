//deque容器
#include <iostream>
using namespace std;
#include<vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>


void test_15()
{
    map<int,string> m;//声明一个键值对的集合
    pair<int,string> a(1,"张三");//创建一个键值对
    m.insert(a);//方式1:把创建的键值对加入集合
    m.insert(pair<int,string>(2,"李四"));//方法2:用pair的构造函数直接构造对象后插入
    m.insert(make_pair(3,"王五"));//方式3:用make_pair函数构建对象后插入
    for (auto &i:m)
    {
        cout<<i.first<<":"<<i.second<<" ";
        cout<<endl;
    }
    multimap<int,string>::iterator t;//新建迭代器
    cout<<endl;
    for(t = m.begin();t!=m.end();t++)
    {
        cout<<t->first<<":"<<t->second<<endl;
    }
}

void test_16()
{
    class A
    {
    public:
        int age = 10;
        double height = 1.70;
        string name = "张三";
        A(){}
        A(int age,double height,string name)   : age(age),height(height),name(name){}
        bool operator<(const A& a)const//重载<使其具有可比性
        {
            return (this->age-a.age<0);
        }
    };
    set<A> s;
    s.insert(A(19,1.68,"高子婷"));
    s.insert(A(20,1.70,"张昕暄"));
    for (auto &t:s)
    {
        cout<<t.name<<"\t"<<t.age<<"\t"<<t.height<<endl;
    }
}

/*
 * map是键值对的集合
 * 键值对叫pair
 * python:key->value
 * c++:first->second
 * 不允许键重复
 * 就算随意插入，输出的时候也是按照从小到大排好的顺序输出的
 */