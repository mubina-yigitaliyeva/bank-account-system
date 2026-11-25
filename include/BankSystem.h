#ifndef BANK_ACCOUNT_MANAGER_BANK_SYSTEM_H
#define BANK_ACCOUNT_MANAGER_BANK_SYSTEM_H

#include "Admin.h"
#include "Bank.h"
#include "BankStaff.h"
#include <string>
#include <vector>

using namespace std;

class FileStorage;
class AuthenticationSystem;

class BankSystem {
    friend class FileStorage;
    friend class AuthenticationSystem;
class AuthenticationSystem;
private:
    vector<Bank*> banks;
    vector<Customer*> customers;
    vector<BankStaff*> staffMembers;
    Admin admin;
    int nextCustomerId = 1001;
    int nextBankId = 2;
    int nextStaffId = 1;

public:
    BankSystem();
    ~BankSystem();

    Bank* findBank(string id) const;
    Customer* findCustomer(string id) const;
    Bank* findBankByName(string name) const;
    const vector<Bank*>& getBanks() const;
    const vector<Customer*>& getCustomers() const;
    const vector<BankStaff*>& getStaffMembers() const;
    const Admin& getAdmin() const;
    void showBanks() const;
    void save() const;
    void run();
};

#endif