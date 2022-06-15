
#include "headfile.h"

// 对一个int类型verctor采用冒泡排序
void bubble_sort(vector<int> &v)
{
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (v[j] > v[j + 1])
            {
                swap(v[j], v[j + 1]);
            }
        }
    }
}

// 把char类型字符串转换为string类型
string char_to_string(char *str)
{
    string s(str);
    return s;
}

// 把string类型字符串转换为char类型
char *string_to_char(string str)
{
    char *s = new char[str.size() + 1];
    strcpy(s, str.c_str());
    return s;
}

// 比较一个char类型字符串和string类型字符串是否相等
bool char_string_equal(char *str1, string str2)
{
    string s1(str1);
    return s1 == str2;
}

// 把一个char类型字符串里的数字提取出来，放到一个int类型vector里
vector<int> extract_number(char *str)
{
    vector<int> v;
    string s(str);
    stringstream ss(s);
    int i;
    while (ss >> i)
    {
        v.push_back(i);
        if (ss.peek() == ',')
        {
            ss.ignore();
        }
    }
    return v;
}



