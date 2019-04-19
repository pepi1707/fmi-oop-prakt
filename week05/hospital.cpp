#include <iostream>
#include <cstring>

using namespace std;

class Patient
{
    char *name;
    char *dateBirth;
    int numVisits;

public:
    ~Patient()
    {
        if(name != nullptr)
            delete[] name;
        if(dateBirth != nullptr)
            delete[] dateBirth;
    }

    Patient()
    {
        name = nullptr;
        dateBirth = nullptr;
        numVisits = 0;
    }

    Patient(const char *_name, const char *_dateBirth, int _numVisits)
    {
        name = new char[strlen(_name) + 1];
        strcpy(name, _name);

        dateBirth = new char[strlen(_dateBirth) + 1];
        strcpy(dateBirth, _dateBirth);

        numVisits = _numVisits;
    }

    Patient(const Patient& toCopy)
    {
        name = new char[strlen(toCopy.name) + 1];
        strcpy(name, toCopy.name);

        dateBirth = new char[strlen(toCopy.dateBirth) + 1];
        strcpy(dateBirth, toCopy.dateBirth);

        numVisits = toCopy.numVisits;
    }

    Patient& operator = (const Patient& toCopy)
    {
        if(this == &toCopy)
            return *this;
        if(name != nullptr)
            delete[] name;
        if(dateBirth != nullptr)
            delete[] dateBirth;
        name = new char[strlen(toCopy.name) + 1];
        strcpy(name, toCopy.name);

        dateBirth = new char[strlen(toCopy.dateBirth) + 1];
        strcpy(dateBirth, toCopy.dateBirth);

        numVisits = toCopy.numVisits;
        return *this;
    }

    bool operator == (const Patient& cmp) const
    {
        if(name == nullptr || cmp.name == nullptr)
            return 0;
        if(dateBirth == nullptr || cmp.dateBirth == nullptr)
            return 0;
        return (!strcmp(name, cmp.name) && !strcmp(dateBirth, cmp.dateBirth));
    }

    int getNumVisits() const
    {
        return numVisits;
    }

    void visits()
    {
        numVisits++;
    }

    void print() const
    {
        cout << name << endl;
        cout << dateBirth << endl;
        cout << numVisits << endl;
    }

    void setNumVisits(int x)
    {
        numVisits = x;
    }

};

class Doctor
{
    Patient* patients;
    int numPatients;
    int capacity;
    static int numAll;
    void resize()
    {
        capacity *= 2;
        Patient* cur = new Patient[capacity];
        for(int i = 0; i < numPatients; i++)
            cur[i] = patients[i];
        delete[] patients;
        patients = cur;
    }

public:
    Doctor()
    {
        patients = new Patient[1];
        numPatients = 0;
        capacity = 1;
    }

    ~Doctor()
    {
        delete[] patients;
    }

    Doctor(const Doctor& toCopy)
    {
        capacity = toCopy.capacity;
        numPatients = toCopy.numPatients;
        patients = new Patient[capacity];
        for(int i = 0; i < numPatients; i++)
        {
            patients[i] = toCopy.patients[i];
        }
    }

    Doctor& operator = (const Doctor& toCopy)
    {
        if(this == &toCopy)
            return *this;
        delete[] patients;
        capacity = toCopy.capacity;
        numPatients = toCopy.numPatients;
        patients = new Patient[capacity];
        for(int i = 0; i < numPatients; i++)
        {
            patients[i] = toCopy.patients[i];
        }
        return *this;
    }

    void visit(const Patient& visitor)
    {
        numAll++;
        for(int i = 0; i < numPatients; i++)
        {
            if(visitor == patients[i])
            {
                patients[i].visits();
                return;
            }
        }
        if(numPatients == capacity)
        {
            resize();
        }
        patients[numPatients] = visitor;
        patients[numPatients].setNumVisits(1);
        numPatients++;
    }

    double averageVisits()
    {
        double sum = 0;
        for(int i = 0; i < numPatients; i++)
        {
            sum += patients[i].getNumVisits();
        }
        sum /= numPatients;
        return sum;
    }

    int numMoreThan(int x) const
    {
        int br = 0;
        for(int i = 0; i < numPatients; i++)
        {
            if(patients[i].getNumVisits() > x)
                br++;
        }
        return br;
    }

    Patient* moreThan(int x) const
    {
        int br = numMoreThan(x);
        Patient* ret = new Patient[br];
        br = 0;
        for(int i = 0; i < numPatients; i++)
        {
            if(patients[i].getNumVisits() > x)
            {
                ret[br] = patients[i];
                br++;
            }
        }
        return ret;
    }

    static int getNumALL()
    {
        return numALL;
    }

    void print()
    {
        cout << numPatients << endl;
        for(int i = 0; i < numPatients; i++)
        {
            patients[i].print();
            cout << endl;
        }
    }
};

static int Doctor::numAll = 0;

class Hospital
{
    Doctor* doctors;
    int numDoctors;
    int capacity;

public:
    Hospital()
    {
        doctors = new Doctor[1];
        numDoctors = 0;
        capacity = 1;
    }

    ~Hospital()
    {
        delete[] doctors;
    }

    Hospital(const Hospital& toCopy)
    {
        numDoctors = toCopy.numDoctors;
        capacity = toCopy.capacity;
        doctors = new Doctor[capacity];
        for(int i = 0; i < numDoctors; i++)
        {
            doctors[i] = toCopy.doctors[i];
        }
    }

    Hospital& operator = (const Hospital& toCopy)
    {
        if(this == &toCopy)
            return *this;
        delete[] doctors;
        numDoctors = toCopy.numDoctors;
        capacity = toCopy.capacity;
        doctors = new Doctor[capacity];
        for(int i = 0; i < numDoctors; i++)
        {
            doctors[i] = toCopy.doctors[i];
        }
        return *this;
    }
};

int main()
{
    Patient p1("Pepi", "11/07/1999", 0);
    Patient p2("Cveti", "08/08/1998", 0);
    Doctor d;
    d.visit(p1);
    d.visit(p2);
    d.print();
    d.visit(p1);
    d.print();
    /*cout << d.averageVisits() << endl;
    Patient* pp = d.moreThan(1);
    int br = d.numMoreThan(1);
    for(int i = 0; i < br; i++)
    {
        pp[i].print();
    }*/
    Doctor cpy(d);
    cpy.print();

    cout << Doctor::getNumAll() << endl;
	return 0;
}
