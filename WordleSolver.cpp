// WordleSolver.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <list>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    list<string> fiveLetters;
    ifstream MyFile("words.txt");
    string myText;

    while (getline(MyFile, myText)) {
        // Output the text from the file
        if (myText.length() == 5)
        {
            fiveLetters.push_back(myText);
            cout << myText << endl;
        }     
    }
}

