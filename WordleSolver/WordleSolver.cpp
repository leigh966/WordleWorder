// WordleSolver.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "WordleSolver.hpp"
using namespace std;

const int MIN_CHAR_INT = 'a', MAX_CHAR_INT = 'z';

list<string> fiveLetters;
list<uint32_t> bins;



bool areDifferent(uint32_t bin1, uint32_t bin2)
{
    return (bin1 & bin2) == 0;
}

void outputWordsForBinaries(uint32_t* chosenBins, int length)
{
    for (int i = 0; i < length; ++i)
    {
        uint32_t bin = *(chosenBins + i);
        string word;
        int index = 0;
        for (auto it = bins.begin(); it != bins.end(); it++)
        {
            if (*it == bin)
            {
                auto newIt = fiveLetters.begin();
                advance(newIt, index);
                word = *newIt;
                break;
            }
            ++index;
        }
        cout << word << ", ";
    }
    cout << endl;
}
const uint32_t ALL_WORDS_MUST_HAVE = 263195; // aeiouy - every word needs at least one
const int GOAL_NUM_WORDS = 5;
bool findDifferentWordBinaries(uint32_t thisWordBin, uint32_t output[5], uint32_t* numFound, int startIndex, uint32_t filter = 0)
{
    filter |= thisWordBin;
    output[*numFound] = thisWordBin;
    (*numFound)++;
    
    if (*numFound == GOAL_NUM_WORDS)
    {
        return false;
    }

    bool impossible = (filter & ALL_WORDS_MUST_HAVE) == filter; //If all of the necissary letters are already taken
    if (impossible) return true;
    //outputWordsForBinaries(output, *numFound); // debug
    cout << "."; // speed
    int index = startIndex;
    auto it = bins.begin();

    
    for (advance(it, index); it != bins.end(); ++it)
    {      
        if (areDifferent(filter, *it))
        {
            bool bad = findDifferentWordBinaries(*it, output, numFound, index, filter);
            if (bad) (*numFound)--;
            else
            {
                return false;
            }
            
        }
        index++;
        
    }
    return true;
}


void searchWord(uint32_t wordBin)
{
    cout << "\nSearching...";
    uint32_t output[GOAL_NUM_WORDS];
    uint32_t numFound = 0;
    findDifferentWordBinaries(wordBin, output, &numFound, 0);
    if (numFound == GOAL_NUM_WORDS)
    {
        outputWordsForBinaries(output, numFound);
    }
}

void search()
{
    for (auto it = bins.begin(); it != bins.end(); ++it)
    {
        searchWord( *it);
    }

}

bool binaryTaken(uint32_t bin)
{
    for (auto it = bins.begin();it != bins.end();++it)
    {
        if (bin == *it) return true;
    }
    return false;
}

uint32_t getLetterIndex(char letter)
{
    
    // letters ordered by frequency in the oxford dictionary
    //      source: http://letterfrequency.org/
    const int NUM_LETTERS = 26;
    char letters[NUM_LETTERS] = { 'e', 'a', 'r', 'i', 'o', 't','n', 's', 'l', 'c', 'u', 'd', 'p', 'm', 'h','g', 'b', 'f',
        'y', 'w', 'k', 'v', 'x', 'z', 'j', 'q' };
    for (int i = 0; i < NUM_LETTERS; i++)
    {
        if (letter == letters[i]) return i;
    }
    const string INVALID_LETTER_MESSAGE = (string)"Unrecognised character " + letter + " in word!";
    throw(INVALID_LETTER_MESSAGE);
}

uint32_t binaryRep(string* s)
{
    uint32_t rep = 0;
    for (auto it = s->begin(); it != s->end(); ++it)
    {
        rep |= 1UL << getLetterIndex(*it);
    }

    return rep;
}


bool onlyAtoZ(string* s)
{
    
    for (auto it = s->begin(); it != s->end(); ++it)
    {
        int char_int = *it;
        if (char_int < MIN_CHAR_INT || char_int > MAX_CHAR_INT) return false;
    }
    return true;
}

bool noRepeatingLetters(string* s)
{
    string seenLetters = "";
    for (auto it = s->begin(); it != s->end(); ++it)
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
    cout << ".";
    // add to list and output only 5 letter words with no punctuation
    if (myText.length() == 5 && onlyAtoZ(&myText) && noRepeatingLetters(&myText))
    {
        uint32_t binRep = binaryRep(&myText);
        if (!binaryTaken(binRep))
        {
            fiveLetters.push_back(myText);
            bins.push_back(binRep);
        }
    }
}

void toLower(string* s)
{
    transform(s->begin(), s->end(), s->begin(),
        [](unsigned char c) { return std::tolower(c); });
}

void outputRuntime(time_t start, time_t end)
{
    // Calculating total time taken by the program.
    double time_taken = double(end - start);
    cout << "Time taken by program is : " << fixed
        << time_taken << setprecision(5);
    cout << " sec " << endl;
}



int main()
{
    time_t start, end;
    ifstream MyFile("words.txt");
    string myText;
    time(&start);
    cout << "Reading...";
    while (getline(MyFile, myText)) {
        toLower(&myText);
        try {
            add(myText);
        }
    
    catch (string s)
    {
        cout << s << endl;
        return -1;
    }
    }
    

    search();

    time(&end);

    outputRuntime(start, end);
    return 0;
}

