#include<bits/stdc++.h>
using namespace std;

class PaymentProcessor{
  public:
  virtual void pay(int amount){
  }
  virtual ~PaymentProcessor()=default;
};

class NetBanking: public PaymentProcessor{
  public:
  void pay(int amount){
    cout<<"Net Banking transaction of rs "<<amount;
  }

};
class UPI: public PaymentProcessor{
  public:
    void pay(int amount){
      cout<<"UPI transaction of rs "<<amount;
    }
  
};
class Credit: public PaymentProcessor{
  public:
    void pay(int amount){
      cout<<"Credit Card transaction of rs "<<amount;
    }
};

class PayPal: public PaymentProcessor{
  public:
    void pay(int amount){
      cout<<"PayPal transaction of rs "<<amount;
    }
};
int main(){
  UPI upi;
  upi.pay(3000);

  PayPal paypal;
  paypal.pay(4000);

}