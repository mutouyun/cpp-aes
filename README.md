# cpp-aes
C++ AES Implementation, Modified from <<[SongLee24.AES-DES](https://github.com/SongLee24/AES-DES)>>.

```c++
auto enc = encrypt(key, buff, size);
ofstream ot;
ot.open("./cpp-aes.enc.txt", ios::binary);
ot.write(enc.data(), enc.size());
ot.close();

auto dec = decrypt(key, enc.data(), enc.size());
ot.open("./cpp-aes.dec.txt", ios::binary);
ot.write(dec.data(), dec.size());
ot.close();
```