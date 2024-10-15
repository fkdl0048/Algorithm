#include <bits/stdc++.h>

using namespace std;

class cat {
public:
    cat() {
        cout << "cat created" << endl;
    }

    ~cat() {
        cout << "cat destroyed" << endl;
    }
};


int main() {
    shared_ptr<cat> c1 = make_shared<cat>();
    cout << "c1 use count: " << c1.use_count() << endl;
    shared_ptr<cat> c2 = c1;
    cout << "c1 use count: " << c1.use_count() << endl;

    return 0;
}