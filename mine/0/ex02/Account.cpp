/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 21:47:41 by jpaul             #+#    #+#             */
/*   Updated: 2025/01/05 21:47:41 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime> // For std::time, std::strftime
#include <sstream>
#include <iomanip>
#include <iostream>
#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts(void)       {return _nbAccounts;}
int Account::getTotalAmount(void)      {return _totalAmount;}
int Account::getNbDeposits(void)       {return _totalNbDeposits;}
int Account::getNbWithdrawals(void)    {return _totalNbWithdrawals;}
int Account::checkAmount(void) const   {return _amount;}

void Account::_displayTimestamp(void)
{
    std::time_t now = std::time(0);
    std::tm *ltm = std::localtime(&now);

    char buffer[20];
    std::strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S] ", ltm);

    std::cout << buffer;
}

void Account::displayAccountsInfos(void) 
{
    _displayTimestamp();
    std::cout
        << "accounts:" << _nbAccounts << ";"
        << "total:" << _totalAmount << ";"
        << "deposits:" << _totalNbDeposits << ";"
        << "withdrawals:" << _totalNbWithdrawals
        << std::endl;
}

void Account::displayStatus(void) const
{
    _displayTimestamp();
    std::cout
        << "index:" << _accountIndex << ";"
        << "amount:" << _amount << ";"
        << "deposits:" << _nbDeposits << ";"
        << "withdrawals:" << _nbWithdrawals
        << std::endl;
}

Account::Account(int initial_deposit) 
{ 
    _accountIndex = _nbAccounts++;

	_amount = initial_deposit;
	_totalAmount += initial_deposit;

    _nbDeposits = 0;
	_nbWithdrawals = 0;

    _displayTimestamp();
    std::cout
        << "index:" << _accountIndex << ";"
        << "amount:" << _amount << ";"
        << "created" << std::endl;
}

Account::~Account(void) 
{
    _displayTimestamp();
    std::cout
        << "index:" << _accountIndex << ";"
        << "amount:" << _amount << ";"
        << "closed" << std::endl;
}

void Account::makeDeposit(int deposit)
{
    int p_amount = checkAmount();

    _amount += deposit;
    _totalAmount += deposit;

    _nbDeposits++;
    _totalNbDeposits++;

    _displayTimestamp();
    std::cout
        << "index:" << _accountIndex << ";"
        << "p_amount:" << p_amount << ";"
        << "deposit:" << deposit << ";"
        << "amount:" << checkAmount() << ";"
        << "nb_deposits:" << _nbDeposits
        << std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
    int p_amount = checkAmount();

    _displayTimestamp();
    std::cout
        <<"index:" << _accountIndex << ";"
        << "p_amount:" << p_amount << ";"
        << "withdrawal:";

    if (withdrawal > p_amount)
    {
        std::cout << "refused" << std::endl;
        return (false);
    }

    _amount -= withdrawal;
    _totalAmount -= withdrawal;

    _nbWithdrawals++;
    _totalNbWithdrawals++;

    std::cout
        << withdrawal << ";"
        << "amount:" << checkAmount() << ";"
        << "nb_withdrawals:" << _nbWithdrawals
        << std::endl;
    return (true);
}
