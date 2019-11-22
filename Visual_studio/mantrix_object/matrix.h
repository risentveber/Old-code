#ifndef MATRIX
#define MATRIX

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
	

class matrix{
private:
	int height; //y
	int width;  //x
	float** line; // массив строк

public:
	void input();//ввод матрицы

	void output() const;//вывод матрицы

	void empty();//обнуление матрицы

	bool empty_check() const;

	bool square() const;//является ли матрица квадратной

	float determinate() const;//вычисление детерминанта

	const matrix& operator=(const matrix&);//определение присвоения
	
	matrix operator+(const matrix&) const;//определение сложения

	matrix operator*(const matrix&) const;//определение умножения матриц на матрицы

	matrix operator*(const int) const;//определение умножения матриц на число

	/*friend matrix operator*(const int, const matrix&);*///числа на матрицу

	matrix(const matrix&);//конструктор копирования

	matrix(){//стандартный конструктор
		height = 0;
		width = 0;
		line = NULL;
	};
	
	~matrix(){
		for(int y = 0; y < height; y++){
			free(line[y]);
		}
		free(line);	
	};
	
};

#endif