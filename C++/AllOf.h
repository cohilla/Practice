// -------
// allof
// -------

#ifndef AllOf
#define AllOf

template <typename BI, typename func>

bool my_all_of(BI b, BI e, func f) {

	while (b != e) {

		if (!f(*b))
			return false;

		++b;
	}

	return true;

}

#endif // Allof