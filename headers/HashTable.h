#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <list>
#include <string>
#include <vector>

class HashTable {
private:
    struct HashNode {
        std::string key;
        int value;
        HashNode(const std::string& k, int v) : key(k), value(v) {}
    };

    std::vector<std::list<HashNode>> table;
    int size;

    int hashFunction(const std::string& word) const {
        unsigned long hash = 5381;
        for (char c : word) {
            hash = ((hash << 5) + hash) + static_cast<unsigned long>(c);
        }
        return hash % size;
    }

public:
    // Construtor que aceita o tamanho da tabela
    HashTable(int s) : size(s), table(s) {}

    void addWord(const std::string& word) {
        int index = hashFunction(word);
        for (auto& node : table[index]) {
            if (node.key == word) {
                node.value++;
                return;
            }
        }
        table[index].emplace_back(word, 1);
    }

    int countWord(const std::string& word) const {
        int index = hashFunction(word);
        for (const auto& node : table[index]) {
            if (node.key == word) {
                return node.value;
            }
        }
        return 0;
    }

    void updateWord(const std::string& word, int count) {
        int index = hashFunction(word);
        for (auto& node : table[index]) {
            if (node.key == word) {
                node.value = count;
                return;
            }
        }
        table[index].emplace_back(word, count);
    }

    void removeWord(const std::string& word) {
        int index = hashFunction(word);
        table[index].remove_if([&](const HashNode& node) {
            return node.key == word;
        });
    }

    bool containsWord(const std::string& word) const {
        int index = hashFunction(word);
        for (const auto& node : table[index]) {
            if (node.key == word) {
                return true;
            }
        }
        return false;
    }

    void printTable() const {
        for (int i = 0; i < size; ++i) {
            std::cout << "Index " << i << ": ";
            for (const auto& node : table[i]) {
                std::cout << "(" << node.key << ", " << node.value << ") ";
            }
            std::cout << std::endl;
        }
    }
};

#endif
