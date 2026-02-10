#include <iostream>
using namespace std;

class HotelMercato {
private:
    const double rent_per_day; // Rent per day is constant and cannot be changed
    string customer_name;
    int days_stayed;

public:
    // Parameterized constructor to initialize the rent per day and customer details
    HotelMercato(string customer_name, int days_stayed) : rent_per_day(1000.85), customer_name(customer_name), days_stayed(days_stayed) {}
    // Function to get the rent per day
    double getPerDayRent() const {
        return rent_per_day;
    }
    // Function to calculate the rent based on the number of days stayed
    double calculateRent() {
        if (days_stayed > 7) {
            return (days_stayed - 1) * getPerDayRent(); // Discounted rent after subtracting one day
        } else {
            return days_stayed * getPerDayRent(); // Normal rent
        }
    }


    // Function to display customer details and rent
    void display() {
        cout << "Customer name: " << customer_name << endl;
        cout << "Days stayed: " << days_stayed << endl;
        cout << "Rent: " << calculateRent() << endl;
    }
};

int main(){
    HotelMercato customer1("Abu Huraira", 10); // Customer who stayed for more than a week
    customer1.display();
    
    return 0;
}

// “Hotel Mercato” requires a system module that will help the hotel to calculate the
// rent of the customers. You are required to develop one module of the system
// according to the following requirements:
//  The hotel wants such a system that should have the feature to change the
// implementation independently of the interface. This will help when dealing
// with changing requirements.
//  The hotel charges each customer 1000.85/- per day. This amount is being
// decided by the hotel committee and cannot be changed fulfilling certain
// complex formalities.
//  The module then analyses he number of days. If the customer has stayed for
// more than a week in the hotel, he gets discount on the rent. Otherwise, he is
// being charged normally.
//  The discounted rent is being calculated after subtracting one day from the
// total number of days.
//  In the end, the module displays the following details:
// o Customer name
// o Days
// o Rent

// Note that, the function used for displaying purpose must not have the ability to
// modify any data member.