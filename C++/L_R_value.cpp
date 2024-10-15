#include <iostream>
#include <vector>

class MyClass {
public:
    std::vector<int> data;
    
    MyClass(std::vector<int> d) : data(std::move(d)) {
        // R-value 참조를 사용하여 벡터의 데이터를 이동
    }
};

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    MyClass obj(std::move(vec)); // vec의 내용을 이동
    std::cout << "vec size: " << vec.size() << std::endl; // vec는 비어 있음
}