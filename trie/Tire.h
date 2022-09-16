//
// Created by 王锐 on 2021/12/6.
//

#ifndef ALGORITHM_TIRE_H
#define ALGORITHM_TIRE_H
#include <cstring>
#include <iostream>
using namespace std;

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
//        cout << "正在调用Trie的构造函数" << endl;
        memset(children, 0, sizeof(children));
        isEnd = false;
    }
    ~Trie() {
//        cout << "正在调用Trie的析构函数" << endl;
        for (auto & e : children) {
            delete e;
        }
    }

    /** Inserts a word into the trie. */
    void insert(const string& word) {
        Trie* node = this;
        for (char ch : word) {
            ch -= 'a';
            if(node->children[ch] == nullptr)
                node->children[ch] = new Trie();
            node = node->children[ch];
        }
        node->isEnd = true;
    }

    /** Returns if the word is in the trie. */
    bool search(const string& word) {
        Trie* node = searchPrefix(word);
        return node != nullptr && node->isEnd;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(const string& prefix) {
        return searchPrefix(prefix) != nullptr;
    }

private:
    Trie* children[26];
    bool isEnd;

    Trie* searchPrefix(const string& prefix) {
        Trie* node = this;
        for (char ch : prefix) {
            ch -= 'a';
            if (node->children[ch] == nullptr)
                return nullptr;
            node = node->children[ch];
        }
        return node;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * rie trie = new Trie();
 * trie.insert("apple");
 * trie.search("apple");   // 返回 True
 * trie.search("app");     // 返回 False
 * trie.startsWith("app"); // 返回 True
 * trie.insert("app");
 * trie.search("app");     // 返回 True
 */

void TrieTest() {
    Trie trie;
    trie.insert("apple");
    cout << trie.search("apple") << endl;
    cout << trie.search("app") << endl;
    cout << trie.startsWith("app") << endl;
    trie.insert("app");
    cout << trie.search("app") << endl;
}

#endif //ALGORITHM_TIRE_H
