#include <bits/stdc++.h>
using namespace std;

// SRP-compliant design: each class has one clear responsibility.
class User {
    string name;
    int age;
    string email;

public:
    User(string name, int age, string email)
        : name(move(name)), age(age), email(move(email)) {}

    string getName() const { return name; }
    int getAge() const { return age; }
    string getEmail() const { return email; }
};

class UserProfile {
public:
    static void printInfo(const User& user) {
        cout << "User name is " << user.getName() << "\n";
    }
};

class UserValidator {
public:
    static bool isAdult(const User& user) {
        return user.getAge() > 18;
    }
};

class UserRepository {
public:
    static void saveToDatabase(const User& user) {
        cout << "Saved user '" << user.getName() << "' to db!\n";
    }

    static void deleteFromDatabase(const User& user) {
        cout << "Deleted user '" << user.getName() << "' from db!\n";
    }
};

int main() {
    User user("aman verma", 21, "aman@gmail.com");

    UserProfile::printInfo(user);
    cout << "Is adult? " << (UserValidator::isAdult(user) ? "yes" : "no") << "\n";

    UserRepository::saveToDatabase(user);
    UserRepository::deleteFromDatabase(user);
}
