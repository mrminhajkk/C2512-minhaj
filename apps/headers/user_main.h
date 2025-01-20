#ifndef USER_MAIN_H
#define USER_MAIN_H

#include <string>
#include <iostream>
#include <regex>

class UserController {
public:
    // Function to read user data
    static void Read(std::string& name,
                     std::string& email,
                     std::string& phone,
                     std::string& password,
                     std::string& confirmPassword,
                     std::string& carNumber,
                     std::string& carModel,
                     std::string& carType);

    // Function to display and edit user data
    static void DisplayAndEdit(std::string& name,
                                std::string& email,
                                std::string& phone,
                                std::string& password,
                                std::string& carNumber,
                                std::string& carModel,
                                std::string& carType);

    // Function to create a user (handles registration)
    void Create();
};

#endif // USER_MAIN_H
void ManageUser();