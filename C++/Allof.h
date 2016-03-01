// -------
// allof
// -------

#ifndef Allof
#define Allof

template <typename BI, typename T, typename func>

bool my_allof(BI b, BI e, func f) {

	while (b != e && b != --e) {

		if (!f(*b))
			return false;

		++b;
	}

	return true;

}

#endif // Allof