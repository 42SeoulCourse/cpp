// For Draft
#include "Account.hpp"
#include <iostream>
#include <iomanip>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(void) {
    return ;
}

Account::Account(int initial_deposit) {
    this->_amount = initial_deposit;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;
    this->_accountIndex = _nbAccounts;
    Account::_nbAccounts++;
    Account::_totalAmount += this->_amount;
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "amount:" << this->_amount << ";";
    std::cout << "created" << std::endl;
}

Account::~Account(void) {
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "amount:" << this->_amount << ";";
    std::cout << "closed" << std::endl;
}

void    Account::_displayTimestamp(void) {
    time_t      time_ptr;
    struct tm   *currentTime;

    std::time(&time_ptr);
    currentTime = localtime(&time_ptr);
    std::cout << "[";
    std::cout << currentTime->tm_year + 1900;
    std::cout << std::setw(2) << std::setfill('0') << currentTime->tm_mon + 1;
    std::cout << std::setw(2) << std::setfill('0') << currentTime->tm_mday << "_";
    std::cout << std::setw(2) << std::setfill('0') << currentTime->tm_hour;
    std::cout << std::setw(2) << std::setfill('0') << currentTime->tm_min;
    std::cout << std::setw(2) << std::setfill('0') << currentTime->tm_sec;
    std::cout << "]";
}

void    Account::displayAccountsInfos(void) {
    Account::_displayTimestamp();
    std::cout << "accounts:" << Account::getNbAccounts() << ";";
    std::cout << "total:" << Account::getTotalAmount() << ";";
    std::cout << "deposits:" << Account::getNbDeposits() << ";";
    std::cout << "withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

int	Account::getNbAccounts( void ) {
    return (Account::_nbAccounts);
}

int	Account::getTotalAmount( void ) {
    return (Account::_totalAmount);
}

int	Account::getNbDeposits( void ) {
    return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals( void ) {
    return (Account::_totalNbWithdrawals);
}

void    Account::displayStatus(void) const
{
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "amount:" << this->_amount << ";";  
    std::cout << "deposits:" << this->_nbDeposits << ";";
    std::cout << "withdrawals:" << this->_nbWithdrawals << std::endl;
}

// void    

// static int	getNbAccounts( void );
// static int	getTotalAmount( void );
// static int	getNbDeposits( void );
// static int	getNbWithdrawals( void );
// static void	displayAccountsInfos( void );

// Account( int initial_deposit );
// // ~Account( void );

// void	makeDeposit( int deposit );
// bool	makeWithdrawal( int withdrawal );
// int		checkAmount( void ) const;
// void	displayStatus( void ) const;

// private:

// static int	_nbAccounts;
// static int	_totalAmount;
// static int	_totalNbDeposits;
// static int	_totalNbWithdrawals;

// static void	_displayTimestamp( void );

// int				_accountIndex;
// int				_amount;
// int				_nbDeposits;
// int				_nbWithdrawals;
