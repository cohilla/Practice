// -------
// Reverse
// -------

#ifndef Reverse
#define Reverse

template <typename BI>

void my_reverse(BI b, BI e) {

	// Work around using only bidirectional iterator.
	while (b != e && b != --e) {

		// auto temp = *e;
		// *e = *b;
		// *b = temp;

		*b ^= *e;
		*e ^= *b;
		*b ^= *e; 

		++b;

	}

}

#endif // Reverse