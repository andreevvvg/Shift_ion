/**
@copyright Evgeny Sidorov 2020

Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

*/

/****************************************************************************/

/** @file validator/prevalidation/true_if_size.hpp
*
*  Defines "true_if_size".
*
*/

/****************************************************************************/

#ifndef DRACOSHA_VALIDATOR_TRUE_IF_SIZE_HPP
#define DRACOSHA_VALIDATOR_TRUE_IF_SIZE_HPP

#include <dracosha/validator/config.hpp>
#include <dracosha/validator/utils/string_view.hpp>
#include <dracosha/validator/properties/empty.hpp>
#include <dracosha/validator/properties/size.hpp>
#include <dracosha/validator/operators/lexicographical.hpp>

DRACOSHA_VALIDATOR_NAMESPACE_BEGIN

//-------------------------------------------------------------

/**
  Definition of stub object to validate resizing.
 **/
struct true_if_size
{
    size_t _size;

    template <typename T>
    bool operator ==(const T& other) const noexcept
    {
        auto&& val=adjust_view_type(other);
        return hana::eval_if(
            hana::bool_<has_property<decltype(val),decltype(size)>()>{},
            [&](auto&& _)
            {
                return _size==_(val).size();
            },
            [&](auto&&)
            {
                // checking only size property, all the rest are ignored
                return true;
            }
        );
    }

    template <typename T>
    bool operator < (const T& other) const noexcept
    {
        auto&& val=adjust_view_type(other);
        return hana::eval_if(
            hana::bool_<has_property<decltype(val),decltype(size)>()>{},
            [&](auto&& _)
            {
                auto sz=_(val).size();
                return _size<sz || _size==sz;
            },
            [&](auto&&)
            {
                // checking only size property, all the rest are ignored
                return true;
            }
        );
    }

    template <typename T>
    bool operator <= (const T& other) const noexcept
    {
        return (*this<other);
    }

    template <typename T>
    bool operator > (const T& other) const noexcept
    {
        auto&& val=adjust_view_type(other);
        return hana::eval_if(
            hana::bool_<has_property<decltype(val),decltype(size)>()>{},
            [&](auto&& _)
            {
                auto sz=_(val).size();
                return _size>sz || _size==sz;
            },
            [&](auto&&)
            {
                // checking only size property, all the rest are ignored
                return true;
            }
        );
    }

    template <typename T>
    bool operator >= (const T& other) const noexcept
    {
        return (*this>other);
    }

    template <typename T>
    bool operator !=(const T&) const noexcept
    {
        // we don't know content, so this comparison is always true and does not depend on size
        return true;
    }

    template <typename T>
    friend bool operator == (const T& other, const true_if_size& v) noexcept
    {
        return v==other;
    }
    template <typename T>
    friend bool operator != (const T& other, const true_if_size& v) noexcept
    {
        return v!=other;
    }
    template <typename T>
    friend bool operator < (const T& other, const true_if_size& v) noexcept
    {
        return v>other;
    }
    template <typename T>
    friend bool operator <= (const T& other, const true_if_size& v) noexcept
    {
        return v>=other;
    }
    template <typename T>
    friend bool operator > (const T& other, const true_if_size& v) noexcept
    {
        return v<other;
    }
    template <typename T>
    friend bool operator >= (const T& other, const true_if_size& v) noexcept
    {
        return v<=other;
    }
};

/**
 * Template specialization of lexicograpical operators for true_if_size.
 */
template <typename T, typename T2>
struct lex_operators<T,T2,hana::when<std::is_same<std::decay_t<T>,true_if_size>::value>>
{
    using T1=true_if_size;

    static bool eq(const T1& a, const T2& b)
    {
        return a==b;
    }

    static bool ne (const T1& a, const T2& b)
    {
        return a!=b;
    }

    static bool lt(const T1& a, const T2& b)
    {
        return a<b;
    }

    static bool lte(const T1& a, const T2& b)
    {
        return a<=b;
    }

    static bool gt(const T1& a, const T2& b)
    {
        return a>b;
    }

    static bool gte(const T1& a, const T2& b)
    {
        return a>=b;
    }

    static bool ieq(const T1& a, const T2& b)
    {
        return eq(a,b);
    }

    static bool ine(const T1& a, const T2& b)
    {
        return ne(a,b);
    }

    static bool ilt(const T1& a, const T2& b)
    {
        return lt(a,b);
    }

    static bool ilte(const T1& a, const T2& b)
    {
        return lte(a,b);
    }

    static bool igt(const T1& a, const T2& b)
    {
        return gt(a,b);
    }

    static bool igte(const T1& a, const T2& b)
    {
        return gte(a,b);
    }

    static bool contains(const T1& a, const T2& b)
    {
        return gte(a,b);
    }

    static bool icontains(const T1& a, const T2& b)
    {
        return contains(a,b);
    }

    static bool starts_with(const T1& a, const T2& b)
    {
        return contains(a,b);
    }

    static bool istarts_with(const T1& a, const T2& b)
    {
        return contains(a,b);
    }

    static bool ends_with(const T1& a, const T2& b)
    {
        return contains(a,b);
    }

    static bool iends_with(const T1& a, const T2& b)
    {
        return contains(a,b);
    }
};

DRACOSHA_VALIDATOR_NAMESPACE_END

#endif // DRACOSHA_VALIDATOR_TRUE_IF_EMPTY_HPP
