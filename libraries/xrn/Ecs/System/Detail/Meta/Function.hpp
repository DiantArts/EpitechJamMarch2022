#pragma once

#include <xrn/Ecs/Signature.hpp>



namespace xrn::ecs::detail::meta {



template <
    typename func
> struct Function
    : public Function<decltype(&func::operator())>
{};



template <
    typename RetType,
    typename... ArgsType
> struct Function<RetType(ArgsType...)> {

    struct Return {
        using Type = RetType;
    };

    struct Arguments {
        using Type = ::std::tuple<ArgsType...>;
        static constexpr const auto areConst{ ((
            ::std::is_const<::std::remove_reference_t<ArgsType>>::value ||
            !::std::is_reference<ArgsType>::value
        ) && ...) };
        static inline constexpr auto signature{ ::xrn::ecs::Signature::generate<ArgsType...>() };
    };

};



template <
    typename RetType,
    typename... ArgsType
> struct Function<RetType(*)(ArgsType...)>
    : public ::xrn::ecs::detail::meta::Function<RetType(ArgsType...)>
{};



template <
    typename RetType,
    typename... ArgsType
> struct Function<::std::function<RetType(ArgsType...)>>
    : public ::xrn::ecs::detail::meta::Function<RetType(ArgsType...)>
{};



template <
    typename ClassType,
    typename RetType,
    typename... ArgsType
>struct Function<RetType(ClassType::*)(ArgsType...) const> {

    struct Return {
        using Type = RetType;
    };

    struct Arguments {
        using Type = ::std::tuple<ArgsType...>;
        static constexpr const auto areConst{ ((
            ::std::is_const<::std::remove_reference_t<ArgsType>>::value ||
            !::std::is_reference<ArgsType>::value
        ) && ...) };
        static inline constexpr auto signature{ ::xrn::ecs::Signature::generate<ArgsType...>() };
    };
};



} // namespace xrn::ecs::detail::meta
