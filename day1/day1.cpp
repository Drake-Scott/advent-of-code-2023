#include <string>
#include <fstream>
#include <iostream>
#include <cctype>
#include <unordered_map>

#define DIGITS ["one", "two", "three", "four", "five", "six", "seven", "eight", "nine"];
#define REVERSE ["eno", "owt", "eerht", "rouf", "evif", "xis", "neves", "thgie", "enin"];

//TODO fix da trie
typedef struct trieNode trieNode;

class TrieNode {
    public:
        char data;
        trieNode* children[26];
        bool isLeaf;
}

class Trie {
    public:
        root
    private:  
        trieNode* createNode(char data) {
            trieNode* node = (trieNode*) malloc (sizeof(trieNode));
            for (int i = 0; i < 26; i++) {
                node->children[i] = NULL;
            }
            node->isLeaf = false;
            node->data = data;
            return node;
        }
        void destroyNode(trieNode* node) {
            for(int i = 0; i < 26; i++) {
                if (node->children[i] != NULL) {
                    destroyNode(node->children[i]); // recursively deallocate all of the node's children.
                }
                else {
                    continue;
                }
            }
            free(node);
        }
}

int calcSum(int a, int b) {
    return (a * 10) + b;
}

int partOne() {
    
    unsigned int totalSum = 0;

    std::ifstream infile("input.txt");
    if(!infile) {
        return -1;
    }
    
    std::string line;
    while(std::getline(infile, line)) {
        int a, b;
        int length = line.length();

        // Loop forward for first digit
        for(int i = 0; i < length; i++) {
            if(std::isdigit(line[i])) {
                a = line[i] - '0';              // subtract ASCII value of 0 to convert char to int.
                break;
            }
        }
        
        // Now backwards
        for(int i = length - 1; i >= 0; i--) {
            if(std::isdigit(line[i])) {
                b = line[i] - '0';
                break;
            }
        }

        totalSum += calcSum(a, b);
    }

    infile.close();
    return totalSum;
}

int partTwo() {
    
    // populate a trie with one through nine
    // iterate letters checking for pattern matches.
    // if 

    return 0;
}



int main() {
    int part1 = partOne();

    std::cout << "PART 1\tsum = " << part1 << std::endl;
    return 0;
}
