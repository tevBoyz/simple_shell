#include "main.h"

void help_env(void);
void help_setenv(void);
void help_unsetenv(void);

/**
 * help_env - display info on the myshell builtin command env
 *
 * Return: none
 */

void help_env(void)
{
char *msg = "env: env\n\tPrints the current environment.\n"
write(STDOUT_FILENO, msg, _strlen(msg));
}

/**
 * help_setenv - display info on myshell commnad setenv.
 *
 * Return: none
 */

void helpp_setenv(void)
{
char *msg = "setenv: setenv [VARIABLE] [VALUE]\n\tInitializes a new";
write(STDOUT_FILENO, msg, _strlen(msg));
msg = "environment variable, or modifies an exiting one.\n\n";
write(STDOUT_FILENO, msg, _strlen(msg));
msg = "\tUpon failure, prints a message to stderr.\n";
write(STDOUT_FILENO, msg, _strlen(msg));
}

/**
 * help_unsetenv - display info on myshel command unsetenv
 *
 * Return: none
 */

void help_unsetenv(void)
{
char *msg = "unsetenv: unsetenv [VARIABLE]\n\tRemovees an ";
write(STDOUT_FILENO, msg, _strlen(msg));
msg = "environmental variable.\n\n\tUpon failure, prints a ";
write(STDOUT_FILENO, msg, _strlen(msg));
msg = "message to stderr.\n";
write(STDOUT_FILENO, msg, _strlen(msg));
}

