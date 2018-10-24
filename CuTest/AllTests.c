#include "CuTest.h"
#include <stdio.h>
    
CuSuite* StrUtilGetSuite();
    
void RunAllTests(void) {
  CuString *output = CuStringNew();
  CuSuite* suite = CuSuiteNew();
     
  // Adding test suites:
  CuSuiteAddSuite(suite, (CuSuite*)daysInMonthGetSuite());
  CuSuiteAddSuite(suite, (CuSuite*)isLeapYearGetSuite());  
 
  CuSuiteRun(suite);
  CuSuiteSummary(suite, output);
  CuSuiteDetails(suite, output);
  printf("%s\n", output->buffer);
}
    
int main(void) {
    RunAllTests();
}