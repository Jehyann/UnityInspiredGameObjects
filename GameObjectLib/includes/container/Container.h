#include <vector>
#include <stdexcept>

#ifndef CONTAINER_H
#define CONTAINER_H


template <typename T>
class Container {

private:
    std::vector<T> data;

public:
    Container();
    void Add(const T& element);
    void Remove(const T& element);
    void RemoveAll(const T& element);
    bool Contains(const T& element) const;
    size_t Size() const;
    T GetElement(size_t index) const;
};

#endif // CONTAINER_H