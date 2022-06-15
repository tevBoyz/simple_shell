#include "main.h"

void sig_handler(int sig);
int execute(char **args, char **front);

/**
 * sig_handler - Prints a new prompt upon a signal.
 * @sig: The signal.
 */
void sig_handler(int sig)
{
char *new_prompt = "\n$ ";
(void)sig;
signal(SIGINT, sig_handler);
write(STDIN_FILENO, new_prompt, 3);
}


/**
 * execute - Executes a command in a child process.
 * @args: An array of arguments.
 * @front: A double pointer to the beginning of args.
 *
 * Return: If an error occurs - a corresponding error code.
 * O/w - The exit value of the last executed command.
 */
int execute(char **args, char **front)
{
pid_t child_pid;
int status, flag = 0, rt = 0;
char *command = args[0];

if (command[0] != '/' && command[0] != '.')
{
flag = 1;
command = get_location(command);
}

if (!command || (access(command, F_OK) == -1))
{
if (errno == EACCES)
rt = (create_error(args, 126));
else
rt = (create_error(args, 127));
}
else
{
child_pid = fork();
if (child_pid == -1)
{
if (flag)
free(command);
perror("Error child:");
return (1);
}
if (child_pid == 0)
{
execve(command, args, environ);
if (errno == EACCES)
rt = (create_error(args, 126));
free_env();
free_args(args, front);
free_alias_list(aliases);
_exit(rt);
}
else
{
wait(&status);
rt = WEXITSTATUS(status);
}
}
if (flag)
free(command);
return (rt);
}

/**
 * main - Runs a simple UNIX command interpreter.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: The return value of the last executed command.
 */
int main(int argc, char *argv[])
{
int rt = 0, rtn;
int *exe_ret = &rtn;
char *prompt = "$ ", *new_line = "\n";

name = argv[0];
hist = 1;
aliases = NULL;
signal(SIGINT, sig_handler);

*exe_ret = 0;
environ = _copyenv();
if (!environ)
exit(-100);

if (argc != 1)
{
rt = proc_file_commands(argv[1], exe_ret);
free_env();
free_alias_list(aliases);
return (*exe_ret);
}

if (!isatty(STDIN_FILENO))
{
while (rt != END_OF_FILE && rt != EXIT)
rt = handle_args(exe_ret);
free_env();
free_alias_list(aliases);
return (*exe_ret);
}
while (1)
{
write(STDOUT_FILENO, prompt, 2);
rt = handle_args(exe_ret);
if (rt == END_OF_FILE || rt == EXIT)
{
if (rt == END_OF_FILE)
write(STDOUT_FILENO, new_line, 1);
free_env();
free_alias_list(aliases);
exit(*exe_ret);
}
}

free_env();
free_alias_list(aliases);
return (*exe_ret);
}

