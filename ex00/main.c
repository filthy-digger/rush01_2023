/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agabasov <agabasov@student.42lausanne      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 22:15:33 by agabasov          #+#    #+#             */
/*   Updated: 2023/06/18 19:47:20 by lfick            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"


int	main(int argc, char **argv)
{
	size_t	size;
	int *uinput;
	int **solution;

	size = 4;
	if (argc == 1)
	{
		puterr("no input");
		return 1;
	}
	else if (argc > 2)
	{
		puterr("extraneous arguments");
		return 1;
	}
	uinput = parse_uinput(argv[1], size);
	if (uinput == NULL)
	{
		puterr("bad format\n");
		return 1;
	}
	solution = gen_solution(size, uinput);
	if (solution == NULL)
	{
		puterr("no solution");
		return 1;
	}
	else
		print_matrix(solution, size, size);
	return 0;
}
