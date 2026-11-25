#ifndef BANK_ACCOUNT_MANAGER_ADMIN_H
#define BANK_ACCOUNT_MANAGER_ADMIN_H

#include "User.h"
#include <vector>
using namespace std;

class Bank;

class Admin : public User {
public:
    Admin(string name, string pwd);
    string getRole() const override;
    void displayProfile() const override;
    string getAdminName() const;
    void showBanks(const vector<Bank*>& banks) const;
};

#endif