#include "user_main.h"  // Include the header file to define the class and methods
#include "./../headers/ui_common.h"  // Assuming ui_common.h is where uiCommon is defined
#include <cstdlib>
#include <ctime>
#include <regex>

// Define the static methods in the UserController class

void UserController::Read(std::string& name,
                           std::string& email,
                           std::string& phone,
                           std::string& password,
                           std::string& confirmPassword,
                           std::string& carNumber,
                           std::string& carModel,
                           std::string& carType) {
    name = uiCommon.in.Str("Enter name:");

    do {
        email = uiCommon.in.Str("Enter email:");

        // Simulate 1/10 probability for "Email already exists"
        if (std::rand() % 10 == 0) {
            std::cout << "Email already exists. Please try again." << std::endl;
            continue;
        }

        std::regex emailRegex(R"(^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$)");
        if (std::regex_match(email, emailRegex)) {
            break;
        }
        std::cout << "Invalid email format. Please try again." << std::endl;
    } while (true);

    do {
        phone = uiCommon.in.Str("Enter phone number:");
        std::regex phoneRegex(R"(^\d{10}$)");
        if (std::regex_match(phone, phoneRegex)) {
            break;
        }
        std::cout << "Invalid phone number. It should be 10 digits." << std::endl;
    } while (true);

    do {
        password = uiCommon.in.Str("Enter password:");
        confirmPassword = uiCommon.in.Str("Confirm password:");
        if (password == confirmPassword) {
            break;
        }
        std::cout << "Passwords do not match. Please try again." << std::endl;
    } while (true);

    carNumber = uiCommon.in.Str("Enter car number:");
    carModel = uiCommon.in.Str("Enter car model:");
    carType = uiCommon.in.Str("Enter car type (e.g., SUV, Sedan):");
}

void UserController::DisplayAndEdit(std::string& name,
                                    std::string& email,
                                    std::string& phone,
                                    std::string& password,
                                    std::string& carNumber,
                                    std::string& carModel,
                                    std::string& carType) {
    int choice;
    do {
        // Display current details
        std::cout << "\nCurrent Details:" << std::endl;
        std::cout << "1 - Name: " << name << std::endl;
        std::cout << "2 - Email: " << email << std::endl;
        std::cout << "4 - Phone: " << phone << std::endl;
        std::cout << "8 - Password: " << password << std::endl;
        std::cout << "16 - Car Number: " << carNumber << std::endl;
        std::cout << "32 - Car Model: " << carModel << std::endl;
        std::cout << "64 - Car Type: " << carType << std::endl;
        std::cout << "\nEnter the sum of option numbers to edit (e.g., 3 to edit Name and Password):" << std::endl;

        choice = uiCommon.in.Int("Enter the combination of options you want to edit (or 0 to finish): ");

        if (choice == 0) {
            std::cout << "Finished editing details." << std::endl;
            break;
        }

        // Process the options using bitwise operations
        if (choice & 1) { // Check if Name is selected (1)
            name = uiCommon.in.Str("Enter new name:");
        }
        if (choice & 2) { // Check if Email is selected (2)
            email = uiCommon.in.Str("Enter new email:");
        }
        if (choice & 4) { // Check if Phone is selected (4)
            phone = uiCommon.in.Str("Enter new phone number:");
        }
        if (choice & 8) { // Check if Password is selected (8)
            password = uiCommon.in.Str("Enter new password:");
        }
        if (choice & 16) { // Check if Car Number is selected (16)
            carNumber = uiCommon.in.Str("Enter new car number:");
        }
        if (choice & 32) { // Check if Car Model is selected (32)
            carModel = uiCommon.in.Str("Enter new car model:");
        }
        if (choice & 64) { // Check if Car Type is selected (64)
            carType = uiCommon.in.Str("Enter new car type (e.g., SUV, Sedan):");
        }

    } while (choice != 0);
}

void UserController::Create() {
    uiCommon.TitleBar("User Registration");

    std::string name, email, phone, password, confirmPassword, carNumber, carModel, carType;

    // Read user details
    Read(name, email, phone, password, confirmPassword, carNumber, carModel, carType);

    // Display and allow editing of details
    DisplayAndEdit(name, email, phone, password, carNumber, carModel, carType);

    // Save the user details (logic for saving can be implemented here)
    std::cout << "\nUser is registered successfully with the following details:" << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Email: " << email << std::endl;
    std::cout << "Phone: " << phone << std::endl;
    std::cout << "Car Number: " << carNumber << std::endl;
    std::cout << "Car Model: " << carModel << std::endl;
    std::cout << "Car Type: " << carType << std::endl;

    uiCommon.PressAnyKey(true);
}
void ManageUser() {
    std::srand(std::time(nullptr)); // Seed the random number generator
    UserController controller;
    controller.Create(); // Directly invoke the Create function for user registration
}