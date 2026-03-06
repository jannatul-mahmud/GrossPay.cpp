/*
Jannatul Mahmud
This program calculates Gross pay for certain number of employee
*/

#include<iostream>
#include<iomanip>
#include<fstream>

using namespace std;

// Function prototype
void getemployeeData(int[], int[], double[], int);
void calcPay(int[], int[], double[], double[], int);

// Main function
int main()
{
	cout << "~*~*~ Welcome to Employee Payroll System ~*~*~\n";
	// Number of digit of the employee id
	const int AMNT = 5;
	int empID[AMNT] = { 12345, 12346, 12347, 12348, 12349 };
	int hours[AMNT];
	double payRate[AMNT];
	double wages[AMNT];
	ofstream backupFile;
	backupFile.open("PayrollDataBackup.txt");

	getemployeeData(empID, hours, payRate, AMNT);
	calcPay(empID, hours, payRate, wages, AMNT);

	for (int i = 0; i < AMNT; i++)
	{
		cout << fixed << showpoint << setprecision(2);
		cout << "_________________________________________________\n";
		cout << left << setw(20) << "Employe ID: " << right << setw(20) << "#" << empID[i] << endl;
		cout << left << setw(20) << "Pay Rate:" << right << setw(20) << "$" << payRate[i] << endl;
		cout << left << setw(20) << "Hours Worked: " << right << setw(21) << hours[i] << " hrs" << endl;
		cout << left << setw(20) << "Gross Pay: " << right << setw(20) << "$" << wages[i] << endl;
		cout << "_________________________________________________\n";
		backupFile << empID[i] << " " << hours[i] << " " << payRate[i] << " " << endl;
	}
	backupFile.close();

	system("pause");
	return 0;
}

// Employee Data function
void getemployeeData(int empID[], int hours[], double payRate[], int AMNT)\
{
	for (int i = 0; i < AMNT; i++)
	{
		cout << "Enter hours worked for Employee # " << empID[i] << ": ";
		cin >> hours[i];

		// Validating inputs
		while (hours[i] <= 0)
		{
			cout << "Hours can't be negative!!\n";
			cout << "Enter hours for Employee # " << empID[i] << ": ";
			cin >> hours[i];
		}
		cout << "Enter Pay Rate for Employee # " << empID[i] << ": $";
		cin >> payRate[i];

		while (payRate[i] < 20.00 || payRate[i] > 29.00)
		{
			cout << "Nobody makes less than $20.00 and more than $29.00" << endl;
			cout << "Enter Pay Rate for Employee # " << empID[i] << ": $";
			cin >> payRate[i];
		}
		cout << endl;
	}
}

// Calculation function
void calcPay(int empID[], int hours[], double payRate[], double wages[], int AMNT)
{
	for (int i = 0; i < AMNT; i++)
	{
		double extraHourPayRate = payRate[i] * 1.5;
		if (hours[i] > 40)
			wages[i] = ((hours[i] - 40) * extraHourPayRate) + 40 * payRate[i];
		else
			wages[i] = hours[i] * payRate[i];
	}
}
