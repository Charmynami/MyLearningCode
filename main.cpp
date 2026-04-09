#include <iostream>

#include "MyInclude/MyReference.h"
using namespace std;
int main() {
    // int a = 10;
    // int b = 20;
    // //通过引用可以达到和传地址一样的效果，并且更清晰
    // ReferenceText(a,b);
    // cout << "a = " << a << " b = " << b << endl;
    int& ref =myReference2();//因为a作为函数的返回值，所以现在的ref相当于a的别名；
    cout << "ref = " << ref << endl;
    //如果函数的返回值是一个引用，这个函数的调用可以作为左值；
    myReference2() = 100;//相当于a = 100;
    cout << "ref = " << ref << endl;
    int a=10;
    showvalue(a);
    return 0;
}
