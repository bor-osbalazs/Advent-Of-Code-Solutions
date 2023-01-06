#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

vector<int> readInput(string inputPath);
vector<int> getNumbers(vector<int> numbers, bool returnTwoNumbers);
int getAnswer(vector<int> numbers);

int main()
{
    // Declare input path
    string inputPath = "Inputs/Day_1_Input.txt";
    // Read from input and parse the contet of it
    vector<int> inputNumbers = readInput(inputPath);

    vector<int> twoNumberCombination = getNumbers(inputNumbers, true);
    vector<int> threeNumberCombination = getNumbers(inputNumbers, false);

    int twoNumberAnswer = getAnswer(twoNumberCombination);
    int threeNumberAnswer = getAnswer(threeNumberCombination);

    cout << "Answer with 2 numbers: " << twoNumberAnswer << endl;
    cout << "Answer with 3 numbers: " << threeNumberAnswer << endl;

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

vector<int> getNumbers(vector<int> numbers, bool returnTwoNumbers)
{
    vector<int> answer;

    if(returnTwoNumbers == true)
    {
        for (size_t firstIndex = 0; firstIndex < numbers.size(); firstIndex++)
        {
            for (size_t secondIndex = 0; secondIndex < numbers.size(); secondIndex++)
            {
                if (numbers.at(firstIndex) + numbers.at(secondIndex) == 2020)
                {
                    answer.push_back(numbers.at(firstIndex));
                    answer.push_back(numbers.at(secondIndex));

                    return answer;
                }
            }
        }
    }
    else
    {
        for (size_t firstIndex = 0; firstIndex < numbers.size(); firstIndex++)
        {
            for (size_t secondIndex = 0; secondIndex < numbers.size(); secondIndex++)
            {
                for (size_t thirdIndex = 0; thirdIndex < numbers.size(); thirdIndex++)
                {
                    if (numbers.at(firstIndex) + numbers.at(secondIndex) + numbers.at(thirdIndex) == 2020)
                    {
                        answer.push_back(numbers.at(firstIndex));
                        answer.push_back(numbers.at(secondIndex));
                        answer.push_back(numbers.at(thirdIndex));

                        return answer;
                    }
                }
            }
        }
    }

    return answer;
}

int getAnswer(vector<int> numbers)
{
    int numberToReturn = 1;

    for (size_t index = 0; index < numbers.size(); index++)
    {
        numberToReturn *= numbers.at(index);
    }
    
    return numberToReturn;
}