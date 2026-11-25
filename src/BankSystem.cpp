#include "BankSystem.h"
#include "Menus.h"
#include "FileStorage.h"
#include <cctype>

using namespace std;

void BankSystem::run() {
    runMainMenu(*this);
}

BankSystem::BankSystem() : admin("admin", "admin") {
    // Start with DEU as the sample bank.
    banks.push_back(new Bank("B001", "deu", "01000000000",
                             "deu@example.com", "Busan, South Korea"));
}

BankSystem::~BankSystem() {
    for (Bank* bank : banks) delete bank;
    for (BankStaff* staff : staffMembers) delete staff;
    for (Customer* customer : customers) delete customer;
}

Bank* BankSystem::findBank(string id) const {
    for (Bank* bank : banks) {
        if (bank->getBankId() == id) return bank;
    }
    return nullptr;
}

Bank* BankSystem::findBankByName(string name) const {
    // ignoring upper/lower case in bank names.
    for (char& c : name) c = static_cast<char>(tolower(static_cast<unsigned char>(c)));

    for (Bank* bank : banks) {
        string registered = bank->getBankName();
        for (char& c : registered)
            c = static_cast<char>(tolower(static_cast<unsigned char>(c)));
        if (registered == name) return bank;
    }
    return nullptr;
}

const vector<Bank*>& BankSystem::getBanks() const { return banks; }
const vector<BankStaff*>& BankSystem::getStaffMembers() const { return staffMembers; }
const Admin& BankSystem::getAdmin() const { return admin; }
void BankSystem::showBanks() const { admin.showBanks(banks); }
void BankSystem::save() const { FileStorage::save(*this); }

Customer* BankSystem::findCustomer(string id) const {
    for (Customer* customer : customers) {
        if (customer->getCustomerId() == id) return customer;
    }
    return nullptr;
}

const vector<Customer*>& BankSystem::getCustomers() const { return customers; }