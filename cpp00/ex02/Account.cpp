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
    std::cout << "] ";
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

void    Account::displayStatus( void ) const {
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "amount:" << this->_amount << ";";  
    std::cout << "deposits:" << this->_nbDeposits << ";";
    std::cout << "withdrawals:" << this->_nbWithdrawals << std::endl;
}

void    Account::makeDeposit( int deposit ) {
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "p_amount:" << this->_amount << ";";
    this->_amount += deposit;
    this->_nbDeposits++;
    Account::_totalAmount += deposit;
    Account::_totalNbDeposits++;
    std::cout << "deposit:" << deposit << ";";
    std::cout << "amount:" << this->_amount << ";";
    std::cout << "nb_deposits:" << this->_nbDeposits << std::endl;
}

int Account::checkAmount( void ) const {
    if (this->_amount < 0)
        return (1);
    return (0);
}

bool    Account::makeWithdrawal( int withdrawal ) {
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "p_amount:" << this->_amount << ";";

    this->_amount -= withdrawal;
    if (Account::checkAmount()) {
        this->_amount += withdrawal;
        std::cout << "withdrawal:refused" << std::endl;
        return (false);
    }
    Account::_totalAmount -= withdrawal;
    this->_nbWithdrawals++;
    Account::_totalNbWithdrawals++;
    std::cout << "withdrawal:" << withdrawal << ";";
    std::cout << "amount:" << this->_amount << ";";
    std::cout << "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
    return (true);
};
