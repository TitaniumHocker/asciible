#ifndef UTIL_H
#define UTIL_H

typedef void (*func)(char*);

void phelp(char* program_name);

void pusage(char* program_name);

void pversion(char* program_name, const char* version);

func make_logger(bool verbose);

#endif
