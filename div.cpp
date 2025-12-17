#include <iostream>
#include <string>
using namespace std;
template<typename R, typename Error>
struct result {
    bool success;
    union Value {
        R r;
        Error e;
        Value(){}                                     // 追加
        Value(const R& r): r(r) {}
        Value(const Error& e): e(e) {}
        ~Value() {}
    } v;
    result(const R& r): success(true), v(r) {}
    result(const Error& e): success(false), v(e) {}
    result(const result& org): success(org.success) { // 追加
        if (success) new (&v.r) R(org.v.r);           // 追加
        else new (&v.e) Error(org.v.e);               // 追加
    }                                                 // 追加
    ~result() {
        if (success) v.r.~R();
        else v.e.~Error();
    }
    operator bool() {return success;}
    R operator *() {return v.r;}
    Error error() {return v.e;}
};
result<double, string> idiv(int left, int right) {
    if (right == 0) {return string("cannot divide by 0");}
    else {return static_cast<double>(left) / right;}
}
int main() {
    auto r = idiv(1,3);
    if (r) cout << *r << endl;
    else cout << r.error() << endl;
    return 0;
}