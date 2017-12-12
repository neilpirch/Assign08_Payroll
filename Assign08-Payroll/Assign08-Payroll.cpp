// Assign08-Payroll.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

int main()
{
	int		employeeID;
	string	lastName;
	string	firstName;
	string	social;
	string	payGrade;
	string	payCode;
	double	hoursWorked;
	double	payRate;
	double	hourlyRate = 0.00;
	double	totalPay;
	char	dollarSign = '$';
	int		recordCnt = 0;
	double	cumPay = 0.00;
	ifstream timeSheet;
	ifstream hourlyPay;
	
	timeSheet.open("TimeSheet.txt");
	hourlyPay.open("HourlyPay.txt");

	if (!timeSheet || !hourlyPay)
	{
		cout << endl << endl << "Error opening input file." << endl << endl;
		system("pause");
		return -1;
	}
	hourlyPay.close();

	cout << fixed << setprecision(2);

	timeSheet >> employeeID;

	while (!timeSheet.eof())
	{
		timeSheet >> lastName >> firstName >> social >> payGrade >> hoursWorked;
		hourlyRate = 0.00;
		payRate = 0.00;

		hourlyPay.open("HourlyPay.txt");

		hourlyPay >> payCode >> payRate;
		while (!hourlyPay.eof())
		{
			if (payGrade == payCode)
			{
				hourlyRate = payRate;
			}
			hourlyPay >> payCode >> payRate;
		}
		hourlyPay.close();
		
		
		totalPay = hoursWorked * hourlyRate;

		cout << endl << employeeID << "  " << payGrade << "     " << dollarSign << setw(10) << right << totalPay << "  " << social << "  " << lastName << ", " << firstName;

		dollarSign = ' ';
		recordCnt++;
		cumPay += totalPay;
		timeSheet >> employeeID;
	}

	cout << endl << endl;
	cout << recordCnt << " pay records $" << setw(10) << right << cumPay << "  total payroll" << endl;
	

	
	cout << endl;
	system("pause");
	return 0;
}

