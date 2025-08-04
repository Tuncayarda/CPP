#include <iostream>
#include <ctime>
#include <iomanip>
#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account()
{

}

Account::Account( int initial_deposit)
{
	_amount = initial_deposit;
	_totalAmount += initial_deposit;
	_accountIndex = _nbAccounts;
	_nbAccounts++;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_displayTimestamp();
	std::cout
		<< "index:" << _accountIndex
		<< ";amount:" << _amount
		<< ";created"
		<< std::endl;
}

Account::~Account()
{

}

int	Account::getNbAccounts() { return (_nbAccounts); }
int	Account::getTotalAmount() { return (_totalAmount); }
int	Account::getNbDeposits() { return (_totalNbDeposits); }
int	Account::getNbWithdrawals() { return (_totalNbWithdrawals); }

void	Account::_displayTimestamp( void )
{
	std::time_t	now = std::time(nullptr);
	std::tm*	tm = std::localtime(&now);
	std::cout << "[" << std::put_time(tm, "%Y%m%d_%H%M%S") << "] ";
}

void	Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout
	<< "accounts:" << _nbAccounts
	<< ";total:" << _totalAmount
	<< ";deposits:" << _totalNbDeposits
	<< ";withdrawals:" << _totalNbWithdrawals
	<< std::endl;
}
void	Account::makeDeposit( int deposit ) {}
bool	Account::makeWithdrawal ( int withdrawal ) {return true;}
int		Account::checkAmount() const {return 31;}

void	Account::displayStatus() const
{
	_displayTimestamp();
	std::cout
		<< "index:" << _accountIndex
		<< ";amount:" << _amount
		<< ";deposits:" << _nbDeposits
		<< ";withdrawals" << _nbWithdrawals
		<< std::endl;
}
