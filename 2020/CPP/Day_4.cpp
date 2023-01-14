#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cctype>

using namespace std;

vector<string> ReadInput(string inputPath);
int GetValidPassportCount(vector<string> inputLines, bool ignoreCid);
string GetValue(string currentLine, string dataToFind);
bool IsValid(string dataType, string dataValue);
bool IsEveryCharacterHex(string line);
bool IsEveryCharacterNum(string line);
int ConvertToInt(string line);

int main()
{
    string inputPath = "Inputs/Day_4_Input.txt";
    vector<string> inputLines = ReadInput(inputPath);

    int validPassportCount = GetValidPassportCount(inputLines, true);

    cout << validPassportCount << endl;

}

vector<string> ReadInput(string inputPath)
{
    ifstream fileStream = ifstream(inputPath);
    string tempLine = "";
    string currentLine = "";
    vector<string> returnVector;

    if (fileStream.is_open() == true)
    {
        while (fileStream.good() == true)
        {
            getline(fileStream, tempLine);

            if (tempLine != "")
            {
                currentLine += tempLine + " ";
            }
            else
            {
                returnVector.push_back(currentLine);
                currentLine = "";
            }
        }
        // To add the last line to the vector because the file doesn't end in an empty new line
        returnVector.push_back(currentLine);
    }

    return returnVector;
}

int GetValidPassportCount(vector<string> inputLines, bool ignoreCid)
{
    int validPassportCounter = 0;

    for (string line : inputLines)
    {
        // Birth Year
        string valueByr = GetValue(line, "byr");
        bool isPresentByr = valueByr != "X";
        bool isValidByr = IsValid("byr", valueByr);

        // Issue Year
        string valueIyr = GetValue(line, "iyr");
        bool isPresentIyr = valueIyr != "X";
        bool isValidIyr = IsValid("iyr", valueIyr);
        
        // Expiration Year
        string valueEyr = GetValue(line, "eyr");
        bool isPresentEyr = valueEyr != "X";
        bool isValidEyr = IsValid("eyr", valueEyr);

        // Height
        string valueHgt = GetValue(line, "hgt");
        bool isPresentHgt = valueHgt != "X";
        bool isValidHgt = IsValid("hgt", valueHgt);

        // Hair Color
        string valueHcl = GetValue(line, "hcl");
        bool isPresentHcl = valueHcl != "X";
        bool isValidHcl = IsValid("hcl", valueHcl);

        // Eye color
        string valueEcl = GetValue(line, "ecl");
        bool isPresentEcl = valueEcl != "X";
        bool isValidEcl = IsValid("ecl", valueEcl);

        // Passport ID
        string valuePid = GetValue(line, "pid");
        bool isPresentPid = valuePid != "X";
        bool isValidPid = IsValid("pid", valuePid);

        // Country ID
        bool isPresentCid = GetValue(line, "cid") != "X";

        if (ignoreCid == true && isPresentByr == true && isPresentIyr == true && isPresentEyr == true && isPresentHgt == true &&
                                 isPresentHcl == true && isPresentEcl == true && isPresentPid == true &&
                                 isValidByr == true && isValidIyr == true && isValidEyr == true && isValidHgt == true &&
                                 isValidHcl == true && isValidEcl == true && isValidPid == true)
        {
            validPassportCounter++;
        }
        else if (ignoreCid == false && isPresentByr == true && isPresentIyr == true && isPresentEyr == true && isPresentHgt == true &&
                                       isPresentHcl == true && isPresentEcl == true && isPresentPid == true && isPresentCid == true &&
                                       isValidByr == true && isValidIyr == true && isValidEyr == true && isValidHgt == true &&
                                       isValidHcl == true && isValidEcl == true && isValidPid == true)
        {
            validPassportCounter++;
        }
    }

    return validPassportCounter;
}

string GetValue(string currentLine, string dataToFind)
{
    string returnValue = "";
    size_t something = 0;

    something = currentLine.find(dataToFind);

    if (something != 4294967295)
    {
        for (size_t index = something; index < currentLine.length(); index++)
        {
            if (currentLine[index] != ' ')
            {
                returnValue += currentLine[index];
            }
            else
            {
                returnValue = returnValue.substr(4, 256);
                break;
            }
        }
    }
    else
    {
        returnValue = "X";
    }

    return returnValue;
}

bool IsValid(string dataType, string dataValue)
{
    string tempString = dataValue;

    if (dataType == "byr" && dataValue.length() == 4 && stoi(dataValue, nullptr, 10) >= 1920 && stoi(dataValue, nullptr, 10) <= 2002)
    {
        return true;
    }
    else if (dataType == "iyr" && dataValue.length() == 4 && stoi(dataValue, nullptr, 10) >= 2010 && stoi(dataValue, nullptr, 10) <= 2020)
    {
        return true;
    }
    else if (dataType == "eyr" && dataValue.length() == 4 && stoi(dataValue, nullptr, 10) >= 2020 && stoi(dataValue, nullptr, 10) <= 2030)
    {
        return true;
    }
    else if (dataType == "hgt" && dataValue.find("cm") != string::npos && ConvertToInt(tempString.substr(0, dataValue.find("cm"))) >= 150 &&
                                                                          ConvertToInt(tempString.substr(0, dataValue.find("cm"))) <= 193 || 
                                  dataValue.find("in") != string::npos && ConvertToInt(tempString.substr(0, dataValue.find("in"))) >= 59 &&
                                                                          ConvertToInt(tempString.substr(0, dataValue.find("in"))) <= 76)
    {
        return true;
    }
    else if (dataType == "hcl" && dataValue[0] == '#' && dataValue.length() == 7 && IsEveryCharacterHex(dataValue) == true)
    {
        return true;
    }
    else if (dataType == "ecl" && (dataValue == "amb" || dataValue == "blu" || dataValue == "brn" ||  dataValue == "gry" || 
                                   dataValue == "grn" || dataValue == "hzl" || dataValue == "oth"))
    {
        return true;
    }
    else if (dataType == "pid" && dataValue.length() == 9 && IsEveryCharacterNum(dataValue))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool IsEveryCharacterHex(string line)
{
    bool isHex = false;

    for (char character : line)
    {
        if (character == '#' || isxdigit(character) != 0)
        {
            isHex = true;
        }
        else
        {
            isHex = false;
            break;
        }
    }

    return isHex;
}

bool IsEveryCharacterNum(string line)
{
    bool isNum = false;

    for (char character : line)
    {
        if (isdigit(character) != 0)
        {
            isNum = true;
        }
        else
        {
            isNum = false;
            break;
        }
    }

    return isNum;
}

int ConvertToInt(string line)
{
    if (IsEveryCharacterNum(line) == true)
    {
        return stoi(line, nullptr, 10);
    }
    else
    {
        return 0;
    }
}