/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlomakin <vlomakin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 15:38:12 by lomakinaval       #+#    #+#             */
/*   Updated: 2024/08/20 14:25:02 by vlomakin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>

void replaceAndWrite(std::ifstream& inFile, std::ofstream& outFile, const std::string s1, const std::string s2)
{
    std::string line;

    while(std::getline(inFile, line))
    {
        size_t pos = 0;
        size_t found;
        while((found = line.find(s1, pos)) != std::string::npos)
        {
            outFile << line.substr(pos, found - pos);
            outFile << s2;
            pos = found + s1.length();
        }
        outFile << line.substr(pos) << std::endl;
    }
}

bool openOutFile(std::string fileName, std::ofstream& outFile)
{
    outFile.open((fileName + ".replace").c_str());
    return (outFile.is_open());
}

bool fileIsOpened(std::string& fileName)
{
    std::ifstream file(fileName.c_str());
    return (file.is_open());
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

    if (s1.empty())
    {
        std::cout << "String s1 cannot be empty!" << std::endl;
        return (3);
    }
    if (!fileIsOpened(fileName))
    {
        std::cout << "Cannot open a file!" << std::endl;
        return (2);
    }

    std::ifstream inFile(fileName.c_str());
    std::ofstream outFile;

    if (!openOutFile(fileName, outFile))
    {
        std::cout << "Cannot open a file!" << std::endl;
        return (2);
    }
    replaceAndWrite(inFile, outFile, s1, s2);
    inFile.close();
    outFile.close();
}