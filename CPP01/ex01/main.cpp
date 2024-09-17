/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c is a Zombie Class.
It has a private name attribute.pp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomakinavaleria <lomakinavaleria@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 18:26:07 by lomakinaval       #+#    #+#             */
/*   Updated: 2024/08/13 21:11:47 by lomakinaval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{

    int N = 5;

    Zombie *horde = zombieHorde( N, "True Zombie");

    for (int i = 0; i < N; i++)
        horde[i].announce();
    delete[] horde;
}