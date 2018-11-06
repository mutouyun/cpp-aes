/*
    CPP-AES-128
    Code covered by the MIT License

    Author: mutouyun (http://orzz.org)
*/

#pragma once

#include <string>
#include <vector>

typedef void* key_t;

key_t gen_key(char const * key_str);
key_t gen_key(std::string const & key_str);

void delete_key(key_t key);

std::vector<char> encrypt(key_t key, char const * data, size_t size);
std::vector<char> decrypt(key_t key, char const * data, size_t size);
