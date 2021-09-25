#include <math/ComplexNumber.hpp>

#include <gtest/gtest.h>

#include <tuple>
#include <cmath>

namespace math
{
    class ComplexNumberTestsFixture : public ::testing::TestWithParam<std::tuple<double, double, double>>
    {
    public:
        ComplexNumber& configureSut(double re, double im)
        {
            _sut = std::make_unique<ComplexNumber>(re, im);
            return *_sut;
        }

    protected:
        std::unique_ptr<ComplexNumber> _sut;
    };

    namespace
    {
        class ComplexNumberTestsFixtureBasicCreation : public ComplexNumberTestsFixture
        {};

        TEST_P(ComplexNumberTestsFixtureBasicCreation, Tests)
        {
            auto re = std::get<0>(GetParam());
            auto im = std::get<1>(GetParam());

            EXPECT_NO_THROW({
                static_cast<void>(configureSut(re, im));
            }) << "re = " << testing::PrintToString(re) << " im=" << testing::PrintToString(im);
        }

        INSTANTIATE_TEST_SUITE_P(
                BasicTests,
                ComplexNumberTestsFixtureBasicCreation,
                ::testing::ValuesIn({
                    std::make_tuple(-1., -1., 0.),
                    std::make_tuple(0., 0., 0.),
                    std::make_tuple(-1., 1., 0.),
                    std::make_tuple(-1., 0., 0.),
                    std::make_tuple(1., -1., 0.),
                    std::make_tuple(0., -1., 0.),
                }));
    }

    namespace
    {
        class ComplexNumberTestsFixtureModuleTests : public ComplexNumberTestsFixture
        {};

        TEST_P(ComplexNumberTestsFixtureModuleTests, Tests)
        {
            auto re = std::get<0>(GetParam());
            auto im = std::get<1>(GetParam());
            auto module = std::get<2>(GetParam());

            auto& sut = configureSut(re, im);
            EXPECT_DOUBLE_EQ(sut.mod(), module);
        }

        INSTANTIATE_TEST_SUITE_P(
                ModuleTests,
                ComplexNumberTestsFixtureModuleTests,
                ::testing::ValuesIn({
                    std::make_tuple(-1., -1., std::sqrt(2)),
                    std::make_tuple(0., 0., 0.),
                    std::make_tuple(-1., 1., std::sqrt(2)),
                    std::make_tuple(-1., 0., 1.),
                    std::make_tuple(1., -1., std::sqrt(2)),
                    std::make_tuple(0., -1., 1.),
                }));
    }
}
