/*Реализовать функцию, которая будет перемножать два числа с помощью
побитовых операторов (без использования арифметических */

#include <iostream>
using namespace std;
int multiplication_x_y(int x, int y)
{
    int X, res, result = 0;
    while (y != 0) {
        if ((y & 1) != 0)
        {
            X = x;
            while (X != 0)
            {
                res = result & X;
                result = result ^ X;
                X = res << 1;
            }
        }

        y = y >> 1;
        x = x << 1;
    }

    return result;
}
int main()
{
	int x, y, result;
	cout << "Enter x = ";
	cin >> x;
    cout << "Enter y = ";
	cin >> y;
    result = multiplication_x_y(x, y);
    cout << "Multiplication of x and y = " << result;

}
