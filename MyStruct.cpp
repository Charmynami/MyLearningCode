#include "Mystring.h"
#include <iostream>
using namespace std;
//结构的定义
//写一个学生的结构
struct Student {
    char name[20];
    //string类也可以作为成员变量
    string idcard;
    int age;
    float score;
    //   friend ostream &operator<<(ostream &in, Student &stu) {
    //     in<<stu.name<< ' ' <<stu.age<<stu.score;
    //     return in;
    // }
};

void mystruct1() {
     //结构的初始化
    Student stu1 = {
        "wangy",
        "1234567890",
        21,
        100
    };
    Student stu2 = {
        "yiyi",
        "1234567890",
        20,
        90
    };
    cout<<stu1.name<<' '<<stu1.age<<' '<<stu1.idcard<<' '<<stu1.score<<endl;

    cout<<
}
