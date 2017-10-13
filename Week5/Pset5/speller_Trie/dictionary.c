/**
 * Implements a dictionary's functionality.
 * Using data struture Trie
 * Each Node specify a letter
 */

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include "dictionary.h"

/**
 * define an Trie Node Structure
 */
typedef struct _TrieNode
{
    struct _TrieNode *next[27]; // a - z and '
    bool isWord;
}
TrieNode;

/**
 * create and initialize a TrieNode
 */
TrieNode *create()
{
    TrieNode *node = malloc(sizeof(TrieNode));
    node->isWord = false;
    memset(node->next, 0, sizeof(node->next)); // set node->next to NULL
    return node;
}

/**
 * insert a word, start from root
 */
void insert(TrieNode *root, char *word)
{
    TrieNode *node = root;
    int index;
    while (*word)
    {
        if (isalpha(*word))
        {
            index = *word - (int)'a';
            if (node->next[index] == NULL)
            {
                node->next[index] = create();
            }
            node = node->next[index];
        }
        else // while *word is '
        {
            if (node->next[26] == NULL)
            {
                node->next[26] = create();
            }
            node = node->next[26];
        }
        word++; // point to next letter
    }
    node->isWord = true;  // at the end of the word set isWord to true
}

/**
 * delete a Trie Node recursivly
 * using pointer to pointer so that I can change the pass-in pointer
 */
void delete(TrieNode **node)
{
    for (int i = 0; i < 27; i++)
    {
        if ((*node)->next[i] != NULL)
        {
            delete(&((*node)->next[i]));
        }
    }
    free(*node);
    *node = NULL;
}

// Global Variable
TrieNode *ROOT;
unsigned int SIZE = 0;

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char *word)
{
    TrieNode *node = ROOT;
    int index;
    while (*word)
    {
        char letter = tolower(*word);
        if (isalpha(letter))
        {
            index = letter - (int)'a';
            node = node->next[index];
            word++;
            if (node == NULL)
            {
                return false;
            }
        }
        else
        {
            node = node->next[26];
            word++;
            if (node == NULL)
            {
                return false;
            }
        }
    }
    if (node->isWord)
    {
        return true;
    }
    return false;
}

/**
 * Loads dictionary into memory. Returns true if successful else false.
 */
bool load(const char *dictionary)
{
    ROOT = create();
    FILE *fptr = fopen(dictionary, "r");
    if (fptr == NULL)
    {
        printf("Could not open dictionary!");
        return false;
    }

    char word[45];
    while (fscanf(fptr, "%s", word) != EOF)
    {
        // at first, I was using fgets() here
        // but fgets() will keep '\n' in the end of a word
        // so instead, use fscanf()
        insert(ROOT, word);
        SIZE++;
    }
    fclose(fptr);
    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    return SIZE;
}

/**
 * Unloads dictionary from memory. Returns true if successful else false.
 */
bool unload(void)
{
    delete(&ROOT);
    if (ROOT == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}
