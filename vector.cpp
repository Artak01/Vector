#include <iostream> 
#include <stdexcept> 
#include <initializer_list> 
#include "vector.h" 
 
template <typename T> 
Vector<T>::const_iterator::const_iterator (pointer ptr) 
         : ptr {ptr} 
{} 
 
template <typename T> 
Vector<T>::const_iterator::const_iterator () 
         : ptr {nullptr} 
{} 
 
template <typename T> 
Vector<T>::const_iterator::const_iterator (const const_iterator& rhv) 
         : ptr {rhv.ptr} 
{} 
 
template <typename T> 
Vector<T>::const_iterator::const_iterator (const_iterator&& rhv) 
         : ptr{rhv.ptr} 
{ 
        rhv.ptr = nullptr; 
} 
 
template <typename T> 
Vector<T>::const_iterator::~const_iterator() 
{ 
    ptr = nullptr; 
} 
 
template <typename T> 
const typename Vector<T>::const_iterator& Vector<T>::const_iterator::operator= (const const_iterator& rhv) 
{ 
    if(&rhv != this) 
    { 
        ptr = rhv.ptr; 
    } 
    return *this; 
} 
 
template <typename T> 
const typename Vector<T>::const_iterator& Vector<T>::const_iterator::operator= (const_iterator&& rhv) 
{ 
    if(&rhv != this) 
    { 
        ptr = rhv.ptr; 
        rhv.ptr = nullptr; 
    } 
    return *this; 
} 
 
template <typename T> 
typename Vector<T>::const_reference Vector<T>::const_iterator::operator* () const 
{ 
    return *ptr; 
}

template <typename T>
typename Vector<T>::const_pointer Vector<T>::const_iterator::operator-> () const
{
    return ptr;
}

template <typename T>
const typename Vector<T>::const_iterator Vector<T>::const_iterator::operator+(Vector<T>::size_type val) const
{
    return const_iterator(ptr + val);
}

template <typename T>
const typename Vector<T>::const_iterator Vector<T>::const_iterator::operator-(Vector<T>::size_type val) const
{
    return const_iterator(ptr - val);
}

template <typename T>
const typename Vector<T>::const_iterator& Vector<T>::const_iterator::operator-=(Vector<T>::size_type val) const
{
    ptr -= val;
    return *this;
}


template <typename T>
const typename Vector<T>::const_iterator& Vector<T>::const_iterator::operator+=(Vector<T>::size_type val) const
{
    ptr += val;
    return *this;
}

template <typename T>
const typename Vector<T>::const_iterator& Vector<T>::const_iterator::operator++()
{
    ++ptr;
    return *this;
}

template <typename T>
const typename Vector<T>::const_iterator Vector<T>::const_iterator::operator++(int)
{
    const_iterator tmp = *this;
    ++tmp;
    return tmp;
}

template <typename T>
const typename Vector<T>::const_iterator& Vector<T>::const_iterator::operator--()
{
    --ptr;
    return *this;
}

template <typename T>
const typename Vector<T>::const_iterator Vector<T>::const_iterator::operator--(int)
{
    const_iterator tmp = *this;
    --tmp;
    return tmp;
}

template <typename T>
typename Vector<T>::const_reference Vector<T>::const_iterator::operator[](Vector<T>::size_type ind) const
{
    return *(ptr + ind);
}

template <typename T>
bool Vector<T>::const_iterator::operator==(const Vector<T>::const_iterator& rhv) const
{
    return ptr == rhv.ptr;
}

template <typename T> 
bool Vector<T>::const_iterator::operator!=(const Vector<T>::const_iterator& rhv) const
{
    return ptr != rhv.ptr;
}

template <typename T>
bool Vector<T>::const_iterator::operator<(const Vector<T>::const_iterator& rhv) const
{
    return ptr < rhv.ptr;
}

template <typename T>
bool Vector<T>::const_iterator::operator>(const Vector<T>::const_iterator& rhv) const
{
    return ptr > rhv.ptr;
}

template <typename T>
bool Vector<T>::const_iterator::operator<=(const Vector<T>::const_iterator& rhv) const
{
    return ptr <= rhv.ptr;
}

template <typename T>
bool Vector<T>::const_iterator::operator>=(const Vector<T>::const_iterator& rhv) const
{
    return ptr >= rhv.ptr;
}
//////////////////////////////////////////////////
/////////////////////////////////////////////////

template <typename T>
Vector<T>::iterator::iterator (pointer ptr)
         :iterator(ptr)
{}

template <typename T>
Vector<T>::iterator::iterator ()
         :iterator(nullptr)
{}

template <typename T>
Vector<T>::iterator::iterator (const iterator& rhv)
         :iterator(rhv)
{}

template <typename T>
Vector<T>::iterator::iterator (iterator&& rhv)
         :iterator(std::move(rhv))
{}


template <typename T>
typename Vector<T>::reference Vector<T>::iterator::operator*()
{
    return *this->ptr;
}

template <typename T>
typename Vector<T>::pointer Vector<T>::iterator::operator->()
{
    return this->ptr;
}

//////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////

template <typename T> 
Vector<T>::const_reverse_iterator::const_reverse_iterator (pointer ptr) 
         : ptr {ptr} 
{} 
 
template <typename T> 
Vector<T>::const_reverse_iterator::const_reverse_iterator () 
         : ptr {nullptr} 
{} 
 
template <typename T> 
Vector<T>::const_reverse_iterator::const_reverse_iterator (const const_reverse_iterator& rhv) 
         : ptr {rhv.ptr} 
{} 
 
template <typename T> 
Vector<T>::const_reverse_iterator::const_reverse_iterator (const_reverse_iterator&& rhv) 
         : ptr{rhv.ptr} 
{ 
        rhv.ptr = nullptr; 
} 
 
template <typename T> 
Vector<T>::const_reverse_iterator::~const_reverse_iterator() 
{ 
    ptr = nullptr; 
} 
 
template <typename T> 
const typename Vector<T>::const_reverse_iterator& Vector<T>::const_reverse_iterator::operator= (const const_reverse_iterator& rhv) 
{ 
    if(&rhv != this) 
    { 
        ptr = rhv.ptr; 
    } 
    return *this; 
} 
 
template <typename T> 
const typename Vector<T>::const_reverse_iterator& Vector<T>::const_reverse_iterator::operator= (const_reverse_iterator&& rhv) 
{ 
    if(&rhv != this) 
    { 
        ptr = rhv.ptr; 
        rhv.ptr = nullptr; 
    } 
    return *this; 
} 
 
template <typename T> 
typename Vector<T>::const_reference Vector<T>::const_reverse_iterator::operator* () const 
{ 
    return *ptr; 
}

template <typename T>
typename Vector<T>::const_pointer Vector<T>::const_reverse_iterator::operator-> () const
{
    return ptr;
}

template <typename T>
const typename Vector<T>::const_reverse_iterator Vector<T>::const_reverse_iterator::operator+(Vector<T>::size_type val) const
{
    return const_reverse_iterator(ptr - val);
}

template <typename T>
const typename Vector<T>::const_reverse_iterator Vector<T>::const_reverse_iterator::operator-(Vector<T>::size_type val) const
{
    return const_reverse_iterator(ptr + val);
}

template <typename T>
const typename Vector<T>::const_reverse_iterator& Vector<T>::const_reverse_iterator::operator-=(Vector<T>::size_type val) const
{
    ptr += val;
    return *this;
}


template <typename T>
const typename Vector<T>::const_reverse_iterator& Vector<T>::const_reverse_iterator::operator+=(Vector<T>::size_type val) const
{
    ptr -= val;
    return *this;
}

template <typename T>
const typename Vector<T>::const_reverse_iterator& Vector<T>::const_reverse_iterator::operator++()
{
    --ptr;
    return *this;
}

template <typename T>
const typename Vector<T>::const_reverse_iterator Vector<T>::const_reverse_iterator::operator++(int)
{
    const_reverse_iterator tmp = *this;
    --tmp;
    return tmp;
}

template <typename T>
const typename Vector<T>::const_reverse_iterator& Vector<T>::const_reverse_iterator::operator--()
{
    ++ptr;
    return *this;
}

template <typename T>
const typename Vector<T>::const_reverse_iterator Vector<T>::const_reverse_iterator::operator--(int)
{
    const_reverse_iterator tmp = *this;
    ++tmp;
    return tmp;
}

template <typename T>
typename Vector<T>::const_reference Vector<T>::const_reverse_iterator::operator[](Vector<T>::size_type ind) const
{
    return *(ptr - ind);
}

template <typename T>
bool Vector<T>::const_reverse_iterator::operator==(const Vector<T>::const_reverse_iterator& rhv) const
{
    return ptr == rhv.ptr;
}

template <typename T> 
bool Vector<T>::const_reverse_iterator::operator!=(const Vector<T>::const_reverse_iterator& rhv) const
{
    return ptr != rhv.ptr;
}

template <typename T>
bool Vector<T>::const_reverse_iterator::operator<(const Vector<T>::const_reverse_iterator& rhv) const
{
    return ptr < rhv.ptr;
}

template <typename T>
bool Vector<T>::const_reverse_iterator::operator>(const Vector<T>::const_reverse_iterator& rhv) const
{
    return ptr > rhv.ptr;
}

template <typename T>
bool Vector<T>::const_reverse_iterator::operator<=(const Vector<T>::const_reverse_iterator& rhv) const
{
    return ptr <= rhv.ptr;
}

template <typename T>
bool Vector<T>::const_reverse_iterator::operator>=(const Vector<T>::const_reverse_iterator& rhv) const
{
    return ptr >= rhv.ptr;
}


//////////////////////////////////////////////////
/////////////////////////////////////////////////

template <typename T>
Vector<T>::reverse_iterator::reverse_iterator (pointer ptr)
         : reverse_iterator(ptr)
{}

template <typename T>
Vector<T>::reverse_iterator::reverse_iterator ()
         :reverse_iterator(nullptr)
{}

template <typename T>
Vector<T>::reverse_iterator::reverse_iterator (const reverse_iterator& rhv)
         :reverse_iterator(rhv)
{}

template <typename T>
Vector<T>::reverse_iterator::reverse_iterator (reverse_iterator&& rhv)
         :reverse_iterator(std::move(rhv))
{}


template <typename T>
typename Vector<T>::reference Vector<T>::reverse_iterator::operator*()
{
    return *this->ptr;
}

template <typename T>
typename Vector<T>::pointer Vector<T>::reverse_iterator::operator->()
{
    return this->ptr;
}

//////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////





template <typename T>
Vector<T>::Vector()
    :_arr {nullptr}
    ,_size {0} 
    ,_capacity {0} 
{}

template <typename T>
Vector<T>::Vector(const Vector<value_type>& rhv) 
    :_size(rhv._size)
    ,_capacity(rhv._capacity) 
    ,_arr {new T[_capacity]}
{

    for (int i = 0; i < _size; ++i) {
        _arr[i] = rhv._arr[i];
    }
}

Vector<T>Vector(Vector&& rhv);



