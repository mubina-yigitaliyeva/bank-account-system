#include "Admin.h"
#include "Bank.h"
#include <iostream>

using namespace std;

Admin::Admin(string name, string pwd)
    : User("ADMIN", name, "", "", pwd) {}

string Admin::getRole() const { return "Admin"; }
string Admin::getAdminName() const { return getFullName(); }
void Admin::displayProfile() const {
    cout << "Administrator: " << fullName << '\n';
}

void Admin::showBanks(const vector<Bank*>& banks) const {
    cout << "\n========== REGISTERED BANKS ==========\n";
    if (banks.empty()) {
        cout << "No banks registered.\n";
    }
    for (Bank* bank : banks) {
        cout << bank->getBankId() << " - " << bank->getBankName()
             << " | " << bank->getAddress()
             << " | Status: " << bank->getStatus() << '\n';
    }
}