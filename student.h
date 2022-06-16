#include "headfile.h"
#include "basicstudent.h"

// 定义一个学生类
class CStudent
{   
public:
    // 构造函数，用来初始化学生数组
    CStudent()
    {
        
    }
    // 析构函数，用来释放学生数组
    ~CStudent()
    {
        
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

    // 生成一个学生，将其插入到students_map 的map结构中
    void insert_student_map(student s)
    {
        students_map.insert(std::pair<int, student>(s.number, s));
    }

    // 根据学生姓名查找学生信息
    student find_student_by_name(string name);


private:
    // 定义一个int类型的vector，用于存储学生的学号。
    vector<int> numbers;

    // 定义一个map，用于存储学生,其中key是学号，value是学生
    map<int, student> students_map;


};

