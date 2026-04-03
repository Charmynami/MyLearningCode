#include "Union_And_Enum.h"
#include <iostream>
using namespace std;
//联合的使用：你能够定义多种数据类型，但是这个结构只能存储一种数据。
union MyUnion {
    int a;
    char b;
};
//结构配合联合的使用：
struct MyStruct {
    int c;
    char d;
    union id_num {
        char youid[10];
        int   num;
    }id_num1;
};
//枚举的定义：定义了week
enum week {
    Monday=1,//可以自定义枚举变量的初始值，后面的变量会自动递增。
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday,
    Sunday
};
//------------------------------------------------------------------------------------------------------------------
void myunion1() {
    union MyUnion mU = {10};
    cout << mU.a << endl;
    union MyUnion mU2 = {'A'};
    cout << mU2.b << endl;
    //输入输出
    cout << "Enter a number:" << endl;
    cin >> mU.a;
    cout << "Enter a character:" << endl;
    cin >> mU2.b;
    cout << "int a=" << mU.a << endl;
    cout << "char b=" << mU2.b << endl;
    //通过输入输出可以改变联合变量的值
}
//------------------------------------------------------------------------------------------------------------------
//联合常常和结构一起使用，匿名联合变量不能单独使用。
void myunion2() {
    MyStruct mS ;
    cout<<"Enter a number:"<<endl;
    cin >> mS.c;
    cout<<"Enter a character:"<<endl;
    cin >> mS.d;
    cout<<"Enter a id:"<<endl;
    cin >> mS.id_num1.num;
    cout<<mS.c<<' '<<mS.d<<' '<<mS.id_num1.youid<<endl;
}
//------------------------------------------------------------------------------------------------------------------
//匿名的联合变量不能单独使用，只能作为结构变量的成员变量
void myunion3() {
    struct text {
        int txt;
        union {
            char name[20];
            int age;
        };
    };
    text t1;
    cout<<"Enter a number:"<<endl;
    cin >> t1.txt;
    if (t1.txt >0) {
        cout<<"Enter a name:"<<endl;
        cin >> t1.name;
    }else{
        cout<<"Enter a age:"<<endl;
        cin >> t1.age;
    }
    //如果t1.txt>0，则输入的是name，此时age无效，但是由于name和age是匿名联合变量，所以它们的地址是相同的，所以age的值也会改变
    //打印的时候，age的值是不确定的。
    cout<<"txt="<<t1.txt<<" name="<<t1.name<<" age="<<t1.age<<endl;
}

//枚举的使用：枚举是一种用户自定义的数据类型，它允许你定义一组命名的整数常量。
//枚举变量的值从0开始递增，你可以指定枚举变量的值。
//比如：设置一周的星期数，从1开始，那么Monday=1，Tuesday=2，Wednesday=3，Thursday=4，Friday=5，Saturday=6，Sunday=7。
//枚举常量的值不能改变，但是你可以改变枚举变量的值。
//------------------------------------------------------------------------------------------------------------------
void myenum1() {
    week w;
    w = Monday;//枚举变量可以赋值，但是赋值必须为枚举变量的成员。
    cout << "w=" << w << endl;
    //w= 2;这就是违法的示例，即使2对应着星期二，但是枚举变量只能赋值给枚举变量的成员。
    int i ;
    //由于枚举是整型，所以可以赋值给整型变量。枚举类型可以提升为整型，但是int类型不能提升为枚举类型。
    i= Monday;
    cout << "i=w:" << i << endl;
    //还可以进行运算
    i= Monday+1;
    cout << "i=Monday+1=" << i << endl;
    //枚举也是有范围的，比如：week这个枚举变量，它的范围是1-7，如果赋值超出这个范围，那么就会得到一个错误。
    //i= week(8);这是一个错误示例，同时也告诉我们，可以有这样的赋值方式：int i= week(1);
}
//枚举更多的是配合switch使用，后面学习。