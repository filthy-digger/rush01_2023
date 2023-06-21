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
	unsigned int		*uinput;
	int		**solution;

	size = 4;
	if (argc == 1)
		puterr("no input");
	else if (argc > 2)
		puterr("extraneous arguments");
	else
	{
		uinput = parse_uinput(argv[1], size);
		if (uinput == NULL)
		{
			puterr("bad format\n");
			return (1);
		}
		solution = gen_solution(size, uinput);
		if (solution == NULL)
			puterr("no solution");
		else
			print_matrix(solution, size, size);
		return (0);
	}
	return (1);
}
