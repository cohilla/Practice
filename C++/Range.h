// ---------------
// Range.h
// ---------------

#ifndef Range_h
#define Range_h

#include <cstddef>  // ptrdiff_t
#include <iterator> // input_iterator_tag

using namespace std;

template <typename T>

class Range {
	private:
		T b;
		T e;

	public:
		Range (const T& begin, const T& end) : b(begin), e(end) {} 

		class iterator : public std::iterator<input_iterator_tag, T> {
					private:
						T v;

					public:
						iterator (T _v) : v(_v) {}

						bool operator == (const iterator& i) const {
							return v == i.v;
						}	

						bool operator != (const iterator& i) const {
							return !(*this == i);
						}

						T operator * () {
							return v;
						}

						iterator& operator ++ () {
							++v;
							return *this;
						}

						iterator operator ++ (int) {
							iterator temp = *this;
							++v;
							return temp;
						}

						T reverseDigits() {
							T copy = v;
							T result = v - v;

							while (copy > 0) {
								T digit = copy % 10;
								copy /= 10;
								result *= 10;
								result += digit;
							}

							return result;
						}

						bool isPalindrome() {
							iterator r = *this;
							T copy = r.reverseDigits();

							return copy == v;
						}

		};

		iterator begin() const{
			return iterator(b);
		}

		iterator end() const{
			return iterator(e);
		}

};


#endif // Range
