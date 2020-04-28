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

void havebrackets(int NUM, int MaxNUM, int Num, int File, char Operator[], int decimal)       //带括号函数
{
    int sign1 = 0, sign2 = 0;
    int k1, k2, random, i, j, len;
    len = strlen(Operator);
    ofstream outfile;
    outfile.open("E:\\file.txt");
    for (i = 0; i < NUM; i++)
    {
        k1 = -1;                         //k为左括号右括号位置
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
                datascript[i].num[j] = rand() % MaxNUM + 1;        //随机输出不大于最大整数值的整数
                datascript[i].num[j + 1] = rand() % MaxNUM + 1;
            }
            if (decimal == 0)
            {
                datascript[i].num1[j] = rand() % MaxNUM/1.0200000; //随机输出不大于最大整数值的小数
                datascript[i].num1[j + 1] = rand() % MaxNUM /1.0200000;
            }
            if (j < Num - 1)
            {
                if (j == k1)                         //若数组下标等于k1，则输出左半括号
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
                else if (j == k2)                        //若数组下标等于k2，则输出右半括号
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

void nobrackets(int NUM, int MaxNUM, int Num, int File, char Operator[], int decimal)      //无括号函数
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
                datascript[i].num[j] = rand() % MaxNUM + 1;            //返回不大于最大值的随机整数
                datascript[i].num[j + 1] = rand() % MaxNUM + 1;
            }
            if (decimal == 0)
            {
                datascript[i].num1[j] = rand() % MaxNUM /1.020000;    //返回不大于最大值的随机小数 ，有误差但是保留一位小数时候误差不计
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
    cout << "                                 *                 四则运算自动生成器                     *\n";
    cout << "                                 **********************************************************\n";

    cout << "您想输入多少组运算表达式：";
    cin >> NUM;

    cout << "请输入运算数的最大值: ";
    cin >> MaxNUM;
    cout << "有无括号？（1代表有括号、0代表无括号）: ";
    cin >> brackets;
    cout << "是否将结果存到文件中？（1代表是、0代表否）: ";
    cin >> File;
    cout << "算术表达式是小数还是整数？（1代表整数、0代表小数）：";
    cin >> decimal;
    cout << "请输入的运算符（+、-、*、/）：";
    cin >> Operator;
    Num = -1;
    cout << "********************************************\n";
    while (1)
    {
        if (Num < 2 || Num>8)
            Num = int(rand() % 10);      //定义每个表达式有多少个参与运算的实数,返回0~9之间的一个随机整数
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