#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

// Generate Strong Random Password
string generateStrongPassword(int length) {
    string chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789@#$%&*";
    string password = "";
    for (int i = 0; i < length; i++) {
        password += chars[rand() % chars.length()];
    }
    return password;
}

// XOR Encryption
string encryptPassword(string pass) {
    char key = 'K';
    for (int i = 0; i < pass.length(); i++) {
        pass[i] ^= key;
    }
    return pass;
}

// Simple Hash
int hashPassword(string pass) {
    int hash = 0;
    for (char c : pass)
        hash += c;
    return hash;
}

// Salted Hash
int saltedHash(string pass, string salt) {
    int hash = 0;
    string combined = pass + salt;
    for (char c : combined)
        hash += c;
    return hash;
}

// OTP Generator
int generateOTP() {
    return rand() % 9000 + 1000;
}

int main() {
    srand(time(0));

    string username, password;
    string salt = "A9@3";

    cout << "----- Secure Password System -----\n";

    cout << "Enter Username: ";
    cin >> username;

    cout << "\n1. Enter your own password";
    cout << "\n2. Generate strong password automatically";
    cout << "\nChoose option: ";

    int choice;
    cin >> choice;

    if (choice == 1) {
        cout << "Enter Password: ";
        cin >> password;
    } else {
        password = generateStrongPassword(12);
        cout << "\nGenerated Strong Password: " << password << endl;
    }

    // Encryption
    string encrypted = encryptPassword(password);

    // Hash
    int hash = hashPassword(password);

    // Salted Hash
    int salted = saltedHash(password, salt);

    cout << "\n--- Security Details ---";
    cout << "\nEncrypted Password: " << encrypted;
    cout << "\nHashed Password: " << hash;
    cout << "\nSalted Hash: " << salted;

    // OTP Login
    int otp = generateOTP();
    cout << "\n\nYour OTP is: " << otp;

    int userOTP;
    cout << "\nEnter OTP: ";
    cin >> userOTP;

    if (otp == userOTP)
        cout << "\nLogin Successful, " << username << "!";
    else
        cout << "\nInvalid OTP. Login Failed.";

    return 0;
}
