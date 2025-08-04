#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit)
{
	_amount = initial_deposit;
	_accountIndex = _nbAccounts;
	_nbAccounts++;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
}

int	Account::getNbAccounts() { return (_nbAccounts); }
int	Account::getTotalAmount() { return (_totalAmount); }
int	Account::getNbDeposits() { return (_totalNbDeposits); }
int	Account::getNbWithdrawals() { return (_totalNbWithdrawals); }

