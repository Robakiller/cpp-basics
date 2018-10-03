#include <iostream>	//Подключаем библиотеки
#include <math.h>

#define PI	3.14159265358979323846	//Определяем константу PI

using namespace std;

int main()
{
	double vdAngle;	//Объявляем переменную для угла в градусах

	cout << "Enter the angle in degrees: ";
	cin >> vdAngle;

	cout << "Your result of solution with the first formula is " << 1 - 0.25*pow(sin(2*vdAngle * PI / 180), 2) + cos(2*vdAngle * PI / 180) << endl; //Вычисляем z1 по первой формуле
	cout << "Of course, your result of solution with the second formula is " << pow(cos(vdAngle * PI / 180), 2) + pow(cos(vdAngle * PI / 180), 4) << " too" << endl; //Вычисляем z2 по второй формуле

	system("PAUSE"); //Ставим на паузу

	return 0;
}