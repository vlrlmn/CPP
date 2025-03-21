/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlomakin <vlomakin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 15:51:20 by vlomakin          #+#    #+#             */
/*   Updated: 2025/03/21 16:00:12 by vlomakin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template <typename T>
T Max(const T& x, const T& y) {
    if (x > y) {
        return x;
    } else {
        return y;
    }
}

template <typename T>
T Min(const T& x, const T& y) {
    if (x < y) {
        return x;
    } else {
        return y;
    }
}

#endif