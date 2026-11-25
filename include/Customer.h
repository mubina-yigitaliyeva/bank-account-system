#ifndef BANK_ACCOUNT_MANAGER_CUSTOMER_H
#define BANK_ACCOUNT_MANAGER_CUSTOMER_H

#include "User.h"
#include "Account.h"
#include <vector>
using namespace std;

class Customer : public User {
private:
    vector<Account*> accounts; // This customer owns its accounts.

public:
    Customer(string id, string name, string phone, string mail, string pwd);
    ~Customer() override;

    string getRole() const override;
    void displayProfile() const override;

    void addAccount(Account* account);
    void removeAccount(string accountNumber);
    Account* findAccount(string accountNumber);
    void listAccounts(string bankId = "") const;
    double getTotalBalance(string bankId = "") const;
    string getCustomerId() const; 
    const vector<Account*>& getAccounts() const;
};

#endif