#include <iostream>	//���������� ����������
#include <math.h>

#define PI	3.14159265358979323846	//���������� ��������� PI

using namespace std;

int main()
{
	double vdAngle;	//��������� ���������� ��� ���� � ��������

	cout << "Enter the angle in degrees: ";
	cin >> vdAngle;

	cout << "Your result of solution with the first formula is " << 1 - 0.25*pow(sin(2*vdAngle * PI / 180), 2) + cos(2*vdAngle * PI / 180) << endl; //��������� z1 �� ������ �������
	cout << "Of course, your result of solution with the second formula is " << pow(cos(vdAngle * PI / 180), 2) + pow(cos(vdAngle * PI / 180), 4) << " too" << endl; //��������� z2 �� ������ �������

	system("PAUSE"); //������ �� �����

	return 0;
}