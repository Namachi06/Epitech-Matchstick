/*
** EPITECH PROJECT, 2017
** my_char_isalpha
** File description:
** 	Return 0 if te char is an alpha
*/

int my_char_isalpha(char c)
{
	if (!(c >= 'A' && c <= 'Z') && !(c >= 'a' && c <= 'z')) {
		return (0);
	}
	return (1);
}
