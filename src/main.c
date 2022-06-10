#include <stdio.h>
#include <stdlib.h>
#include <sys/utsname.h>
#include <string.h>

int main(void) {
  struct utsname unameData; // machine and kernel data
  uname(&unameData);
  char *shell = getenv("SHELL");
  char *user = getenv("USER");

  // Getting the OS - thx redfetch
  char line[100];
  char distroname[60];
  int scanned_count = 0;
  FILE* osfile = fopen("/etc/os-release", "r");
  while(!feof(osfile)) {
    fgets(line, 100, osfile);
    scanned_count = sscanf(line,"NAME=\"%[^\"]\"", distroname);
    if(scanned_count == 0){
      scanned_count = sscanf(line,"NAME=%s",distroname);
    }
    if(scanned_count != 0){ break; }
  }
  fclose(osfile);
  
  printf("%s@%s\n", user, unameData.nodename);
  printf("----------------\n");
  printf("sys ~ %s\n", distroname);
  printf("ker ~ %s %s\n", unameData.sysname, unameData.release);
  printf("arch ~ %s\n", unameData.machine);
  printf("sh ~ %s\n", shell);
    
  return 0;
}

