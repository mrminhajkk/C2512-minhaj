#include<iostream>
#include<vector>
#include<iomanip>
#include<chrono>
#include<fstream>
#include<string>

using namespace std;

class ParkingSpot {
private:
    int spotID;
    bool isOccupied;
    std::string vehicleNumber;
    std::chrono::time_point<std::chrono::steady_clock> startTime;

public:
    ParkingSpot(int id) : spotID(id), isOccupied(false), vehicleNumber("") {}

    bool reserveSpot(const std::string& vehicleNum) {
        if (!isOccupied) {
            isOccupied = true;
            vehicleNumber = vehicleNum;
            startTime = std::chrono::steady_clock::now();
            return true;
        }
        return false;
    }

    bool releaseSpot() {
        if (isOccupied) {
            isOccupied = false;
            vehicleNumber = "";
            return true;
        }
        return false;
    }

    double calculateCharges() {
        auto endTime = std::chrono::steady_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::hours>(endTime - startTime).count();
        return (duration > 0 ? duration : 1) * 5.0; // $5/hour
    }

    bool isAvailable() const {
        return !isOccupied;
    }

    int getID() const {
        return spotID;
    }

    std::string getVehicleNumber() const {
        return vehicleNumber;
    }

    void displaySpot() const {
        std::cout << "Spot ID: " << spotID
                  << " | Status: " << (isOccupied ? "Occupied" : "Available")
                  << " | Vehicle: " << (isOccupied ? vehicleNumber : "None") << "\n";
    }
};

class ParkingLot {
private:
    std::vector<ParkingSpot> spots;

public:
    ParkingLot(int numSpots) {
        for (int i = 1; i <= numSpots; ++i) {
            spots.emplace_back(i);
        }
    }

    void displayAvailableSpots() {
        std::cout << "Available Spots:\n";
        for (const auto& spot : spots) {
            if (spot.isAvailable()) {
                spot.displaySpot();
            }
        }
    }

    void reserveSpot() {
        std::cout << "Enter Vehicle Number: ";
        std::string vehicleNum;
        std::cin >> vehicleNum;

        for (auto& spot : spots) {
            if (spot.isAvailable()) {
                if (spot.reserveSpot(vehicleNum)) {
                    std::cout << "Spot " << spot.getID() << " reserved successfully!\n";
                    return;
                }
            }
        }
        std::cout << "No available spots!\n";
    }

    void releaseSpot() {
        std::cout << "Enter Spot ID to release: ";
        int spotID;
        std::cin >> spotID;

        for (auto& spot : spots) {
            if (spot.getID() == spotID && !spot.isAvailable()) {
                double charges = spot.calculateCharges();
                spot.releaseSpot();
                std::cout << "Spot " << spotID << " released. Charges: $" << charges << "\n";
                return;
            }
        }
        std::cout << "Invalid Spot ID or Spot is already available!\n";
    }

    void saveDataToFile(const std::string& filename) {
        std::ofstream outFile(filename);
        if (outFile.is_open()) {
            for (const auto& spot : spots) {
                outFile << spot.getID() << " " << spot.isAvailable() << " " << spot.getVehicleNumber() << "\n";
            }
            outFile.close();
        }
    }

    void loadDataFromFile(const std::string& filename) {
        std::ifstream inFile(filename);
        if (inFile.is_open()) {
            int id;
            bool isOccupied;
            std::string vehicleNum;

            while (inFile >> id >> isOccupied >> vehicleNum) {
                spots[id - 1] = ParkingSpot(id);
                if (!isOccupied) {
                    spots[id - 1].reserveSpot(vehicleNum);
                }
            }
            inFile.close();
        }
    }
};



void displayMenu() {
    std::cout << "\nSmart Parking System\n";
    std::cout << "1. View Available Parking Spots\n";
    std::cout << "2. Reserve a Parking Spot\n";
    std::cout << "3. Release a Parking Spot\n";
    std::cout << "4. Exit\n";
    std::cout << "Enter your choice: ";
}

int main() {
    ParkingLot lot(10); // Initialize with 10 spots
    lot.loadDataFromFile("parking_lot_data.txt");

    int choice;
    do {
        displayMenu();
        std::cin >> choice;

        switch (choice) {
        case 1:
            lot.displayAvailableSpots();
            break;
        case 2:
            lot.reserveSpot();
            break;
        case 3:
            lot.releaseSpot();
            break;
        case 4:
            lot.saveDataToFile("parking_lot_data.txt");
            std::cout << "Data saved. Exiting...\n";
            break;
        default:
            std::cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 4);

    return 0;
}







