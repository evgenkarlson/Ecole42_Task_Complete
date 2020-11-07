/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/09/28 19:37:09 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*         команда для компиляции и одновременного запуска                    */
/*                                                                            */
/*  gcc -Wall -Werror -Wextra test.c && chmod +x ./a.out && ./a.out           */
/* ************************************************************************** */

#include <unistd.h>						/* Подключаем библиотеку содержащую функцию "write" */
#include <stdlib.h>						/* Подкоючаем библиотеку содержащую функцию для выделения памяти(malloc) и функцию для
										 * подсчета размера (sizeof) и функцию(free) для освобождения выделеной памяти */
#include "ft_list.h"					/* Подключаем заголовочный файл содержащий нужную нам структуру */


/* ************************************************************************** */

void		ft_putchar(char c)			/* Функция печати символа */
{
	write(1, &c, 1);
}

/* ************************************************************************** */

void		ft_putstr(char *str)		/* Функция печатает строку */
{
	int	i;

	i = 0;
	while (*(str + i))
		i++;
	write(1, str, i);
}

/* ************************************************************************** */

void		ft_put_list(t_list *list)	/* Функция печати связанных между собой экземпляров структуры типа 't_list' */
{
	while (list)
	{
		ft_putstr((char *)list->data);
		list = list->next;
	}
}

/* ************************************************************************** */

t_list		*ft_create_elem(void *data)	/* Функция создает экземпляр структуры типа t_list, заполняет его данными - адрес из указателя data
										 * в первый элемент экземпляра структуры, нулевой адрес во второй элемент экземпляра структуры. И в 
										 * конце функция его возвращает адрес созданого экземпляра структуры типа t_list*/
{
	t_list	*tmp;						/* Обьявляем указатель структуры типа t_list для хранения там адреса экземпляра структуры типа t_list */

	if ((tmp = (t_list *)malloc(sizeof(t_list))) == ((void *)0))/* Инициализируем указатель, сохраняя туда адрес выделеной под экземпляр памяти */
		return ((void *)0);										/* Если память не выделилась то завершаем функцию и возвращаем нулевой указатель */
	tmp->next = ((void *)0);			/* Заполняем Экземпляр структуры типа t_list записывая в этот элемент экземпляра структуры нулевой указатель */
	tmp->data = data;					/* Заполняем Экземпляр структуры типа t_list записывая в этот элемент экземпляра структуры адрес принятого
										 * в аргументах элемента неизвестного типа */
	return (tmp);						/* Завершаем функцию и возвращаем адрес созданного нами экземпляра структуры типа t_list */
}

/* ************************************************************************** */

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)	/* Функция помещает элементы списка begin_list2 в конец другого списка begin_list1 
										 * соединяя их в одну цепь связанных между собой структур  */
{
	t_list	*current;					/* Обьявим указатель для хранения адреса текущего экземпляра структуры цепи связанных между собой экземпляров */

	if (*begin_list1)					/* Если указатель с первым экземпляром цепи связанных между собой экземпляров не пуст то запускаем код, 
										 * который найдет конец первой цепи связяанных между собой экземпляров и свяжет конец этой цепи со второй 
										 * цепью связанных между собой экземпляров */
	{
		current = *begin_list1;		/* Сохраняем адрес первого экземпляра первой цепи во временный указатель для прохождения по адресам экземпляров */
		while (current->next)			/* ЗАпускаем цикл который пройдеться по всем экземплярам структуры цепи связаннх между собой экземпляров,
										 * до тех пор пока мы не втретим экземпляр структы, который не содержит адреса на след экземпляр структуры */
			current = current->next;	/* Перезаписываем указатель хранящий адресс текущего экзепляра структуры на адресс следующего экзепляра 
										 * структуры для работы в след итерации цикла со следующим экзепляром структуры */
		current->next = begin_list2;	/* Сохраняем в указателе найденого нами последнего экземпляра структуры адрес первого экземпляра второй цепи 
										 * связанных между собой структур */
	}
	else								/* Если указатель с первым экземпляром цепи связанных между собой экземпляров пуст то */
		*begin_list1 = begin_list2;		/* Сохраняем адрес первого экземпляра второй цепи в указатель хранящий адрес первого экземпляра первой цепи */
}



int			main(void)
{
	t_list	*list1;						/* Обьявим указатель структуры типа t_list для хранения адреса экземпляра структуры типа t_list */
	t_list	*list2;

	list1 = ft_create_elem("Bro ");		/* Запустим фунцию которая создаст экземпляр структуры типа t_list, заполнит его элементы(взяв для этого часть
										 * данных которыем мы ей отправим) и вернет адрес этого экземпляра структуры типа t_list,
										 * который мы сохраним в указателе на экземпляр структуры типа t_list */
	list1->next = ft_create_elem("Hey ");/* Запустим фунцию которая создаст экземпляр структуры типа t_list, заполнит его элементы(взяв для этого часть
										 * данных которыем мы ей отправим) и вернет адрес этого экземпляра структуры типа t_list 
										 * И сохранит этот адрес в указателе на экземпляр структуры типа t_list, который хранится в одном из элементов 
										 * текущего экземпляра структуры, адрес которой хранится в указателе 'list' */
	/* И создадим еще дополнительно несколько экземпляров структуры, которые свяжем между собой и с предыдущим экземпляром */
	list1->next->next = ft_create_elem("Hello ");
	list2 = ft_create_elem("My ");
	list2->next = ft_create_elem("Cool ");
	list2->next->next = ft_create_elem("Friend ");


	ft_list_merge(&list1, list2);		/* Помещаем элементы списка list2 в конец другого списка list1 соединяя их в одну цепь связанных между собой
										 * структур */
	ft_put_list(list1);
	ft_putchar('\n');					/* Печатаем символ переноса строки для кореектного отображения вывода */
	return (0);							/* Завершаем функцию и возвращаем ноль */
}