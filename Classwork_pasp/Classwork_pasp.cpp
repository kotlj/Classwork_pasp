
#include <iostream>

enum sex
{
    Male,
    Female
};
class Passport
{
protected:
    int _date;
    int _born;
    int _code;
    char* _firstName;
    char* _secondName;
    char* _adres;
    sex _sx;
private:
    char* _thirdName;
public:
    Passport()
    {
        _date = 0;
        _born = 0;
        _code = 0;
        _firstName = nullptr;
        _secondName = nullptr;
        _thirdName = nullptr;
        _adres = nullptr;
        _sx = sex(1);
    }
    Passport(int date,  int born, int code, char* firstName, char* secondName, char* thirdName, char* adres, sex sx)
    {
        _born = born;
        _code = code;
        _date = date;
        _firstName = new char[strlen(firstName) + 1];
        _firstName[strlen(firstName)] = '\0';
        for (int i = 0; i < strlen(firstName); i++)
        {
            _firstName[i] = firstName[i];
        }
        _secondName = new char[strlen(secondName) + 1];
        _secondName[strlen(firstName)] = '\0';
        for (int i = 0; i < strlen(secondName); i++)
        {
            _secondName[i] = secondName[i];
        }
        _thirdName = new char[strlen(thirdName)];
        _thirdName[strlen(firstName)] = '\0';
        for (int i = 0; i < strlen(thirdName); i++)
        {
            _thirdName[i] = thirdName[i];
        }
        _adres = new char[strlen(adres) + 1];
        _adres[strlen(adres)] = '\0';
        for (int i = 0; i < strlen(adres); i++)
        {
            _adres[i] = adres[i];
        }
        _sx = sx;
        std::cout << "PASSCUNSTRUCT\n";
    }

    void show_Name(char* name)
    {
        for (int i = 0; name[i] != '\0'; i++)
        {
            std::cout << name[i];
        }
        std::cout << '\n';
    }
    void show()
    {
        std::cout << "First name: ";
        show_Name(_firstName);
        std::cout << "Second name: ";
        show_Name(_secondName);
        std::cout << "Third name: ";
        show_Name(_thirdName);
        std::cout << "Adres: ";
        show_Name(_adres);
        std::cout << "Date: " << _date << '\n' << "Born: " << _born << '\n' << "Code: " << _code << '\n' <<
            "Sex: " << (_sx == 0 ? "Male" : "Female") << '\n';
    }

    ~Passport()
    {
        if (_firstName != nullptr)
        {
            delete[] _firstName;
        }
        if (_secondName != nullptr)
        {
            delete[] _secondName;
        }
        if (_thirdName != nullptr)
        {
            delete[] _thirdName;
        }
        if (_adres != nullptr)
        {
            delete[] _adres;
        }
        std::cout << "PASSDESTRUCT\n";
    }
};

class ForeignPassport : public Passport
{
private:
    Passport pass;
    int _activDue;
    int _frCode;

public:
    ForeignPassport(int date, int born, int code, char* firstName, 
        char* secondName, char* thirdName, char* adres, sex sx, int activeDue, int frCode): Passport(date, born, code, firstName, secondName, thirdName, adres, sx)
    {
        _activDue = activeDue;
        _frCode = frCode;
        std::cout << "FRCONSTRUCT\n";
    }

    void show()
    {
        Passport::show();
        std::cout << "Active due: " << _activDue << '\n' << "Foreign code: " << _frCode << '\n';
    }

    ~ForeignPassport()
    {
        std::cout << "FRDESTRUCT\n";
    }
};

int main()
{
    int size = 10;
    char* str = new char[size];
    str[size - 1] = '\0';
    for (int i = 0; i < size - 1; i++)
    {
        str[i] = 'A';
    }
    ForeignPassport test(1, 1, 1, str, str, str, str, sex(1), 2, 2);
    test.show();
    if (str != nullptr)
    {
        delete[] str;
    }
}