#include<bits/stdc++.h>
using namespace std;
// is we want to change in save_to_database or in get_user_info function then User class will affect again & again 
class User{
  string name;
  int age;
  string email;
  public:
  User(string name,int age, string email){
    this->age=age;
    this->name=name;
    this->email=email;
  }

  void get_user_info(){
    cout<<"User name is "<<name;
  }

  bool is_adult(){
    return this->age>18;
  }

  void save_to_database(){
    cout<<"saved to db!";
  }


};


int main(){
  User user1=User("aman",21,"aman@gmail.com");
  user1.get_user_info();
}