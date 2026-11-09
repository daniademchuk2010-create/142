#include <iostream>
using namespace std;

class Passport
{
private:
    string seria;
    int number;
    string name;
    string surname;
    string patronymic;
    string date_of_birth;
    string place_of_birth;

public:
    Passport()
    {
        seria = "0000";
        number = 0;
        name = "no name";
        surname = "no name";
        patronymic = "no name";
        date_of_birth = "00.00.0000";
        place_of_birth = "no place";
    }

    Passport(string s, int n, string nm, string sn,
        string p, string date, string place)
    {
        seria = s;
        number = n;
        name = nm;
        surname = sn;
        patronymic = p;
        date_of_birth = date;
        place_of_birth = place;
    }

    void Print()
    {
        cout << "Seria: " << seria << endl;
        cout << "Number: " << number << endl;
        cout << "Name: " << name << endl;
        cout << "Surname: " << surname << endl;
        cout << "Patronymic: " << patronymic << endl;
        cout << "Date of birth: " << date_of_birth << endl;
        cout << "Place of birth: " << place_of_birth << endl;
    }
};

class ForeignPassport : public Passport
{
private:
    string foreignNumber;
    int countVisas;
    string visas[10];

public:
    ForeignPassport(string s, int n, string nm, string sn,
        string p, string date, string place,
        string fn)
        : Passport(s, n, nm, sn, p, date, place)
    {
        foreignNumber = fn;
        countVisas = 0;
    }

    void AddVisa(string visa)
    {
        if (countVisas < 10)
        {
            visas[countVisas] = visa;
            countVisas++;
        }
    }

    void PrintForeignPassport()
    {
        Print();

        cout << "Foreign passport number: " << foreignNumber << endl;

        cout << "Visas: " << endl;

        for (int i = 0; i < countVisas; i++)
        {
            cout << visas[i] << endl;
        }
    }
};

int main()
{
    ForeignPassport person(
        "AB",
        123456,
        "Ivan",
        "Petrenko",
        "Ivanovych",
        "10.05.2000",
        "Kyiv",
        "FT123456"
    );

    person.AddVisa("Germany");
    person.AddVisa("Poland");
    person.AddVisa("USA");

    person.PrintForeignPassport();
}

