//vector����
#include <iostream>
#include<vector>
#include <string>
#include <algorithm>
using namespace std;

void printVector(vector<int>&v)//��ӡ���vector�ĺ���
{
    for (auto i:v)
    {
        cout<<i<<" ";
    }
    cout<<endl;
}

//vector�����ֹ��캯��
void test_6()
{
    vector<int> v1;//Ĭ�Ϲ��죬�޲ι���
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }
    printVector(v1);

    //ͨ������ķ�ʽ���й���
    vector<int> v2(v1.begin(),v1.end());
    printVector(v2);

    //n��elem��ʽ����  ,��һ�������Ƕ��ٸ���ͬ��Ԫ�أ��ڶ�����Ҫ�Ž�ȥ��Ԫ��
    vector<int> v3(10,100);
    printVector(v3);

    //��������
    vector<int> v4(v3);
    printVector(v4);
}

//vector��ֵ
void test_7()
{
    //push_back()��ֵ
    vector<int> v1;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }
    printVector(v1);

    vector<int>v2;
    v2 = v1;//�������ص�operator����v2��ֵ
    printVector(v2);

    //assign
    vector<int>v3;
    v3.assign(v1.begin()+1,v1.end()-1);
    printVector(v3);

    //n��elem��ʽ��ֵ
    vector<int>v4;
    v4.assign(10,50);
    printVector(v4);
}

//vector�����������ʹ�С����
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
        cout<<"v1Ϊ��"<<endl;
    }
    else
    {
        cout<<"v1��Ϊ��"<<endl;
        cout<<"v1������Ϊ:"<<v1.capacity()<<endl;
        cout<<"v1�Ĵ�СΪ:"<<v1.size()<<endl;
    }

    //����ָ����С
    v1.resize(15);
    printVector(v1);//Ĭ�ϻ���0���������λ�ã�Ҳ����ָ����ʲô�����
    v1.resize(20,50);
    printVector(v1);
    v1.resize(10);
    printVector(v1);
}

//vector�Ĳ����ɾ��
void test_9()
{
    vector<int> v1;
    for(int i=0;i<51;i+=10)
    {
        v1.push_back(i);
    }
    printVector(v1);
    //βɾ��
    v1.pop_back();
    printVector(v1);
    //����
    v1.insert(v1.begin(),100);
    printVector(v1);

    v1.insert(v1.begin(),3,1000);
    printVector(v1);
    //ɾ�� ���Ĳ���Ҳ�ǵ�����
    v1.erase(v1.begin());
    printVector(v1);
    //���
    v1.clear();
    //����v1.erase(v1.begin(),v1.end())
    printVector(v1);
}

//vector���������ݴ�ȡ
void test_10()
{
    vector<int> v1;
    for(int i=0;i<10;i+=1)
    {
        v1.push_back(i);
    }

    //����[]��ʽ����������Ԫ��
    for(int i=0;i<v1.size();i++)
    {
        cout<<v1[i]<<" ";
    }

    //����at��ʽ����Ԫ��
    for(int i=0;i<v1.size();i++)
    {
        cout<<v1.at(i)<<" ";
    }
    cout<<endl;
    //��ȡ��һ��Ԫ��
    cout<<"��һ��Ԫ��:"<<v1.front()<<endl;
    //��ȡ���һ��Ԫ��
    cout<<"���һ��Ԫ��Ϊ:"<<v1.back()<<endl;
}

//vector��������
//1.����ʹ��
void test_11()
{
    cout<<"����ǰ:"<<endl;
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
    cout<<"������:"<<endl;
    v1.swap(v2);
    printVector(v1);
    printVector(v2);
}
//2.ʵ����;
//����swap���������ڴ�ռ�
void test_12()
{
    vector<int>v;
    for(int i=0;i<100000;i++)
    {
        v.push_back(i);
    }
    cout<<"v������Ϊ:"<<v.capacity()<<endl;
    cout<<"v�Ĵ�СΪ:"<<v.size()<<endl;

    v.resize(3);
    cout<<"v������Ϊ:"<<v.capacity()<<endl;
    cout<<"v�Ĵ�СΪ:"<<v.size()<<endl;
    //������ĵĽ�����Կ���,resize�Ժ�v�������ǲ���ģ��൱�����ڴ����滹��ռ�˺ܴ�һ��ռ�
    //����û��ʹ�ã���ͻ�����˷�
    cout<<"-----------------------------";
    //����swap�����ڴ�
    vector<int>(v).swap(v);
    //vector<int>(v)����������ʵ���ϵ����˿������캯��
    //����v�Ĵ�С����ʼ������������˴�����������Ŀ������캯���Ժ�,��������3
    //�������ܹ���ʡ���ڴ�ռ�
    //�����ռ���ִ�к������ɾ��
    cout<<"v������Ϊ:"<<v.capacity()<<endl;
    cout<<"v�Ĵ�СΪ:"<<v.size()<<endl;
}

void test_13()
{
    vector<int>v;
    int num = 0;//ͳ�ƿ��ٵĴ���
    int *p = NULL;
    for(int i=0;i<100000;i++)
    {
        v.push_back(i);
        if (p!= &v[0])//����ͳ�ƿ����˶��ٴ��ڴ�
        {             //���p�ĵ�ַ�����ڵ�һ��Ԫ�صĵ�ַ
            p = &v[0];//��ô�Ͱ�pָ���һ��Ԫ��
            num += 1;
        }
    }
    cout<<"num = "<<num<<endl;
}

void test_14()
{
    vector<int>v;
    v.reserve(100000);
    int num = 0;//ͳ�ƿ��ٵĴ���
    int *p = NULL;
    for(int i=0;i<100000;i++)
    {
        v.push_back(i);
        if (p!= &v[0])//����ͳ�ƿ����˶��ٴ��ڴ�
        {             //���p�ĵ�ַ�����ڵ�һ��Ԫ�صĵ�ַ
            p = &v[0];//��ô�Ͱ�pָ���һ��Ԫ��
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
