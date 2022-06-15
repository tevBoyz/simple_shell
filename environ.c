#include "main.h"

char **_copyenvv(void);
void free_env(void);
char **_getenv(const char *var);

/**
 * _copyenv - create a copy of environment
 *
 * Return: if error occur - null
 * poiter to a new copy
 */

char **_copyenv(void)
{
char **new_env;
size_t size;
int index;

for (size = 0; environ[size]; size++)
;

new_env = malloc(sizeof(char *) * (size + 1));
if (!new_env)
return (NULL);

for (index = 0; environ[index]; index++)
{
new_env[index] = malloc(_strlen(environ[index]) + 1);

if (!new_env[index])
{
for (index--; index >= 0; index--)
free(new_env[index]);
free(new_env);
return (NULL);
}
_strcpy(new_env[index], environ[index]);
}
new_env[index] = NULL;

return (new_env);
}

/**
 * free_env - frees the env copy
 *
 * Return: none
 */
void free_env(void)
{
int x;

for (x = 0; environ[x]; x++)
free(environ[x]);
free(environ);
}

/**
 * _getenv - get env variable from current path
 * @var: name of env var to get
 *
 * Return: NULL if var doesnt exist, or the pointer to the env variable
 */

char **_getenv(const char *var)
{
int x, len;
len = _strlen(var);
for (x = 0; environ[x]; x++)
{
if (_strncmp(var, environ[x], len) == 0)
return (&environ[x]);
}

return (NULL);
}

