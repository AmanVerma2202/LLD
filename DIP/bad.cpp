#include<bits/stdc++.h>
using namespace std;

class EmailService{
  public:
    void email(string email){
      cout<<"email sent to "<<email;
    }
};

class SMSService{
  public:
    void sms(string number){
      cout<<"sms sent to "<<number;
    }
};

class NotificationService{
  EmailService eml;
  SMSService sms;
  public:
    NotificationService(){
      this->eml=EmailService();
      this->sms=SMSService();
    }
    void notifyByEmail(string gmail){
      this->eml.email(gmail);
    }
    void notifyBySMS(string number){
      this->sms.sms(number);
    }
    
};


int main(){
  NotificationService nts;
  // but NotificationService depends on email and sms service 
  nts.notifyByEmail("aman@gmail.com");
  nts.notifyBySMS("7007751852");
}