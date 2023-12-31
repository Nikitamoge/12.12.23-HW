﻿#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstring>

using namespace std;

class Contact
{
    char* name;
    char* lastname;
    char* middlename;
    int home_phone_number;
    int work_phone_number;
    int phone_number;
public:
    Contact()
    {
        cout << "Constructor by default\n";
        name = nullptr;
        lastname = nullptr;
        middlename = nullptr;
        home_phone_number = 0;
        work_phone_number = 0;
        phone_number = 0;
    }
    Contact(const char* Name, const char* LastName, char* MiddleName, int HomePhoneNumber, int WorkPhoneNumber, int PhoneNumber) // construct by 2 param
    {
        cout << "Constructor with parameters\n";
        name = new char[strlen(Name) + 1];
        strcpy(name, Name);

        lastname = new char[(strlen(LastName) + 1)];
        strcpy(lastname, LastName);

        middlename = new char[(strlen(MiddleName) + 1)];
        strcpy(middlename, MiddleName);

        home_phone_number = HomePhoneNumber;
        work_phone_number = WorkPhoneNumber;
        phone_number = PhoneNumber;
    }

    ~Contact() // Destructor
    {
        cout << "Destructor called\n";
        delete[] name;
        delete[] lastname;
        delete[] middlename;
    }

    void setName() {
        cout << "Enter the name that is no more than 30 symbols long: " << endl;
        char transfer[30];
        cout << "Enter your name: ";
        cin >> transfer;

        if (name != nullptr)
        {
            delete[] name;
        }

        name = new char[strlen(transfer) + 1];
        strcpy(name, transfer);
    }

    void setLastName() {
        cout << "Enter the lastname that is no more than 30 symbols long: " << endl;
        char transfer[30];
        cout << "Enter your lastname: ";
        cin >> transfer;

        if (lastname != nullptr)
        {
            delete[] lastname;
        }

        lastname = new char[strlen(transfer) + 1];
        strcpy(lastname, transfer);
    }

    void setMiddleName() {
        cout << "Enter the middlename that is no more than 30 symbols long: " << endl;
        char transfer[30];
        cout << "Enter your middlename: ";
        cin >> transfer;

        if (middlename != nullptr)
        {
            delete[] middlename;
        }

        middlename = new char[strlen(transfer) + 1];
        strcpy(middlename, transfer);
    }

    void setHomePhoneNumber() {
        cout << "Enter home phone number: ";
        cin >> home_phone_number;
    }

    void setWorkPhoneNumber() {
        cout << "Enter work phone number: ";
        cin >> work_phone_number;
    }

    void setPhoneNumber() {
        cout << "Enter phone number: ";
        cin >> phone_number;
    }

    void Output()
    {
        if (name == nullptr || lastname == nullptr || middlename == nullptr)
        {
            cout << "Empty object!\n";
            return;
        }
        cout << "Name: " << name << endl << "Lastname: " << lastname << endl << "Middlename: " << middlename << endl
            << "Home phone number: " << home_phone_number << endl << "Work phone number: " << work_phone_number << endl << "Phone number: " << phone_number << endl << endl;
    }
};

void printContacts(Contact* contacts, int size) {
    for (int i = 0; i < size; i++) {
        contacts[i].Output();
    }
}

int main()
{
    int size = 6;
    Contact* contacts = new Contact[size];

    for (int i = 0; i < size; i++) {
        contacts[i].setName();
        contacts[i].setLastName();
        contacts[i].setMiddleName();
        contacts[i].setHomePhoneNumber();
        contacts[i].setWorkPhoneNumber();
        contacts[i].setPhoneNumber();
    }

    printContacts(contacts, size);

    delete[] contacts;
    return 0;
}
