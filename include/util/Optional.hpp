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
        
        template <typename U>
        static Optional<T> of(const U& value)
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
        
        template <typename U>
        Optional(const Optional<U>& other)
        : value(nullptr)
        {
            if(other.available()) {
                value.reset(new U(*other.value));
            }
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
        
    protected:
        
        Optional(const T& value)
            : value(std::make_unique<T>(value))
            {}
            
        Optional()
            : value(nullptr)
            {}
        
        std::unique_ptr<T> value;
        
        template <typename U>
        friend class Optional;
};
    
}
