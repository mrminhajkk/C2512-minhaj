#pragma once
#include <vector>
#include<string>
#include "user.h"



class IUserRepo {       
    public: 
         virtual void Create(User& user) = 0;
         virtual User ReadByEmail(std::string email) = 0;
         virtual ~IUserRepo() { }
};
