/*
** EPITECH PROJECT, 2017
** matchstick
** File description:
** 	Programm Matchstick
*/

#include "../include/matchstick.h"

int matchstick(t_arguments *arg, int *turn)
{
	int line;
	int nb_matchstick;
	int res;

	res = player_turn(&line, &nb_matchstick, arg, &(*turn));
	if (res == -1)
		return (-1);
	else if (res == -2)
		return (-2);
	res = check_end_game(arg, &(*turn));
	if (res != 0)
		return (res);
	ia_turn(&line, &nb_matchstick, arg, &(*turn));
	res = check_end_game(arg, &(*turn));
	if (res != 0)
		return (res);
}
