#pragma once
#include <string>
#include <cstring>

class User {
    private:
        int id;
        std::string name;
        std::string email;
        std::string phone;
        std::string password;
    public: // getters | setters 
        void SetId(int id) { this->id = id; }
        int GetId() { return this->id; }
        void SetName(std::string name) { this->name = name; }
        std::string GetName() { return this->name; }
        void SetEmail(std::string email) { this->email = email; }
        std::string GetEmail() { return this->email; }
        void SetPhone(std::string phone) { this->phone = phone; }
        std::string GetPhone() { return this->phone; }
        void SetPassword(std::string password) { this->password = password; }
        std::string GetPassword() { return this->password; }
};

class FileUser {
    public: 
        int id;
        char name[255];
        char email[255];
        char phone[255];
        char password[255];
};

class UserConverter { 
    public: 
        static FileUser ConvertUserToFileUser(User& user) {
            FileUser fileUser;
            fileUser.id = user.GetId();
            strcpy(fileUser.name, user.GetName().c_str());
            strcpy(fileUser.email, user.GetEmail().c_str());
            strcpy(fileUser.phone, user.GetPhone().c_str());
            strcpy(fileUser.password, user.GetPassword().c_str());
            return fileUser;
        }

        static User ConvertFileUserToUser(FileUser& fileUser) {
            User user;
            user.SetId(fileUser.id);
            user.SetName(fileUser.name);
            user.SetEmail(fileUser.email);
            user.SetPhone(fileUser.phone);
            user.SetPassword(fileUser.password);
            return user;
        }
};
