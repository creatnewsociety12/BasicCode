// 消息类型定义头文件
// 所有服务端之间，客户端和服务端之间的消息传递功能类型定义，都在这里定义
// 整个系统大致分为3个部分，客户端以C开头，网关以G开头，内网服务端以S开头。其中客户端是用户所在任意网络，而G在公共IP地址，任何人都可以访问，而S是在服务器内网，专门
// 用来处理逻辑，不直接接受外网访问，只能和G进行数据沟通。

#define MESSAGE_OK       0  // 消息返回成功
#define MESSAGE_ERRO    -1  // 消息返回错误


#define C2GREJESTSTUDENT    1   // 注册一个学生信息，客户端发给网关服务端
#define C2GLOGIN            2   // 客户端发送登录请求


// 学生学籍，个人信息相关消息

// 学生每学期课程相关消息

// 学生宿舍相关消息

// 学生考试类相关消息

// 老师，学校职工个人信息相关消息

// 学校老师，职工，薪酬，职称，获奖相关消息

// 学校日常举办活动，举办会议，任务相关消息

// 学校设备，硬件网络远程控制相关消息

// 学校食堂相关消息

// 学校日常公告通知相关消息

// 学生，老师，职工内部聊天消息

// 校园一卡通相关消息



