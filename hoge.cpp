#include <iostream>
#include <iomanip>
#include <cstdint>
using namespace std;
union hoge {
uint64_t u64;
uint8_t u8[8];
};
int main() {
    hoge o;
    o.u64 = 1234;
    for (auto b: o.u8) {
        cout << hex << setw(2) << setfill('0') << static_cast<uint16_t>(b) << dec << " ";
    }
    cout << endl;
    return 0;
}
// d2 04 00 00 00 00 00 00 

