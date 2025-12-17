#include <iostream>
#include <string>
using namespace std;
template<typename R, typename Error>
struct result {
    bool success;
    union Value {
        R r;
        Error e;
    } v;
    operator bool() {return success;}
    R operator *() {return v.r;}
    Error error() {return v.e;}
};
result<double, string> idiv(int left, int right) {
    result<double, string> r;
    if (right == 0) {r.e = string("cannot divide by 0");}
    else {r.r = static_cast<double>(left) / right;}
    return r;
}
int main() {
    auto r = idiv(1,3);
    if (r) cout << *r << endl;
    else cout << r.error() << endl;
    return 0;
}