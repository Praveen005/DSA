#include<iostream>
using namespace std;
class complex {
	int real;
	int img;

public:
	complex() {
		real = 0;
		img = 0;
	}
	// one more constructor can be initialize the complex no.
	complex(const int r, const int i) {
		real = r;
		img = i;

	}
	//setter
	void set_real(const int n) {
		real = n;
	}
	void set_img(const int n) {
		img = n;
	}
	//getter
	int get_real()const {
		return real;
	}
	int get_img()const {
		return img;
	}
	void print()const {
		if (img < 0) {
			cout << real << " - " << -img << "i" << endl;
		}
		else {
			cout << real << " + " << img << "i" << endl;
		}
	}
	void add(const complex &x) {
		real = real + x.real;
		img += x.img;
	}

	complex operator+(const complex &x) {
		real = real + x.real;
		img += x.img;
		complex m(real, img);
		return m;
	}
	//Unary operator
	// Doesn't accept any parameter
	void operator!() {
		img *= -1;
	}

	// void operator[](string s) {
	// 	if (img > 0)
	// 		cout << real << " + " << img << "i" << s << endl;
	// 	else
	// 		cout << real << " - " << -img << "i" << s << endl;
	// }

	int operator[](string s) {
		if (s == "real") {
			return real;
		}
		else {
			return img;
		}
	}

};

// void operator>>(istream &is, complex& c) {
// 	int r1, i1;
// 	is >> r1 >> i1;
// 	c.set_real(r1);
// 	c.set_img(i1);
// }
istream& operator>>(istream &is, complex& c) {
	int r1, i1;
	is >> r1 >> i1;
	c.set_real(r1);
	c.set_img(i1);
	return is;
}
// void operator<<(ostream &os, complex& c) {
// 	c.print();
// }
ostream& operator<<(ostream &os, complex& c) {
	c.print();
	return os;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	complex a(5, 6);
	a.print();
	complex d;
	d.set_img(-2);
	d.set_real(8);
	d.print();
	//we used add function to add two complex numbers
	// can't we do a+d ? yes:
	a.add(d);
	a.print();

	complex f = a + d; /// adds  (13+4i)+(8-2i)
	f.print();
	a.print();
	!a;
	a.print();
	cout << d["img"] << endl;;
	complex c;
	cin >> c;
	c.print();
	cout << c;

}