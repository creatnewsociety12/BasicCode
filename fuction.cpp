#include <stdio.h>

#include "function.h"

// 定义一个单链表，Node节点数据结构体
struct Node
{
    int data;
    Node *next;
};

// 创建一个单链表的Node节点，new一个新节点失败，要打印报错信息
Node *createNode(int data)
{
    Node *node = new Node;
    if (node == NULL)
    {
        printf("new node failed!\n");
        return NULL;
    }
    node->data = data;
    node->next = NULL;
    return node;
}

// 创建一个单链表，并返回链表头节点
Node *createList()
{
    Node *head = createNode(1);
    Node *node = head;
    for (int i = 2; i <= 10; i++)
    {
        node->next = createNode(i);
        node = node->next;
    }
    return head;
}

//得到当前系统空闲内存，当前CPU使用率，当前系统运行时间，当前磁盘使用率，当前磁盘读写速度，当前磁盘空闲空间，printf打印输出
void getSystemInfo()
{
    system("top -n 1");
}

// 将一个节点插入单链表最末尾，new一个新节点失败，要打印报错信息
void insertNode(Node *head, int data)
{
    Node *node = createNode(data);
    if (node == NULL)
    {
        printf("new node failed!\n");
        getSystemInfo();
        return;
    }
    Node *p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = node;
}

// 一个单链表，准备插入一个Node节点，二分查找该链表，找到链表中第一个节点，该节点的data值刚好大于等于准备插入的Node节点data值，则插入到该节点之前
void InsertNode(Node *&head, Node *&tail, Node *&node)
{
    Node *p = head;
    Node *q = NULL;
    while (p != NULL)
    {
        if (p->data >= node->data)
        {
            break;
        }
        q = p;
        p = p->next;
    }
    if (p == head)
    {
        node->next = head;
        head = node;
    }
    else
    {
        q->next = node;
        node->next = p;
    }
}

//一个单链表，采用标准折半查找来查找一个节点，找到链表中第一个节点，该节点的data值刚好等于准备查找的Node节点data值，则返回true，否则返回false
bool searchNode(Node *head, int data)
{
    Node *p = head;
    while (p != NULL)
    {
        if (p->data == data)
        {
            return true;
        }
        p = p->next;
    }
    return false;
}

// 用二分查找单链表，当其中一个Node节点的data数据等于给定的值时，返回true，否则返回false
bool searchNode(Node *head, int data, Node *&node)
{
    Node *p = head;
    while (p != NULL)
    {
        if (p->data == data)
        {
            node = p;
            return true;
        }
        p = p->next;
    }
    return false;
}


// 遍历一个链表节点，当其中一个Node节点的data等于某个值，delete要非空判断
void DeleteNode(Node *&head, Node *&tail, int value)
{
    Node *p = head;
    Node *q = NULL;
    while (p != NULL)
    {
        if (p->data == value)
        {
            if (p == head)
            {
                head = p->next;
            }
            else
            {
                q->next = p->next;
            }
            delete p;
            p = NULL;
            break;
        }
        q = p;
        p = p->next;
    }
}

//对一个单链表，按照Node节点里的data值大小，进行升序排序
void SortNode(Node *&head, Node *&tail)
{
    Node *p = head;
    Node *q = NULL;
    Node *r = NULL;
    while (p != NULL)
    {
        q = p->next;
        while (q != NULL)
        {
            if (p->data > q->data)
            {
                r = q->next;
                q->next = p;
                if (p == head)
                {
                    head = q;
                }
                else
                {
                    p->next = r;
                }
                p = q;
            }
            q = r;
        }
        p = p->next;
    }
}

//对一个单链表，按照Node节点里的data值大小，进行降序排序
void SortNodeDesc(Node *&head, Node *&tail)
{
    Node *p = head;
    Node *q = NULL;
    Node *r = NULL;
    while (p != NULL)
    {
        q = p->next;
        while (q != NULL)
        {
            if (p->data < q->data)
            {
                r = q->next;
                q->next = p;
                if (p == head)
                {
                    head = q;
                }
                else
                {
                    p->next = r;
                }
                p = q;
            }
            q = r;
        }
        p = p->next;
    }
}

// 对一个单链表，按照Node节点里的data值大小，进行升序排列，然后再将所得的新链表，根据传入的值，用二分查找法查找，返回该节点的地址
Node *BinarySearch(Node *head, int value)
{
    Node *p = head;
    Node *q = NULL;
    Node *r = NULL;
    while (p != NULL)
    {
        q = p->next;
        while (q != NULL)
        {
            if (p->data > q->data)
            {
                r = q->next;
                q->next = p;
                if (p == head)
                {
                    head = q;
                }
                else
                {
                    p->next = r;
                }
                p = q;
            }
            q = r;
        }
        p = p->next;
    }
    p = head;
    while (p != NULL)
    {
        if (p->data == value)
        {
            return p;
        }
        p = p->next;
    }
    return NULL;
}


// 对一个单链表，按照Node节点里的data值大小，用标准快速排序
void QuickSort(Node *&head, Node *&tail, int low, int high)
{
    if (low >= high)
    {
        return;
    }
    int i = low;
    int j = high;
    int key = head->data;
    while (i < j)
    {
        while (i < j && head->data <= key)
        {
            i++;
            head = head->next;
        }
        while (i < j && head->data > key)
        {
            j--;
            tail = tail->next;
        }
        if (i < j)
        {
            int temp = head->data;
            head->data = tail->data;
            tail->data = temp;
        }
    }
    head->data = tail->data;
    tail->data = key;
    QuickSort(head, tail, low, i - 1);
    QuickSort(head, tail, j + 1, high);
}

// 对一个单链表，按照Node节点里的data值大小，用快速排序，选出由大到小前n个节点，输出新链表
void QuickSortTopN(Node *&head, Node *&tail, int n)
{
    Node *p = head;
    Node *q = NULL;
    Node *r = NULL;
    while (p != NULL)
    {
        q = p->next;
        while (q != NULL)
        {
            if (p->data > q->data)
            {
                r = q->next;
                q->next = p;
                if (p == head)
                {
                    head = q;
                }
                else
                {
                    p->next = r;
                }
                p = q;
            }
            q = r;
        }
        p = p->next;
    }
    p = head;
    int i = 0;
    while (p != NULL)
    {
        if (i >= n)
        {
            break;
        }
        p = p->next;
        i++;
    }
    if (p != NULL)
    {
        tail = p->next;
        p->next = NULL;
    }
}

// 对一个单链表，按照Node节点里的data值大小，进行降序排列，然后再将所得的新链表，凡是data值小于传入的值的节点都删除
void DeleteNode(Node *&head, Node *&tail, int value)
{
    SortNodeDesc(head, tail);

    p = head;
    while (p != NULL)
    {
        if (p->data < value)
        {
            if (p == head)
            {
                head = p->next;
            }
            else
            {
                q->next = p->next;
            }
            delete p;
            p = q->next;
        }
        else
        {
            q = p;
            p = p->next;
        }
    }
}

// 单链表，凡是节点里data值等于传入的值，则把该节点下的data值都改为0
void ChangeNode(Node *&head, Node *&tail, int value)
{
    Node *p = head;
    while (p != NULL)
    {
        if (p->data == value)
        {
            p->data = 0;
        }
        p = p->next;
    }
}

// 清空整个链表
void ClearList(Node *&head, Node *&tail)
{
    Node *p = head;
    Node *q = NULL;
    while (p != NULL)
    {
        q = p->next;
        delete p;
        p = q;
    }
    head = NULL;
    tail = NULL;
}

// 把一个verctor里的数据，按照Node节点里的data值大小，放入一个单链表
void VectorToList(vector<int> &vec, Node *&head, Node *&tail)
{
    Node *p = NULL;
    Node *q = NULL;
    for (int i = 0; i < vec.size(); i++)
    {
        p = new Node;
        p->data = vec[i];
        p->next = NULL;
        if (head == NULL)
        {
            head = p;
        }
        else
        {
            q->next = p;
        }
        q = p;
    }
    tail = p;
}

//把一个verctor里的int数据，按照大小，采用快速排序，升序排列，且每完成n%的排序，输出排序进度
void VectorToList(vector<int> &vec, Node *&head, Node *&tail, int n)
{
    Node *p = NULL;
    Node *q = NULL;
    for (int i = 0; i < vec.size(); i++)
    {
        p = new Node;
        p->data = vec[i];
        p->next = NULL;
        if (head == NULL)
        {
            head = p;
        }
        else
        {
            q->next = p;
        }
        q = p;
    }
    tail = p;
    int i = 0;
    while (p != NULL)
    {
        if (i % n == 0)
        {
            cout << "排序进度：" << i << " / " << vec.size() << endl;
        }
        p = p->next;
        i++;
    }
}

//把一个int类型map数据，存入一个verctor里
void MapToVector(map<int, int> &map, vector<int> &vec)
{
    for (auto it = map.begin(); it != map.end(); it++)
    {
        vec.push_back(it->first);
    }
}

//把一个int类型verctor，存入一个map数据里
void VectorToMap(vector<int> &vec, map<int, int> &map)
{
    for (int i = 0; i < vec.size(); i++)
    {
        map[vec[i]] = vec[i];
    }
}

//随机生成n个从a到b的整数，存入一个verctor里
void RandomToVector(vector<int> &vec, int n, int a, int b)
{
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        vec.push_back(rand() % (b - a + 1) + a);
    }
}

//把一个string字符串通过md5加密，返回一个string
string MD5(string str)
{
    unsigned char md[16];
    MD5_CTX ctx;
    MD5_Init(&ctx);
    MD5_Update(&ctx, str.c_str(), str.size());
    MD5_Final(md, &ctx);
    char buf[33];
    for (int i = 0; i < 16; i++)
    {
        sprintf(buf + i * 2, "%02x", md[i]);
    }
    return string(buf);
}

// 把char字符串转换为string类型
string CharToString(char *str)
{
    string s = str;
    return s;
}

//把string 类型字符串转换为char字符串
char *StringToChar(string str)
{
    char *c = new char[str.size() + 1];
    strcpy(c, str.c_str());
    return c;
}

//获取char数组的长度
int GetCharArrayLength(char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    return i;
}

//获取string类型的字符串的长度
int GetStringLength(string str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    return i;
}

//获取string类型的字符串的大小
int GetStringSize(string str)
{
    return str.size();
}

// 把int类型转换成string类型
string IntToString(int n)
{
    stringstream ss;
    ss << n;
    string s = ss.str();
    return s;
}

//把string类型转换成int类型
int StringToInt(string str)
{
    int n = 0;
    stringstream ss;
    ss << str;
    ss >> n;
    return n;
}

//打开一个txt文件，并将每一行存入string，然后把每一行的string生成一个单链表
void OpenTxtFile(string filename, Node *&head, Node *&tail)
{
    ifstream fin;
    fin.open(filename);
    string line;
    Node *p = NULL;
    Node *q = NULL;
    while (getline(fin, line))
    {
        p = new Node;
        p->data = CharToString(StringToChar(line));
        p->next = NULL;
        if (head == NULL)
        {
            head = p;
        }
        else
        {
            q->next = p;
        }
        q = p;
    }
    tail = p;
    fin.close();
}

//把一个链表的data数据写入一个txt文件，每一行一个数据并且后面附带时间戳
void WriteTxtFile(string filename, Node *head)
{
    ofstream fout;
    fout.open(filename);
    Node *p = head;
    while (p != NULL)
    {
        fout << p->data << " " << time(NULL) << endl;
        p = p->next;
    }
    fout.close();
}

//根据提供的值，二分查找data值，查找完毕后，快速排序该链表
void BinarySearch(Node *&head, Node *&tail, int value)
{
    Node *p = head;
    Node *q = NULL;
    while (p != NULL)
    {
        if (p->data == value)
        {
            q = p;
            break;
        }
        p = p->next;
    }
    if (q != NULL)
    {
        if (q == head)
        {
            head = q->next;
        }
        else
        {
            p = head;
            while (p->next != q)
            {
                p = p->next;
            }
            p->next = q->next;
        }
        q->next = head;
        head = q;
    }
    QuickSort(head);
}

//判断一个结构体数据中的x,y值是否在一个矩形中
bool IsInRect(Rectangle rect, Point point)
{
    if (point.x >= rect.x && point.x <= rect.x + rect.width && point.y >= rect.y && point.y <= rect.y + rect.height)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//判断一个结构体数据中的x,y值是否在一个圆形中
bool IsInCircle(Circle circle, Point point)
{
    if (sqrt((point.x - circle.x) * (point.x - circle.x) + (point.y - circle.y) * (point.y - circle.y)) <= circle.r)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//判断两个矩形是否相交
bool IsIntersect(Rectangle rect1, Rectangle rect2)
{
    if (rect1.x + rect1.width < rect2.x || rect1.x > rect2.x + rect2.width || rect1.y + rect1.height < rect2.y || rect1.y > rect2.y + rect2.height)
    {
        return false;
    }
    else
    {
        return true;
    }
}

//求出两个相交矩形的相交区域
Rectangle GetIntersectRect(Rectangle rect1, Rectangle rect2)
{
    Rectangle rect;
    rect.x = max(rect1.x, rect2.x);
    rect.y = max(rect1.y, rect2.y);
    rect.width = min(rect1.x + rect1.width, rect2.x + rect2.width) - rect.x;
    rect.height = min(rect1.y + rect1.height, rect2.y + rect2.height) - rect.y;
    return rect;
}

//判断当前玩家疲劳值是否满足进入某个房间给定的值
bool IsFatigue(int fatigue, int value)
{
    if (fatigue >= value)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//玩家强化武器装备成功率依次递减
int GetSuccessRate(int strength)
{
    int rate = 0;
    if (strength == 1)
    {
        rate = 100;
    }
    else if (strength == 2)
    {
        rate = 80;
    }
    else if (strength == 3)
    {
        rate = 60;
    }
    else if (strength == 4)
    {
        rate = 40;
    }
    else if (strength == 5)
    {
        rate = 20;
    }
    else if (strength == 6)
    {
        rate = 0;
    }
    return rate;
}

// 一个map类型，由一个key为unsigned int，value为string类型的verctor组成，将每个map中vector里的int，导入到一个单链表里，new一个新节点失败，要打印报错信息，返回false，并退出程序
bool MapToList(map<unsigned int, vector<int>> &map, Node *&head, Node *&tail)
{
    Node *p = NULL;
    for (auto &i : map)
    {
        for (auto &j : i.second)
        {
            p = new Node;
            if (p == NULL)
            {
                cout << "new node failed" << endl;
                return false;
            }
            p->data = j;
            if (head == NULL)
            {
                head = p;
            }
            else
            {
                tail->next = p;
            }
            tail = p;
        }
    }
    return true;
}

// 把一个csv文件中的数据读入到一个map中，key为unsigned int，value为string类型的verctor组成，返回map
map<unsigned int, vector<int>> CsvToMap(string fileName)
{
    map<unsigned int, vector<int>> map;
    ifstream fin(fileName);
    if (!fin)
    {
        cout << "open file failed" << endl;
        return map;
    }
    string line;
    while (getline(fin, line))
    {
        stringstream ss(line);
        unsigned int key;
        vector<int> value;
        ss >> key;
        while (ss)
        {
            int temp;
            ss >> temp;
            value.push_back(temp);
        }
        map[key] = value;
    }
    fin.close();
    return map;
}

//对一个int 类型的verctor，进行快速排序
void QuickSort(vector<int> &vec)
{
    if (vec.size() <= 1)
    {
        return;
    }
    int temp = vec[0];
    vector<int>::iterator low = vec.begin();
    vector<int>::iterator high = vec.end() - 1;
    while (low < high)
    {
        while (low < high && *high >= temp)
        {
            high--;
        }
        *low = *high;
        while (low < high && *low <= temp)
        {
            low++;
        }
        *high = *low;
    }
    *low = temp;
    QuickSort(vec, 0, low - vec.begin());
    QuickSort(vec, low - vec.begin() + 1, vec.size() - 1);
}

//一个int 类型的verctor，采用二分查找某个给定的int值
int BinarySearch(vector<int> &vec, int value)
{
    int low = 0;
    int high = vec.size() - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (vec[mid] == value)
        {
            return mid;
        }
        else if (vec[mid] < value)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

// 把一个char类型字符串，粘贴到另一个char类型字符串的最后面，然后再把这个字符串反转，返回反转后的字符串
string PasteAndReverse(char *strC1, char *strC2)
{
    string str1 = CharToString(strC1);
    string str2 = CharToString(strC2);

    string str = str1 + str2;
    reverse(str.begin(), str.end());
    return str;
}

// 把一个int类型数组，获取这个数组的大小后，全部memset为0
void ClearArray(int *array)
{
    int size = sizeof(array) / sizeof(array[0]);
    memset(array, 0, size);
}
































//----------------------------------------------麻将游戏----------------------------------------------

//创建一个麻将桌子，桌子可以容纳4个玩家，创建完毕后，返回这个桌子的地址，，且把麻将桌子的状态TableState标志设置为TABLE_FREE，如果创建失败，返回NULL
Table *CreateTable(int tableId)
{
    Table *table = new Table;
    if (table == NULL)
    {
        cout << "new table failed" << endl;
        return NULL;
    }
    table->tableId = tableId;
    table->tableState = TABLE_FREE;
    return table;
}

//销毁一个麻将桌子，判断该桌子状态是否为TABLE_FREE，如果不是，返回false，如果是，则销毁该桌子，并且返回true
bool DestroyTable(Table *table)
{
    if (table == NULL)
    {
        cout << "table is NULL" << endl;
        return false;
    }
    if (table->tableState != TABLE_FREE)
    {
        cout << "table is not free" << endl;
        return false;
    }
    delete table;
    return true;
}

//一个玩家加入桌子，判断该桌子人数是否超出最大人数MAX_PLAYER，如果满了，则返回false，否则，把玩家加入到桌子上，并且把桌子的状态标志置为TABLE_PLAYING，返回true
// 且把玩家从大厅空闲队列中删除，并且把玩家的状态标志设置为InGame
bool JoinTable(Table *table, Player *player)
{
    if (table == NULL || player == NULL)
    {
        cout << "table or player is NULL" << endl;
        return false;
    }
    if (table->status != TABLE_FREE)
    {
        cout << "table id = "<<table->id<<"  is not free" << endl;
        return false;
    }
    if (table->players.size() >= MAX_PLAYER)
    {
        cout << "table id = "<<table->id<<" is full" << endl;
        return false;
    }
    table->players.push_back(player);
    table->status = TABLE_OCCUPIED;
    return true;
}

// 玩家当前桌子只有1人，该玩家退出后，把桌子的状态标志置为TABLE_FREE，并且把该玩家添加到大厅玩家空闲队列lobbyPlayerQueue中，并且把玩家的状态标志设置为LeaveGame
bool LeaveTable(Table *table, Player *player)
{
    if (table == NULL || player == NULL)
    {
        cout << "table or player is NULL" << endl;
        return false;
    }
    if (table->status != TABLE_OCCUPIED)
    {
        cout << "table id = "<<table->id<<" is not occupied" << endl;
        return false;
    }
    if (table->players.size() != 1)
    {
        cout << "table id = "<<table->id<<" is not 1" << endl;
        return false;
    }
    table->status = TABLE_FREE;
    table->players.clear();
    return true;
}

//创建一个麻将房间，这个房间是map容器，key是桌子id号，里面存放的是麻将桌子，返回这个房间的地址
Room *CreateRoom(unsigned int id)
{
    Room *room = new Room;
    room->id = id;
    return room;
}

// 麻将房间添加桌子，根据传入的桌子地址，把桌子加入到房间中，map左值是桌子id号，如果桌子已经存在，则不添加，返回false，否则，添加成功，返回true
bool AddTableToRoom(Room *room, Table *table)
{
    if (room == NULL || table == NULL)
    {
        cout << "room or table is NULL" << endl;
        return false;
    }
    if (room->tables.find(table->id) != room->tables.end())
    {
        cout << "table id = "<<table->id<<" is already in room" << endl;
        return false;
    }
    room->tables.insert(pair<int, Table *>(table->id, table));
    return true;
}

// 麻将房间删除桌子，根据传入的桌子id，把桌子从房间中删除，如果桌子不存在，则不删除，返回false，否则，删除成功，返回true
bool RemoveTableFromRoom(Room *room, int tableId)
{
    if (room == NULL)
    {
        cout << "room is NULL" << endl;
        return false;
    }
    if (room->tables.find(tableId) == room->tables.end())
    {
        cout << "table id = "<<tableId<<" is not in room" << endl;
        return false;
    }
    room->tables.erase(tableId);
    return true;
}

// 销毁一个麻将房间，遍历房间，把桌子都销毁，然后把房间销毁，返回true
bool DestroyRoom(Room *room)
{
    if (room == NULL)
    {
        cout << "room is NULL" << endl;
        return false;
    }
    map<int, Table *>::iterator it;
    for (it = room->tables.begin(); it != room->tables.end(); it++)
    {
        DestroyTable(it->second);
    }
    delete room;
    return true;
}

// 在一个麻将房间中查找指定的桌子，根据传入的桌子id，查找房间中是否存在该桌子，如果存在，返回该桌子的地址，否则，返回NULL
Table *FindTableInRoom(Room *room, int tableId)
{
    if (room == NULL)
    {
        cout << "room is NULL" << endl;
        return NULL;
    }
    if (room->tables.find(tableId) == room->tables.end())
    {
        cout << "table id = "<<tableId<<" is not in room" << endl;
        return NULL;
    }
    return room->tables[tableId];
}

// 在一个麻将房间中查找指定的玩家userid，根据传入的玩家userid，查找房间中是否存在该玩家，如果存在，返回该玩家桌子的id号，否则，返回0
int FindTableIdInRoom(Room *room, int userId)
{
    if (room == NULL)
    {
        cout << "room is NULL" << endl;
        return 0;
    }
    map<int, Table *>::iterator it;
    for (it = room->tables.begin(); it != room->tables.end(); it++)
    {
        for (int i = 0; i < MAX_PLAYER; i++)
        {
            if (it->second->players[i].id == userId)
            {
                return it->first;
            }
        }
    }
    return 0;
}

// 创建一个麻将大厅Hall，返回这个大厅的地址
Hall *CreateHall()
{
    Hall *hall = new Hall;
    return hall;
}

// 麻将大厅插入一个房间，根据传入的房间地址，把房间插入到大厅中，如果房间已经存在，则不插入，返回false，否则，插入成功，返回true
bool AddRoomToHall(Hall *hall, Room *room)
{
    if (hall == NULL || room == NULL)
    {
        cout << "hall or room is NULL" << endl;
        return false;
    }
    if (hall->rooms.find(room->id) != hall->rooms.end())
    {
        cout << "room id = "<<room->id<<" is already in hall" << endl;
        return false;
    }
    hall->rooms.insert(pair<int, Room *>(room->id, room));
    return true;
}

// 麻将大厅删除一个房间，根据传入的房间id，把房间从大厅中删除，如果房间不存在，则不删除，返回false，否则，删除成功，返回true
bool RemoveRoomFromHall(Hall *hall, int roomId)
{
    if (hall == NULL)
    {
        cout << "hall is NULL" << endl;
        return false;
    }
    if (hall->rooms.find(roomId) == hall->rooms.end())
    {
        cout << "room id = "<<roomId<<" is not in hall" << endl;
        return false;
    }
    hall->rooms.erase(roomId);
    return true;
}

// 销毁一个麻将大厅，遍历大厅，把房间都销毁，然后把大厅销毁，返回true
bool DestroyHall(Hall *hall)
{
    if (hall == NULL)
    {
        cout << "hall is NULL" << endl;
        return false;
    }
    map<int, Room *>::iterator it;
    for (it = hall->rooms.begin(); it != hall->rooms.end(); it++)
    {
        DestroyRoom(it->second);
    }
    delete hall;
    return true;
}

// 在麻将大厅里，根据玩家userid，查找该玩家所在的房间，如果存在，返回该房间的地址，否则，返回NULL
Room *FindRoomInHall(Hall *hall, int userId)
{
    if (hall == NULL)
    {
        cout << "hall is NULL" << endl;
        return NULL;
    }
    map<int, Room *>::iterator it;
    for (it = hall->rooms.begin(); it != hall->rooms.end(); it++)
    {
        if (FindTableIdInRoom(it->second, userId) != 0)
        {
            return it->second;
        }
    }
    return NULL;
}

// 在麻将大厅里，根据玩家昵称，查找该玩家所在的房间，如果存在，返回该房间的id号，否则，返回0
int FindRoomIdInHall(Hall *hall, string userName)
{
    if (hall == NULL)
    {
        cout << "hall is NULL" << endl;
        return 0;
    }
    map<int, Room *>::iterator it;
    for (it = hall->rooms.begin(); it != hall->rooms.end(); it++)
    {
        if (FindTableIdInRoom(it->second, userName) != 0)
        {
            return it->first;
        }
    }
    return 0;
}

//大厅空闲玩家队列
// 在map类型lobbyPlayerQueue里，插入一个玩家player，根据传入的玩家player 的id，插入到lobbyPlayerQueue中，如果玩家已经存在，则不插入，返回false，否则，插入成功，返回true
bool AddPlayerToLobbyPlayerQueue(map<int, Player *> &lobbyPlayerQueue, Player *player)
{
    if (player == NULL)
    {
        cout << "player is NULL" << endl;
        return false;
    }
    if (lobbyPlayerQueue.find(player->id) != lobbyPlayerQueue.end())
    {
        cout << "player id = "<<player->id<<" is already in lobbyPlayerQueue" << endl;
        return false;
    }
    lobbyPlayerQueue.insert(pair<int, Player *>(player->id, player));
    return true;
}

// 玩家空闲队列里，删除一个玩家，根据传入的玩家id，删除空闲队列里的该玩家，如果不存在，则不删除，返回false，否则，删除成功，返回true
bool RemovePlayerFromLobbyPlayerQueue(map<int, Player *> &lobbyPlayerQueue, int playerId)
{
    if (lobbyPlayerQueue.find(playerId) == lobbyPlayerQueue.end())
    {
        cout << "player id = "<<playerId<<" is not in lobbyPlayerQueue" << endl;
        return false;
    }
    lobbyPlayerQueue.erase(playerId);
    return true;
}

// 玩家空闲队列里，查找一个玩家，根据传入的玩家id，查找空闲队列里的该玩家，如果查找失败，那么返回false，否则，返回true
bool FindPlayerInLobbyPlayerQueue(map<int, Player *> &lobbyPlayerQueue, int playerId)
{
    if (lobbyPlayerQueue.find(playerId) == lobbyPlayerQueue.end())
    {
        cout << "player id = "<<playerId<<" is not in lobbyPlayerQueue" << endl;
        return false;
    }
    return true;
}


































