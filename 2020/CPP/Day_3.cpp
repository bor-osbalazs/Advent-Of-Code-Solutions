#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

vector<string> ReadInput(string inputPath);
int GetTreeCount(vector<string> inputLines);
int GetCurrentIndex(int currentIndex, int lineLength);

int main(int argc, char const *argv[])
{
    string inputPath = "Inputs/Day_3_Input.txt";

    vector<string> inputLines = ReadInput(inputPath);

    int treeCounter = GetTreeCount(inputLines);

    cout << treeCounter << endl;

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

int GetTreeCount(vector<string> inputLines)
{
    int treeCounter = 0;
    int currentIndex = 0;

    for (string currentLine : inputLines)
    {
        if (currentLine[currentIndex] == '#')
        {
            treeCounter++;
        }

        currentIndex = GetCurrentIndex(currentIndex, inputLines.at(0).length());
    }

    return treeCounter;
}

int GetCurrentIndex(int currentIndex, int lineLength)
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

    return currentIndex;
}