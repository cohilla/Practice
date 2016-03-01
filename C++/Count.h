// -------
// Count
// -------

#ifndef Count
#define Count

template <typename II, typename T>

T my_count(II b, II e, T v) {

	T result = 0;

	while (b != e) {

		if (*b == v)
			++result;

		++b;

	}

	return result;
}

#endif // Count