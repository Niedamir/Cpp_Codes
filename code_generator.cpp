#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

string prefix;
string suffix;
bool isAlphanumerical = false;
int codeLenght = 3;
int codesNumber = 1;

string setString(string & string)
{
    cin >> string;
    cout << endl;
    cin.clear();
    cin.sync();

    return string;
}

bool setCharset(bool isAlphanumerical)
{
    string charset;
    int charsetOperationCode;
    bool endSetCharset = false;

    if(isAlphanumerical == true)
        charset = "alphanumerical";
    else
        charset = "numerical";

    do
    {
        cout << "Actual code charset: " << charset << endl;
        cout << "Please, choose option:" << endl;
        cout << "[1] Alphanumerical" << endl;
        cout << "[2] Numerical" << endl;
        cin >> charsetOperationCode;
        cout << endl;

        switch(charsetOperationCode)
        {
        case 1:
            isAlphanumerical = true;
            endSetCharset = true;
            break;
        case 2:
            isAlphanumerical = false;
            endSetCharset = true;
            break;
        default:
            cout << "ERROR! An unknown operation code has been entered! Please try again." << endl << endl;
            break;
        }
        cin.clear();
        cin.sync();
    }while(endSetCharset != true);

    return isAlphanumerical;
}

int setNumber(int & number)
{
    bool endSetNumber = false;
    int valueValidation;

    do
    {
        cin >> valueValidation;
        cout << endl;

        if(cin.good() && valueValidation > 0)
            endSetNumber = true;
        else
            cout << "ERROR! The entered value is invalid! Please try again." << endl << endl;

        cin.clear();
        cin.sync();
    }while(endSetNumber != true);

    return valueValidation;
}

void settings()
{
    bool back = false;
    int settingsOperationCode;

    do
    {
        cout << "[1] Set prefix" << endl;
        cout << "[2] Set suffix" << endl;
        cout << "[3] Set charset" << endl;
        cout << "[4] Set main code lenght" << endl;
        cout << "[5] Set number of codes" << endl;
        cout << "[0] Back" << endl;
        cin >> settingsOperationCode;
        cout << endl;

        switch(settingsOperationCode)
        {
        case 1:
            cout << "Actual prefix: " << suffix << endl;
            cout << "Please enter new prefix: ";
            prefix = setString(prefix);
            break;
        case 2:
            cout << "Actual suffix: " << suffix << endl;
            cout << "Please enter new suffix: ";
            suffix = setString(suffix);
            break;
        case 3:
            isAlphanumerical = setCharset(isAlphanumerical);
            break;
        case 4:
            cout << "Actual code lenght: " << codeLenght << endl;
            cout << "Please enter the number of code chars: ";
            codeLenght = setNumber(codeLenght);
            break;
        case 5:
            cout << "Program will generate " << codesNumber << " codes." << endl;
            cout << "Please enter the number of codes: ";
            codesNumber = setNumber(codesNumber);
            break;
        case 0:
            back = true;
            break;
        default:
            cout << "ERROR! An unknown operation code has been entered! Please try again." << endl << endl;
            break;
        }
        cin.clear();
        cin.sync();
    }while(back != true);
}

void printTxt(string table[])
{
    ofstream codesTxt;
    codesTxt.open("codes.txt");

    codesTxt << "  +----------------------------------+" << endl;
    codesTxt << "  |       codes generated with:      |" << endl;
    codesTxt << "  |    PROMOTION CODES GENERATOR     |" << endl;
    codesTxt << "  |  Developed by Rafal Lewandowski  |" << endl;
    codesTxt << "  |              ver. 1.0            |" << endl;
    codesTxt << "  +----------------------------------+" << endl;
    codesTxt << endl << endl;

    for(int i = 0; i < codesNumber; i++)
    {
        codesTxt << table[i] << endl;
    }

    codesTxt << endl << "Thank you for using my tool.";
    codesTxt.close();
}

void generate()
{
    srand(time(NULL));
    string codelist[codesNumber];
    bool isChar;
    char codeChar;


    for(int i = 0; i < codesNumber; i++)
    {
        codelist[i] = prefix;
        if(isAlphanumerical == false)
        {
            for(int x = 0; x < codeLenght; x++)
            {
                codeChar = (rand() % 10) + 48;
                codelist[i] += codeChar;
            }
        }
        else
        {
            for(int x = 0; x < codeLenght; x++)
            {
                isChar = rand() % 2;
                if(isChar == false)
                    codeChar = (rand() % 10) + 48;
                else
                    codeChar = (rand() % 26) + 97;
                codelist[i] += codeChar;
            }
        }

        codelist[i] += suffix;
        cout << codelist[i] << endl;
    }

    cout << endl;
    printTxt(codelist);
    cout << "DONE!" << endl << endl;
}

void menu()
{

    bool exit = false;
    int menuOperationCode;

    do
    {
        cout << "[1] Settings" << endl;
        cout << "[2] Generate" << endl;
        cout << "[0] Exit" << endl;
        cin >> menuOperationCode;
        cout << endl;

        switch(menuOperationCode)
        {
        case 1:
            settings();
            break;
        case 2:
            generate();
            break;
        case 0:
            exit = true;
            break;
        default:
            cout << "ERROR! An unknown operation code has been entered! Please try again." << endl << endl;
            break;
        }
        cin.clear();
        cin.sync();
    }while(exit != true);
}



int main()
{
    cout << "  +----------------------------------+" << endl;
    cout << "  |    PROMOTION CODES GENERATOR     |" << endl;
    cout << "  |  Developed by Rafal Lewandowski  |" << endl;
    cout << "  |              ver. 1.0            |" << endl;
    cout << "  +----------------------------------+" << endl;
    cout << endl << endl;

    menu();

    return 0;
}
