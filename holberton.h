#ifndef _HOLBERTON_H_
#define _HOLBERTON_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <signal.h>

#define BUFSIZE 256
#define SHELLNAME "hsh"

/* ERRORS */
#define ENOSTRING 1106
#define EILLEGAL 227

extern char **environ;

/**
 * struct linkedList - linked list data structure
 * @string: environ variable path name
 * @next: pointer to next node
 */
typedef struct linkedList
{
	char *string;
	struct linkedList *next;
} linked_l;

/**
 * struct configurations - configuration of build settings
 * @env: linked list of local env variables
 * @args: array of argument strings
 * @buffer: string buffer of user input
 * @path: array of $PATH locations
 * @fullPath: string of path with correct prepended $PATH
 * @lineCounter: counter of lines users have entered
 */
typedef struct configurations
{
	linked_l *env;
	char **args;
	char *buffer;
	char *path;
	char *fullPath;
	unsigned int lineCounter;
} config;

/**
 * struct builtInCommands - commands and functions associated with it
 * @command: input command
 * @func: output function
 */
typedef struct builtInCommands
{
	char *command;
	int (*func)(config *);
} type_b;

/* main */
config *configInit(config *build);

/* built_ins */
int builtIns(config *);
int exitFunc(config *);
int envFunc(config *);
int historyFunc(config *);
int aliasFunc(config *);
int cdFunc(config *);
int setenvFunc(config *);
int unsetenvFunc(config *);
int _isalpha(int c);

/* built_in_helpers*/
int countArgs(char **args);
int _atoi(char *s);

/* shell */
void shell(config *);
void checkAndGetLine(config *);
void forkAndExecute(config *);
/* _getenv */
char *_getenv(char *input, char **environ);

/* error_handler */
void errorHandler(int n, char *cmd, char *arg);
unsigned int countDigits(int num);
char *itoa(unsigned int num);
char *getErrorMessage();

/* shell_helpers */
void freeArgs(char **args);
void insertNullByte(char *str, unsigned int index);
void displayPrompt(void);
void displayNewLine(void);
void sigintHandler(int sigint);

/* check_path */
char *checkPath(char *input, char *path);

/* split_string */
char **splitString(char *str);
unsigned int countWords(char *s);
_Bool isSpace(char c);

/* string_helpers1 */
int _strlen(char *s);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strdup(char *str);

/* string_helpers2 */
char *_strtok(char *str, char *delim);
int _strcspn(char *string, char *chars);
char *_strchr(char *s, char c);

/* llfuncs1 */
linked_l *addNode(linked_l **head, const char *str);
linked_l *addNodeEnd(linked_l **head, const char *str);
size_t printList(const linked_l *h);
void freeList(linked_l *head);
int searchNode(linked_l *head, char *str);

/* llfuncs2 */
int deleteNodeAtIndex(linked_l **head, unsigned int index);
linked_l *generateLinkedList(char **array);

/* welcome */
void welcome_screen_1(void);
void welcome_screen_2(void);

/* _getline */
int _getline(char **bufferptr, size_t *n, FILE *stream);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char *_strcpy(char *dest, char *src);
char *_memcpy(char *dest, char *src, unsigned int n);

/* free */
void freeMembers(config *build);

#endif
