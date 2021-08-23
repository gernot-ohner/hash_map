//
// Created by gernotohner on 22.08.21.
//
#include "catch.hpp"
#include "HashMap.h"

TEST_CASE("Can create a new empty HashMap") {
    HashMap h{};
}

TEST_CASE("Can get size of an empty hashmap") { // in elements
    HashMap h{};

    REQUIRE(h.size() == 0);
}

TEST_CASE("Can add a pair of numbers to the hashmap") {
    HashMap h{};

    h.add( 1, 10);

    REQUIRE(h.size() == 1);
}


TEST_CASE("Can retrieve a previously added number") {
    // given
    HashMap h{};
    h.add(1, 10);

    //when
    auto item = h.get(1);

    // then
    REQUIRE(item == 10);
}

TEST_CASE("Can get a previously added number for which there has been a key collision") {
    // given
    HashMap h{};
    h.add(1, 10);
    h.add(11, 20);

    //when
    auto item = h.get(1);

    // then
    REQUIRE(item == 10);
}

TEST_CASE("Can retrieve all keys in HashMap") {
    // given
    HashMap h{};
    h.add(1, 10);
    h.add(2, 10);
    std::set<int> expected { 1, 2 };

    //when
    auto actual = h.keys();

    // then
    REQUIRE(actual == expected);
}



