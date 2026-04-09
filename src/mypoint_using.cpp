#include "../MyInclude/mypoint_using.h"
#include <vector>
#include <cstring>
#include <iostream>
using namespace std;

//指针：指针是一个变量，它的值保存的是一个地址。指针变量必须声明为指针类型，指针类型由一个*号和数据类型组成。指针变量可以保存任意类型的地址。
//------------------------------------------------------------------------------------------------------------------
//指针的基础使用；使用&运算符获取变量的地址，可以赋值给指针变量。
void mypoint_array1() {
    int a = 10;
    int* p = &a;//&a获取a的地址，赋值给p      //C++11以后，&a也可以写成a.operator&()
    //C++程序员习惯这样定义指针变量：int* p;让int和*想靠近来强调这是一个指针变量。
    cout << "a=" << a << " a address=" << &a;
    //*p获取p指向的地址的值，而p就是a的
    cout << " p=" << *p << " p address=" << p << endl;
    //同样，我们可以使用指针来改变a的值。
    *p = 20;
    cout << "a=" << a << " a address=" << &a;
    cout << " p=" << *p << " p address=" << p << endl;
    //注意，如果指针没有初始化，那么它的值就是0。是一个野指针。
    //这很危险，因为指针变量p指向的未知内存空间，它的值可能被其他程序改变，导致程序错误。
    //所有创建指针时，必须初始化，如果没有初始化，请赋值为NUll；
    int* p2= NULL;//这样就可以创建一个空指针变量，防止指针变量p指向的未知内存空间。
}
//------------------------------------------------------------------------------------------------------------------
//使用new和delete创建指针变量：格式：int* p = new int;
void mypoint_array2() {
    int* p = new int;//创建一个int类型的指针变量p，并分配一个int类型的内存空间，并把指针变量p指向这个内存空间。
    //*p获取p指向的int类型的内存空间中的值，而p就是int类型的内存空间。
    //但是不能像mypoint_array1()使用确定的变量访问内存空间，因为指针变量p指向的内存空间是动态分配的，它的地址是未知的。
    *p = 10;//可以正常赋值
    cout << "p=" << *p << " p address=" << p << endl;
    //释放内存空间
    delete p;
    //使用new创建的指针变量，必须使用delete释放内存空间。一定要释放内存空间，否则会造成内存泄漏。
    int *p2 = new int;
    int *p3 = p2;//p3和p2指向同一个内存空间，可以像这样赋值。
    //也就是可以创建多个指针变量，指向同一个内存空间，这样可以节省内存空间。
    //两者可以相互赋值，改变同一个内存空间中的值。
    *p2 = 20;
    cout << "p2=" << *p2 << " p2 address=" << p2 << endl;
    *p3 = 30;//这样就改变了p2中的值
    cout << "p3=" << *p3 << " p3 address=" << p3 << endl;
    cout << "p2=" <<*p2  << " p2 address=" << p2 << endl;
    //释放内存空间
    delete p2;//千万要注意，一定要释放内存空间，否则会造成内存泄漏。
    //定义p3指针不用释放内存空间，因为p3和p2指向同一个内存空间，所以p2释放内存空间，那么p3也会释放内存空间。
    //注意，p3和p2是同一个内存空间，所以p3和p2不能同时释放内存空间，否则会造成内存泄漏。
    //也不要释放同一个内存空间多次，否则会造成难以描述的错误。
}
//------------------------------------------------------------------------------------------------------------------
//动态数组：动态数组是指在运行时根据需要分配内存空间。动态数组的声明格式：int* p = new int[10];
//数组和指针一样，可以访问数组中的元素。它们的操作基本一样。数组名可以看作是一个指向数组第一个元素的指针。所以数组名可以代替指针变量。
void mypoint_array3() {
    int* p = new int[10];
    //接下来可以赋值
    for (int i = 0; i < 10; i++) {
        p[i] = i;
    }
    //也可以像这样赋值
    for (int i = 0; i < 10; i++) {
        *(p + i) = i;//由于*运算符的优先级低于+运算符，所以必须加括号，否则会先计算p+i，然后取p+i的值，这样就错了。
        //*p+i=i;这样是错误示例，因为*p是取p指向的int类型的内存空间中的值，然后+i，这样会得到一个int类型的值，而不是一个指针变量。
    }
    //综合来说，尽量使用p[i] = i这样的赋值方式，而不是*(p + i) = i，更加简洁。
    //输出数组中的元素
    for (int i = 0; i < 10; i++) {
        cout << "p[" << i << "]=" << p[i] << " p address=" << p << endl;
    }
    //还有这样的性质：p默认为首元素即p[0]，p+i表示第i个元素，所有p=p+1表示p指向下一个元素，p-1表示p指向前一个元素。
    cout << "p=" << *p << " p address=" << p << endl;
    p=p+1;//现在p指向下一个元素；即p[1]；
    cout << "p=p+1 = " << *p << " p address=" << p << endl;
    //释放内存空间，与mypoint_array2()一样，只要使用new关键字创建的指针变量，必须使用delete关键字释放内存空间。
    delete[] p;
}
//------------------------------------------------------------------------------------------------------------------
//虽然数组名会被解释为首元素的地址，但是对数组名使用&运算符，会得到整个数组的地址。
void mypoint_array4() {
    int a[10]={1,2,3,4,5,6,7,8,9,10};
    cout << "a=" << a << "a[0] address"<< &a[0] << endl;
    cout << " a address=" << &a << endl;
    //数组的一些操作：1.sizeof(a)获取数组a的大小，2.sizeof(a[0])获取数组a中元素的大小，3.sizeof(a)/sizeof(a[0])获取数组a的长度。
    cout << "sizeof(a)=" << sizeof(a) << " sizeof(a[0])="
    << sizeof(a[0]) << " sizeof(a)/sizeof(a[0])=" << sizeof(a)/sizeof(a[0]) << endl;
    //.length()获取数组a的长度，但是这个方法只适用于C++11以上版本。
 }
//------------------------------------------------------------------------------------------------------------------
//指针和字符串
void point_string1() {
    //之前提到，字符串相当于一个字符数组，字符串的声明格式：char* p = "hello world";
    //所有可以使用指针访问字符串中的元素。
    char flower[10]="rose";
    cout << "flower=" << flower << endl;
    //为什么通过 flower就可以打印出字符串呢？因为字符串是一个字符数组，字符串名被解释为字符串第一个元素的地址。
    //其实，如果给cout提供一个字符的地址，那么cout从这个地址开始打印，直到遇到'\0'结束。
    cout << "flower=" << (int *)flower << endl;//这里的(int *)flower是把flower转换成int*类型，然后打印出来。
    //可以打印出字符串中的地址
    //接下来展示一下字符串的基本操作：
    //1.strlen(p)获取字符串的长度，2.strcpy(p,q)将q中的字符串复制给p，
    //3.strcat(p,q)将q中的字符串追加给p，4.strcmp(p,q)比较p和q中的字符串，5.strchr(p,c)在p中查找c，6.strstr(p,q)在p中查找q
    //通过指针获取字符串的副本
    char *p=new char[strlen(flower)+1];//strlen(flower)获取字符串的长度，+1是因为字符串中的'\0'占一个字节。
    strcpy(p, flower);//strcpy(p, flower)将flower中的字符串复制给p。
    strcat(p, " is beautiful");//strcat(p, " is beautiful")将" is beautiful"追加给p。
    strcmp(p, flower);//strcmp(p, flower)比较p和flower中的字符串
    //返回0表示相等，返回1表示p大于flower，返回-1表示p小于flower。
    //这些函数都是C语言中的字符串函数，C++中字符串函数很多，但是C++中字符串函数的声明格式和C语言中的字符串函数声明格式一样。
    //不过，C++中的String类型处理起来更方便，String类型是一个类，String类型对象可以像字符串一样访问元素。
    cout << "p=" << p << endl;
}
//------------------------------------------------------------------------------------------------------------------
//指针、结构体、new
void mypoint_struct1() {
    //学生类的结构体创建
    struct Student {
        char name[10];
        int age;
    };
    Student s1 = { "zhangsan", 18 };//创建结构体变量s1，并初始化
    Student* p = new Student; //创建结构体指针p，并分配内存空间
    p = &s1; //p指向s1
    //使用指针访问结构体成员：专属的运算符->：p->name表示p指向的Student结构体的name成员，p->age表示p指向的Student结构体的age成员。
    cout << "p->name=" << p->name << " p->age=" << p->age << endl;
    //访问结构体成员：普通运算符.：p.name表示p指向的Student结构体的name成员，p.age表示p指向的Student结构体的age成员。
    cout << "s1.name=" << s1.name << " s1.age=" << s1.age << endl;
    //输入：cin>>p->name>>p->age; //输入结构体成员
    cout<<"Use p->X :Enter the name and age of the student："<<endl;
    cin>>p->name>>p->age;
    cout<<"p->name=" << p->name << " p->age=" << p->age << endl;
    cout<<"Use s1.X :Enter the name and age of the student："<<endl;
    cin>>s1.name>>s1.age;
    cout<<"s1.name=" << s1.name << " s1.age=" << s1.age << endl;
    //使用cin.get(p->name,10)获取字符串
    cout<<"Use cin.get(p->name,10) :Enter the name of the student："<<endl;
    cin.get(p->name,10);
    cout<<"p->name=" << p->name << endl;
}
//------------------------------------------------------------------------------------------------------------------
//以下是C++PrimerPlus的示例代码：一个使用new和delete的例子：可以节省内存空间。
void mypoint_delete() {
    char* getname(void);
    char* name;
    name = getname();
    cout << name << " at " << (int *)name << endl;
    delete[] name;
}
char* getname(void) {
    char temp[80];//临时变量
    cout << "Enter last name: ";
    cin >> temp;
    char* pn = new char[strlen(temp) + 1];//strlen(temp)获取字符串的长度，+1是因为字符串中的'\0'占一个字节。
    strcpy(pn, temp);//strcpy(pn, temp)将temp中的字符串复制给pn。
    return pn;//返回字符串的副本
}
//------------------------------------------------------------------------------------------------------------------
//数组、结构、指针的混合使用
void mix_point_array_struct() {
    struct Student {
        char name[10];
        int age;
    };
    // struct Student {
    //     char name[10];
    //     int age;
    // }s1，s2,s3;//可以这样创建结构变量
    //创建结构变量s1，并初始化//也可以Student s1 ，s2 ，s3;这样创建结构变量
    Student s1 = { "zhangsan", 18 };
    cout << "s1.name=" << s1.name << " s1.age=" << s1.age << endl;

    //结构指针：创建结构指针p，并分配内存空间
    Student* p = new Student[3];
    //使用指针访问结构成员；
    p = &s1; //p指向s1
    //使用指针访问结构成员改变结构成员
    cout << "Use p->age change age:" << endl;
    cin>>p->age;
    cout << "s1.age=" << s1.age << endl;

    //结构数组：创建结构数组stu，并初始化
    Student stu[3] = { "zhangsan", 18, "lisi", 19, "wangwu", 20 };
    //结构数组就是一个数组，所以可以像普通数组一样访问元素。
    for (int i = 0; i < 3; ++i) {
        cout << "stu[" << i << "].name=" << stu[i].name << " stu[" << i << "].age=" << stu[i].age << endl;
    }
    cout << "Use stu. age to change stu:" << endl;
    for (int i = 0; i < 3; ++i) {
        cout<<"stu["<<i<<"].age=";
        cin>>stu[i].age;
        cout<<endl;
    }

    //指针数组：创建指针数组p1，并分配内存空间
    Student* p1[3];
    //指针数组是一个数组，每个元素都是一个指针，可以指向一个结构变量。
    p1[0]=&s1;//p1[0]指向s1
    p1[1]=&stu[1];//p1[1]指向stu[1]
    p1[2]=&stu[2];//p1[2]指向stu[2]
    //这样就可以访问结构变量了
    //修改结构变量
    cout << "Use p1[0]->age change age:" << endl;
    cin>>p1[0]->age;
    cout << "s1.age=" << s1.age << endl;

    //还可以创建指向指针数组的指针
    Student** p2;
    p2=p1;
    cout << "Use p2 to access p1:" << endl;
    cout << "p2[0]->name=" << p2[0]->name << " p2[0]->age=" << p2[0]->age << endl;

    //关于**的用法，可以理解为指向指针的指针，即**p2表示p2是一个指向指针的指针。
    //用法：
    //*（*（p2+i）+x)表示p2[i][x]：p2[i]表示p2[i]是一个指针，*（p2+i）表示p2[i]的值是一个指针，*（*（p2+i）+x）表示p2[i][x]。
    //此时p2指向p1,那么*（*（p2+i）+x）表示p1[i][x]。
}
//------------------------------------------------------------------------------------------------------------------
//v__cpp_lib_constexpr_vector,模块类vector
void my_vector_using() {
    //vector类是使用new创建动态数组的替代品：需要包含<vector>头文件
    vector<int> v; //创建一个vector对象v，v是一个动态数组，可以存放int类型的数据
    int i;
    cin >> i;
    vector<double> d(i);//创建一个vector对象d，d是一个动态数组，可以存放double类型数据，大小为i
    //这样可以动态的创建数组，不需要提前定义数组的大小。
}



//const修饰指针的三种情况
//1.const修饰指针：const int *p;//p是一个指向int的常量指针，p可以指向任意int类型的变量，但是不能修改p指向的变量的值。
//2.const修饰指针指向的变量：int * const p=&a;//p是一个指向a的指针，p不能指向其他的int 变量的地址，但是p可以修改p指向的变量的值。
//3.const修饰指针指向的变量和指针本身：const int * const p;//p是一个指向int的常量指针，p不能修改p的指向，p可以指向任意int类型的变量，但是不能修改p指向的变量的值。
void mypoint_const1() {
    //1.const修饰指针：指向可变，指向的变量的值不可变
    const int *p;
    int a = 10;
    p = &a;
    cout << "a=" << a << endl;
    cout << "*p=" << *p << endl;
    //*p = 20; //错误，不能修改p指向的变量的值

    cout << "change p to point b"<<endl;//修改p指向的变量
    int b = 20;
    p = &b;
    cout << "b=" << b << endl;
    cout << "*p=" << *p << endl;
    //2.const修饰指针指向的变量：指向不可变，指向的变量的值可变
    int c = 30;
    int * const p1 = &c;
    cout << "c=" << c << endl;
    cout << "*p1=" << *p1 << endl;
    cout<<"change p1 's value"<<endl;
    *p1=33;
    cout << "c=" << c << endl;
    //3.const修饰指针指向的变量和指针本身：指向不可变，指向的变量的值不可变，指针本身不可变
    const int * const p2 = &a;
    cout << "a=" << a << endl;
    cout << "*p2=" << *p2 << endl;
}
