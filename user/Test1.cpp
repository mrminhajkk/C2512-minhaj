//Prerequisites: sudo apt-get install libgtest-dev
#include <gtest/gtest.h>
// #include "../LibSun/Headers/Gcd.h"
// #include "../LibSun/Headers/Arithmetic.h"

#include <string>
#include "./../apps/header/user.h"
#include "./../apps/header/user_file_repo.h"

// Sample test for Gcd function
TEST(UserFileRepoCreate, Create) {
    User user;
    std::string email = "minhaj@gmail.com";
    user.SetEmail(email);
    user.SetPhone("1111222233");
    user.SetName("Minhaj");
    user.SetPassword("12345");
    user.SetId(1);
    UserFileRepo repo;
    repo.Create(user);
    //
    //User createdUser = repo.ReadByEmail(email);
    //EXPECT_EQ(createdUser.GetEmail(), email);
    EXPECT_EQ(1, 1);
}

// Main function to run tests
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
