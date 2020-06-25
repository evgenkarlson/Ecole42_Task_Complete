/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/02/15 10:51:23 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*	команда для компиляции и одновременного запуска                           */
/*                                                                            */
/*  gcc -Wall -Werror -Wextra test.c && chmod +x ./a.out && ./a.out	   	      */
/* ************************************************************************** */

#include <unistd.h>						/* Подключаем библиотеку содержащую функцию "write" */
#include <stdlib.h>						/* Подкоючаем библиотеку содержащую функцию для выделения памяти(malloc) и функцию для
										 * подсчета размера (sizeof) и функцию(free) для освобождения выделеной памяти */
#include "ft_list.h"					/* Подключаем заголовочный файл содержащий нужную нам структуру */

/* ************************************************************************** */

void	ft_putchar(char c)				/* Функция печати символа */
{
	write(1, &c, 1);
}

/* ************************************************************************** */

void	ft_putstr(char *str)			/* Функция печати строки */
{
	while(*str)
		ft_putchar(*str++);
}

/* ************************************************************************** */


t_list		*ft_create_elem(void *data)	/* функция создает экземпляр структуры типа t_list, заполняет его данными, и его возвращает адрес */
{
	t_list	*tmp;						/* Обьявляем указатель структуры типа t_list для хранения там адреса экземпляра структуры типа t_list */

	if ((tmp = (t_list *)malloc(sizeof(t_list))) == ((void *)0))/* Инициализируем указатель, сохраняя туда адресс выделеной под экземпляр памяти */
		return ((void *)0);										/* Если память не выделилась то завершаем функцию и возвращаем нулевой указатель */
	tmp->next = ((void *)0);			/* Заполняем Экземпляр структуры типа t_list записывая в этот элемент структуры нулевой указатель */
	tmp->data = data;					/* Заполняем Экземпляр структуры типа t_list записывая в этот элемент структуры адресс принятого в аргументах элемента неизвестного типа */
	return (tmp);						/* Завершаем функцию и возвращаем адрес созданного нами экземпляра структуры типа t_list */
}


int			main(void)
{
	t_list	*list;						/* Обьявим указатель на экземпляр структуры типа t_list */

	list = ft_create_elem("Hello");		/* Запустим фунцию котрая создаст структуры экземпляр типа t_list, заполнит его элементы(взяв для этого часть данных которыем мы ей отправим)
										 * и вернет адресс этого экземпляра структуры типа t_list */
	ft_putstr((char *)(list->data));	/* Для проверки полученого эземпляра структуры типа t_list, мы напечатаем содежимое его элемента 'data' */
	ft_putchar('\n');					/* Печатаем символ переноса строки для корректного отображения вывода */
	ft_putstr((char *)((*list).data));	/* Для демнострации другого способа доступа к элементам экемпляра, мы еще раз напечатаем содежимое его элемента 'data' */
	ft_putchar('\n');					/* Печатаем символ переноса строки для корректного отображения вывода */

	free(list);							/* Освобождаем Память, которую мы выделили для хранения экземпляра структуры */

	return (0);							/* Завершаем функцию и возвращаем ноль */
}

/*
int			main(void)
{
	t_list *head;

	head = ft_create_elem("Hello");
	head->next = ft_create_elem("My");
	head->next->next = ft_create_elem("Friend");
	while (head)
	{
		printf("%s", head->data);
		head = head->next;
	}
	return 0;
}
*/