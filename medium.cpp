/*Создайте динамический двумерный массив и заполните его
случайными  числами от 10 до 50. Вывести его в консоль.
Для напоплнения и визуализации необходимо написать отдельные функции*/

#include<iostream>
#include<ctime>
using namespace std;
void init_ar(int**a , int n, int m)
{
	int i, j;
	srand(time(NULL));
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			a[i][j] = rand() % 41 + 10;
	
}
void print_ar(int**a, int n, int m)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
			cout << a[i][j]<<" ";
		cout << "\n";
	}
}

int main()
{
	int n, m, i;
	cout << "line n = ";
	cin >> n;
	cout << "column m = ";
	cin >> m;
	int** a = new int*[n];
	for (i = 0; i < n; i++)
		a[i] = new int[m];
	init_ar(a, n, m);
	print_ar(a, n, m);
	delete[] a;



}