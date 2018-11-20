#include <stdio.h>
#include <locale.h>
#include <wchar.h>

int main()
{
  setlocale(LC_CTYPE,"UTF-8");
  char *locale;



  locale = setlocale(LC_CTYPE,"UTF-8");
  printf("The current locale is %s\n",locale);

  return(0);
}