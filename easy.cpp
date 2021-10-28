//реализовать игру "жизнь"
#include<iostream>
#include<ctime>
using namespace std;
void init_ar(int** a, int N)
{
	int i, j;
	srand(time(NULL));
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			a[i][j] = rand() % 2;

}
void print_ar(int** a, int N)
{
	int i, j;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
			cout << a[i][j] << " ";
		cout << "\n";
	}
}
void live(int** a, int N, int i, int j)
{
	int count = 0;
	//для a[i-1][j-1] - левый верхний сосед
	if (((i - 1) < 0 && (j - 1) < 0) || ((i - 1) < 0 && (j - 1) >= 0))
	{
		if ((i - 1) < 0 && (j - 1) < 0)
			if (a[N - 1][N - 1] == 1)
				count++;
		if ((i - 1) < 0 && (j - 1) >= 0)
			if (a[N - 1][j - 1] == 1)
				count++;
	}
	else
		if (a[i - 1][j - 1] == 1)
			count++;

	//для a[i-1][j] -  верхний сосед
	if ((i - 1) < 0)
	{
		if (a[N - 1][j] == 1)
			count++;
	}
	else 
		if (a[i - 1][j] == 1)
			count++;

	//для a[i-1][j+1] -  верхний правый сосед
	if (((i - 1) < 0 && (j + 1) == N) || ((i - 1) < 0 && (j + 1) >= 0))//угловой верхний элемент [0][0]
	{
		if ((i - 1) < 0 && (j + 1) == N)
			if (a[N - 1][0] == 1)
				count++;
		if ((i - 1) < 0 && (j + 1) >= 0)
			if (a[N - 1][j + 1] == 1)
				count++;
	}
	else
		if (a[i - 1][j - 1] == 1)
			count++;

	//для a[i][j+1] - правый сосед
	if ((j + 1) == N)
	{
		if (a[i][0] == 1)
			count++;
	}
	else
		if (a[i][j+1] == 1)
			count++;
	//для a[i+1][j+1] - правый нижний сосед
	if (((i + 1) == N && (j + 1) == N) || ((i + 1) == N && (j + 1) >= 0))
	{
		if ((i + 1) == N && (j + 1) == N)
			if (a[0][0] == 1)
				count++;
		if ((i + 1) == N && (j + 1) >= 0)
			if (a[0][j + 1] == 1)
				count++;
	}
	else
		if (a[i + 1][j + 1] == 1)
			count++;
	//для a[i+1][j] -  нижний сосед
	if ((i + 1) == N)
	{
		if (a[0][j] == 1)
			count++;
	}
	else
		if (a[i + 1][j] == 1)
			count++;
	//для a[i+1][j-1] -  нижний левый сосед
	if (((i + 1) == N && (j - 1) < 0) || ((i + 1) == N && (j - 1) >= 0))
	{
		if ((i + 1) == N && (j - 1) < 0)
			if (a[0][N - 1] == 1)
				count++;
		if ((i + 1) == N && (j - 1) >= 0)
			if (a[0][j - 1] == 1)
				count++;
	}
	else
		if (a[i + 1][j - 1] == 1)
			count++;
	
	//для a[i][j-1] - левый сосед
	if ((j - 1) < 0)
	{
		if (a[i][N - 1] == 1)
			count++;
	}
	else
		if (a[i][j - 1] == 1)
			count++;
	if ((count < 2) || (count > 3))
		a[i][j] = 0;
}
void death(int** a, int N, int i, int j)
{
	int count = 0;
	//для a[i-1][j-1] - левый верхний сосед
	if (((i - 1) < 0 && (j - 1) < 0) || ((i - 1) < 0 && (j - 1) >= 0))
	{
		if ((i - 1) < 0 && (j - 1) < 0)
			if (a[N - 1][N - 1] == 1)
				count++;
		if ((i - 1) < 0 && (j - 1) >= 0)
			if (a[N - 1][j - 1] == 1)
				count++;
	}
	else
		if (a[i - 1][j - 1] == 1)
			count++;

	//для a[i-1][j] -  верхний сосед
	if ((i - 1) < 0)
	{
		if (a[N - 1][j] == 1)
			count++;
	}
	else
		if (a[i - 1][j] == 1)
			count++;

	//для a[i-1][j+1] -  верхний правый сосед
	if (((i - 1) < 0 && (j + 1) == N) || ((i - 1) < 0 && (j + 1) >= 0))//угловой верхний элемент [0][0]
	{
		if ((i - 1) < 0 && (j + 1) == N)
			if (a[N - 1][0] == 1)
				count++;
		if ((i - 1) < 0 && (j + 1) >= 0)
			if (a[N - 1][j + 1] == 1)
				count++;
	}
	else
		if (a[i - 1][j - 1] == 1)
			count++;

	//для a[i][j+1] - правый сосед
	if ((j + 1) == N)
	{
		if (a[i][0] == 1)
			count++;
	}
	else
		if (a[i][j + 1] == 1)
			count++;
	//для a[i+1][j+1] - правый нижний сосед
	if (((i + 1) == N && (j + 1) == N) || ((i + 1) == N && (j + 1) >= 0))
	{
		if ((i + 1) == N && (j + 1) == N)
			if (a[0][0] == 1)
				count++;
		if ((i + 1) == N && (j + 1) >= 0)
			if (a[0][j + 1] == 1)
				count++;
	}
	else
		if (a[i + 1][j + 1] == 1)
			count++;
	//для a[i+1][j] -  нижний сосед
	if ((i + 1) == N)
	{
		if (a[0][j] == 1)
			count++;
	}
	else
		if (a[i + 1][j] == 1)
			count++;
	//для a[i+1][j-1] -  нижний левый сосед
	if (((i + 1) == N && (j - 1) < 0) || ((i + 1) == N && (j - 1) >= 0))
	{
		if ((i + 1) == N && (j - 1) < 0)
			if (a[0][N - 1] == 1)
				count++;
		if ((i + 1) == N && (j - 1) >= 0)
			if (a[0][j - 1] == 1)
				count++;
	}
	else
		if (a[i + 1][j - 1] == 1)
			count++;

	//для a[i][j-1] - левый сосед
	if ((j - 1) < 0)
	{
		if (a[i][N - 1] == 1)
			count++;
	}
	else
		if (a[i][j - 1] == 1)
			count++;
	if (count == 3)
		a[i][j] = 1;
}

int main()
{
	int N, i, j, s = 0;
	cout << "Enter N = ";
	cin >> N;
	int** a = new int* [N];
	for (i = 0; i <N; i++)
		a[i] = new int[N];
	int** b = new int* [N];
	for (i = 0; i <N; i++)
		b[i] = new int[N];
	init_ar(a, N);
	b = a;
	print_ar(a, N);

	while (1)
	{
		for (i = 0; i < N; i++)
			for (j = 0; j < N; j++)
				if (a[i][j] == 1)
					live(a, N, i, j);
				else
					death(a, N, i, j);
		cout << "\n";
		print_ar(a, N);
		for (i = 0; i < N; i++)
		{
			for (j = 0; j < N; j++)
				s += a[i][j];
		}
		if (s == 0)
			break;
		if (a == b)
			break;
		else
			b = a;

	}
	delete[] a;
	delete[] b;
}