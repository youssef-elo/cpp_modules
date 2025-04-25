#include "Account.hpp"
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(){}

Account::Account(int initial_deposit)
{
	_displayTimestamp();
	_accountIndex = Account::_nbAccounts;
	Account::_nbAccounts++;
	Account::_totalAmount += initial_deposit;
	_amount = initial_deposit;
	std::cout << "index:" << _accountIndex 
				<< ";amount:" << initial_deposit 
				<< ";created" << std::endl;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
}

int	Account::getNbAccounts( void )
{
	return Account::_nbAccounts;
}
int	Account::getTotalAmount( void )
{
	return Account::_totalAmount;
}
int	Account::getNbDeposits( void )
{
	return Account::_totalNbDeposits;
}
int	Account::getNbWithdrawals( void )
{
	return Account::_totalNbWithdrawals;
}
int Account::checkAmount() const
{
	return _amount;
}

void Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() 
				<< ";total:" << getTotalAmount() 
				<< ";deposits:" << getNbDeposits()
				<< ";withdrawals:" << getNbWithdrawals() << std::endl;
}

void Account::displayStatus() const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
				<< ";amount:" << _amount
				<< ";deposits:" << _nbDeposits
				<< ";withdrawals:" << _nbWithdrawals << std::endl;
}

void Account::makeDeposit(int deposit)
{
	int pre = _amount;
	Account::_totalNbDeposits++;
	_nbDeposits++;
	_amount += deposit;
	Account::_totalAmount += deposit;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
				<< ";p_amount:" << pre
				<< ";deposit:" << deposit
				<< ";amount:" << _amount
				<< ";nb_deposits:" << _nbDeposits << std::endl;
}


bool Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	if (checkAmount() < withdrawal)
	{
		std::cout << "index:" << _accountIndex 
				<< ";p_amount:" << _amount 
				<< ";withdrawal:refused" << std::endl;
		return false;
	}
	Account::_totalNbWithdrawals++;
	_nbWithdrawals++;
	_amount -= withdrawal;
	Account::_totalAmount -= withdrawal;
	std::cout << "index:" << _accountIndex 
				<< ";p_amount:" << _amount + withdrawal
				<< ";withdrawal:" << withdrawal 
				<< ";amount:" << _amount 
				<< ";nb_withdrawals:" << _nbWithdrawals << std::endl;
	return true;
}

void Account::_displayTimestamp()
{
	std::cout << "[19920104_091532] ";
}

Account::~Account(){
	_displayTimestamp();
	std::cout << "index:" << _accountIndex 
				<< ";amount:" <<_amount
				<< ";closed" << std::endl;
}