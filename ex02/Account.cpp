#include <iostream>
#include "Account.hpp"

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

void	Account::_displayTimestamp( void )
{
	std::cout<< "[19920104_091532] "; // temp!!
	return;
}

Account::Account(int deposit):
		_accountIndex(_nbAccounts),
		_amount(deposit),
		_nbDeposits(0),
		_nbWithdrawals(0)
{
	_nbAccounts ++;
	_totalAmount += deposit;
	_displayTimestamp ();
	std::cout<< "index:" << this->_accountIndex
			 << ";amount:" << this->_amount
			 << ";created"
			 << std::endl;
}

Account::~Account(void)
{
	_displayTimestamp ();
	std::cout<< "index:" << this->_accountIndex
			 << ";amount:" << this->_amount
			 << ";closed"
			 << std::endl;
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

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp ();
	std::cout<< "accounts:"		<< _nbAccounts
			 << ";total:"		<< _totalAmount
			 << ";deposits:"	<< _totalNbDeposits
			 << ";withdrawals:"	<< _totalNbWithdrawals
			 << std::endl;
	return;
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp ();
	std::cout<< "index:"		<< _accountIndex
			 << ";amount:"		<< _amount
			 << ";deposits:"	<< _nbDeposits
			 << ";withdrawals:"	<< _nbWithdrawals
			 << std::endl;
}

void	Account::makeDeposit(int deposit)
{
	int	p_amount;

	p_amount = this->_amount;
	this->_amount += deposit;
	this->_nbDeposits ++;
	_totalAmount += deposit;
	_totalNbDeposits ++;
	_displayTimestamp ();
	std::cout<< "index:"		<< _accountIndex
			 << ";p_amount:"	<< p_amount
			 << ";deposit:"		<< deposit
			 << ";amount:"		<< this->_amount
			 << ";nb_deposits:"	<< _nbDeposits
			 << std::endl;
}

int		Account::checkAmount( void ) const
{
	return (this->_amount);
}

bool	Account::makeWithdrawal(int withdrawal)
{
	int	p_amount;
	
	if (withdrawal > this->_amount)
	{
		_displayTimestamp ();
		std::cout<< "index:"		<< _accountIndex
				<< ";p_amount:"		<< this->_amount
				<< ";withdrawal:"	<< "refused"
				<< std::endl;
		return (false);
	}
	p_amount = this->_amount;
	this->_amount -= withdrawal;
	this->_nbWithdrawals ++;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals ++;
	_displayTimestamp ();
	std::cout<< "index:"			<< _accountIndex
			 << ";p_amount:"		<< p_amount
			 << ";withdrawal:"		<< withdrawal
			 << ";amount:"			<< this->_amount
			 << ";nb_withdrawals:"	<< _nbWithdrawals
			 << std::endl;
	return (true);
}
