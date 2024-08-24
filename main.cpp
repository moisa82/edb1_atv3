#include <iostream>
#include <string>
#include "headers/HashTable.h"

int main() {
    // Criando a tabela de dispersão
    HashTable hashTable(100); // Tamanho da tabela de dispersão é 100

    // Adicionando 20 palavras à tabela de dispersão
    hashTable.addWord("apple");
    hashTable.addWord("orange");
    hashTable.addWord("banana");
    hashTable.addWord("grape");
    hashTable.addWord("cherry");
    hashTable.addWord("peach");
    hashTable.addWord("mango");
    hashTable.addWord("apricot");
    hashTable.addWord("plum");
    hashTable.addWord("date");
    hashTable.addWord("fig");
    hashTable.addWord("kiwi");
    hashTable.addWord("lemon");
    hashTable.addWord("lime");
    hashTable.addWord("nectarine");
    hashTable.addWord("tangerine");
    hashTable.addWord("pear");
    hashTable.addWord("quince");
    hashTable.addWord("raspberry");
    hashTable.addWord("strawberry");


    std::cout << "Quantidade de 'apple': " << hashTable.countWord("apple") << std::endl;
    std::cout << "Quantidade de 'orange': " << hashTable.countWord("orange") << std::endl;
    std::cout << "Quantidade de 'banana': " << hashTable.countWord("banana") << std::endl;
    std::cout << "Quantidade de 'grape': " << hashTable.countWord("grape") << std::endl;
    std::cout << "Quantidade de 'cherry': " << hashTable.countWord("cherry") << std::endl;

    // Verificar se uma palavra está na tabela
    if (hashTable.containsWord("peach")) {
        std::cout << "'peach' está presente na tabela." << std::endl;
    } else {
        std::cout << "'peach' não está presente na tabela." << std::endl;
    }

    // Removendo uma palavra da tabela
    hashTable.removeWord("date");
    if (!hashTable.containsWord("date")) {
        std::cout << "'date' foi removida da tabela." << std::endl;
    }

    // Imprimir todo o conteúdo da tabela
    hashTable.printTable();

    return 0;
}
