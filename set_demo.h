#include <iostream>
using namespace std;
#include <set>

void printSet(const set<int> s)
{
    for(auto i:s)
    {
        cout<<i<<"  ";
    }
    cout<<endl;
}

void test_30()
{
    set<int> s1;
    //set容器插入数据只有insert方式
    s1.insert(20);
    s1.insert(10);
    s1.insert(30);
    printSet(s1);

}