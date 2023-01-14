#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

vector<string> ReadInput(string inputPath);
int GetValidPassportCount(vector<string> inputLines, bool ignoreCid);
string GetValue(string currentLine, string dataToFind);

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
        bool isValidByr = GetValue(line, "byr") != "X"; // Birt Year
        bool isValidIyr = GetValue(line, "iyr") != "X"; // Issue Year
        bool isValidEyr = GetValue(line, "eyr") != "X"; // Expiration Year
        bool isValidHgt = GetValue(line, "hgt") != "X"; // Height
        bool isValidHcl = GetValue(line, "hcl") != "X"; // Hair Color
        bool isValidEcl = GetValue(line, "ecl") != "X"; // Eye color
        bool isValidPid = GetValue(line, "pid") != "X"; // Passport ID
        bool isValidCid = GetValue(line, "cid") != "X"; // Country ID

        if (ignoreCid == true && isValidByr == true && isValidIyr == true && isValidEyr == true && isValidHgt == true &&
            isValidHcl == true && isValidEcl == true && isValidPid == true)
        {
            validPassportCounter++;
        }
        else if (ignoreCid == false && isValidByr == true && isValidIyr == true && isValidEyr == true && isValidHgt == true &&
                 isValidHcl == true && isValidEcl == true && isValidPid == true && isValidCid == true)
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

                if (dataToFind == "hgt")
                {
                    returnValue = returnValue.substr(0, returnValue.find("cm"));
                }

                returnValue = "";
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