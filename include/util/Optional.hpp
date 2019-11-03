#pragma once

#include <memory>
#include <exception>

namespace util {
    
template <typename T>
class Optional {
    public:
    
        static Optional<T> empty()
        {
            return Optional<T>();
        }
        
        static Optional<T> of(T value)
        {
            return Optional<T>(value);
        }
        
        bool available() const
        {
            return value.get() == nullptr ? false : true;
        }
        
        T& get()
        {
            if( !available() ) { throw std::runtime_error("Optional not available"); }
            return *value;
        }
    
        Optional(const Optional<T>& other)
        : value(nullptr)
        {
            if(other.available()) {
                value.reset(new T(*other.value));
            }
        }
        
        Optional(Optional<T>&& other) noexcept
        : value(std::move(other.value))
        {
        }
    private:
        Optional(T value)
            : value(std::make_unique<T>(value))
            {}
            
        Optional()
            : value(nullptr)
            {}
        
        std::unique_ptr<T> value;
};
    
}
