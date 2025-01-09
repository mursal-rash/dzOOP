#include <iostream>

template<typename T, T Mod>
class Modular {
public:
    Modular(T value = 0) : value(value % Mod) {
        if (this->value < 0) this->value += Mod;
    }

    Modular(const Modular& other) : value(other.value) {}

    Modular& operator=(const Modular& other) {
        if (this != &other) {
            value = other.value;
        }
        return *this;
    }

    Modular operator+(const Modular& other) const {
        return Modular((value + other.value) % Mod);
    }

    Modular operator-(const Modular& other) const {
        return Modular((value - other.value + Mod) % Mod);
    }

    Modular operator*(const Modular& other) const {
        return Modular((value * other.value) % Mod);
    }

    Modular operator-() const {
        return Modular(-value);
    }

    friend std::ostream& operator<<(std::ostream& os, const Modular& m) {
        return os << m.value;
    }

private:
    T value;
};

int main() {
    Modular<int, 7> a(10);
    std::cout << a << std::endl;

    a = a + 8; // 10 + 8 = 18 % 7 = 4
    a = a * 4; // 4 * 4 = 16 % 7 = 2
    std::cout << a << std::endl;

    Modular<int, 7> b(a); // b = 2
    b = b + 2; // 2 + 2 = 4
    a = a - b; // 2 - 4 = -2 % 7 = 5
    std::cout << a << std::endl;

    return 0;
}
