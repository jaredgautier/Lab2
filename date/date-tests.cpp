#include "date.h"
#include <iostream>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

// Exercise 2.1
// Comment out this test after inspecting the output.
// Tests which require manual verification should not be lumped
// with tests which are automatically verified!
//TEST_CASE("Date has uninitialised state") {	 
//    // make some prior memory allocations - which will be the case in a typical program
//    auto i = {1.0,1.3,1.4,1.5,1.6,1.7,1.8,1.9,10.2,11.0,1.2,1.3,1.23};
//    auto i2 = 1.0;
//    
//    Date today;	
//    std::cout << "Today is: " << endl;
//    printDate(today);
//}

 //Write code to make this test pass
TEST_CASE("Valid Date is initialised correctly") {
	Date heritage_day{24, Month::September, 2000};
	CHECK(heritage_day.day() == 24);
	CHECK(heritage_day.month() == Month::September);
	CHECK(heritage_day.year() == 2000);
}


// Exercise 2.2
// Supply additional tests for the constructor here, which
// verify that an exception is thrown when an attempt is made
// to construct an invalid date. Think carefully about which
// invalid dates to test.

TEST_CASE("Number of days in mopnth is not greater than days in month") 
{

	CHECK_THROWS_AS(Date test_day(31, Month::September, 2000),monthWithTooManyDays);
}

TEST_CASE("Check that leap years are working") 
{
    Date test_day1{29, Month::February, 2000};
    Date test_day2{29, Month::February, 2016};
    CHECK(test_day1.isLeapYear());
    CHECK(test_day2.isLeapYear());
}

TEST_CASE("Check that leap years have 29 days in February") 
{
    Date test_day{29, Month::February, 2016};
    int numDays = test_day.daysInMonthPub();
    CHECK(numDays == test_day.day());
    
}
TEST_CASE("Check year is not greater than 2017") 
{
    CHECK_THROWS_AS(Date test_day(15, Month::September, 2020),invalidYear);
}
TEST_CASE("Check year is not less than 0") 
{
    CHECK_THROWS_AS(Date test_day(15, Month::September, -5),invalidYear);
}
TEST_CASE("Check for valid day of month") 
{
    CHECK_THROWS_AS(Date test_day(0, Month::September, 2016),invalidDay);
}

// Exercise 2.3
TEST_CASE("Identical Dates are Equal")
 {
    Date date_1(1, Month::January, 2000);
    Date date_2(1, Month::January, 2000);

    CHECK(date_1 == date_2);
}

TEST_CASE("Leap year dates are equal")
 {
    Date date_1(29, Month::February, 2016);
    Date date_2(29, Month::February, 2016);

    CHECK(date_1 == date_2);
}


TEST_CASE("Dates with different years are not equal") 
{
    Date date_1(25, Month::February, 2016);
    Date date_2(25, Month::February, 2015);
    
    CHECK_FALSE(date_1 == date_2);
}
TEST_CASE("Dates with different months are not equal") 
{
    Date date_1(25, Month::March, 2016);
    Date date_2(25, Month::February, 2016);
    
    CHECK_FALSE(date_1 == date_2);
}
TEST_CASE("Dates with different days are not equal") 
{
    Date date_1(24, Month::February, 2016);
    Date date_2(25, Month::February, 2016);
    
    CHECK_FALSE(date_1 == date_2);
}
// Supply at least three additional tests for
// the equality operator here, to ensure that
// it is working correctly.


// Exercise 2.4
// Provide tests for a new member function of the Date class
// which will increase the date by one day.


TEST_CASE("Date actually increases")
 {
    Date date_1(28, Month::August, 2017);
    date_1.incrementDay();
    CHECK(date_1.day() == 29);
}

TEST_CASE("Adding one to the date will change the month and set it to the first")
 {
    Date date_1(31, Month::July, 2017);
    Date date_2(1, Month::August, 2017);
    
    date_1.incrementDay();
    CHECK(date_1 == date_2);
}
TEST_CASE("Adding one to the date will change the month and set it to the first on a leap year")
 {
    Date date_1(29, Month::February, 2016);
    Date date_2(1, Month::March, 2016);
    
    date_1.incrementDay();
    CHECK(date_1== date_2);
}
TEST_CASE("Adding one to december 31 will tick the year over")
 {
    Date date_1(31, Month::December, 2016);
    Date date_2(1, Month::January, 2017);
    
    date_1.incrementDay();
    CHECK(date_1== date_2);
}



// Exercise 2.5
// Write tests for the new default constructor and the
// setDefaultDate method.
TEST_CASE("Check to see that default date is correct") 
{
    Date date_1(1, Month::January, 1900);
    CHECK(date_1 == Date::defaultdate());
}
