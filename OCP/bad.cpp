#include<bits/stdc++.h>
using namespace std;

class PaymentProcessor{
  public:
  void pay(string payment_method,int amount){
    if(payment_method=="UPI"){
      cout<<"UPI transaction of rs "<<amount;
    }else if(payment_method=="Credit Card"){
      cout<<"Credit Card transaction of rs "<<amount;
    }else if(payment_method=="Net Banking"){
      cout<<"Net Banking transaction of rs "<<amount;
    }
  }
  // what if i want paypal integration then we have to modify this ...which violates OCP
};

int main(){
  PaymentProcessor payment;
  payment.pay("UPI",3000);

}