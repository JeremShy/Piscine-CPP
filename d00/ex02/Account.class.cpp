#include "Account.class.hpp"
#include <ctime>
#include <iostream>
#include <iomanip>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) : _amount(initial_deposit), _nbDeposits(0)
																				, _accountIndex(Account::_nbAccounts)
																				, _nbWithdrawals(0){
	Account::_nbAccounts++;
	Account::_totalAmount += initial_deposit;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";created" << std::endl;
}

Account::Account(void) {
	Account::_nbAccounts++;
}

Account::~Account(void) {
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
						<< "amount:" << this->_amount << ";"
						<< "closed" << std::endl;

}

int	Account::getNbAccounts( void ) {
	return (0);
}

int	Account::getTotalAmount( void ) {
	return (0);
}

int	Account::getNbDeposits( void ) {
	return (0);
}

int	Account::getNbWithdrawals( void ) {
	return (0);
}

void	Account::displayAccountsInfos( void ) {
	Account::_displayTimestamp();
	std::cout << "accounts:"   << Account::_nbAccounts         << ";"
						<< "total:"      << Account::_totalAmount        << ";"
						<< "deposits:"    << Account::_totalNbDeposits    << ";"
						<< "withdrawals:" << Account::_totalNbWithdrawals
						<< std::endl;
}

void	Account::makeDeposit( int deposit ) {
	int p = this->_amount;

	this->_amount += deposit;
	this->_nbDeposits++;
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits++;

	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
						<< "p_amount:" << p << ";"
						<< "deposit:" << deposit << ";"
						<< "amount:" << this->_amount << ";"
						<< "nb_deposits:" << this->_nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal ) {

	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
			 << "p_amount:" << this->_amount << ";";
	if (withdrawal > this->_amount) {
		std::cout << "withdrawal:refused" << std::endl;
		return false;
	}
	Account::_totalAmount -= withdrawal;
	this->_amount -= withdrawal;
	this->_nbWithdrawals++;
	Account::_totalNbWithdrawals++;
	std::cout << "withdrawal:" << withdrawal << ";"
						<< "amount:" << this->_amount << ";"
						<< "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	return (true);
}

int		Account::checkAmount( void ) const {
	return (0);
}

void	Account::displayStatus( void ) const {
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
						<< "amount:" << this->_amount << ";"
						<< "deposits:" << this->_nbDeposits << ";"
						<< "withdrawals:" << this->_nbWithdrawals << std::endl;
}

void	Account::_displayTimestamp( void ) {
	time_t t = time(0);
	struct tm *now = localtime(&t);
	std::cout << "[" <<  (now->tm_year + 1900) << std::setw(2) << std::setfill('0')
		<< (now->tm_mon + 1) << std::setw(2) << std::setfill('0') <<  now->tm_mday
		<< "_" << std::setw(2) << std::setfill('0') << now->tm_hour << std::setw(2)
		<< std::setfill('0') << now->tm_min << std::setw(2) << std::setfill('0')
		<< now->tm_sec << "] ";
}
