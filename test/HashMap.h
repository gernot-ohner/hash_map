//
// Created by gernotohner on 22.08.21.
//

#ifndef HASH_MAP_HASHMAP_H
#define HASH_MAP_HASHMAP_H


#include <utility>
#include <vector>
#include <set>
#include <list>
#include <memory>

typedef std::vector<std::unique_ptr<std::list<std::pair<int, int>>>> values_t;

class HashMap {
public:
    HashMap();

    void add(std::pair<int, int> key_value);

    [[nodiscard]] int size() const;

    [[nodiscard]] int get(int key) const;

    [[nodiscard]] std::set<int> keys() const;

private:
    static int hash(int value);

private:
    static constexpr int INITIAL_SIZE = 10;
    int num_of_entries = 0;
    std::set<int> keySet;
    std::vector<int> keyVector = std::vector<int>(10);
    values_t valuesVector;
};

#endif //HASH_MAP_HASHMAP_H
