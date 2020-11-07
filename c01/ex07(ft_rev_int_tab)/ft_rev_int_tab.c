/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/10/19 14:32:09 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/* ************************************************************************** **
**
**  Каталог сдачи задания: ex07/
**  Файлы для сдачи: ft_rev_int_tab.c	
**  Разрешенные функции: отсутствуют
**
** ************************************************************************** **
**  
**  
**  - Создайте функцию, которая переворачивает данный массив целых чисел (первый
**  элемент массива станет последним, и т.д.).
**  
**  
**  - Аргументами будут указатель на адресс первого элемента массива целых чисел
**  типа 'int' и количество целых чисел в этом массиве.
**  
**  
**  - Вот как это должно быть обьявлено:
**
**         void		ft_rev_int_tab(int *tab, int size);
**  
**
** ************************************************************************** **
**
**  - Пример:
**  
**  1 => 1
**  1,2 => 2,1
**  1,2,3,4,5 => 5,4,3,2,1
**
**
** ************************************************************************** **
**
**
**  Скомпилируй файл тест. В нем можно увидеть как работает эта функция вживую
**
** ************************************************************************** */
/* ************************************************************************** */


void	ft_rev_int_tab(int *tab, int size)
{
	int		i;
	char	temp;

	i = -1;
	while (++i < --size)
	{
		temp = tab[i];
		tab[i] = tab[size];
		tab[size] = temp;
	}
}


/* ************************************************************************** */
/* ************************************************************************** */


void	ft_rev_int_tab(int *tab, int size)
{
	int		counter;
	char	temp;

	counter = 0;
	while (counter < size - 1)
	{
		temp = tab[size];
		tab[size] = tab[counter];
		tab[counter] = temp;
		counter++;
		size--;
	}
}


/* ************************************************************************** */
/* ************************************************************************** */
