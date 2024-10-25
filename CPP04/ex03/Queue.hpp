/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Queue.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomakinavaleria <lomakinavaleria@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:31:01 by lomakinaval       #+#    #+#             */
/*   Updated: 2024/10/25 13:22:32 by lomakinaval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#pragma once
#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <iostream>

class Node
{
public:
	void	*val;
	Node	*next;
	Node();
	Node(void *val);
	~Node();
};


class Queue
{
private:
	Node	*front;
	Node	*rear;
public:
	Queue();
	virtual ~Queue();
	void	enqueue(void *val);
	void	*dequeue(void);
	void	*queueFront();
	int		isEmpty();

};


#endif