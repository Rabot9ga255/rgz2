#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>

using namespace std;


class Address {
private:
    string locality;            // ��������� �����
    string street;              // ������
    string house_number;        // ����� �������
    string apartment_number;    // ����� ��������

public:

    void setData(string loc, string str, string house, string apartment) {
        locality = loc;
        street = str;
        house_number = house;
        apartment_number = apartment;
    }

    void printData() {
        cout << "���������� �����: " << locality << endl;
        cout << "������: " << street << endl;
        cout << "����� �������: " << house_number << endl;
        cout << "����� ��������: " << apartment_number << endl;
    }

    /*Address() {
        locality = ""; street = ""; house_number = ""; apartment_number = "";
    }*/

};

class Human {
public:

    string name;
    string surname;
    string telephone;
    Address address;

};



class member_of_social_network : public Human {
public:

    string date_registration;
    int count_of_contacts;      


    member_of_social_network() {
        count_of_contacts = 0;
    }

};



class member_of_conference : public Human {
public:

    string name_report;
    string date_report;
    string time_report;

};




int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);



    member_of_social_network social1;
    member_of_conference conference1;



    social1.name = "������";
    social1.surname = "ճ�����";
    social1.telephone = "+380505419172";
    social1.address.setData("��������", "ϳ�������������", "15�", "82");

    social1.date_registration = "04.06.2022";
    social1.count_of_contacts = 120;

    // ����
    cout << "\t ������� ��������� �����:\n" << social1.name << endl << social1.surname << endl << social1.telephone << endl;
    social1.address.printData();
    cout << social1.date_registration << endl << social1.count_of_contacts << endl << endl;




    conference1.name = "³�����";
    conference1.surname = "�����";
    conference1.telephone = "+380975221523";
    conference1.address.setData("��������", "ʳ������� ������", "12", "43");

    conference1.name_report = "�����������";
    conference1.date_report = "10.06.2022";
    conference1.time_report = "11:30";

    // ����
    cout << "\t ������� ��������� �����:\n" << conference1.name << endl << conference1.surname << endl << conference1.telephone << endl;
    conference1.address.printData();
    cout << conference1.name_report << endl << conference1.date_report << endl << conference1.time_report << endl << endl;

    return 0;
}