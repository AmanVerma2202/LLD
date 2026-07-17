#include<bits/stdc++.h>
using namespace std;


class Etable{
  public:
    virtual void eat()=0;
};

class Workable{
  public:
    virtual void work()=0;
};

class Robot: public Workable{
  public:
    void work() override {
      cout<<"robot kaam kr rha h";
    }
};

class Human: public Etable, public Workable{
  public:
    void eat() override {
      cout<<"human kaam kr rha h";
    }
    void work() override {
      cout<<"human khana kha rha h";
    }
};

int main(){
  Human h;
  h.eat();
  h.work();
}
