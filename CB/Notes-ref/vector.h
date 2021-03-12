// This is user defined vector class
// we have defined a header file ' vector.h '
class vector {
	int cs;		// Current size of the vector
	int cap;	//capacity of the vector
	int*arr;
public:
	vector() {
		cs = 0;
		cap = 1;
		arr = new int[cap];
	}
	vector(int defaultSize) {
		cs = 0;
		cap = defaultSize;
		arr = new int[cap];
	}

	void push_back(const int d) {
		if (cs == cap) {
			int* newArr = arr;
			arr = new int[2 * cap];
			cap *= 2;
			for (int i = 0; i <= cs; i++) {
				arr[i] = newArr[i];
			}
			delete [] newArr;
		}
		arr[cs] = d;
		cs++;
	}
	//operator overloading to find the element at index 'i'
	int operator[](const int i)const {
		return arr[i];
	}
	bool empty()const {
		return cs == 0;
	}
	void pop_back() {
		if (!empty())
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
	int front()const {
		return arr[0];
	}
	int back()const {
		return arr[cs - 1];
	}
};