//stack����
#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

void test_23()
{
//    �ص�:�����Ƚ���������ݽṹ
    std::stack<int> s;
    //��ջ
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    //ֻҪջ��Ϊ��,�鿴ջ�����ִ�г�ջ����
    while(!s.empty())
    {
        //�鿴ջ��Ԫ��
        std::cout<<"ջ��Ԫ��Ϊ:"<<s.top()<< std::endl;

        //��ջ
        s.pop();
    }
    std::cout<<"ջ�Ĵ�С:"<<s.size()<<std::endl;
}