#include<iostream>
#include<string>
#define max 1000//最大人数
using namespace std;

struct student//学生结构体
{
    int  msex;
    string mname;
    int mage;
    int mscore;
    int mid;
    int mchinese;
    int mmath;
    int menglish;
};
struct addressbooks//学生录结构体
{
    struct student studentarry[max];
    int msize;//学生录中的人员数
};

void addstudent(addressbooks* abs)//添加学生
{
    if (abs->msize == max)
    {
        cout << "通讯录已满，无法添加" << endl;
        return;
    }
    else
    {
        string name;
        cout << "请输入姓名：  " << endl;
        cin >> name;
        abs->studentarry[abs->msize].mname = name;

        cout << "1--男" << endl;
        cout << "2--女" << endl;
        int sex = 0;
        while (true)//死循环一直到输入的数对为止猜出结果
        {
            cin >> sex;
            if (sex == 1 || sex == 2)
            {
                abs->studentarry[abs->msize].msex = sex;
                break;
            }
            cout << "输入有误，请重新输入" << endl;
        }

        cout << "请输入年龄:  " << endl;
        int age = 0;
        cin >> age;
        abs->studentarry[abs->msize].mage = age;

        cout << "请输入语文成绩：" << endl;
        int chinese = 0;
        cin >> chinese;
        abs->studentarry[abs->msize].mchinese = chinese;
        cout << "请输入数学成绩：" << endl;
        int math;
        cin >> math;
        abs->studentarry[abs->msize].mmath = math;
        cout << "请输入英语成绩：" << endl;
        int english;
        cin >> english;
        abs->studentarry[abs->msize].menglish = english;
        abs->studentarry[abs->msize].mscore = chinese + math + english;

        cout << "请输入学号" << endl;
        int id;
        cin >> id;
        abs->studentarry[abs->msize].mid = id;

        abs->msize++;
        cout << "添加成功" << endl;

//        system("pause");//按任意键进行
//        system("cls");//清屏功能
    }
}

void showstudent(addressbooks* abs)//显示联系人
{
    if (abs->msize == 0)
    {
        cout << "当前记录为空" << endl;
    }
    else
    {
        for (int i = 0; i < abs->msize; i++)
        {
            cout << "名字： " << abs->studentarry[i].mname << "\t";
            cout << "性别： " << (abs->studentarry[i].msex == 1 ? "男" : "女") << "\t";//三目运算符
            cout << "年龄： " << abs->studentarry[i].mage << "\t";
            cout << "语文： " << abs->studentarry[i].mchinese << "\t";
            cout << "数学： " << abs->studentarry[i].mmath << "\t";
            cout << "英语： " << abs->studentarry[i].menglish << "\t";
            cout << "分数： " << abs->studentarry[i].mscore << "\t";
            cout << "学号： " << abs->studentarry[i].mid << endl;
            cout << endl;
        }
    }
//    system("pause");
//    system("cls");
}

//检测联系人是否存在，如果存在，返回联系人所在数组中的具体位置，不存在返回-1
int isExist(addressbooks* abs, string name)//通讯录，对比名字
{
    for (int i = 0; i < abs->msize; i++)
    {
        if (abs->studentarry[i].mname == name)
        {
            return i;//返回查找人在数组中的下标编号
        }
    }
    return -1;//如果遍历结束都没找到，返回负一
}
void deletestudent(addressbooks* abs)//删除学生
{
    cout << "请输入你想要删除的联系人" << endl;
    string name;
    cin >> name;
    int ret = isExist(abs, name);//接收上函数的数据
    if (ret != -1)
    {
        for (int i = ret; i < abs->msize; i++)
        {
            abs->studentarry[i] = abs->studentarry[i + 1];//数据前移
        }
        abs->msize--;//更像通讯录中的人员数
        cout << "删除成功" << endl;
    }
    else
    {
        cout << "查无此人" << endl;
    }
//    system("pause");
//    system("cls");
}

void findstudent(addressbooks* abs)//查找学生
{
    cout << "请输入你要查找的联系人" << endl;
    string name;
    cin >> name;
    int ret = isExist(abs, name);
    if (ret != -1)
    {
        cout << "姓名： " << abs->studentarry[ret].mname << endl;
        cout << "性别： " << abs->studentarry[ret].msex << endl;
        cout << "年龄： " << abs->studentarry[ret].mage << endl;
        cout << "分数： " << abs->studentarry[ret].mscore << endl;
        cout << "语文： " << abs->studentarry[ret].mchinese << endl;
        cout << "数学： " << abs->studentarry[ret].mmath << endl;
        cout << "英语： " << abs->studentarry[ret].menglish << endl;
        cout << "学号： " << abs->studentarry[ret].mid << endl;
    }
    else
    {
        cout << "查无此人" << endl;
    }
//    system("pause");
//    system("cls");
}

void modifystudent(addressbooks* abs)//修改学生
{
    cout << "请输入要修改的人" << endl;
    string name;
    cin >> name;
    int ret = isExist(abs, name);
    {
        if (ret != -1)
        {
            string name;
            cout << "请输入姓名：" << endl;
            cin >> name;
            abs->studentarry[ret].mname = name;

            cout << "请输入性别:" << endl;
            cout << "1--男" << endl;
            cout << "2--女" << endl;
            int sex = 0;
            while (true)//死循环一直到输入的数对为止猜出结果
            {
                cin >> sex;
                if (sex == 1 || sex == 2)
                {
                    abs->studentarry[ret].msex = sex;
                    break;
                }
                cout << "输入有误，请重新输入" << endl;
            }

            cout << "请输入年龄:  " << endl;
            int age = 0;
            cin >> age;
            abs->studentarry[ret].mage = age;

            cout << "请输入语文成绩：" << endl;
            int chinese = 0;
            cin >> chinese;
            abs->studentarry[abs->msize].mchinese = chinese;
            cout << "请输入数学成绩：" << endl;
            int math;
            cin >> math;
            abs->studentarry[abs->msize].mmath = math;
            cout << "请输入英语成绩：" << endl;
            int english;
            cin >> english;
            abs->studentarry[abs->msize].menglish = english;
            abs->studentarry[abs->msize].mscore = chinese + math + english;

            cout << "请输入学号" << endl;
            int id;
            cin >> id;
            abs->studentarry[abs->msize].mid = id;

            cout << "修改成功" << endl;
        }
        else
        {
            cout << "查无此人" << endl;
        }
//        system("pause");
//        system("cls");
    }
}

void cleanstudent(addressbooks* abs)
{

    cout << "按1--确定清空，按2退出清空" << endl;
    int  choise = 0;
    cin >> choise;
    if (choise == 1)
    {
        abs->msize = 0;//将当前记录的联系人重置为0；做逻辑清空操作
        cout << "通讯录已清空" << endl;
    }
    else
    {
        cout << "退出清空" << endl;
    }
//    system("pause");
//    system("cls");
}
//void rankstudent(addressbooks* abs)
//{
//    for (int i = 0; i < abs->msize - 1; i++)
//    {
//        for (int j = 0; j < abs->msize - i - 1; j++)
//        {
//            if (abs->studentarry[j].mscore < abs->studentarry[j + 1].mscore)
//            {
//                //换分数
//                int temp1 = abs->studentarry[j + 1].mscore;
//                abs->studentarry[j + 1].mscore = abs->studentarry[j].mscore;
//                abs->studentarry[j].mscore = temp1;
//
//                //换名字
//                string temp2 = abs->studentarry[j + 1].mname;
//                abs->studentarry[j + 1].mname = abs->studentarry[j].mname;
//                abs->studentarry[j].mname = temp2;
//
//                //换性别
//                int temp3 = abs->studentarry[j + 1].msex;
//                abs->studentarry[j + 1].msex = abs->studentarry[j].msex;
//                abs->studentarry[j].msex = temp3;
//
//                //换语文成绩
//                int temp4 = abs->studentarry[j + 1].mchinese;
//                abs->studentarry[j + 1].mchinese = abs->studentarry[j].mchinese;
//                abs->studentarry[j].mchinese = temp4;
//
//                //换数学成绩
//                int temp5 = abs->studentarry[j + 1].mmath;
//                abs->studentarry[j + 1].mmath = abs->studentarry[j].mmath;
//                abs->studentarry[j].mmath = temp5;
//
//                //换英语成绩
//                int temp6 = abs->studentarry[j + 1].menglish;
//                abs->studentarry[j + 1].menglish = abs->studentarry[j].menglish;
//                abs->studentarry[j].menglish = temp6;
//
//                //换学号
//                int temp = abs->studentarry[j + 1].mid;
//                abs->studentarry[j + 1].mid = abs->studentarry[j].mid;
//                abs->studentarry[j].mid = temp;
//
//                //换年龄
//                int temp7 = abs->studentarry[j + 1].mage;
//                abs->studentarry[j + 1].mage = abs->studentarry[j].mage;
//                abs->studentarry[j].mage = temp7;
//            }
//        }
//    }
//    for (int i = 0; i < abs->msize; i++)
//    {
//        cout << "名字： " << abs->studentarry[i].mname << "\t";
//        cout << "性别： " << (abs->studentarry[i].msex == 1 ? "男" : "女") << "\t";//三目运算符
//        cout << "年龄： " << abs->studentarry[i].mage << "\t";
//        cout << "语文： " << abs->studentarry[i].mchinese << "\t";
//        cout << "数学： " << abs->studentarry[i].mmath << "\t";
//        cout << "英语： " << abs->studentarry[i].menglish << "\t";
//        cout << "分数： " << abs->studentarry[i].mscore << "\t";
//        cout << "学号： " << abs->studentarry[i].mid << endl;
//        cout << endl;
//    }
//    system("pause");
//    system("cls");
//}
void rankstudent(addressbooks abs)
{
    for (int i = 0; i < abs.msize - 1; i++)
    {
        for (int j = 0; j < abs.msize - i - 1; j++)
        {
            if (abs.studentarry[j].mscore < abs.studentarry[j + 1].mscore)
            {
                student student=abs.studentarry[j+1];
                abs.studentarry[j+1]=abs.studentarry[j];
                abs.studentarry[j]=student;
            }
        }
    }
    for (int i = 0; i < abs.msize; i++)
    {
        cout << "名字： " << abs.studentarry[i].mname << "\t";
        cout << "性别： " << (abs.studentarry[i].msex == 1 ? "男" : "女") << "\t";//三目运算符
        cout << "年龄： " << abs.studentarry[i].mage << "\t";
        cout << "语文： " << abs.studentarry[i].mchinese << "\t";
        cout << "数学： " << abs.studentarry[i].mmath << "\t";
        cout << "英语： " << abs.studentarry[i].menglish << "\t";
        cout << "分数： " << abs.studentarry[i].mscore << "\t";
        cout << "学号： " << abs.studentarry[i].mid << endl;
        cout << endl;
    }
    system("pause");
    system("cls");
}
void fail(addressbooks* abs){
     for(int i=0; i<abs->msize;i++){
         if(abs->studentarry[i].mchinese<60 || abs->studentarry[i].mmath<60 ||abs->studentarry[i].menglish<60 ){
             cout << "名字： " << abs->studentarry[i].mname << "\t";
             cout << "性别： " << (abs->studentarry[i].msex == 1 ? "男" : "女") << "\t";//三目运算符
             cout << "年龄： " << abs->studentarry[i].mage << "\t";
             cout << "语文： " << abs->studentarry[i].mchinese << "\t";
             cout << "数学： " << abs->studentarry[i].mmath << "\t";
             cout << "英语： " << abs->studentarry[i].menglish << "\t";
             cout << "分数： " << abs->studentarry[i].mscore << "\t";
             cout << "学号： " << abs->studentarry[i].mid << endl;
             cout << endl;
         }
     }
}
void showMenu()
{
    cout << "1、添加学生" << endl;
    cout << "2、显示学生" << endl;
    cout << "3、删除学生" << endl;
    cout << "4、查找学生" << endl;
    cout << "5、修改学生" << endl;
    cout << "6、清空学生" << endl;
    cout << "7、排序学生" << endl;
    cout << "8、输出不及格学生"<<endl;
    cout << "0、退出系统" << endl;
}
int main()
{
    addressbooks abs;//学生录结构体变量
    abs.msize = 0;//初始化通讯录中当前人员的数
    int choise = 0;//用户选择的功能
    while (true)
    {
        showMenu();
        cin >> choise;
        switch (choise)
        {
            case 1://添加学生
                addstudent(&abs);//利用地址传递，可以修改实参
                break;
            case 2://显示学生
                showstudent(&abs);
                break;
            case 3://删除学生
                deletestudent(&abs);
                break;
            case 4://查找学生
                findstudent(&abs);
                break;
            case 5://修改联系人
                modifystudent(&abs);
                break;
            case 6://清空学生
                cleanstudent(&abs);
                break;
            case 7:
                rankstudent(abs);
            case 8:
                fail(&abs);
            case 0://退出学生录
                cout << "欢迎下次使用" << endl;
                system("pause");
                break;
            default:
                break;
        }
    }

    system("pause");
    return 0;
}