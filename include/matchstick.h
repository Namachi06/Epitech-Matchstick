/*
** EPITECH PROJECT, 2017
** matchstick
** File description:
** 	Include
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"

typedef struct s_arguments
{
	int number1;
	int number2;
	char **map;
} t_arguments;

// utils
int convert_str_to_int(char const **argv, int argc, t_arguments *arg);
int check_end_game(t_arguments *arg, int *turn);
void count_pipes(int *count_pipe, t_arguments *arg, int line);

// players
int player_turn(int *line, int *nb_matchstick, t_arguments *arg, int *turn);
void ia_turn(int *line, int *nb_matchstick, t_arguments *arg, int *turn);

// Display
char **display_map(t_arguments *arg);
char **add_matchstick(t_arguments *arg);
char **display(t_arguments *arg);
void display_updated_map(t_arguments *arg, int line, int nb_matchstick);

int matchstick(t_arguments *arg, int *turn);
