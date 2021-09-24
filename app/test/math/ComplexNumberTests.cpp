#include <math/ComplexNumber.hpp>

#include <gtest/gtest.h>

#include <utility>

namespace math
{
    class ComplexNumberTestsFixture : public ::testing::TestWithParam<std::pair<double, double>>
    {
    public:
        ComplexNumber& configureSut(double re, double im)
        {
            _sut = std::make_unique<ComplexNumber>(re, im);
            return *_sut;
        }


    private:
        std::unique_ptr<ComplexNumber> _sut;
    };

    TEST_P(ComplexNumberTestsFixture, BasicCreation)
    {
        auto re = std::get<0>(GetParam());
        auto im = std::get<1>(GetParam());

        EXPECT_NO_THROW({
            static_cast<void>(configureSut(re, im));
        }) << "re = " << testing::PrintToString(re) << " im=" << testing::PrintToString(im);
    }

    INSTANTIATE_TEST_SUITE_P(
            ComplexNumberTests,
            ComplexNumberTestsFixture,
            ::testing::ValuesIn({
                std::make_pair(-1., -1.),
                std::make_pair(0., 0.),
                std::make_pair(-1., -1.),
                std::make_pair(-1., 1.),
                std::make_pair(-1., 0.),
                std::make_pair(1., -1.),
                std::make_pair(0., -1.),
            }));

}
