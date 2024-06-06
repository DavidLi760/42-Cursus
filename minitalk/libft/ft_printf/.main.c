/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davli <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 17:35:09 by davli             #+#    #+#             */
/*   Updated: 2024/05/25 17:38:07 by davli            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include <stdint.h>
#include "ft_printf.h"

int main(void)
{
    int len1, len2;

    // Test avec une chaîne simple
    len1 = printf("Hello, World!\n");
    len2 = ft_printf("Hello, World!\n");
    printf("printf returned: %d\n", len1);
    printf("ft_printf returned: %d\n", len2);

    // Test avec des entiers
    len1 = printf("Integer: %d\n", 42);
    len2 = ft_printf("Integer: %d\n", 42);
    printf("printf returned: %d\n", len1);
    printf("ft_printf returned: %d\n", len2);

    // Test avec des chaînes
    len1 = printf("String: %s\n", "Test");
    len2 = ft_printf("String: %s\n", "Test");
    printf("printf returned: %d\n", len1);
    printf("ft_printf returned: %d\n", len2);

    // Test avec des caractères
    len1 = printf("Character: %c\n", 'A');
    len2 = ft_printf("Character: %c\n", 'A');
    printf("printf returned: %d\n", len1);
    printf("ft_printf returned: %d\n", len2);

    // Test avec des hexadécimaux
    len1 = printf("Hexadecimal: %x\n", 255);
    len2 = ft_printf("Hexadecimal: %x\n", 255);
    printf("printf returned: %d\n", len1);
    printf("ft_printf returned: %d\n", len2);

    // Test avec des pointeurs
    int *ptr = &len1;
    len1 = printf("Pointer: %p\n", (void *)ptr);
    len2 = ft_printf("Pointer: %p\n", (void *)ptr);
    printf("printf returned: %d\n", len1);
    printf("ft_printf returned: %d\n", len2);
}
