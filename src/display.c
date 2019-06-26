/*
** EPITECH PROJECT, 2017
** display
** File description:
** 	Display map
*/

#include "../include/matchstick.h"

char **add_matchstick(t_arguments *arg)
{
	int increase_matchstick = 1;

	for (int i = 1; arg->map[i] != NULL; i++) {
		for (int j = 0; j < increase_matchstick; j++) {
			arg->map[i][arg->number1 + j - i + 1] = '|';
		}
		if (arg->map[i + 2] == NULL) {
			break;
		}
		increase_matchstick += 2;
	}
	return (arg->map);
}

char **display_map(t_arguments *arg)
{
	char **game_display;
	int number_line = arg->number1 + 2 + 1;
	int length_line = arg->number1 * 2 + 1;

	game_display = malloc(sizeof(char *) * number_line + 1);
	for (int i = 0; i < number_line; i++) {
		game_display[i] = malloc(sizeof(char) * length_line + 1);
		for (int j = 0; j < length_line; j++) {
			if (i == 0 || i == (number_line - 1) || j == 0 ||
				j == (length_line - 1)) {
				game_display[i][j] = '*';
			} else {
				game_display[i][j] = ' ';
			}
		}
		game_display[i][length_line] = '\0';
	}
	game_display[number_line - 1] = NULL;
	return (game_display);
}

void display_updated_map(t_arguments *arg, int line, int nb_matchstick)
{
	int index_last_pipe_line = 0;
	int count_space = 0;

	for (int p = 1; arg->map[line][p] != '|'; p++) {
		count_space++;
	}
	for (int i = 1; arg->map[line][i] != '*'; i++) {
		if (arg->map[line][i] == '|') {
			index_last_pipe_line++;
		}
	}
	for (int j = index_last_pipe_line; nb_matchstick > 0; j--) {
		arg->map[line][j + count_space] = ' ';
		nb_matchstick--;
	}
	for (int n = 0; arg->map[n] != NULL; n++) {
		my_putstr(arg->map[n]);
		my_putchar('\n');
	}
	my_putchar('\n');
}

char **display(t_arguments *arg)
{
	char **display;

	arg->map = display_map(arg);
	display = add_matchstick(arg);
	for (int i = 0; display[i] != NULL; i++) {
		my_putstr(display[i]);
		my_putchar('\n');
	}
	my_putchar('\n');
	return (display);
}
