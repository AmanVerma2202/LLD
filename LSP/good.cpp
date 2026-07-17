#include<bits/stdc++.h>
using namespace std;

class BankAccount{
  protected:
    float balance;
  public:
    BankAccount(float balance){
      this->balance=balance;
    }
    virtual void deposit(float amount)=0;
};


class Withdrawable: public BankAccount{
  public:
  Withdrawable(float balance): BankAccount(balance){}
  virtual void withdraw(float amount)=0;
};


class SavingsAccount: public Withdrawable{
  public:
    SavingsAccount(float balance)
        : Withdrawable(balance) {}

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

class CurrentAccount : public Withdrawable {
public:
    CurrentAccount(float balance)
        : Withdrawable(balance) {}

    void withdraw(float amount) override {
        balance -= amount;
    }

    void deposit(float amount) override {
        balance += amount;
    }
};


class FDAccount : public BankAccount {
public:
    FDAccount(float balance) : BankAccount(balance) {}
    void deposit(float amount) override {
        balance += amount;
    }
};



int main(){
  SavingsAccount s(5000);
  CurrentAccount c(1000);
  FDAccount fd(50000);
  fd.deposit(400);
  s.withdraw(500);
}