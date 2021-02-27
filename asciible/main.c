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
static int verbose;

bool asciible (char* string)
{
  for (int i = 0; i < strlen(string); i++)
  {
    if ((int)string[i] < 0 || (int)string[i] > 127)
      return false;
  }
  return true;
}

int main(int argc, char* argv[])
{
  const char* program_name = argv[0];
  if (argc <= 1)
  {
    pusage(program_name);
    exit(EXIT_FAILURE);
  }

  for (int i = 1; i < argc; i++)
  {
    if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0)
    {
      phelp(program_name);
      exit(EXIT_SUCCESS);
    }
    if (strcmp(argv[i], "--version") == 0)
    {
      pversion(program_name, version);
      exit(EXIT_SUCCESS);
    }
  }

  return EXIT_SUCCESS;
}
