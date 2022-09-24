#ifndef TRIE
#define TRIE
#include <iostream>

int plIndex(char letter) //helper fuction for correct indieces
{
    if (letter == '¥') // first we use 'q', 'v', 'x' for polish letters
    {
        return 'q' - 'a';
    }
    else if (letter == '†')
    {
        return 'v' - 'a';
    }
    else if (letter == '©')
    {
        return 'x' - 'a';
    }
    else if (letter == 'ˆ') //we use higher indieces for rest of polish letters
    {
        return 26;
    }
    else if (letter == 'ä')
    {
        return 27;
    }
    else if (letter == '¢')
    {
        return 28;
    }
    else if (letter == '˜')
    {
        return 29;
    }
    else if (letter == '«')
    {
        return 30;
    }
    else if (letter == '¾')
    {
        return 31;
    }
    else
    {
        return letter - 'a';
    }
}

    struct Trie {
        bool isWord;
        Trie *children[32];
    };

Trie *createTrie()
{
    Trie *root = new Trie;
    root->isWord = false;
    for (int i = 0; i < 32; i++)
    {
        root->children[i] = nullptr;
    }
    return root;
}

void insert(Trie *root, std::string word)
{
    Trie *current = root;
    for (int i = 0; i < word.length(); i++)
    {
        int index = plIndex(word[i]);
        if (current->children[index] == nullptr)
        {
            current->children[index] = createTrie();
        }
        current = current->children[index];
    }
    current->isWord = true;
}

bool search(Trie *root, std::string word)
{
    Trie *current = root;
    for (int i = 0; i < word.length(); i++)
    {
        int index = plIndex(word[i]);
        if (current->children[index] == nullptr)
        {
            return false;
        }
        current = current->children[index];
    }
    return current->isWord;
}

bool startsWith(Trie *root, std::string prefix)
{
    Trie *current = root;
    for (int i = 0; i < prefix.length(); i++)
    {
        int index = plIndex(prefix[i]);
        if (current->children[index] == nullptr)
        {
            return false;
        }
        current = current->children[index];
    }
    return true;
}

void deleteTrie(Trie *root)
{
    for (int i = 0; i < 32; i++)
    {
        if (root->children[i] != nullptr)
        {
            deleteTrie(root->children[i]);
        }
    }
    delete root;
}

#endif