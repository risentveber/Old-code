#include "matrix.h"


matrix::matrix(const matrix& matrix_2){
	width = 0;
	height = 0;
	line = NULL;
	operator=(matrix_2);//можно улучшить!!!
};

void matrix::input(){//создание матрицы
		puts("Please input the height and the width");
		std::cin >> height >> width;
		puts("Please input the elements");
		line = (float**)calloc(height, sizeof(float*));//создание массива строк

		for(int y = 0; y < height; y++){//заполнение каждой строки
			line[y] = (float*)calloc(width, sizeof(float));//создание 

			for(int x = 0; x < width; x++){ //пор€дoк х, y обратный
				std::cin >> line[y][x];//поэлементное заполнение
			}
		}										
	};

bool matrix::square() const {
	if ((width == height)&&(empty_check()))
		return true;
	else
		return false;
}

void matrix::output() const {//вывод матрицы
		if ((width == 0)||(height == 0))
			puts("matrix is empty");
		else{
			for(int y = 0; y < height; y++){
				for(int x = 0; x < width; x++){ //пор€дoк х, y обратный!!!!
					printf("%10f", line[y][x]);
				}
				printf("\n");
			}
		}
	};

void matrix::empty(){//опустошение матрицы
		for(int y = 0; y < height; y++){
			free(line[y]);
		}
		free(line);
		height = 0;
		width = 0;
		line = NULL;
	}

bool matrix::empty_check() const{
	if ((height > 0)&&(width > 0)&&(line != NULL))
		return true;
	else
		return false;
}

float matrix::determinate() const {
		float result = 1;
	
		int n = height;

		matrix matrix_temp;
		matrix_temp.width = n;
		matrix_temp.height = n;
		matrix_temp.line = (float**)calloc(n, sizeof(float*));

		for(int y = 0; y < n; y++){
			matrix_temp.line[y] = (float*)calloc(n, sizeof(float));

			for(int x = 0; x < n; x++){ //пор€дoк х, y обратный!!!!
				matrix_temp.line[y][x] = line[y][x] ;
			}
		}
	
		
		float factor = 1;
		int k = 1;

		for(int y = 0; y < n - 1; y++){// приведение матрицы к диагональному виду y - Ќќћ≈– ƒ»ј√ќЌјЋ№Ќќ√ ЁЋ≈ћ≈Ќ“ј
			k = 1;
			if (matrix_temp.line[y][y] == 0){
				k = -1;
				for(int i = y + 1; i < n; i++){
					if (matrix_temp.line[i][y] != 0){
						k = i;
						i = n;
					}
				}

				if (k == -1){// действи€ согласно выбору: есть соответствующа€ ненулева€ строчка или нет.
					result = 0;
					n = 0;
				}else{
						std::swap(matrix_temp.line[y],matrix_temp.line[k]);		
						result *= -1;
				}
			}// поиск ненулевой строчки

			for(int i = y + 1; i < n; i++){
				factor = matrix_temp.line[i][y] / matrix_temp.line[y][y];
				for(int m = y; m < n; m++){
					matrix_temp.line[i][m] -= matrix_temp.line[y][m] * factor;
				}
			}	
		
		}

		for(int i = 0; i < n; i++){//вычисление определител€
			result *= matrix_temp.line[i][i];
		}

		return result;		
	}

const matrix& matrix::operator=(const matrix& matrix_2){
		empty();
		height = matrix_2.height;
		width = matrix_2.width;
		line = (float**)calloc(height, sizeof(float*));

		for(int y = 0; y < height; y++){
			line[y] = (float*)calloc(width, sizeof(float));

			for(int x = 0; x < width; x++){ //пор€дoк х, y обратный!!!!
				line[y][x] = matrix_2.line[y][x];
			}
		}
		return matrix_2;
	};

matrix matrix::operator+(const matrix& matrix_2) const{
	matrix temp;
	if ((height == matrix_2.height)&&(width == matrix_2.width)&&(empty_check())&&(matrix_2.empty_check())){
		temp.height = height;
		temp.width = width;
		temp.line = (float**)calloc(height, sizeof(float*));
		for(int y = 0; y < height; y++){
			temp.line[y] = (float*)calloc(width, sizeof(float));
			for(int x = 0; x < width; x++)
				temp.line[y][x] = line[y][x] + matrix_2.line[y][x];
		}

	}
	return temp;
};

matrix matrix::operator*(const int t) const{
	matrix temp = *this;
	for(int y = 0; y < height; y++)
		for(int x = 0; x < width; x++)
			temp.line[y][x] *= t;
	return temp;
};

matrix operator*(const int t, const matrix& matrix_2) {
	return matrix_2 * t;
}

matrix matrix::operator*(const matrix& matrix_2) const{
	matrix temp;
	if ((width == matrix_2.height)&&(empty_check())) {
		temp.height = height;
		temp.width = matrix_2.width;
		temp.line = (float**)calloc(height, sizeof(float*));
		float stroke;
		for(int y = 0; y < temp.height; y++){
			temp.line[y] = (float*)calloc(temp.width, sizeof(float));
			for(int x = 0; x < temp.width; x++){
				stroke = 0;
				for(int i = 0; i < width; i++){
					stroke += line[y][i] * matrix_2.line[i][x];
				}
				temp.line[y][x] = stroke;
			}		
		}
	}
	return temp;
};
