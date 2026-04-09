#include "../MyInclude/Mystring.h"
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
//------------------------------------------------------------------------------------------------------------------
//基础的结构使用
void mystruct1() {
     //结构的初始化
    Student stu1 = {
        "wangy",
        "1234567890",
        21,
        100
    };
    Student stu2 = {};
    //结构之间可以赋值、比较、查找、替换、长度、查找、排序
    cout<<"stu1's struct:";
    cout<<stu1.name<<' '<<stu1.age<<' '<<stu1.idcard<<' '<<stu1.score<<endl;
    //赋值
    stu2 = stu1;
    cout<<"stu2's struct:";
    cout<<stu2.name<<' '<<stu2.age<<' '<<stu2.idcard<<' '<<stu2.score<<endl;
}
//------------------------------------------------------------------------------------------------------------------
//结构数组的使用
void mystruct2() {
    //直接定义并且初始化
    Student stu[3] = {
        {"wangy", "1234567890", 21, 100},
        {"yiyi", "1234567891", 20, 99},
        {"wayi", "1234567892", 19, 98}
    };
    //访问结构数组元素
    cout<<"stu[0]'s struct:";
    cout<<stu[0].name<<' '<<stu[0].age<<' '<<stu[0].idcard<<' '<<stu[0].score<<endl;
    cout<<"stu[1]'s struct:";
    cout<<stu[1].name<<' '<<stu[1].age<<' '<<stu[1].idcard<<' '<<stu[1].score<<endl;
    cout<<"stu[2]'s struct:";
    cout<<stu[2].name<<' '<<stu[2].age<<' '<<stu[2].idcard<<' '<<stu[2].score<<endl;
    //定义结构数组
    Student stu2[3];
    //输入结构数组元素
    for(int i = 0; i < 3; i++) {
        cout<<"Enter the "<<i+1<<"th struct:"<<endl;
        cin>>stu2[i].name>>stu2[i].age>>stu2[i].idcard>>stu2[i].score;
    }
    //输出结构数组元素
    for(int i = 0; i < 3; i++) {
        cout<<"stu2["<<i<<"]'s struct:";
        cout<<stu2[i].name<<' '<<stu2[i].age<<' '<<stu2[i].idcard<<' '<<stu2[i].score<<endl;
    }

}
