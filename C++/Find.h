// -------
// Find
// -------

#ifndef Find
#define Find

template <typename II, typename T>

II my_find(II b, II e, T v) {

	while (b != e) {
		if (*b == v)
			return b;

		++b;
	}

	// Returns the last element if not found.
	return e;
}

#endif // Find