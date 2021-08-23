//
// Created by gernotohner on 22.08.21.
//

#include "HashMap.h"

// public

HashMap::HashMap() {
    for (int i = 0; i < INITIAL_SIZE; ++i) {
        valuesVector.emplace_back(
                std::make_unique<std::list<Entry>>(
                        std::list<Entry>(1)
                )
        );
    }
}

void HashMap::add(int key, int value) {
    keySet.insert(key);
    valuesVector.at(1)->emplace_back(
            Entry{.key = key, .value = value}
    );
    num_of_entries++;
}

std::set<int> HashMap::keys() const { return keySet; }

int HashMap::size() const noexcept { return num_of_entries; }

int HashMap::get(int key) const {
    return std::find_if(
            (*valuesVector.at(hash(key))).begin(),
            (*valuesVector.at(hash(key))).end(),
            [&key](Entry e) { return e.key == key; })
            ->value;
}

// private
int HashMap::hash(int value) noexcept {
    return value % 10;
}

