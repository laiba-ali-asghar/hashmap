#ifndef HASHTABLE_LAIBA_H
#define HASHTABLE_LAIBA_H

#include <iostream>
#include <string>

using namespace std;
class HashTable
{
private:
    string *table;
    int S; // Table size
    int n; // Current number of elements
public:
    HashTable(int size)
    {
        S = size;
        n = 0;
        table = new string[size];
        for (int i = 0; i < S; i++)
        {
            table[i] = "/";
        }
    }
    ~HashTable()
    {
        delete table;
    }
    bool isEmpty() // Checks whether the hash table is empty or not
    {
        if (S == 0)
        {
            return true;
        }
        return false;
    }
    bool isFull() // Checks whether the hash table is full or not
    {
        if (this->S == n)
        {
            return true;
        }
        return false;
    }
    double loadFactor() // Calculates & returns the load factor of the hash table (n/S)
    {
        return n / S;
    }
    int getHashValue(string name)
    {
        int sum = 0;
        char c;
        for (int i = 0; i < name.length(); i++)
        {
            c = name[i];
            sum = sum + int(c);
        }
        return sum;
    }
    bool insert(string name)
    {
        if (S == n)
        {
            // if the full
            return false;
        }
        else
        {
            int index = getHashValue(name);
            index = index % S;
            if (table[index] != "/")
            {
                table[index] = name;
                n++;
                return true;
            }
            else
            {
                cout << "the treversed indexs r :";
                int ind = 1;
                for (int i = index; i < S; i++)
                {

                    if (table[ind + i] == "/")
                    {
                        table[ind+i] = name;
                        n++;
                        return true;
                    }
                    else
                    {
                        cout << ind + i<<" ";
                    }
                }
                for (int i = 0; i < index; i++)
                {

                    if (table[ i] == "/")
                    {
                        table[i] = name;
                        n++;
                        return true;
                    }
                    else
                    {
                        cout <<  i<<" ";
                    }
                }
            }
        }
        return false;
    }
    bool search(string name)
    {
        int index = getHashValue(name);
        index = index % S;
        if (table[index] == name)
        {
            return true;
        }
        else
        {
            int ind = 1;
            for (int i = index; i < S; i++)
            {

                if (table[ind + i] == name)
                {

                    return true;
                }
            }
            for (int i = 0; i < index; i++)
            {

                if (table[ind + i] == name)
                {

                    return true;
                }
            }
        }
        return false;
    }
    bool remove(string name)
    {
        int index = getHashValue(name);
        index = index % S;
        if (table[index] == name)
        {
            n--;
            table[index] = "/";
            return true;
        }
        else
        {
            int ind = 1;
            for (int i = index; i < S; i++)
            {

                if (table[ind + i] == name)
                {
                    table[ind+i] = "/";
                    n--;
                    return true;
                }
            }
            for (int i = 0; i < index; i++)
            {

                if (table[ind + i] == name)
                {
                    table[ind+i] = "/";
                    n--;
                    return true;
                }
            }
        }
        return false;
    }
    void display()
    {
        for(int i=0;i<S;i++)
        {
            if(table[i]!="/")
            {
                cout<<table[i]<<"  ";
            }
        }
    }
// int indexHelper(string name)
// {
//     int 
// }
};


#endif