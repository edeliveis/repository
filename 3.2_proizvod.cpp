#include <iostream>
#include <math.h>
#include "proizvod.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Задание №3.2\nНАХОЖДЕНИЕ ПРОИЗВОДНЫХ ТАБЛИЧНО-ЗАДАННОЙ ФУНКЦИИ ПО ФОРМУЛАМ ЧИСЛЕННОГО ДИФФЕРЕНЦИРОВАНИЯ\n";
    cout << "\nВариант #7 (k = 3)\n\n";
   
    double a = 0, h = 0.1;
    size_t m = 10, rows = (m +1), cols = 8, k;

    cout << "Начальные данные: \n";
    cout << "\tФункция f(x) = exp(-x)-x^2/2" << endl;

    do
    {
        cout << "\tВведите значение a: \n\ta = ";
        cin >> a;
        cout << "\tВведите шаг h:\n\th = ";
        cin >> h;
        cout << "\tВведите m:\n\tm = ";
        cin >> m;
        table_row* table = new table_row[m + 1];  //таблица для задания функции

        cout << endl;

        cout << "Табличное задание функции f(x):\n";

        Function_table(a, h, m, table);
        Draw_Function_table(m, table);

        double** mas = new double* [rows];

        for (size_t i = 0; i < rows; ++i)
        {
            mas[i] = new double[cols];
        }

        cout << endl;

        cout << "Таблица со значениями производных f(x):\n";
        proizvod_table(a, h, table, rows, cols, mas);
        draw_proizvod_table(rows, cols, mas);

        for (size_t i = 0; i < rows; ++i)
        {
            delete[] mas[i];
        }

        cout << "Вау) Задача решена! Хотите снова?" << endl;
        cout << "\tЕсли хотите получить решение задачи для других значений x и n, ВВЕДИТЕ 0" << endl;
        cout << "\tДля завершения задачи, ВВЕДИТЕ 1" << endl;
        cin >> k;

        cout << endl;
    } while (k != 1);

}

