#include <iostream>
#include <cstdio>
#include<fstream>
#include<string.h>
#include <cstdlib>
#include <time.h>
#include<iomanip>
using namespace std;
struct data
{
    int num[114514];
    float num1[114514];
}datascript[500];

void havebrackets(int NUM, int MaxNUM, int Num, int File, char Operator[], int decimal)       //�����ź���
{
    int sign1 = 0, sign2 = 0;
    int k1, k2, random, i, j, len;
    len = strlen(Operator);
    ofstream outfile;
    outfile.open("E:\\file.txt");
    for (i = 0; i < NUM; i++)
    {
        k1 = -1;                         //kΪ������������λ��
        k2 = -1;
        while (1)
        {
            if (k1 > k2 || k2 - k1<2 || k2>Num)
            {
                k1 = int(rand() % (Num - 1));
                k2 = int(rand() % (Num - 1));
            }
            else
                break;
        }
        for (j = 0; j < Num; j++)
        {
            random = int(rand() % len);
            if (decimal == 1)
            {
                datascript[i].num[j] = rand() % MaxNUM + 1;        //�������������������ֵ������
                datascript[i].num[j + 1] = rand() % MaxNUM + 1;
            }
            if (decimal == 0)
            {
                datascript[i].num1[j] = rand() % MaxNUM/1.0200000; //�������������������ֵ��С��
                datascript[i].num1[j + 1] = rand() % MaxNUM /1.0200000;
            }
            if (j < Num - 1)
            {
                if (j == k1)                         //�������±����k1��������������
                {
                    if (decimal == 1)
                    {
                        cout << "(" << datascript[i].num[j] << " " << Operator[random] << " ";
                        sign1 = 1;
                        if (File == 1)
                            outfile << "(" << datascript[i].num[j] << " " << Operator[random] << " ";
                    }
                    else
                    {
                        cout << "(" << setprecision(1) << std::fixed << datascript[i].num1[j] << " " << Operator[random] << " ";
                        sign1 = 1;
                        if (File == 1)
                            outfile << "(" << setprecision(1) << std::fixed << datascript[i].num1[j] << " " << Operator[random] << " ";
                    }
                }
                else if (j == k2)                        //�������±����k2��������Ұ�����
                {
                    if (decimal == 1)
                    {
                        cout << datascript[i].num[j] << ")" << " " << Operator[random] << " ";
                        sign2 = 1;
                        if (File == 1)
                            outfile << datascript[i].num[j] << ")" << " " << Operator[random] << " ";
                    }
                    else
                    {
                        cout << setprecision(1) << std::fixed << datascript[i].num1[j] << ")" << " " << Operator[random] << " ";
                        sign2 = 1;
                        if (File == 1)
                            outfile << setprecision(1) << std::fixed << datascript[i].num1[j] << ")" << " " << Operator[random] << " ";
                    }
                }
                else
                {
                    if (decimal == 1)
                    {
                        cout << datascript[i].num[j] << " " << Operator[random] << " ";
                        if (File == 1)
                            outfile << datascript[i].num[j] << " " << Operator[random] << " ";
                    }
                    else
                    {
                        cout << setprecision(1) << std::fixed << datascript[i].num1[j] << " " << Operator[random] << " ";
                        if (File == 1)
                            outfile << setprecision(1) << std::fixed << datascript[i].num1[j] << " " << Operator[random] << " ";
                    }
                }
            }
            else
            {
                if (sign1 == 1 && sign2 == 0)
                {
                    if (decimal == 1)
                    {
                        cout << datascript[i].num[j] << ")" << " ";
                        if (File == 1)
                            outfile << datascript[i].num[j] << ")" << " ";
                    }
                    else
                    {
                        cout << setprecision(1) << std::fixed << datascript[i].num1[j] << ')';
                        if (File == 1)
                            outfile << setprecision(1) << std::fixed << datascript[i].num1[j] << ')';
                    }
                }
                else
                {
                    if (decimal == 1)
                    {
                        cout << datascript[i].num[j] << " ";
                        if (File == 1)
                            outfile << datascript[i].num[j] << " ";
                    }
                    else
                    {
                        cout << setprecision(1) << std::fixed << datascript[i].num1[j];
                        if (File == 1)
                            outfile << setprecision(1) << std::fixed << datascript[i].num1[j];
                    }
                }
            }
        }
        cout << "= " << "\n";
        if (File == 1)
            outfile << "= " << "\n";
    }
    outfile.close();
}

void nobrackets(int NUM, int MaxNUM, int Num, int File, char Operator[], int decimal)      //�����ź���
{
    int i, j, len, random;
    len = strlen(Operator);

    ofstream outfile;
    outfile.open("E:\\file.txt");
    for (i = 0; i < NUM; i++)
    {
        for (j = 0; j < Num; j++)
        {
            random = int(rand() % len);
            if (decimal == 1)
            {
                datascript[i].num[j] = rand() % MaxNUM + 1;            //���ز��������ֵ���������
                datascript[i].num[j + 1] = rand() % MaxNUM + 1;
            }
            if (decimal == 0)
            {
                datascript[i].num1[j] = rand() % MaxNUM /1.020000;    //���ز��������ֵ�����С�� �������Ǳ���һλС��ʱ������
                datascript[i].num1[j + 1] = rand() % MaxNUM/1.020000;
            }
            if (j < Num - 1)
            {
                if (decimal == 1)
                {
                    cout << datascript[i].num[j] << " " << Operator[random] << " ";
                    if (File == 1)
                        outfile << datascript[i].num[j] << " " << Operator[random] << " ";
                }
                else
                {
                    cout << setprecision(1) << std::fixed << datascript[i].num1[j] << " " << Operator[random] << " ";
                    if (File == 1)
                        outfile << setprecision(1) << std::fixed << datascript[i].num1[j] << " " << Operator[random] << " ";
                }
            }
            if (j == Num - 1)
            {
                if (decimal == 1)
                {
                    cout << datascript[i].num[j] << " ";
                    if (File == 1)
                        outfile << datascript[i].num[j] << " ";
                }
                else
                {
                    cout << setprecision(1) << std::fixed << datascript[i].num1[j];
                    if (File == 1)
                        outfile << setprecision(1) << std::fixed << datascript[i].num1[j];
                }
            }
        }
        cout << "=  " << "\n";
        if (File == 1)
            outfile << "=  " << "\n";
    }
    outfile.close();
}
int main()
{
    int NUM, Num, MaxNUM;
    int brackets, File, decimal;
    char Operator[5];
    cout << "                                 **********************************************************\n";
    cout << "                                 *                 ���������Զ�������                     *\n";
    cout << "                                 **********************************************************\n";

    cout << "�������������������ʽ��";
    cin >> NUM;

    cout << "�����������������ֵ: ";
    cin >> MaxNUM;
    cout << "�������ţ���1���������š�0���������ţ�: ";
    cin >> brackets;
    cout << "�Ƿ񽫽���浽�ļ��У���1�����ǡ�0�����: ";
    cin >> File;
    cout << "�������ʽ��С��������������1����������0����С������";
    cin >> decimal;
    cout << "��������������+��-��*��/����";
    cin >> Operator;
    Num = -1;
    cout << "********************************************\n";
    while (1)
    {
        if (Num < 2 || Num>8)
            Num = int(rand() % 10);      //����ÿ�����ʽ�ж��ٸ����������ʵ��,����0~9֮���һ���������
        else
            break;
    }
    if (brackets == 1)
    {
        havebrackets(NUM, MaxNUM, Num, File, Operator, decimal);
    }
    else if (brackets == 0)
    {
        nobrackets(NUM, MaxNUM, Num, File, Operator, decimal);
    }
    cout << "********************************************\n";
    system("pause");
    return 0;
}