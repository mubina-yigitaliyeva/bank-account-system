#ifndef BANK_ACCOUNT_MANAGER_AUTHENTICATION_SYSTEM_H
#define BANK_ACCOUNT_MANAGER_AUTHENTICATION_SYSTEM_H

#include <string>
using namespace std;

class BankSystem;
class Customer;
class BankStaff;
class Admin;

class AuthenticationSystem {
public:
    static Customer* registerCustomer(BankSystem& system, string name,
                                      string phone, string email, string password);
    static BankStaff* registerBankAndStaff(BankSystem& system,
                                           string bankName, string bankPhone,
                                           string bankEmail, string bankAddress,
                                           string staffName, string staffPhone,
                                           string staffEmail, string staffPassword);
    static Customer* loginCustomer(const BankSystem& system,
                                   string contact, string password);
    static BankStaff* loginStaff(const BankSystem& system,
                                 string contact, string password);
    static const Admin* loginAdmin(const BankSystem& system,
                                   string username, string password);
};

#endif