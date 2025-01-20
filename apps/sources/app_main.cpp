#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>

#include "./../headers/app_main.h"
#include "./../headers/user_main.h"
#include "./../headers/admin_main.h"

UiCommon uiCommon;

// Simulated user data
std::unordered_map<std::string, std::string> userCredentials = {
    {"admin", "admin123"}, // Admin credentials
    {"user", "user123"}    // User credentials
};

// Function to validate login credentials
std::string ValidateLogin(const std::string& name, const std::string& password) {
    auto it = userCredentials.find(name);
    if (it != userCredentials.end() && it->second == password) {
        return name == "admin" ? "admin" : "user";
    }
    return "";
}

// Function to display the app menu
static int ReadAppMenu() {
    int choice;

    uiCommon.TitleBar("Driver App");

    std::stringstream soutput;
    soutput << "1 - Driver Registration" << std::endl;
    soutput << "2 - Login" << std::endl;
    soutput << "99 - Exit" << std::endl;
    soutput << "Your choice:";
    choice = uiCommon.in.Int(soutput.str());

    uiCommon.Line('~');
    uiCommon.PressAnyKey(true);
    return choice;
}

// Function to manage the app
void ManageApp() {
    int choice;

    do {
        choice = ReadAppMenu();
        switch (choice) {
            case 1: { // Driver Registration
                ManageUser();
            } break;

            case 2: { // Login
                std::string name, password;

                uiCommon.TitleBar("Login");
                std::cout << "Enter Name: ";
                std::cin >> name;
                std::cout << "Enter Password: ";
                std::cin >> password;

                std::string role = ValidateLogin(name, password);

                if (role == "admin") {
                    std::cout << "Login successful! Redirecting to Admin Dashboard..." << std::endl;
                    ManageAdmin();
                } else if (role == "user") {
                    std::cout << "Login successful! Redirecting to User Dashboard..." << std::endl;
                    ManageUser();
                } else {
                    std::cout << "Invalid credentials. Please try again." << std::endl;
                }

                uiCommon.PressAnyKey(true);
            } break;

            case 99: {
                std::cout << "Exiting the application. Goodbye!" << std::endl;
            } break;

            default: {
                std::cout << "Invalid choice. Please try again." << std::endl;
            } break;
        }
    } while (choice != 99);
}

// Entry point for the app
void AppMain() {
    ManageApp();
}