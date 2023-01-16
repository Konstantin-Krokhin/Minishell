
#include <stdio.h> // printf
#include <stdlib.h> // free
#include <readline/readline.h> //readline
#include <readline/history.h> //history

#include <string.h> //strlen
#include "libft/libft.h"

int	print_output_to_file(char *filename, char *buff);


// void    sig_handler(int signum)
// {
//     if (signum == SIGINT)
//     {
//         printf("\n");
//         rl_on_new_line();
//         rl_replace_line("", 0);
//         rl_redisplay();
//     }


int	main(void)
{

	char *buff;
	char **str;

	printf("-----Welcome to Minishell-----\n");

	// write functions output to the buff and print aftewards if there is no pipe or feeding it to a specific output
	while (1)
	{
		buff = readline(">>");
		if (ft_strlen(buff) > 0)
			 add_history(buff);
		//split inputs with spaces and search for commands
		str = ft_split(buff, ' ');
		int i = 0;
		while (str[i] != 0)
		{
			// Command Selector

			// pwd
			if (ft_strncmp(str[i], "pwd", ft_strlen(str[i])) == 0)
			{
				char cwd[256];
				if (getcwd(cwd, sizeof(cwd)) == NULL)
     				perror("Error: getcwd()\n");
     			printf("%s\n", cwd);

			}
			// cd
			else if (ft_strncmp(str[i], "cd", ft_strlen(str[i])) == 0)
			{
				i++;

				if (chdir(str[i]) != 0)
					perror("Error: chdir()\n");
				else {
					char cwd[256];
					if (getcwd(cwd, sizeof(cwd)) == NULL)
						perror("Error: getcwd()\n");
				}
			}
			else if (ft_strncmp(str[i], "exit", ft_strlen(str[i])) == 0)
			{
				//free all str[i] and str memory and return from main
				//pass i and char **str so function can  free all memory left allocated by split
				return(0);
			}
			else if(str[i][0] == '$')
			{
				if (str[i][1] != '\0')
				{
					printf("%s\n", getenv(str[i] + 1));
				}
				else
				{
					printf("42bash: command not found: %s\n", str[i]);
					//free all str[i] and str memory and return from main
					//pass i and char **str so function can  free all memory left allocated by split
					break;
				}
			}
			else if(ft_strncmp(str[i], "print_output", ft_strlen(str[i])) == 0)
			{
				// split separates the string to be written in the file - problem will also happen in echo
				char *filename = 0;
				char *buff = 0;
				i++;
				if (str[i] != 0)
				{
					filename = str[i];
					i++;
					if (str[i] != 0)
					{
						buff = str[i];
						print_output_to_file(filename, buff);
					}
					else
						break;
				}
				else
					break;
			}
			else
				printf("42bash: command not found: %s\n", str[i]);
			free(str[i]);
			i++;
		}
		free(str[i]);
		free(str);
		buff = readline(">>");
	}

	// rl_clear_history();
	return (0);
}


int	print_output_to_file(char *filename, char *buff)
{
	FILE *fp;
	int fd;

	// what does the original function do if buff == 0 ? does it create an empty file or do nothing?
	// if file exists, should we check for permissions before overwriting it?
   if (filename == 0)
		return (-1);
   fp = fopen(filename, "w");
   if( fp == NULL) {
      perror("Error: fopen");
	  fclose(fp);
      return(-1);
   }
	fd = fp->_file; // convert pointer to a file descriptor
   if (buff != 0)
		write(fd, buff, ft_strlen(buff));
   fclose(fp);
   return (0);
}