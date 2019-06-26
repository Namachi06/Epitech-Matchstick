/*
** EPITECH PROJECT, 2017
** utils
** File description:
** 	utils programm
*/

#include "../include/matchstick.h"
#include <stdio.h>

int check_char(char const **argv)
{
	int check = 0;

	for (int i = 1; argv[i] != NULL; i++) {
		for (int j = 0; argv[i][j] != '\0'; j++)
			check = my_char_isalpha(argv[i][j]);
		if (check == 1)
			return (-1);
	}
	return (0);
}

int check_error_argument(int argc, char const **argv)
{
	int check = 0;

	check = check_char(argv);
	if (check != 0 || argc != 3){
		return (-1);
	}
	return (0);
}

int convert_str_to_int(char const **argv, int argc, t_arguments *arg)
{
	if (check_error_argument(argc, argv) != -1) {
		arg->number1 = my_str_to_int(argv[1]);
		arg->number2 = my_str_to_int(argv[2]);
		if (arg->number1 < 2 || arg->number1 > 99)
			return (-1);
		return (0);
	}
	return (-1);
}

int check_end_game(t_arguments *arg, int *turn)
{
	for (int i = 1; arg->map[i] != NULL; i++) {
		for (int j = 1; arg->map[i][j] != '*'; j++) {
			if (arg->map[i][j] == '|') {
				*turn = 0;
				return (0);
			}
		}
	}
	if (*turn == 1) {
		my_putstr("I lost... snif... "
		"but I'll get you next time!!\n");
		return (1);
	} else if (*turn == 2) {
		my_putstr("You lost, too bad...\n");
		return (2);
	}
}

void count_pipes(int *count_pipe, t_arguments *arg, int line)
{
	for (int i = 1; arg->map[line][i] != '*'; i++) {
		if (arg->map[line][i] == '|')
			(*count_pipe)++;
	}
}
