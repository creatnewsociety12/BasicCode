#include "dormitory.h"

// 定义一个寝室结构体，包含寝室的号码，寝室的床位数，寝室的床位号
struct Dormitory
{
    int number;
    int bed_num;
    int bed_num_used;
    int bed_num_unused;
    // 宿舍现在是否有人居住
    bool is_used;
    // 宿舍类型，1表示4人间，2表示6人间，3表示8人间，4表示单人宿舍
    int type;
    // 宿舍面积
    int area;
    // 宿舍的楼层
    int floor;
    // 宿舍的楼号
    int building_number;
    // 宿舍的楼名
    char building_name[20];
    // 宿舍的地址
    char address[20];
    // 宿舍的管理员
    char manager[20];
    // 宿舍的管理员电话
    char manager_phone[20];
    // 宿舍的管理员QQ
    char manager_qq[20];
    // 宿舍的管理员邮箱
    char manager_email[20];
    // 宿舍的管理员微信
    char manager_wechat[20];
    // 宿舍的管理员微博
    char manager_weibo[20];
    // 宿舍能够居住的人员类型 1表示学生，2表示教师，3表示管理员，4表示其他
    int people_type;


    int *bed_num_list;
};

// 定义一个map, 用来存储学生的学号和寝室号
map<int, int> number_dormitory;



