#include "ComplexNumber.hpp"
#include <cmath>
#include <stdexcept>

namespace math
{
    ComplexNumber::ComplexNumber(double re, double im)
        : _re(re)
        , _im(im)
    {
    }

    double ComplexNumber::mod() const
    {
        return std::sqrt(std::pow(_re, 2.) + std::pow(_im, 2.));
    }

    inline double mod(const ComplexNumber &obj)
    {
        return obj.mod();
    }



}
