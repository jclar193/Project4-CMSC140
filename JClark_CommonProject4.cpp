#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

ofstream outputFile("employeeAbsences.txt");

// variable declaration.
int totalEmployees, absentDays, totalabsentDays, identificationNumber;

string programmerName;

double averageemployeeAbsences;

// function prototypes
int numberofEmployees();

int totaldaysAbsent(int);

double AverageAbsence(int, int);

int main()
{
	cout << "This program will calculate the average number of days a company's employees are absent.\n ";

	// File output formatting
	outputFile << "EMPLOYEE ABSENCES REPORT\n";
	outputFile << "employee id" << "   " << "days absent\n";
	
	// function calls.

	numberofEmployees();

	totaldaysAbsent(totalEmployees);
	
	AverageAbsence(totalEmployees, totalabsentDays);

	// file output calculations. 
	outputFile << "The " << totalEmployees << " employees were absent for a total of " << totalabsentDays << " days.\n The average number of days absent is " << setprecision(4) << averageemployeeAbsences << " days.\n Programmer: " << programmerName << endl;
	outputFile << "Programmer: John Clark";
	outputFile.close();	
}

int numberofEmployees() // function will input and validate the total number of employees.
{
	cout << "How many employees do you have in your company?: ";
	cin >> totalEmployees;
	while (totalEmployees < 1)
	{
		cout << "You must have one or more employees. Try again! ";
		cin >> totalEmployees;
	}
	return totalEmployees;
}

int totaldaysAbsent(int totalEmployees)
{
	for (int employee = 1; employee <= totalEmployees; employee++) // variable "employee" is used as the counter variable.
	{
		cout << "Enter an employee Identification number: (ID)\n "; 
		cin >> identificationNumber;
		cout << "How many days did this employee miss?: ";
		cin >> absentDays;
		totalabsentDays += absentDays;
		outputFile << identificationNumber << "          " << absentDays << endl;
	}
	cout << "The total absences for the year are: " << totalabsentDays << endl;
	return totalabsentDays;
}

double AverageAbsence(int totalEmployees, int totalabsentDays)
{
	averageemployeeAbsences = static_cast<double>(totalabsentDays) / totalEmployees;
	return averageemployeeAbsences;
}