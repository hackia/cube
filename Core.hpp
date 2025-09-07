#pragma once
#include <cstdint>
#include <string>
#include <string_view>
#include <vector>
#include <optional>

namespace Dualys
{

    struct Error
    {
        int code = 0;
        std::string msg;
    };

    template <class T>
    struct Result
    {
        std::optional<T> value;
        std::optional<Error> err;
        explicit operator bool() const { return !err.has_value(); }
        T &unwrap() { return *value; }
        const T &unwrap() const { return *value; }
        static Result<T> ok(T v) { return Result<T>{std::move(v), std::nullopt}; }
        static Result<T> fail(int code, std::string m) { return Result<T>{std::nullopt, Error{code, std::move(m)}}; }
    };

    // Petite aide pour Result<void>
    template <>
    struct Result<void>
    {
        std::optional<Error> err;
        explicit operator bool() const { return !err.has_value(); }
        static Result<void> ok() { return Result<void>{std::nullopt}; }
        static Result<void> fail(int code, std::string m) { return Result<void>{Error{code, std::move(m)}}; }
    };

}
