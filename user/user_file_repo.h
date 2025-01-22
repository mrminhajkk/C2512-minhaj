#pragma once
#include "iuser_repo.h"
#include "user.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <stdexcept>
#include <string>

class UserFileRepo : public IUserRepo {
private:
    std::string repo_file_name = "user.dat";

    void CreateFile_() { 
        std::ofstream output(repo_file_name, std::ios::binary | std::ios::app);
        output.close();
    }

    int GetLastId_() {
        CreateFile_(); //create file if not exists

        std::fstream file(repo_file_name, std::ios::binary | std::ios::in);
        if (!file) {
            throw std::runtime_error("Failed to open file for reading.");
        }

        // Get the size of the file
        file.seekg(0, std::ios::end);
        size_t fileSize = file.tellg();

        // Check if the file is empty
        if (fileSize == 0) {
            file.close();
            return 0; // No records exist
        }

        // Calculate the position of the last record
        size_t lastRecordPos = fileSize - sizeof(FileUser);

        // Seek to the last record
        file.seekg(lastRecordPos, std::ios::beg);

        // Read the last record
        FileUser fileUser;
        file.read((char*)&fileUser, sizeof(FileUser));

        file.close();
        return fileUser.id;
    }

public:
    void Create(User& entity) { 
        int lastId = GetLastId_();
        std::ofstream output(repo_file_name, std::ios::binary | std::ios::app);
        if (!output) {
            throw std::runtime_error("Failed to open file for writing.");
        }

        FileUser fileAccount = UserConverter::ConvertUserToFileUser(entity);
        fileAccount.id = lastId + 1; // new Id
        output.write((char*)&fileAccount, sizeof(fileAccount));
        output.close();
    }

    User ReadByEmail(std::string email) {
        CreateFile_(); //create file if not exists

        std::ifstream input(repo_file_name, std::ios::binary);
        if (!input) {
            throw std::runtime_error("Failed to open file for reading.");
        }

        FileUser fileUser;

        while (input.read((char*)&fileUser, sizeof(FileUser))) {
            if (strcmp(fileUser.email, email.c_str()) == 0) {
                input.close();
                return UserConverter::ConvertFileUserToUser(fileUser);
            }
        }

        input.close();
        throw std::runtime_error("User with given email not found.");
    }

    // std::vector<User> ReadAll() {
    //     CreateFile_(); //create file if not exists
        
    //     std::vector<User> users;

    //     std::ifstream file(repo_file_name, std::ios::binary);
    //     if (!file) {
    //         throw std::runtime_error("Failed to open file for reading.");
    //     }

    //     FileUser fileUser;

    //     while (file.read((char*)&fileUser, sizeof(FileUser))) {
    //         auto&& user = UserConverter::ConvertFileUserToUser(fileUser);
    //         users.push_back(user);
    //     }

    //     file.close();
    //     return users;
    // }
};
