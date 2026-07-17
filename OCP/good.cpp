#include<bits/stdc++.h>
using namespace std;

class PaymentProcessor{
  public:
  virtual void pay(int amount)=0;
  virtual ~PaymentProcessor()=default;
};

class NetBanking: public PaymentProcessor{
  public:
  void pay(int amount) override {
    cout<<"Net Banking transaction of rs "<<amount;
  }

};
class UPI: public PaymentProcessor{
  public:
    void pay(int amount) override {
      cout<<"UPI transaction of rs "<<amount;
    }
  
};
class Credit: public PaymentProcessor{
  public:
    void pay(int amount) override {
      cout<<"Credit Card transaction of rs "<<amount;
    }
};

class PayPal: public PaymentProcessor{
  public:
    void pay(int amount) override {
      cout<<"PayPal transaction of rs "<<amount;
    }
};
int main(){
  UPI upi;
  upi.pay(3000);

  PayPal paypal;
  paypal.pay(4000);

}