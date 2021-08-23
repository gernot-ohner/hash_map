//
// Created by gernotohner on 22.08.21.
//

#include "HashMap.h"

// public

HashMap::HashMap() {
    for (int i = 0; i < INITIAL_SIZE; ++i) {
        valuesVector.emplace_back(
                std::make_unique<std::list<std::pair<int, int>>>(
                        std::list<std::pair<int, int>>(1)
                )
        );
    }
}

void HashMap::add(std::pair<int, int> key_value) {
    keyVector.push_back(key_value.first);
    keySet.insert(key_value.first);
    valuesVector.at(1)->push_back(key_value);
    num_of_entries++;
}

std::set<int> HashMap::keys() const { return keySet; }

int HashMap::size() const { return num_of_entries; }

int HashMap::get(int key) const {
    return std::find_if(
            (*valuesVector.at(hash(key))).begin(),
            (*valuesVector.at(hash(key))).end(),
            [&key](std::pair<int, int> a) { return a.first == key; })
            ->second;
}

// private
int HashMap::hash(int value) {
    return value % 10;
}

