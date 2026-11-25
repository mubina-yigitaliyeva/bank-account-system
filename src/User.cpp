#include "User.h"

User::User(string id, string name, string phone, string mail, string pwd)
    : userId(id), fullName(name), phoneNumber(phone), email(mail), password(pwd) {}

string User::getUserId() const { return userId; }
string User::getFullName() const { return fullName; }
string User::getPhoneNumber() const { return phoneNumber; }
string User::getEmail() const { return email; }
string User::getPassword() const { return password; }
bool User::verifyPassword(string pwd) const { return password == pwd; }