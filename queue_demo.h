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

void test_31()
{
    class Customer
    {
    public:
        Customer(){};
        Customer(string name,int priority,double balance):name(name),priority(priority),balance(balance){}
        bool operator()(const Customer &a,const Customer &b)//虚函数，即可类名当作函数看待，让元素具有可比性
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

    priority_queue<Customer,vector<Customer>,Customer> pq;//新建了一个优先级队列，最后一个Customer相当于Customer(Customer a,Customer b)  一个虚函数
    pq.push(Customer("张三",8,1000000));//往队列里新增用户:先用Customer构造函数新建一个对象，再把对象压入栈
    pq.emplace("李四",6,2000000);//往队列里新增用户，直接把构造函数的参数给到emplace，由队列自己新位置新建对象
    Customer c("王五",7,3000000);
    pq.push(c);



    while(!pq.empty())
    {
        Customer c = pq.top();
        c.show();
        pq.pop();
    }
}