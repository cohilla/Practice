// -------
// Fill
// -------

#ifndef Fill
#define Fill

template <typename FI, typename T>

void my_fill(FI b, FI e, T v) {

	while (b != e) {
		*b = v;
		++b;
	}

}

#endif // Fill