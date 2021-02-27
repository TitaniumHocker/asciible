#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <errno.h>
#include <getopt.h>


#include "util.h"

const char* USAGE_TEMPLATE =
  "Usage: %s [TEXT] [-i|--input FILE|DIR...] [-r|--recursive] "
  "[-h|-?|--help] [--version] [-v|--verbose]\n";
const char* VERSION_TEMPLATE = "%s version %s\n";
const char* HELP_TEMPLATE =
  "Usage: %s [-i|--input FILE|DIR...] [-r|--recursive] "
  "[-h|-?|--help] [--version] [-v|--verbose] [TEXT]\n"
  "\n"
  "This is a simple program for checking if provided "
  "text, file or files in directory has non-ASCII symbols.\n"
  "If at least one non-ASCII symbol was detected returns non-zero "
  "exit code, otherwise - zero exit code.\n"
  "If non text nor files or dirs with files provided - returns "
  "non-zero exit code.\n"
  "\n"
  "Options:\n"
  "\t-r|--recursive       Used for recursive check in directory.\n"
  "\t-h|--help         Show help and exit.\n"
  "\t--version            Show version and exit.\n"
  "\t-v|--verbose         Show verbose output.\n"
  "\n"
  "Arguments:\n"
  "\tTEXT                 Provided text for check.\n"
  "\t-i|--input FILE|DIR  Provided files or dirs with files for check.\n"
  "\n"
  "The author of the program, as always, bears no responsibility.\n";


void pusage(const char* program_name)
{
  printf(USAGE_TEMPLATE, program_name);
}

void pversion(const char* program_name, const char* version)
{
  printf(VERSION_TEMPLATE, program_name, version);
}

void phelp(const char* program_name)
{
  printf(HELP_TEMPLATE, program_name);
}


bool isAccessable(char* path, char* errbuf)
{
  if (access(path, R_OK) == 0)
    return true;
  if (errno == ENOENT)
    errbuf = "No such file or directory";
  if (errno == EACCES)
    errbuf = "Permission denied";
  return false;
}