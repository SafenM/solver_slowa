#ifndef DICTIONARY
#define DICTIONARY

#include <iostream>
#include <string>
#include <fstream>
#include "trie.hpp"

class Dictionary {
    public:
    Dictionary(std::string filename)
    {
    this->filename = filename;
    this->root = createTrie();
    std::string line;
    std::ifstream myfile (filename);
    if (myfile.is_open())
        {
        while ( getline (myfile,line) )
            {
            insert(root, line);
            }
        myfile.close();
        }
    else
        {
        std::cout << "Unable to open file slowa.txt\n";
        }
    }

    ~Dictionary()
    {
    deleteTrie(root);
    //std::cout << "Dictionary deleted" << std::endl;
    }

    bool wordExists(std::string word) const
    {
    return search(root, word);
    }

    bool prefixExists(std::string prefix) const
    {
    return startsWith(root, prefix);
    }

    private:
    std::string filename;
    Trie *root;
};

#endif