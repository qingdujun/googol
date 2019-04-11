template<typename T>
class unique_ptr
{
public:
    explicit unique_ptr (T* p = nullptr);
    template<typename U>
    unique_ptr(unique_ptr<U>& rhs);
    ~unique_ptr ();
    template<typename U>
    unique_ptr<T>& operator=(unique_ptr<U>& rhs);
    T& operator*() const;
    T* operator->() const;
    T* get() const;
    T* release();
    void reset(T* p = nullptr);

private:
    T* pointee;
    template<typename U>
    friend class unique_ptr;
};

template<typename T>
inline unique_ptr<T>::unique_ptr(T* p) : pointee(p) {

}

template<typename T>
template<typename U>
inline unique_ptr<T>::unique_ptr(unique_ptr<U>& rhs) : pointee(rhs.release()) {

}

template<typename T>
template<typename U>
inline unique_ptr<T>& unique_ptr<T>::operator=(unique_ptr<U>& rhs) {
    if (this != &rhs) 
        reset(rhs.release());
    return *this;
}

template<typename T>
inline T& unique_ptr<T>::operator*() const {
    return *pointee;
}

template<typename T>
inline T* unique_ptr<T>::operator->() const {
    return pointee;
}

template<typename T>
inline T* unique_ptr<T>::get() const {
    return pointee;
}

template<typename T>
inline T* unique_ptr<T>::release() {
    T* old_pointee = pointee;
    pointee = nullptr;
    return old_pointee;
}

template<typename T>
inline void unique_ptr<T>::reset(T* p) {
    if (pointee != p) {
        delete pointee;
        pointee = p;
    }
}
