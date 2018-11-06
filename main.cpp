#include "aes.h"

#include <iostream>
#include <fstream>
#include <ostream>

using namespace std;

int main(void)
{
    auto key = gen_key("what.the.fxxk!!!");

    ifstream in;
    in.open("./cpp-aes.pro", ios::binary);
    if (!in.good()) {
        cout << "bad read!" << std::endl;
        return 0;
    }
    in.seekg(0, ios::end);
    size_t size = in.tellg();
    char* buff = new char[size];
    in.seekg(0, ios::beg);
    if (!in.read(buff, size)) {
        cout << "bad read!" << std::endl;
        return 0;
    }
    in.close();

    auto enc = encrypt(key, buff, size);
    ofstream ot;
    ot.open("./cpp-aes.enc.txt", ios::binary);
    ot.write(enc.data(), enc.size());
    ot.close();

    auto dec = decrypt(key, enc.data(), enc.size());
    ot.open("./cpp-aes.dec.txt", ios::binary);
    ot.write(dec.data(), dec.size());
    ot.close();

    return 0;
}
