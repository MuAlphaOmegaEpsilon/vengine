#pragma once
/**
 * @brief A collection of custom tailored algorithms.
 * @file algorithm.hpp
 * @author Tommaso Bonvicini <tommasobonvicini@gmail.com>
 *         https://github.com/MuAlphaOmegaEpsilon/vengine
 * @date 12-09-2019
 */

#define VE_AL vengine::algorithm
#define INL inline
#define NX noexcept
#define ND [[nodiscard]]

namespace vengine::algorithm
{
    template <class T> using UnaryScore = ui32 (* const)
                                            (const T&);
    template <class T> using UnaryPred  = bool (* const)
                                            (const T&);
    template <class T> using BinaryPred = bool (* const)
                                            (const T&,
                                             const T&);

	template <class T>
    ND constexpr INL T* find_if
                    (T* begin,
                     T* end,
	                 UnaryPred<T> predicate) NX;
	template <class T> 
	ND constexpr INL T& max
					(T& a,
					 T& b) NX;
	template <class T> 
	ND constexpr INL T& max
					(T& a,
					 T& b,
					 BinaryPred<T> compare) NX;
	template <class T>
	ND constexpr INL T* max
					(T* begin,
					 T* end,
					 BinaryPred<T> compare,
					 UnaryPred<T> filter) NX;
	template <class T>
	ND constexpr INL T* max
					(T* begin,
					 T* end,
					 UnaryScore<T> classify) NX;
	template <class T>
	ND constexpr INL T* max
					(T* begin,
					 T* end,
					 UnaryScore<T> classify,
					 UnaryPred<T> filter) NX;
	template <class T> 
	ND constexpr INL T& min
					(T& a,
					 T& b) NX;
	template <class T> 
	ND constexpr INL T& min
					(T& a,
					 T& b,
					 BinaryPred<T> compare) NX;
}



template <class T>
constexpr T* VE_AL::find_if
				(T* begin,
				 T* end,
				 UnaryPred<T> predicate) NX
{
	while (begin < end && !predicate(*begin))
		++begin;
	return begin;
}

template <class T> 
constexpr T& VE_AL::max
				(T& a,
				 T& b) NX
{
	return a < b ? b : a;
}

template <class T> 
constexpr T& VE_AL::max
				(T& a,
				 T& b,
				 BinaryPred<T> compare) NX
{
	return compare(a, b) ? b : a;
}

template <class T> 
constexpr T& VE_AL::min
				(T& a,
				 T& b) NX
{
	return a < b ? a : b;
}

template <class T> 
constexpr T& VE_AL::min
				(T& a,
				 T& b,
				 BinaryPred<T> compare) NX
{
	return compare(a, b) ? a : b;
}

template <class T>
constexpr T* VE_AL::max
				(T* begin,
				 T* end,
				 BinaryPred<T> compare,
				 UnaryPred<T> filter) NX
{
	T* max_elem = find_if (begin, end, filter);
	if (max_elem >= end)
		return end;
	T* next = find_if (max_elem + 1, end, filter);
	while (next < end)
	{
		max_elem = &max (*max_elem, *next, compare);
		next = find_if (++next, end, filter);
	}
	return max_elem;
}

template <class T>
constexpr T* VE_AL::max
					(T* begin,
					 T* end,
					 UnaryScore<T> score) NX
{
	return max (begin, end, score, [](T&){ return true; });
}

template <class T>
constexpr T* VE_AL::max
					(T* begin,
					 T* end,
					 UnaryScore<T> score,
					 UnaryPred<T> filter) NX
{
	T* max_elem = begin;
	ui32 max_score = score(*begin);
	while (++begin < end)
	{
		if (!filter(*begin))
			continue;
		ui32 current_score = score(*begin);
		if (current_score > max_score)
			max_elem = begin;
	}
	return max_elem;
}

#undef VE_AL
#undef INL
#undef NX
#undef ND
