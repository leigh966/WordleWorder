// WordleSolver.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <list>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    cout << "Hello World!\n";
    ifstream MyFile("words.txt");
    string myText;
    while (getline(MyFile, myText)) {
        // Output the text from the file
        cout << myText << endl;
    }
}

