#include "main.h"

int num_len(int num);
char *__itoa(int num);
int create_error(char **args, int err);

/**
 * num_len - count the digit length of a number.
 * @num: number to count length
 *
 * Return: number of digits
 */

int num_len(int num)
{
unsigned int num1;
int len = 1;

if (num < 0)
{
len++;
num1 = num * -1;
}
else
{
num1 = num;
}
while (num1 > 9)
{
len++;
num1 /= 10;
}

return (len);
}

/**
 * __itoa - converts integer to string
 * @num: integer
 *
 * Return: string
 */

char *__itoa(int num)
{
char *buff;
int len = num_len(num);
unsigned int num1;

buff = malloc(sizeof(char) * (len + 1));
if (!buff)
return (NULL);

buff[len] = '\0';

if (num < 0)
{
num1 = num * -1;
buff[0] = '-';
}
else
{
num1 = num;
}

len--;
do {
buff[len] = (num1 %  10) + '0';
num1 /= 10;
len--;
} while (num1 > 0);

return (buff);
}

/**
 * create_error - writes a custom error message to stderr
 * @args: args
 * @err: error value
 *
 * Return: error val
 */

int create_error(cahr **args, int err)
{
char *error;

switch (err)
{
case -1:
error = error_env(args);
break;
case 1:
error = error_1(args);
break;
case 2:
if (*(args[0]) == 'e')
error = error_2_exit(++args);
else if (args[0][0] == ';' || args[0][0] == '&' || args[0][0] == '|')
error = error_2_syntax(args);
else
error = error_2_cd(args);
break;
case 126:
error = error_126(args);
break;
case 127:
error = error_127(args);
break;
}
write(STDERR_FILENO, error, _strlen(error));

if (error)
free(error);

return (err);
}

