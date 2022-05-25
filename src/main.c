#include <unistd.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <limits.h>

int main(void) {
  char hostname[HOST_NAME_MAX + 1];
  char *user = getlogin();
  gethostname(hostname, HOST_NAME_MAX + 1);

  printf("%s@%s\n", user, hostname);

  return EXIT_SUCCESS;
}

