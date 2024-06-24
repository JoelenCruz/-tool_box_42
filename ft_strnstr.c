/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everton <everton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 12:58:01 by evdos-sa          #+#    #+#             */
/*   Updated: 2024/01/14 12:50:07 by everton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
A função ft_strnstr() localiza a primeira ocorrência da string little na string big,
onde não mais do que len caracteres são pesquisados. Os caracteres que aparecem após
um caractere `\0' não são pesquisados.
Se little é uma string vazia, big é retornada; se little não ocorre em big, NULL é retornado;
caso contrário, um ponteiro para a primeira caracter de little em big é retornado.
*/
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if ((len == 0 && !*little) || !*little)
		return ((char *) big);
	if (len == 0)
		return (NULL);
	while (big[i] != '\0' && i < len)
	{
		j = 0;
		while (big[i + j] != '\0' && little[j] != '\0'
			&& big[i + j] == little[j] && (i + j) < len)
		{
			if (little[j + 1] == '\0')
				return ((char *)&(big[i]));
			j++;
		}
		i++;
	}
	return (NULL);
}

/*
int	main()
{
	const char *largestring = "ls -l >>za.txt";
	const char *smallstring = ">>";
	char *ptr;

	ptr = ft_strnstr(largestring, smallstring, strlen(largestring));
	printf("The string starts at position: %s\n", ptr);

	return (0);
}
*/
