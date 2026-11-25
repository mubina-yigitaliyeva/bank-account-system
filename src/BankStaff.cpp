#include "BankStaff.h"
#include <iostream>
using namespace std;

BankStaff::BankStaff(string id, string bank, string name,
                     string phone, string mail, string pwd)
    : User(id, name, phone, mail, pwd), bankId(bank) {}

string BankStaff::getRole() const { return "BankStaff"; }

void BankStaff::displayProfile() const {
    cout << "Bank staff: " << fullName << " (" << userId << ")\n";
    cout << "Bank ID: " << bankId << " | Email: " << email << '\n';
}

string BankStaff::getStaffId() const { return getUserId(); }
string BankStaff::getBankId() const { return bankId; }