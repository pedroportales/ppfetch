#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/utsname.h>

int main(void) {
  struct utsname unameData;
  uname(&unameData);
  char *user = getlogin();
  //  char kernel_name = uname(&os);
  printf("%s@%s\n", user, unameData.nodename);
  printf("system name = %s\n", unameData.sysname);
  printf("release = %s\n", unameData.release);
  printf("version = %s\n", unameData.version);
  printf("machine = %s\n", unameData.machine);
  
  return 0;
}

