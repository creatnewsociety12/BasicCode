#include <stdio.h>

#include "SQLServer.h"

//初始化MySQL连接
void init_mysql(MYSQL *mysql)
{
    mysql_init(mysql);
    if (mysql_real_connect(mysql, "localhost", "root", "123456", "test", 0, NULL, 0) == NULL)
    {
        printf("Error connecting to database:%s\n", mysql_error(mysql));
        exit(1);
    }
}

//连接MySQL数据库
MYSQL *connect_mysql()
{
    MYSQL *conn;
    conn = mysql_init(NULL);
    if (!mysql_real_connect(conn, "localhost", "root", "123456", "test", 0, NULL, 0))
    {
        printf("Error connecting to database:%s\n", mysql_error(conn));
        return NULL;
    }
    return conn;
}

//打开MySQL数据库
void open_mysql(MYSQL *conn)
{
    if (mysql_query(conn, "use test"))
    {
        printf("Error making query:%s\n", mysql_error(conn));
        return;
    }
}

//关闭MySQL数据库
void close_mysql(MYSQL *conn)
{
    mysql_close(conn);
}

//选择MySQL数据库
void select_mysql(MYSQL *conn, char *db)
{
    if (mysql_query(conn, db))
    {
        printf("Error making query:%s\n", mysql_error(conn));
        return;
    }
}

//导出MySQL数据库
void export_mysql(MYSQL *conn, char *db)
{
    if (mysql_query(conn, db))
    {
        printf("Error making query:%s\n", mysql_error(conn));
        return;
    }
}



