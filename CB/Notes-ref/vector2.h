// This is user defined vector class
// we have defined a header file ' vector.h '
template<typename T>
class vector {
	int cs;		// Current size of the vector
	int cap;	//capacity of the vector
	T*arr;
public:
	vector() {
		cs = 0;
		cap = 1;
		arr = new T[cap];
	}
	vector(int defaultSize) {
		cs = 0;
		cap = defaultSize;
		arr = new T[cap];
	}

	void push_back(const T d) {
		if (cs == cap) {
			T* oldArr = arr;
			arr = new T[2 * cap];
			cap *= 2;
			for (int i = 0; i <= cs; i++) {
				arr[i] = oldArr[i];
			}
			delete [] oldArr;
		}
		arr[cs] = d;
		cs++;
	}
	//operator overloading to find the element at index 'i'
	T operator[](const int i)const {
		return arr[i];
	}
	void pop_back() {
		cs--;

	}
	void clear() {
		cs = 0;
	}
	int capacity()const {
		return cap;
	}
	int size() const {
		return cs;
	}
	T front()const {
		return arr[0];
	}
	T back()const {
		return arr[cs - 1];
	}
	bool empty()const {
		return cs == 0;
	}
};