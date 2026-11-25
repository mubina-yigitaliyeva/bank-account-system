#include "Customer.h"

#include "Exceptions.h"

#include <iostream>

using namespace std;

Customer::Customer(string id, string name,
                   string phone, string mail, string pwd)
    : User(id, name, phone, mail, pwd) {}

Customer::~Customer() {
    for (Account* account : accounts) {
        delete account;
    }
}

void Customer::addAccount(Account* account) {
    if (account != nullptr) {
        accounts.push_back(account);
    }
}

void Customer::removeAccount(string accountNumber) {
    for (vector<Account*>::iterator it = accounts.begin();
         it != accounts.end(); ++it) {
        if ((*it)->getAccountNumber() == accountNumber) {
            // removing account from the actual memory
            delete *it;
            // removing its pointer from the vector
            accounts.erase(it);
            return;
        }
    }
    throw AccountNotFoundException();
}

Account* Customer::findAccount(string accountNumber) {
    for (Account* account : accounts) {
        if (account->getAccountNumber() == accountNumber) {
            return account;
        }
    }
    return nullptr;
}

void Customer::listAccounts(string bankId) const {
    int count = 0;
    for (Account* account : accounts) {
        if (bankId.empty() || account->getBankId() == bankId) {
            cout << "\nACCOUNT #" << ++count << " - " << account->getType() << "\n";
            account->display();
        }
    }
    if (count == 0) cout << "No accounts found.\n";
}

double Customer::getTotalBalance(string bankId) const {
    double total = 0.0;
    for (Account* account : accounts) {
        if (bankId.empty() || account->getBankId() == bankId) {
            total += account->getBalance();
        }
    }
    return total;
}

string Customer::getCustomerId() const { return getUserId(); }

string Customer::getRole() const { return "Customer"; }

void Customer::displayProfile() const {
    cout << "Customer: " << fullName << " (" << userId << ")\n";
    cout << "Phone: " << phoneNumber << " | Email: " << email << '\n';
}

const vector<Account*>& Customer::getAccounts() const {
    return accounts;
}