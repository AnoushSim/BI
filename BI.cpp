#ifndef BIGINTEGER_H
#define BIGINTEGER_H

#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include "BigInteger.h"
BigInteger::BigInteger() 
{
	number = "0";
	sign = false;
}
BigInteger::BigInteger(string s, bool ssign) 
{
  setNumber(s);
  setSign(ssign);
}
void BigInteger::setNumber(string s)
{
	number = s;
}

const string& BigInteger::getNumber() 
{
	return number;
}

void BigInteger::setSign(bool ssign)
{
	sign = ssign;
}

const bool& BigInteger::getSign()
{
	return sign;
}
BigInteger abs()
{
  return BigInteger(getNumber());
}
BigInteger BigInteger::operator + (BigInteger a,BigInteger b)
{
	BigInteger gumar;
	if( a.getSign() == b.getSign() ) 
	{
		gumar.setNumber( sum(a.getNumber(), b.getNumber() ) );
		gumar.setSign( a.getSign() );
	}
	else 
	{
		if( a.abs() > b.abs() )
		{
			gumar.setNumber( sub(a.getNumber(), b.getNumber() ) );
			gumar.setSign(a.getSign());
		}
		else
		{
			gumar.setNumber( sub(b.getNumber(), a.getNumber() ) );
			gumar.setSign(b.getSign());
		}
	}
	
	return gumar;
}
BigInteger BigInteger::operator - (BigInteger a,BigInteger b)
{
	BigInteger trb;
	if( a.getSign() == b.getSign() && a.abs() > b.abs() ) 
	{
		trb.setNumber(sub(a.getNumber(), b.getNumber()));
		trb.setSign( a.getSign() );
	}
	else if( a.getSign() == b.getSign() && a.abs() < b.abs() ) 
	{
	  trb.setNumber(sub(a.getNumber(), b.getNumber()));
	trb.setSign(true);
	  
	}
	else if( a.getSign() != b.getSign() && a.abs() > b.abs())
	{
	  trb.setNumber(sub(a.getNumber(), b.getNumber()));
	trb.setSign( a.getSign());
	}
	
	else if( a.getSign() != b.getSign() && a.abs() < b.abs())
	{
	  trb.setNumber(sub(a.getNumber(), b.getNumber()));
	trb.setSign(true);
	}

	
	return trb;
}
BigInteger BigInteger::operator * (BigInteger a,BigInteger b)
{
	BigInteger bazm;

	bazm.setNumber( mul(a.getNumber(), b.getNumber() ) );
	bazm.setSign( a.getSign() != b.getSign() );

	if(bazm.getNumber() == "0") 
		bazm.setSign(false);

	return bazm;
}
string BigInteger::sum(string s1,string s2)
{ 
  int carry=0;
  string s3=(s1.length()>s2.length())? s1: s2;
int dif=abs(s1.length()-s2.length());
if(s1.length()>s2.length())
s2.insert(0,dif,'0');
else s1.insert(0,dif,'0');
for(int i=s1.length()-1; i>=0;i--)
{
  s3[i] = (carry-'0')+(s1[i]-'0')+(s2[i]-'0') + '0';

	if(i)
	{	
	if(s3[i] > '9')
	{
	s3[i] %= 10;
  carry = 1;
	}
	else carry = 0;
	}}
	if(s3[0] > '9')
	{
		s3[0]%= 10;
		s3.insert(0,1,'1');
	}
	return s3;
}
}
}
string BigInteger::sub(string s1,string s2)
{ 
  string s3=(s1.length()>s2.length())? s1: s2;
int dif=abs(s1.length()-s2.length());
if(s1.length()>s2.length())
s2.insert(0,dif,'0');
else s1.insert(0,dif,'0');
for(int i=s1.length()-1; i>=0;i--)
{
  if(s1[i]<s2[i])
  {
    s1[i]+=10;
    s1[i-1]--;
  }
  s3[i]=(s1[i]-'0')-(s2[i]-'0')+'0';
  //dimaci 0nery vonc hanem)))))
  return s3;
}
string BigInteger::mul(string s1,string s2)
{
  int carry=0;
  string s3=s1+' '+s2;
  for(int i=s3.length()-1;i>=0; i--)
  s3[i]='0';
  for(int i<s1.length()-1;i>=0; i--)
  {
 for(int j=s2.length()-1; j>=0; j--)  
 s3[j]=(s2[j]+'0') * (s1[i]+'0') + carry;
 if(temp[j] > 9)
	{
	carry = s3[j]/10;
	s3[j] = s3[j]%10;
	}
	else
	carry = 0;
  }

	if(carry > 0)
		s3.insert(0, 1, (carry+'0'));
		
		s3.append((s1.length()-i-1), '0'); 
  }
return s3   
}
