#ifndef MAIN_H
#define MAIN_H


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <sys/wait.h>


extern char **environ;

int _atoi(char *str);
char *append_path(char *args);
void free_args(char **args);
char *getpath(char *name);
int print_string(char *string);

int allocate_buffer(char **lineptr, size_t *n, size_t len);
ssize_t readline(char **lineptr, size_t *n, int fd);

int _len(char *str);
int _strncmp(char *str_1, char *str_2, int len);
char *_strcat(char *str_1, char *str_2);
char *_strdup(char *str_1);

int print_error(int argc ,char *argv[], char **token);

void exit_func(char **args, char *buffer);
void print_env(void);
int _exe(int argc, char *argv[], char **args);
int process_line(int argc, char *argv[], char *buffer);
#endif
