#include<iostream>
#include<string>
#define max 1000//�������
using namespace std;

struct student//ѧ���ṹ��
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
struct addressbooks//ѧ��¼�ṹ��
{
    struct student studentarry[max];
    int msize;//ѧ��¼�е���Ա��
};

void addstudent(addressbooks* abs)//���ѧ��
{
    if (abs->msize == max)
    {
        cout << "ͨѶ¼�������޷����" << endl;
        return;
    }
    else
    {
        string name;
        cout << "������������  " << endl;
        cin >> name;
        abs->studentarry[abs->msize].mname = name;

        cout << "1--��" << endl;
        cout << "2--Ů" << endl;
        int sex = 0;
        while (true)//��ѭ��һֱ�����������Ϊֹ�³����
        {
            cin >> sex;
            if (sex == 1 || sex == 2)
            {
                abs->studentarry[abs->msize].msex = sex;
                break;
            }
            cout << "������������������" << endl;
        }

        cout << "����������:  " << endl;
        int age = 0;
        cin >> age;
        abs->studentarry[abs->msize].mage = age;

        cout << "���������ĳɼ���" << endl;
        int chinese = 0;
        cin >> chinese;
        abs->studentarry[abs->msize].mchinese = chinese;
        cout << "��������ѧ�ɼ���" << endl;
        int math;
        cin >> math;
        abs->studentarry[abs->msize].mmath = math;
        cout << "������Ӣ��ɼ���" << endl;
        int english;
        cin >> english;
        abs->studentarry[abs->msize].menglish = english;
        abs->studentarry[abs->msize].mscore = chinese + math + english;

        cout << "������ѧ��" << endl;
        int id;
        cin >> id;
        abs->studentarry[abs->msize].mid = id;

        abs->msize++;
        cout << "��ӳɹ�" << endl;

//        system("pause");//�����������
//        system("cls");//��������
    }
}

void showstudent(addressbooks* abs)//��ʾ��ϵ��
{
    if (abs->msize == 0)
    {
        cout << "��ǰ��¼Ϊ��" << endl;
    }
    else
    {
        for (int i = 0; i < abs->msize; i++)
        {
            cout << "���֣� " << abs->studentarry[i].mname << "\t";
            cout << "�Ա� " << (abs->studentarry[i].msex == 1 ? "��" : "Ů") << "\t";//��Ŀ�����
            cout << "���䣺 " << abs->studentarry[i].mage << "\t";
            cout << "���ģ� " << abs->studentarry[i].mchinese << "\t";
            cout << "��ѧ�� " << abs->studentarry[i].mmath << "\t";
            cout << "Ӣ� " << abs->studentarry[i].menglish << "\t";
            cout << "������ " << abs->studentarry[i].mscore << "\t";
            cout << "ѧ�ţ� " << abs->studentarry[i].mid << endl;
            cout << endl;
        }
    }
//    system("pause");
//    system("cls");
}

//�����ϵ���Ƿ���ڣ�������ڣ�������ϵ�����������еľ���λ�ã������ڷ���-1
int isExist(addressbooks* abs, string name)//ͨѶ¼���Ա�����
{
    for (int i = 0; i < abs->msize; i++)
    {
        if (abs->studentarry[i].mname == name)
        {
            return i;//���ز������������е��±���
        }
    }
    return -1;//�������������û�ҵ������ظ�һ
}
void deletestudent(addressbooks* abs)//ɾ��ѧ��
{
    cout << "����������Ҫɾ������ϵ��" << endl;
    string name;
    cin >> name;
    int ret = isExist(abs, name);//�����Ϻ���������
    if (ret != -1)
    {
        for (int i = ret; i < abs->msize; i++)
        {
            abs->studentarry[i] = abs->studentarry[i + 1];//����ǰ��
        }
        abs->msize--;//����ͨѶ¼�е���Ա��
        cout << "ɾ���ɹ�" << endl;
    }
    else
    {
        cout << "���޴���" << endl;
    }
//    system("pause");
//    system("cls");
}

void findstudent(addressbooks* abs)//����ѧ��
{
    cout << "��������Ҫ���ҵ���ϵ��" << endl;
    string name;
    cin >> name;
    int ret = isExist(abs, name);
    if (ret != -1)
    {
        cout << "������ " << abs->studentarry[ret].mname << endl;
        cout << "�Ա� " << abs->studentarry[ret].msex << endl;
        cout << "���䣺 " << abs->studentarry[ret].mage << endl;
        cout << "������ " << abs->studentarry[ret].mscore << endl;
        cout << "���ģ� " << abs->studentarry[ret].mchinese << endl;
        cout << "��ѧ�� " << abs->studentarry[ret].mmath << endl;
        cout << "Ӣ� " << abs->studentarry[ret].menglish << endl;
        cout << "ѧ�ţ� " << abs->studentarry[ret].mid << endl;
    }
    else
    {
        cout << "���޴���" << endl;
    }
//    system("pause");
//    system("cls");
}

void modifystudent(addressbooks* abs)//�޸�ѧ��
{
    cout << "������Ҫ�޸ĵ���" << endl;
    string name;
    cin >> name;
    int ret = isExist(abs, name);
    {
        if (ret != -1)
        {
            string name;
            cout << "������������" << endl;
            cin >> name;
            abs->studentarry[ret].mname = name;

            cout << "�������Ա�:" << endl;
            cout << "1--��" << endl;
            cout << "2--Ů" << endl;
            int sex = 0;
            while (true)//��ѭ��һֱ�����������Ϊֹ�³����
            {
                cin >> sex;
                if (sex == 1 || sex == 2)
                {
                    abs->studentarry[ret].msex = sex;
                    break;
                }
                cout << "������������������" << endl;
            }

            cout << "����������:  " << endl;
            int age = 0;
            cin >> age;
            abs->studentarry[ret].mage = age;

            cout << "���������ĳɼ���" << endl;
            int chinese = 0;
            cin >> chinese;
            abs->studentarry[abs->msize].mchinese = chinese;
            cout << "��������ѧ�ɼ���" << endl;
            int math;
            cin >> math;
            abs->studentarry[abs->msize].mmath = math;
            cout << "������Ӣ��ɼ���" << endl;
            int english;
            cin >> english;
            abs->studentarry[abs->msize].menglish = english;
            abs->studentarry[abs->msize].mscore = chinese + math + english;

            cout << "������ѧ��" << endl;
            int id;
            cin >> id;
            abs->studentarry[abs->msize].mid = id;

            cout << "�޸ĳɹ�" << endl;
        }
        else
        {
            cout << "���޴���" << endl;
        }
//        system("pause");
//        system("cls");
    }
}

void cleanstudent(addressbooks* abs)
{

    cout << "��1--ȷ����գ���2�˳����" << endl;
    int  choise = 0;
    cin >> choise;
    if (choise == 1)
    {
        abs->msize = 0;//����ǰ��¼����ϵ������Ϊ0�����߼���ղ���
        cout << "ͨѶ¼�����" << endl;
    }
    else
    {
        cout << "�˳����" << endl;
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
//                //������
//                int temp1 = abs->studentarry[j + 1].mscore;
//                abs->studentarry[j + 1].mscore = abs->studentarry[j].mscore;
//                abs->studentarry[j].mscore = temp1;
//
//                //������
//                string temp2 = abs->studentarry[j + 1].mname;
//                abs->studentarry[j + 1].mname = abs->studentarry[j].mname;
//                abs->studentarry[j].mname = temp2;
//
//                //���Ա�
//                int temp3 = abs->studentarry[j + 1].msex;
//                abs->studentarry[j + 1].msex = abs->studentarry[j].msex;
//                abs->studentarry[j].msex = temp3;
//
//                //�����ĳɼ�
//                int temp4 = abs->studentarry[j + 1].mchinese;
//                abs->studentarry[j + 1].mchinese = abs->studentarry[j].mchinese;
//                abs->studentarry[j].mchinese = temp4;
//
//                //����ѧ�ɼ�
//                int temp5 = abs->studentarry[j + 1].mmath;
//                abs->studentarry[j + 1].mmath = abs->studentarry[j].mmath;
//                abs->studentarry[j].mmath = temp5;
//
//                //��Ӣ��ɼ�
//                int temp6 = abs->studentarry[j + 1].menglish;
//                abs->studentarry[j + 1].menglish = abs->studentarry[j].menglish;
//                abs->studentarry[j].menglish = temp6;
//
//                //��ѧ��
//                int temp = abs->studentarry[j + 1].mid;
//                abs->studentarry[j + 1].mid = abs->studentarry[j].mid;
//                abs->studentarry[j].mid = temp;
//
//                //������
//                int temp7 = abs->studentarry[j + 1].mage;
//                abs->studentarry[j + 1].mage = abs->studentarry[j].mage;
//                abs->studentarry[j].mage = temp7;
//            }
//        }
//    }
//    for (int i = 0; i < abs->msize; i++)
//    {
//        cout << "���֣� " << abs->studentarry[i].mname << "\t";
//        cout << "�Ա� " << (abs->studentarry[i].msex == 1 ? "��" : "Ů") << "\t";//��Ŀ�����
//        cout << "���䣺 " << abs->studentarry[i].mage << "\t";
//        cout << "���ģ� " << abs->studentarry[i].mchinese << "\t";
//        cout << "��ѧ�� " << abs->studentarry[i].mmath << "\t";
//        cout << "Ӣ� " << abs->studentarry[i].menglish << "\t";
//        cout << "������ " << abs->studentarry[i].mscore << "\t";
//        cout << "ѧ�ţ� " << abs->studentarry[i].mid << endl;
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
        cout << "���֣� " << abs.studentarry[i].mname << "\t";
        cout << "�Ա� " << (abs.studentarry[i].msex == 1 ? "��" : "Ů") << "\t";//��Ŀ�����
        cout << "���䣺 " << abs.studentarry[i].mage << "\t";
        cout << "���ģ� " << abs.studentarry[i].mchinese << "\t";
        cout << "��ѧ�� " << abs.studentarry[i].mmath << "\t";
        cout << "Ӣ� " << abs.studentarry[i].menglish << "\t";
        cout << "������ " << abs.studentarry[i].mscore << "\t";
        cout << "ѧ�ţ� " << abs.studentarry[i].mid << endl;
        cout << endl;
    }
    system("pause");
    system("cls");
}
void fail(addressbooks* abs){
     for(int i=0; i<abs->msize;i++){
         if(abs->studentarry[i].mchinese<60 || abs->studentarry[i].mmath<60 ||abs->studentarry[i].menglish<60 ){
             cout << "���֣� " << abs->studentarry[i].mname << "\t";
             cout << "�Ա� " << (abs->studentarry[i].msex == 1 ? "��" : "Ů") << "\t";//��Ŀ�����
             cout << "���䣺 " << abs->studentarry[i].mage << "\t";
             cout << "���ģ� " << abs->studentarry[i].mchinese << "\t";
             cout << "��ѧ�� " << abs->studentarry[i].mmath << "\t";
             cout << "Ӣ� " << abs->studentarry[i].menglish << "\t";
             cout << "������ " << abs->studentarry[i].mscore << "\t";
             cout << "ѧ�ţ� " << abs->studentarry[i].mid << endl;
             cout << endl;
         }
     }
}
void showMenu()
{
    cout << "1�����ѧ��" << endl;
    cout << "2����ʾѧ��" << endl;
    cout << "3��ɾ��ѧ��" << endl;
    cout << "4������ѧ��" << endl;
    cout << "5���޸�ѧ��" << endl;
    cout << "6�����ѧ��" << endl;
    cout << "7������ѧ��" << endl;
    cout << "8�����������ѧ��"<<endl;
    cout << "0���˳�ϵͳ" << endl;
}
int main()
{
    addressbooks abs;//ѧ��¼�ṹ�����
    abs.msize = 0;//��ʼ��ͨѶ¼�е�ǰ��Ա����
    int choise = 0;//�û�ѡ��Ĺ���
    while (true)
    {
        showMenu();
        cin >> choise;
        switch (choise)
        {
            case 1://���ѧ��
                addstudent(&abs);//���õ�ַ���ݣ������޸�ʵ��
                break;
            case 2://��ʾѧ��
                showstudent(&abs);
                break;
            case 3://ɾ��ѧ��
                deletestudent(&abs);
                break;
            case 4://����ѧ��
                findstudent(&abs);
                break;
            case 5://�޸���ϵ��
                modifystudent(&abs);
                break;
            case 6://���ѧ��
                cleanstudent(&abs);
                break;
            case 7:
                rankstudent(abs);
            case 8:
                fail(&abs);
            case 0://�˳�ѧ��¼
                cout << "��ӭ�´�ʹ��" << endl;
                system("pause");
                break;
            default:
                break;
        }
    }

    system("pause");
    return 0;
}