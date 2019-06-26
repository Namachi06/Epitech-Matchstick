/*
** EPITECH PROJECT, 2017
** my_str_to_int
** File description:
** 	Convert str to number
*/
int my_str_to_int(char const *str)
{
	int nb = 0;
	int res = 0;
	int i = 0;

	while ((str[i] >= '0' && str[i] <= '9') && str[i] != '\0') {
		nb = str[i] - '0';
		res *= 10;
		res += nb;
		i++;
	}
	if (i == 0)
		return (-1);
	return (res);
}
