#include "headfile.h"

using namespace std;

// 创建一个空的学生数据结构体
student create_student()
{
    student s;
    return s;
}

// 创建一个学生信息
student create_student()
{
    student s;
    cout << "请输入学生姓名：";
    cin >> s.name;
    cout << "请输入学生学号：";
    cin >> s.number;
    cout << "请输入学生成绩：";
    cin >> s.score;
    cout << "请输入学生年龄：";
    cin >> s.age;
    cout << "请输入学生性别(0是女,1是男):";
    cin >> s.sex;
    cout << "请输入学生所在年级：";
    cin >> s.grade;
    cout << "请输入学生所在班级：";
    cin >> s.class_number;
    cout << "请输入学生所在班级的辅导员：";
    cin >> s.teacher;
    cout << "请输入学生所在寝室号码：";
    cin >> s.room_number;
    cout << "请输入学生对应的校园卡号码：";
    cin >> s.card_number;
    cout << "请输入学生的类型(0是本科生,1是研究生):";
    cin >> s.type;
    return s;
}

// 新建一个学生
void new_student(student *s)
{
    *s = create_student();
}


// 新建一个student_class类实例，用来存储所有学生的信息
student_class student_class_instance;


// 定义一个student类型的vector，用于存储学生信息。
vector<student> students;

// verctor插入一个学生信息
void insert_student(student s)
{
    students.push_back(s);
}

// 冒泡排序，按照学生的成绩从小到大排序
void bubble_sort()
{
    int n = students.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (students[j].score > students[j + 1].score)
            {
                swap(students[j], students[j + 1]);
            }
        }
    }
}

// 快速排序，按照学生的成绩从小到大排序
void quick_sort()
{
    int n = students.size();
    int i = 0;
    int j = n - 1;
    int pivot = students[n / 2].score;
    while (i <= j)
    {
        while (students[i].score < pivot)
        {
            i++;
        }
        while (students[j].score > pivot)
        {
            j--;
        }
        if (i <= j)
        {
            swap(students[i], students[j]);
            i++;
            j--;
        }
    }
    if (i < n / 2)
    {
        quick_sort(i, n - 1);
    }
    if (j > n / 2)
    {
        quick_sort(0, j);
    }
}

// 根据学生姓名,从students_map STL 容器中查找学生信息
student CStudent::find_student(string name)
{
    student s;
    for (auto it = students_map.begin(); it != students_map.end(); it++)
    {
        if (it->second.name == name)
        {
            s = it->second;
            break;
        }
    }
    return s;
}

// 根据学生成绩查找学生信息
student CStudent::find_student_by_score(int score)
{
    for (int i = 0; i < students.size(); i++)
    {
        if (students[i].score == score)
        {
            return students[i];
        }
    }
    student s;
    return s;
}

// 根据学生学号,从students_map STL 容器中查找学生信息
student CStudent::find_student_by_number(int number)
{
    student s;
    s = students_map[number]; // 从students_map STL 容器中查找学生信息
    return s;
}

// 根据学生学号，删除学生信息
void CStudent::delete_student_by_number(int number)
{
    students_map.erase(number);
}

// 随机生成一个学号，范围在10001到99999之间
// 生成完毕后读取vector中最后一个学号，对比刚生成的学号
// 如果二者相同则学号+1，再进行对比，直到二者不同为止，否则直接插入。
int CStudent::generate_number()
{
    int number = rand() % 9999 + 10001;
    for (int i = 0; i < students.size(); i++)
    {
        if (students[i].number == number)
        {
            number++;
            i = 0;
        }
    }
    return number;
}

// 学生map插入一个学生信息
void CStudent::insert_student_map(student s)
{
    student_map.insert(pair<int, student>(s.number, s));
}

// 根据提供的学生学号，修改一个学生的成绩
void CStudent::update_student_score(int number, int score)
{
    student_map[number].score = score;
}


