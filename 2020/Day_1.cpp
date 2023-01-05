#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

vector<int> readInput(string inputPath);
pair<int, int> getNumbers(vector<int> numbers);
int getAnswer(pair<int, int> numbers);

int main()
{
    // Declare input path
    string inputPath = "Inputs/Day_1_Input.txt";
    // Read from input and parse the contet of it
    vector<int> inputNumbers = readInput(inputPath);

    pair<int, int> numberPairs = getNumbers(inputNumbers);

    int answer = getAnswer(numberPairs);

    cout << answer << endl;

    return 0;
}

vector<int> readInput(string inputPath)
{
    // Create Input File Stream and construct it with the Input's Path
    ifstream fileStream(inputPath);
    // Create a Temporary String to load the current input line into it
    string tempInput = "";
    // Create an Integer Vector to store the input lines as numbers
    vector<int> numbers{};

    if (fileStream.is_open() == true)
    {
        while (fileStream)
        {
            // Read the current input line and load it into tempInput
            getline(fileStream, tempInput);
            // Parse the current input line and add it to the numbers vector
            numbers.push_back(stoi(tempInput, nullptr, 10));
        }
    }

    return numbers;
}

pair<int, int> getNumbers(vector<int> numbers)
{
    pair<int, int> answer{0, 0};

    for (size_t firstIndex = 0; firstIndex < numbers.size(); firstIndex++)
    {
        for (size_t secondIndex = 0; secondIndex < numbers.size(); secondIndex++)
        {
            if (numbers.at(firstIndex) + numbers.at(secondIndex) == 2020)
            {
                answer.first = numbers.at(firstIndex);
                answer.second = numbers.at(secondIndex);
            }
        }
    }

    return answer;
}

int getAnswer(pair<int, int> numbers)
{
    return numbers.first * numbers.second;
}
