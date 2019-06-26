/*
** EPITECH PROJECT, 2017
** player
** File description:
** 	Manage player turn
*/

#include "../include/matchstick.h"

int check_line_limit(int line, t_arguments *arg, char *line_str)
{

	if (line == -1) {
		my_putstr("Error: invalid input (positive number expected)\n");
		return (-1);
	} else if (line <= 0 || line > arg->number1) {
		my_putstr("Error: this line is out of range\n");
		return (-1);
	} else if (line < 0) {
		my_putstr("Error: you have to remove at least one match\n");
		return (-1);
	}
	return (0);
}

int check_stick_limit(int nb_matchstick, t_arguments *arg, int line)
{
	int count_pipe = 0;

	count_pipes(&count_pipe, arg, line);
	if (nb_matchstick == - 1) {
		my_putstr("Error: invalid input (positive number expected)\n");
		return (-1);
	} else if (nb_matchstick > arg->number2) {
		my_putstr("Error: you cannot remove more than ");
		my_put_nbr(arg->number2);
		my_putstr(" matches per turn\n");
		return (-1);
	} else if (nb_matchstick == 0) {
		my_putstr("Error: you have to remove at least one match\n");
		return (-1);
	} else if (nb_matchstick > count_pipe) {
		my_putstr("Error: not enough matches on this line\n");
		return (-1);
	}
	return (0);
}

int read_player_line_and_number_matchstick(int *line, int *nb_matchstick,
	t_arguments *arg)
{
	char *line_str;
	char *nb_matchstick_str;
	int res;

	line_str = get_next_line(0);
	if (line_str == NULL)
		return (-2);
	*line = my_str_to_int(line_str);
	res = check_line_limit(*line, arg, line_str);
	if (res != 0)
		return (-1);
	my_putstr("Matches: ");
	nb_matchstick_str = get_next_line(0);
	if (nb_matchstick_str == NULL)
		return (-2);
	*nb_matchstick = my_str_to_int(nb_matchstick_str);
	res = check_stick_limit(*nb_matchstick, arg, *line);
	if (res != 0)
		return (-1);
	return (0);
}

int player_turn(int *line, int *nb_matchstick, t_arguments *arg, int *turn)
{
	int res;

	*turn = 2;
	my_putstr("Line: ");
	res = read_player_line_and_number_matchstick(&(*line),
			&(*nb_matchstick), arg);
	if (res == -1)
		return (-1);
	else if (res == -2)
		return (-2);
	my_putstr("Player removed ");
	my_put_nbr(*nb_matchstick);
	my_putstr(" match(es) from line ");
	my_put_nbr(*line);
	my_putchar('\n');
	display_updated_map(arg, *line, *nb_matchstick);
	return (0);
}
