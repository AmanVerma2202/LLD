#include<bits/stdc++.h>
using namespace std;

class Employee{
  public:
  virtual void eat()=0;
  virtual void work()=0;
};

class Human: public Employee{
  public:
    void eat() override {
      cout<<"Human khate h khana";
    }
    void work() override {
      cout<<"Human kaam krte h";
    }
};

class Robot: public Employee{
  public:
    void eat() override {
      cout<<"Human khate h khana";
    }
    void work() override {
      cout<<"Robot kaam krte h";
    }
};



int main(){
  Human h;
  Robot r;
  h.eat();
  h.work();
  r.work();
  
}