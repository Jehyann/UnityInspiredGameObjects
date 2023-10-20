#ifndef VECTOR2D_H 
#define VECTOR2D_H
#include <cmath>
#include <iostream>
#include <string>

template <typename T>
class Vector2D {
public:
    T x;
    T y;

    Vector2D();
    Vector2D(const T& vx, const T& vy);
    std::string ToString() const;

    Vector2D operator+(const Vector2D& other) const;
    Vector2D operator-(const Vector2D& other) const;
    bool operator==(const Vector2D& other) const;
    Vector2D<T> operator*(T scalar) const;
    Vector2D<T> operator/(T scalar) const;

    Vector2D<T> scale(T factor) const;
    T distance(const Vector2D& other) const;

    void MoveTowards(const Vector2D<T>& target, T speed);
    static const Vector2D<T> down;
    static const Vector2D<T> up;
    static const Vector2D<T> left;
    static const Vector2D<T> right;
    static const Vector2D<T> zero;

};

#include "Vector2D.inl"

#endif // VECTOR2D_H