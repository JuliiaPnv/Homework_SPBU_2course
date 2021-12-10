#include<iostream>
using namespace std;

float* search_ptrC(float* ptrA, float* ptrB)
{
	float* ptrC = ptrA;
	if (ptrA < ptrB)
	{
		while (ptrA != ptrB) 
		{
			ptrA++;
			ptrC--;
		}
	}
	else
	{
		while (ptrB != ptrA)
		{
			ptrB++;
			ptrC++;
		}
	}
	return(ptrC);
}


int main()
{
	int N, i, A, B;
	float* ptrA, * ptrB;
	cout << "Enter the number of items = ";
	cin >> N;
	float* a = new float[N];
	cout << "Vvedite znacheniya elementov:"<<endl;
	for (i = 0; i < N; i++)
		cin >> a[i];
	for (i = 0; i < N; i++)
		cout << a[i]<<" ";
	cout <<endl<< "Vvedite nomer elementa ptrA = ";
	cin >> A;
	cout << "Vvedite nomer elementa ptrB = ";
	cin >> B;
	while (1)
	{
		if ((A < 0) || (A > N - 1))
		{
			cout << "NE V DIAPAZONE! Vvedite nomer elementa ptrA = ";
			cin >> A;
		}
		if ((B < 0) || (B > N - 1))
		{
			cout << "NE V DIAPAZONE! Vvedite nomer elementa ptrB = ";
			cin >> B;
		}
		if ((B >= 0) && (B < N) && (A >= 0) && (A < N))
			break;
	}
	ptrA = &a[A];
	ptrB = &a[B];
	float* ptrC = search_ptrC(ptrA, ptrB);
	if (ptrC < &a[0])
		ptrC = &a[0];
	if (ptrC > & a[N - 1])
		ptrC = &a[N - 1];
	cout << "Znacheniye elementa ptrC = " << *ptrC;
	delete[] a;
}