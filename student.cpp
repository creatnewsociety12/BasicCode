#include "headfile.h"

using namespace std;

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

// 操作students_map STL容器，将其插入某个students学生， key为学生学号，value为学生信息
void CStudent_class::insert_student(student s)
{
    students_map.insert(pair<int, student>(s.number, s));
}

// 对map类型的students_map容器，按照score成绩，把里面的每一个student，按照score成绩从小到大排序
void CStudent_class::sort_student()
{
    // 定义一个student类型的vector，用于存储学生信息。
    vector<student> students;

    // 定义一个map类型的iterator，用于遍历students_map容器
    map<int, student>::iterator it;

    // 遍历students_map容器，将每一个student信息插入到students容器中
    for (it = students_map.begin(); it != students_map.end(); it++)
    {
        students.push_back(it->second);
    }

    // 对students容器，按照score成绩，把里面的每一个student，按照score成绩从小到大排序
    sort(students.begin(), students.end(), compare_student);

    // 清空students_map容器
    students_map.clear();

    // 遍历students容器，将每一个student信息插入到students_map容器中
    for (int i = 0; i < students.size(); i++)
    {
        students_map.insert(pair<int, student>(students[i].number, students[i]));
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

// 根据学生姓名，修改一个学生的成绩
void CStudent::update_student_score(string name, int score)
{
    for (auto it = student_map.begin(); it != student_map.end(); it++)
    {
        if (it->second.name == name)
        {
            it->second.score = score;
            break;
        }
    }
}

// 根据给定分数，查找小于给定分数的学生信息，并返回一个vector
vector<student> CStudent::find_students_by_score(int score)
{
    vector<student> students_by_score;
    for (auto it = student_map.begin(); it != student_map.end(); it++)
    {
        if (it->second.score < score)
        {
            students_by_score.push_back(it->second);
        }
    }
    return students_by_score;
}







