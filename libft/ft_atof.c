/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcosta-f <fcosta-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 15:55:02 by ncastell          #+#    #+#             */
/*   Updated: 2023/08/04 17:54:11 by fcosta-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <stdlib.h>
#include "libft.h"

#include <stdbool.h>

float ft_atof(const char *str)
{
    int i = 0;
    float num = 0.0;
    float fraction = 0.0;
    int neg = 1;

    while (str[i] >= '0' && str[i] <= '9')
    {
        num = num * 10 + (str[i] - '0');
        i++;
    }

    if (str[i] == '-')
        neg = -1;

    if (str[i] == '.' && str[i + 1] >= '0' && str[i + 1] <= '9')
    {
        i++;
        float divisor = 10.0;
        while (str[i] >= '0' && str[i] <= '9')
        {
            fraction += (str[i] - '0') / divisor;
            divisor *= 10;
            i++;
        }
    }

    return (num + fraction) * neg;
}

/*
int	main(){
	char num[10] = " -477";
	//char num1[10] = " 122";

	printf("La cadena \"%s\" = numero: %d\n", num, atoi(num));
	printf("La cadena \"%s\" = numero: %d\n", num, ft_atoi(num));
}*/
