add_library (Math
#HEADER
    math/ComplexNumber.hpp

#SOURCE
    math/ComplexNumber.cpp)

include_directories(.)

add_executable (app main.cpp)
target_link_libraries (app Math)
