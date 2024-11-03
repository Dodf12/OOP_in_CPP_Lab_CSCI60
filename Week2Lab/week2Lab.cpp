#include <iostream>

using namespace std;

class ModInt
{
	private:
		int numericalValue;
		int modValue;
	public:
		ModInt()
		{
			numericalValue = 0;
			modValue = 1;
		}

		ModInt(int value, int mod)
		{
			numericalValue = value;
			modValue = mod;
		}

		int getNumericalValue() const 
		{
			return numericalValue;
		}

		int getModValue() const
		{
			return modValue;
		}

	void operator +=(const ModInt& rhs);
	
};

bool operator ==(const ModInt& lhs,const ModInt& rhs) 
{
	//Make sure teh variables are camelcase
	int lhs_val = lhs.getNumericalValue();
	int rhs_val = rhs.getNumericalValue();
	int lhs_mod = lhs.getModValue();
	int rhs_mod = rhs.getModValue();

	if ( (lhs_val == rhs_val) && (lhs_mod == rhs_mod))
	{
		return true;
	}

	return false;
}

/*
void ModInt :: operator +=(const ModInt& rhs) {

//sets num and mod to -1 if mods do not equal each other

if (rhs.getMod() != mod) {

num = -1;

mod = -1;

} else {

 

int numTemp = num + rhs.getNum();

num = numTemp % mod;

 

}

*/

void ModInt::operator +=(const ModInt& rhs) 
{
	int tempMod = rhs.modValue;
	if (modValue==tempMod){
		int total = numericalValue + rhs.getNumericalValue();

		numericalValue = total%modValue;
	}
	else
	{
		modValue = -1;
		numericalValue = -1;
	}

}
/*

Calls ModInt class by creating an object.
Gets attributes of the variables in the class
*/
int main()
{
	ModInt myModInt = ModInt(23,4);
	ModInt myModInt2 = ModInt(23,4);
	//cout << myModInt.getNumericalValue() << endl << myModInt.getModValue();

	cout << (myModInt == myModInt2) << endl;

	myModInt+=myModInt2;

	cout << myModInt.getNumericalValue();

}