// HashTable.h

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>

using namespace std;

#define TABLE_SIZE 13

class HashTable {
 public:
    /*Constructor
     Pre:none.
     Post: Creates an empty table.
     */
    HashTable();
    
    
    /*Destructor
     Pre:none.
     Post: free memory
     */
    ~HashTable();
    
    
    /*insert()
     Pre: s is a type of string.
     Post: inserts a string s into the hash table.
     */
    void insert(const string& s);
    
    
    /*Operator
     Pre: none
     Post: Overloaded assigment operator.
     */
    friend ostream& operator << (ostream& out, const HashTable& hashtable);
    
 private:
    vector<list<string>> hash;
};


/*Constructor
 Pre:none.
 Post: Creates an empty table.
 */
HashTable::HashTable()
    :hash(TABLE_SIZE)
{
    
}

/*Destructor
 Pre:none.
 Post: free memory
 */
HashTable::~HashTable()
{
    
}


/*insert()
 Pre: s is type of string.
 Post: inserts a string s into the hash table.
 */
void HashTable::insert(const string& s)
{
    int index = 0;
    
    if(s.length() == 1)
    {
        index = ((int)s[0]) % TABLE_SIZE;
    }
    
    else if (s.length() == 2)
    {
        index = ((int)s[0] + (int)s[1]) % TABLE_SIZE;
    }
    
    else
    {
        index = ((int)s[0] + (int)s[1]+(int)s[2]) % TABLE_SIZE;
    }
    
    hash[index].push_front(s);
}


/*Operator
 Pre: none
 Post: Overloaded assigment operator.
 */
ostream& operator << (ostream& out, const HashTable& hashtable)
{
    int index = 0;
    for(vector<list<string>>::const_iterator it_vector = hashtable.hash.begin(); it_vector != hashtable.hash.end(); it_vector++)
    {
        cout << "Index " << index << ":";
        for(list<string>::const_iterator it_list = it_vector->begin(); it_list != it_vector->end(); it_list++)
        {
            cout << " " << *it_list;
        }
        cout << endl;
        index ++;
    }
    return out;
}

#endif
