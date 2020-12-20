#include <iostream>

using namespace std;

const int PLANE_SPEED = 20;
const int TRAIN_SPEED = 15;
const int CAR_SPEED = 5;

const int PLANE_COST = 5;
const int TRAIN_COST = 3;
const int CAR_COST = 4;

struct travelResult
{
    double time;
    double cost;

    friend ostream& operator << (ostream& out, const travelResult& obj)
    {
        return out << "Time: " << obj.time << ". Cost: " << obj.cost << endl;
    }
};

class PassengerCarrier
{
protected:
    double speed;
    double cost;

    PassengerCarrier(double speed, double cost) : speed(speed), cost(cost)
    {

    }

    travelResult calculateCost(double distance, int passengers) const
    {
        double time = distance / speed;
        double cost = passengers * distance * this->cost;
        return travelResult{ time, cost };
    }
};

class Plane : PassengerCarrier
{
private:
    int ticketCost = 0;
public:
    Plane() : PassengerCarrier(PLANE_SPEED, PLANE_COST)
    {

    }

    void calculateTravelCost(double distance, int passengers) const
    {
        travelResult result = PassengerCarrier::calculateCost(distance, passengers);
        result.cost += ticketCost;
        cout << "Travel result by plane. " << result;
    }

    void setTicketCost(int ticketCost)
    {
        this->ticketCost = ticketCost;
    }
};

class Train : PassengerCarrier
{
private:
    bool kupe = false;
public:
    Train() : PassengerCarrier(TRAIN_SPEED, TRAIN_COST)
    {
        
    }

    void calculateTravelCost(double distance, int passengers) const
    {
        travelResult result = PassengerCarrier::calculateCost(distance, passengers);
        result.cost += kupe ? 15 : 5;
        cout << "Travel result by train. " << result;
    }

    void setKupe(bool kupe)
    {
        this->kupe = kupe;
    }
};

class Car : PassengerCarrier
{
private:
    unsigned short borderPassed = 0;
public:
    Car() : PassengerCarrier(CAR_SPEED, CAR_COST)
    {

    }

    void calculateTravelCost(double distance, int passengers) const
    {
        travelResult result = PassengerCarrier::calculateCost(distance, passengers);
        result.cost += borderPassed * 4ull;
        cout << "Travel result by car. " << result;
    }

    void setBorderPassed(unsigned short borderPassed)
    {
        this->borderPassed = borderPassed;
    }
};

int main()
{
    cout << "1. Plane" << endl;
    cout << "2. Train" << endl;
    cout << "3. Car" << endl;

    int transport;
    cin >> transport;

    cout << "Travel distant: ";

    int distance;
    cin >> distance;

    cout << "Passengers: ";

    int passengers;
    cin >> passengers;

    switch (transport)
    {
    case 1:
    {
        Plane plane;
        int ticketCost;
        cout << "Ticket cost: ";
        cin >> ticketCost;
        plane.setTicketCost(ticketCost);
        plane.calculateTravelCost(distance, passengers);
        break;
    }
    case 2:
    {
        Train train;
        bool kupe;
        cout << "Is kupe: ";
        cin >> kupe;
        train.setKupe(kupe);
        train.calculateTravelCost(distance, passengers);
        break;
    }
    case 3:
    {
        Car car;
        unsigned short bordersPassed;
        cout << "Borders passed: ";
        cin >> bordersPassed;
        car.setBorderPassed(bordersPassed);
        car.calculateTravelCost(distance, passengers);
        break;
    }
    default:
        cout << "Unknown carriage. Exit";
        return 0;
    }
}
