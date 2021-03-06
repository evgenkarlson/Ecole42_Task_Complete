/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/10/11 23:26:57 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*         команда для компиляции и одновременного запуска программы          */
/*                                                                            */
/*  gcc -Wall -Werror -Wextra test.c && chmod +x ./a.out && ./a.out	   	      */
/* ************************************************************************** */


#include <unistd.h>

void	ft_putchar(char c)			/* Функция вывода символа через стандартный поток вывода */
{
	write(1, &c, 1);
}

/* ************************************************************************** */
/* ************************************************************************** */

void	ft_putnbr(int nb)     		/* Функция вывода числа */
{
	int	temp;						/* Обьявляем переменную для временного хранения данных переменной 'nb' */
	int	size;						/* Обьявляем переменную для хранения размера числа*/

	size = 1;						/* Установим ей начальный размер */

	if (nb < 0)						/* Проверяем яляется полученное нами число в 'nb' отрицательным */	
	{
		ft_putchar('-');			/* Если число отрицательное, то мы печатаем символ минуса '-' */ 
		nb = -nb;					/* Делаем содержимое переменной 'nb' положительным, с помощью хитрости(nb = -nb), помня из математики, что минус на минус дает плюс */
	}
	if (nb == -2147483648)
	{	
		ft_putchar('2');
		nb = 147483648;
	}
	temp = nb;						/* Сохраним в переменную 'temp' наше число 'nb' для вычисления размера этого числа */

	while ((temp /= 10) > 0)		/* Вычисляем размер числа c помощью накопления количества умноженых десяток друг на друга */ 
		size *= 10;					/* Если результ деления нашего числа в 'temp' на 10 больше нуля то увеличиваем переменную 'size' умножив ее содержимое на 10 */

									/* НУЖО ПОМНИТЬ что при делении целого числа на целое результат сохраняемый в переменной типа 'int' будет без плавающей точки. 
									** она автоматически отбрасывается */ /* Пример: делим 4  на 10  в итоге результат будет 0.4 но в переменной типа 'int' сохраниться
									** только 0, потому что всё после точки в числе отбрасывается и в целочисленную переменную не записывается. */

	temp = nb;						/* Восстановим расстерзаное делением число в переменную 'temp'. Оно нам снова понадобится 
									** для того чтобы отделить цифры нужного нам числа и напечатать по отдельности */

	while (size)					/* проверяем длинну числа если длинна еще не равна нулю (в результате уменьшения на 10 в цикле) то продолжаем работу цикла */
	{
		ft_putchar((char)((temp / size)) + '0');	/* делим число на размер, который у нас получился */   /* тут тоже хитрость */  
									/* допустим размер полученогонами числа 345 получисля равным 100 */ 
									/* деля 345 на 100  мы получим 3.45*/ /* 0.45 отбрасывается по тому что идет приведение к целому числу */ /* и остаеться 3 */
									/* Так вот мы и отделяем 3 от 45 и уже можем ее напечатать тройку прибавив к ней 48, чтоб полуить код символа '3' */

		temp %= size;				/* Здесь с помощь деления числа temp (в примере у нас это 345) по модулю на size (в примере у нас это 100) мы получим 
									** оставшуюся часть без первого символа temp ( т.е у нас получится 45. Тройка канула в лету. Так мы ее отбрасываем чтоб потом,
									** на новой итерации цикла напечатать 4 и 5 и т.д по мере отделения и печати чисел,  и помере того как size уменьшается */

		size /= 10;					/* после то как отделили 3 от 45 в числе 345 и после того как оставили себе только 45 для дальнейшего отделения. число 100 нам больше не нужно.
									** Так что делим size на 10 чтобы в след итерации число 45 уже делилось на 10 отдавая 4 на печать, и еще 45 делилось по модулю на 10 сохраняя 5 
									** на следующую итерацию, потом снова уменьшение size на 10 (чтобы можно было работать с temp, которое теперь уже хранит 5). 
									** Теперь 5 делм на 1 получаем пять отдаем его на печать, 5 деленное по модулю на 1 сохраняет в переменную 0 но это нам уже не нужно.
									** Потому что дальше size делится на 10 снова и размер size становится равным нулю. А при след итерации цикл будет проверять размер size 
									** и если он равен 0 то цикл завершается */
									/* И жили они долго и счастливо, конец */
	}
}

/* ************************************************************************** */
/* ************************************************************************** */

int		ft_ctoi(char c)				/* Функция переводит символ в число и возвращает его. (символ '0' вернется как число 0, а не 48)
									** Если символ условиям не соответствует то возвращается (-1)*/
{
	if (c >= '0' && c <= '9')		/* Если символ числа от 0 до 9 */
		return (c - '0');			/* То вычесть из символа числа символ нуля чтобы в остатке осталось только само число в диапазоне до 9 включительно */
	if (c >= 'A' && c <= 'F')		/* Если символ в пределах от 'A' до 'F' то значит перед нами число в пределах от 10 до 16 включительно */
		return (c - 'A' + 10);		/* Чтобы его достать нужно из символа вычесть 'A' и к получившемуся числу прибавить 10.
									 * После завершаем функцию и возвращаем добытое число */
	if (c >= 'a' && c <= 'f')		/* Если символ в пределах от 'a' до 'f' то значит перед нами число в пределах от 10 до 16 включительно */
		return (c - 'a' + 10);		/* Чтобы его достать нужно из символа вычесть 'a' и к получившемуся числу прибавить 10.
									 * После завершаем функцию и возвращаем добытое число */
	return (-1);					/* Если символ не соответсвует ни одному условию то завершаем функцию и возвращаем (-1). */
}

/* ************************************************************************** */
/* ************************************************************************** */

int		ft_pow(int nb, int power)	/* Функция возведения в степень */
{
	int	result;						/* обьявляем переменную для хранения добытого результата */

	result = 1;						/* инициализируем ее единицей для начала вычислений результата возведения в степень */
	if(power < 0)					/* Проверяем соответствует ли число в степени условиям */
		return (0);					/* Если не соответствует то завершаем функцию и возвращаем ноль */
	if(power == 0)					/* Проверяем соответствует ли число в степени условиям */
		return (1);					/* Если не соответствует то завершаем функцию и возвращаем ноль */
	while (power--)					/* Запускаем цикл который умножит переменную 'result' на 'nb' столько раз сколько записано в 'power'. Возведет в 'nb' в степень 'power'. */
		result *= nb;				/* Умножая 'result' на 'nb' и сохраняя результат в той же переменной 'result' столько раз сколько записано в 'power'  
									 * мы сможем получить результат возведения в степень 'power' числа 'nb'. */
	return (result);				/* Завершаем функцию и возвращаем результат возведения в степень */
}

/* ************************************************************************** */
/* ************************************************************************** */

int		ft_check_base(char *base)		/* Функция проверки массива с нужной на системой счисления на корректность. Она принимает 
										** адресс массива и возвращает, если все корректно, число отражающее размер  проверяемого
										** базового типа. Если же массив не пройдет проверку на корректность, то функция вернет '0' */
{
	int	i;								/* обьявляем счетчик */
	int	z;								/* обьявляем счетчик */

	i = 0;								/* инициализируем счетчик нулем чтобы начать с начала массива */
	if (!base || !base[1])				/* Проверяем наличие в массиве данных. Если массив пуст */
		return (0);						/* то мы завершаем функцию и возвращаем '0' */
	while (base[i])						/* Запускаем цикл пройдется по всему массиву символов до тех пор пока мы не дойдетдо конца массива.
										** Он проверит относится ли каждый элемент массива только к символам цифр или букв алфавита, а так 
										** же выяснит не повторяется ли символ в какой либо части текущего массива. */
	{
		if (!((base[i] >= '0' && base[i] <= '9') || (base[i] >= 'a' \
				&& base[i] <= 'z') || (base[i] >= 'A' && base[i] <= 'Z'))) /* Провеяем каждый елемент массива, чтобы там были только символы
										** чисел или букв алфавита */
			return (0);					/* Если в массиве есть что то не нужное нам, то мы завершаем функцию и возвращаем '0' */
										/* Теперь проверим повторяется ли текущий символ где ли бо еще в массиве с помощью цикла ниже */
		z = i + 1;						/* Используем переменную 'z' для хранения числа указывающего на ячейку, которая следует после той
										** ячейки, на которую указывает число, в переменной 'i' */
		while (base[z])					/* Запускаем цикл, который проверит все ячеки которые следуют за теми на которые указывает переменная
										** 'i' и выясним повторяется ли текущий символ в какой либо части текущего массива символов */
		{
			if (base[i] >= base[z])		/* Если символ из ячейки, на которую указывает переменная 'i', такой же что и в другой ячейке массива, 
										** на котрую указывает переменная 'z', или больше по значению */ 
				return (0);				/* То мы завершаем функцию и возвращаем '0' */
			z++;						/* Если же похожий или меньший символ не найден, то мы увеличиваем содержимое переменной 'z' для перехода
										** к проверке след ячейки массива и продолжаем цикл, пробегаясь по остальным ячейкам массива, сравнивая их
										** с символом из ячейки, на котрую указывает переменная 'i' */
		}
		i++;							/* Если мы дошли до сюда, значит текущий символ массива из ячейки на которую указывает переменная 'i'
										** соответсвует условиям и мы увеличиваем увеличиваем содержимое переменной 'i' для перехода к след ячейке
										** массива и проверке её содержимого на соответствие нашим условиям */
	}
	return (i);							/* Если дошли до сюда, значит массив проверен и соответсвует нашим условиям.
										** Завершаем функцию и возвращаем размер базового типа, как знак положительного прохождения теста */
}

/* ************************************************************************** */
/* ************************************************************************** */

int		ft_atoi_base(char *str, char *base)/* Функция преобразующая строку(str) определенного базового типа в десятичное число */
{
	int		num;						/* Обьявляем перменную, в которую мы положим преобразованное число */
	int		negative;					/* Обьявляем перменную для хранения информации о том отрицательное это число или положительное */
	int		i;							/* Обьявляем перменную для счетчика, с помощью которого мы пройдемся по массиву переобразовывая каждый символ */
	int		pow;						/* Обьявляем перменную для счетчика, который будет говорить о том в какую степень возвести добытое из символа 
										 * число в зависимости от позиции ячейки добытого из символа числа */
	int		base_type;					/* Обьявляем переменную для хранения основания числа отражающего систему счисления, которая нам будет 
										** нужна для вычислений. Это число мы получим после проверки массива хранящего нужную нам систему счисления */

	negative = 1;						/* Инициализируем единицей переменную хранящую состояние. В конце функции она умножается на добытое число,
										** в случае если знак у числа в строке будет отрицательным. Это для того чтобы применить знак к добытому числу */
	i = 0;								/* Инициализируем нулем переменную счетчика чтобы начать работать с массивом символов с нулевой позиции */
	if((base_type = ft_check_base(base)))/* Запускаем проверку соответствия массива содержащего символы нужной нам системы счисления
										** и сохраняем результат в переменную 'base_type'.
										** Проверяем число, полученое после проверки массива, с нужной системой счисления. Если проверка прошла успешно,
										** то в переменной должно находиться положительное число. Если число положительно, то мы запускаем код внутри  */
	{
		if (*str == '-')				/* Если нулевая ячейка, массива символов 'str', хранит символ, который равен отрицательному знаку */
		{
			i++;						/* то переходим к след ячейке */
			negative = -1;				/* А в переменную 'negative' записываем (-1), чтобы потом, перед возвращением добытого числа ,умножить его
										** на эту переменную и получить такое же отрицательное число, какое было принято на преобразование */
		}
		while (str[i])					/* Запускаем цикл, который пройдется мо массиву символов(строке) и посчитает его длинну */
			i++;
		pow = 0;						/* Инициализируем нулем переменную указывающую на степень, в которую нужно будет возводить число отражающее
										** систему счисления */
		num = 0;						/* Инициализируем нулем переменную для хранения добытого числа */
		while (--i >= 0)				/* Запускаем цикл который начиная с конца масива перобразует символы в цифры и собирает их в одно число работая 
										** до тех пор пока не пройдет по всем ячейкам */
		{
			if ((ft_ctoi(str[i]) != -1) && (ft_ctoi(str[i]) < base_type))/* Если символ в ячейке соответствует условиям то запускаем преобразование символа */ 
				num += ft_ctoi(str[i]) * ft_pow(base_type, pow++);	/* получаем из символа число и умножаем это число на его систему счисления возведенную
																	** в степень, которая равна позиции символа в строке. И в конце сохраняем все в "num", 
																	** прибавля полученое к тому что там уже хранится */
		}
		return (num * negative);		/* Завершаем функцию и возвращаем полученый результат умноженый на единицу, хранящую полученный нами знак 
										** отрицательности или положительности конвертируемого числа */
	}
	return (0);
}

/* ************************************************************************** */
/* ************************************************************************** */

int     main(void)
{
	char	*base;
	char	*str;

	str = "12fdb3";
	base = "0123456789ABCDEF";
    ft_putnbr(ft_atoi_base(str, base));	/* Отправляем в функцию нужную нам строку с нужным числом в одном аргументе и другую строку с описанием базового типа этого числа
										** для преобразования числа из имеющейся системы счисления в десятичную систему счисления.
										** А возвращаемый результат отправляем на печать в функцию печати числа */
    return (0);							/* Завершаем функцию и возвращаем ноль */
}