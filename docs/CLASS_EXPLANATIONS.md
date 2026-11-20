# How the updated bank classes work — team notes

## Why the design changed

**Earlier design:** A customer had to register separately in a chosen bank. The same person could have different customer profiles at different banks.

**Current design:** The customer registers only once with `BankSystem`. After logging in, the customer can open a savings or checking account at any bank. One `Customer` object owns all their accounts.

## What each class does

| Class | Simple explanation |
|---|---|
| `BankSystem` | Owns all banks, staff, and customer profiles. Registration and login happen here. |
| `Customer` | Saves customer contact details/password and owns their accounts. |
| `Bank` | Has bank name/contact/rates and issues savings/checking accounts. It keeps references only to customers with accounts here. |
| `Account` | Abstract parent class. Stores an account number, bank ID, and balance. |
| `SavingsAccount` | Adds interest rate and minimum balance. Its withdrawal checks the minimum. |
| `CheckingAccount` | Adds overdraft limit and transaction fee. Its withdrawal checks both. |
| `Admin` | Checks `admin` / `admin` login and allows viewing all banks, all customers, or customers at one bank. |
| `BankStaff` | Stores staff profile and which bank they work for. |
| `FileStorage` | Saves and loads customer, bank, staff and account records. |
| Exception classes | Show meaningful errors rather than accepting invalid operations. |

## Important UML relationships

- `BankSystem` **composition** `Customer`: BankSystem owns each customer, only once.
- `BankSystem` **composition** `Bank`: manages several banks.
- `Customer` **composition** `Account`: one person can own many accounts, potentially in different banks.
- `Account` **association** `Bank`: the `bankId` says which bank issued that account.
- `Bank` **association** `Customer`: the bank lists only people who have accounts there; the bank does not own their customer profiles.
- `SavingsAccount` and `CheckingAccount` **hierarchically inherit** `Account`.
- `BankStaff` **association** `Bank`: staff works at one bank.
- `FileStorage` **dependency** `BankSystem`: it reads and writes bank system data.
