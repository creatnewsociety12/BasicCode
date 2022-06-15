#include "headfile.h"

// 定义一个寝室结构体，包含寝室的号码，寝室的床位数，寝室的床位号
struct Dormitory
{
    int number;
    int bed_num;
    int bed_num_used;
    int bed_num_unused;
    int *bed_num_list;
};

// 定义一个map, 用来存储学生的学号和寝室号
map<int, int> number_dormitory;



