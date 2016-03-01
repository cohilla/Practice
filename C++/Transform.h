// -------
// Transform
// -------

#ifndef Transform
#define Transform

template <typename II, typename OI, typename UF>

// Needs Unary function
OI my_transform(II b, II e, OI r, UF f) {

	while (b != e) {

		*r = f(*b);

		++b;
		++r;
	}

	return r;
}

#endif // Transform