#include <iostream> 
#include <fstream> 
#include <string> 
#include <Windows.h> 


using namespace std;




struct TAGdata
{
    char tag[3];        // -128 
    char title[30];     // -125 
    char artist[30];    // -95 
    char album[30];     // -65 
    char year[4];       // -35 
    char comment[30];     // -31 

};


void clearData(fstream &mp3File, int const mp3TagSize) {

    string s; string s1; string s2; string s3; string s4;

    s = s1 = s2 = s4 = "                            ";
    s3 = "    ";

    mp3File << s;
    mp3File.seekg(-(mp3TagSize - 33), ios::end);
    mp3File << s1;
    mp3File.seekg(-(mp3TagSize - 63), ios::end);
    mp3File << s2;
    mp3File.seekg(-(mp3TagSize - 93), ios::end);
    mp3File << s3;
    mp3File.seekg(-(mp3TagSize - 97), ios::end);
    mp3File << s4;

    mp3File.seekg(-(mp3TagSize - 3), ios::end);
}


void fillData(fstream& mp3File, string s, string s1, string s2, string s3, string s4, int const mp3TagSize) {

    mp3File << s;
    mp3File.seekg(-(mp3TagSize - 33), ios::end);
    mp3File << s1;
    mp3File.seekg(-(mp3TagSize - 63), ios::end);
    mp3File << s2;
    mp3File.seekg(-(mp3TagSize - 93), ios::end);
    mp3File << s3;
    mp3File.seekg(-(mp3TagSize - 97), ios::end);
    mp3File << s4;

}


void printData(TAGdata& tagStruct) {

    printf("\n\nTag: %0.3s\n", tagStruct.tag);
    printf("Title: %0.30s\n", tagStruct.title);
    printf("Artist: %0.30s\n", tagStruct.artist);
    printf("Album: %0.30s\n", tagStruct.album);
    printf("Year: %0.4s\n", tagStruct.year);
    printf("Comment: %0.30s\n", tagStruct.comment);

}


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int const mp3TagSize = 128;
    TAGdata tagStruct = { 0 };

    fstream mp3File;



    string filename = "zvuk.mp3";

    mp3File.open(filename);


    if (mp3File) {
        cout << "Successful open of " << filename << endl;
    }
    else {
        cerr << "Aborting Could not open " << filename << endl;
        return 1;
    }


    cout << "\t Inctruction:\n";
    cout << "write 1 to check ID3 tags\n";
    cout << "write 2 to change ID3 tags\n";
    cout << "write 0 to exit\n\n";

    int answer = 50;
    while (answer != 0) {
        cin >> answer;
        if (answer == 1) {

            //move file pointer to 128 bytes off the end of the file. 
            mp3File.seekg(-(mp3TagSize), ios::end);
            if (mp3File.fail()) {
                cerr << "Could not seek, Aborting " << endl;
                return 1;
            }

            //get the data 
            mp3File.read(tagStruct.tag, 3);
            mp3File.read(tagStruct.title, 30);
            mp3File.read(tagStruct.artist, 30);
            mp3File.read(tagStruct.album, 30);
            mp3File.read(tagStruct.year, 4);
            /*mp3File.read(tagStruct.comment, 25);*/
            mp3File.read(tagStruct.comment, 30);

            mp3File.close();

            printData(tagStruct);

            mp3File.open(filename);
        }
        else if (answer == 2) {

            //move file pointer to 125 bytes off the end of the file, skip TAG 
            mp3File.seekg(-(mp3TagSize - 3), ios::end);
            if (mp3File.fail()) {
                cerr << "Could not seek, Aborting " << endl;
                return 1;
            }

            string s; string s1; string s2; string s3; string s4;

            cout << "Enter title\n";
            cin.ignore();
            getline(cin, s);
            cout << "\nEnter artist\n";
            getline(cin, s1);
            cout << "\nEnter album\n";
            getline(cin, s2);
            cout << "\nEnter year\n";
            getline(cin, s3);
            cout << "\nEnter comment\n";
            getline(cin, s4);

            clearData(mp3File, mp3TagSize);

            fillData(mp3File, s, s1, s2, s3, s4, mp3TagSize);


            mp3File.close();
            mp3File.open(filename);
        }
        cout << "something else?\n\n";
    }


    mp3File.close();
    return 0;
}