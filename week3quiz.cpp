


class Fraction
{
	public:
		Fraction() : n(0), d(1) { }
		Fraction(int n, int d) : n(n), d(d) { }

		getN() {return n;}
		getD() {return d;}
	private: 
		int n;
		int d;

}

//overload << as a non-member function
ostream& operator<<(ostream% out, const Fraction& f)
{
	out << f.getN() << "/" << f.getD();
	return out;
}


int mian()
{
	Fraction f(3,4);
	cout << "f = " << f << endl; //output "f=3/4"
}