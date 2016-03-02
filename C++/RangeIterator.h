// ---------------
// RangeIterator.h
// ---------------

#ifndef RangeIterator_h
#define RangeIterator_h

#include <cstddef>  // ptrdiff_t
#include <iterator> // input_iterator_tag

using namespace std;

template <typename T>

class RangeIterator : public iterator<input_iterator_tag, T> {
	private:
		T v;

	public:

		RangeIterator(const T& _v) : 
			v (_v)
			// v = _v;
		{}

		// x.operator==(y);
		bool operator == (const RangeIterator& r) const{
			return v == r.v;
		}

		// using *this to call the == function on the argument
		bool operator != (const RangeIterator& r) const{
			return !(*this == r);
		}

		T operator * () {
			return v;
		}

		// empty argument gives prefix
		// returns L value
		RangeIterator& operator ++ () {
			++v;
			return *this;
		}

		// postfix
		// x.operator++(0);
		// returns R value
		RangeIterator operator ++ (int i) {
			auto temp = *this;
			++v; // or ++*this; calls the ++ function on this object
			return temp;
		}

};



#endif // RangeIterator
