// Daily_Summer_Mod7_DateClass.cpp : Defines the entry point for the console application.
// Author: Summer Daily
// Last Updated: 10/18/18
// Purpose: Demonstrate Exception Handling

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#include "stdafx.h"

class Date
{
public:
	Date();
	Date(int, int, int);
	void changeMonth(int);
	void changeDay(int);
	void changeYear(int);
	void toString();
private:
	int month;
	int day;
	int year;
	int num_days_in[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	string thisMonth[13] = { "None", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
};

int main()
{
	int myMonth;
	int myDay;
	int myYear;

	cout << "Enter all dates as mm/dd/yyyy. All dates must be between 1900 and 2020." << endl;
	cout << "Try to enter an invalid date: ";
	
	cin >> myMonth;
	cin.ignore(1);
	cin >> myDay;
	cin.ignore(1);
	cin >> myYear;
	Date myFavDate = Date(myMonth, myDay, myYear);

	myFavDate.toString();

	cout << "Try to change the month of your date to one that doesn't exist. (i.e. less than 1 or more than 12): ";
	cin >> myMonth;
	myFavDate.changeMonth(myMonth);

	cout << "Try to change the day of your date to one that doesn't exist. (i.e. less than 1 or more than 31): ";
	cin >> myDay;
	myFavDate.changeDay(myDay);

	cout << "Try to change the year of your date to one before 1900 or after 2020: ";
	cin >> myYear;
	myFavDate.changeYear(myYear);

	cout << "All done." << endl;
	myFavDate.toString();

	cout << "Press any key to continue...";
	cin.ignore();
	cin.get();
    return 0;
}

Date::Date()
{
	month = 01;
	day = 01;
	year = 1900;
}
Date::Date(int newMonth, int newDay, int newYear)
{
	bool done = false;
	
	do
	{
		try
		{
			if (!cin)
			{
				int error = 404;
				throw error;
			}
			else if (newMonth < 1)
			{
				string error = "Month cannot be less than 1.";
				throw error;
			}
			else if (newMonth > 12)
			{
				string error = "Month can't be greater than 12.";
				throw error;
			}
			else if (newYear > 0 && newYear <= 99)
			{
				string error = "You cannot enter years as two digits. Years must be entered as four digit numbers. ";
				throw error;
			}
			else if (newYear > 2020 || newYear < 1900)
			{
				string error = "Year must be between 1900 and 2020.";
				throw error;
			}
			else if (newDay < 1)
			{
				string error = "Days cannot be less than 1.";
				throw error;
			}
			else if (newDay > num_days_in[newMonth])
			{
				string error = thisMonth[newMonth] + " does not have more than " + to_string(newDay) + " days.";
				throw error;
			}
			done = true;
			month = newMonth;
			day = newDay;
			year = newYear;
		}
		catch (string error)
		{
			cout << error;
			cout << "Try entering date again: ";
			cin >> newMonth;
			cin.ignore(1);
			cin >> newDay;
			cin.ignore(1);
			cin >> newYear;
		}
		catch (int error)
		{
			cin.clear();
			cin.ignore (1000, '\n');
			cout << "Woah! You entered something wacky. Try entering date again: ";
			cin >> newMonth;
			cin.ignore(1);
			cin >> newDay;
			cin.ignore(1);
			cin >> newYear;
		}
	} 
	while (!done);
}
void Date::changeMonth(int newMonth)
{
	bool done = false;

	do
	{
		try
		{
			if (!cin)
			{
				int error = 404;
				throw error;
			}
			else if (newMonth < 1 )
			{
				string error = "Month cannot be less than 1.";
				throw error;
			}
			else if (newMonth > 12)
			{
				string error = "Month can't be greater than 12.";
				throw error;
			}
			else if (day > num_days_in[newMonth])
			{
				string error = thisMonth[newMonth] + " does not have more than " + to_string(day) + " days.";
				throw error;
			}
			done = true;
			month = newMonth;
		}
		catch (string error)
		{
			cout << error;
			cout << "Try entering month again: ";
			cin >> newMonth;
		}
		catch (int error)
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Woah! You entered something wacky. Try entering month again: ";
			cin >> newMonth;
		}
	} while (!done);
}
void Date::changeDay(int newDay)
{
	bool done = false;

	do
	{
		try
		{
			if (!cin)
			{
				int error = 404;
				throw error;
			}
			else if (newDay < 1)
			{
				string error = "Day cannot be less than 1.";
				throw error;
			}
			else if (newDay > num_days_in[month])
			{
				string error = thisMonth[month] + " does not have more than " + to_string(newDay) + " days.";
				throw error;
			}
			done = true;
			day = newDay;
		}
		catch (string error)
		{
			cout << error;
			cout << "Try entering day again: ";
			cin >> newDay;
		}
		catch (int error)
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Woah! You entered something wacky. Try entering day again: ";
			cin >> newDay;
		}
	} while (!done);
}
void Date::changeYear(int newYear)
{
	bool done = false;

	do
	{
		try
		{
			if (!cin)
			{
				int error = 404;
				throw error;
			}
			else if (newYear > 0 && newYear <= 99)
			{
				string error = "You cannot enter years as two digits. Years must be entered as four digit numbers. ";
				throw error;
			}
			else if (newYear > 2020 || newYear < 1900)
			{
				string error = "Year must be between 1900 and 2020.";
				throw error;
			}
			done = true;
			year = newYear;
		}
		catch (string error)
		{
			cout << error;
			cout << "Try entering year again: ";
			cin >> newYear;
		}
		catch (int error)
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Woah! You entered something wacky. Try entering year again: ";
			cin >> newYear;
		}
	} while (!done);

}
void Date::toString()
{
	cout << "Your date is " << thisMonth[month] << " " << day << ", " << year << endl;
}