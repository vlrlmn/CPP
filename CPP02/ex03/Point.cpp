/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomakinavaleria <lomakinavaleria@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 17:19:52 by lomakinaval       #+#    #+#             */
/*   Updated: 2024/09/27 18:36:16 by lomakinaval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : x(0), y(0) {}

Point::Point(const float xVal, const float yVal) : x(xVal), y(yVal) {}

Point::Point(const Point &other) : x(other.x), y(other.y) {}

Point::~Point() {}

Point &Point::operator=(const Point &other) 
{
    return *this;
}

float  Point::getX() const 
{
    return x.toFloat();
}

float Point::getY() const 
{
    return y.toFloat();
}

