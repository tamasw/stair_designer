#pragma once

#include "geometry/Line.hpp"

using namespace geometry;

template <typename CASTED_RESULT_TYPE, typename RESULT_TYPE, typename... Args>
class LineTester {
    public:
        typedef typename std::add_lvalue_reference<CASTED_RESULT_TYPE>::type CASTED_REULT_TYPE_REF; 
        
        LineTester(std::function<util::Optional<RESULT_TYPE>(Line*, Args...)> function)
        : function(function)
        {
        }
            
        CASTED_RESULT_TYPE getResult(std::unique_ptr<Line>& line, Args... args)
        {
            CASTED_RESULT_TYPE result = static_cast<CASTED_REULT_TYPE_REF>(function(line.get(), args...).get());
            return result;
        }
            
        private:
            std::function<util::Optional<RESULT_TYPE>(Line*, Args...)> function;
};

