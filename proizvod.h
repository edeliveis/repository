#pragma once
#include <iostream>
#include <math.h>


using namespace std;

struct table_row     //��������� � ������� ��������� ����� � �������� ������� � ���� �����
{
    double point; //�����
    double value; //�������� ������� � ���� �����
};

double f(double x); //�������, ������ � ������� ������

double ff(double x); //�������

double fff(double x); //������ ��������

void Function_table(double a, double b, size_t m, table_row* table);   //���������� ������� ��������

void Draw_Function_table(size_t m, table_row* table);  //����� ������� ��������

void proizvod_table(double a, double h, table_row* table, size_t rows, size_t cols, double** mas);

void draw_proizvod_table(size_t rows, size_t cols, double** mas);