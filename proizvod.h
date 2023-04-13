#pragma once
#include <iostream>
#include <math.h>


using namespace std;

struct table_row     //структура в которой храниться точка и значение функции в этой точке
{
    double point; //точка
    double value; //значение функции в этой точке
};

double f(double x); //функция, данная в условии задачи

double ff(double x); //поизвод

double fff(double x); //вторая производ

void Function_table(double a, double b, size_t m, table_row* table);   //заполнение таблицы значений

void Draw_Function_table(size_t m, table_row* table);  //вывод таблицы значений

void proizvod_table(double a, double h, table_row* table, size_t rows, size_t cols, double** mas);

void draw_proizvod_table(size_t rows, size_t cols, double** mas);