#include <iostream>
#include <queue>
#include <vector>
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

void test_31()
{
    class Customer
    {
    public:
        Customer(){};
        Customer(string name,int priority,double balance):name(name),priority(priority),balance(balance){}
        bool operator()(const Customer &a,const Customer &b)//�麯����������������������������Ԫ�ؾ��пɱ���
        {
            return a.priority < b.priority;
        }
        void show()
        {
            cout<<this->name<<","<<this->priority<<","<<this->balance<<endl;
        }
    private:
        int priority = 0;
        string name;
        double balance;
    };

    priority_queue<Customer,vector<Customer>,Customer> pq;//�½���һ�����ȼ����У����һ��Customer�൱��Customer(Customer a,Customer b)  һ���麯��
    pq.push(Customer("����",8,1000000));//�������������û�:����Customer���캯���½�һ�������ٰѶ���ѹ��ջ
    pq.emplace("����",6,2000000);//�������������û���ֱ�Ӱѹ��캯���Ĳ�������emplace���ɶ����Լ���λ���½�����
    Customer c("����",7,3000000);
    pq.push(c);



    while(!pq.empty())
    {
        Customer c = pq.top();
        c.show();
        pq.pop();
    }
}