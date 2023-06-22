//
// Created by vlad-mihai on 2023/06/23.
//

#ifndef OOP_REDUCERE_H
#define OOP_REDUCERE_H

#include <string>
#include <iostream>

template<class T>
class Reducere {
private:
    T value;
public:
    explicit Reducere(const T &value_) : value(value_) {}
    friend std::ostream& operator << (std::ostream& out, const Reducere<T> &ob) {
        out << "Reducerea aplicată este: " << ob.value << "\n";
        return out;
    }

    Reducere<T> combine(Reducere<T> other) {
        return Reducere(value + other.value);
    }

    template<class U>
    Reducere<T> combine(Reducere<U> other) {
        return *this;
    }
};

#endif //OOP_REDUCERE_H
