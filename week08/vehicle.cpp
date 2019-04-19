#include <iostream>
#include <cstring>

using namespace std;

class Vehicle
{

private:

    char *colour;
    char *merch;
    int year;
    int capacity;
    double maxSpeed;

    void copy(const Vehicle& toCopy)
    {
        colour = new char[strlen(toCopy.colour) + 1];
        strcpy(colour, toCopy.colour);

        merch = new char[strlen(toCopy.merch) + 1];
        strcpy(merch, toCopy.merch);

        year = toCopy.year;

        capacity = toCopy.capacity;

        maxSpeed = toCopy.maxSpeed;
    }

public:

    Vehicle()
    {
        colour = nullptr;
        merch = nullptr;
        year = 0;
        capacity = 0;
        maxSpeed = 0;
    }

    ~Vehicle()
    {
        delete[] colour;
        delete[] merch;
    }

    Vehicle(char* _colour, char* _merch, int _year, int _capacity, double _maxSpeed)
    {
        colour = new char[strlen(_colour) + 1];
        strcpy(colour, _colour);

        merch = new char[strlen(_merch) + 1];
        strcpy(merch, _merch);

        year = _year;

        capacity = _capacity;

        maxSpeed = _maxSpeed;
    }

    Vehicle(const Vehicle& toCopy)
    {
        this->copy(toCopy);
    }

    Vehicle& operator = (const Vehicle& toCopy)
    {
        if(this == &toCopy)
        {
            return *this;
        }

        if(colour != nullptr)
            delete[] colour;

        if(merch != nullptr)
            delete[] merch;

        this->copy(toCopy);

        return *this;
    }

    char* getColour()
    {
        if(colour == nullptr)
            return nullptr;
        char* ret = new char[strlen(colour) + 1];
        strcpy(ret, colour);
        return ret;
    }

    void setColour(char* _colour)
    {
        if(colour != nullptr)
        {
            delete[] colour;
        }

        colour = new char[strlen(_colour) + 1];
        strcpy(colour, _colour);
    }

    char* getMerch()
    {
        if(merch == nullptr)
            return nullptr;
        char* ret = new char[strlen(merch) + 1];
        strcpy(ret, colour);
        return ret;
    }

    void setMerch(char* _merch)
    {
        if(merch != nullptr)
        {
            delete[] merch;
        }

        merch = new char[strlen(_merch) + 1];
        strcpy(merch, _merch);
    }

    int getYear()
    {
        return year;
    }

    void setYear(int _year)
    {
        year = _year;
    }

    int getCapacity()
    {
        return capacity;
    }

    void setCapacity(int _capacity)
    {
        capacity = _capacity;
    }

    double getMaxSpeed()
    {
        return maxSpeed;
    }

    void setMaxSpeed(double _maxSpeed)
    {
        maxSpeed = _maxSpeed;
    }
};

class Bicycle : public Vehicle
{

private:

    int numSpeeds;
    bool hasLights;
    bool hasRing;

public:

    int getNumSpeeds()
    {
        return numSpeeds;
    }

    void setNumSpeeds(int _numSpeeds)
    {
        numSpeeds = _numSpeeds;
    }

    bool getHasLights()
    {
        return hasLights;
    }

    void setHasLights(bool _hasLights)
    {
        hasLights = _hasLights;
    }

    bool getHasRing()
    {
        return hasRing;
    }

    void setHasRing(bool _hasRing)
    {
        hasRing = _hasRing;
    }

    Bicycle() : Vehicle()
    {
        numSpeeds = 0;
        hasLights = 0;
        hasRing = 0;
    }

    Bicycle(char* _colour, char* _merch, int _year, int _capacity, double _maxSpeed, int _numSpeeds, bool _hasLights, bool _hasRing) : Vehicle(_colour, _merch, _year, _capacity, _maxSpeed)
    {
        numSpeeds = _numSpeeds;
        hasLights = _hasLights;
        hasRing = _hasRing;
    }

    Bicycle(const Bicycle& toCopy) : Vehicle(toCopy)
    {
        numSpeeds = toCopy.numSpeeds;
        hasLights = toCopy.hasLights;
        hasRing = toCopy.hasRing;
    }

    Bicycle& operator = (const Bicycle& toCopy)
    {
        if(this == &toCopy)
        {
            return *this;
        }

        Vehicle::operator = (toCopy);

        numSpeeds = toCopy.numSpeeds;
        hasLights = toCopy.hasLights;
        hasRing = toCopy.hasRing;

        return *this;
    }

};

class Car : public Vehicle
{

private:

    char* model;
    int numDoors;
    int horsePower;

public:

    Car() : Vehicle()
    {
        model = nullptr;
        numDoors = 0;
        horsePower = 0;
    }

    ~Car()
    {
        delete[] model;
    }

    Car(char* _colour, char* _merch, int _year, int _capacity, double _maxSpeed, char* _model, int _numDoors, int _horsePower) : Vehicle(_colour, _merch, _year, _capacity, _maxSpeed)
    {
        model = new char[strlen(_model) + 1];
        strcpy(model, _model);

        numDoors = _numDoors;

        horsePower = _horsePower;
    }

    Car(const Car& toCopy) : Vehicle(toCopy)
    {
        model = new char[strlen(toCopy.model) + 1];
        strcpy(model, toCopy.model);

        numDoors = toCopy.numDoors;

        horsePower = toCopy.horsePower;
    }

    Car& operator = (const Car& toCopy)
    {
        if(this == &toCopy)
        {
            return *this;
        }

        Vehicle::operator = (toCopy);

        if(model != nullptr)
            delete[] model;

        model = new char[strlen(toCopy.model) + 1];
        strcpy(model, toCopy.model);

        numDoors = toCopy.numDoors;

        horsePower = toCopy.horsePower;

        return *this;
    }

    char* getModel()
    {
        if(model == nullptr)
            return nullptr;
        char* ret = new char[strlen(model) + 1];
        strcpy(ret, model);
        return ret;
    }

    void setModel(char* _model)
    {
        if(model != nullptr)
        {
            delete[] model;
        }

        model = new char[strlen(_model) + 1];
        strcpy(model, _model);
    }

    int getNumDoors()
    {
        return numDoors;
    }

    void setNumDoors(int _numDoors)
    {
        numDoors = _numDoors;
    }

    int getHorsePower()
    {
        return horsePower;
    }

    void setHorsePower(int _horsePower)
    {
        horsePower = _horsePower;
    }
};

int main()
{
    Vehicle v("blue", "mercedes", 2000, 5, 260.6);
    Vehicle v2, v3;
    v3 = v2 = v;
    cout << v3.getColour() << endl;

    Bicycle b("red", "balkanche", 1999, 4, 210.4, 5, true, true);
    cout << b.getColour() << endl;

    Bicycle b2;
    b2 = b;
    cout << b2.getColour() << endl;

    Car c("cherveno", "ferari", 2019, 2, 327.4, "nai-noviq", 2, 1000);
    cout << c.getModel() << " " << c.getMerch() << endl;

    Car c2;
    c2 = c;
    cout << c2.getModel() << " " << c2.getMerch() << endl;

	return 0;
}
