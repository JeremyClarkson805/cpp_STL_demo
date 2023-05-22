//vector容器
#include <iostream>
#include<vector>
#include <string>
#include <algorithm>
using namespace std;

void printVector(vector<int>&v)//打印输出vector的函数
{
    for (auto i:v)
    {
        cout<<i<<" ";
    }
    cout<<endl;
}

//vector的四种构造函数
void test_6()
{
    vector<int> v1;//默认构造，无参构造
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }
    printVector(v1);

    //通过区间的方式进行构造
    vector<int> v2(v1.begin(),v1.end());
    printVector(v2);

    //n个elem方式构造  ,第一个参数是多少个相同的元素，第二个是要放进去的元素
    vector<int> v3(10,100);
    printVector(v3);

    //拷贝构造
    vector<int> v4(v3);
    printVector(v4);
}

//vector赋值
void test_7()
{
    //push_back()赋值
    vector<int> v1;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }
    printVector(v1);

    vector<int>v2;
    v2 = v1;//利用重载的operator来给v2赋值
    printVector(v2);

    //assign
    vector<int>v3;
    v3.assign(v1.begin()+1,v1.end()-1);
    printVector(v3);

    //n个elem方式赋值
    vector<int>v4;
    v4.assign(10,50);
    printVector(v4);
}

//vector容器的容量和大小操作
void test_8()
{
    vector<int> v1;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }
    printVector(v1);

    if(v1.empty())
    {
        cout<<"v1为空"<<endl;
    }
    else
    {
        cout<<"v1不为空"<<endl;
        cout<<"v1的容量为:"<<v1.capacity()<<endl;
        cout<<"v1的大小为:"<<v1.size()<<endl;
    }

    //重新指定大小
    v1.resize(15);
    printVector(v1);//默认会用0填充多出来的位置，也可以指定用什么来填充
    v1.resize(20,50);
    printVector(v1);
    v1.resize(10);
    printVector(v1);
}

//vector的插入和删除
void test_9()
{
    vector<int> v1;
    for(int i=0;i<51;i+=10)
    {
        v1.push_back(i);
    }
    printVector(v1);
    //尾删法
    v1.pop_back();
    printVector(v1);
    //插入
    v1.insert(v1.begin(),100);
    printVector(v1);

    v1.insert(v1.begin(),3,1000);
    printVector(v1);
    //删除 他的参数也是迭代器
    v1.erase(v1.begin());
    printVector(v1);
    //清空
    v1.clear();
    //或者v1.erase(v1.begin(),v1.end())
    printVector(v1);
}

//vector容器的数据存取
void test_10()
{
    vector<int> v1;
    for(int i=0;i<10;i+=1)
    {
        v1.push_back(i);
    }

    //利用[]方式访问数组中元素
    for(int i=0;i<v1.size();i++)
    {
        cout<<v1[i]<<" ";
    }

    //利用at方式访问元素
    for(int i=0;i<v1.size();i++)
    {
        cout<<v1.at(i)<<" ";
    }
    cout<<endl;
    //获取第一个元素
    cout<<"第一个元素:"<<v1.front()<<endl;
    //获取最后一个元素
    cout<<"最后一个元素为:"<<v1.back()<<endl;
}

//vector容器互换
//1.基本使用
void test_11()
{
    cout<<"交换前:"<<endl;
    vector<int>v1;
    for(int i=0;i<10;i++)
    {
        v1.push_back(i);
    }
    printVector(v1);
    vector<int>v2;
    for(int i=10;i>0;i--)
    {
        v2.push_back(i);
    }
    printVector(v2);
    cout<<"交换后:"<<endl;
    v1.swap(v2);
    printVector(v1);
    printVector(v2);
}
//2.实际用途
//巧用swap可以收缩内存空间
void test_12()
{
    vector<int>v;
    for(int i=0;i<100000;i++)
    {
        v.push_back(i);
    }
    cout<<"v的容量为:"<<v.capacity()<<endl;
    cout<<"v的大小为:"<<v.size()<<endl;

    v.resize(3);
    cout<<"v的容量为:"<<v.capacity()<<endl;
    cout<<"v的大小为:"<<v.size()<<endl;
    //由这里的的结果可以看到,resize以后v的容量是不变的，相当于在内存里面还是占了很大一块空间
    //但是没有使用，这就会造成浪费
    cout<<"-----------------------------";
    //巧用swap收缩内存
    vector<int>(v).swap(v);
    //vector<int>(v)叫匿名对象，实际上调用了拷贝构造函数
    //会用v的大小来初始化匿名对象，因此传给匿名对象的拷贝构造函数以后,容量就是3
    //这样就能够节省下内存空间
    //匿名空间再执行后会立马删除
    cout<<"v的容量为:"<<v.capacity()<<endl;
    cout<<"v的大小为:"<<v.size()<<endl;
}

void test_13()
{
    vector<int>v;
    int num = 0;//统计开辟的次数
    int *p = NULL;
    for(int i=0;i<100000;i++)
    {
        v.push_back(i);
        if (p!= &v[0])//用来统计开辟了多少次内存
        {             //如果p的地址不等于第一个元素的地址
            p = &v[0];//那么就把p指向第一个元素
            num += 1;
        }
    }
    cout<<"num = "<<num<<endl;
}

void test_14()
{
    vector<int>v;
    v.reserve(100000);
    int num = 0;//统计开辟的次数
    int *p = NULL;
    for(int i=0;i<100000;i++)
    {
        v.push_back(i);
        if (p!= &v[0])//用来统计开辟了多少次内存
        {             //如果p的地址不等于第一个元素的地址
            p = &v[0];//那么就把p指向第一个元素
            num += 1;
        }
    }
    cout<<"num = "<<num<<endl;
}

void myf(int x)
{
    x = x * 2;
    cout<<x<<endl;
}

void test_32()
{
    vector<int> v = {2,4,6,8,10};
    for_each(v.begin(),v.end(),myf);
    for(auto &t:v)
    {
        cout<<t<<"  ";
    }
    cout<<endl;
}
