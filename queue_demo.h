#include <iostream>
#include <queue>
using namespace std;

void test_24()
{
    class Person
    {
    public:
        Person (string name,int age)
        {
            this->m_Name = name;
            this->m_Age = age;
        }
        string m_Name;
        int m_Age;
    };
    //创建队列
    queue<Person> q;
    Person p1("张三",18);
    Person p2("李四",19);
    Person p3("高子婷",20);
    Person p4("张昕暄",21);
    q.push(p1);
    q.push(p2);
    q.push(p3);
    q.push(p4);
    cout<<"队列大小为:"<<q.size()<<endl;
    //判断只要队列不为空，查看队头队尾，出队
    while(!q.empty())
    {
        cout<<"队头元素-姓名:"<<q.front().m_Name<<"  "<<"队头元素-年龄:"<<q.front().m_Age<<endl;
        cout<<"队尾元素-姓名:"<<q.back().m_Name<<"  "<<"队尾元素-年龄:"<<q.back().m_Age<<endl;
        q.pop();
    }
    cout<<"队列大小为:"<<q.size()<<endl;
}