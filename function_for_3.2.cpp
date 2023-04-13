#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

struct table_row     //структура в которой храниться точка и значение функции в этой точке
{
    double point; //точка
    double value; //значение функции в этой точке
};

double f(double x) //функция, данная в условии задачи
{
    return (exp(1.5 * 3 * x));
    /*return(x*x*x - 5*x*x);*/
}

double ff(double x) //поизвод
{
    return ((9 * exp( 4.5 * x)) / 2);
}

double fff(double x) //вторая производ
{
    return ((81 * exp(4.5 * x)) / 4);
}

void Function_table(double a, double h, size_t m, table_row* table)   //заполнение таблицы значений
{
    for (size_t k = 0; k <= m; ++k)
    {
        table[k].point = a + h * k;
        table[k].value = f(table[k].point);
    }
}

void Draw_Function_table(size_t m, table_row* table)   //вывод таблицы значений
{
    cout << " _______________________________" << endl;
    cout << "|             |                 |" << endl;
    cout << "| x_k\t" << "      | f(x_k)\t        |" << endl;
    cout << "|_____________|_________________|" << endl;

    for (size_t k = 0; k <= m; ++k)
    {
        cout << "|  " << fixed << table[k].point << "   | " << fixed << table[k].value << "\t|" << endl;
        cout << "|_____________|_________________|" << endl;
    }
}

void proizvod_table(double a, double h, table_row* table, size_t rows, size_t cols, double** mas)
{
    mas[0][0] = table[0].point;
    mas[0][1] = table[0].value;
    mas[0][2] = (-3 * table[0].value + 4 * table[1].value - table[2].value) / (2 * h);
    mas[0][3] = abs(ff(table[0].point) - mas[0][2]);;
    mas[0][4] = 0;
    mas[0][5] = 0;
    mas[0][6] = 0;
    mas[0][7] = 0;

    for (size_t i = 1; i < rows - 1; ++i)
    {
        mas[i][0] = table[i].point;
        mas[i][1] = table[i].value;
        mas[i][2] = (table[i + 1].value - table[i - 1].value) / (2 * h);
        mas[i][3] = abs(ff(table[i].point) - mas[i][2]);
        mas[i][4] = mas[i][3] / abs(mas[i][2]);
        mas[i][5] = (table[i + 1].value - 2 * table[i].value + table[i - 1].value) / (h * h);
        mas[i][6] = abs(fff(table[i].point) - mas[i][5]);
        mas[i][7] = mas[i][6] / abs(mas[i][5]);
    }

    mas[rows - 1][0] = table[rows - 1].point;
    mas[rows - 1][1] = table[rows - 1].value;
    mas[rows - 1][2] = (3 * table[rows - 1].value - 4 * table[rows - 2].value + table[rows - 3].value) / (2 * h);
    mas[rows - 1][3] = abs(ff(table[rows - 1].point) - mas[rows - 1][2]);;
    mas[rows - 1][4] = 0;
    mas[rows - 1][5] = 0;
    mas[rows - 1][6] = 0;
    mas[rows - 1][7] = 0;

}

void draw_proizvod_table(size_t rows, size_t cols, double** mas)
{
    cout << "_________________________________________________________________________________________________________________________________" << endl;
    cout << "                |               |               |               |               |               |               |               |" << endl;
    cout << " x_i            | f(x_i)        | f'_чд         | |f'т - f'_чд| | относ. погреш.| f''_чд        ||f''т - f''_чд|| относ. погреш.|" << endl;

    for (size_t i = 0; i < rows; ++i)
    {
        cout << "________________|_______________|_______________|_______________|_______________|_______________|_______________|_______________|" << endl;
        for (size_t j = 0; j < cols; ++j)
        {
            cout << mas[i][j] << "\t|";
        }
        cout << endl;
    }
    cout << "________________|_______________|_______________|_______________|_______________|_______________|_______________|_______________|" << endl;

}