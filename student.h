#include "headfile.h"

// 定义一个学生数据结构体，包含学生的姓名、学号、成绩和年龄。
struct student
{
    char name[20];
    int number;
    int score;
    int age;
    // 学生性别，0是女，1是男
    int sex;
    // 学生当前所在年级
    int grade;
    // 学生当前所在班级
    int class_number;
    // 学生当前所在班级的辅导员
    char teacher[20];
    // 对应的心理辅导员
    char counselor[20];
    // 所在寝室号码
    char room_number[20];
    // 对应校园卡号码
    char card_number[20];
    // 对应的学生类型，0是本科生，1是研究生
    int type;
    // 对应的学生所在学院类型
    int college_type;
    // 学生所学专业
    char major[20];
    // 学生所在学院
    char college[20];
    // 学生所在学校
    char school[20];
    // 学生所在学校的地址
    char address[20];
    // 学生所在学校的电话号码
    char phone_number[20];
    // 学生所在学校的邮箱
    char email[20];
    // 学生所在学校的网址
    char website[20];
    // 紧急联系人姓名
    char emergency_name[20];
    // 紧急联系人电话号码
    char emergency_phone_number[20];


};

// 定义一个学生类
class student_class
{   
    // 定义一个学生数组，用来存储所有学生的数据
    student *students;
public:
    // 构造函数，用来初始化学生数组
    student_class()
    {
        students = new student[100];
    }
    // 析构函数，用来释放学生数组
    ~student_class()
    {
        delete[] students;
    }

public:
    // 创建一个空的学生数据，用来插入新的学生数据
    student create_student()
    {
        student s;
        return s;
    }
    // 插入一个学生数据
    void insert_student(student s)
    {
        students[0] = s;
    }

private:
    // 定义一个int类型的vector，用于存储学生的学号。
    vector<int> numbers;

    

};

