// -------
// Remove
// -------

#ifndef Remove
#define Remove

template <typename FI, typename T>

// Remove all elements equal to v, and move the next value down the removed 
// place. Return the new end of the iterator.
FI my_remove(FI b, FI e, T v) {

	FI result = b;

	while (b != e) {

		if (*b == v)
			++b;

		else {
			*result = *b;
			++result;
			++b;
		}

	}

	return result;
}

#endif // Remove