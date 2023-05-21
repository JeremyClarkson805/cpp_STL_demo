//stack容器
#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

void test_23()
{
//    特点:符合先进后出的数据结构
    std::stack<int> s;
    //入栈
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    //只要栈不为空,查看栈项，并且执行出栈操作
    while(!s.empty())
    {
        //查看栈项元素
        std::cout<<"栈项元素为:"<<s.top()<< std::endl;

        //出栈
        s.pop();
    }
    std::cout<<"栈的大小:"<<s.size()<<std::endl;
}