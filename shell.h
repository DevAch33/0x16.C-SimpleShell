#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

// Buffers 
#define BUF_FLUSH -1
#define WRITE_BUF_SIZE 1024

// string.c 
int _strlen (char *);
int _strcmp (char *,char *);
char *_strcat(char *, const char *);
char *_strcpy(char *, const char *);
char *_strdup(const char *);

// Memory function
char *_memset(char *, char, unsigned int);
void *_realloc(void *, unsigned int, unsigned int);
#endif
