/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gauffret <gauffret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 10:10:21 by gauffret          #+#    #+#             */
/*   Updated: 2017/12/15 17:38:39 by fbertoia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <locale.h>
#include <stdio.h>

#define	TEST_BASE 0
#define TEST_C 0
#define TEST_S 0
#define TEST_LC 0
#define TEST_LS 0
#define TEST_P 0
#define TEST_D 0
#define TEST_LD 0
#define TEST_O 1
#define TEST_LO 1
#define TEST_U 1
#define TEST_LU 1
#define TEST_X 1
#define TEST_BAZAR 1
#define TEST_CRASH 1

/*
 * #define TEST_F 1
 * #define TEST_E 1
 * #define TEST_G 1
 * #define TEST_B 1
 * #define TEST_NO 1 //leaks
 * #define TEST_COLOR 1 //leaks
 * #define TEST_CHECKER 1
 * */

#define INFINITY 0

void	ft_print_result(int mr, int or, int line)
{
	static int c = 0;
	printf("\033[33m[%d]\033[0m MINE = %i - ORIG = %i", c, mr, or);
	if (mr == or)
		printf("\t\033[32m✔\033[0m");
	else
		printf("\t\033[31m✘ - (failed between lines %i and %i)\033[0m",
				line - 3, line);
	printf("\n---------------\n");
	c++;
}

int	main(void)
{
	int			or, mr;
	char		**test;
	char*		l;
	int			dec = 654321;
	long int	ldec = 3659855789;

	l = setlocale(LC_ALL, "");
	test = malloc(sizeof(char*));
	or = 0;
	mr = 0;
	if (TEST_BASE)
	{
		printf("\e[38;5;6m\t\t======== BASIC TEST ========\033[0m\n");

		mr = ft_printf("MINE>\t[%c]\n", 'c');
		or = printf("ORIG>\t[%c]\n", 'c');
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%[RED]%b%[NC]\n", -254);
		or = printf("ORIG>\t[%d %ld %lld %hd %hhd %zd %jd]\n", -254, -546156465, -4161651651, -521, -512, -56, -955);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%s]\n", "Chaine a afficher");
		or = printf("ORIG>\t[%s]\n", "Chaine a afficher");
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%C]\n", 177);
		or = printf("ORIG>\t[%C]\n", 177);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%S]\n", L"Chaine a afficher");
		or = printf("ORIG>\t[%S]\n", L"Chaine a afficher");
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%p]\n", test);
		or = printf("ORIG>\t[%p]\n", test);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%d]\n", 42);
		or = printf("ORIG>\t[%d]\n", 42);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%D]\n", 3216549871);
		or = printf("ORIG>\t[%D]\n", 3216549871);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%o]\n", 953);
		or = printf("ORIG>\t[%o]\n", 953);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%O]\n", 3216549871);
		or = printf("ORIG>\t[%O]\n", 3216549871);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%u]\n", 953);
		or = printf("ORIG>\t[%u]\n", 953);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%U]\n", 3216549871);
		or = printf("ORIG>\t[%U]\n", 3216549871);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%x]\n", 3216549871);
		or = printf("ORIG>\t[%x]\n", 3216549871);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%f]\n", 138.56);
		or = printf("ORIG>\t[%f]\n", 138.56);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%e]\n", 138.56);
		or = printf("ORIG>\t[%e]\n", 138.56);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%g]\n", 138.56);
		or = printf("ORIG>\t[%g]\n", 138.56);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%d][%d]\n", -2147483648, 2147483647);
		or = printf(   "ORIG>\t[%d][%d]\n", -2147483648, 2147483647);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%u][%u]\n", 0, 4294967295);
		or = printf(   "ORIG>\t[%u][%u]\n", 0, 4294967295);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%o][%o]\n", 0, 4294967295);
		or = printf(   "ORIG>\t[%o][%o]\n", 0, 4294967295);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%x][%x]\n", 0, 4294967295);
		or = printf(   "ORIG>\t[%x][%x]\n", 0, 4294967295);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%lld]\n", 9223372036854775807);
		or = printf(   "ORIG>\t[%lld]\n", 9223372036854775807);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%llu]\n", 18446744073709551615);
		or = printf(   "ORIG>\t[%llu]\n", 18446744073709551615);
		ft_print_result(mr, or, __LINE__);

		printf("\e[38;5;6m\t\t======== end BASIC TEST =====\033[0m\n\n");
	}
	if (TEST_C)
	{
		printf("\e[38;5;6m\t\t======== %%c ========\033[0m\n");

		mr = ft_printf("MINE>\t[%c]\n", 'c');
		or = printf("ORIG>\t[%c]\n", 'c');
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%10c]\n", 'c');
		or = printf("ORIG>\t[%10c]\n", 'c');
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%+10c]\n", 'c');
		or = printf("ORIG>\t[%+10c]\n", 'c');
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%-10c]\n", 'c');
		or = printf("ORIG>\t[%-10c]\n", 'c');
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%010c]\n", 'c');
		or = printf("ORIG>\t[%010c]\n", 'c');
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%+-10c]\n", 'c');
		or = printf("ORIG>\t[%+-10c]\n", 'c');
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%0+10c]\n", 'c');
		or = printf("ORIG>\t[%0+10c]\n", 'c');
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%0-10c]\n", 'c');
		or = printf("ORIG>\t[%0-10c]\n", 'c');
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%+-010c]\n", 'c');
		or = printf("ORIG>\t[%+-010c]\n", 'c');
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%*c]\n", 7, 'c');
		or = printf("ORIG>\t[%*c]\n", 7, 'c');
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%10*c]\n", 7, 'c');
		or = printf("ORIG>\t[%10*c]\n", 7, 'c');
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%0c]\n", 'c');
		or = printf("ORIG>\t[%0c]\n", 'c');
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%.10c]\n", 'c');
		or = printf("ORIG>\t[%.10c]\n", 'c');
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%.*c]\n", 5, 'c');
		or = printf("ORIG>\t[%.*c]\n", 5, 'c');
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%10.5c]\n", 'c');
		or = printf("ORIG>\t[%10.5c]\n", 'c');
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%*.*c]\n", 5, 10, 'c');
		or = printf("ORIG>\t[%*.*c]\n", 5, 10, 'c');
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%#c]\n", 'c');
		or = printf("ORIG>\t[%#c]\n", 'c');
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[% c]\n", 'c');
		or = printf("ORIG>\t[% c]\n", 'c');
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%    c]\n", 'c');
		or = printf("ORIG>\t[%    c]\n", 'c');
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[% -10c]\n", 'c');
		or = printf("ORIG>\t[% -10c]\n", 'c');
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%#20-0.5+10c]\n", 'c');
		or = printf("ORIG>\t[%#20-0.5+10c]\n", 'c');
		ft_print_result(mr, or, __LINE__);

		printf("\e[38;5;6m\t\t======== end %%c =====\033[0m\n\n");
	}
	if (TEST_S)
	{
		printf("\e[38;5;6m\t\t======== %%s ========\033[0m\n");

		mr = ft_printf("MINE>\t[%s]\n", "Text");
		or = printf("ORIG>\t[%s]\n", "Text");
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%s]\n", "");
		or = printf("ORIG>\t[%s]\n", "");
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%s]\n", NULL);
		or = printf("ORIG>\t[%s]\n", NULL);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%10s]\n", "Text");
		or = printf("ORIG>\t[%10s]\n", "Text");
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%*s]\n", 10, "Text");
		or = printf("ORIG>\t[%*s]\n", 10, "Text");
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%0s]\n", "Text");
		or = printf("ORIG>\t[%0s]\n", "Text");
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%.10s]\n", "Text");
		or = printf("ORIG>\t[%.10s]\n", "Text");
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%.0s]\n", "Text");
		or = printf("ORIG>\t[%.0s]\n", "Text");
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%.*s]\n", 10, "Text");
		or = printf("ORIG>\t[%.*s]\n", 10, "Text");
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[% s]\n", "Text");
		or = printf("ORIG>\t[% s]\n", "Text");
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%+s]\n", "Text");
		or = printf("ORIG>\t[%+s]\n", "Text");
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%-s]\n", "Text");
		or = printf("ORIG>\t[%-s]\n", "Text");
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%0s]\n", "Text");
		or = printf("ORIG>\t[%0s]\n", "Text");
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%#s]\n", "Text");
		or = printf("ORIG>\t[%#s]\n", "Text");
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[% 2s]\n", "Text");
		or = printf("ORIG>\t[% 2s]\n", "Text");
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[% .2s]\n", "Text");
		or = printf("ORIG>\t[% .2s]\n", "Text");
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%+15s]\n", "Text");
		or = printf("ORIG>\t[%+15s]\n", "Text");
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%-15s]\n", "Text");
		or = printf("ORIG>\t[%-15s]\n", "Text");
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%-9.3s]\n", "Text");
		or = printf("ORIG>\t[%-9.3s]\n", "Text");
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%+-0s]\n", "Text");
		or = printf("ORIG>\t[%+-0s]\n", "Text");
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%#+-010.1s]\n", "Text");
		or = printf("ORIG>\t[%#+-010.1s]\n", "Text");
		ft_print_result(mr, or, __LINE__);

		printf("\e[38;5;6m\t\t======== end %%s =====\033[0m\n\n");
	}
	if (TEST_LC)
	{
		printf("\e[38;5;6m\t\t======== %%C ========\033[0m\n");

		mr = ft_printf("MINE>\t[%C]\n", 9876);
		or = printf("ORIG>\t[%C]\n", 9876);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%10C]\n", 9876);
		or = printf("ORIG>\t[%10C]\n", 9876);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%+10C]\n", 9876);
		or = printf("ORIG>\t[%+10C]\n", 9876);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%-10C]\n", 9876);
		or = printf("ORIG>\t[%-10C]\n", 9876);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%010C]\n", 9876);
		or = printf("ORIG>\t[%010C]\n", 9876);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%+-10C]\n", 9876);
		or = printf("ORIG>\t[%+-10C]\n", 9876);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%0+10C]\n", 9876);
		or = printf("ORIG>\t[%0+10C]\n", 9876);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%0-10C]\n", 9876);
		or = printf("ORIG>\t[%0-10C]\n", 9876);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%+-010C]\n", 9876);
		or = printf("ORIG>\t[%+-010C]\n", 9876);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%*C]\n", 7, 9876);
		or = printf("ORIG>\t[%*C]\n", 7, 9876);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%10*C]\n", 7, 9876);
		or = printf("ORIG>\t[%10*C]\n", 7, 9876);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%0C]\n", 9876);
		or = printf("ORIG>\t[%0C]\n", 9876);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%.10C]\n", 9876);
		or = printf("ORIG>\t[%.10C]\n", 9876);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%.*C]\n", 5, 9876);
		or = printf("ORIG>\t[%.*C]\n", 5, 9876);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%10.5C]\n", 9876);
		or = printf("ORIG>\t[%10.5C]\n", 9876);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%*.*C]\n", 5, 10, 9876);
		or = printf("ORIG>\t[%*.*C]\n", 5, 10, 9876);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%#C]\n", 9876);
		or = printf("ORIG>\t[%#C]\n", 9876);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[% C]\n", 9876);
		or = printf("ORIG>\t[% C]\n", 9876);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%    C]\n", 9876);
		or = printf("ORIG>\t[%    C]\n", 9876);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[% -10C]\n", 9876);
		or = printf("ORIG>\t[% -10C]\n", 9876);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%#20-0.5+10C]\n", 9876);
		or = printf("ORIG>\t[%#20-0.5+10C]\n", 9876);
		ft_print_result(mr, or, __LINE__);

		printf("\e[38;5;6m\t\t======== end %%C =====\033[0m\n\n");
	}
	if (TEST_LS)
	{
		printf("\e[38;5;6m\t\t======== %%S ========\033[0m\n");

		mr = ft_printf("MINE>\t[%S]\n", L"我是一只猫。");
		or = printf("ORIG>\t[%S]\n", L"我是一只猫。");
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%S]\n", L"");
		or = printf("ORIG>\t[%S]\n", L"");
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%S]\n", NULL);
		or = printf("ORIG>\t[%S]\n", NULL);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%30S]\n", L"我是一只猫。");
		or = printf("ORIG>\t[%30S]\n", L"我是一只猫。");
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%*S]\n", 30, L"我是一只猫。");
		or = printf("ORIG>\t[%*S]\n", 30, L"我是一只猫。");
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%0S]\n", L"我是一只猫。");
		or = printf("ORIG>\t[%0S]\n", L"我是一只猫。");
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%.10S]\n", L"我是一只猫。");
		or = printf("ORIG>\t[%.10S]\n", L"我是一只猫。");
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%.0S]\n", L"我是一只猫。");
		or = printf("ORIG>\t[%.0S]\n", L"我是一只猫。");
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%.*S]\n", 10, L"我是一只猫。");
		or = printf("ORIG>\t[%.*S]\n", 10, L"我是一只猫。");
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[% S]\n", L"我是一只猫。");
		or = printf("ORIG>\t[% S]\n", L"我是一只猫。");
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%+S]\n", L"我是一只猫。");
		or = printf("ORIG>\t[%+S]\n", L"我是一只猫。");
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%-S]\n", L"我是一只猫。");
		or = printf("ORIG>\t[%-S]\n", L"我是一只猫。");
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%0S]\n", L"我是一只猫。");
		or = printf("ORIG>\t[%0S]\n", L"我是一只猫。");
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%#S]\n", L"我是一只猫。");
		or = printf("ORIG>\t[%#S]\n", L"我是一只猫。");
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[% 10S]\n", L"我是一只猫。");
		or = printf("ORIG>\t[% 10S]\n", L"我是一只猫。");
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[% .2S]\n", L"我是一只猫。");
		or = printf("ORIG>\t[% .2S]\n", L"我是一只猫。");
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%+15S]\n", L"我是一只猫。");
		or = printf("ORIG>\t[%+15S]\n", L"我是一只猫。");
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%-15S]\n", L"我是一只猫。");
		or = printf("ORIG>\t[%-15S]\n", L"我是一只猫。");
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%-9.3S]\n", L"我是一只猫。");
		or = printf("ORIG>\t[%-9.3S]\n", L"我是一只猫。");
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%+-0S]\n", L"我是一只猫。");
		or = printf("ORIG>\t[%+-0S]\n", L"我是一只猫。");
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%#+-010.5S]\n", L"我是一只猫。");
		or = printf("ORIG>\t[%#+-010.5S]\n", L"我是一只猫。");
		ft_print_result(mr, or, __LINE__);

		printf("\e[38;5;6m\t\t======== end %%S =====\033[0m\n\n");
	}
	if (TEST_P)
	{
		printf("\e[38;5;6m\t\t======== %%p ========\033[0m\n");

		mr = ft_printf("MINE>\t[%p]\n", &mr);
		or = printf(   "ORIG>\t[%p]\n", &mr);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%p]\n", 0);
		or = printf(   "ORIG>\t[%p]\n", 0);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%20p]\n", &mr);
		or = printf(   "ORIG>\t[%20p]\n", &mr);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%0p]\n", &mr);
		or = printf(   "ORIG>\t[%0p]\n", &mr);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%.0p]\n", &mr);
		or = printf(   "ORIG>\t[%.0p]\n", &mr);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%10.0p]\n", 0);
		or = printf(   "ORIG>\t[%10.0p]\n", 0);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%.5p]\n", &mr);
		or = printf(   "ORIG>\t[%.5p]\n", &mr);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%.p]\n", &mr);
		or = printf(   "ORIG>\t[%.p]\n", &mr);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%.30p]\n", &mr);
		or = printf(   "ORIG>\t[%.30p]\n", &mr);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%20.5p]\n", &mr);
		or = printf(   "ORIG>\t[%20.5p]\n", &mr);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%40.20p]\n", &mr);
		or = printf(   "ORIG>\t[%40.20p]\n", &mr);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%*.*p]\n", 25, 6, &mr);
		or = printf(   "ORIG>\t[%*.*p]\n", 25, 6, &mr);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%+20p]\n", &or);
		or = printf(   "ORIG>\t[%+20p]\n", &or);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%-20p]\n", &mr);
		or = printf(   "ORIG>\t[%-20p]\n", &mr);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[% 20p]\n", &or);
		or = printf(   "ORIG>\t[% 20p]\n", &or);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%020p]\n", &or);
		or = printf(   "ORIG>\t[%020p]\n", &or);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%#20p]\n", &or);
		or = printf(   "ORIG>\t[%#20p]\n", &or);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%+-017p]\n", &or);
		or = printf(   "ORIG>\t[%+-017p]\n", &or);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%+#-017p]\n", &or);
		or = printf(   "ORIG>\t[%+#-017p]\n", &or);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%+-20p]\n", &or);
		or = printf(   "ORIG>\t[%+-20p]\n", &or);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%#+-020p]\n", &or);
		or = printf(   "ORIG>\t[%#+-020p]\n", &or);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[% #-0+20.15p]\n", &or);
		or = printf(   "ORIG>\t[% #+-020.15p]\n", &or);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[% #+-020p]\n", &or);
		or = printf(   "ORIG>\t[% #+-020p]\n", &or);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%#+020.15p]\n", &or);
		or = printf(   "ORIG>\t[%#+020.15p]\n", &or);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%#+-020.5p]\n", &or);
		or = printf(   "ORIG>\t[%#+-020.5p]\n", &or);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%#+020.5p]\n", &or);
		or = printf(   "ORIG>\t[%#+020.5p]\n", &or);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%hhp]\n", (void *)ft_printf, NULL);
		or = printf(   "ORIG>\t[%hhp]\n", (void *)ft_printf, NULL);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%hp]\n", (void *)ft_printf, NULL);
		or = printf(   "ORIG>\t[%hp]\n", (void *)ft_printf, NULL);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%lp]\n", (void *)ft_printf, NULL);
		or = printf(   "ORIG>\t[%lp]\n", (void *)ft_printf, NULL);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%llp]\n", (void *)ft_printf, NULL);
		or = printf(   "ORIG>\t[%llp]\n", (void *)ft_printf, NULL);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%jp]\n", (void *)ft_printf, NULL);
		or = printf(   "ORIG>\t[%jp]\n", (void *)ft_printf, NULL);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%zp]\n", (void *)ft_printf, NULL);
		or = printf(   "ORIG>\t[%zp]\n", (void *)ft_printf, NULL);
		ft_print_result(mr, or, __LINE__);

		printf("\e[38;5;6m\t\t==== end %%p ===\033[0m\n");
	}
	if (TEST_D)
	{
		printf("\e[38;5;6m\t\t======== %%d ========\033[0m\n");

		mr = ft_printf("MINE>\t[%d][%d]\n", dec, -dec);
		or = printf(   "ORIG>\t[%d][%d]\n", dec, -dec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%d]\n", 0);
		or = printf(   "ORIG>\t[%d]\n", 0);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%20d][%20d]\n", dec, -dec);
		or = printf(   "ORIG>\t[%20d][%20d]\n", dec, -dec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%0d][%0d]\n", dec, -dec);
		or = printf(   "ORIG>\t[%0d][%0d]\n", dec, -dec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%.0d][%.0d]\n", dec, -dec);
		or = printf(   "ORIG>\t[%.0d][%.0d]\n", dec, -dec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%.5d][%.5d]\n", dec, -dec);
		or = printf(   "ORIG>\t[%.5d][%.5d]\n", dec, -dec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%.d][%.d]\n", dec, -dec);
		or = printf(   "ORIG>\t[%.d][%.d]\n", dec, -dec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%.30d][%.30d]\n", dec, -dec);
		or = printf(   "ORIG>\t[%.30d][%.30d]\n", dec, -dec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%20.5d][%20.5d]\n", dec, -dec);
		or = printf(   "ORIG>\t[%20.5d][%20.5d]\n", dec, -dec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%40.20d][%40.20d]\n", dec, -dec);
		or = printf(   "ORIG>\t[%40.20d][%40.20d]\n", dec, -dec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%*.*d][%*.*d]\n", 25, 6, dec, 25, 6, -dec);
		or = printf(   "ORIG>\t[%*.*d][%*.*d]\n", 25, 6, dec, 25, 6, -dec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%+20d][%+20d]\n", dec, -dec);
		or = printf(   "ORIG>\t[%+20d][%+20d]\n", dec, -dec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%-20d][%-20d]\n", dec, -dec);
		or = printf(   "ORIG>\t[%-20d][%-20d]\n", dec, -dec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[% 20d][% 20d]\n", dec, -dec);
		or = printf(   "ORIG>\t[% 20d][% 20d]\n", dec, -dec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%020d][%020d]\n", dec, -dec);
		or = printf(   "ORIG>\t[%020d][%020d]\n", dec, -dec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%#20d][%#20d]\n", dec, -dec);
		or = printf(   "ORIG>\t[%#20d][%#20d]\n", dec, -dec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%+-017d][%+-017d]\n", dec, -dec);
		or = printf(   "ORIG>\t[%+-017d][%+-017d]\n", dec, -dec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%+#-017d][%+#-017d]\n", dec, -dec);
		or = printf(   "ORIG>\t[%+#-017d][%+#-017d]\n", dec, -dec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%+-20d][%+-20d]\n", dec, -dec);
		or = printf(   "ORIG>\t[%+-20d][%+-20d]\n", dec, -dec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%#+-020d][%#+-020d]\n", dec, -dec);
		or = printf(   "ORIG>\t[%#+-020d][%#+-020d]\n", dec, -dec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[% #+-020.15d][% #+-020.15d]\n", dec, -dec);
		or = printf(   "ORIG>\t[% #+-020.15d][% #+-020.15d]\n", dec, -dec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[% #+-020d][% #+-020d]\n", dec, -dec);
		or = printf(   "ORIG>\t[% #+-020d][% #+-020d]\n", dec, -dec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%#+020.15d][%#+020.15d]\n", dec, -dec);
		or = printf(   "ORIG>\t[%#+020.15d][%#+020.15d]\n", dec, -dec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%#+-020.5d][%#+-020.5d]\n", dec, -dec);
		or = printf(   "ORIG>\t[%#+-020.5d][%#+-020.5d]\n", dec, -dec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%#+020.5d][%#+020.5d]\n", 10, dec, 10, -dec);
		or = printf(   "ORIG>\t[%#+020.5d][%#+020.5d]\n", 10, dec, 10, -dec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%#20-.*+0 d][%#20-.*+0 d]\n", 10, dec, 10, -dec);
		or = printf(   "ORIG>\t[%#20-.*+0 d][%#20-.*+0 d]\n", 10, dec, 10, -dec);
		ft_print_result(mr, or, __LINE__);

		printf("\e[38;5;6m\t\t==== end %%d ===\033[0m\n");
	}
	if (TEST_LD)
	{
		printf("\e[38;5;6m\t\t======== %%D ========\033[0m\n");

		mr = ft_printf("MINE>\t[%D][%D]\n", ldec, -ldec);
		or = printf(   "ORIG>\t[%D][%D]\n", ldec, -ldec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%D]\n", 0);
		or = printf(   "ORIG>\t[%D]\n", 0);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%20D][%20D]\n", ldec, -ldec);
		or = printf(   "ORIG>\t[%20D][%20D]\n", ldec, -ldec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%0D][%0D]\n", ldec, -ldec);
		or = printf(   "ORIG>\t[%0D][%0D]\n", ldec, -ldec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%.0D][%.0D]\n", ldec, -ldec);
		or = printf(   "ORIG>\t[%.0D][%.0D]\n", ldec, -ldec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%.5D][%.5D]\n", ldec, -ldec);
		or = printf(   "ORIG>\t[%.5D][%.5D]\n", ldec, -ldec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%.D][%.D]\n", ldec, -ldec);
		or = printf(   "ORIG>\t[%.D][%.D]\n", ldec, -ldec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%.30D][%.30D]\n", ldec, -ldec);
		or = printf(   "ORIG>\t[%.30D][%.30D]\n", ldec, -ldec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%20.5D][%20.5D]\n", ldec, -ldec);
		or = printf(   "ORIG>\t[%20.5D][%20.5D]\n", ldec, -ldec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%40.20D][%40.20D]\n", ldec, -ldec);
		or = printf(   "ORIG>\t[%40.20D][%40.20D]\n", ldec, -ldec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%*.*D][%*.*D]\n", 25, 6, ldec, 25, 6, -ldec);
		or = printf(   "ORIG>\t[%*.*D][%*.*D]\n", 25, 6, ldec, 25, 6, -ldec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%+20D][%+20D]\n", ldec, -ldec);
		or = printf(   "ORIG>\t[%+20D][%+20D]\n", ldec, -ldec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%-20D][%-20D]\n", ldec, -ldec);
		or = printf(   "ORIG>\t[%-20D][%-20D]\n", ldec, -ldec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[% 20D][% 20D]\n", ldec, -ldec);
		or = printf(   "ORIG>\t[% 20D][% 20D]\n", ldec, -ldec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%020D][%020D]\n", ldec, -ldec);
		or = printf(   "ORIG>\t[%020D][%020D]\n", ldec, -ldec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%#20D][%#20D]\n", ldec, -ldec);
		or = printf(   "ORIG>\t[%#20D][%#20D]\n", ldec, -ldec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%+-017D][%+-017D]\n", ldec, -ldec);
		or = printf(   "ORIG>\t[%+-017D][%+-017D]\n", ldec, -ldec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%+#-017D][%+#-017D]\n", ldec, -ldec);
		or = printf(   "ORIG>\t[%+#-017D][%+#-017D]\n", ldec, -ldec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%+-20D][%+-20D]\n", ldec, -ldec);
		or = printf(   "ORIG>\t[%+-20D][%+-20D]\n", ldec, -ldec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%#+-020D][%#+-020D]\n", ldec, -ldec);
		or = printf(   "ORIG>\t[%#+-020D][%#+-020D]\n", ldec, -ldec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[% #+-020.15D][% #+-020.15D]\n", ldec, -ldec);
		or = printf(   "ORIG>\t[% #+-020.15D][% #+-020.15D]\n", ldec, -ldec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[% #+-020D][% #+-020D]\n", ldec, -ldec);
		or = printf(   "ORIG>\t[% #+-020D][% #+-020D]\n", ldec, -ldec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%#+020.15D][%#+020.15D]\n", ldec, -ldec);
		or = printf(   "ORIG>\t[%#+020.15D][%#+020.15D]\n", ldec, -ldec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%#+-020.5D][%#+-020.5D]\n", ldec, -ldec);
		or = printf(   "ORIG>\t[%#+-020.5D][%#+-020.5D]\n", ldec, -ldec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%#+020.5D][%#+020.5D]\n", 10, ldec, 10, -ldec);
		or = printf(   "ORIG>\t[%#+020.5D][%#+020.5D]\n", 10, ldec, 10, -ldec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%#20-.*+0 D][%#20-.*+0 D]\n", 10, ldec, 10, -ldec);
		or = printf(   "ORIG>\t[%#20-.*+0 D][%#20-.*+0 D]\n", 10, ldec, 10, -ldec);
		ft_print_result(mr, or, __LINE__);

		printf("\e[38;5;6m\t\t==== end %%D ===\033[0m\n");
	}
	if (TEST_O)
	{
		printf("\e[38;5;6m\t\t======== %%o ========\033[0m\n");

		mr = ft_printf("MINE>\t[%o][%o]\n", dec, -dec);
		or = printf(   "ORIG>\t[%o][%o]\n", dec, -dec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%o]\n", 0);
		or = printf(   "ORIG>\t[%o]\n", 0);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%20o][%20o]\n", dec, -dec);
		or = printf(   "ORIG>\t[%20o][%20o]\n", dec, -dec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%0o][%0o]\n", dec, -dec);
		or = printf(   "ORIG>\t[%0o][%0o]\n", dec, -dec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%.0o][%.0o]\n", dec, -dec);
		or = printf(   "ORIG>\t[%.0o][%.0o]\n", dec, -dec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%.5o][%.5o]\n", dec, -dec);
		or = printf(   "ORIG>\t[%.5o][%.5o]\n", dec, -dec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%.o][%.o]\n", dec, -dec);
		or = printf(   "ORIG>\t[%.o][%.o]\n", dec, -dec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%.30o][%.30o]\n", dec, -dec);
		or = printf(   "ORIG>\t[%.30o][%.30o]\n", dec, -dec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%20.5o][%20.5o]\n", dec, -dec);
		or = printf(   "ORIG>\t[%20.5o][%20.5o]\n", dec, -dec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%40.20o][%40.20o]\n", dec, -dec);
		or = printf(   "ORIG>\t[%40.20o][%40.20o]\n", dec, -dec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%*.*o][%*.*o]\n", 25, 6, dec, 25, 6, -dec);
		or = printf(   "ORIG>\t[%*.*o][%*.*o]\n", 25, 6, dec, 25, 6, -dec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%+20o][%+20o]\n", dec, -dec);
		or = printf(   "ORIG>\t[%+20o][%+20o]\n", dec, -dec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%-20o][%-20o]\n", dec, -dec);
		or = printf(   "ORIG>\t[%-20o][%-20o]\n", dec, -dec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[% 20o][% 20o]\n", dec, -dec);
		or = printf(   "ORIG>\t[% 20o][% 20o]\n", dec, -dec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%020o][%020o]\n", dec, -dec);
		or = printf(   "ORIG>\t[%020o][%020o]\n", dec, -dec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%#20o][%#20o]\n", dec, -dec);
		or = printf(   "ORIG>\t[%#20o][%#20o]\n", dec, -dec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%+-017o][%+-017o]\n", dec, -dec);
		or = printf(   "ORIG>\t[%+-017o][%+-017o]\n", dec, -dec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%+#-017o][%+#-017o]\n", dec, -dec);
		or = printf(   "ORIG>\t[%+#-017o][%+#-017o]\n", dec, -dec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%+-20o][%+-20o]\n", dec, -dec);
		or = printf(   "ORIG>\t[%+-20o][%+-20o]\n", dec, -dec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%#+-020o][%#+-020o]\n", dec, -dec);
		or = printf(   "ORIG>\t[%#+-020o][%#+-020o]\n", dec, -dec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[% #+-020.15o][% #+-020.15o]\n", dec, -dec);
		or = printf(   "ORIG>\t[% #+-020.15o][% #+-020.15o]\n", dec, -dec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[% #+-020o][% #+-020o]\n", dec, -dec);
		or = printf(   "ORIG>\t[% #+-020o][% #+-020o]\n", dec, -dec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%#+020.15o][%#+020.15o]\n", dec, -dec);
		or = printf(   "ORIG>\t[%#+020.15o][%#+020.15o]\n", dec, -dec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%#+-020.5o][%#+-020.5o]\n", dec, -dec);
		or = printf(   "ORIG>\t[%#+-020.5o][%#+-020.5o]\n", dec, -dec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%#+020.5o][%#+020.5o]\n", 10, dec, 10, -dec);
		or = printf(   "ORIG>\t[%#+020.5o][%#+020.5o]\n", 10, dec, 10, -dec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%#20-.*+0 o][%#20-.*+0 o]\n", 10, dec, 10, -dec);
		or = printf(   "ORIG>\t[%#20-.*+0 o][%#20-.*+0 o]\n", 10, dec, 10, -dec);
		ft_print_result(mr, or, __LINE__);

		printf("\e[38;5;6m\t\t==== end %%o ===\033[0m\n");
	}
	if (TEST_LO)
	{
		printf("\e[38;5;6m\t\t======== %%O ========\033[0m\n");

		mr = ft_printf("MINE>\t[%O][%O]\n", ldec, -ldec);
		or = printf(   "ORIG>\t[%O][%O]\n", ldec, -ldec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%O]\n", 0);
		or = printf(   "ORIG>\t[%O]\n", 0);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%30O][%30O]\n", ldec, -ldec);
		or = printf(   "ORIG>\t[%30O][%30O]\n", ldec, -ldec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%0O][%0O]\n", ldec, -ldec);
		or = printf(   "ORIG>\t[%0O][%0O]\n", ldec, -ldec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%2O][%2O]\n", ldec, -ldec);
		or = printf(   "ORIG>\t[%2O][%2O]\n", ldec, -ldec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%.0O][%.0O]\n", ldec, -ldec);
		or = printf(   "ORIG>\t[%.0O][%.0O]\n", ldec, -ldec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%.5O][%.5O]\n", ldec, -ldec);
		or = printf(   "ORIG>\t[%.5O][%.5O]\n", ldec, -ldec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%.O][%.O]\n", ldec, -ldec);
		or = printf(   "ORIG>\t[%.O][%.O]\n", ldec, -ldec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%.40O][%.40O]\n", ldec, -ldec);
		or = printf(   "ORIG>\t[%.40O][%.40O]\n", ldec, -ldec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%30.10O][%30.10O]\n", ldec, -ldec);
		or = printf(   "ORIG>\t[%30.10O][%30.10O]\n", ldec, -ldec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%40.30O][%40.30O]\n", ldec, -ldec);
		or = printf(   "ORIG>\t[%40.30O][%40.30O]\n", ldec, -ldec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%*.*O][%*.*O]\n", 40, 25, ldec, 40, 25, -ldec);
		or = printf(   "ORIG>\t[%*.*O][%*.*O]\n", 40, 25, ldec, 40, 25, -ldec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%+30O][%+30O]\n", ldec, -ldec);
		or = printf(   "ORIG>\t[%+30O][%+30O]\n", ldec, -ldec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%-30O][%-30O]\n", ldec, -ldec);
		or = printf(   "ORIG>\t[%-30O][%-30O]\n", ldec, -ldec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[% 30O][% 30O]\n", ldec, -ldec);
		or = printf(   "ORIG>\t[% 30O][% 30O]\n", ldec, -ldec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%030O][%030O]\n", ldec, -ldec);
		or = printf(   "ORIG>\t[%030O][%030O]\n", ldec, -ldec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%#30O][%#30O]\n", ldec, -ldec);
		or = printf(   "ORIG>\t[%#30O][%#30O]\n", ldec, -ldec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%+-028O][%+-028O]\n", ldec, -ldec);
		or = printf(   "ORIG>\t[%+-028O][%+-028O]\n", ldec, -ldec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%+#-028O][%+#-028O]\n", ldec, -ldec);
		or = printf(   "ORIG>\t[%+#-028O][%+#-028O]\n", ldec, -ldec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%+-30O][%+-30O]\n", ldec, -ldec);
		or = printf(   "ORIG>\t[%+-30O][%+-30O]\n", ldec, -ldec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%#+-030O][%#+-030O]\n", ldec, -ldec);
		or = printf(   "ORIG>\t[%#+-030O][%#+-030O]\n", ldec, -ldec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[% #+-030.25O][% #+-030.25O]\n", ldec, -ldec);
		or = printf(   "ORIG>\t[% #+-030.25O][% #+-030.25O]\n", ldec, -ldec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[% #+-030O][% #+-030O]\n", ldec, -ldec);
		or = printf(   "ORIG>\t[% #+-030O][% #+-030O]\n", ldec, -ldec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%#+030.27O][%#+030.27O]\n", ldec, -ldec);
		or = printf(   "ORIG>\t[%#+030.27O][%#+030.27O]\n", ldec, -ldec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%#+-030.25O][%#+-030.25O]\n", ldec, -ldec);
		or = printf(   "ORIG>\t[%#+-030.25O][%#+-030.25O]\n", ldec, -ldec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%#+030.25O][%#+030.25O]\n", ldec, -ldec);
		or = printf(   "ORIG>\t[%#+030.25O][%#+030.25O]\n", ldec, -ldec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%#30-.*+0 O][%#30-.*+0 O]\n", 26, ldec, 26, -ldec);
		or = printf(   "ORIG>\t[%#30-.*+0 O][%#30-.*+0 O]\n", 26, ldec, 26, -ldec);
		ft_print_result(mr, or, __LINE__);

		printf("\e[38;5;6m\t\t==== end %%O ===\033[0m\n");
	}
	if (TEST_U)
	{
		printf("\e[38;5;6m\t\t======== %%u ========\033[0m\n");

		mr = ft_printf("MINE>\t[%u][%u]\n", dec, -dec);
		or = printf(   "ORIG>\t[%u][%u]\n", dec, -dec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%u]\n", 0);
		or = printf(   "ORIG>\t[%u]\n", 0);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%30u][%30u]\n", dec, -dec);
		or = printf(   "ORIG>\t[%30u][%30u]\n", dec, -dec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%0u][%0u]\n", dec, -dec);
		or = printf(   "ORIG>\t[%0u][%0u]\n", dec, -dec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%2u][%2u]\n", dec, -dec);
		or = printf(   "ORIG>\t[%2u][%2u]\n", dec, -dec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%.0u][%.0u]\n", dec, -dec);
		or = printf(   "ORIG>\t[%.0u][%.0u]\n", dec, -dec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%.5u][%.5u]\n", dec, -dec);
		or = printf(   "ORIG>\t[%.5u][%.5u]\n", dec, -dec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%.u][%.u]\n", dec, -dec);
		or = printf(   "ORIG>\t[%.u][%.u]\n", dec, -dec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%.40u][%.40u]\n", dec, -dec);
		or = printf(   "ORIG>\t[%.40u][%.40u]\n", dec, -dec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%30.10u][%30.10u]\n", dec, -dec);
		or = printf(   "ORIG>\t[%30.10u][%30.10u]\n", dec, -dec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%40.30u][%40.30u]\n", dec, -dec);
		or = printf(   "ORIG>\t[%40.30u][%40.30u]\n", dec, -dec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%*.*u][%*.*u]\n", 40, 25, dec, 40, 25, -dec);
		or = printf(   "ORIG>\t[%*.*u][%*.*u]\n", 40, 25, dec, 40, 25, -dec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%+30u][%+30u]\n", dec, -dec);
		or = printf(   "ORIG>\t[%+30u][%+30u]\n", dec, -dec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%-30u][%-30u]\n", dec, -dec);
		or = printf(   "ORIG>\t[%-30u][%-30u]\n", dec, -dec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[% 30u][% 30u]\n", dec, -dec);
		or = printf(   "ORIG>\t[% 30u][% 30u]\n", dec, -dec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%030u][%030u]\n", dec, -dec);
		or = printf(   "ORIG>\t[%030u][%030u]\n", dec, -dec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%#30u][%#30u]\n", dec, -dec);
		or = printf(   "ORIG>\t[%#30u][%#30u]\n", dec, -dec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%+-028u][%+-028u]\n", dec, -dec);
		or = printf(   "ORIG>\t[%+-028u][%+-028u]\n", dec, -dec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%+#-028u][%+#-028u]\n", dec, -dec);
		or = printf(   "ORIG>\t[%+#-028u][%+#-028u]\n", dec, -dec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%+-30u][%+-30u]\n", dec, -dec);
		or = printf(   "ORIG>\t[%+-30u][%+-30u]\n", dec, -dec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%#+-030u][%#+-030u]\n", dec, -dec);
		or = printf(   "ORIG>\t[%#+-030u][%#+-030u]\n", dec, -dec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[% #+-030.25u][% #+-030.25u]\n", dec, -dec);
		or = printf(   "ORIG>\t[% #+-030.25u][% #+-030.25u]\n", dec, -dec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[% #+-030u][% #+-030u]\n", dec, -dec);
		or = printf(   "ORIG>\t[% #+-030u][% #+-030u]\n", dec, -dec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%#+030.27u][%#+030.27u]\n", dec, -dec);
		or = printf(   "ORIG>\t[%#+030.27u][%#+030.27u]\n", dec, -dec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%#+-030.25u][%#+-030.25u]\n", dec, -dec);
		or = printf(   "ORIG>\t[%#+-030.25u][%#+-030.25u]\n", dec, -dec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%#+030.25u][%#+030.25u]\n", dec, -dec);
		or = printf(   "ORIG>\t[%#+030.25u][%#+030.25u]\n", dec, -dec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%#30-.*+0 u][%#30-.*+0 u]\n", 26, dec, 26, -dec);
		or = printf(   "ORIG>\t[%#30-.*+0 u][%#30-.*+0 u]\n", 26, dec, 26, -dec);
		ft_print_result(mr, or, __LINE__);

		printf("\e[38;5;6m\t\t==== end %%u ===\033[0m\n");
	}
	if (TEST_LU)
	{
		printf("\e[38;5;6m\t\t======== %%U ========\033[0m\n");

		mr = ft_printf("MINE>\t[%U][%U]\n", ldec, -ldec);
		or = printf(   "ORIG>\t[%U][%U]\n", ldec, -ldec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%U]\n", 0);
		or = printf(   "ORIG>\t[%U]\n", 0);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%30U][%30U]\n", ldec, -ldec);
		or = printf(   "ORIG>\t[%30U][%30U]\n", ldec, -ldec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%0U][%0U]\n", ldec, -ldec);
		or = printf(   "ORIG>\t[%0U][%0U]\n", ldec, -ldec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%2U][%2U]\n", ldec, -ldec);
		or = printf(   "ORIG>\t[%2U][%2U]\n", ldec, -ldec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%.0U][%.0U]\n", ldec, -ldec);
		or = printf(   "ORIG>\t[%.0U][%.0U]\n", ldec, -ldec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%.5U][%.5U]\n", ldec, -ldec);
		or = printf(   "ORIG>\t[%.5U][%.5U]\n", ldec, -ldec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%.U][%.U]\n", ldec, -ldec);
		or = printf(   "ORIG>\t[%.U][%.U]\n", ldec, -ldec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%.40U][%.40U]\n", ldec, -ldec);
		or = printf(   "ORIG>\t[%.40U][%.40U]\n", ldec, -ldec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%30.10U][%30.10U]\n", ldec, -ldec);
		or = printf(   "ORIG>\t[%30.10U][%30.10U]\n", ldec, -ldec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%40.30U][%40.30U]\n", ldec, -ldec);
		or = printf(   "ORIG>\t[%40.30U][%40.30U]\n", ldec, -ldec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%*.*U][%*.*U]\n", 40, 25, ldec, 40, 25, -ldec);
		or = printf(   "ORIG>\t[%*.*U][%*.*U]\n", 40, 25, ldec, 40, 25, -ldec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%+30U][%+30U]\n", ldec, -ldec);
		or = printf(   "ORIG>\t[%+30U][%+30U]\n", ldec, -ldec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%-30U][%-30U]\n", ldec, -ldec);
		or = printf(   "ORIG>\t[%-30U][%-30U]\n", ldec, -ldec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[% 30U][% 30U]\n", ldec, -ldec);
		or = printf(   "ORIG>\t[% 30U][% 30U]\n", ldec, -ldec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%030U][%030U]\n", ldec, -ldec);
		or = printf(   "ORIG>\t[%030U][%030U]\n", ldec, -ldec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%#30U][%#30U]\n", ldec, -ldec);
		or = printf(   "ORIG>\t[%#30U][%#30U]\n", ldec, -ldec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%+-028U][%+-028U]\n", ldec, -ldec);
		or = printf(   "ORIG>\t[%+-028U][%+-028U]\n", ldec, -ldec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%+#-028U][%+#-028U]\n", ldec, -ldec);
		or = printf(   "ORIG>\t[%+#-028U][%+#-028U]\n", ldec, -ldec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%+-30U][%+-30U]\n", ldec, -ldec);
		or = printf(   "ORIG>\t[%+-30U][%+-30U]\n", ldec, -ldec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%#+-030U][%#+-030U]\n", ldec, -ldec);
		or = printf(   "ORIG>\t[%#+-030U][%#+-030U]\n", ldec, -ldec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[% #+-030.25U][% #+-030.25U]\n", ldec, -ldec);
		or = printf(   "ORIG>\t[% #+-030.25U][% #+-030.25U]\n", ldec, -ldec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[% #+-030U][% #+-030U]\n", ldec, -ldec);
		or = printf(   "ORIG>\t[% #+-030U][% #+-030U]\n", ldec, -ldec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%#+030.27U][%#+030.27U]\n", ldec, -ldec);
		or = printf(   "ORIG>\t[%#+030.27U][%#+030.27U]\n", ldec, -ldec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%#+-030.25U][%#+-030.25U]\n", ldec, -ldec);
		or = printf(   "ORIG>\t[%#+-030.25U][%#+-030.25U]\n", ldec, -ldec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%#+030.25U][%#+030.25U]\n", ldec, -ldec);
		or = printf(   "ORIG>\t[%#+030.25U][%#+030.25U]\n", ldec, -ldec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%#30-.*+0 U][%#30-.*+0 U]\n", 26, ldec, 26, -ldec);
		or = printf(   "ORIG>\t[%#30-.*+0 U][%#30-.*+0 U]\n", 26, ldec, 26, -ldec);
		ft_print_result(mr, or, __LINE__);

		printf("\e[38;5;6m\t\t==== end %%U ===\033[0m\n");
	}
	if (TEST_X)
	{
		printf("\e[38;5;6m\t\t======== %%x and %%X ========\033[0m\n");

		mr = ft_printf("MINE>\t[%x][%x]\n", dec, -dec);
		or = printf(   "ORIG>\t[%x][%x]\n", dec, -dec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%x]\n", 0);
		or = printf(   "ORIG>\t[%x]\n", 0);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%30X][%30X]\n", dec, -dec);
		or = printf(   "ORIG>\t[%30X][%30X]\n", dec, -dec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%0X][%0X]\n", dec, -dec);
		or = printf(   "ORIG>\t[%0X][%0X]\n", dec, -dec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%2x][%2x]\n", dec, -dec);
		or = printf(   "ORIG>\t[%2x][%2x]\n", dec, -dec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%.0x][%.0x]\n", dec, -dec);
		or = printf(   "ORIG>\t[%.0x][%.0x]\n", dec, -dec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%.5X][%.5X]\n", dec, -dec);
		or = printf(   "ORIG>\t[%.5X][%.5X]\n", dec, -dec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%.X][%.X]\n", dec, -dec);
		or = printf(   "ORIG>\t[%.X][%.X]\n", dec, -dec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%.40x][%.40x]\n", dec, -dec);
		or = printf(   "ORIG>\t[%.40x][%.40x]\n", dec, -dec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%30.10x][%30.10x]\n", dec, -dec);
		or = printf(   "ORIG>\t[%30.10x][%30.10x]\n", dec, -dec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%40.30X][%40.30X]\n", dec, -dec);
		or = printf(   "ORIG>\t[%40.30X][%40.30X]\n", dec, -dec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%*.*X][%*.*X]\n", 40, 25, dec, 40, 25, -dec);
		or = printf(   "ORIG>\t[%*.*X][%*.*X]\n", 40, 25, dec, 40, 25, -dec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%+30x][%+30x]\n", dec, -dec);
		or = printf(   "ORIG>\t[%+30x][%+30x]\n", dec, -dec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%-30x][%-30x]\n", dec, -dec);
		or = printf(   "ORIG>\t[%-30x][%-30x]\n", dec, -dec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[% 30X][% 30X]\n", dec, -dec);
		or = printf(   "ORIG>\t[% 30X][% 30X]\n", dec, -dec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%030X][%030X]\n", dec, -dec);
		or = printf(   "ORIG>\t[%030X][%030X]\n", dec, -dec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%#30x][%#30x]\n", dec, -dec);
		or = printf(   "ORIG>\t[%#30x][%#30x]\n", dec, -dec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%+-028x][%+-028x]\n", dec, -dec);
		or = printf(   "ORIG>\t[%+-028x][%+-028x]\n", dec, -dec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%+#-028X][%+#-028X]\n", dec, -dec);
		or = printf(   "ORIG>\t[%+#-028X][%+#-028X]\n", dec, -dec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%+-30X][%+-30X]\n", dec, -dec);
		or = printf(   "ORIG>\t[%+-30X][%+-30X]\n", dec, -dec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%#+-030x][%#+-030x]\n", dec, -dec);
		or = printf(   "ORIG>\t[%#+-030x][%#+-030x]\n", dec, -dec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[% #+-030.25x][% #+-030.25x]\n", dec, -dec);
		or = printf(   "ORIG>\t[% #+-030.25x][% #+-030.25x]\n", dec, -dec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[% #+-030X][% #+-030X]\n", dec, -dec);
		or = printf(   "ORIG>\t[% #+-030X][% #+-030X]\n", dec, -dec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%#+030.27X][%#+030.27X]\n", dec, -dec);
		or = printf(   "ORIG>\t[%#+030.27X][%#+030.27X]\n", dec, -dec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%#+-030.25x][%#+-030.25x]\n", dec, -dec);
		or = printf(   "ORIG>\t[%#+-030.25x][%#+-030.25x]\n", dec, -dec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%#+030.25x][%#+030.25x]\n", dec, -dec);
		or = printf(   "ORIG>\t[%#+030.25x][%#+030.25x]\n", dec, -dec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%#30-.*+0 X][%#30-.*+0 X]\n", 26, dec, 26, -dec);
		or = printf(   "ORIG>\t[%#30-.*+0 X][%#30-.*+0 X]\n", 26, dec, 26, -dec);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%#30-.*+0 X]\n", 26, "test");
		or = printf(   "ORIG>\t[%#30-.*+0 X]\n", 26, "test");
		ft_print_result(mr, or, __LINE__);

		printf("\e[38;5;6m\t\t==== end %%x and %%X ===\033[0m\n");
	}
	if (TEST_BAZAR)
	{
		printf("\e[38;5;6m\t\t======== Wrong Flags Tests ========\033[0m\n");

		mr = ft_printf("MINE>\t[%]\n", 25, 16215);
		or = printf("ORIG>\t[%]\n", 25, 16215);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%%%]\n", 25, 16215);
		or = printf("ORIG>\t[%%%]\n", 25, 16215);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%%%%]\n", 25, 16215);
		or = printf("ORIG>\t[%%%%]\n", 25, 16215);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[30%%]\n", 25, 16215);
		or = printf("ORIG>\t[30%%]\n", 25, 16215);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[% ]\n", 25, 16215);
		or = printf("ORIG>\t[% ]\n", 25, 16215);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[% h]\n", 25, 16215);
		or = printf("ORIG>\t[% h]\n", 25, 16215);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%Z]\n", 25, 16215);
		or = printf("ORIG>\t[%Z]\n", 25, 16215);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[% Z]\n", 25, 16215);
		or = printf("ORIG>\t[% Z]\n", 25, 16215);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[% hZ]\n", 25, 16215);
		or = printf("ORIG>\t[% hZ]\n", 25, 16215);
		ft_print_result(mr, or, __LINE__);

		printf("\e[38;5;6m\t\t======== No Specifier Tests ========\033[0m\n");

		mr = ft_printf("MINE>\t[%%]\n");
		or = printf("ORIG>\t[%%]\n");
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%10%]\n");
		or = printf("ORIG>\t[%10%]\n");
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%-10%]\n");
		or = printf("ORIG>\t[%-10%]\n");
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%010%]\n");
		or = printf("ORIG>\t[%010%]\n");
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%-010%]\n");
		or = printf("ORIG>\t[%-010%]\n");
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%.0%]\n");
		or = printf("ORIG>\t[%.0%]\n");
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%     %]\n");
		or = printf("ORIG>\t[%     %]\n");
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%0000     %]\n");
		or = printf("ORIG>\t[%0000     %]\n");
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%%     %]\n");
		or = printf("ORIG>\t[%%     %]\n");
		ft_print_result(mr, or, __LINE__);

		printf("\e[38;5;6m\t\t======== Mistaken Tests ========\033[0m\n");

		mr = ft_printf("MINE>\t[%zhd]\n", 4294967296);
		or = printf("ORIG>\t[%zhd]\n", 4294967296);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%jhd]\n", 9223372036854775807);
		or = printf("ORIG>\t[%jhd]\n", 9223372036854775807);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%jzd]\n", 9223372036854775807);
		or = printf("ORIG>\t[%jzd]\n", 9223372036854775807);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%lhl]\n", 9223372036854775807);
		or = printf("ORIG>\t[%lhl]\n", 9223372036854775807);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%lhlz]\n", 9223372036854775807);
		or = printf("ORIG>\t[%lhlz]\n", 9223372036854775807);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%jz]\n", 9223372036854775807);
		or = printf("ORIG>\t[%jz]\n", 9223372036854775807);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%lhh]\n", 2147483647);
		or = printf("ORIG>\t[%lhh]\n", 2147483647);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%hhld]\n", 128);
		or = printf("ORIG>\t[%hhld]\n", 128);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%####0000 33..1..#00d]\n", 256);
		or = printf("ORIG>\t[%####0000 33..1..#00d]\n", 256);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%###-#0000 33...12..#0+0d]\n", 256);
		or = printf("ORIG>\t[%###-#0000 33...12..#0+0d]\n", 256);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%####0000 33..1u]\n", 256);
		or = printf("ORIG>\t[%####0000 33..1u]\n", 256);
		ft_print_result(mr, or, __LINE__);
	}
	if (TEST_CRASH)
	{
		printf("\e[38;5;6m\t\t==== Crashtest zone ===\033[0m\n");

		mr = ft_printf("MINE>\t[]\n", 25, 16215);
		or = printf("ORIG>\t[]\n", 25, 16215);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[-10+d s : {%+-10d} {%s}]\n", 12345, "argl");
		or = printf(   "ORIG>\t[-10+d s : {%+-10d} {%s}]\n", 12345, "argl");
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%{after]\n", 25, 16215);
		or = printf("ORIG>\t[%{after]\n", 25, 16215);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[%{%{%{%]\n", 25, 16215);
		or = printf("ORIG>\t[%{%{%{%]\n", 25, 16215);
		ft_print_result(mr, or, __LINE__);

		mr = ft_printf("MINE>\t[{%{%{%{]\n", 25, 16215);
		or = printf("ORIG>\t[{%{%{%{]\n", 25, 16215);
		ft_print_result(mr, or, __LINE__);
	}
}
