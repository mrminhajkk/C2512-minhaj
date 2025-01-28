//single source file app...
#include <string>
#include <cstring>

class User {
    private:
        int id;
        short role;
        std::string name;
        std::string email;
        std::string phone;
        std::string password;
        std::string created_at;
        std::string modified_at;
    public: // getters | setters 
       void SetId(int id) { this->id = id; }
        int GetId()const { return this->id; }
        void SetRole(int role) { this->role = role; }
        int GetRole()const { return this->role; }
        void SetName(std::string name) { this->name = name; }
        std::string GetName() const{ return this->name; }
        void SetEmail(std::string email) { this->email = email; }
        std::string GetEmail() const{ return this->email; }
        void SetPhone(std::string phone) { this->phone = phone; }
        std::string GetPhone() const{ return this->phone; }
        void SetPassword(std::string password) { this->password = password; }
        std::string GetPassword() const { return this->password; }
        void SetCreatedAt(std::string created_at) { this->created_at = created_at; }
        std::string GetCreatedAt() const { return this->created_at; }
        void SetModifiedAt(std::string modified_at) { this->modified_at = modified_at; }
        std::string GetModifiedAt() const { return this->modified_at; }
};

class FileUser {
    public: 
        short role;
        int id;
        char name[255];
        char email[255];
        char phone[255];
        char password[255];
        char created_at[255];
        char modified_at[255];
};

class UserConverter { 
    public: 
        static FileUser ConvertUserToFileUser(User& user) {
            FileUser fileUser;
            fileUser.role = user.GetRole();
            fileUser.id = user.GetId();
            strcpy(fileUser.name, user.GetName().c_str());
            strcpy(fileUser.email, user.GetEmail().c_str());
            strcpy(fileUser.phone, user.GetPhone().c_str());
            strcpy(fileUser.password, user.GetPassword().c_str());
            strcpy(fileUser.created_at, user.GetCreatedAt().c_str());
            strcpy(fileUser.modified_at, user.GetModifiedAt().c_str());
            return fileUser;
        }

        static User ConvertFileUserToUser(FileUser& fileUser) {
            User user;
            user.SetRole(fileUser.role);
            user.SetId(fileUser.id);
            user.SetName(fileUser.name);
            user.SetEmail(fileUser.email);
            user.SetPhone(fileUser.phone);
            user.SetPassword(fileUser.password);
            user.SetCreatedAt(fileUser.created_at);
            user.SetModifiedAt(fileUser.modified_at);
            return user;
        }
};

class Login {
    private:
        std::string email;
        std::string password;
    public: // getters | setters 
        void SetEmail(std::string email) { this->email = email; }
        std::string GetEmail() { return this->email; }
        void SetPassword(std::string password) { this->password = password; }
        std::string GetPassword() { return this->password; }
};

#include <string>
#include <cstring>

class Car {
    private:
        int id;
        int userId;
        std::string carNumber;
        std::string carModel;
        int carType;
        std::string created_at;
    public: // getters | setters 
        void SetId(int id) { this->id = id; }
        int GetId() { return this->id; }
        void SetUserId(int userId) { this->userId = userId; }
        int GetUserId() { return this->userId; }
        void SetCarNumber(std::string carNumber) { this->carNumber = carNumber; }
        std::string GetCarNumber() const { return this->carNumber; }
        void SetCarModel(std::string carModel) { this->carModel = carModel; }
        std::string GetCarModel() const { return this->carModel; }
        void SetCarType(int carType) { this->carType = carType; }
        int GetCarType() { return this->carType; }
        void SetCreatedAt(std::string created_at) { this->created_at = created_at; }
        std::string GetCreatedAt() const { return this->created_at; }
};

class FileCar {
    public: 
        int id;
        int userId;
        char carNumber[255];
        char carModel[255];
        int carType;
        char created_at[255];
};

class CarConverter { 
    public: 
        static FileCar ConvertCarToFileCar(Car& car) {
            FileCar fileCar;
            fileCar.id = car.GetId();
            fileCar.userId = car.GetUserId();
            strcpy(fileCar.carNumber, car.GetCarNumber().c_str());
            strcpy(fileCar.carModel, car.GetCarModel().c_str());
            fileCar.carType = car.GetCarType();
            strcpy(fileCar.created_at, car.GetCreatedAt().c_str());
            return fileCar;
        }

        static Car ConvertFileCarToCar(FileCar& fileCar) {
            Car car;
            car.SetId(fileCar.id);
            car.SetUserId(fileCar.userId);
            car.SetCarNumber(fileCar.carNumber);
            car.SetCarModel(fileCar.carModel);
            car.SetCarType(fileCar.carType);
            car.SetCreatedAt(fileCar.created_at);
            return car;
        }
};

// class Login {
//     private:
//         std::string email;
//         std::string password;
//     public: // getters | setters 
//         void SetEmail(std::string email) { this->email = email; }
//         std::string GetEmail() { return this->email; }
//         void SetPassword(std::string password) { this->password = password; }
//         std::string GetPassword() { return this->password; }
// };
#include <cstring>
#include <string>

class Floor {
    private:
        int floorId;
        std::string floorNumber;
    public: // getters | setters 
        void SetFloorId(int id) { this->floorId = id; }
        int GetFloorId() { return this->floorId; }
        void SetFloorNumber(const std::string& number) { this->floorNumber = number; }
        std::string GetFloorNumber() const { return this->floorNumber; }
};

class FileFloor {
    public: 
        int floorId;
        char floorNumber[255];
};

class FloorConverter { 
    public: 
        static FileFloor ConvertFloorToFileFloor(Floor& floor) {
            FileFloor fileFloor;
            //fileFloor.id = floor.GetId();
            strcpy(fileFloor.floorNumber, floor.GetFloorNumber().c_str());
            return fileFloor;
        }
        static Floor ConvertFileFloorToFloor(FileFloor& fileFloor) {
            Floor floor;
            floor.SetFloorId(fileFloor.floorId);
            floor.SetFloorNumber(fileFloor.floorNumber);
            return floor;
        }
};
#include <cstring>
#include <string>
#include <ctime>


class Spot {
    private:
        int spotId;
        int available = 1;
        std::string floorNumber;
        std::string spotNumber;
        std::string created_at;
        std::string modified_at;
    public: // getters | setters 
        void SetSpotId(int id) { this->spotId = id; }
        int GetSpotId() { return this->spotId; }
        void SetFloorNumber(const std::string& number) { this->floorNumber = number; }
        std::string GetFloorNumber() const { return this->floorNumber; }
        void SetSpotNumber(const std::string& number) { this->spotNumber = number; }
        std::string GetSpotNumber() const { return this->spotNumber; }
        void SetAvailability(int isAvailable) { available = isAvailable; }
        int IsAvailable() const { return available; }

        void SetCreatedAt(std::string createdAt) { this->created_at = createdAt; }
        std::string GetCreatedAt() const { return created_at; }

        void SetModifiedAt(std::string modifiedAt) { this->modified_at = modifiedAt; }
        std::string GetModifiedAt() const { return modified_at; }
};

class FileSpot {
    public: 
        int spotId;
        char floorNumber[255];
        char spotNumber[255];
        int available;
};

class SpotConverter { 
    public: 
        static FileSpot ConvertSpotToFileSpot(Spot& spot) {
            FileSpot fileSpot;
            fileSpot.spotId = spot.GetSpotId();
            strcpy(fileSpot.floorNumber, spot.GetFloorNumber().c_str());
            strcpy(fileSpot.spotNumber, spot.GetSpotNumber().c_str());
            return fileSpot;
        }
        static Spot ConvertFileSpotToSpot(FileSpot& fileSpot) {
            Spot spot;
            spot.SetSpotId(fileSpot.spotId);
            spot.SetFloorNumber(fileSpot.floorNumber);
            spot.SetSpotNumber(fileSpot.spotNumber);
            return spot;
        }
};

#include <string>
#include <cstring>

class Reservation {
private:
    int id;
    int carId;
    std::string start_time;
    std::string end_time;
    std::string booking_number;
    int driverId;
    int spotId;
    double amount;
    std::string created_at;
    std::string modified_at;

public:
    void SetReservationId(int id) { this->id = id; }
    int GetReservationId() const { return this->id; }

    void SetCarId(int carId) { this->carId = carId; }
    int GetCarId() const { return this->carId; }

    void SetStartTime(const std::string& start_time) { this->start_time = start_time; }
    std::string GetStartTime() const { return this->start_time; }

    void SetEndTime(const std::string& end_time) { this->end_time = end_time; }
    std::string GetEndTime() const { return this->end_time; }

    void SetBookingNumber(const std::string& booking_number) { this->booking_number = booking_number; }
    std::string GetBookingNumber() const { return this->booking_number; }

    void SetSpotId(const int& spotId) { this->spotId = spotId; }
    int GetSpotId() const { return this->spotId; }

    void SetDriverId(const int& driverId) { this->driverId = driverId; }
    int GetDriverId() const { return this->driverId; }

    void SetAmount(double amount) { this->amount = amount; }
    double GetAmount() const { return this->amount; }

    void SetCreatedAt(std::string created_at) { this->created_at = created_at; }
    std::string GetCreatedAt() const { return this->created_at; }

    void SetModifiedAt(std::string modified_at) { this->modified_at = modified_at; }
    std::string GetModifiedAt() const { return this->modified_at; }
};

class FileReservation {
public:
    int id;
    int carId;
    char Start_time[30];
    char end_time[30];
    char booking_number[30];
    int spotId;
    int driverId;
    double amount;
    char created_at[255];
    char modified_at[255];

};

class ReservationConverter {
public:
    static FileReservation ConvertReservationToFileReservation(Reservation& reservation) {
        FileReservation fileReservation;
        fileReservation.id = reservation.GetReservationId();
        fileReservation.carId =  reservation.GetCarId();
        std::strcpy(fileReservation.Start_time, reservation.GetStartTime().c_str());
        std::strcpy(fileReservation.end_time, reservation.GetEndTime().c_str());
        std::strcpy(fileReservation.booking_number, reservation.GetBookingNumber().c_str());
        fileReservation.spotId= reservation.GetSpotId();
        fileReservation.driverId=reservation.GetDriverId();
        fileReservation.amount = reservation.GetAmount();
        std::strcpy(fileReservation.created_at, reservation.GetCreatedAt().c_str());
        std::strcpy(fileReservation.modified_at, reservation.GetModifiedAt().c_str());
        return fileReservation;
    }

    static Reservation ConvertFileReservationToReservation(const FileReservation& fileReservation) {
        Reservation reservation;
        reservation.SetReservationId(fileReservation.id);
        reservation.SetCarId(fileReservation.carId);
        reservation.SetStartTime(fileReservation.Start_time);
        reservation.SetEndTime(fileReservation.end_time);
        reservation.SetBookingNumber(fileReservation.booking_number);
        reservation.SetSpotId(fileReservation.spotId);
        reservation.SetDriverId(fileReservation.driverId);
        reservation.SetAmount(fileReservation.amount);
        reservation.SetCreatedAt(fileReservation.created_at);
        reservation.SetModifiedAt(fileReservation.modified_at);

        return reservation;
    }
};

#define CLRSCR_METHOD 2 // 1 - ANSI Escape Codes 2- system "clear"

#include <termios.h>
#include <unistd.h>

#include<iostream>
#include<limits>
#include <ctime>
#include <iomanip>

#include<string>


class UiCommon {
    public:
        void Clear() {  
#if CLRSCR_METHOD == 1
            std::cout << "\033[2J\033[1;1H"; 
#else 
            system("clear");
#endif
        }
        void Line(char ch) {
            for(int I =0; I < 80; I++) {
                std::cout << ch;
            }
            std::cout << std::endl;
        }
        void Title(std::string title) {
            std::cout << title << std::endl;
        }
        void TitleBar(std::string title, char lineCh='-') {
            Clear();
            Line(lineCh);
            Title(title);
            Line(lineCh);
        }
        void PressAnyKey(bool beforeNumber = false) {
            std::cout << "Press any key to continue..."; 
            std::cin.get();
            if(beforeNumber) {
                std::cin.get();
            }
        }

        class Input {
            public:
                Input() {
                    srand(static_cast<unsigned>(time(0)));
                }
                std::string Str(std::string caption = "") {
                    std::cout << caption;

                    std::string str;
                    std::cin >> str;
                    return str;
                }
                int Int(std::string caption = "") {
                    std::string str = this->Str(caption);
                    try {
                        // Convert to int
                        int intValue = std::stoi(str);
                        return intValue;
                    } catch (const std::invalid_argument& e) {
                        std::cerr << "Invalid Number" << std::endl;
                        return this->Int(caption);
                    }
                }
                float Float(std::string caption = "") {
                    std::string str = this->Str(caption);
                    try {
                        // Convert to int
                        int intValue = std::stof(str);
                        return intValue;
                    } catch (const std::invalid_argument& e) {
                        std::cerr << "Invalid Number" << std::endl;
                        return this->Float(caption);
                    }
                }
                double Double(std::string caption = "") {
                    std::string str = this->Str(caption);
                    try {
                        // Convert to int
                        int intValue = std::stod(str);
                        return intValue;
                    } catch (const std::invalid_argument& e) {
                        std::cerr << "Invalid Number" << std::endl;
                        return this->Double(caption);
                    }
                }
                int giveMeNumber(int start, int end)
                {	
                    const int MAX_SIZE = end - start + 1;
                    int num = rand() % MAX_SIZE;
                    num += start;
                    return num;
                }
                bool exist() {
                    int num = giveMeNumber(1,10);
                    return (num == 1);
                }

                std::string GetCurrentTime() {
                std::time_t now = std::time(nullptr);
                std::tm* localTime = std::localtime(&now);

                // Format the time as "YYYY-MM-DD HH:MM:SS"
                std::ostringstream oss;
                oss << (1900 + localTime->tm_year) << "-"
                    << std::setw(2) << std::setfill('0') << (localTime->tm_mon + 1) << "-"
                    << std::setw(2) << std::setfill('0') << localTime->tm_mday << " "
                    << std::setw(2) << std::setfill('0') << localTime->tm_hour << ":"
                    << std::setw(2) << std::setfill('0') << localTime->tm_min;
                    //<< std::setw(2) << std::setfill('0') << localTime->tm_sec;

                return oss.str();
                } 

                std::string GetCurrentDate() {
                std::time_t now = std::time(nullptr);
                std::tm* localTime = std::localtime(&now);

                // Format the date as "YYYY-MM-DD"
                std::ostringstream oss;
                oss << (1900 + localTime->tm_year) << "-"
                    << std::setw(2) << std::setfill('0') << (localTime->tm_mon + 1) << "-"
                    << std::setw(2) << std::setfill('0') << localTime->tm_mday;

                return oss.str();
            }
        };

        Input in;
};

extern UiCommon uiCommon;
void AdminPage();
void ManageAdmin();

#include <memory>
#include <iostream>

class AppController {
    private: 
        AppUi view;
        std::unique_ptr<IUserRepo> repo;
    public: 
    //AppController() : repo(new UserFileRepo()) { } 
        void RegisterDriver() {
            uiCommon.TitleBar("Driver Registration");

            User newUser;
            view.RegisterDriver(newUser); 
            // repo->Create(newUser);
            std::cout << "User created successfully." << std::endl;
            uiCommon.PressAnyKey(true);
        }

    std::unordered_map<std::string, std::string> userCredentials = {
            {"admin", "admin123"}, // Admin credentials
            {"user", "user123"}    // User credentials
        };

        // Function to validate login credentials
    short ValidateLogin(const std::string& name, const std::string& password) {
            auto it = userCredentials.find(name);
            if (it != userCredentials.end() && it->second == password) {
                return name == "admin" ? 1 : 2;
            }
            return 0;
        }

        void DoLogin(){
            Login login;
            view.DoLogin(login);
            User user;
                 //user.SetRole(ValidateLogin(login.GetEmail(), login.GetPassword()));
            try {
                std::cout << "Three" << std::endl;
                uiCommon.PressAnyKey();
                
                user = repo->ReadByEmail(login.GetEmail());
                
                std::cout << "Four" << std::endl;
                uiCommon.PressAnyKey();
                
                if (user.GetRole() == 1) {
                    std::cout << "Login successful! Redirecting to Admin Dashboard..." << std::endl;
                    AdminPage("Minhaj");
                } else if (user.GetRole() == 2) {
                    std::cout << "Login successful! Redirecting to User Dashboard..." << std::endl;
                    ManageDriver();
                } else {
                    std::cout << "Invalid credentials. Please try again." << std::endl;
                }
            }catch(...) {
                std::cout << "Invalid credentials. Please try again." << std::endl;
            }
                // if (user.GetRole() == 1) {
                //     std::cout << "Login successful! Redirecting to Admin Dashboard..." << std::endl;
                //     AdminPage("Minhaj");
                // } else if (user.GetRole() == 2) {
                //     std::cout << "Login successful! Redirecting to User Dashboard..." << std::endl;
                //     ManageDriver();
                // } else {
                //     std::cout << "Invalid credentials. Please try again." << std::endl;
                // }

                uiCommon.PressAnyKey(true);
        }
        // void DisplayOne();
        // void DisplayAll();

        AppController(std::unique_ptr<IUserRepo> repo) : repo(std::move(repo)) { 
            
            std::cout << "Two" << &*this->repo << std::endl;
            uiCommon.PressAnyKey();
        }
};

#include <iostream>
#include <fstream>
#include <vector>
#include <stdexcept>
#include <string>

class CarFileRepo {
private:
    std::string repo_file_name = "car.dat";
    std::string repo_text_file_name = "car.txt";

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
        size_t lastRecordPos = fileSize - sizeof(FileCar);

        // Seek to the last record
        file.seekg(lastRecordPos, std::ios::beg);

        // Read the last record
        FileCar fileCar;
        file.read((char*)&fileCar, sizeof(FileCar));

        file.close();
        return fileCar.id;
    }

public:
    void Create(Car& entity) { 
        int lastId = GetLastId_();
        std::ofstream output(repo_file_name, std::ios::binary | std::ios::app);
        if (!output) {
            throw std::runtime_error("Failed to open file for writing.");
        }

        FileCar fileCar = CarConverter::ConvertCarToFileCar(entity);
        fileCar.id = lastId + 1; // new Id
        output.write((char*)&fileCar, sizeof(fileCar));
        output.close();
    }

    Car ReadByCarNumber(std::string carNumber) {
        std::cout << "Searching car by number..." << std::endl;
        CreateFile_(); //create file if not exists
        
        std::ifstream input(repo_file_name, std::ios::binary);
        if (!input) {
            throw std::runtime_error("Failed to open file for reading.");
        }

        FileCar fileCar;
       
        while (input.read((char*)&fileCar, sizeof(FileCar))) {
            if (strcmp(fileCar.carNumber, carNumber.c_str()) == 0) {
                input.close();
                return CarConverter::ConvertFileCarToCar(fileCar);
            }
        }

        input.close();
        throw std::runtime_error("Car with the given car number not found.");
        }

        Car ReadByUserId(int userId) {
        std::cout << "Searching car by number..." << std::endl;
        CreateFile_(); //create file if not exists
        
        std::ifstream input(repo_file_name, std::ios::binary);
        if (!input) {
            throw std::runtime_error("Failed to open file for reading.");
        }

        FileCar fileCar;
       
        while (input.read((char*)&fileCar, sizeof(FileCar))) {
            if(userId == fileCar.userId) {
                input.close();
                return CarConverter::ConvertFileCarToCar(fileCar);
            }
        }

        input.close();
        throw std::runtime_error("Car with the given car number not found.");
        }

    void MonitorDb() {
    CreateFile_(); //create file if not exists
    
    std::vector<Car> cars;

    std::ifstream input(repo_file_name, std::ios::binary);
    std::ofstream output(repo_text_file_name, std::ios::trunc);
    if (!input) {
        throw std::runtime_error("Failed to open file for reading.");
    }
    if (!output) {
        throw std::runtime_error("Failed to open file for writing or creating file.");
    }

    FileCar fileCar;
std::cout <<"Car details" <<std::endl;
    while (input.read((char*)&fileCar, sizeof(FileCar))) {
        output << fileCar.carNumber << "," 
               << fileCar.carModel << "," 
               << fileCar.carType << "," 
               << std::endl; 
        
        std::cout << fileCar.carNumber << "," 
               << fileCar.carModel << "," 
               << fileCar.carType << "," 
               << std::endl; 
              
    }      std::cout <<std::endl;  

    input.close();
    output.close();
}

    std::vector<Car> ReadAll() {
        CreateFile_(); //create file if not exists
        
        std::vector<Car> cars;

        std::ifstream file(repo_file_name, std::ios::binary);
        if (!file) {
            throw std::runtime_error("Failed to open file for reading.");
        }

        FileCar fileCar;

        while (file.read((char*)&fileCar, sizeof(FileCar))) {
            auto&& car = CarConverter::ConvertFileCarToCar(fileCar);
            cars.push_back(car);
        }

        file.close();
        return cars;
    }
};

// #include "ifloor_repo.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <stdexcept>
#include <string>

class FloorFileRepo { //: public IFloorRepo {
private:
    std::string repo_file_name = "floor.dat";
    std::string repo_text_file_name = "floor.txt";

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
        size_t lastRecordPos = fileSize - sizeof(FileFloor);

        // Seek to the last record
        file.seekg(lastRecordPos, std::ios::beg);

        // Read the last record
        FileFloor fileFloor;
        file.read((char*)&fileFloor, sizeof(fileFloor));

        file.close();
        return fileFloor.floorId;
    }

public:
    void Create(Floor& entity) { 
        int lastId = GetLastId_();
        std::ofstream output(repo_file_name, std::ios::binary | std::ios::app);
        if (!output) {
            throw std::runtime_error("Failed to open file for writing.");
        }

        FileFloor fileAccount = FloorConverter::ConvertFloorToFileFloor(entity);
        fileAccount.floorId = lastId + 1; // new Id
        output.write((char*)&fileAccount, sizeof(fileAccount));
        output.close();
    }

    Floor ReadByNumber(std::string floorNumber) {
        CreateFile_(); //create file if not exists

        std::ifstream input(repo_file_name, std::ios::binary);
        if (!input) {
            throw std::runtime_error("Failed to open file for reading.");
        }

        FileFloor fileFloor;

        while (input.read((char*)&fileFloor, sizeof(FileFloor))) {
            if (strcmp(fileFloor.floorNumber, floorNumber.c_str()) == 0) {
                input.close();
                return FloorConverter::ConvertFileFloorToFloor(fileFloor);
            }
        }

        input.close();
        throw std::runtime_error("Floor with given floor number not found.");
    }


void UpdateByNumber(const std::string& oldNumber, const std::string& newNumber) {
    CreateFile_(); // Ensure the file exists

    // Open the file for reading
    std::ifstream input(repo_file_name, std::ios::binary);
    if (!input) {
        throw std::runtime_error("Failed to open file for reading.");
    }

    std::vector<FileFloor> floors;
    FileFloor fileFloor;
    bool updated = false;

    // Read all floors into memory and identify the one to update
    while (input.read((char*)&fileFloor, sizeof(FileFloor))) {
        if (strcmp(fileFloor.floorNumber, oldNumber.c_str()) == 0) {
            // Update the floor number
            strncpy(fileFloor.floorNumber, newNumber.c_str(), sizeof(fileFloor.floorNumber) - 1);
            fileFloor.floorNumber[sizeof(fileFloor.floorNumber) - 1] = '\0'; // Null-terminate
            updated = true;
        }
        floors.push_back(fileFloor);
    }
    input.close();

    if (!updated) {
        throw std::runtime_error("Floor with number '" + oldNumber + "' not found.");
    }

    // Open the file for writing (truncate mode)
    std::ofstream output(repo_file_name, std::ios::binary | std::ios::trunc);
    if (!output) {
        throw std::runtime_error("Failed to open file for writing.");
    }

    // Write all floors back to the file
    for (const auto& floor : floors) {
        output.write((char*)&floor, sizeof(FileFloor));
    }
    output.close();

    std::cout << "Floor number updated successfully from '" << oldNumber << "' to '" << newNumber << "'." << std::endl;
}



    void DeleteByNumber(std::string number) {
    CreateFile_(); // Ensure file exists

    std::ifstream input(repo_file_name, std::ios::binary);
    if (!input) {
        throw std::runtime_error("Failed to open file for reading.");
    }

    std::vector<FileFloor> floors;
    FileFloor fileFloor;
    bool found = false;

    // Read all floors except the one to be deleted
    while (input.read((char*)&fileFloor, sizeof(FileFloor))) {
        if (strcmp(fileFloor.floorNumber, number.c_str()) != 0) {
            floors.push_back(fileFloor);
        } else {
            found = true;
        }
    }
    input.close();

    if (!found) {
        throw std::runtime_error("Floor with given floor number not found.");
    }

    // Write updated list back to the file
    std::ofstream output(repo_file_name, std::ios::binary | std::ios::trunc);
    if (!output) {
        throw std::runtime_error("Failed to open file for writing.");
    }

    for (const auto& floor : floors) {
        output.write((char*)&floor, sizeof(FileFloor));
    }
    output.close();
}

std::vector<Floor> ReadAll() {
    CreateFile_(); // Ensure file exists

    std::ifstream input(repo_file_name, std::ios::binary);
    if (!input) {
        throw std::runtime_error("Failed to open file for reading.");
    }

    std::vector<Floor> floors;
    FileFloor fileFloor;

    // Read all records from the file
    while (input.read((char*)&fileFloor, sizeof(FileFloor))) {
        floors.push_back(FloorConverter::ConvertFileFloorToFloor(fileFloor));
    }
    input.close();

    return floors;
}

    void MonitorDb() {
    CreateFile_(); //create file if not exists
    
    std::vector<Floor> floors;

    std::ifstream input(repo_file_name, std::ios::binary);
    std::ofstream output(repo_text_file_name, std::ios::trunc);
    if (!input) {
        throw std::runtime_error("Failed to open file for reading.");
    }
    if (!output) {
        throw std::runtime_error("Failed to open file for writing or creating file.");
    }

    FileFloor fileFloor;
std::cout <<"Floor details" <<std::endl;
    while (input.read((char*)&fileFloor, sizeof(FileFloor))) {
        output << fileFloor.floorNumber << "," 
               << std::endl; 
        std::cout << fileFloor.floorNumber << "," 
               << std::endl; 
               
    }   std::cout <<std::endl;    

    input.close();
    output.close();
}

bool ExistsByNumber(const std::string& floorNumber) {
    CreateFile_(); // Ensure the file exists

    std::ifstream input(repo_file_name, std::ios::binary);
    if (!input) {
        throw std::runtime_error("Failed to open file for reading.");
    }

    FileFloor fileFloor;

    // Iterate through the file to check if the floor number exists
    while (input.read((char*)&fileFloor, sizeof(FileFloor))) {
        if (strcmp(fileFloor.floorNumber, floorNumber.c_str()) == 0) {
            input.close();
            return true; // Floor exists
        }
    }

    input.close();
    return false; // Floor not found
}

};
#include <vector>
#include <string>
#include <fstream>
#include <stdexcept>
#include <iostream>

class ReservationFileRepo {
private:
    std::string repo_file_name = "reservation.dat";
    std::string repo_text_file_name = "reservation.txt";

    void CreateFile_() {
        std::ofstream output(repo_file_name, std::ios::binary | std::ios::app);
        output.close();
    }

    int GetLastId_() {
        CreateFile_();
        std::fstream file(repo_file_name, std::ios::binary | std::ios::in);
        if (!file) {
            throw std::runtime_error("Failed to open file for reading.");
        }

        file.seekg(0, std::ios::end);
        size_t fileSize = file.tellg();

        if (fileSize == 0) {
            file.close();
            return 0;
        }

        size_t lastRecordPos = fileSize - sizeof(FileReservation);
        file.seekg(lastRecordPos, std::ios::beg);

        FileReservation fileReservation;
        file.read(reinterpret_cast<char*>(&fileReservation), sizeof(FileReservation));

        file.close();
        return fileReservation.id;
    }

public:
    void Create(Reservation& entity) {
        int lastId = GetLastId_();
        std::ofstream output(repo_file_name, std::ios::binary | std::ios::app);
        if (!output) {
            throw std::runtime_error("Failed to open file for writing.");
        }

        FileReservation fileReservation = ReservationConverter::ConvertReservationToFileReservation(entity);
        fileReservation.id = lastId + 1;
        output.write(reinterpret_cast<char*>(&fileReservation), sizeof(fileReservation));
        output.close();
    }

    void displayall() {
        CreateFile_();
        std::ifstream input(repo_file_name, std::ios::binary);
        std::ofstream output(repo_text_file_name, std::ios::trunc);
        if (!input) {
            throw std::runtime_error("Failed to open file for reading.");
        }
        if (!output) {
            throw std::runtime_error("Failed to open file for writing.");
        }

        FileReservation fileReservation;
        while (input.read(reinterpret_cast<char*>(&fileReservation), sizeof(FileReservation))) {
            output << fileReservation.id << ","
                   << fileReservation.carId << ","
                   << fileReservation.Start_time << ","
                   << fileReservation.end_time << ","
                   << fileReservation.booking_number << ","
                   << fileReservation.spotId << ","
                   << fileReservation.driverId << ","
                   << fileReservation.created_at << ","
                   << fileReservation.modified_at << ","
                   << fileReservation.amount << "\n";
        }

        input.close();
        output.close();
    }

    Reservation ReadByNumber(const std::string& reservationNumber) {
        CreateFile_();
        std::ifstream input(repo_file_name, std::ios::binary);
        if (!input) {
            throw std::runtime_error("Failed to open file for reading.");
        }

        FileReservation fileReservation;
        while (input.read(reinterpret_cast<char*>(&fileReservation), sizeof(FileReservation))) {
            if (reservationNumber == fileReservation.booking_number) {
                input.close();
                return ReservationConverter::ConvertFileReservationToReservation(fileReservation);
            }
        }

        input.close();
        throw std::runtime_error("Reservation with given booking number not found.");
    }
};



// #include "ifloor_repo.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <stdexcept>
#include <string>

class SpotFileRepo { //: public IFloorRepo {
private:
    std::string repo_file_name = "spot.dat";
    std::string repo_text_file_name = "spot.txt";

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
        size_t lastRecordPos = fileSize - sizeof(FileSpot);

        // Seek to the last record
        file.seekg(lastRecordPos, std::ios::beg);

        // Read the last record
        FileSpot fileSPot;
        file.read((char*)&fileSPot, sizeof(fileSPot));

        file.close();
        return fileSPot.spotId;
    }

public:
    void Create(Spot& entity) { 
        int lastId = GetLastId_();
        std::ofstream output(repo_file_name, std::ios::binary | std::ios::app);
        if (!output) {
            throw std::runtime_error("Failed to open file for writing.");
        }

        FileSpot fileAccount = SpotConverter::ConvertSpotToFileSpot(entity);
        fileAccount.spotId = lastId + 1; // new Id
        output.write((char*)&fileAccount, sizeof(fileAccount));
        output.close();
    }

    Spot ReadByNumber(std::string spotNumber) {
        CreateFile_(); //create file if not exists

        std::ifstream input(repo_file_name, std::ios::binary);
        if (!input) {
            throw std::runtime_error("Failed to open file for reading.");
        }

        FileSpot fileSpot;

        while (input.read((char*)&fileSpot, sizeof(FileSpot))) {
            if (strcmp(fileSpot.spotNumber, spotNumber.c_str()) == 0) {
                input.close();
                return SpotConverter::ConvertFileSpotToSpot(fileSpot);
            }
        }

        input.close();
        throw std::runtime_error("Floor with given spot id not found.");
    }


void DeleteByNumber(std::string spotNumber) {
    CreateFile_(); // Ensure file exists

    std::ifstream input(repo_file_name, std::ios::binary);
    if (!input) {
        throw std::runtime_error("Failed to open file for reading.");
    }

    std::vector<FileSpot> spots;
    FileSpot fileSpot;
    bool found = false;

    // Read all spots except the one to be deleted
    while (input.read((char*)&fileSpot, sizeof(FileSpot))) {
        if (strcmp(fileSpot.spotNumber, spotNumber.c_str()) != 0) {
            spots.push_back(fileSpot);
        } else {
            found = true;
        }
    }
    input.close();

    if (!found) {
        throw std::runtime_error("Floor with given floor number not found.");
    }

    // Write updated list back to the file
    std::ofstream output(repo_file_name, std::ios::binary | std::ios::trunc);
    if (!output) {
        throw std::runtime_error("Failed to open file for writing.");
    }

    for (const auto& spot : spots) {
        output.write((char*)&spot, sizeof(FileSpot));
    }
    output.close();
}



std::vector<Spot> ReadAll() {
    CreateFile_(); // Ensure file exists

    std::ifstream input(repo_file_name, std::ios::binary);
    if (!input) {
        throw std::runtime_error("Failed to open file for reading.");
    }

    std::vector<Spot> spots;
    FileSpot fileSpot;

    // Read all records from the file
    while (input.read((char*)&fileSpot, sizeof(FileSpot))) {
        spots.push_back(SpotConverter::ConvertFileSpotToSpot(fileSpot));
    }
    input.close();

    return spots;
}

void UpdateByNumber(const std::string& oldSpotNumber, const std::string& newSpotNumber) {
    CreateFile_(); // Ensure the file exists

    std::ifstream input(repo_file_name, std::ios::binary);
    if (!input) {
        throw std::runtime_error("Failed to open file for reading.");
    }

    std::vector<Spot> spots;
    FileSpot fileSpot;
    bool found = false;

    // Read all spots and modify the matching one
    while (input.read((char*)&fileSpot, sizeof(FileSpot))) {
        Spot spot = SpotConverter::ConvertFileSpotToSpot(fileSpot);
        if (spot.GetSpotNumber() == oldSpotNumber) {
            spot.SetSpotNumber(newSpotNumber);
            found = true;
        }
        spots.push_back(spot);
    }
    input.close();

    if (!found) {
        throw std::runtime_error("Spot with ID '" + oldSpotNumber + "' not found.");
    }

    // Write updated spots back to the file
    std::ofstream output(repo_file_name, std::ios::binary | std::ios::trunc);
    if (!output) {
        throw std::runtime_error("Failed to open file for writing.");
    }

    for (auto& spot : spots) {
        FileSpot fileSpot = SpotConverter::ConvertSpotToFileSpot(spot);
        output.write((char*)&fileSpot, sizeof(FileSpot));
    }
    output.close();
}

void MonitorDb() {
    CreateFile_(); //create file if not exists
    
    std::vector<Spot> spots;

    std::ifstream input(repo_file_name, std::ios::binary);
    std::ofstream output(repo_text_file_name, std::ios::trunc);
    if (!input) {
        throw std::runtime_error("Failed to open file for reading.");
    }
    if (!output) {
        throw std::runtime_error("Failed to open file for writing or creating file.");
    }

    FileSpot fileSpot;
std::cout <<"Spot details" <<std::endl;
    while (input.read((char*)&fileSpot, sizeof(FileSpot))) {
        output << fileSpot.floorNumber << "," 
               << fileSpot.spotId << "," 
               << std::endl; 
        std::cout << fileSpot.floorNumber << "," 
               << fileSpot.spotId << "," 
               << std::endl; 
    }       std::cout <<std::endl;

    input.close();
    output.close();
}

std::vector<Spot> ReadByFloorNumber(const std::string& floorNumber) {
    CreateFile_(); // Ensure the file exists

    std::ifstream input(repo_file_name, std::ios::binary);
    if (!input) {
        throw std::runtime_error("Failed to open file for reading.");
    }

    std::vector<Spot> spots;
    FileSpot fileSpot;

    // Read all spots and filter by floor number
    while (input.read((char*)&fileSpot, sizeof(FileSpot))) {
        if (strcmp(fileSpot.floorNumber, floorNumber.c_str()) == 0) {
            spots.push_back(SpotConverter::ConvertFileSpotToSpot(fileSpot));
        }
    }

    input.close();
    return spots;
}

    
};

#define CLRSCR_METHOD 2 // 1 - ANSI Escape Codes 2- system "clear"

#include <iostream>
#include <fstream>
#include <vector>
#include <stdexcept>
#include <string>

class UserFileRepo  {
private:
    std::string repo_file_name = "user.dat";
    std::string repo_text_file_name = "user.txt";

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

    std::vector<User> ReadAll() {
        CreateFile_(); //create file if not exists
        
        std::vector<User> users;

        std::ifstream file(repo_file_name, std::ios::binary);
        if (!file) {
            throw std::runtime_error("Failed to open file for reading.");
        }

        FileUser fileUser;

        while (file.read((char*)&fileUser, sizeof(FileUser))) {
            auto&& user = UserConverter::ConvertFileUserToUser(fileUser);
            users.push_back(user);
        }

        file.close();
        return users;
    }

    void MonitorDb() {
    CreateFile_(); //create file if not exists
    
    std::vector<User> users;

    std::ifstream input(repo_file_name, std::ios::binary);
    std::ofstream output(repo_text_file_name, std::ios::trunc);
    if (!input) {
        throw std::runtime_error("Failed to open file for reading.");
    }
    if (!output) {
        throw std::runtime_error("Failed to open file for writing or creating file.");
    }

    FileUser fileUser;
std::cout <<"User details" <<std::endl;
    while (input.read((char*)&fileUser, sizeof(FileUser))) {
        output << fileUser.role << "," 
               << fileUser.id << "," 
               << fileUser.name << "," 
               << fileUser.email << "," 
               << fileUser.phone << "," 
               << fileUser.password << std::endl;
        
        std::cout << fileUser.role << "," 
               << fileUser.id << "," 
               << fileUser.name << "," 
               << fileUser.email << "," 
               << fileUser.phone << "," 
               << fileUser.password << std::endl; 
        
    }   std::cout <<std::endl;    

    input.close();
    output.close();
}

void DeleteByEmail(const std::string& email) {
        CreateFile_(); // Ensure the file exists

        std::ifstream input(repo_file_name, std::ios::binary);
        if (!input) {
            throw std::runtime_error("Failed to open file for reading.");
        }

        std::vector<FileUser> remainingUsers;
        FileUser fileUser;

        bool found = false;

        // Read all users, except the one to delete
        while (input.read((char*)&fileUser, sizeof(FileUser))) {
            if (strcmp(fileUser.email, email.c_str()) == 0) {
                found = true; // Mark as found but skip adding to remaining users
            } else {
                remainingUsers.push_back(fileUser);
            }
        }

        input.close();

        if (!found) {
            throw std::runtime_error("User with the given email not found.");
        }

        // Rewrite the file with remaining users
        std::ofstream output(repo_file_name, std::ios::binary | std::ios::trunc);
        if (!output) {
            throw std::runtime_error("Failed to open file for writing.");
        }

        for (const auto& user : remainingUsers) {
            output.write((char*)&user, sizeof(FileUser));
        }

        output.close();
    }


void Update(User& updatedUser) {
    CreateFile_(); // Ensure the file exists

    std::ifstream input(repo_file_name, std::ios::binary);
    if (!input) {
        throw std::runtime_error("Failed to open file for reading.");
    }

    std::vector<FileUser> users;
    FileUser fileUser;
    bool updated = false;

    // Read all users and update the matching one
    while (input.read((char*)&fileUser, sizeof(FileUser))) {
        if (fileUser.id == updatedUser.GetId()) { // Match by ID
            fileUser = UserConverter::ConvertUserToFileUser(updatedUser); // Update record
            updated = true;
        }
        users.push_back(fileUser);
    }

    input.close();

    if (!updated) {
        throw std::runtime_error("User with the given ID not found.");
    }

    // Rewrite the file with updated users
    std::ofstream output(repo_file_name, std::ios::binary | std::ios::trunc);
    if (!output) {
        throw std::runtime_error("Failed to open file for writing.");
    }

    for (const auto& user : users) {
        output.write((char*)&user, sizeof(FileUser));
    }

    output.close();
}


};



void ManageDriver();

void ManageFloor();
#ifndef RESERVATION_MAIN_H
#define RESERVATION_MAIN_H

#include <string>

class ParkingSystem {
    ReservationFileRepo reservationrepo;

public:
    void reserveParkingSpot();
    void viewBookings();
};

#endif

void ManageSpot();
// #ifndef USER_MAIN_H
// #define USER_MAIN_H
extern std::string email;
// #include <string>
// #include <iostream>
// #include <regex>
// #include"./../header/user.h"
// #include"./../header/user_file_repo.h"
#ifndef USER_CONTROLLER_H
#define USER_CONTROLLER_H

#include<iostream>
#include<sstream>
#include<string>

class UserController {
    UserFileRepo userRepo;
    CarFileRepo carRepo;
public:
    // User Registration Method
    void UCreate();
    
    // Display all users for editing
    void DisplayAll();
    
    // Edit functionality placeholder (if needed)
    void Edit();
    
    // Delete functionality placeholder (if needed)
    void Delete();
    void UserPage();
    void EditPassword();
    void DisplayLoggedInUserProfile();

// Function to manage user-specific actions (calls relevant controller methods)
void ManageUser();
    static int ReadUserMenu();
};

// Menu function for user management options


// Function to handle user-specific actions (view profile, reservations, etc.)




#endif // USER_CONTROLLER_H

// // USER_MAIN_H
// void ManageUser();
// void UserPage();

void AppMain();
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <cstdlib>


class AppUi {
public:
        void Read(std::string& name, std::string& password, std::string& email, std::string& phone, int flags = 15) {
        if((flags & 1) != 0) {
            std::cout << "Name:"; std::cin >> name;
        }
        if((flags & 2) != 0) {
            std::cout << "Password:"; std::cin >> password;
        }
        if((flags & 4) != 0) {
            std::cout << "Email:"; std::cin >> email;
        }
        if((flags & 8) != 0) {
            std::cout << "Phone Number:"; std::cin >> phone;
        }
    }

    void RegisterDriver(User& user) {
        std::string name, password, email, phone;
        int flags = 15;
        do {
            Read(name, password, email, phone, flags);
            int proceedOption; 
            
            std::cout << "1 - edit `name`." << std::endl; 
            std::cout << "2 - edit `password`." << std::endl; 
            std::cout << "3 - edit `email`." << std::endl; 
            std::cout << "4 - edit `phone number`." << std::endl; 
            std::cout << "5 - I am sure to create." << std::endl;
            std::cout << "\tYour choice:"; std::cin >> proceedOption;

            if(5 == proceedOption) {
                user.SetName(name);
                user.SetPassword(password);
                user.SetEmail(email);
                user.SetPhone(phone);
                break;
            }
            flags = 1 << (proceedOption - 1);
        } while(true);
    }
        // Simulated user data

    void DoLogin(Login& login){
                std::string name, password;

                uiCommon.TitleBar("Login");
                std::cout << "Enter UserName(Email): ";
                std::cin >> name;
                std::cout << "Enter Password: ";
                std::cin >> password;
                login.SetEmail(name);
                login.SetPassword(password);
    }
    
    



};

void ManageApps() {
    AppMain();
}

int main() {
    ManageApps();
    return 0;
}


#include<iostream>
#include<sstream>
#include<string>
#include <iomanip> // For std::setw and std::left

class AdminController { 
    UserFileRepo userRepo;
    public:
        void Create() {
            uiCommon.TitleBar("Admin App > Admin Management > Create admin");
            std::string name;
            std::string email;
            std::string password;
            std::string phone;
            int role = 1; 
            
            // do {
                name = uiCommon.in.Str("Enter name:");
                email = uiCommon.in.Str("Enter email:");
                password = uiCommon.in.Str("Enter password:");
                phone = uiCommon.in.Str("Enter phone:");
                role = 1; // 1 - admin
      
                // int proceedOption; 

                // std::stringstream soutput; 
                // soutput << "1 - edit `name`." << std::endl; 
                // soutput << "2 - edit `email`." << std::endl; 
                // soutput << "4 - edit `password`." << std::endl; 
                // soutput << "8 - edit `phone`." << std::endl; 
                // soutput << "3 - edit `phone` and `email`." << std::endl; 
                // soutput << "91 - Proceed to create admin." << std::endl;
                // soutput << "\tYour choice:"; 
                // proceedOption = uiCommon.in.Int(soutput.str());

                // if(91 == proceedOption) {
                //     //set to biz object
                //     break;
            //     // }
            //     flags = proceedOption;
            // } while(true);
            try{
                User newuser;
                newuser.SetName(name);
                newuser.SetEmail(email);
                newuser.SetPassword(password);
                newuser.SetPhone(phone);
                newuser.SetRole(role);
                userRepo.Create(newuser);
            } catch (const std::exception& e){
                std::cout << "Error: " << e.what()  << std::endl;
            }
            std::cout << "Admin is created successfully." << std::endl;
            uiCommon.PressAnyKey(true);        
        }

void Delete()
    {
        uiCommon.TitleBar("Admin App > Admin Management > Delete Admin");
        std::string email = uiCommon.in.Str("Enter the email of the admin to delete:");

        try
        {
            userRepo.DeleteByEmail(email); // Assuming DeleteByEmail is implemented
            std::cout << "Admin deleted successfully." << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cout << "Error: " << e.what() << std::endl;
        }

        uiCommon.PressAnyKey(true);
    }


  void Edit()
{
    uiCommon.TitleBar("Admin App > Admin Management > Edit Admin");

    std::string email = uiCommon.in.Str("Enter the email of the admin to edit:");
    try
    {
        User adminToEdit = userRepo.ReadByEmail(email); // Retrieve admin by email

        std::cout << "Editing admin details:" << std::endl;
        std::cout << "Current details:" << std::endl;
        std::cout << "Name: " << adminToEdit.GetName() << std::endl;
        std::cout << "Email: " << adminToEdit.GetEmail() << std::endl;
        std::cout << "Phone: " << adminToEdit.GetPhone() << std::endl;
        std::cout << "Role: " << (adminToEdit.GetRole() == 1 ? "Admin" : "User") << std::endl;

        std::string newName = uiCommon.in.Str("Enter new name (press Enter to keep the current):");
        if (!newName.empty())
            adminToEdit.SetName(newName);

        std::string newEmail = uiCommon.in.Str("Enter new email (press Enter to keep the current):");
        if (!newEmail.empty())
            adminToEdit.SetEmail(newEmail);

        std::string newPhone = uiCommon.in.Str("Enter new phone (press Enter to keep the current):");
        if (!newPhone.empty())
            adminToEdit.SetPhone(newPhone);

        std::string newRole = uiCommon.in.Str("Enter new role (1 for Admin, 0 for User, or press Enter to keep the current):");
        if (!newRole.empty())
            adminToEdit.SetRole(std::stoi(newRole));

        userRepo.Update(adminToEdit); // Save updated details
        std::cout << "Admin details updated successfully!" << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    uiCommon.PressAnyKey(true);
}




      void EditPassword()
{
    uiCommon.TitleBar("Admin App > Admin Management > Edit Admin Password");

    std::string email = uiCommon.in.Str("Enter the email of the admin to update the password:");
    try
    {
        User adminToEdit = userRepo.ReadByEmail(email); // Retrieve admin by email

        std::cout << "Editing password for admin:" << std::endl;
        std::cout << "Name: " << adminToEdit.GetName() << std::endl;
        std::cout << "Email: " << adminToEdit.GetEmail() << std::endl;

        std::string newPassword = uiCommon.in.Str("Enter new password:");
        if (!newPassword.empty())
        {
            adminToEdit.SetPassword(newPassword);
            userRepo.Update(adminToEdit); // Save updated password
            std::cout << "Password updated successfully!" << std::endl;
        }
        else
        {
            std::cout << "Password cannot be empty!" << std::endl;
        }
    }
    catch (const std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    uiCommon.PressAnyKey(true);
}
        // void Edit() {
        //     uiCommon.TitleBar("Admin App > Admin Management > Edit Admin");
        //     uiCommon.PressAnyKey(true); 
        // }

//         void  Edit() {
//     uiCommon.TitleBar("Admin App > Admin Management > Edit Admin");

//     // Step 1: Ask the admin to enter the unique identifier (e.g., email) of the admin to edit
//     std::string email = uiCommon.in.Str("Enter the email of the admin to edit:");

//     try {
//         // Step 2: Retrieve the admin by email (or another unique identifier)
//         User adminToEdit = userRepo.ReadByEmail(email); // Assuming ReadByEmail() is a method in UserFileRepo

//         // Step 3: Display the current details of the admin
//         std::cout << "Editing admin details:" << std::endl;
//         std::cout << "Current details:" << std::endl;
//         std::cout << "Name: " << adminToEdit.GetName() << std::endl;
//         std::cout << "Email: " << adminToEdit.GetEmail() << std::endl;
//         std::cout << "Phone: " << adminToEdit.GetPhone() << std::endl;
//         std::cout << "Role: " << (adminToEdit.GetRole() == 0 ? "Admin" : "User") << std::endl;

//         // Step 4: Allow the user to update each field
//         std::string newName = uiCommon.in.Str("Enter new name (or press Enter to keep the current one):");
//         if (!newName.empty()) adminToEdit.SetName(newName);

//         std::string newPhone = uiCommon.in.Str("Enter new phone (or press Enter to keep the current one):");
//         if (!newPhone.empty()) adminToEdit.SetPhone(newPhone);

//         std::string newPassword = uiCommon.in.Str("Enter new password (or press Enter to keep the current one):");
//         if (!newPassword.empty()) adminToEdit.SetPassword(newPassword);

//         // The role can be changed as well, but make sure to handle it carefully (perhaps restrict to admin only)
//         std::string newRole = uiCommon.in.Str("Enter new role (0 for Admin, 1 for User, or press Enter to keep the current one):");
//         if (!newRole.empty()) adminToEdit.SetRole(std::stoi(newRole)); // Assuming role is stored as an integer (0 or 1)

//         // Step 5: Save the updated admin details back to the repository
//         userRepo.Update(adminToEdit); // Assuming there's an Update() method to update an existing admin

//         std::cout << "Admin details updated successfully!" << std::endl;

//     } catch (const std::exception& e) {
//         std::cout << "Error: " << e.what() << std::endl;
//     }

//     uiCommon.PressAnyKey(true); // Optional: Press any key to return
// }


        // void Delete() {
        //     uiCommon.TitleBar("Admin App > Admin Management > Delete Admin");
        //     uiCommon.PressAnyKey(true); 
        // }

        void DisplayAll() {
            uiCommon.TitleBar("Admin App > Admin Management > List of Logins");
            try {



                auto admins = userRepo.ReadAll();
        if (!admins.empty()) {
            std::cout << "List of Admins:" << std::endl;

            // Set up the table header
            std::cout << std::left << std::setw(20) << "Name"
                      << std::setw(30) << "Email"
                      << std::setw(15) << "Phone"
                      << std::setw(10) << "Role"
                      << std::endl;

            // Output a line separator
            std::cout << std::setw(20) << std::setfill('-') << "" 
                      << std::setw(30) << "" 
                      << std::setw(15) << "" 
                      << std::setw(10) << "" 
                      << std::setfill(' ') << std::endl;

            // Loop through each admin and display their details
            for (const auto& admin : admins) {
                std::cout << std::left << std::setw(20) << admin.GetName()
                          << std::setw(30) << admin.GetEmail()
                          << std::setw(15) << admin.GetPhone()
                          << std::setw(10) << (admin.GetRole() == 1 ? "Admin" : "User")
                          << std::endl;
            }
        
            // auto admins = userRepo.ReadAll();
            // if (!admins.empty()) {
            //     std::cout << "List of Admins:" << std::endl;
            //     for (const auto& admin : admins) {
            //         std::cout << "- " << admin.GetName()<< "- " << admin.GetPassword() << "- "<< admin.GetPhone() << "- "<< admin.GetEmail() << "- " <<admin.GetRole()<< std::endl;
            //     }
            } else {
                std::cout << "No admin available." << std::endl;
            }
        } catch (const std::exception& e) {
            std::cout << "Error: " << e.what() << std::endl;
        }           
            uiCommon.PressAnyKey(true); 
        }
};









static int ReadAdminMenu() {
    int choice;
    
    uiCommon.TitleBar("Admin App > Admin Management");

    std::stringstream soutput;
    soutput << "1 - Create Admin" << std::endl;
    soutput << "2 - Edit Admin" << std::endl;
    soutput << "3 - Delete Admin" << std::endl;
    soutput << "4 - Display All Logins" << std::endl;
    soutput << "5 - Change password" << std::endl; 
    soutput << "99 - Exit" << std::endl;
    soutput << "Your choice:"; 
    choice = uiCommon.in.Int(soutput.str()); //std::cin >> choice;
    
    uiCommon.Line('~');
    uiCommon.PressAnyKey(true); 
    return choice;
}

void AdminPage() {
    uiCommon.TitleBar("Admin App ");
    int option;
    std::cout << "Welcome ! "<< std::endl;
    do {
        std::cout << "1 - Admins Management" << std::endl;
        std::cout << "2 - Floor Management" << std::endl;
        std::cout << "3 - Spot Management" << std::endl;
        std::cout << "4 - Bookings History" << std::endl;
        std::cout << "5 - Payments History" << std::endl;
        std::cout << "99 - Logout" << std::endl;
        std::cout << "Select an option: ";
        std::cin >> option;

        switch (option) {
            case 1:
                ManageAdmin();
                break;
            case 2:
                ManageFloor();
                break;
            case 3:
                ManageSpot();
                break;
            case 99:
                std::cout << "Logging out..." << std::endl;
                AppMain();
                break;
            default:
                std::cout << "Invalid option. Please try again." << std::endl;
        }
    } while (option != 99);
}

void ManageAdmin() { 
    AdminController controller;
    
    int choice;

    do { 
        choice = ReadAdminMenu();
        switch(choice) {
            case 99: {
                std::cout << std::endl;
                AdminPage();
            } break;
            case 1: {
                controller.Create();
            } break;
            case 2: {
                controller.Edit();
            } break;
            case 3: {
               controller.Delete();
            } break;
            case 4: {
                controller.DisplayAll();
            } break;
             case 5:
            {
                 controller.EditPassword();
             }
             break;
        }
    } while(99 != choice);
};














































//old
// #include<iostream>
// #include<sstream>
// #include<string>

// #include"./../header/admin_main.h"
// #include"./../header/app_main.h"
// #include"./../header/spot_main.h"
// #include"./../header/floor_main.h"
// #include"./../header/ui_common.h"
// #include"./../header/user.h"
// #include"./../header/user_file_repo.h"

// class AdminController { 
//     UserFileRepo userRepo;
//     public:
//         void Create() {
//             uiCommon.TitleBar("Admin App > Admin Management > Create admin");
//             std::string name;
//             std::string email;
//             std::string password;
//             std::string phone;
//             int role = 0; 
            
//             // do {
//                 name = uiCommon.in.Str("Enter name:");
//                 email = uiCommon.in.Str("Enter email:");
//                 password = uiCommon.in.Str("Enter password:");
//                 phone = uiCommon.in.Str("Enter phone:");
//                 role = 1; // 1 - admin
      
//                 // int proceedOption; 

//                 // std::stringstream soutput; 
//                 // soutput << "1 - edit `name`." << std::endl; 
//                 // soutput << "2 - edit `email`." << std::endl; 
//                 // soutput << "4 - edit `password`." << std::endl; 
//                 // soutput << "8 - edit `phone`." << std::endl; 
//                 // soutput << "3 - edit `phone` and `email`." << std::endl; 
//                 // soutput << "91 - Proceed to create admin." << std::endl;
//                 // soutput << "\tYour choice:"; 
//                 // proceedOption = uiCommon.in.Int(soutput.str());

//                 // if(91 == proceedOption) {
//                 //     //set to biz object
//                 //     break;
//             //     // }
//             //     flags = proceedOption;
//             // } while(true);
//             try{
//                 User newuser;
//                 newuser.SetName(name);
//                 newuser.SetEmail(email);
//                 newuser.SetPassword(password);
//                 newuser.SetPhone(phone);
//                 newuser.SetRole(role);
//                 userRepo.Create(newuser);
//             } catch (const std::exception& e){
//                 std::cout << "Error: " << e.what()  << std::endl;
//             }
//             std::cout << "Admin is created successfully." << std::endl;
//             uiCommon.PressAnyKey(true);        
//         }

//         // void Edit() {
//         //     uiCommon.TitleBar("Admin App > Admin Management > Edit Admin");
//         //     uiCommon.PressAnyKey(true); 
//         // }

//         // void Delete() {
//         //     uiCommon.TitleBar("Admin App > Admin Management > Delete Admin");
//         //     uiCommon.PressAnyKey(true); 
//         // }

//         void DisplayAll() {
//             uiCommon.TitleBar("Admin App > Admin Management > List of Admins");
//             try {
//             auto admins = userRepo.ReadAll();
//             if (!admins.empty()) {
//                 std::cout << "List of Admins:" << std::endl;
//                 for (const auto& admin : admins) {
//                     std::cout << "- " << admin.GetName()<< "- " << admin.GetPassword() << "- "<< admin.GetPhone() << "- "<< admin.GetEmail() << "- " << std::endl;
//                 }
//             } else {
//                 std::cout << "No admin available." << std::endl;
//             }
//         } catch (const std::exception& e) {
//             std::cout << "Error: " << e.what() << std::endl;
//         }           
//             uiCommon.PressAnyKey(true); 
//         }
// };

// static int ReadAdminMenu() {
//     int choice;
    
//     uiCommon.TitleBar("Admin App > Admin Management");

//     std::stringstream soutput;
//     soutput << "1 - Create Admin" << std::endl;
//     soutput << "2 - Edit Admin" << std::endl;
//     soutput << "3 - Delete Admin" << std::endl;
//     soutput << "4 - Display All Admins" << std::endl;
//     soutput << "99 - Exit" << std::endl;
//     soutput << "Your choice:"; 
//     choice = uiCommon.in.Int(soutput.str()); //std::cin >> choice;
    
//     uiCommon.Line('~');
//     uiCommon.PressAnyKey(true); 
//     return choice;
// }

// void AdminPage() {
//     uiCommon.TitleBar("Admin App ");
//     int option;
//     std::cout << "Welcome, " << "Minhaj" << "!" << std::endl;
//     do {
//         std::cout << "[1] Admins Management" << std::endl;
//         std::cout << "[2] Floor Management" << std::endl;
//         std::cout << "[3] Spot Management" << std::endl;
//         std::cout << "[4] Bookings History" << std::endl;
//         std::cout << "[5] Payments History" << std::endl;
//         std::cout << "[99] Logout" << std::endl;
//         std::cout << "Select an option: ";
//         std::cin >> option;

//         switch (option) {
//             case 1:
//                 ManageAdmin();
//                 break;
//             case 2:
//                 ManageFloor();
//                 break;
//             case 3:
//                 ManageSpot();
//                 break;
//             case 99:
//                 std::cout << "Logging out..." << std::endl;
//                 AppMain();
//                 break;
//             default:
//                 std::cout << "Invalid option. Please try again." << std::endl;
//         }
//     } while (option != 99);
// }

// void ManageAdmin() { 
//     AdminController controller;
    
//     int choice;

//     do { 
//         choice = ReadAdminMenu();
//         switch(choice) {
//             case 99: {
//                 std::cout << std::endl;
//                 AdminPage();
//             } break;
//             case 1: {
//                 controller.Create();
//             } break;
//             case 2: {
//                 //controller.Edit();
//             } break;
//             case 3: {
//                // controller.Delete();
//             } break;
//             case 4: {
//                 controller.DisplayAll();
//             } break;
//         }
//     } while(99 != choice);
// }
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>


void ManageDriver() {
    ParkingSystem ps;
    uiCommon.TitleBar("Driver Dashboard");

    std::string name = "John Doe", email = "john.doe@example.com", phone = "1234567890";
    std::string carNumber = "ABC123", carModel = "Toyota Camry", carType = "Sedan";

    std::cout << "Welcome " << name << "!" << std::endl;
    std::cout << "Your Car Details:" << std::endl;
    std::cout << "Car Number: " << carNumber << std::endl;
    std::cout << "Car Model: " << carModel << std::endl;
    std::cout << "Car Type: " << carType << std::endl;

    std::cout << "\nOptions:" << std::endl;
    std::cout << "[1] View/Edit Profile" << std::endl;
    std::cout << "[2] Do Reservation" << std::endl;
    std::cout << "[3] Pay and Unpark" << std::endl;
    std::cout << "[4] Change Password" << std::endl;
    std::cout << "[99] Logout" << std::endl;

    int choice;
    std::cin >> choice;

    if (choice == 1) {
         uiCommon.TitleBar("Driver Dashboard > View / Edit Profile");
        std::cout << "\nProfile Details:" << std::endl;
        std::cout << "Name: " << name << " {required}" << std::endl;
        std::cout << "Email: " << email << " {required, isEmail, isExist}" << std::endl;
        std::cout << "Phone: " << phone << " {required, 10-digits isPhoneNumber, isExist}" << std::endl;
        std::cout << "Car Number: " << carNumber << " {required, isExist}" << std::endl;
        std::cout << "Car Model: " << carModel << " {required}" << std::endl;
        std::cout << "Car Type: " << carType << " {selectable}" << std::endl;

        std::cout << "\nOptions:" << std::endl;
        std::cout << "1. Edit Field/Group of Fields" << std::endl;
        std::cout << "2. Confirm" << std::endl;
        std::cout << "3. Exit" << std::endl;

        int editChoice;
        std::cin >> editChoice;

        if (editChoice == 1) {
            std::cout << "Edited successfully" << std::endl;
            ManageDriver();
        } else if (editChoice == 2) {
            std::cout << "\nProfile updated successfully!" << std::endl;
            ManageDriver();
        } else {
            std::cout << "\nExiting..." << std::endl;
            ManageDriver();
        }
    } else if (choice == 2) {
         ps.reserveParkingSpot();
        std::cout << "Reservation done successfully!" << std::endl;
        ManageDriver();
    } else if (choice == 3) {
       // ps.unparkVehicle();
        std::cout << "Payment and unparked successfully!" << std::endl;
        ManageDriver();
    } else if (choice == 4) {
        std::cout << "Password changed successfully!" << std::endl;
        ManageDriver();
    } else if (choice == 99) {
        std::cout << "Logging out..." << std::endl;
        // Redirect to login page logic here
    }
}


#include<iostream>
#include<sstream>
#include<string>
#include<map>
#include<iomanip>



class FloorController {
    FloorFileRepo repo;
    SpotFileRepo spRepo;

public:
    void Create() {
        uiCommon.TitleBar("Admin App > Floor Management > Create floor");
         std::string floorNumber;
        std::cout << "Enter Floor Number: ";
        std::cin >> floorNumber;

        try {
            Floor newFloor;
            newFloor.SetFloorNumber(floorNumber);
            repo.Create(newFloor);
            std::cout << "Floor created successfully." << std::endl;
        } catch (const std::exception& e) {
            std::cout << "Error: " << e.what() << std::endl;
        }

        uiCommon.PressAnyKey(true);
    }

void Edit()
{
    uiCommon.TitleBar("Admin App > Floor Management > Edit Floor");

    // Prompt user for the floor number to edit
    std::string floorNumber = uiCommon.in.Str("Enter the floor number to edit:");
    try
    {
        // Retrieve the floor by its number
        Floor floorToEdit = repo.ReadByNumber(floorNumber);

        // Display current details of the floor
        std::cout << "Editing floor details:" << std::endl;
        std::cout << "Current Floor Number: " << floorToEdit.GetFloorNumber() << std::endl;

        // Prompt user for updated details
        std::string newFloorNumber = uiCommon.in.Str("Enter new floor number (press Enter to keep the current):");
        if (!newFloorNumber.empty())
            floorToEdit.SetFloorNumber(newFloorNumber);

        // Save updated floor details
        repo.UpdateByNumber(floorNumber, floorToEdit.GetFloorNumber());

        std::cout << "Floor details updated successfully!" << std::endl;
    }
    catch (const std::exception &e)
    {
        // Handle errors, such as floor not found
        std::cout << "Error: " << e.what() << std::endl;
    }

    // Pause for user to review changes
    uiCommon.PressAnyKey(true);
}



        void Delete() {
            uiCommon.TitleBar("Admin App > Floor Management > Delete floor");
            std::string floorNumber;
        std::cout << "Enter Floor Number to Delete: ";
        std::cin >> floorNumber;

        try {
            repo.DeleteByNumber(floorNumber);
            std::cout << "Floor deleted successfully." << std::endl;
        } catch (const std::exception& e) {
            std::cout << "Error: " << e.what() << std::endl;
        }
            uiCommon.PressAnyKey(true); 
        }

        void DisplayAll() {
            uiCommon.TitleBar("Admin App > Floor Management > List of floors");
            try {
            auto floors = repo.ReadAll();
            if (!floors.empty()) {
                std::cout << "List of Floors:" << std::endl;
                for (const auto& floor : floors) {
                    std::cout << "- " << floor.GetFloorNumber() << std::endl;
                }
            } else {
                std::cout << "No floors available." << std::endl;
            }
        } catch (const std::exception& e) {
            std::cout << "Error: " << e.what() << std::endl;
        }

            uiCommon.PressAnyKey(true); 
        }

        void DisplayByAvailability() {
            uiCommon.TitleBar("Admin App > Floor Management > List of Available Spots");
            try {
            auto spots = spRepo.ReadAll();
            if (!spots.empty()) {
                std::cout << "List of Available Spots:" << std::endl;
                for (const auto& spot : spots) {
                    std::cout << "- " << spot.GetSpotNumber() << std::endl;
                }
            } else {
                std::cout << "No spots available." << std::endl;
            }
        } catch (const std::exception& e) {
            std::cout << "Error: " << e.what() << std::endl;
        }

            uiCommon.PressAnyKey(true); 
        }
};

static int ReadFloorMenu() {
    int choice;
    
    uiCommon.TitleBar("Admin App > Floor Management");

    std::stringstream soutput;
    soutput << "1 - Create Floor" << std::endl;
    soutput << "2 - Edit Floor" << std::endl;
    soutput << "3 - Delete Floor" << std::endl;
    soutput << "4 - Display All Floors" << std::endl;
    soutput << "5 - Display Available Spots" << std::endl;
    soutput << "99 - Exit" << std::endl;
    soutput << "Your choice:"; 
    choice = uiCommon.in.Int(soutput.str()); //std::cin >> choice;
    
    uiCommon.Line('~');
    uiCommon.PressAnyKey(true); 
    return choice;
}

void ManageFloor() { 
    FloorController controller;
    
    int choice;

    do { 
        choice = ReadFloorMenu();
        switch(choice) {
            case 99: {
                std::cout << std::endl;
                AdminPage();
            } break;
            case 1: {
                controller.Create();
            } break;
            case 2: {
                controller.Edit();
            } break;
            case 3: {
                controller.Delete();
            } break;
            case 4: {
                controller.DisplayAll();
            } break;
            case 5: {
                controller.DisplayByAvailability();
            } break;
        }
    } while(99 != choice);
}
#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>
#include <sstream>
#include <optional>
#include <vector>
using namespace std;

std::string GetCurrentDateAndTime() {
    // Get the current time
    std::time_t now = std::time(nullptr);
    std::tm* localTime = std::localtime(&now);
 
    // Format the time as "YYYY-MM-DD HH:MM"
    std::ostringstream oss;
    oss << (1900 + localTime->tm_year) << "-"
        << std::setw(2) << std::setfill('0') << (localTime->tm_mon + 1) << "-"
        << std::setw(2) << std::setfill('0') << localTime->tm_mday << " "
        << std::setw(2) << std::setfill('0') << localTime->tm_hour << ":"
        << std::setw(2) << std::setfill('0') << localTime->tm_min;
 
    return oss.str();
}


UserController controller;

std::string NextBookingNumber(const std::tm& start_tm) {
    // Generate the booking number based on the date (YYYYMMDD format)
    std::ostringstream bookingStream;
    bookingStream << "B" 
                  << std::setw(4) << std::setfill('0') << (start_tm.tm_year + 1900)  // Year
                  << std::setw(2) << std::setfill('0') << (start_tm.tm_mon + 1)      // Month
                  << std::setw(2) << std::setfill('0') << start_tm.tm_mday;          // Day
    return bookingStream.str();
}

std::tm StrToTime(const std::string& timeStr) {
    std::tm value_tm = {};
    std::stringstream start_ss(timeStr);
    start_ss >> std::get_time(&value_tm, "%Y-%m-%d %H:%M");
    if (start_ss.fail()) {
        throw std::runtime_error("Invalid date-time format. Please use YYYY-MM-DD HH:MM.");
    }
    return value_tm;
}

double TimeDiffSec(const std::tm& start_tm, const std::tm& end_tm) {
    // Convert std::tm to time_t
    std::time_t start_time = std::mktime(const_cast<std::tm*>(&start_tm));
    std::time_t end_time = std::mktime(const_cast<std::tm*>(&end_tm));

    // Calculate the difference in seconds
    return std::difftime(end_time, start_time);
}

double TimeDiffHour(const std::tm& start_tm, const std::tm& end_tm) {
    return TimeDiffSec(start_tm, end_tm) / 3600.0;  // Convert seconds to hours
}

std::optional<Spot> AvailableSpot() {
    SpotFileRepo spotRepo;
    std::vector<Spot> spots = spotRepo.ReadAll();
    for (const auto& spot : spots) {
        if (spot.IsAvailable() == 1) {
            return spot;
        }
    }

    return std::nullopt;
}

void ParkingSystem::reserveParkingSpot() {
    User user;
    Car car;
    UserFileRepo userRepo;
    CarFileRepo carRepo;
    try {
        user = userRepo.ReadByEmail(email);      // owner of ReadByEmail: Minhaj/Vinayak
        car = carRepo.ReadByUserId(user.GetId()); // owner of ReadByUserId: Sana
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
        uiCommon.PressAnyKey(true);
        return;
    }

    uiCommon.TitleBar("Driver Dashboard > Do Reservation");
    std::cout << "\n1. Reserve Parking Spot:\n";
    std::cout << "Car Number: " << car.GetCarNumber() << std::endl;

    std::string startTime, endTime;
    std::cout << "Enter Start Time (YYYY-MM-DD HH:MM): ";
    std::getline(std::cin, startTime);
    std::cout << "Enter End Time (YYYY-MM-DD HH:MM): ";
    std::getline(std::cin, endTime);

    std::tm start_tm, end_tm;
    try {
        start_tm = StrToTime(startTime);
        end_tm = StrToTime(endTime);
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
        uiCommon.PressAnyKey(true);
        return;
    }

    double durationInHours = TimeDiffHour(start_tm, end_tm);
    double Amount = durationInHours * 10; // 10 rupees per hour
    std::string bookingNumber = NextBookingNumber(start_tm);

    std::cout << "Total Price: ₹ " << std::fixed << std::setprecision(2) << Amount << std::endl;
    char confirm;
    std::cout << "Confirm Booking (Y/N): ";
    std::cin >> confirm;

    if (confirm == 'Y' || confirm == 'y') {
        std::optional<Spot> optionalSpot = AvailableSpot();
        if (!optionalSpot.has_value()) {
            std::cout << "No spot is available for booking\n";
            uiCommon.PressAnyKey(true);
            return;
        }

        Spot spot = optionalSpot.value();
        SpotFileRepo spotRepo;
        try {
            Reservation newReservation;
            newReservation.SetDriverId(user.GetId());       // owner: Minhaj
            newReservation.SetCarId(car.GetId());           // owner: Minhaj
            newReservation.SetSpotId(spot.GetSpotId());         // owner: Sana
            newReservation.SetStartTime(startTime);
            newReservation.SetEndTime(endTime);
            newReservation.SetAmount(Amount);
            newReservation.SetBookingNumber(bookingNumber);
            newReservation.SetCreatedAt(GetCurrentDateAndTime()); //////// 

            

            reservationrepo.Create(newReservation);
           // spotRepo.UpdateAvailable(spot.GetSpotId(), 0);      // owner: Sana

            std::cout << "Reservation successful, spot number " << spot.GetSpotNumber() << " reserved." << std::endl;
            std::cout << "Generated Booking Number is " << bookingNumber << std::endl;
        } catch (const std::exception& e) {
            std::cout << "Error: " << e.what() << std::endl;
        }
        uiCommon.PressAnyKey(true);
    }
}

void ParkingSystem::viewBookings() {
    uiCommon.TitleBar("Driver Dashboard > View Bookings");

    try {
        std::string bookingNumber;
        std::cout << "Enter Booking Number: ";
        std::cin >> bookingNumber;

        // Retrieve the reservation by booking number
        Reservation reservation = reservationrepo.ReadByNumber(bookingNumber);

        // Display the booking details
        std::cout << "Booking Number: " << reservation.GetBookingNumber() << std::endl;
        //std::cout << "Car Number: " << reservation.GetCarNumber() << std::endl;
        //std::cout << "Spot Number: " << reservation.GetSpotId() << std::endl;
        std::cout << "Start Time: " << reservation.GetStartTime() << std::endl;
        std::cout << "End Time: " << reservation.GetEndTime() << std::endl;
        std::cout << "Amount: ₹ " << std::fixed << std::setprecision(2) << reservation.GetAmount() << std::endl;

    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    uiCommon.PressAnyKey(true);
}



#include<iostream>
#include<sstream>
#include<string>
#include<iomanip>
#include<map>
#include<ctime>




class SpotController {
    SpotFileRepo spotRepo;

    public:

        void Create() {
            uiCommon.TitleBar("Admin App > Spot Management > Create spot");
            std::string floorNumber;
            std::string spotNumber;
            //int spotId;
            // int available = 1;

            Floor floor;
            FloorFileRepo floorRepo;
            do {
                std::cout << "Enter Floor Number: ";
                std::cin >> floorNumber;
                
                try {
                    floor = floorRepo.ReadByNumber(floorNumber);
                    break;
                }catch (const std::exception& e) {
                    std::cout << "Error: " << e.what() << std::endl;
                    continue;
                }
            } while(true);

            std::cout << "Enter Spot Number: ";
            std::cin >> spotNumber;

            
            // Create and save the spot
            Spot newSpot;
            newSpot.SetFloorNumber(floor.GetFloorNumber());
            newSpot.SetSpotNumber(spotNumber);  // Correctly associate with the floor
            //newSpot.SetSpotId(spotId);       // Set spot ID
            newSpot.SetCreatedAt(uiCommon.in.GetCurrentTime()); // Set creation timestamp
            spotRepo.Create(newSpot);            // Save in the repository
            std::cout << "Spot created successfully." << std::endl;
           

            uiCommon.PressAnyKey(true);
        }

    void Edit() {
    uiCommon.TitleBar("Admin App > Spot Management > Edit Spot");
    Spot newSpot;
    // Prompt for the spot ID to edit
    std::string oldSpotNumber;
    std::cout << "Enter Spot Number to Edit (e.g., GR-R001): ";
    std::cin >> oldSpotNumber;

    try {
        // Retrieve the existing spot by ID
        Spot spotToEdit = spotRepo.ReadByNumber(oldSpotNumber);

        // Display current spot details
        std::cout << "Editing Spot Details:" << std::endl;
        std::cout << "Current Spot Number: " << spotToEdit.GetSpotNumber() << std::endl;
        std::cout << "Floor Number: " << spotToEdit.GetFloorNumber() << std::endl;

        // Prompt for a new spot ID
        std::string newSpotNumber;
        std::cout << "Enter New Spot Number (press Enter to keep current): ";
        std::cin.ignore(); // Clear input buffer
        std::getline(std::cin, newSpotNumber);

        // Update spot details if a new ID is provided
        if (!newSpotNumber.empty()) {
            spotToEdit.SetSpotNumber(newSpotNumber);
        }

        int newAvailability;
        //std::cout << "Enter Availability (1 for available, 0 for parked): ";
        std::cin >> newAvailability;
        spotToEdit.SetAvailability(newAvailability);

        // Save the updated spot to the repository
        spotRepo.UpdateByNumber(oldSpotNumber, spotToEdit.GetSpotNumber());
        newSpot.SetModifiedAt(uiCommon.in.GetCurrentTime()); 
        std::cout << "Spot updated successfully!" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    uiCommon.PressAnyKey(true);
}

void Delete() {
    uiCommon.TitleBar("Admin App > Spot Management > Delete Spot");
    std::string spotNumber;
    std::cout << "Enter Spot Number to Delete: ";
    std::cin >> spotNumber;

    try {
        spotRepo.DeleteByNumber(spotNumber);
        std::cout << "Spot deleted successfully." << std::endl;
        } 
        catch (const std::exception& e) {
            std::cout << "Error: " << e.what() << std::endl;
        }
        uiCommon.PressAnyKey(true); 
    }


void DisplayAll() {
    uiCommon.TitleBar("Admin App > Spot Management > List of Spots");

    try {
        auto spots = spotRepo.ReadAll();
        if (!spots.empty()) {
            std::cout << "Floor Number | Spot Number | Availability " << std::endl;
            std::cout << "------------------------------------------------------" << std::endl;

            for (const auto& spot : spots) {
                std::cout << spot.GetFloorNumber() << "        | "
                          << spot.GetSpotNumber() << "         | "
                          << (spot.IsAvailable() ? "Available" : "Parked") << "   | "
                           << std::endl;
            }
        } else {
            std::cout << "No spots available." << std::endl;
        }
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    uiCommon.PressAnyKey(true);
}

};

static int ReadSpotMenu() {
    int choice;

    uiCommon.TitleBar("Admin App > Spot Management");

    std::stringstream soutput;
    soutput << "1 - Create Spot" << std::endl;
    soutput << "2 - Edit Spot" << std::endl;
    soutput << "3 - Delete Spot" << std::endl;
    soutput << "4 - Display All Spots" << std::endl;
    soutput << "99 - Exit" << std::endl;
    soutput << "Your choice: ";
    choice = uiCommon.in.Int(soutput.str());

    uiCommon.Line('~');
    uiCommon.PressAnyKey(true);
    return choice;
}

void ManageSpot() {
    SpotController controller;

    int choice;
    do {
        choice = ReadSpotMenu();
        switch (choice) {
            case 99: {
                std::cout << std::endl;
                AdminPage();
            } break;
            case 1: {
                controller.Create();
            } break;
            case 2: {
                controller.Edit();
            } break;
            case 3: {
                controller.Delete();
            } break;
            case 4: {
                controller.DisplayAll();
            } break;
        }
    } while (99 != choice);
}
#include<iostream>
#include<sstream>
#include<string>



    void UserController::UCreate() {
            uiCommon.TitleBar("Driver Registration");
            std::string name;
            std::string email;
            std::string password;
            std::string phone;
            std::string carNumber;
            std::string carModel;
            int carType;
            
            name = uiCommon.in.Str("Enter name:");
            email = uiCommon.in.Str("Enter email:");
            password = uiCommon.in.Str("Enter password:");
            phone = uiCommon.in.Str("Enter phone:");
            carNumber = uiCommon.in.Str("Enter car number:");
            carModel = uiCommon.in.Str("Enter car model:");
            std::cout << "Select a car type:\n";
                std::cout << "1. SUV\n";
                std::cout << "2. Sedan\n";
                std::cout << "3. MUV\n";
                std::cout << "Enter your choice (1-3): ";

                std::cin >> carType;
        
            try {
                User newUser;
                newUser.SetName(name);
                newUser.SetEmail(email);
                newUser.SetPassword(password);
                newUser.SetPhone(phone);
                newUser.SetCreatedAt(uiCommon.in.GetCurrentTime());
                newUser.SetRole(0);
                Car newcar;
                newcar.SetCarNumber(carNumber);
                newcar.SetCarModel(carModel);
                newcar.SetCarType(carType);
                newcar.SetCreatedAt(uiCommon.in.GetCurrentTime());

                userRepo.Create(newUser);
                newcar.SetUserId(newUser.GetId());
                carRepo.Create(newcar);
                std::cout << "User is created successfully." << std::endl;
            } catch (const std::exception& e) {
                std::cout << "Error: " << e.what() << std::endl;
            }

            uiCommon.PressAnyKey(true);        
        }


            // std::string GetCurrentTime() {
            // // Get the current time
            // std::time_t now = std::time(nullptr);
            // std::tm* localTime = std::localtime(&now);

            // // Format the time as "YYYY-MM-DD HH:MM:SS"
            // std::ostringstream oss;
            // oss << (1900 + localTime->tm_year) << "-"
            //     << std::setw(2) << std::setfill('0') << (localTime->tm_mon + 1) << "-"
            //     << std::setw(2) << std::setfill('0') << localTime->tm_mday << " "
            //     << std::setw(2) << std::setfill('0') << localTime->tm_hour << ":"
            //     << std::setw(2) << std::setfill('0') << localTime->tm_min;
            //     //<< std::setw(2) << std::setfill('0') << localTime->tm_sec;

            // return oss.str();
            // } 

            // std::string GetCurrentDate() {
            // // Get the current time
            // std::time_t now = std::time(nullptr);
            // std::tm* localTime = std::localtime(&now);

            // // Format the date as "YYYY-MM-DD"
            // std::ostringstream oss;
            // oss << (1900 + localTime->tm_year) << "-"
            //     << std::setw(2) << std::setfill('0') << (localTime->tm_mon + 1) << "-"
            //     << std::setw(2) << std::setfill('0') << localTime->tm_mday;

            // return oss.str();
            // }

       void UserController::DisplayAll() {
        //     uiCommon.TitleBar("Driver App > View/Edit Profile");
        //     try {
        //         auto users = userRepo.ReadAll();
        //         auto cars = carRepo.ReadAll();
        //         if (!users.empty()) {
        //             std::cout << "List of Users:" << std::endl;
        //             for (const auto& user : users) {
        //                 std::cout << "- " << user.GetName() << "- " << user.GetPhone() << "- " << user.GetEmail();
        //             }


        //             // for (const auto& car : cars) {
        //             //     std::cout << "- " << car.GetCarNumber() << "- " << car.GetCarModel() << "- " << car.GetCarType() << std::endl;
        //             // }


        //         } else {
        //             std::cout << "No users available." << std::endl;
        //         }
        //     } catch (const std::exception& e) {
        //         std::cout << "Error: " << e.what() << std::endl;
        //     }

        //     // Ask the user to select the user to edit and provide options to edit all fields
        //     std::string userId;
        //     std::cout << "Enter the User ID you wish to edit: ";
        //     std::cin >> userId;
        //     // Get the selected user (you may need to adapt this depending on how you're storing users)
        //     User selectedUser = userRepo.ReadByEmail(userId); 

        //     // Allow the user to edit fields
        //     std::string newName = uiCommon.in.Str("Edit name (Leave empty to keep current):");
        //     std::string newEmail = uiCommon.in.Str("Edit email (Leave empty to keep current):");
        //     std::string newPassword = uiCommon.in.Str("Edit password (Leave empty to keep current):");
        //     std::string newPhone = uiCommon.in.Str("Edit phone (Leave empty to keep current):");

        //     if (!newName.empty()) selectedUser.SetName(newName);
        //     if (!newEmail.empty()) selectedUser.SetEmail(newEmail);
        //     if (!newPassword.empty()) selectedUser.SetPassword(newPassword);
        //     if (!newPhone.empty()) selectedUser.SetPhone(newPhone);

        //   //  userRepo.Update(selectedUser); // Assuming Update method exists in UserFileRepo
        //     std::cout << "Profile updated successfully." << std::endl;

        //     uiCommon.PressAnyKey(true); 
        }

   void UserController::DisplayLoggedInUserProfile() {
    uiCommon.TitleBar("Driver App > View Profile");
    UserController UC;

    try {
        // Assuming that the logged-in user's email is available from session or context
        std::string loggedInUserEmail = email; // Replace this with actual logged-in email

        // Fetch the user based on the email (assuming it's stored during login)
        User loggedInUser = userRepo.ReadByEmail(loggedInUserEmail);

        if (!loggedInUser.GetName().empty()) {
            // Display the details in a formatted and clean manner
            std::cout << "\n===== User Profile =====\n";
            std::cout << "Name      : " << loggedInUser.GetName() << std::endl;
            std::cout << "Phone     : " << loggedInUser.GetPhone() << std::endl;
            std::cout << "Email     : " << loggedInUser.GetEmail() << std::endl;

     
            char editChoice;
            std::cout << "\nWould you like to edit your profile? (y/n): ";
            std::cin >> editChoice;

            if (editChoice == 'y' || editChoice == 'Y') {
                std::cout << "\n===== Edit Your Profile =====\n";

                // Show current details and ask for new inputs
                std::string newName = uiCommon.in.Str("Current Name: " + loggedInUser.GetName() + "\nEdit name (Leave empty to keep current):");
                std::string newEmail = uiCommon.in.Str("Current Email: " + loggedInUser.GetEmail() + "\nEdit email (Leave empty to keep current):");
                std::string newPassword = uiCommon.in.Str("Edit password (Leave empty to keep current):");
                std::string newPhone = uiCommon.in.Str("Current Phone: " + loggedInUser.GetPhone() + "\nEdit phone (Leave empty to keep current):");
                email= newEmail;
                // Apply the changes only if the new values are provided
                if (!newName.empty()) loggedInUser.SetName(newName);
                if (!newEmail.empty()) loggedInUser.SetEmail(newEmail);  // Update email if entered
                if (!newPassword.empty()) loggedInUser.SetPassword(newPassword);
                if (!newPhone.empty()) loggedInUser.SetPhone(newPhone);

                // Update the user profile in the repository
                userRepo.Update(loggedInUser); // Assuming Update method exists
                std::cout << "\nProfile updated successfully.\n";
                UC.DisplayLoggedInUserProfile();
            } else {
                std::cout << "\nProfile not edited.\n";
                loggedInUser.SetModifiedAt(uiCommon.in.GetCurrentTime());
                    uiCommon.PressAnyKey(true);
                UC.UserPage();
            }

        } else {
            std::cout << "User not found or invalid email.\n";
        }
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    // After editing or skipping, return to the driver page
    uiCommon.PressAnyKey(true);
    // Assuming there is a function to return to the driver page
    
}

        void Edit() {
            // Implement the Edit functionality for users here if needed
        }

        void Delete() {
            // Implement the Delete functionality for users here if needed
        }


int UserController::ReadUserMenu() {
    int choice;
    
    uiCommon.TitleBar("User App > User Management");

    std::stringstream soutput;
    soutput << "1 - View/Edit Profile" << std::endl;
    soutput << "2 - Do Reservation" << std::endl;
    soutput << "3 - Pay and Unpark" << std::endl;
    soutput << "4 - Change Password" << std::endl;
    soutput << "99 - Exit" << std::endl;
    soutput << "Your choice:"; 
    choice = uiCommon.in.Int(soutput.str());
    
    uiCommon.Line('~');
    uiCommon.PressAnyKey(true); 
    return choice;
}

void UserController::EditPassword()
{
    uiCommon.TitleBar("Driver Page > Change Password");

    try
    {
        std::string loggedInUserEmail = email;
        User driverToEdit = userRepo.ReadByEmail(loggedInUserEmail);  // Retrieve current driver

        std::cout << "Editing password for driver:" << std::endl;
        std::cout << "Name: " << driverToEdit.GetName() << std::endl;
        std::cout << "Email: " << driverToEdit.GetEmail() << std::endl;

        std::string newPassword = uiCommon.in.Str("Enter new password:");
        if (!newPassword.empty())
        {
            driverToEdit.SetPassword(newPassword);
            userRepo.Update(driverToEdit); // Save updated password
            std::cout << "Password updated successfully!" << std::endl;
            driverToEdit.SetModifiedAt(uiCommon.in.GetCurrentTime());
        }
        else
        {
            std::cout << "Password cannot be empty!" << std::endl;
        }
    }
    catch (const std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    uiCommon.PressAnyKey(true);
    UserPage();
}

void UserController::UserPage() {
    ParkingSystem ps;
    uiCommon.TitleBar("Driver App");
    int option;
    std::string loggedInUserEmail = email;
    User loggedInUser = userRepo.ReadByEmail(loggedInUserEmail);
    std::cout << "Welcome, " << loggedInUser.GetName() << "!" << std::endl;
    do {
        std::cout << "1- View/Edit Profile" << std::endl;
        std::cout << "2- Do Reservation" << std::endl;
        std::cout << "3- Pay and Unpark" << std::endl;
        std::cout << "4- Change Password" << std::endl;
        std::cout << "5- Display Bookings" << std::endl;
        std::cout << "99- Logout" << std::endl;
        std::cout << "Select an option: ";
        std::cin >> option;

        switch (option) {
            case 1:
                DisplayLoggedInUserProfile();
                break;
            case 2:
                ps.reserveParkingSpot();
                break;
            case 3:
                //ps.unparkVehicle();
                break;
            case 4:
                EditPassword();
                break;
              case 5:
                ps.viewBookings();
                break;
            case 99:
                std::cout << "Logging out..." << std::endl;
                AppMain();
                break;
            default:
                std::cout << "Invalid option. Please try again." << std::endl;
        }
    } while (option != 99);
}

void UserController::ManageUser() { 
    UserController controller;
    
    int choice;

    do { 
        choice = ReadUserMenu();
        switch(choice) {
            case 99: {
                std::cout << std::endl;
                UserPage();
            } break;
            case 1: {
                controller.DisplayAll();
            } break;
            case 2: {
                // controller.Reservation(); Implement reservation feature
            } break;
            case 3: {
                // controller.PayAndUnpark(); Implement pay and unpark feature
            } break;
            case 4: {
                // controller.ChangePassword(); Implement password change feature
            } break;
        }
    } while(99 != choice);
}
#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <unordered_map>
std::string email;

UiCommon uiCommon;
UserFileRepo urepo;
CarFileRepo crepo;
FloorFileRepo frepo;
SpotFileRepo srepo;
ReservationFileRepo rrepo;
UserController UC;


static int ReadAppMenu() {
    int choice;

    uiCommon.TitleBar("Driver App");

    std::stringstream soutput;
    soutput << "1 - Driver Registration" << std::endl;
    soutput << "2 - Login" << std::endl;
    soutput << "3 - Monitor Database" << std::endl;
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
                UC.UCreate();
            } break;

            case 2: { // Login
                std::string password;

                uiCommon.TitleBar("Login");
                std::cout << "Enter Name: ";
                std::cin >> email;
                std::cout << "Enter Password: ";
                std::cin >> password;

                UserFileRepo userRepo;
                User user = userRepo.ReadByEmail(email);
                if(user.GetPassword()==password){
                short role = user.GetRole();
                 if (role == 1) {
                    std::cout << "Login successful! Redirecting to Admin Dashboard..." << std::endl;
                    AdminPage();
                } else if (role == 0) {
                    std::cout << "Login successful! Redirecting to User Dashboard..." << std::endl;
                    
                    UC.UserPage();
                } else {
                    std::cout << "Invalid credentials. Please try again." << std::endl;
                }

                uiCommon.PressAnyKey(true);
                }
            } break;
             case 3: {
                uiCommon.TitleBar("Monitor Database");
                urepo.MonitorDb();
                crepo.MonitorDb();
                frepo.MonitorDb();
                srepo.MonitorDb();
                //rrepo.MonitorDb();
                uiCommon.PressAnyKey(true);
            }break;
            case 99: {
                std::cout << "Exiting the application. Goodbye!" << std::endl;
                exit(0);
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

