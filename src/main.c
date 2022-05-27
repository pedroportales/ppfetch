#include <stdio.h>
#include <stdlib.h>
#include <sys/utsname.h>

int main(void) {
  struct utsname unameData; // machine and kernel data
  uname(&unameData);
  char *shell = getenv("SHELL");
  char *user = getenv("USER");

  // distro name
  FILE *fp;
  char distroname[20];
  fp = popen("lsb_release -ds", "r");
  fgets(distroname, 20, fp);
  pclose(fp);
  
  printf("%s@%s\n", user, unameData.nodename);
  printf("----------------\n");
  printf("system ~ %s\n", distroname);
  printf("kernel ~ %s %s\n", unameData.sysname, unameData.release);
  printf("arch ~ %s\n", unameData.machine);
  printf("shell ~ %s\n", shell);
    
  return 0;
}

