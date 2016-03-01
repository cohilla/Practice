// -------
// equal
// -------

#ifndef Equal
#define Equal

template <typename II, typename II2>

// Need two different iterators
bool my_equal(II b, II e, II2 c) {

	while (b != e) {

		if (*b != *c)
			return false;

		++b;
		++c;
	}

	return true;
}

#endif // Equal