#include <stdio.h>
#include <stdlib.h>
#include <clocale>
#include <iostream>


using namespace std;

struct matrix
{
    int height; //y
    int width;  //x
    float** line;
};

const matrix matrix000 = { 0, 0, NULL};

matrix* create()
{
    int height;
    int width;
    puts("Пожалуйста введите высоту и ширину матрицы");
    cin >> height >> width;
    puts("Введите последовательно элементы матрицы");
    matrix* result = (matrix*)calloc(1, sizeof(matrix));
    result->height = height;
    result->width = width;
    result->line = (float**)calloc(height, sizeof(float*));

    for(int y = 0; y < height; y++)
    {
        result->line[y] = (float*)calloc(width, sizeof(float));

        for(int x = 0; x < result->width; x++) //порядoк х, y обратный!!!!
        {
            cin >> result->line[y][x];
        }
    }

    return result;
};

int dispose(matrix* matrix)
{
    for( int y = 0; y < matrix->height; y++)
    {
        free(matrix->line[y]);
    }
    free(matrix->line);
    free(matrix);
    return 0;
};

float determinate(matrix matrix1)
{
    float result = 1;

    int n = matrix1.height;
    matrix* matrix_temp = (matrix*)calloc(1, sizeof(matrix));
    matrix_temp->height = n;
    matrix_temp->width = n;
    matrix_temp->line = (float**)calloc(n, sizeof(float*));

    for(int y = 1; y <= n; y++)
    {
        matrix_temp->line[y-1] = (float*)calloc(n, sizeof(float));

        for(int x = 1; x <= matrix_temp->width; x++) //порядoк х, y обратный!!!!
        {
            matrix_temp->line[y-1][x-1] = matrix1.line[y-1][x-1] ;
        }
    }// создание временной матрицы matrix temp

    float factor = 1;
    int k = 1;

    for(int y = 0; y < n - 1; y++)// приведение матрицы к диагональному виду y - НОМЕР ДИАГОНАЛЬНОГ ЭЛЕМЕНТА
    {
        k = 1;
        if (matrix_temp->line[y][y] == 0)
        {
            k = -1;
            for(int i = y + 1; i < n; i++)
            {
                if (matrix_temp->line[i][y] != 0)
                {
                    k = i;
                    i = n;
                }
            }

            if (k == -1)// действия согласно выбору: есть соответствующая ненулевая строчка или нет.
            {
                result = 0;
                n = 0;
            }
            else
            {
                swap(matrix_temp->line[y],matrix_temp->line[k]);
                result *= -1;
            }
        }// поиск ненулевой строчки

        for(int i = y + 1; i < n; i++)
        {
            factor = matrix_temp->line[i][y] / matrix_temp->line[y][y];
            for(int m = y; m < n; m++)
            {
                matrix_temp->line[i][m] -= matrix_temp->line[y][m] * factor;
            }
        }



    }

    for(int i = 0; i < n; i++)
    {
        result *= matrix_temp->line[i][i];
    }//вычисление определителя

    dispose(matrix_temp);
    return result;
};

int print(matrix matrix1)
{
    if (matrix1.line != NULL)
    {
        for(int y = 0; y < matrix1.height; y++)
        {
            for(int x = 0; x < matrix1.width; x++) //порядoк х, y обратный!!!!
            {
                printf("%10f", matrix1.line[y][x]);
            }
            printf("\n");
        }

    }

    return 0;
};

matrix* sum(matrix matrix1, matrix matrix2)/*Возвращает указатель на матрицу суммы в случае невозможности суммировать возвращает пустую матрицу константу*/
{
    matrix* result = (matrix*)calloc(1, sizeof(matrix));

    if ((matrix1.width == matrix2.width) && (matrix1.height == matrix2.height))// Возможно дополнительное условие != 0
    {
        result->width = matrix1.width;// ининциализация непустой матрицы
        result->height = matrix1.height;
        result->line = (float**)calloc(result->height, sizeof(float*));

        for(int y = 0; y < result->height; y++)
        {
            result->line[y] = (float*)calloc(result->width, sizeof(float));

            for(int x = 0; x < result->width; x++) //порядoк х, y обратный!!!!
            {
                result->line[y][x] = matrix1.line[y][x] + matrix2.line[y][x];
            }
        }
        puts("Сумма матриц");
    }
    else
    {
        *result = matrix000;
        puts("Сумма матриц невозможна");
    }


    return result;
};

void product(matrix matrix1, matrix matrix2)
{
    matrix* result = (matrix*)calloc(1, sizeof(matrix));
    *result = matrix000;
    float stroke;
    if (matrix1.width == matrix2.height)
    {
        result->height = matrix1.height;
        result->width = matrix2.width;
        result->line = (float**)calloc(matrix1.height, sizeof(float*));
        for(int y = 0; y < matrix1.height; y++)
        {
            result->line[y] = (float*)calloc(matrix2.width, sizeof(float));
            for(int x = 0; x < matrix2.width; x++)
            {
                stroke = 0;
                for(int i = 0; i < matrix1.width; i++)
                {
                    stroke += matrix1.line[y][i] * matrix2.line[i][x];
                }
                result->line[y][x] = stroke;
            }
        }
        puts("Произведение матриц равно:");
        print(*result);
    }
    else
        puts("Произведение матриц невозможно.");
};


int main()
{
    setlocale(LC_ALL, "RUSSIAN");
    puts("Ввод первой матрицы");
    matrix* example1 = create();
    puts("Ввод второй матрицы");
    matrix* example2 = create();
    float d;

    if (example1->height == example1->width)
    {
        d = determinate(*example1);
        puts("Определитель первой матрицы");
        printf("%f\n", d);
    }
    else
    {
        puts("Первая матрица не является квадратной - вычисление определителя невозможно.");
    }

    if (example2->height == example2->width)
    {
        d = determinate(*example2);
        puts("Определитель второй матрицы");
        printf("%f\n", d);
    }
    else
    {
        puts("Вторая матрица не является квадратной - вычисление определителя невозможно.");
    }

    product(*example1, *example2);
    matrix* sumresult = sum(*example1, *example2);
    print(*sumresult);


    dispose(example1);
    dispose(example2);
    dispose(sumresult);
}
