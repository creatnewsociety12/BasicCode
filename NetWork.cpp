#include <stdio.h>

#include "NetWork.h"

// 创建socket套接字
int create_socket()
{
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        perror("socket");
        exit(1);
    }
    return sockfd;
}

// 初始化socket套接字
void init_socket(int sockfd)
{
    int opt = 1;
    // 设置地址重用
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) < 0)
    {
        perror("setsockopt");
        exit(1);
    }
}

//绑定套接字
void bind_socket(int sockfd, int port)
{
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    if (bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0)
    {
        perror("bind");
        exit(1);
    }
}

//监听套接字
void listen_socket(int sockfd)
{
    if (listen(sockfd, 10) < 0)
    {
        perror("listen");
        exit(1);
    }
}

//接收客户端连接
int accept_socket(int sockfd)
{
    struct sockaddr_in client_addr;
    socklen_t len = sizeof(client_addr);
    int client_sockfd = accept(sockfd, (struct sockaddr *)&client_addr, &len);
    if (client_sockfd < 0)
    {
        perror("accept");
        exit(1);
    }
    return client_sockfd;
}

//发送数据
void send_data(int sockfd, char *buf, int len)
{
    if (send(sockfd, buf, len, 0) < 0)
    {
        perror("send");
        exit(1);
    }
}

// 创建TCP连接
int create_tcp_connect(char *ip, int port)
{
    int sockfd = create_socket();
    init_socket(sockfd);
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = inet_addr(ip);
    if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0)
    {
        perror("connect");
        exit(1);
    }
    return sockfd;
}

// 关闭TCP连接
void close_tcp_connect(int sockfd)
{
    close(sockfd);
}

// 创建TCP连接队列
int create_tcp_listen(int port)
{
    int sockfd = create_socket();
    init_socket(sockfd);
    bind_socket(sockfd, port);
    listen_socket(sockfd);
    return sockfd;
}

// 创建一个tcp_thread_pool函数
void *tcp_thread_pool(void *arg)
{
    int sockfd = *(int *)arg;
    char buf[1024];
    while (1)
    {
        memset(buf, 0, sizeof(buf));
        int len = recv(sockfd, buf, sizeof(buf), 0);
        if (len < 0)
        {
            perror("recv");
            exit(1);
        }
        else if (len == 0)
        {
            printf("client close\n");
            break;
        }
        else
        {
            printf("recv: %s\n", buf);
            send_data(sockfd, buf, len);
        }
    }
    close_tcp_connect(sockfd);
}

// 创建TCP连接线程池
void create_tcp_thread_pool(int sockfd, int thread_num)
{
    pthread_t *pthid = (pthread_t *)malloc(sizeof(pthread_t) * thread_num);
    for (int i = 0; i < thread_num; i++)
    {
        pthread_create(&pthid[i], NULL, tcp_thread_pool, (void *)&sockfd);
    }
}

//定义一个消息队列节点msg_queue_t
typedef struct msg_queue_t
{
    int sockfd;
    struct msg_queue_t *next;
} msg_queue_t;

//初始化一个消息队列
void init_msg_queue(msg_queue_t *msg_queue)
{
    msg_queue->head = msg_queue->tail = NULL;
    pthread_mutex_init(&msg_queue->mutex, NULL);
    pthread_cond_init(&msg_queue->cond, NULL);
}

//创建一个消息队列
int create_msg_queue()
{
    int msgid = msgget(IPC_PRIVATE, IPC_CREAT | 0666);
    if (msgid < 0)
    {
        perror("msgget");
        exit(1);
    }
    return msgid;
}

// 监听一个消息队列
int listen_msg_queue(int msgid)
{
    struct msqid_ds buf;
    if (msgctl(msgid, IPC_STAT, &buf) < 0)
    {
        perror("msgctl");
        exit(1);
    }
    printf("msgid: %d\n", msgid);
    printf("msg_perm.uid: %d\n", buf.msg_perm.uid);
    printf("msg_perm.gid: %d\n", buf.msg_perm.gid);
    printf("msg_perm.cuid: %d\n", buf.msg_perm.cuid);
    printf("msg_perm.cgid: %d\n", buf.msg_perm.cgid);
    printf("msg_perm.mode: %o\n", buf.msg_perm.mode);
    printf("msg_qbytes: %d\n", buf.msg_qbytes);
    printf("msg_ctime: %ld\n", buf.msg_ctime);
    printf("msg_stime: %ld\n", buf.msg_stime);
    printf("msg_rtime: %ld\n", buf.msg_rtime);
    printf("msg_lspid: %d\n", buf.msg_lspid);
    printf("msg_lrpid: %d\n", buf.msg_lrpid);
    return msgid;
}

//创建UDP连接
int create_udp_connect(char *ip, int port)
{
    int sockfd = create_socket();
    init_socket(sockfd);
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = inet_addr(ip);
    if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0)
    {
        perror("connect");
        exit(1);
    }
    return sockfd;
}

//关闭UDP连接
void close_udp_connect(int sockfd)
{
    close(sockfd);
}

//创建UDP监听队列
int create_udp_listen(int port)
{
    int sockfd = create_socket();
    init_socket(sockfd);
    bind_socket(sockfd, port);
    return sockfd;
}


