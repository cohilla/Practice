// -------
// Accumulate
// -------

#ifndef Accumulate
#define Accumulate

template <typename II, typename T, typename func>

T my_accumulate(II b, II e, T v, func f) {

	auto result = v;

	while (b != e) {

		result += *b;

		++b;

	}

	return result;

}

#endif // Accumulate