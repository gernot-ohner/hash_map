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


struct Entry {
    int key;
    int value;
};

//typedef std::pair<int, int> entry_t;
typedef std::vector<std::unique_ptr<std::list<Entry>>> values_t;


class HashMap {
public:
    HashMap();

    void add(int key, int value);

    [[nodiscard]] int size() const noexcept;

    [[nodiscard]] int get(int key) const;

    [[nodiscard]] std::set<int> keys() const;

private:
    static int hash(int value) noexcept;

private:
    static constexpr int INITIAL_SIZE = 10;
    int num_of_entries = 0;
    std::set<int> keySet;
    values_t valuesVector;
};

#endif //HASH_MAP_HASHMAP_H
