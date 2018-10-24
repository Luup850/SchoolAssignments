#include <stdio.h>
#include <stdlib.h>
#include "CuTest.h"

int isLeapYear(int yr);

int daysInMonth(int month, int year){
  int numberOfDays;
  switch(month){
    case 1: case 3: case 5: case 7: case 8: case 10: case 12: 
      numberOfDays = 31; break;
    case 4: case 6: case 9: case 11: 
      numberOfDays = 30; break;
    case 2:
      if (isLeapYear(year)) numberOfDays = 29; 
      else numberOfDays = 28; break;
    default: exit(-1);  break;
  }
  return numberOfDays;
}   

/* A number of test functions of daysInMonth */

void testDaysInMonthJan(CuTest *tc){
  int actual = daysInMonth(1, 2010);
  int expected = 31;
  CuAssertIntEquals(tc, expected, actual);
}

void testDaysInMonthFeb(CuTest *tc){
  int actual = daysInMonth(2, 2010);
  int expected = 28;
  CuAssertIntEquals(tc, expected, actual);
}

void testDaysInMonthApr(CuTest *tc){
  int actual = daysInMonth(4, 2010);
  int expected = 30;
  CuAssertIntEquals(tc, expected, actual);
}

void testDaysInMonthDec(CuTest *tc){
  int actual = daysInMonth(12, 2010);
  int expected = 31;
  CuAssertIntEquals(tc, expected, actual);
}

/* Test case management: Adding test cases to a test suite */
CuSuite* daysInMonthGetSuite() {
  CuSuite* suite = CuSuiteNew();
  SUITE_ADD_TEST(suite, testDaysInMonthJan);
  SUITE_ADD_TEST(suite, testDaysInMonthFeb);
  SUITE_ADD_TEST(suite, testDaysInMonthApr);
  SUITE_ADD_TEST(suite, testDaysInMonthDec);

  return suite;
}


/* Function Under Test */
int isLeapYear(int year){
  int res;
  if (year % 400 == 0)
    res = 1;
  else if (year % 100 == 0)
    res = 0;
  else if (year % 4 == 0)
    res = 1;
  else res = 0;
  return res;
}  

/* A number of test functions of isLeapYear */

void testIsLeapYear1(CuTest *tc){
  int actual = isLeapYear(1999);
  int expected = 0;
  CuAssertIntEquals(tc, expected, actual);
}

void testIsLeapYear2(CuTest *tc){
  int actual = isLeapYear(2000);
  int expected = 1;
  CuAssertIntEquals(tc, expected, actual);
}

void testIsLeapYear3(CuTest *tc){
  int actual = isLeapYear(1900);
  int expected = 0;
  CuAssertIntEquals(tc, expected, actual);
}

void testIsLeapYear4(CuTest *tc){
  int actual = isLeapYear(2008);
  int expected = 1;
  CuAssertIntEquals(tc, expected, actual);
}  


/* Test case management: Adding test cases to a test suite */
CuSuite* isLeapYearGetSuite() {
  CuSuite* suite = CuSuiteNew();

  SUITE_ADD_TEST(suite, testIsLeapYear1);
  SUITE_ADD_TEST(suite, testIsLeapYear2);
  SUITE_ADD_TEST(suite, testIsLeapYear3);
  SUITE_ADD_TEST(suite, testIsLeapYear4);

  return suite;
}