//����Ƕ������
#include <iostream>
using namespace std;
#include<vector>
#include <string>
#include <algorithm>

void test_4()
{
    vector<vector<int>>v;
    //����С����
    vector<int>v1;
    vector<int>v2;
    vector<int>v3;
    vector<int>v4;
    vector<int>v5;
    //��С�������������
    for(int i=0;i<4;i++)
    {
        v1.push_back(i+1);
        v2.push_back(i+2);
        v3.push_back(i+3);
        v4.push_back(i+4);
        v5.push_back(i+5);
    }
    //��С�������뵽��������
    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);
    v.push_back(v4);
    v.push_back(v5);
    //ͨ�����������������ݱ���һ��
    for(auto i:v)
    {
        for(auto j:i)
        {
            cout<<j<<"  ";
        }
        cout<<endl;
    }
}