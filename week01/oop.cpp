#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void func1()
{
    char input[100];
    cin.getline(input,100);
    ofstream file("text.txt");
    if(!file.is_open())
    {
        cout<<"ERROR\n";
    }
    file << input;
    file.close();

    ifstream fi("text.txt");
    if(!fi.is_open())
    {
        cout<<"ERROR\n";
    }
    char output[100];
    fi.getline(output, 100);
    cout<<output<<endl;
    fi.close();
}

int sizeOfFile(const char *fileName)
{
    ifstream file(fileName);
    char c;
    int counter = 0;
    while(!file.eof())
    {
        c = file.get();
        counter++;
    }
    file.close();
    return counter;
}

int _sizeOfFile(const char *fileName)
{
    streampos begin,end;
    ifstream file(fileName);
    begin = file.tellg();
    file.seekg(0,ios::end);
    end = file.tellg();
    file.close();
    return (end - begin);
}

int numberRows(const char *filename)
{
    int counter = 0;
    ifstream file(filename);
    int maxSize = _sizeOfFile(filename);
    char *input = new char[maxSize + 1];
    while(file.getline(input, maxSize))
    {
        counter ++;
    }
    delete[] input;
    file.close();
    return counter;
}

int numRows(const char *filename)
{
    int counter = 1;
    ifstream file(filename);
    char c;
    while(!file.eof())
    {
        c = file.get();
        if(c == '\n')
            counter++;
    }
    file.close();
    return counter;
}

int main()
{
    int rows =  numberRows("text.txt");
    int _rows = numRows("text.txt");
    cout<<rows<<" "<<_rows<<endl;
    return 0;
}
