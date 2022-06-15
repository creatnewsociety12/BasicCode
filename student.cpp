
// 定义一个学生数据结构体，包含学生的姓名、学号、成绩和年龄。
struct student
{
    char name[20];
    int number;
    int score;
    int age;
};

// 定义一个student类型的vector，用于存储学生信息。
vector<student> students;

// verctor插入一个学生信息
void insert_student(student s)
{
    students.push_back(s);
}

// 冒泡排序，按照学生的成绩从小到大排序
void bubble_sort()
{
    int n = students.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (students[j].score > students[j + 1].score)
            {
                swap(students[j], students[j + 1]);
            }
        }
    }
}

// 快速排序，按照学生的成绩从小到大排序
void quick_sort()
{
    int n = students.size();
    int i = 0;
    int j = n - 1;
    int pivot = students[n / 2].score;
    while (i <= j)
    {
        while (students[i].score < pivot)
        {
            i++;
        }
        while (students[j].score > pivot)
        {
            j--;
        }
        if (i <= j)
        {
            swap(students[i], students[j]);
            i++;
            j--;
        }
    }
    if (i < n / 2)
    {
        quick_sort(i, n - 1);
    }
    if (j > n / 2)
    {
        quick_sort(0, j);
    }
}

// 根据学生姓名查找学生信息
student find_student_by_name(char *name)
{
    string s(name);
    for (int i = 0; i < students.size(); i++)
    {
        if (string(students[i].name) == s)
        {
            return students[i];
        }
    }
    student s1;
    return s1;
}

// 根据学生成绩查找学生信息
student find_student_by_score(int score)
{
    for (int i = 0; i < students.size(); i++)
    {
        if (students[i].score == score)
        {
            return students[i];
        }
    }
    student s1;
    return s1;
}

// 根据学生学号查找学生信息
student find_student_by_number(int number)
{
    for (int i = 0; i < students.size(); i++)
    {
        if (students[i].number == number)
        {
            return students[i];
        }
    }
    student s1;
    return s1;
}

// 根据学生学号，删除学生信息
void delete_student_by_number(int number)
{
    for (int i = 0; i < students.size(); i++)
    {
        if (students[i].number == number)
        {
            students.erase(students.begin() + i);
        }
    }
}

// 根据学生学号，二分查找学生信息
student binary_search_by_number(int number)
{
    int n = students.size();
    int i = 0;
    int j = n - 1;
    int mid = 0;
    while (i <= j)
    {
        mid = (i + j) / 2;
        if (students[mid].number == number)
        {
            return students[mid];
        }
        if (students[mid].number > number)
        {
            j = mid - 1;
        }
        if (students[mid].number < number)
        {
            i = mid + 1;
        }
    }
    student s1;
    return s1;
}




