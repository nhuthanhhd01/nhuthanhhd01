#include<iostream>
#include<math.h>
using namespace std;
class DT {
	int n; // bac cua da thuc
	double* a; // chua he so cua da thuc
public:
	DT() { // ham tao khong doi
		this->n = 0;
		this->a = NULL;
	}
	DT(int n1) { // ham tao 1 doi
		this->n = n1;
		a = new double[n1 + 1];
	}
	~DT() {
	
	}
	friend ostream& operator<< (ostream& os, const DT& d);  // ham toan tu in
	friend istream& operator >>(istream& is, DT& d); // ham toan tu nhap
	DT operator-(); // ham dao dau da thuc
	DT operator +(const DT& d2);//ham toan tu cong
	DT operator -(DT d2); // ham toan tu tru
	DT operator *(const DT& d2); // ham toan tu nhan
	double operator^(const double& x); // da thuc mu x
	double operator [](int i) {
		if (i < 0) {
			return double(n);
		}
		else {	
			return a[i];
		}
	}
};
// viet ham
 ostream& operator << (ostream& os, const DT& d) {
	 os << "\t ->Cac he so lan luot tu bac "<<d.n<<" la: ";
	 for (int i = d.n ; i >= 0; i--) {
		 os << d.a[i] << " ";
	 }
	 return os;
}
 istream& operator >> (istream& is, DT& d) {
	 if (d.a != NULL) delete d.a;
	 cout << "\tNhap bac cua da thuc: ";
	 cin >> d.n;
	 d.a = new double[d.n + 1];
	 cout << "Nhap he so cua da thuc: \n";
	 for (int i = d.n; i>=0; i--) {
		 cout << "He so bac " << i << " :";
		 is >> d.a[i];
		}
	 return is;
 }
 double F(DT p, double x) {
	 double f=0.0;
	 int n = int(p[-1]); // lay bac cua da thuc
		 for (int i = n; i >= 0; i--) {
			 f = f + p[i] * pow(x, i);
	 }
		 return f;
 }
 DT DT:: operator-() { // ham dao dau da thuc
	 DT p(this->n);
	 for (int i = n; i >= 0; i--) {
		 p.a[i] = - this->a[i];
	 }
	 return p;
 }
 DT DT::operator +(const DT& d2) {
	 int i, k;
	 if (n > d2.n) k = n;
	 else
		 k = d2.n;
	// k = n > d2.n ? n : d2.n;
	 DT p(k);
	 for (i = k; i >= 0; i--) {
		 if (i <= n && i <= d2.n) {
			 p.a[i] = this->a[i] + d2.a[i];
		 }
		 else if (i <= n) {
			 p.a[i] = a[i];
		 }
		 else
			 p.a[i] = d2.a[i];
	 }
	 return p;
 }
 DT DT::operator-(DT d2) {
	 return (*this + (-d2));
 }
 DT DT :: operator*(const DT& d2) {
	 int k, i, j;
	 k = n + d2.n;
	 DT d(k);
	 for (i = k; i >= 0; i--) d.a[i] = 0;
	 for (i = n; i >= 0; i--) {
		 for (j = d2.n; j >= 0; j--) {
			 d.a[i + j] += this->a[i] * d2.a[j];
		 }
	 }
	 return d;

}
 double DT :: operator^(const double& x) {
	 double s = 0,t = 1;
	 for (int i = n; i >= 0; i--) {
		 s = s + this->a[i] * t;
		 t = t * x;
	 }
	 return s;
 }
int main() {
	 DT p,q,r,s;
	 double x1, x2;
	 cout << "Nhap da thuc p: \n"; cin >> p;
	 cout << "Nhap da thuc q: \n"; cin >> q;
	 cout << "Nhap da thuc r: \n"; cin >> r;
	 cout << "Nhap da thuc s: \n"; cin >> s;
	// cout << p << endl;
	// q = -p;
	 DT  f = -(p + q) * (r - s);
	 cout << f;
	 cout << "\nNhap x1= "; cin >> x1;
	 cout << "\nNhap x2= "; cin >> x2;
	 double h1 = f^x1;
	 double h2 = F(f, x2);
	 cout << "f(" << x1 << ")= " << h1 << endl;
	 cout << "f(" << x2 << ")= " << h2 << endl;
	 return 0;
 }
