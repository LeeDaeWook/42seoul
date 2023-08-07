#include "Account.hpp"

int	Account::_nbAccounts;
int	Account::_totalAmount;
int	Account::_totalNbDeposits;
int	Account::_totalNbWithdrawals;

int Account::getNbAccounts(void)
{
    return _nbAccounts;
}

int Account::getTotalAmount(void)
{
    return _totalAmount;
}

int Account::getNbDeposits(void)
{
    return _totalNbDeposits;
}

int Account::getNbWithdrawals(void)
{
    return _totalNbWithdrawals;
}

void    Account::displayAccountsInfos(void)
{
    _displayTimestamp();
    std::cout << "accounts:" << getNbAccounts() << ";total:" \
    << getTotalAmount() << ";deposits:" << getNbDeposits() \
    << ";withdrawals:" << getNbWithdrawals() << std::endl;   
}

Account::Account(int initial_deposit)
{
    _amount = initial_deposit;
    _accountIndex = _nbAccounts;
    _nbAccounts++;
    _nbDeposits = 0;
    _nbWithdrawals = 0;
    _totalAmount += initial_deposit;

    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}

Account::~Account(void)
{
    _nbAccounts--;
    _totalAmount -= _amount;
    _totalNbDeposits -= _nbDeposits;
    _totalNbWithdrawals -= _nbWithdrawals;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

void Account::makeDeposit(int deposit)
{
    _amount += deposit;
    _displayTimestamp();
    _totalAmount += deposit;
    _nbDeposits++;
    _totalNbDeposits++;
    std::cout << "index:" << _accountIndex << ";p_amount:" << _amount - deposit << ";deposit:" << deposit << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << std::endl;
}

bool    Account::makeWithdrawal(int withdrawal)
{
    bool    ret_val;

    _amount -= withdrawal;
    _displayTimestamp();
    _totalAmount -= withdrawal;
    std::cout << "index:" << _accountIndex << ";p_amount:" << _amount + withdrawal << ";withdrawal:";
    _nbWithdrawals++;
    _totalNbWithdrawals++;
    if (!checkAmount())
    {
        ret_val = false;
        _amount += withdrawal;
        _totalAmount += withdrawal;
        _nbWithdrawals--;
        _totalNbWithdrawals--;
        std::cout << "refused";
    }
    else
    {
        ret_val = true;
        std::cout << withdrawal << ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals;
    }
    std::cout << std::endl;
    return (ret_val);
}

int     Account::checkAmount(void) const
{
    if (_amount < 0)
        return 0;
    return 1;
}

void    Account::displayStatus(void) const
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}

void    Account::_displayTimestamp(void)
{
    char timeString[100];

    std::time_t currentTime = std::time(NULL);
    std::strftime(timeString, sizeof(timeString), "%Y%m%d_%H%M%S", std::localtime(&currentTime));
    std::cout << "[" << timeString << "] ";
}