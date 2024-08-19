/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HarlFilter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomakinavaleria <lomakinavaleria@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 16:42:06 by lomakinaval       #+#    #+#             */
/*   Updated: 2024/08/19 18:39:01 by lomakinaval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARLFILTER_HPP
#define HARLFILTER_HPP

#include <string>
#include <iostream>


class Harl
{
    private:
            void debug( void );
            void info( void );
            void warning( void );
            void error( void );
    public:
            void    complain( std::string level );
            void filter(std::string level);
};

#endif