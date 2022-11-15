// WordleSolver.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <list>
#include <fstream>
#include <string>
#include <iomanip>      // std::setprecision
#include <algorithm>
#include <cctype>
using namespace std;

const int MIN_CHAR_INT = 'a', MAX_CHAR_INT = 'z';

list<string> fiveLetters;

bool onlyAtoZ(string* s)
{
    
    for (auto it = s->begin(); it != s->end(); it++)
    {
        int char_int = *it;
        if (char_int < MIN_CHAR_INT || char_int > MAX_CHAR_INT) return false;
    }
    return true;
}

bool noRepeatingLetters(string* s)
{
    string seenLetters = "";
    for (auto it = s->begin(); it != s->end(); it++)
    {
        char letter = *it;
        if (seenLetters.find(letter) != string::npos)
        {
            return false;
        }
        seenLetters += letter;
    }
    return true;
}

void add(string myText)
{ 
    // add to list and output only 5 letter words with no punctuation
    if (myText.length() == 5 && onlyAtoZ(&myText) && noRepeatingLetters(&myText))
    {
        fiveLetters.push_back(myText);
        cout << myText << endl;
    }
}

void toLower(string* s)
{
    transform(s->begin(), s->end(), s->begin(),
        [](unsigned char c) { return std::tolower(c); });
}

int main()
{
    time_t start, end;
    
    ifstream MyFile("words.txt");
    string myText;
    time(&start);
    while (getline(MyFile, myText)) {
        toLower(&myText);
        add(myText);
    }
    time(&end);
    // Calculating total time taken by the program.
    double time_taken = double(end - start);
    cout << "Time taken by program is : " << fixed
        << time_taken << setprecision(5);
    cout << " sec " << endl;
    return 0;
}

