// -------
// Copy
// -------

#ifndef Copy
#define Copy

template <typename II, typename OI>

OI my_copy(II b, II e, OI r) {

	while (b != e) {

		*r = *b;

		++r;
		++b;

	}

	return r;
}

#endif // Copy