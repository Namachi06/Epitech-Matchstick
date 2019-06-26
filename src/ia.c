/*
** EPITECH PROJECT, 2017
** ia
** File description:
** 	Manage ia
*/

#include "../include/matchstick.h"
#include <time.h>

int search_pipe(t_arguments *arg)
{
	for (int i = 1; arg->map[i] != NULL; i++) {
		for (int j = 1; arg->map[i][j] != '*'; j++) {
			if (arg->map[i][j] == '|') {
				return (i);
			}
		}
	}
}

void random_ia_line_and_matchstick(t_arguments *arg,
	int *numberIa1, int *numberIa2)
{
	int count_pipe = 0;

	srand(time(NULL));
	*numberIa1 = rand() % arg->number1 + 1;
	for (int i = 1; arg->map[*numberIa1][i] != '*'; i++) {
		if (arg->map[*numberIa1][i] == '|') {
			count_pipe++;
		}
	}
	if (count_pipe > 1) {
		*numberIa2 = (rand() % count_pipe) % arg->number2 + 1;
	} else if (count_pipe == 1) {
		*numberIa2 = 1;
	} else if (count_pipe == 0) {
		*numberIa1 = search_pipe(arg);
		*numberIa2 = 1;
	}
}

void ia_turn(int *line, int *nb_matchstick, t_arguments *arg, int *turn)
{
	*turn = 1;
	my_putstr("AI's turn...\n");
	random_ia_line_and_matchstick(arg, &(*line),
		&(*nb_matchstick));
	my_putstr("AI removed ");
	my_put_nbr(*nb_matchstick);
	my_putstr(" match(es) from line ");
	my_put_nbr(*line);
	my_putchar('\n');
	display_updated_map(arg, *line, *nb_matchstick);
}
