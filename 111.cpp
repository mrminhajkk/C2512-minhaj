
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
#include <chrono>
#include <ctime>
#include <sstream>

using namespace std;
using namespace chrono;

// File names
const string USERS_FILE = "users.txt";
const string VEHICLES_FILE = "vehicles.txt";
const string PARKING_SPOTS_FILE = "parking_spots.txt";
const string BOOKINGS_FILE = "bookings.txt";

// Classes
class User {
public:
    string name, email, phone, password;

    void registerUser() {
        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Email: ";
        cin >> email;
        cout << "Enter Phone: ";
        cin >> phone;
        cout << "Enter Password: ";
        cin >> password;

        ofstream file(USERS_FILE, ios::app);
        file << name << "," << email << "," << phone << "," << password << endl;
        file.close();

        cout << "User registered successfully!\n";
    }

    bool loginUser() {
        string inputEmail, inputPassword;
        cout << "Enter Email: ";
        cin >> inputEmail;
        cout << "Enter Password: ";
        cin >> inputPassword;

        ifstream file(USERS_FILE);
        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            string userName, userEmail, userPhone, userPassword;
            getline(ss, userName, ',');
            getline(ss, userEmail, ',');
            getline(ss, userPhone, ',');
            getline(ss, userPassword, ',');

            if (userEmail == inputEmail && userPassword == inputPassword) {
                name = userName;
                email = userEmail;
                phone = userPhone;
                password = userPassword;
                cout << "Login successful! Welcome, " << name << ".\n";
                return true;
            }
        }
        file.close();

        cout << "Invalid email or password.\n";
        return false;
    }
};

class Vehicle {
public:
    string vehicleNumber, model, type;

    void addVehicle(const string& userEmail) {
        cout << "Enter Vehicle Number: ";
        cin >> vehicleNumber;
        cout << "Enter Vehicle Model: ";
        cin >> model;
        cout << "Enter Vehicle Type: ";
        cin >> type;

        ofstream file(VEHICLES_FILE, ios::app);
        file << userEmail << "," << vehicleNumber << "," << model << "," << type << endl;
        file.close();

        cout << "Vehicle added successfully!\n";
    }

    void viewVehicles(const string& userEmail) {
        ifstream file(VEHICLES_FILE);
        string line;
        bool found = false;

        cout << "Your Vehicles:\n";
        while (getline(file, line)) {
            stringstream ss(line);
            string email, number, model, type;
            getline(ss, email, ',');
            getline(ss, number, ',');
            getline(ss, model, ',');
            getline(ss, type, ',');

            if (email == userEmail) {
                cout << "Vehicle Number: " << number << ", Model: " << model << ", Type: " << type << endl;
                found = true;
            }
        }
        file.close();

        if (!found) {
            cout << "No vehicles found.\n";
        }
    }
};

class ParkingSpot {
public:
    string location;
    double pricePerHour;
    int capacity;

    void addParkingSpot() {
        cout << "Enter Location: ";
        cin.ignore();
        getline(cin, location);
        cout << "Enter Price per Hour: ";
        cin >> pricePerHour;
        cout << "Enter Capacity: ";
        cin >> capacity;

        ofstream file(PARKING_SPOTS_FILE, ios::app);
        file << location << "," << pricePerHour << "," << capacity << endl;
        file.close();

        cout << "Parking spot added successfully!\n";
    }

    void searchParkingSpots() {
        ifstream file(PARKING_SPOTS_FILE);
        string line;

        cout << "Available Parking Spots:\n";
        while (getline(file, line)) {
            stringstream ss(line);
            string location;
            double price;
            int capacity;

            getline(ss, location, ',');
            ss >> price;
            ss.ignore();
            ss >> capacity;

            cout << "Location: " << location << ", Price per Hour: $" << price << ", Capacity: " << capacity << endl;
        }
        file.close();
    }
};

class Booking {
public:
    string userEmail, parkingLocation;
    time_point<system_clock> startTime, endTime;

    void bookParkingSpot(const string& userEmail) {
        ParkingSpot spot;
        spot.searchParkingSpots();

        cout << "Enter Parking Location to Book: ";
        cin.ignore();
        getline(cin, parkingLocation);

        startTime = system_clock::now();
        cout << "Parking spot booked successfully!\n";

        ofstream file(BOOKINGS_FILE, ios::app);
        file << userEmail << "," << parkingLocation << "," << chrono::system_clock::to_time_t(startTime) << endl;
        file.close();
    }

    void calculateParkingTime() {
        endTime = system_clock::now();
        duration<double> elapsedTime = endTime - startTime;

        cout << "Parking Duration: " << elapsedTime.count() / 60 << " minutes.\n";
    }
};

// Menu
void displayMenu() {
    cout << "\n--- Smart Parking System ---\n";
    cout << "1. Register User\n";
    cout << "2. Login User\n";
    cout << "3. Add Vehicle\n";
    cout << "4. View Vehicles\n";
    cout << "5. Search Parking Spots\n";
    cout << "6. Book Parking Spot\n";
    cout << "7. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    User user;
    Vehicle vehicle;
    ParkingSpot spot;
    Booking booking;

    int choice;
    bool isLoggedIn = false;

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
        case 1:
            user.registerUser();
            break;
        case 2:
            isLoggedIn = user.loginUser();
            break;
        case 3:
            if (isLoggedIn) vehicle.addVehicle(user.email);
            else cout << "Please log in first.\n";
            break;
        case 4:
            if (isLoggedIn) vehicle.viewVehicles(user.email);
            else cout << "Please log in first.\n";
            break;
        case 5:
            spot.searchParkingSpots();
            break;
        case 6:
            if (isLoggedIn) booking.bookParkingSpot(user.email);
            else cout << "Please log in first.\n";
            break;
        case 7:
            cout << "Exiting the system. Goodbye!\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 7);

    return 0;
}
