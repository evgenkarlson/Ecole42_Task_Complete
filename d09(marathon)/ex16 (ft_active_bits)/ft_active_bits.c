/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_active_bits.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/02/15 10:51:23 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int				convert(int nbr, char *base, int *nbr_final)
{
	int size_base;
	int i;

	i = 0;
	size_base = 0;
	while (base[size_base])
		size_base++;
	while (nbr)
	{
		nbr_final[i] = nbr % size_base;
		nbr = nbr / size_base;
		i++;
	}
	return (i);
}

unsigned int	ft_active_bits(int value)
{
	int				nbr_final[100];
	char			base[] = "01";
	int				i;
	unsigned int	active_bits;
	int				negativ;

	i = 0;
	negativ = 0;
	active_bits = 0;
	if (value < 0)
	{
		negativ = 1;
		value = -value;
	}
	i = convert(value, base, nbr_final);
	while (--i >= 0)
		active_bits = active_bits + (base[nbr_final[i]] - 48);
	if (negativ == 1)
		return (32 - active_bits + 1);
	return (active_bits);
}


/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */

unsigned int	ft_active_bits(int value)
{
	unsigned int count;

	count = 0;
	while (value)
	{
		count += value & 1;
		value >>= 1;
	}
	return (count);
}



/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */


unsigned int	ft_active_bits(int value)
{
	int			bits;

	bits = 0;
	while (value > 0)
	{
		if ((value & 1) == 1)
			bits += 1;
		value >>= 1;
	}
	return (bits);
}




/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */