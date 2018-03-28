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
		cout << "����� �������?";
		cin >> z;
		if (z == 0)
		{
			break;
		}
		else if (z == 1)
		{
			//1.������������ ������ � ���������� ����� ������������ �����. �������� ���������, ������� ����������, �������� �� ��������� ����� � ���������� (���������� ��������� ������������ �����, � �������� ����� ������ 3 ���� ����� ����� ������ ���� ����). ���� ������������ ���� �� ������������ ����� � ��������� �� ������.
			int chislo, count = 0;
			cout << "������� ������������ �����: ";
			cin >> chislo;
			int pr = chislo;
			while (pr>0)
			{
				pr /= 10;
				count += 1;
			}

			if (count != 6)
			{
				cout << "��������� ����� �� ������������!" << endl;
			}
			else
			{
				HappyNum(&chislo);
			}
		}
		else if (z == 2)
		{
			//2.	������������ ������ �������������� �����. ���������� �������� � ���� ����� 1 � 2 �����, � ����� 3 � 4 �����.  ���� ������������ ������ �� �������������� ����� � ������� ��������� �� ������.
			int chislo, count = 0;
			cout << "������� �������������� �����: ";
			cin >> chislo;
			int pr = chislo;
			while (pr > 0)
			{
				pr /= 10;
				count += 1;
			}
			if (count != 4)
			{
				cout << "��������� ����� �� ��������������!" << endl;
			}
			else
			{
				cout << swap(&chislo) << endl;
			}
		}
		else if (z == 3)
		{
			//3.�������� ��������� ���������� 200$ + ������� �� ������. ������� �� 500$ - 3%, �� 500 �� 1000 � 5%, ����� 1000 � 8%. ������������ ������ � ���������� ������� ������ ��� ���� ����������. ���������� �� ��������, ���������� ������� ���������, ��������� ��� ������ 200$, ������� ����� �� �����.
			int prodazha1, prodazha2, prodazha3, max;
			cout << "������� ������� ������� ���������: ";
			cin >> prodazha1;
			cout << "������� ������� ������� ���������: ";
			cin >> prodazha2;
			cout << "������� ������� �������� ���������: ";
			cin >> prodazha3;
			int zp1 = zarplata1(&prodazha1);
			int zp2 = zarplata2(&prodazha2);
			int zp3 = zarplata3(&prodazha3);
			cout << "�������� ������� ��������� " << zp1 << "\n�������� ������� ��������� " << zp2 << "\n�������� �������� ��������� " << zp3;
			if (zp1 > zp2)
				max = zp1;
			else
				max = zp2;
			if (zp3 > max)
				max = zp3;

			cout << "\n�����: ������ �������� ��������� ������� ��: " << max << " �����";
			max += 200;
			cout << "\n������������ ������� �������� �������� � �������: " << max;
		}
		else if (z == 5)
		{
			//5.	���������� ���������� ����� ����� � ��������� �� 100 �� 999 � ������� ���� ��� ���������� �����

			sameN();

		}
		else if (z == 6)
		{
			//6.	���������� ���������� ����� ����� � ��������� �� 100 �� 999 � ������� ��� ����� ������
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
		cout << "������ ����� ���������e!" << endl;
	else
		cout << "������ ����� �� �������� ����������!" << endl;

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