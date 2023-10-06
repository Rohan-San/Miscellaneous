#include <iostream>
#include <string>

using namespace std;

class Bank {
protected:
    string name;
    long accountNumber;
    double balance;

public:
    Bank(const string& n, long acc, double bal) : name(n), accountNumber(acc), balance(bal) {}

    virtual void display() {
        cout << "Name: " << name << "\nAccount Number: " << accountNumber << "\nBalance: $" << balance << endl;
    }

    virtual void calculateInterest() = 0; // Pure virtual function for interest calculation
};

class CityBank : public Bank {
public:
    CityBank(const string& n, long acc, double bal) : Bank(n, acc, bal) {}

    void calculateInterest() override {
        double rate = 5.0; // Interest rate for City Bank (5%)
        double interest = (balance * rate) / 100.0;
        cout << "City Bank Interest Earned: $" << interest << endl;
    }
};

class SBIBank : public Bank {
public:
    SBIBank(const string& n, long acc, double bal) : Bank(n, acc, bal) {}

    void calculateInterest() override {
        double rate = 4.5; // Interest rate for SBI Bank (4.5%)
        double interest = (balance * rate) / 100.0;
        cout << "SBI Bank Interest Earned: $" << interest << endl;
    }
};

class CanaraBank : public Bank {
public:
    CanaraBank(const string& n, long acc, double bal) : Bank(n, acc, bal) {}

    void calculateInterest() override {
        double rate = 4.75; // Interest rate for Canara Bank (4.75%)
        double interest = (balance * rate) / 100.0;
        cout << "Canara Bank Interest Earned: $" << interest << endl;
    }
};

int main() {
    CityBank cityAccount("John Doe", 1001, 5000.0);
    SBIBank sbiAccount("Alice Smith", 2002, 7500.0);
    CanaraBank canaraAccount("Bob Johnson", 3003, 6000.0);

    cityAccount.display();
    cityAccount.calculateInterest();

    sbiAccount.display();
    sbiAccount.calculateInterest();

    canaraAccount.display();
    canaraAccount.calculateInterest();

    return 0;
}
