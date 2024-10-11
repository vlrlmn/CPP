/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlomakin <vlomakin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 18:06:46 by lomakinaval       #+#    #+#             */
/*   Updated: 2024/10/09 15:32:44 by vlomakin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Point.hpp"
#include <cmath>

float calculateArea(const Point &a, const Point &b, const Point &c) 
{
  float area = a.getX() * (b.getY() - c.getY()) +
               b.getX() * (c.getY() - a.getY()) +
               c.getX() * (a.getY() - b.getY());
  if (area < 0)
    area *= -1;
	area *= 0.5;
	return (area);
}

bool bsp(Point const a, Point const b, Point const c, Point const point) 
{
  float areaABC = calculateArea(a, b, c);
  float areaPAB = calculateArea(point, a, b);
  float areaPBC = calculateArea(point, b, c);
  float areaPCA = calculateArea(point, c, a);

  if (areaPCA == 0 || areaPAB == 0 || areaPBC == 0)
    return (false);
	float	sum = areaPAB + areaPBC + areaPCA;
	if (sum == areaABC)
	  return (true);
	return (false);
}