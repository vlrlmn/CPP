/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomakinavaleria <lomakinavaleria@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 15:38:12 by lomakinaval       #+#    #+#             */
/*   Updated: 2024/08/15 15:58:23 by lomakinaval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>

bool fileIsOpened(std::string fileName)
{
    
}

int main(int argc,  char *argv[])
{
    if (argc != 4)
    {
        std::cout << "Incorrect anount of arguments!" << std::endl;
        return (1);
    }
    std::string fileName = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    if (!fileIsOpened(fileName))
    {
        std::cout << "Cannot open a file!" << std::endl;
        return (1);
    }
}