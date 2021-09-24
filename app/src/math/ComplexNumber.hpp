#ifndef COMPLEXNUMBER_HPP
#define COMPLEXNUMBER_HPP

namespace math
{
    class ComplexNumber
    {
    public:
        ComplexNumber() = delete;
        ComplexNumber(double re, double im);

        double mod() const;

    private:
        double _re;
        double _im;
    };

    double mod(const ComplexNumber& obj);
}

#endif // COMPLEXNUMBER_HPP
