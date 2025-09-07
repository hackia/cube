#pragma once

#include <cstdint>
#include <string>
#include <string_view>
#include <vector>
#include <optional>

class Cube
{
public:
    Cube(double side_length);
    double volume() const;
    double surface_area() const;

private:
    double side_length_;
};
