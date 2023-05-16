#pragma once

template <typename T>
class Vector
{
public:
    // Constructors
    Vector();
    Vector(const Vector<T>& other);
    Vector(Vector<T>&& other);

};