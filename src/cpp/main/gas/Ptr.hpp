#ifndef GAS_PTR_HPP
#define GAS_PTR_HPP

#include "Object.hpp"

namespace gas{
    template<class T>
    class Ptr: public Object{
    private:
        T* mPtr;
        int mCount;
    public:
        Ptr(T* ptr);
        Ptr(Ptr& p);
        ~Ptr() override;
        Ptr& operator=(Ptr& p);
        T& operator*();
        T* operator->();
        operator T*();        
    };
}

#include "Ptr_impl.hpp"

#endif