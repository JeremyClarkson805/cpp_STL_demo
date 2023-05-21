//deque����
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

void test_17()//deque�����ֹ��캯��
{
    deque<int> d1;
    for (int i = 0; i < 10; i++)//��һ�֣�push_back
    {
        d1.push_back(i);
    }
    printDeque(d1);

    deque<int>d2(d1.begin(),d1.end());
    printDeque(d2);

    deque<int>d3(10,50);//�����֣��ظ���n����
    printDeque(d3);

    deque<int>d4(d3);   //�����֣��������캯��
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

    deque<int> d2;//�������ص� = ����ֵ
    d2 = d1;
    printDeque(d2);

    deque<int>d3(d1.begin(),d1.end());
    printDeque(d3);

    deque<int>d4;
    d4.assign(10,100);
    printDeque(d4);
}

void test_19()//deque�Ĵ�С����
{
    deque<int> d1;
    for (int i = 0; i < 10; i++)
    {
        d1.push_back(i);
    }
    if (d1.empty())
    {
        cout<<"d1Ϊ��"<<endl;
    }
    else
    {
        cout<<"d1��Ϊ��"<<endl;
        cout<<"d1�Ĵ�СΪ:"<<d1.size()<<endl;
        //deque����û�������ĸ���
    }
    d1.resize(15);
    printDeque(d1);
    d1.resize(20,1);
    printDeque(d1);
    d1.resize(9);
    printDeque(d1);
}

void test_20()//deque�����Ĳ����ɾ��
{
    deque<int> d1;
    for (int i = 0; i < 21; i+= 10)
    {
        d1.push_back(i);//β�巨
    }
    printDeque(d1);

    d1.push_front(67);//ͷ��
    printDeque(d1);

    d1.pop_back();
    printDeque(d1);//βɾ

    d1.pop_front();//ͷɾ
    printDeque(d1);

    d1.insert(d1.cbegin(),1000);//insert����������
    printDeque(d1);

    d1.insert(d1.begin(),2,500);
    printDeque(d1);
}

void test_21()//deque�������ݴ�ȡ
{
    deque<int>d;
    d.push_back(10);
    d.push_back(20);
    d.push_back(30);
    d.push_front(100);
    d.push_front(200);
    d.push_front(300);

    //ͨ��[]��ʽ����Ԫ��
    for(int i=0;i<d.size();i++)
    {
        cout<<d[i]<<" ";
    }
    cout<<endl;

    //ͨ��at��ʽ����Ԫ��
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
    sort(d.begin(),d.end());   //���� Ĭ��������� ��С���� ����
    printDeque(d);
}

