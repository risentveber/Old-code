#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct algItem
{
	bool openNote;
	bool number;
	char oper;
	double val;
};

int priority(char a)
{
	if (a == '-' || a == '+')
		return 1;
	if (a == '*' || a == '/')
		return 2;
	if (a == '^')
		return 3;
	return 0;
}

struct stack
{
	algItem data;
	stack* next;
};

void push(stack*& base, algItem item)
{
	stack* temp = (stack*)malloc(sizeof(stack));
	temp->data = item;
	temp->next = base;
	base = temp;
}

algItem pop(stack*& base)
{
	algItem tempItem = base->data;
	stack* temp = base->next;
	free(base);
	base = temp;
	return tempItem;
}

void freeStack(stack*& base)
{
	stack* temp;
	while (base != NULL){
		temp = base->next;
		free(base);
		base = temp;
	}
}

void main()
{
	bool error = false;
	bool number = false;
	bool point = false;
	bool unarity;
	bool stop;
	int pointPosition;
	double tempNumber;
	char expr[250];
	int n;
	stack* saver = NULL;
	algItem tempEl;
	algItem note[100];
	int k = 0;

	do
	{
		if (error)//повтор ввода
			puts("invalid input");
		freeStack(saver);
		error = false;
		number = false;
		unarity = true;
		k = 0;
		gets(expr);

		n = 0;
		for(; expr[n] != '\0'; )
			n++;

		if (n == 0)
		{
			error = true ;
			continue;
		}

		for (int i = 0; i < n && !error ; i++) //основной цикл
		{
			if('0' <= expr[i] && expr[i] <= '9'){//цифра
				unarity = false;
				if (number){
					if (point){
						pointPosition++;
						tempNumber += (expr[i] - '0')*pow(10.0, (-pointPosition));
					} else {
						tempNumber *= 10;
						tempNumber += expr[i] - '0';
					}					
				} else {
					number = true;
					point = false;
					tempNumber = expr[i] - '0';
				}
			} else if(expr[i] == '.'){//точка или запятая
				unarity = false;
				if (number && !point){
					pointPosition = 0;
					point = true;
				} else {
					error = true;
					continue;
				}
			} else {

				if (number){
					tempEl.number = true;
					tempEl.openNote = false;
					tempEl.val = tempNumber;					
					note[k] =tempEl;
					k++;
					number = false;
				} 

				
				if(expr[i] == ' '){

				} else if(expr[i] == '-' || expr[i] == '+' || expr[i] == '*' || expr[i] == '/' || expr[i] == '^' ){
					tempEl.number = false;
					tempEl.openNote = false; 
					tempEl.oper = expr[i];
					if (expr[i] == '-' && unarity){
						note[k].number = true;
						note[k].val = 0;
						k++;
					}

					stop = false;
					while (!stop){
						if (saver == NULL){
							push(saver, tempEl);
							stop = true;
						} else {
							if (saver->data.openNote){
								push(saver, tempEl);
								stop = true;
							}else if ((priority(saver->data.oper) >= priority(expr[i]) && expr[i] != '^') || (priority(saver->data.oper) > priority(expr[i]) && expr[i] == '^')){
								note[k] = pop(saver);								 
								k++;
							}else{

								push(saver, tempEl);
								stop = true;
							}
						}
					}
				unarity = false;

				} else if(expr[i] == '('){
					unarity = true;
					tempEl.number = false;
					tempEl.openNote = true; 
					push(saver, tempEl);
				} else if(expr[i] == ')'){//выталкивание до открывающей скобки включительно
					unarity = false;
					stop = false;
					do
					{
						if (saver != NULL){
							if (saver->data.openNote){//убираем открывающую скобу и выходим из цикла
								stop = true;
								pop(saver);
							} else {//выпихиваем операторы в поисках скобы
								tempEl = pop(saver);
								note[k] =tempEl;
								k++;
							}
						} else {//скоба не найдена а стек уже закончился
							error = true;
							stop = true;
						}
					}while (!stop);
					if (error)
						continue;
				} else { 
					error = true;
					continue;
				}
			}
		}

		if (error)
			continue;

		if (number){
					tempEl.number = true;
					tempEl.openNote = false;
					tempEl.val = tempNumber;	
					note[k] =tempEl;
					k++;
					number = false;
				} 

		while (saver != NULL){
			tempEl = pop(saver);
			
			note[k] =tempEl;
			k++;
			if (tempEl.openNote)
				error = true;
		}

		if (error)
			continue;

		for (int i = 0; i < k; i++){
			if (note[i].number){
				printf(" %f", note[i].val);
			} else {
				printf(" %c", note[i].oper);
			}
		}
		printf("\n");

		freeStack(saver);//вычисление по обратной польской нотации
		double x,y;
		for (int i = 0; i<k && !error; i++)
		{
			if (note[i].number)
				push(saver, note[i]);
			else{
				if (saver != NULL){
					tempEl = pop(saver);
					y = tempEl.val;
				}else{
					error = true;
					continue;
				}
				if (saver != NULL){
					tempEl = pop(saver);
					x = tempEl.val;
				}else{
					error = true;
					continue;
				}

				if (note[i].oper == '+')
					tempEl.val = x + y;
				else if (note[i].oper == '-')
					tempEl.val = x - y;
				else if (note[i].oper == '*')
					tempEl.val = x * y;
				else if (note[i].oper == '/'){
					if (y != 0.0)
					tempEl.val = x / y;
					else{
						error = true;
						continue;
					}
				} else  if (note[i].oper == '^')
					tempEl.val = pow(x, y);
				
				
				push(saver, tempEl);
			}
		}
		if (error)
			continue;
		if (saver != NULL){
			tempEl = pop(saver);
			if (saver == NULL)
				printf("%f\n", tempEl.val);
			else
				error = true;
		} else
			error = true;

	}while (error);
	getchar();
}
