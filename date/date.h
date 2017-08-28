#ifndef DATE_H
#define DATE_H
// date.h
// class Date declaration

#include <cassert>
#include <iostream>
using namespace std;



class monthWithTooManyDays{};
class invalidYear{};
class invalidDay{};


enum class Month 
{
	January = 1, 
	February = 2,
	March = 3, 
	April = 4,
	May =5,
	June =6,
	July =7, 
	August =8, 
	September =9,
	October =10,
	November =11, 
	December =12
};
	
class Date
{
public:
    //constructor
    Date(const int day,const Month month , const int year);		
    
    void incrementDay();
	// return the day of the month
	int	day () const;
	// return the month of the year
	Month month () const;
	// return the year
	int year () const;
	// return true if it is a leap-year, false if not
	bool isLeapYear () const;
    int daysInMonthPub() const;
    bool operator==(const Date& rhs) const;
    

private:
	// return the number of days in the _month
	int	daysInMonth () const;		
	
	int	_day;
	Month _month;
	int	_year;

};

// standalone function for printing the date
void printDate(const Date& date);

#endif