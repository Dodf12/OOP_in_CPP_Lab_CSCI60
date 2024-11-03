#include <iostream>

using namespace std;

class ModInt
{
	private:
		int value;
		int mod;
	public:
		ModInt() {};
		
		ModInt(int v, int m)
		{
			value = v;
			mod = m;
		}

		//Accessors
		int getValue() const { return value; }
		int getMod() const { return mod; }
		friend ostream& operator <<(ostream& out, const ModInt& a);

		//Mutators
		void operator +=(const ModInt& rhs);




};

bool operator ==(const ModInt& lhs, const ModInt& rhs)
{
	if ( (lhs.getValue() == rhs.getValue() ) && ( lhs.getMod() == rhs.getMod() ) ) {return true; }
	return false;
}

void ModInt::operator +=(const ModInt& rhs)
{
	if ( mod == rhs.mod )
		{
			value += rhs.getValue();
			value %= mod;
		}

}

ModInt operator +(const ModInt& lhs, const ModInt& rhs)
{
	ModInt returnObj;
	returnObj+=lhs;
	returnObj+=rhs;

	return returnObj;
}

ModInt operator *(const ModInt lhs, const ModInt rhs)
{
	if ( lhs.getMod() != rhs.getMod() ) { return ModInt(-1,-1); }
	return ModInt( ((lhs.getValue() * rhs.getValue()) % lhs.getMod()), lhs.getMod());
}

ostream& operator <<(ostream& out, const ModInt& a)
{
	out << "Value: " << a.value << endl;
	out << "Mod: " << a.mod << endl;
	return out;
}

int main()
{
	ModInt();
	ModInt p = ModInt(1,2);
	ModInt p1 = ModInt(2,2);
	p += p1;
	p+p1;

	cout << p;
}