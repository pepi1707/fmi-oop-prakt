#include <iostream>

using namespace std;

const int MAX_SIZE = 101;
const int EGN_SIZE = 11;

struct Student
{
    char name[MAX_SIZE];
    char egn[EGN_SIZE];
    int facNum;
    int numGrades;
    double grades[MAX_SIZE];
};

void initialize(Student &s)
{
    cin.ignore();
    cin.getline(s.name, MAX_SIZE);
    //cin.get();
    cin.getline(s.egn, EGN_SIZE);
    cin>> s.facNum;
    cin>> s.numGrades;
    int i;
    for(i=0;i<s.numGrades;i++)
    {
        cin>>s.grades[i];
    }
}

void print(const Student &s)
{
    cout<<s.name<<endl;
    cout<<s.egn<<endl;
    cout<<s.facNum<<endl;
    cout<<s.numGrades<<endl;
    int i;
    for(i=0;i<s.numGrades;i++)
    {
        cout<<s.grades[i]<<" ";
    }
    cout<<endl;
}

double calcAvarage(const Student s)
{
    double avarage = 0;
    for(int j = 0; j < s.numGrades; j++)
    {
        avarage += s.grades[j];
    }
    avarage /= (double)s.numGrades;
    return avarage;
}

void printAvarageMarks(Student *students, size_t count)
{
    for(int i = 0 ; i < count ; i++)
    {
        double avarage = calcAvarage(students[i]);
        cout<< avarage << endl;
    }
}

Student& getBestStudent(Student* students, size_t count)
{
    double bestAvarage = -1;
    int id = -1;
    for(int i = 0 ; i < count ; i++)
    {
        double avarage = calcAvarage(students[i]);
        if(avarage > bestAvarage)
        {
            bestAvarage = avarage;
            id = i;
        }
    }
    return students[id];
}

int main()
{
    Student students[MAX_SIZE];
    int n;
    cin>>n;
    for(int i = 0; i<n ;i++)
    {
        initialize(students[i]);
        print(students[i]);
    }
    printAvarageMarks(students, n);
    print(getBestStudent(students,n));
    return 0;
}
