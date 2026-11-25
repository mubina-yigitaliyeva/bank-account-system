#ifndef BANK_ACCOUNT_MANAGER_USER_H
#define BANK_ACCOUNT_MANAGER_USER_H

#include <string>
using namespace std;

class User {
protected:
    string userId;
    string fullName;
    string phoneNumber;
    string email;
    string password;

public:
    User(string id, string name, string phone, string mail, string pwd);
    virtual ~User() {}

    string getUserId() const;
    string getFullName() const;
    string getPhoneNumber() const;
    string getEmail() const;
    string getPassword() const;
    bool verifyPassword(string pwd) const;

    virtual string getRole() const = 0;
    virtual void displayProfile() const = 0;
};

#endif