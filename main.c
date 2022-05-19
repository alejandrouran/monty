#include "monty.h"

/**
 * main - Entry point
 * @argc: arguments
 * @argv: char const to argv
 * Return: void
 */
int main(int argc, char *argv[])
{
	FILE *file;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	process(file);
	fclose(file);
	return (EXIT_SUCCESS);
}
