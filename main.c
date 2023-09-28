#include "main.h"
/**
 * main - Entry point of the program
 *
 * Return: 0 on normal execution, error code on exit due to error
 */
int main(int argc, char *argv[])
{
    (void)argc;
    if (isatty(STDOUT_FILENO) && isatty(STDIN_FILENO))
    {
        return interactive(argv);
    }
    else
    {
        return non_interactive(argv);
    }
}
