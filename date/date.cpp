// date.cpp
// Implementation of the Date class

#include "date.h"


Date::Date( int day, Month month , int year):
    _day{day},
    _month{month},
    _year{year}
{
    
    
    int maxDays = daysInMonth();
    
    if(_day > maxDays) throw monthWithTooManyDays();
        
        
    int maxYear = 2017;
    int minYear = 0;
    if (_year > maxYear || _year < minYear) throw invalidYear();
    
    int minDays = 1;
    if (_day < minDays) throw invalidDay();
    
    
    
}
Date Date::_default(1, Month::January, 1900);

void Date::incrementDay()
{
    
    int staticMonth = static_cast<int>(_month);
    
    if(_day == daysInMonth())
    {
        if(staticMonth == 12)
        {
            staticMonth = 1;
            _month = static_cast<Month>(staticMonth);
            _day = 1;
            _year ++;
        }
        else
        {
               staticMonth = staticMonth + 1;
            _month = static_cast<Month>(staticMonth);
            _day = 1; 
        }
    }
    else
    {
        _day =_day +  1;    
    }
}


int Date::day() const
{
	return _day;
}

Month Date::month() const
{
    
    return _month;
}

int Date::year() const
{
	return _year;
}

Date Date::defaultdate ()
{
    return _default;
}

bool Date::isLeapYear() const
{
    // leap years must be divisible by 4 but not by 100
    // or divisible by 400
    if(((_year % 4 == 0) && (_year % 100 != 0)) || (_year % 400 == 0))
        return true;
    else
        return false;
}

int Date::daysInMonth() const
{
	switch (_month) {
		case Month::January: 
		case Month::March: 
		case Month::May: 
		case Month::July:
		case Month::August: 
		case Month::October: 
		case Month::December:
			return 31;	
		case Month::April: 
		case Month::June: 
		case Month::September:
		case Month::November:
			return 30;	
		case Month::February:
			if ( isLeapYear() ) return 29;
			else return 28;
		default:
			// should never reach here 
			assert(false); // See: http://www.cplusplus.com/reference/cassert/assert/
            return -1;
	}    
}

int Date::daysInMonthPub() const
{
    return daysInMonth();
}


bool Date::operator==(const Date& rhs) const
{
    int rhsDay = rhs.day();
    Month rhsMonth = rhs.month();
    int rhsYear = rhs.year();
    
    if(rhsDay == _day && rhsMonth ==_month && rhsYear ==_year)
    {
        return true;
    }
    else
    {
        return false;
    }
    return false;
    

}


// Note, this standalone function is not part of the Date class
void printDate(const Date& date)
{
	cout << date.day() << "/"
		// cast to an integer to allow the month to be sent to the stream
        << static_cast<int>(date.month()) << "/"
		<< date.year()
		<< endl;
}

