#include <iostream>
#include <fstream>
#include <string>
using namespace std;
 
class User {
private:
    string username;
    string password;
 
public:
    void setUsername(string u) { username = u; }
    void setPassword(string p) { password = p; }
 
    string getUsername() { return username; }
    string getPassword() { return password; }
 
    bool isValid() {
        if (username.empty() || password.empty()) {
            cout << "\nERROR! Username and password cannot be empty!\n";
            return false;
        }
        if (username.length() < 3) {
            cout << "\nERROR! Username must be at least 3 characters!\n";
            return false;
        }
        if (password.length() < 6) {
            cout << "\nERROR! Password must be at least 6 characters!\n";
            return false;
        }
        return true;
    }
};
 
class Registration {
public:
 
    
    bool isDuplicate(string username) {
        string filename = username + ".txt";  
        ifstream file(filename);
        return file.is_open();  
    }

    void registerUser() {
        User newUser;
        string uname, pass;
 
        cout << "\n========== REGISTRATION ==========\n";
        cout << "Enter Username : ";
        cin >> uname;
        cout << "Enter Password : ";
        cin >> pass;
 
        newUser.setUsername(uname);
        newUser.setPassword(pass);
 
        if (!newUser.isValid()) {
            return;
        }
 
        if (isDuplicate(newUser.getUsername())) {
            cout << "\nERROR! Username '" << newUser.getUsername()
                 << "' already exists! Choose a different username.\n";
            return;
        }
 
        string filename = newUser.getUsername() + ".txt";
        ofstream file(filename);
 
        if (!file.is_open()) {
            cout << "\nERROR! Could not create user file!\n";
            return;
        }
 
        file << "USERNAME:" << newUser.getUsername() << endl;
        file << "PASSWORD:" << newUser.getPassword() << endl;
        file.close();
 
        cout << "\nSUCCESS! Registration successful!\n";
        cout << "          Your data is saved in '" << filename << "'.\n";
        cout << "          You can now log in.\n";
    }
};

class Login {
public:
    void loginUser() {
        string uname, pass;
 
        cout << "\n========== LOGIN ==========\n";
        cout << "Enter Username : ";
        cin >> uname;
        cout << "Enter Password : ";
        cin >> pass;
 
        string filename = uname + ".txt";
        ifstream file(filename);
 
        if (!file.is_open()) {
            cout << "\nERROR! Username '" << uname << "' not found!"
                 << " Please register first.\n";
            return;
        }
 
        string line, storedUser = "", storedPass = "";
 
        while (getline(file, line)) {
            if (line.substr(0, 9) == "USERNAME:") {
                storedUser = line.substr(9);  
            }
            if (line.substr(0, 9) == "PASSWORD:") {
                storedPass = line.substr(9); 
            }
        }
        file.close();
 
        if (uname == storedUser && pass == storedPass) {
            cout << "\nSUCCESS! Login successful! Welcome, " << uname << "!\n";
        } else {
            cout << "\nERROR! Incorrect password. Please try again.\n";
        }
    }
};
 
int main() {
    Registration reg;
    Login log;
    int choice;
 
    cout << "===   LOGIN AND REGISTRATION SYSTEM   ===\n";
 
    do {
        cout << "\n-------- MENU --------\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Enter choice (1-3): ";
        cin >> choice;
 
        switch (choice) {
            case 1:
                reg.registerUser();
                break;
            case 2:
                log.loginUser();
                break;
            case 3:
                cout << "\nGoodbye! Exiting system...\n";
                break;
            default:
                cout << "\n[ERROR] Invalid choice! Please enter 1, 2, or 3.\n";
        }
 
    } while (choice != 3);
 
    return 0;
}