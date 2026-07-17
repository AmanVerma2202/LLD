#include<bits/stdc++.h>
using namespace std;


// this is abstraction 
class Notifier{
  public:
    virtual void send(string msg) = 0;
    virtual ~Notifier() = default; 
};

class EmailService : public Notifier{
  public:
    void send(string email) override {
      cout<<"email sent to "<<email;
    }
};

class SMSService : public Notifier{
  public:
    void send(string number) override {
      cout<<"sms sent to "<<number;
    }
};

// easily added WA notification service 
class WhatsApp: public Notifier{
  public:
    void send(string number) override {
      cout<<"wa sms sent to "<<number;
    }
};

class NotificationService{
  Notifier* notifier;
  public:
    NotificationService(Notifier* notifier) {
        this->notifier = notifier;
    }

    void notify(string msg) {
        notifier->send(msg);
    }
};


int main(){
    EmailService email;
    SMSService sms;
    WhatsApp wp;

    NotificationService emailNotification(&email);
    emailNotification.notify("aman@gmail.com");

    NotificationService smsNotification(&sms);
    smsNotification.notify("7007751852");

    NotificationService wpNotification(&wp);
    wpNotification.notify("HI");
}