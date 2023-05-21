//deque����
#include <iostream>
using namespace std;
#include<vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>


void test_15()
{
    map<int,string> m;//����һ����ֵ�Եļ���
    pair<int,string> a(1,"����");//����һ����ֵ��
    m.insert(a);//��ʽ1:�Ѵ����ļ�ֵ�Լ��뼯��
    m.insert(pair<int,string>(2,"����"));//����2:��pair�Ĺ��캯��ֱ�ӹ����������
    m.insert(make_pair(3,"����"));//��ʽ3:��make_pair����������������
    for (auto &i:m)
    {
        cout<<i.first<<":"<<i.second<<" ";
        cout<<endl;
    }
    multimap<int,string>::iterator t;//�½�������
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
        string name = "����";
        A(){}
        A(int age,double height,string name)   : age(age),height(height),name(name){}
        bool operator<(const A& a)const//����<ʹ����пɱ���
        {
            return (this->age-a.age<0);
        }
    };
    set<A> s;
    s.insert(A(19,1.68,"������"));
    s.insert(A(20,1.70,"�����"));
    for (auto &t:s)
    {
        cout<<t.name<<"\t"<<t.age<<"\t"<<t.height<<endl;
    }
}

/*
 * map�Ǽ�ֵ�Եļ���
 * ��ֵ�Խ�pair
 * python:key->value
 * c++:first->second
 * ��������ظ�
 * ����������룬�����ʱ��Ҳ�ǰ��մ�С�����źõ�˳�������
 */