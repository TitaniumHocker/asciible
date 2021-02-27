#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "util.h"

/* asciible
 *
 * This is simple program for checking non-ASCII symbols
 * in provided text, file(s) or file(s) in dir(s). 
 *
 */

const char* version = "0.1";
static int verbose_flag;

int main(int argc, char* argv[]) {
  char* program_name = argv[0];
  if (argc <= 1) {
    pusage(program_name);
    exit(EXIT_FAILURE);
  }
  return 1;
}
