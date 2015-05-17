/*
** my_echo.c for  in /home/rusign/rendu/42sh/PSU_2014_42sh/bultin
** 
** Made by rusig_n
** Login   <nicolas.rusig@epitech.eu>
** 
** Started on  Thu May 14 11:51:53 2015 rusig_n
** Last update Thu May 14 11:51:53 2015 rusig_n
*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include "project.h"

void	exe_echo_opt_n(char *str, int i)
{
  i++;
  if (str[i] == 'n')
    my_putchar('\n');
  else if (str[i] == 't')
    my_putchar('\t');
  else if (str[i] == 'f')
    my_putchar('\f');
  else if (str[i] == 'a')
    my_putchar('\a');
  else if (str[i] == 'b')
    my_putchar('\b');
  else if (str[i] == 'f')
    my_putchar('\f');
  else if (str[i] == 'r')
    my_putchar('\r');
  else if (str[i] == 'v')
    my_putchar('\v');
}

void	exe_echo(char *str, int opt)
{
  int	i;

  i = -1;
  if (opt == 2)
    {
      while (str[++i] != 0)
	{
	  if (str[i] == '\\')
	    exe_echo_opt_n(str, i++);
	  else
	    my_putchar(str[i]);
	}
    }
  else
    my_putstr(str);
}

void	print_echo(char **cmd, int opt)
{
  int	i;

  i = 1;
  while (cmd[i])
    {
      if ((my_strcmp(cmd[i], "-n")) == 0 ||
	  (my_strcmp(cmd[i], "-e")) == 0 ||
	  (my_strcmp(cmd[i], "-E")) == 0)
	i++;
      else
	{
	  exe_echo(cmd[i++], opt);
	  if (cmd[i])
	    my_putchar(' ');
	}
    }
  if (opt == 0 || opt == 2)
    my_putchar(10);
}

int		my_echo(char **cmd)
{
  char		opt;
  int		i;

  i = -1;
  opt = 0;
  while (cmd[++i] != NULL)
    {
      if ((my_strcmp(cmd[i], "-n")) == 0)
	opt = 1;
      if ((my_strcmp(cmd[i], "-e")) == 0)
	opt = 2;
      if ((my_strcmp(cmd[i], "-E")) == 0)
	opt = 0;
    }
  print_echo(cmd, opt);
  return (1);
}
