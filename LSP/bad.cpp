#include<bits/stdc++.h>
using namespace std;

class BankAccount{
  protected:
    float balance;
  public:
    BankAccount(float balance){
      this->balance=balance;
    }

    virtual void withdraw(float amount)=0;
    virtual void deposit(float amount)=0;
};

class SavingsAccount: public BankAccount{
  public:
    SavingsAccount(float balance)
        : BankAccount(balance) {}

    void withdraw(float amount) override {
        if(balance - amount >= 1000)
        {
            balance -= amount;
            cout << "Withdraw Successful\n";
        }
        else
        {
            cout << "Minimum Balance Required\n";
        }
    }

    void deposit(float amount) override {
        balance += amount;
    }
};

class CurrentAccount : public BankAccount {
public:
    CurrentAccount(float balance)
        : BankAccount(balance) {}

    void withdraw(float amount) override {
        if(balance - amount >= 1000)
        {
            balance -= amount;
            cout << "Withdraw Successful\n";
        }
        else
        {
            cout << "Minimum Balance Required\n";
        }
    }

    void deposit(float amount) override {
        balance += amount;
    }
};

// ye Liskov ko break karega 
// we have to split our BankAccount class in order to prevent from runtime exception

class FDAccount : public BankAccount {
public:
    FDAccount(float balance) : BankAccount(balance) {}

    void withdraw(float amount) override {
        throw runtime_error("Withdrawal is not allowed from a Fixed Deposit account before maturity.");
    }

    void deposit(float amount) override {
        balance += amount;
    }
};



int main(){
  SavingsAccount s(5000);
  CurrentAccount c(1000);
  FDAccount fd(50000);
  fd.withdraw(300);
  s.withdraw(500);
}