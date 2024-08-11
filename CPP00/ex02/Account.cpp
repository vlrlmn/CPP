/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomakinavaleria <lomakinavaleria@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 21:36:45 by lomakinaval       #+#    #+#             */
/*   Updated: 2024/08/11 20:54:08 by lomakinaval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Account.hpp"

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account()
{
	_accountIndex = _nbAccounts;
	_nbAccounts++;
	_amount = 0;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
}
void	Account::_displayTimestamp( void )
{
   std::time_t now = std::time(nullptr);

   std::tm* local_time = std::localtime(&now);

   std::cout << '['
             << (local_time->tm_year + 1900)
             << std::setw(2) << std::setfill('0') << (local_time->tm_mon + 1)
             << std::setw(2) << std::setfill('0') << local_time->tm_mday
             << '_'
             << std::setw(2) << std::setfill('0') << local_time->tm_hour
             << std::setw(2) << std::setfill('0') << local_time->tm_min
             << std::setw(2) << std::setfill('0') << local_time->tm_sec
             << ']';
}

Account::Account( int initial_deposit )
{
	_displayTimestamp();
	_accountIndex  = _nbAccounts;
	_nbAccounts++;
	_amount = initial_deposit;
	_totalAmount += _amount;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
    std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}

int	Account::getNbAccounts( void )
{
    return (_nbAccounts);
}

int	Account::getTotalAmount( void )
{
    return (_totalAmount);
}

int	Account::getNbDeposits( void )
{
    return (_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
    return (_totalNbWithdrawals);
}
void	Account::makeDeposit( int deposit )
{
    _displayTimestamp();
	std::cout << " index:" << _accountIndex << ";p_amount:" << checkAmount() << ";deposit:" << deposit;
    _nbDeposits++;
    _amount += deposit;
    _totalNbDeposits++;
    _totalAmount += deposit;
    std::cout << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
    _displayTimestamp();
    std::cout << " index:" << _accountIndex << ";p_amount:" << checkAmount() << ";withdrawal:";
    if (withdrawal > _amount)
    {
        std::cout << "refused" << std::endl;
        return (false);
    }
    else
    {
        _nbWithdrawals++;
        _amount -= withdrawal;
        _totalNbWithdrawals++;
        _totalAmount -= withdrawal;
        std::cout << withdrawal << ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
        return (true);
    }
}

int		Account::checkAmount( void ) const
{
    return (_amount);
}

void	Account::displayStatus( void ) const
{
    _displayTimestamp();
    std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl; 
}

void	Account::displayAccountsInfos( void )
{
    _displayTimestamp();
    std::cout << " accounts:" << getNbAccounts() << ";total:" << getTotalAmount() << ";deposits:" << getNbDeposits() << ";withdrawals:" << getNbWithdrawals() << std::endl;
}

Account::~Account( void )
{
    _displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;   
}