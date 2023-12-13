#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/* FUNCTIONS */

void _print(const char *text);
void prompt(char *command, size_t size);
void _exe(const char *pmpt);
int token(const char *pmpt, char *arg[128]);
void _exe(const char *pmpt);

#endif
