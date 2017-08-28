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


    Date(int day, Month month, int year);		
    Date();
    
    
    //Date _default{1, Month::January, 1900};
    
    void incrementDay();
    
    static Date defaultdate ();
    
    static void setDefaultDate(int day, Month month, int year)
    {
        Date::_default._day = day;
        Date::_default._month = month;
        Date::_default._year =  year;
    }
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
	
    static Date _default;
	int	_day;
	Month _month;
	int	_year;

};

// standalone function for printing the date
void printDate(const Date& date);

#endif