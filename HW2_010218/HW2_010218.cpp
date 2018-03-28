#include<iostream>
#include<stdio.h>
using namespace std;
unsigned short int z;
void HappyNum(int *chislo);
int swap(int *ch);
int zarplata1(int *prodazha);
int zarplata2(int *prodazha);
int zarplata3(int *prodazha);
void sameN();
void main() {
	setlocale(LC_ALL, "ru");
	while (true)
	{
		cout << "Какое задание?";
		cin >> z;
		if (z == 0)
		{
			break;
		}
		else if (z == 1)
		{
			//1.Пользователь вводит с клавиатуры целое шестизначное число. Написать программу, которая определяет, является ли введенное число – счастливым (Счастливым считается шестизначное число, у которого сумма первых 3 цифр равна сумме вторых трех цифр). Если пользователь ввел не шестизначное число – сообщение об ошибке.
			int chislo, count = 0;
			cout << "Введите шестизначное число: ";
			cin >> chislo;
			int pr = chislo;
			while (pr>0)
			{
				pr /= 10;
				count += 1;
			}

			if (count != 6)
			{
				cout << "Введенное число не шестизначное!" << endl;
			}
			else
			{
				HappyNum(&chislo);
			}
		}
		else if (z == 2)
		{
			//2.	Пользователь вводит четырехзначное число. Необходимо поменять в этом числе 1 и 2 цифры, а также 3 и 4 цифры.  Если пользователь вводит не четырехзначное число – вывести сообщение об ошибке.
			int chislo, count = 0;
			cout << "Введите четырехзначное число: ";
			cin >> chislo;
			int pr = chislo;
			while (pr > 0)
			{
				pr /= 10;
				count += 1;
			}
			if (count != 4)
			{
				cout << "Введенное число не четырехзначное!" << endl;
			}
			else
			{
				cout << swap(&chislo) << endl;
			}
		}
		else if (z == 3)
		{
			//3.Зарплата менеджера составляет 200$ + процент от продаж. продажи до 500$ - 3%, от 500 до 1000 – 5%, свыше 1000 – 8%. Пользователь вводит с клавиатуры уровень продаж для трех менеджеров. Определить их зарплату, определить лучшего менеджера, начислить ему премию 200$, вывести итоги на экран.
			int prodazha1, prodazha2, prodazha3, max;
			cout << "введите продажу первого менеджера: ";
			cin >> prodazha1;
			cout << "введите продажу второго менеджера: ";
			cin >> prodazha2;
			cout << "введите продажу третьего менеджера: ";
			cin >> prodazha3;
			int zp1 = zarplata1(&prodazha1);
			int zp2 = zarplata2(&prodazha2);
			int zp3 = zarplata3(&prodazha3);
			cout << "зарплата первого менеджера " << zp1 << "\nзарплата второго менеджера " << zp2 << "\nзарплата третьего менеджера " << zp3;
			if (zp1 > zp2)
				max = zp1;
			else
				max = zp2;
			if (zp3 > max)
				max = zp3;

			cout << "\nИтоги: лучший менеджер сделавший продажу на: " << max << " сумму";
			max += 200;
			cout << "\nНаграждается премией получает зарплату в размере: " << max;
		}
		else if (z == 5)
		{
			//5.	Подсчитать количество целых чисел в диапазоне от 100 до 999 у которых есть две одинаковые цифры

			sameN();

		}
		else if (z == 6)
		{
			//6.	Подсчитать количество целых чисел в диапазоне от 100 до 999 у которых все цифры разные
			int r1, r2, r3, count = 0;
			for (int i = 100; i <= 999; i++) {

				r1 = i / 100;
				r2 = (i % 100) / 10;
				r3 = i % 10;

				if (r1 == r2 && r1 == r3 && r2 == r3)
				{
					count += 1;
				}
			}
			cout << count << endl;
		}
	}
	system("pause");
}

void HappyNum(int *chislo)
{
	int sumF = 0, sumS = 0, first, second;
	first = *chislo / 1000;
	second = *chislo % 1000;
	while (first > 0)
	{
		sumF = sumF + first % 10;
		first /= 10;
	}
	while (second > 0)
	{
		sumS = sumS + second % 10;
		second /= 10;
	}
	if (sumF == sumS)
		cout << "Данное число счастливоe!" << endl;
	else
		cout << "Данное число НЕ является счастливым!" << endl;

}
int swap(int *ch)
{
	int first, second, third, fourth, newN;
	first = *ch / 1000;
	second = (*ch / 100) % 10;
	third = (*ch % 100) / 10;
	fourth = *ch % 10;
	return newN = (((second * 1000) + (first * 100)) + fourth * 10) + third;

}
int zarplata1(int *prodazha)
{
	int zar;
	if (*prodazha < 500)
		zar = 200 + (*prodazha * 3) / 100;
	if (*prodazha>500 && *prodazha<1000)
		zar = 200 + (*prodazha * 5) / 100;
	if (*prodazha>1000)
		zar = 200 + (*prodazha * 8) / 100;
	return zar;
}

int zarplata2(int *prodazha)
{
	int zar2;
	if (*prodazha < 500)
		zar2 = 200 + (*prodazha * 3) / 100;
	if (*prodazha>500 && *prodazha<1000)
		zar2 = 200 + (*prodazha * 5) / 100;
	if (*prodazha>1000)
		zar2 = 200 + (*prodazha * 8) / 100;
	return zar2;
}
int zarplata3(int *prodazha)
{
	int zarplata;
	if (*prodazha < 500)
		zarplata = 200 + (*prodazha * 3) / 100;
	if (*prodazha>500 && *prodazha<1000)
		zarplata = 200 + (*prodazha * 5) / 100;
	if (*prodazha>1000)
		zarplata = 200 + (*prodazha * 8) / 100;
	return zarplata;
}
void sameN()
{
	int r1, r2, r3, count = 0;
	for (int i = 100; i <= 999; i++) {

		r1 = i / 100;
		r2 = (i % 100) / 10;
		r3 = i % 10;

		if (r1 == r2 || r1 == r3 || r2 == r3)
		{
			count += 1;
		}
	}
	cout << count << endl;
}