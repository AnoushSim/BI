#include <string>
using namespace std;
class BigInteger
{
  private:
	string number;
	bool sign;
  string sum(string number1, string number2);
	string sub(string number1, string number2);
	string mul(string n1, string n2);
	public:
	BigInteger(); 
	BigInteger(string s, bool sin); 
	void setNumber(string s);
	const string& getNumber(); 
	void setSign(bool s);
	const bool& getSign();
	BigInteger operator + (BigInteger a,BigInteger b);
	BigInteger operator - (BigInteger a,BigInteger b);
	BigInteger operator * (BigInteger a,BigInteger b);
	BigInteger abs();
}
