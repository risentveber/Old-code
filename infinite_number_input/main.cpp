#include <iostream>
#include <string>
#include <locale>

using namespace std;

int main()
{
	setlocale(LC_ALL,"RUSSIAN");
	int x=0; //itoa()
	bool mistake = false;
	bool step; //текущее значение обработано
	int sum=0;
	int n=0;// количество элементов
	int min, max;
	string s=" ";
	string s2;
	cout << "Введите число если хотите выполнить ввод нового числа" << endl;
	cout << "Введите avg чтобы вывести среднее значение введеных чисел" << endl;
	cout << "Введите sum чтобы вывести сумму введеных чисел" << endl;
	cout << "Введите min чтобы вывести минимальное из введеных чисел" << endl;
	cout << "Введите max чтобы вывести максимальное из введеных чисел" << endl;
	cout << "Введите clear чтобы забыть введеные числа" << endl;
	cout << "Введите q чтобы прекратить ввод" << endl;

	while (s !="q")
	{
		step = false;

		if (mistake) // ошибка была шаг цикла назад
		{
			cout << "Вы ошиблись, повторите ввод" << endl;
			mistake = false;
		};
		cin >> s;

		if (s=="sum")// для вывода суммы чисел соответсвенно
		{
			cout << sum << endl;
			step = true;
		};

		if (s=="q")// обработка символа прекращения ввода
			step = true;

		if (s == "avg") // для вывода среднего арифметического
	    {
			if (n != 0)
			{
				cout << sum/(n + 0.0) << endl;

			}
			else
				cout << "Вывод среднего значения невозможен: массив пуст" << endl;
			step = true;
		};

		if (s == "min")// для вывода минимального
	    {
			if ( n == 0)
				cout << "Вывод минимального элемента невозможен: массив пуст" << endl;
			else
				cout << min << endl;
			step = true;
		};

		if (s=="max")// для вывода максимального
	    {
			if (n==0)
				cout << "Вывод максимального элемента невозможен: массив пуст" << endl;
			else
				cout << max << endl;
			step = true;
		};

		if (s=="clear") // для вывода среднего арифметического
	    {
			n = 0;
			sum = 0;

			step = true;
		};
		if (!step)
		{
			x = atoi(s.c_str());
			char tmp[100];
			_itoa( x, tmp, 10 );
			s2 = tmp;
			if (s == s2 ) // если введенная строка является числом таким же как и полученное с
				          // помощью функции  atoi х то ввод правилен и введено х
			{
				if (n == 0)  // если элементы раннее не вводились
				{
					min = x;
					max = x;
				}
				else  // если элементы раньше были
				{
					if (x < min)
						min = x;
					if (x > max)
						max = x;
				};

				sum += x;  //изменяем соответственно информацию о всех введеных числах
				++n;

			}
			else // если ввод ошибочен поднимаем флаг ошибки
				mistake = true;
		};



	};
	system("pause");

	return 0;
}
