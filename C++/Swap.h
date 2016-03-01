// -------
// Swap
// -------

#ifndef Swap
#define Swap

template <typename T>

void my_swap(T& a, T& b) {

	*a ^= *b;
	*b ^= *a;
	*a ^= *b;

}

#endif // Swap