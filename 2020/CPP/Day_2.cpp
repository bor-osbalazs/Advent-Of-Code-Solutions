#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<string> ReadInput(string inputPath);
int GetCorrectPasswordCount(vector<string> inputLines);
int GetMinimumOccurrence(string line);
int GetMaximumOccurrence(string line);
string GetPassword(string line);
string GetPasswordCharacter(string line);
bool IsValidPassword(string password, int minOccurrence, int maxOccurrence, string passwordCharacter);

int main()
{
    // Declare input's path
    string inputPath = "Inputs/Day_2_Input.txt";
    // Read the input file
    vector<string> inputLines = ReadInput(inputPath);
    // Get the correct passwords count (first part answer)
    int correctPasswordsCount = GetCorrectPasswordCount(inputLines);

    cout << "The valid password count is: " << correctPasswordsCount << endl;

    return 0;
}

vector<string> ReadInput(string inputPath)
{
    // Initilaize Input File Stream with the input path
    ifstream inputStream = ifstream(inputPath);
    // Initilaize the string vector that we return
    vector<string> inputLines{};

    if(inputStream.is_open() == true)
    {
        string currentInputLine;

        while (inputStream.good() == true)
        {
            getline(inputStream, currentInputLine);

            inputLines.push_back(currentInputLine);
        }
    }

    return inputLines;
}

int GetCorrectPasswordCount(const vector<string> inputLines)
{
    int minOccurrence = 0;
    int maxoccurrence = 0;
    string password = "";
    string passwordCharacter = "";

    int validCounter = 0;

    for (string currentLine : inputLines)
    {
        minOccurrence = GetMinimumOccurrence(currentLine);
        maxoccurrence = GetMaximumOccurrence(currentLine);
        password = GetPassword(currentLine);
        passwordCharacter = GetPasswordCharacter(currentLine);

        if(IsValidPassword(password, minOccurrence, maxoccurrence, passwordCharacter) == true)
        {
            validCounter++;
        }
    }

    return validCounter;
}

int GetMinimumOccurrence(string line)
{
    int minimumOccurence = 0;

    stringstream currentLine {line};
    string currentSegment;
    vector<string> segmentList;

    // Seperate the first number from the rest of the string
    while(getline(currentLine, currentSegment, '-'))
    {
        segmentList.push_back(currentSegment);
    }

    minimumOccurence = stoi(segmentList.at(0), nullptr, 10);

    return minimumOccurence;
}

int GetMaximumOccurrence(string line)
{
    int maximumOccurrence = 0;

    stringstream currentLine {line};
    string currentSegment;
    vector<string> segmentList;

    // Seperate the first number from the rest of the string
    while(getline(currentLine, currentSegment, '-'))
    {
        segmentList.push_back(currentSegment);
    }

    // Clear the string in stringstream
    currentLine.str("");
    // Clear the error state in stringstream
    currentLine.clear();
    // Add the second segment to the stringstream after the first number and '-' was cut from the input
    currentLine << segmentList.at(1);
    // Clear the segmentList vector to use again
    segmentList.clear();

    // Seperate the second number from the rest of the string
    while(getline(currentLine, currentSegment, ' '))
    {
        segmentList.push_back(currentSegment);
    }

    maximumOccurrence = stoi(segmentList.at(0), nullptr, 10);    

    return maximumOccurrence;
}

string GetPasswordCharacter(string line)
{
    string passwordCharacter = "";

    stringstream currentLine {line};
    string currentSegment;
    vector<string> segmentList;

    // Seperate the first number from the rest of the string
    while(getline(currentLine, currentSegment, '-'))
    {
        segmentList.push_back(currentSegment);
    }

    // Clear the string in stringstream
    currentLine.str("");
    // Clear the error state in stringstream
    currentLine.clear();
    // Add the second segment to the stringstream after the first number and '-' was cut from the input
    currentLine << segmentList.at(1);
    // Clear the segmentList vector to use again
    segmentList.clear();

    // Seperate the second number from the rest of the string
    while(getline(currentLine, currentSegment, ' '))
    {
        segmentList.push_back(currentSegment);
    }

    passwordCharacter = segmentList.at(1)[0];

    return passwordCharacter;
}

string GetPassword(string line)
{
    string password = "";

    stringstream currentLine {line};
    string currentSegment;
    vector<string> segmentList;

    // Seperate the first number from the rest of the string
    while(getline(currentLine, currentSegment, ' '))
    {
        segmentList.push_back(currentSegment);
    }

    password = segmentList.at(2);

    return password;
}

bool IsValidPassword(string password, int minOccurrence, int maxOccurrence, string passwordCharacter)
{
    bool isValid = false;
    int characterCounter = 0;

    for (char character : password)
    {
        if (character == passwordCharacter[0])
        {
            characterCounter++;
        }
    }

    if (characterCounter >= minOccurrence && characterCounter <= maxOccurrence)
    {
        isValid = true;
    }

    return isValid;
}