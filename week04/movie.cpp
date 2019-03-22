#include <iostream>
#include <cstring>

using namespace std;

class Movie
{
    char *name;
    char *director;
    int time;

public:
    Movie()
    {
        name = nullptr;
        director = nullptr;
        time = 0;
    }

    Movie(char *_name, char *_director, int _time)
    {
        name = new char[strlen(_name) + 1];
        strcpy(name, _name);

        director = new char[strlen(_director) + 1];
        strcpy(director, _director);

        time = _time;
    }

    Movie(const Movie &toCopy)
    {
        name = new char[strlen(toCopy.name) + 1];
        strcpy(name, toCopy.name);

        director = new char[strlen(toCopy.director) + 1];
        strcpy(director, toCopy.director);

        time = toCopy.time;
    }

    ~Movie()
    {
        if(name != nullptr)
        {
            delete[] name;
            delete[] director;
        }
    }

    Movie& operator = (const Movie& toCopy)
    {
        if(this == &toCopy)
        {
            return *this;
        }
        if(name != nullptr)
        {
            delete[] name;
            delete[] director;
        }
        name = new char[strlen(toCopy.name) + 1];
        strcpy(name, toCopy.name);

        director = new char[strlen(toCopy.director) + 1];
        strcpy(director, toCopy.director);

        time = toCopy.time;

        return *this;
    }

    friend ostream& operator << (ostream& out, const Movie& src)
    {
        out << src.name << "\n" << src.director << "\n" << src.time << "\n";
        return out;
    }

    friend istream& operator >> (istream& in, Movie& src)
    {
        if (src.name != nullptr)
            delete[] src.name;

        if (src.director !=nullptr)
            delete[] src.director;

        char buffer[1001];
        in >> buffer;
        src.name = new char[strlen(buffer) + 1];
        strcpy(src.name, buffer);

        in >> buffer;
        src.director = new char[strlen(buffer) + 1];
        strcpy(src.director, buffer);

        in >> src.time;
    }

};

int main()
{
    Movie m;
    cin >> m;
    cout << m << endl;
	return 0;
}
