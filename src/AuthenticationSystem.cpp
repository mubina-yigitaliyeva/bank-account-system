#include "AuthenticationSystem.h"
#include "BankSystem.h"
#include "Exceptions.h"
#include <string>
using namespace std;

// Basic checks also keep the '|' text-file separator out of saved fields.
bool validField(const string& s) {
    return !s.empty() && s.find_first_not_of(" \t\r\n") != string::npos &&
           s.find('|') == string::npos;
}

bool validEmail(const string& email) {
    size_t at = email.find('@');
    size_t dot = email.rfind('.');
    return at != string::npos && at > 0 &&
           email.find('@', at + 1) == string::npos &&
           dot != string::npos && dot > at + 1 && dot + 1 < email.size() &&
           email.find_first_of(" \t\r\n|") == string::npos;
}

BankStaff* AuthenticationSystem::loginStaff(const BankSystem& system, string emailOrPhone, string pwd) {
    for (BankStaff* staff : system.staffMembers) {
        if ((staff->getEmail() == emailOrPhone ||
             staff->getPhoneNumber() == emailOrPhone) &&
            staff->verifyPassword(pwd)) return staff;
    }
    throw BankingException("Incorrect staff email/phone or password.");
}

BankStaff* AuthenticationSystem::registerBankAndStaff(BankSystem& system, string bankName, string bankPhone,
                                           string bankEmail, string bankAddress,
                                           string staffName, string staffPhone,
                                           string staffEmail, string staffPassword) {
    if (!validField(bankName) || !validField(bankPhone) || !validEmail(bankEmail) ||
        !validField(bankAddress) || !validField(staffName) ||
        !validField(staffPhone) || !validEmail(staffEmail) ||
        !validField(staffPassword))
        throw BankingException("Invalid registration information.");
    if (system.findBankByName(bankName) != nullptr) {
        throw BankingException("Bank name is already registered.");
    }
    for (BankStaff* staff : system.staffMembers) {
        if (staff->getEmail() == staffEmail || staff->getPhoneNumber() == staffPhone) {
            throw BankingException("This staff email or phone is already registered.");
        }
    }

    // Generate unique IDs using the counters owned by BankSystem.
    string bankId = string("B") + (system.nextBankId < 10 ? "00" : (system.nextBankId < 100 ? "0" : ""))
                    + to_string(system.nextBankId);
    string staffId = string("S") + (system.nextStaffId < 10 ? "00" : (system.nextStaffId < 100 ? "0" : ""))
                     + to_string(system.nextStaffId);
    Bank* newBank = new Bank(bankId, bankName, bankPhone, bankEmail, bankAddress);
    BankStaff* newStaff = nullptr;
    try {
        newStaff = new BankStaff(staffId, bankId, staffName,
                                staffPhone, staffEmail, staffPassword);
    } catch (...) {
        delete newBank;
        throw;
    }
    newBank->setStatus("PENDING");
    system.banks.push_back(newBank);
    system.staffMembers.push_back(newStaff);
    ++system.nextBankId;
    ++system.nextStaffId;
    return newStaff;
}


Customer* AuthenticationSystem::registerCustomer(BankSystem& system, string name, string phone,
                                      string email, string password) {
    if (!validField(name) || !validField(phone) || !validEmail(email) ||
        !validField(password))
        throw BankingException("Invalid customer information.");
    for (Customer* customer : system.customers) {
        if (customer->getEmail() == email || customer->getPhoneNumber() == phone) {
            throw BankingException("Email or phone number is already registered.");
        }
    }
    string id = to_string(system.nextCustomerId);
    Customer* customer = new Customer(id, name, phone, email, password);
    system.customers.push_back(customer);
    ++system.nextCustomerId;
    return customer;
}

Customer* AuthenticationSystem::loginCustomer(const BankSystem& system, string emailOrPhone, string password) {
    for (Customer* customer : system.customers) {
        if ((customer->getEmail() == emailOrPhone ||
             customer->getPhoneNumber() == emailOrPhone) &&
            customer->verifyPassword(password)) return customer;
    }
    throw BankingException("Incorrect customer email/phone or password.");
}


const Admin* AuthenticationSystem::loginAdmin(const BankSystem& system,
                                              string username, string password) {
    if (system.admin.getAdminName() == username && system.admin.verifyPassword(password))
        return &system.admin;
    return nullptr;
}
