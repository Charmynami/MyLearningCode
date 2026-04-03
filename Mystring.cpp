#include "Mystring.h"
#include <iostream>
#include <cstring>
using namespace std;
//string类的使用
void mystring1() {
    char str1[50] = "hello,how are you?";
    string str2 ;
    cout<<"Enter a string:"<<endl;
    cin>>str2;
    cout<<"str1="<<str1<<endl;
    cout<<"str2="<<str2<<endl;
    //string类之间可以赋值、拼接、比较、查找、替换、大小、长度、查找、排序
    string str3 = str1;
    cout<<"str3="<<str3<<endl;
    //拼接：只需要用+号即可
    string str4 = str1 + str2;
    cout<<"str4="<<str4<<endl;
    //比较：只需要用==号即可
    if(str1 == str2)
        cout<<"str1 is equal to str2"<<endl;
    else
        cout<<"str1 is not equal to str2"<<endl;
    //还可以使用+=进行拼接
    str2 += str3;
    cout<<"str2+=str3\n"<<str2<<endl;
}
//------------------------------------------------------------------------------------------------------------------
void mystring2() {
    //cin只能输入一个单词，不能输入多个单词，以空格结束
    //输入多个单词，用getline()函数或者get();
    //获取长度：strlen()函数或者.size()方法或者length()方法
    char str1[50];
    string str2;
    char str3[50];
    char str4[50];
    char str5[50];
    //getline()函数会忽略掉输入的回车符，并且将回车符变成空格
    cout<<"Enter the first string:and the third string:\n";
    //对于使用字符数组定义的字符串，cin.getline()使用：限制长度；
    cin.getline(str1,50).getline(str3,50);
    //输入的字符串不能超过50个字符，最后一个字符必须为回车符转换为‘\0’
    cout<<"str1="<<str1<<endl;
    cout<<"str3="<<str3<<endl;
    cin.get();
    cout<<"Enter the fouth string:and the fifth string:\n";
    cin.get(str4,50).get(str5,50);//像这样拼接，可以避免输入的回车符被转换成空格导致错误
    cout<<"str4="<<str4<<endl;
    cout<<"str5="<<str5<<endl;
    //下面是使用cin.get()函数读取多余的换行符
    //cin.get(str4,50)；
    //cin.get();
    //cin.get(str5,50);
    cout<<"Enter the second string\n";
    cin.ignore();
    //对于string类，getline()使用：没有长度的限制
    getline(cin,str2);//两种方法的差异
    cout<<"str1="<<str1<<endl;
    cout<<"str2="<<str2<<endl;


}

