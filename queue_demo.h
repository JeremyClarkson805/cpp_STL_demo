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
    //��������
    queue<Person> q;
    Person p1("����",18);
    Person p2("����",19);
    Person p3("������",20);
    Person p4("�����",21);
    q.push(p1);
    q.push(p2);
    q.push(p3);
    q.push(p4);
    cout<<"���д�СΪ:"<<q.size()<<endl;
    //�ж�ֻҪ���в�Ϊ�գ��鿴��ͷ��β������
    while(!q.empty())
    {
        cout<<"��ͷԪ��-����:"<<q.front().m_Name<<"  "<<"��ͷԪ��-����:"<<q.front().m_Age<<endl;
        cout<<"��βԪ��-����:"<<q.back().m_Name<<"  "<<"��βԪ��-����:"<<q.back().m_Age<<endl;
        q.pop();
    }
    cout<<"���д�СΪ:"<<q.size()<<endl;
}