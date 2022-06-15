#include "main.h"

char *error_126(char **args);
char *error_127(char **args);

/**
 * error_126 - creates error message for Permission denied
 * @args: args passsed to command
 *
 * Return: error string
 */
char *error_126(char **args)
{
char *error, *hist_str;
int len;

hist_str = __itoa(hist);
if (!hist_str)
return (NULL);

len = _strlen(name) + _strlen(hist_str) + _strlen(args[0]) + 24;
error = malloc(sizeof(char) * (len + 1));
if (!error)
{
free(hist_str);
return (NULL);
}

_strcpy(error, name);
_strcat(error, ": ");
_strcat(error, hist_str);
_strcat(error, ": ");
_strcat(error, args[0]);
_strcat(error, ": Permission denied\n");

free(hist_str);
return (error);
}

/**
 * error_127 - create error for command not found failure
 * @args: args
 *
 * Return: error message generated
 */

char *error_127(char **args)
{
char *error, *hist_str;
int len;

hist_str = __itoa(hist);
if (!hist_str)
return (NULL);

len = _strlen(name) + _strlen(hist_str) + _strlen(args[0]) + 16;
error = malloc(sizeof(char) * (len + 1));
if (!error)
{
free(hist_str);
return (NULL);
}

_strcpy(error, name);
_strcat(error, ": ");
_strcat(error, hist_str);
_strcat(error, ": ");
_strcat(error, args[0]);
_strcat(error, ": not found\n");

free(hist_str);
return (error);
}

