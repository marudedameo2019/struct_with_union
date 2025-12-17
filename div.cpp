#include <iostream>
#include <string>
using namespace std;
template<typename R, typename Error>
struct result {
    bool success;
    union Value {
        R r;
        Error e;
        Value(const R& r): r(r) {}     // 追加
        Value(const Error& e): e(e) {} // 追加
    } v;
    result(const R& r): success(true), v(r) {}      // 追加
    result(const Error& e): success(false), v(e) {} // 追加
    operator bool() {return success;}
    R operator *() {return v.r;}
    Error error() {return v.e;}
};
result<double, string> idiv(int left, int right) {
    if (right == 0) {return string("cannot divide by 0");} // 変更
    else {return static_cast<double>(left) / right;}       // 変更
}
int main() {
    auto r = idiv(1,3);
    if (r) cout << *r << endl;
    else cout << r.error() << endl;
    return 0;
}