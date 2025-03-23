#include <iostream>
using namespace std;

class ticket {
    int id;
    string name;
    double price;
    string date;
    string destination;

public:
    // Corrected constructor name
    ticket(int id, string name, double price, string date, string destination) {
        this->id = id;
        this->name = name;
        this->price = price;
        this->date = date;
        this->destination = destination;
    }

    virtual void reserve() {
        cout << "Ticket reserved" << endl;
    }

    virtual void cancel() {
        cout << "Ticket cancelled" << endl;
    }

    virtual void display() {
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Price: " << price << endl;
        cout << "Date: " << date << endl;
        cout << "Destination: " << destination << endl;
    }

    virtual ~ticket() {} // Virtual destructor for proper cleanup
};

class flight_ticket : public ticket {
    string airline_name;
    int flight_no;
    string seat_class;

public:
    flight_ticket(int id, string name, double price, string date, string destination,
                  string airline_name, int flight_no, string seat_class)
        : ticket(id, name, price, date, destination) { // Corrected base class constructor call
        this->airline_name = airline_name;
        this->flight_no = flight_no;
        this->seat_class = seat_class;
    }

    void display() { // Overriding display() without 'override'
        ticket::display();
        cout << "Airline Name: " << airline_name << endl;
        cout << "Flight No: " << flight_no << endl;
        cout << "Seat Class: " << seat_class << endl;
    }
};

class train_ticket : public ticket {
    int train_no;
    string coach_type;
    string departure_time;

public:
    train_ticket(int id, string name, double price, string date, string destination,
                 int train_no, string coach_type, string departure_time)
        : ticket(id, name, price, date, destination) { // Corrected base class constructor call
        this->train_no = train_no;
        this->coach_type = coach_type;
        this->departure_time = departure_time;
    }

    void reserve() { // Overriding reserve() without 'override'
        cout << "Train ticket reserved" << endl;
    }
};

class bus_ticket : public ticket {
    string bus_company;
    int s_no;

public:
    bus_ticket(int id, string name, double price, string date, string destination,
               string bus_company, int s_no)
        : ticket(id, name, price, date, destination) { // Corrected base class constructor call
        this->bus_company = bus_company;
        this->s_no = s_no;
    }

    void cancel() { // Overriding cancel() without 'override'
        cout << "Bus ticket cancelled" << endl;
    }
};

class concert_ticket : public ticket {
    string artist;
    string venue;
    string seat_type;

public:
    concert_ticket(int id, string name, double price, string date, string destination,
                   string artist, string venue, string seat_type)
        : ticket(id, name, price, date, destination) { // Corrected base class constructor call
        this->artist = artist;
        this->venue = venue;
        this->seat_type = seat_type;
    }

    void display() { // Overriding display() without 'override'
        ticket::display();
        cout << "Artist: " << artist << endl;
        cout << "Venue: " << venue << endl;
        cout << "Seat Type: " << seat_type << endl;
    }
};

int main() {
    ticket *t1 = new flight_ticket(1, "Ali", 1000, "12-12-2020", "Lahore", "PIA", 123, "Economy");
    t1->display();
    cout << endl;

    ticket *t2 = new train_ticket(2, "Ahmed", 500, "12-12-2020", "Karachi", 123, "AC", "12:00");
    t2->reserve();
    cout << endl;

    ticket *t3 = new bus_ticket(3, "Asad", 200, "12-12-2020", "Islamabad", "Daewoo", 12);
    t3->cancel();
    cout << endl;

    ticket *t4 = new concert_ticket(4, "Ahsan", 300, "12-12-2020", "Lahore", "Ali Zafar", "Alhamra", "VIP");
    t4->display();
    cout << endl;

    // Proper cleanup
    delete t1;
    delete t2;
    delete t3;
    delete t4;

    return 0;
}
