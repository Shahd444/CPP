#include "Account.hpp"
#include <iostream>
#include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
	_displayTimestamp();
	this->_accountIndex = Account::_nbAccounts;
	Account::_nbAccounts++;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	Account::_totalAmount += initial_deposit;
	std::cout << "index:" << this->_accountIndex
				<< ";amount:" << this->_amount << ";created" << std::endl;
}

int	Account::getNbAccounts(void)
{
	return (Account::_nbAccounts);
}
int	Account::getTotalAmount(void)
{
	return (Account::_totalAmount);
}
int	Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}
int	Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}
int	Account::checkAmount(void) const
{
	return (_amount);
}

void	Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	this->_amount += deposit;
	this->_nbDeposits++;
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits++;
	std::cout << "index:" << this->_accountIndex 
				<< ";p_amount:" << this->_amount - deposit
				<< ";deposit:" << deposit
				<< ";amount:" << this->_amount
				<< ";nb_deposits:" << this->_nbDeposits << std::endl;
}
bool	Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
				<< ";p_amount:" << this->_amount
				<< ";withdrawal:";
	if (this->_amount >= withdrawal)
	{
		this->_amount -= withdrawal;
		this->_nbWithdrawals++;
		Account::_totalAmount -= withdrawal;
		Account::_totalNbWithdrawals++;
		std::cout << withdrawal
					<< ";amount:" << this->_amount
					<< ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
		return (true);
	}
	else
	{
		std::cout << "refused" << std::endl;
		return (false);
	}
}
void	Account::_displayTimestamp(void)
{
	std::time_t now = std::time(NULL);
	std::tm* tm = std::localtime(&now);
	char buf[20];
	std::strftime(buf, sizeof(buf), "[%Y%m%d_%H%M%S]", tm);
	std::cout << buf << " ";
}

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << Account::_nbAccounts
				<< ";total:" << Account::_totalAmount
				<< ";deposits:" << Account::_totalNbDeposits
				<< ";withdrawals:" << Account::_totalNbWithdrawals << std::endl;
}

void	Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
				<< ";amount:" << this->_amount 
				<< ";deposits:" << this->_nbDeposits 
				<< ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

Account::~Account(void)
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
				<< ";amount:" << this->_amount << ";closed" << std::endl;
}
