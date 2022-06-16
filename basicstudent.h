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
    // 学生本学期是否已经缴费，0是未缴费，1是已经缴费
    int is_pay;
    // 学生本学期是否已经通过考试，0是未通过，1是已经通过
    int is_pass;
    // 学生是否存在历史未缴费记录，0是不存在，1是存在
    int is_history_pay;
    // 学生是否存在历史未通过考试记录，0是不存在，1是存在
    int is_history_pass;
    // 学生是否已经毕业，0是未毕业，1是已经毕业
    int is_graduate;
    // 学生是否已经退学，0是未退学，1是已经退学
    int is_quit;
    // 学生是否已经被删除，0是未被删除，1是已经被删除
    int is_delete;
    // 学生是否已经被禁用，0是未被禁用，1是已经被禁用
    int is_disable;
    // 学生是否已经被挂失，0是未被挂失，1是已经被挂失
    int is_loss;
    // 学生是否已经被锁定，0是未被锁定，1是已经被锁定
    int is_lock;
    // 学生是否已经被拉黑，0是未被拉黑，1是已经被拉黑
    int is_black;
    // 学生是否已经被激活，0是未被激活，1是已经被激活
    int is_active;
    // 学生是否已经被登记，0是未被登记，1是已经被登记
    int is_register;
    // 学生是否已经被绑定，0是未被绑定，1是已经被绑定
    int is_bind;
    // 学生是否已经被解绑，0是未被解绑，1是已经被解绑
    int is_unbind;
    // 本学期公共选修课名称
    string public_course_name;
    // 学生校园卡是否已经被挂失，0是未被挂失，1是已经被挂失
    int is_card_loss;
    // 学生校园卡是否已经被锁定，0是未被锁定，1是已经被锁定
    int is_card_lock;
    // 学生校园卡是否已经被拉黑，0是未被拉黑，1是已经被拉黑
    int is_card_black;
    // 学生校园卡是否已经被激活，0是未被激活，1是已经被激活
    int is_card_active;
    // 学生校园卡是否已经被登记，0是未被登记，1是已经被登记
    int is_card_register;
    // 学生校园卡是否已经被绑定，0是未被绑定，1是已经被绑定
    int is_card_bind;
    // 学生校园卡是否已经被解绑，0是未被解绑，1是已经被解绑
    int is_card_unbind;
    // 学生校园卡余额
    int card_balance;



};

// 定义一个奖学金结构体
struct Scholarship
{
    // 奖学金编号
    int scholarship_id;
    // 奖学金名称
    string scholarship_name;
    // 奖学金类型，0是学生奖学金，1是教师奖学金
    int scholarship_type;
    // 奖学金金额
    int scholarship_amount;
    // 奖学金是否已经发放，0是未发放，1是已经发放
    int is_grant;
    // 奖学金是否已经被删除，0是未被删除，1是已经被删除
    int is_delete;
    // 奖学金是否已经被禁用，0是未被禁用，1是已经被禁用
    int is_disable;
    // 奖学金是否已经被挂失，0是未被挂失，1是已经被挂失
    int is_loss;
    // 奖学金是否已经被锁定，0是未被锁定，1是已经被锁定
    int is_lock;
};

// 定义一个学生本学期课程结构体
struct StudentCourse
{
    // 学生本学期课程编号
    int student_course_id;
    // 学生编号
    int student_id;
    // 课程编号
    int course_id;
    // 课程名称
    string course_name;
    // 课程类型，0是公共课，1是专业课
    int course_type;
    // 课程学分
    int course_credit;
    // 课程学时
    int course_hour;
    // 课程是否已经被删除，0是未被删除，1是已经被删除
};

// 定义一个员工结构体
struct Employee
{
    // 员工编号
    int employee_id;
    // 员工姓名
    string employee_name;
    // 员工性别，0是男，1是女
    int employee_
    // 员工职位，0是教师，1是管理员
    int employee_position;
    // 员工职称，0是讲师，1是副教授，2是教授
    int employee_title;
    // 员工月薪
    int employee_salary;
    // 员工是否已经被删除，0是未被删除，1是已经被删除
    int is_delete;
    // 员工是否已经被禁用，0是未被禁用，1是已经被禁用
    int is_disable;
    // 员工是否离职，0是未离职，1是已经离职
    int is_leave;
    // 员工是否已经被锁定，0是未被锁定，1是已经被锁定
    int is_lock;
    // 员工年假天数
    int annual_leave;
    // 员工调休天数
    int rest_leave;
    // 员工病假天数
    int sick_leave;
    // 员工事假天数
    int affair_leave;
    // 员工其他假天数
    int other_leave;
    
};


// 定义一个学生食堂就餐结构体
struct StudentDining
{
    // 学生食堂就餐编号
    int student_dining_id;
    // 学生编号
    int student_id;
    // 食堂编号
    int dining_id;
    // 食堂名称
    string dining_name;
    // 食堂负责人姓名
    string dining_principal_name;
    // 食堂负责人联系方式
    string dining_principal_phone;
    // 食堂负责人职位
    string dining_principal_position;
    // 食堂负责人职称
    string dining_principal_title;
    // 食堂负责人是否已经被删除，0是未被删除，1是已经被删除
    int is_delete;
    // 该食堂现有员工数量
    int dining_employee_count;
    // 该食堂现有每个员工信息，存储在一个vector中
    vector<Employee> dining_employee_list;



