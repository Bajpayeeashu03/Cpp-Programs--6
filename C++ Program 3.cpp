#include <iostream>
#include <string>
using namespace std;

class Vehicle {
protected:
    string name;
    double mileage;
    double distance;
    double fuel;
public:
    void input() {
        try {
            cout << "Enter The Name :-" << endl;
            cin >> name;
            cout << "Enter total Distance Travelled:" << endl;
            cin >> distance;
            if (distance <= 0) {
                throw runtime_error("Distance must be a positive number.");
            }
            cout << "Enter Total Fuel Consumed :" << endl;
            cin >> fuel;
            if (fuel <= 0) {
                throw runtime_error("Fuel consumption must be a positive number.");
            }
        } catch (exception& a) {
            cout<<a.what() << endl;
            exit(1);
        }
    }

    void displayDetails() {
        cout << "Name Is : " << name << endl;
        mileage = distance / fuel;
        cout << "Mileage Is : " << mileage << " km/litre" << endl;
    }
};

class TwoWheeler : public Vehicle {
private:
    double price;
public:
    void bike() {
        try {
            Vehicle::input();
            Vehicle::displayDetails();
            cout << "Enter The price Of Two Wheeler:" << endl;
            cin >> price;
            if (price <= 0) {
                throw runtime_error("Price must be a positive number.");
            }
            cout << "The Price Of Two Wheeler Is :" << price << endl;
        } catch (exception &a) {
            cout<< a.what() << endl;
            exit(1);
        }
    }
};

class FourWheeler : public Vehicle {
private:
    double cost;
public:
    void car() {
        try {
            Vehicle::input();
            Vehicle::displayDetails();
            cout << "Enter The price Of Four Wheeler:" << endl;
            cin >> cost;
            if (cost <= 0) {
                throw runtime_error("Price must be a positive number.");
            }
            cout << "The Price of Four Wheeler is :" << cost << endl;
        } catch (exception& a) {
            cout<< a.what() << endl;
            exit(1);
        }
    }
};

int main() {
    try {
        TwoWheeler obj1;
        FourWheeler obj2;
        int choice;
        cout << "Enter 1 for TwoWheeler or 2 for FourWheeler:-";
        cin >> choice;
        switch (choice) {
            case 1:
                obj1.bike();
                break;
            case 2:
                obj2.car();
                break;
            default:
                cout << "Invalid Choice" << endl;
                return 0;
        }
    } catch (exception& a) {
        cout << "Error: " << a.what() << endl;
        return 1;
    }
    return 0;
}