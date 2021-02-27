#ifndef UTIL_H
#define UTIL_H

void phelp(const char* program_name);

void pusage(const char* program_name);

void pversion(const char* program_name, const char* version);

bool isAccessable(char* path, char* errbuf);

#endif
