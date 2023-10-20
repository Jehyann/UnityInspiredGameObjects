#include "container/Container.h"


template <typename T>
Container<T>::Container() {}

// add element at the end of "data"
template <typename T>
void Container<T>::Add(const T& element) {
    data.push_back(element);
}

// removes an element from the container (first occurrence)
template <typename T>
void Container<T>::Remove(const T& element) {
    typename std::vector<T>::iterator i;
    for (i = data.begin(); i != data.end(); ++i) {
        if (*i == element) {
            data.erase(i);
            break; // delete only the first occurrence
        }
    }
}

// removes every occurence of an element
template <typename T>
void Container<T>::RemoveAll(const T& element) {
    data.erase(std::remove(data.begin(), data.end(), element), data.end());
}

// search for an item in the container
template <typename T>
bool Container<T>::Contains(const T& element) const {
    for (const T& item : data) {
        if (item == element) {
            return true;
        }
    }
    return false;
}

// get container size
template <typename T>
size_t Container<T>::Size() const {
    return data.size();
}

// get an element at a given index
template <typename T>
T Container<T>::GetElement(size_t index) const {
    if (index < data.size()) {
        return data[index];
    }
    // if off-limit
    throw std::out_of_range("Index out of range");
}