#ifndef BANK_ACCOUNT_MANAGER_BANK_STAFF_H
#define BANK_ACCOUNT_MANAGER_BANK_STAFF_H

#include "User.h"
using namespace std;

class BankStaff : public User {
private:
    string bankId;

public:
    BankStaff(string id, string bank, string name,
              string phone, string mail, string pwd);

    string getRole() const override;
    void displayProfile() const override;
    string getStaffId() const;
    string getBankId() const;
};

#endif