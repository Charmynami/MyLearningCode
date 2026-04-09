//
// Created by wangy on 2026/4/9.
//
#include "../MyInclude/MyReference.h"
#include <iostream>
//引用：格式：数据类型 & 引用名 = 原名;
//引用就是一个别名。
//引用必须初始化，不能为空。初始化后，不能改变引用名。
using namespace std;
void myReference1() {
    //原名
    int a = 10;
    //引用名
    int &b = a;
    //b和a是同一个变量:
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    //通过b修改a的值
    cout << "through b to change a: " << endl;
    cin>>b;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
}

//引用参数：能够改变参数的值
void ReferenceText(int &a, int &b) {
    int c = a;
    a = b;
    b = c;
}
//引用可以作为函数的返回值：格式：数据类型 & 函数名()；
//千万不能返回局部变量
int& myReference2() {
    static int a = 10;//局部变量返回会报错，使用const可以使a变为静态变量
    return a;
}
//引用的本质是一个指针常量

//常量引用：格式：const 数据类型 & 引用名 = 原名;能够防止错误的操作
void myReference3() {
    //1.引用必须引用合法的空间；但是加上const可以引用任何空间
    int a = 10;
    //int &b = 10;//这是错误，因为10不是空间
    const int &b = 10;//加上 const后，编译器会将b声明为常量引用，此时b可以引用任何空间
    //此时相当于：int temp = 10;
    cout << "b = " << b << endl;
    //使用const更多的是为了防止错误操作，其实被修饰后相当于一个常量；
}
void showvalue(const int &a) {
    //a = 100;//这是错误，因为a是常量，不能被修改
    //如果没有const，a可以修改，这是不好的编程方式
    cout << "a = " << a << endl;
}