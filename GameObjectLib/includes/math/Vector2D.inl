// creating a .inl file is to handle LNK2019 error, its a file that join class and function + act as a header, need include it to .h

// constructor with Default container
template <typename T>
Vector2D<T>::Vector2D() : x(T(0)), y(T(0)) {}

// constructor with parameters
template <typename T>
Vector2D<T>::Vector2D(const T& vx, const T& vy) : x(vx), y(vy) {}

// gives a string of where is 
template <typename T>
std::string Vector2D<T>::ToString() const {
    return "(" + std::to_string(x) + ", " + std::to_string(y) + ")";
}

// --------------------------------------------------------------------------------------------------------

// sum
template <typename T>
Vector2D<T> Vector2D<T>::operator+(const Vector2D& other) const {
    return Vector2D(x + other.x, y + other.y);
}

// substraction
template <typename T>
Vector2D<T> Vector2D<T>::operator-(const Vector2D& other) const {
    return Vector2D(x - other.x, y - other.y);
}

// equal
template <typename T>
bool Vector2D<T>::operator==(const Vector2D<T>& other) const {
    return (x == other.x) && (y == other.y);
}

// multiply
template <typename T>
Vector2D<T> Vector2D<T>::operator*(T scalar) const {
    return Vector2D(x * scalar, y * scalar);
}

// divide
template <typename T>
Vector2D<T> Vector2D<T>::operator/(T scalar) const {
    if (scalar == 0) {
        std::cout << "Cannot divide by 0." << std::endl;
        return *this;
    }
    return Vector2D(x / scalar, y / scalar);
}

// scale
template <typename T>
Vector2D<T> Vector2D<T>::scale(T factor) const {
    return Vector2D(x * factor, y * factor);
}

// distance
template <typename T>
T Vector2D<T>::distance(const Vector2D& other) const {
    T dx = x - other.x;
    T dy = y - other.y;
    return std::sqrt(dx * dx + dy * dy);
}

// --------------------------------------------------------------------------------------------------------

// move to a specific target with a specific speed
// speed : determine how many units the point moved with each update
template <typename T>
void Vector2D<T>::MoveTowards(const Vector2D<T>& target, T speed) {
    Vector2D<T> direction = target - *this; // subtracts the current position from the target position to get a vector that points from the current position to the target position
    T distance = direction.magnitude(); // euclidian distance
    if (distance > T(0)) { // check if need to move
        direction.normalize();
        *this = *this + direction * speed;
    }
}

// down by 1
template <typename T>
const Vector2D<T> Vector2D<T>::down = Vector2D<T>(T(0), T(-1));

// up by 1
template <typename T>
const Vector2D<T> Vector2D<T>::up = Vector2D<T>(T(0), T(1));

// left by 1
template <typename T>
const Vector2D<T> Vector2D<T>::left = Vector2D<T>(T(-1), T(0));

// right by 1
template <typename T>
const Vector2D<T> Vector2D<T>::right = Vector2D<T>(T(1), T(0));

// goes zero
template <typename T>
const Vector2D<T> Vector2D<T>::zero = Vector2D<T>(T(0), T(0));