// -------
// IsPalindrome
// -------

#ifndef IsPalindrome
#define IsPalindrome

template <typename BI>

bool is_palindrome(BI b, BI e) {

	while (b != e && b != --e) {

		if (*b != *e)
			return false;

		++b;
	}

	return true;
}

#endif // IsPalindrome