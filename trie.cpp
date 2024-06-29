#include <iostream>
#include <unordered_map>
#include <string>

class TrieNode
{
public:
    std::unordered_map<char, TrieNode *> children;
    bool word_end;

    TrieNode() : word_end(false) {}
};

class Trie
{
private:
    TrieNode *root;

public:
    Trie()
    {
        root = new TrieNode();
    }

    void insert(const std::string word)
    {
        TrieNode* node = root;
        for(char c : word)
        {
            if (node->children.find(c) == node->children.end())
            {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
        }
        node->word_end = true;
    }

    bool search(const std::string& word)
    {
        TrieNode* node = root;
        for(char c : word)
        {
            if(node->children.find(c) == node->children.end())
            {
                return false;
            }

            node = node->children[c];
        }

        return node->word_end;
    }
};

int main()
{
    Trie trie;
    trie.insert("apple");
    std::cout << std::boolalpha;
    std::cout << "Search for 'apple': " << trie.search("apple") << std::endl; // true
    std::cout << "Search for 'app': " << trie.search("app") << std::endl; // false
    trie.insert("app");
    std::cout << "Search for 'app' after inserting 'app': " << trie.search("app") << std::endl; // true

    return 0;
}