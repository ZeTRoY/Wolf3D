/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroi <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 09:45:07 by aroi              #+#    #+#             */
/*   Updated: 2018/03/25 17:07:34 by aroi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(const char *big, const char *little)
{
	int		i;
	int		j;
	char	*str;

	i = -1;
	j = 0;
	str = (char *)big;
	if (little[0] == '\0')
		return (&str[0]);
	while (big[++i])
	{
		j = 0;
		if (big[i] == little[j])
		{
			while (big[i++] == little[j] && little[j])
				j++;
			if (little[j] == '\0')
				return (&str[i - j - 1]);
			i -= j;
		}
	}
	return (0);
}
