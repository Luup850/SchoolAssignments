#include <windows.h>
#include<unistd.h>

int main(int argc, char const *argv[])
{
  for(int i = 0; i <= 10; i++)
  {
    ShellExecute(NULL, "open", "https://www.youtube.com/watch?v=dQw4w9WgXcQ", NULL, NULL, SW_SHOWNORMAL);
    sleep(2);
  }
  return 0;
}