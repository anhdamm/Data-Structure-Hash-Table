#include <iostream>
#include "HashTable.h"

using namespace std;

int main()
{
    fstream inFile;
    string input;
    HashTable hash;
    cout << "Enter a file name: ";
    cin >> input;
    cout << "Here is your hash table: " << endl;
    
    inFile.open(input);
    if(!inFile)
    {
        cout << "Cannot open the file" << endl;
        exit(1);
    }
    
    if(inFile.is_open())
    {
        while(!inFile.eof())
        {
            inFile >> input;
            hash.insert(input);
        }
        
        cout << hash;
        inFile.close();
    }
}
