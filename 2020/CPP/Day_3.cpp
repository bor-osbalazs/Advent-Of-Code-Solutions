#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

vector<string> ReadInput(string inputPath);
int GetTreeCount(vector<string> inputLines, string slopeType, int downNumber);
int GetCurrentIndex(int currentIndex, int lineLength, string slopeType);
long GetMultipleSlopeAnswer(vector<string> inputLines);

int main(int argc, char const *argv[])
{
    string inputPath = "Inputs/Day_3_Input.txt";

    vector<string> inputLines = ReadInput(inputPath);

    // Day 3 Part 1 Answer
    int treeCounter = GetTreeCount(inputLines, "r3", 1);
    cout << treeCounter << endl;

    // Day 3 Part 2 Answer
    long slopeTreeCounter = GetMultipleSlopeAnswer(inputLines);
    cout << slopeTreeCounter << endl;

    return 0;
}

vector<string> ReadInput(string inputPath)
{
    ifstream inputStream = ifstream(inputPath);
    vector<string> inputLines{};

    if (inputStream.is_open() == true)
    {
        while (inputStream.good() == true)
        {
            string currentLine = "";

            getline(inputStream, currentLine);

            inputLines.push_back(currentLine);
        }
    }

    return inputLines;
}

int GetTreeCount(vector<string> inputLines, string slopeType, int downNumber)
{
    int treeCounter = 0;
    int currentIndex = 0;
    int lineCounter = 0;

    for (string currentLine : inputLines)
    {
        if (downNumber == 1)
        {
            if (currentLine[currentIndex] == '#')
            {
                treeCounter++;
            }
            // Change after every line
            currentIndex = GetCurrentIndex(currentIndex, inputLines.at(0).length(), slopeType);
        }
        else if (downNumber == 2)
        {
            if (lineCounter % 2 == 0 && currentLine[currentIndex] == '#')
            {
                treeCounter++;
            }

            // CurrentIndex MUST be inside the if statement because it changes after every two lines: right 1, down 2.
            if (lineCounter % 2 == 0)
            {
                currentIndex = GetCurrentIndex(currentIndex, inputLines.at(0).length(), slopeType);
            }
        }

        lineCounter++;
    }

    return treeCounter;
}

int GetCurrentIndex(int currentIndex, int lineLength, string slopeType)
{
    if (slopeType == "r1")
    {
        if (currentIndex == lineLength - 1)
        {
            currentIndex = 0;
        }
        else
        {
            currentIndex++;
        }
    }
    else if (slopeType == "r3")
    {
        if (currentIndex == lineLength - 1)
        {
            currentIndex = 2;
        }
        else if (currentIndex == lineLength - 2)
        {
            currentIndex = 1;
        }
        else if (currentIndex == lineLength - 3)
        {
            currentIndex = 0;
        }
        else
        {
            currentIndex += 3;
        }
    }
    else if (slopeType == "r5")
    {
        if (currentIndex == lineLength - 1)
        {
            currentIndex = 4;
        }
        else if (currentIndex == lineLength - 2)
        {
            currentIndex = 3;
        }
        else if (currentIndex == lineLength - 3)
        {
            currentIndex = 2;
        }
        else if (currentIndex == lineLength - 4)
        {
            currentIndex = 1;
        }
        else if (currentIndex == lineLength - 5)
        {
            currentIndex = 0;
        }
        else
        {
            currentIndex += 5;
        }
    }
    else if (slopeType == "r7")
    {
        if (currentIndex == lineLength - 1)
        {
            currentIndex = 6;
        }
        else if (currentIndex == lineLength - 2)
        {
            currentIndex = 5;
        }
        else if (currentIndex == lineLength - 3)
        {
            currentIndex = 4;
        }
        else if (currentIndex == lineLength - 4)
        {
            currentIndex = 3;
        }
        else if (currentIndex == lineLength - 5)
        {
            currentIndex = 2;
        }
        else if (currentIndex == lineLength - 6)
        {
            currentIndex = 1;
        }
        else if (currentIndex == lineLength - 7)
        {
            currentIndex = 0;
        }
        else
        {
            currentIndex += 7;
        }
    }

    return currentIndex;
}

long GetMultipleSlopeAnswer(vector<string> inputLines)
{
    int slopeOne = GetTreeCount(inputLines, "r1", 1); // 53
    int slopeTwo = GetTreeCount(inputLines, "r3", 1); // 282
    int slopeThree = GetTreeCount(inputLines, "r5", 1); // 54
    int slopeFour = GetTreeCount(inputLines, "r7", 1); // 54
    int slopeFive = GetTreeCount(inputLines, "r1", 2); // 22

    return slopeOne * slopeTwo * slopeThree * slopeFour * slopeFive;
}