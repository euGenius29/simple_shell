#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <errno.h>
#include <signal.h>

/**
 * struct node - A node pointing to an environment variable
 *
 * @name: The name of the variable
 * @value: The value of the variable
 * @next: The next environment variable
 *
 * Description: Stores all the environment variables
*/
typedef struct node
{
	char *name;
	char *value;
	struct node *next;
} node_t;

#define I_MODE 1
#define NON_I_MODE 0
#define NULL_FOUND -2
#define INV_CMD 127
#define VALID_CMD 0
#define SIG_CODE 130
#define IS_ABS_PATH 1
#define IS_REL_PATH 2
#define IS_EXEC 1
#define IS_PATH 1
#define IS_NOT_PATH 0
#define ERR_OCCURED -1
#define SHLVL_NAME "SHLVL"
#define SHLVL_VAL "1"
#define EQUAL_STR 0
#define OVERWRITE 1
#define IGNORE 0
#define EXIT (_strcmp(commands[0], "exit") == EQUAL_STR)

extern char **environ;
extern int signal_value;
extern node_t *head;

int _accept(char **buffer, size_t *bytes_read);
char **_tokenize(char *str, char *delimiter);
int _token_count(char *str, char *delimiter);
int _exec(char **commands, int commands_executed
, char *program, char **env);
int _check_mode(void);
void handle_sigint(int signum);
void _isexit(char **commands, char *buffer, char **envpath
, int signal_value, char **env_clone);
int _isexec(char *path);
int _exitshell(char **envpath, char **env_clone, char *buffer);


char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
int _strlen(char *str);
int _putchar(char character, int file_descriptor);
char *_strdup(char *str);
const char *_strstr(const char *haystack, const char *needle);


void _print_err(int commands_executed, int param_count, ...);
void print_number(int number);


int _check_file(char *path);
int _isrelpath(char *path);
char *_getenvpathvar();
int _isenvvarpath(char *env_variable);
char *_pathbuilder(int argc, ...);
int _checkpath(char *pathname);
char **_loadpaths(node_t *head);
char *_get_fullpath(char *path, char *command);


void _free_str(char *str);
void _free_array(char **commands);
void free_list(node_t *head);


int _checkenv(char *command);
void _printenv(void);
int _set_env(const char *name, const char *value, int overwrite);
char **_get_envs(char **env);
void _relpath(int *file_info, char **envpath, char **commands
, char *buffer, int *exit_code);


node_t *_addnodeend(node_t **head, char *name, char *value);
node_t *_findnode(node_t *head, char *name);


#endif
