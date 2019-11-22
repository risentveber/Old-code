#ifndef MATRIX
#define MATRIX

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
	

class matrix{
private:
	int height; //y
	int width;  //x
	float** line; // ������ �����

public:
	void input();//���� �������

	void output() const;//����� �������

	void empty();//��������� �������

	bool empty_check() const;

	bool square() const;//�������� �� ������� ����������

	float determinate() const;//���������� ������������

	const matrix& operator=(const matrix&);//����������� ����������
	
	matrix operator+(const matrix&) const;//����������� ��������

	matrix operator*(const matrix&) const;//����������� ��������� ������ �� �������

	matrix operator*(const int) const;//����������� ��������� ������ �� �����

	/*friend matrix operator*(const int, const matrix&);*///����� �� �������

	matrix(const matrix&);//����������� �����������

	matrix(){//����������� �����������
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