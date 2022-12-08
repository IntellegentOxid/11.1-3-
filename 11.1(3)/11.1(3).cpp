#include <iostream>
#include <cmath>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;

const unsigned int ASIZE = 20;

bool floatEquals(float a, float b, float epsilon)
{
	return (fabs(a - b) < epsilon);
}

int main()
{
	int n;
	cout << "Enter the task number (1-3) that you would like to run: ";
	cin >> n;

	switch (n)
	{
	case 1:
	{
		float km;
		int day;
		cout << "\nEnter the length of the pasta (in kilometers): ";
		cin >> km;
		if (km <= 0)
		{
			cout << "Error: the length of the pasta cannot be less than or equal to 0. Try again!" << endl;
			return 1;
		}
		cout << "Enter the number of days the boy eats pasta: ";
		cin >> day;
		if (day < 0)
		{
			cout << "Error: the number of days the boy eats pasta cannot be less than 0. Try again!" << endl;
			return 1;
		}
		else if (day == 0)
		{
			cout << "\nIt remains to eat " << round(km * 1000) / 1000 << " kilometers of pasta...\n";
		}
		else
		{
			float pasta = km;
			for (int i = 1; i <= day; i++)
			{
				pasta = pasta * (1 - (1.0 / (i + 1)));
			}
			if ((round(pasta * 1000) / 1000) == 0)
				cout << "\nCongratulations! All the pasta is eaten.\n";
			else
				cout << "\nIt remains to eat " << round(pasta * 1000) / 1000 << " kilometers of pasta...\n";
		}
	}
	break;
	case 2:
	{
		float pi = M_PI;
		double dpi = M_PI;

		cout.precision(25);
		cout << "\nThe value of pi with ordinary precision: " << pi << endl;
		cout.precision(50);
		cout << "The value of pi with double precision: " << dpi << endl;

		int odd[ASIZE];
		int n = 1;
		for (int i = 0; i < ASIZE; i++)
		{
			while ((n % 2 == 0) || (n != 3 && n % 3 == 0) || (n != 5 && n % 5 == 0))
			{
				n++;
			}
			odd[i] = n;
			n++;
		}

		float pi3 = 3.141;
		float p = 0;
		int count = 0;
		do
		{
			if (count % 2 == 0)
				p += 4 * (1.0 / odd[count]);
			else
				p += -4 * (1.0 / odd[count]);
			count++;
		} while (!floatEquals(p, pi3, 0.001));
		cout << "\nThe number of terms is necessary to calculate the number pi with an accuracy of up to 3 digits: " << count << endl;
	}
	break;
	case 3:
	{
		int g;

		cout << "\nEnter a natural number: ";
		cin >> g;
		if (g < 0)
		{
			cout << "Incorrect value has been entered. Repeat again!" << endl;
			return 1;
		}
		cout << "The simple multipliers of the enteered number: ";
		do
		{
			if (g == 1)
			{
				cout << "1";
				g = 1;
			}
			else if ((g % 2) == 0)
			{
				cout << "2";
				g /= 2;
			}
			else if ((g % 3) == 0)
			{
				cout << "3";
				g /= 3;
			}
			else if ((g % 5) == 0)
			{
				cout << "5";
				g /= 5;
			}
			else if ((g % 7) == 0)
			{
				cout << "7";
				g /= 7;
			}
			else
			{
				cout << g;
				g = 1;
			}
			cout << ", ";
		} while (g != 1);
		cout << "1.\n";
	}
	break;
	default:
	{
		cout << "The task with this number does not exist. Try again!";
	}
	break;
	}
}