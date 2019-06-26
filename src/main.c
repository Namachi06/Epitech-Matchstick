/*
** EPITECH PROJECT, 2017
** main
** File description:
** 	Programm execution
*/

#include "../include/matchstick.h"

int compute_matchstick(t_arguments *arg)
{
	int res = 0;
	int turn;

	do {
		if (res != -1)
			my_putstr("Your turn:\n");
		res = matchstick(arg, &turn);
		if (res == -1)
			continue;
		else if (res == -2)
			break;
		if (turn == 1)
			return (1);
		else if (turn == 2)
			return (2);
	} while (1);
}

int main(int argc, char const *argv[])
{
	t_arguments *arg = (t_arguments *)malloc(sizeof(t_arguments));
	int res = convert_str_to_int(argv, argc, arg);

	if (res != 0)
		return (84);
	arg->map = display(arg);
	res = compute_matchstick(arg);
	if (res == 1) {
		free(arg);
		return (1);
	} else if (res == 2) {
		free(arg);
		return (2);
	}
}
