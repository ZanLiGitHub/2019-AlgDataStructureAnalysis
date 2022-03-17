//*********************************************************************************************************************
// Course name: Algorithm & Data Structure Analysis (COMP 7201)
// Author: Zan Li a1750906
// Date: 19/August/2019
// Description: C++ Implementation of Integer Addition, Multiplication, and Division 
//*********************************************************************************************************************

#include <iostream>
#include <string.h>
#include <algorithm>
#include <cstdlib>
#include <sstream>
using namespace std;

//Tool: Converting int to string***************************************************************************************
string toString (int num)
{
    //Declare variable
    string str;
    //Use int string to store int
    stringstream ss(str);
    //Use int string to store int
    ss<<num;
    //Return parameter
    return ss.str();
}

//Tool: Add 0 to the front of the parameter to reach the same length***************************************************
int addZeroFront(string& num1, string& num2)
{
    //Declare variable
    long int len1 = num1.length();
    //Declare variable
    long int len2 = num2.length();
    //Test execution condition
    if(len1 > len2)
    {
        //Loop begin
        for(long int i = 0;i < len1 - len2;++i)
        {
            num2 = "0" + num2;
        }//Loop finish
        //Return parameter
        return len1;
    }
    else
    {
        //Loop begin
        for(long int i = 0; i < len2 - len1; ++i)
        {
            num1 = "0" + num1;
        }//Loop finish
        //Return parameter
        return len2;
    }
    
}

//Tool: Add 0 to the behind of the parameter to reach the same length**************************************************
string addZeroBehind(string num, int len)
{
    //Test execution condition
    if(num == "0")
    {
        //Return parameter
        return num;
    }
    //Loop begin
    for(long int i = 0;i < len;++i)
    {
        num += "0";
    }//Loop finish
    //Return parameter
    return num;
}

//Tool: Compare the length of two numbers******************************************************************************
int compare(string num1, string num2)
{
	//Declare variable
    long int len1 = num1.length();
    //Declare variable
    long int len2 = num2.length();
	//Test execution condition
	if(len1 > len2)  
	{
		//Return parameter
		return 1;
	}
	//Test execution condition
	else if(len1 < len2) 
	{
		//Return parameter
		return -1;
	}
	//Loop begin
	for(long int i = 0; i < len1; i++)
	{	
		//Test execution condition
		if(num1.at(i) > num2.at(i)) 
		{	
			//Return parameter
			return 1;
		}
		//Test execution condition
		if(num1.at(i) < num2.at(i)) 
		{	
			//Return parameter	
			return -1;
		}
	}//Loop finish
	//Return parameter
	return 0;
}

//Tool: Converting numbers to different bases**************************************************************************
string convertBase (string num, int oldBase, int newBase)
{
    //Declare variable
    char newNum[1000];
    //Declare variable
    int div[1000];
    //Declare variable
    int quo[1000];
    //Declare variable
    int rem[1000]; 
    //Conver string to char[]
    strcpy(newNum, num.c_str());
    //Declare variable
    int i,len = strlen(newNum);
    //Declare variable
    int i1, i2, i3;
    //Initialization
    div[0] = len;
    //Loop begin
    for(i=1; i <= len; i++)
    {
        //Test execution condition
        if(newNum[i-1] >= '0' && newNum[i-1] <= '9')
        {
            div[i] = newNum[i-1] - '0';
        }
    }//Loop finish
    //Initialization
    memset(rem,0,sizeof(rem));
    //Declare variable
    int newRem;
    //Loop begin
    while(div[0] >= 1)
    {
        newRem=0;
        i1=1;
        quo[0]=div[0];
        //Loop begin
        while(i1 <= div[0])
        {
            newRem = newRem * oldBase + div[i1];
            quo[i1++] = newRem/newBase;
            newRem %= newBase;
        }//Loop finish
        rem[++rem[0]] = newRem;
        //Initialization
        i1 = 1;
        //Loop begin
        while((i1<=quo[0]) && (quo[i1]==0)) 
        {		
        	i1++;
        }
        //Initialization
        memset(div,0,sizeof(div));
        //Loop begin
        for(i2 = i1;i2 <= quo[0];i2++)
        {
            div[++div[0]] = quo[i2];
        }//Loop finish
        //Initialization
        memset(quo,0,sizeof(quo)); 
    }
    //Convert int[] to string
    string res;
    //Loop begin
    for(i3 = rem[0];i3 >= 1;--i3)
    {
        res += toString(rem[i3]);
    }//Loop finish
    //Return parameter
    return res;
}

//Algorithm: Big number School Method Addition*************************************************************************
string schoolMethodAddition(string num1,string num2){
    //Declare variable
    int len1 = num1.length();
    //Declare variable
    int len2 = num2.length();
    //Declare variable
    int i = len1-1,j = len2-1;
    //Declare variable
    int a,b,sum,car = 0;
    //Declare variable
    string res;
    //Test execution condition
    if(len1 <= 0)
    {
        return num2;
    }
    //Test execution condition
    if(len2 <= 0)
    {
        return num1;
    }
    //Loop begin
    while(i >= 0 || j >= 0 || car > 0)
    {
        a = i >= 0 ? num1[i] - '0' : 0;
        b = j >= 0 ? num2[j] - '0' : 0;
        sum = a + b + car;
        car = sum / 10;
        res.insert(res.begin(),sum % 10 + '0');
        --i;
        --j;
    }//Loop finish
    //Return parameter
    return res;
}

//Algorithm: Big number subtraction function***************************************************************************
string subtraction(string num1, string num2) 
{
    //Declare variable
    long int len1 = num1.length();
    //Declare variable
    long int len2 = num2.length();
    //Declare variable
    bool pos = true;
    //Declare variable
    string res;
    //Test execution condition
    if(num1 == num2)
    {
    	//Return parameter
        return "0";
    }
    //Test execution condition
    if(len1 < len2 || (len1 == len2 && num1 < num2))
    {
        pos = false;
        //Exchange num1 and num2 so that num1 is greater than num2
        string tmp = num1;
        num1 = num2;
        num2 = tmp;
        int tmp2 = len1;
        len1 = len2;
        len2 = tmp2;
    }
    //Declare variable
    int newLen1 = len1 - 1;
	//Declare variable
    int newLen2 = len2 - 1;
    //Declare variable
    int a,b,sum,car = 0;
    //Loop begin
    while(newLen1 >= 0 || newLen2 >= 0)
    {
        a = newLen1 >= 0 ? num1[newLen1] - '0' : 0;
        b = newLen2 >= 0 ? num2[newLen2] - '0' : 0;
        sum = a - b + car;
        //reset carry
        car = 0;
        //Test execution condition
        if(sum < 0)
        {
            sum += 10;
            car = -1;
        }
        res.insert(res.begin(),sum + '0');
        --newLen1;
        --newLen2;
    }
    // Delete front 0
    string::iterator it = res.begin();
    //Loop begin
    while(it != res.end() && *it == '0')
    {
        ++it;
    }//Loop finish
    res.erase(res.begin(),it);
    //Return parameter
    return pos ? res : "-" + res;
}

//Algorithm: Big number karatsuba multiplication***********************************************************************
string karatsubaMultiplication(string num1, string num2)
{
    //Declare variable
    long int len = addZeroFront(num1,num2);
	//Declare variable
    int mid = len / 2;
    //Test execution condition
    if(len == 0)
    {
        //Return parameter
        return 0;
    }
    //Test execution condition
    else if(len == 1)
    {
        //Return parameter
        return toString((num1[0] - '0')*(num2[0] - '0'));
    }
    //Declare variable
    string rightNum1 = num1.substr(0, mid);
    //Declare variable
    string leftNum1 = num1.substr(mid, len - mid);
    //Declare variable
    string rightNum2 = num2.substr(0, mid);
    //Declare variable
    string leftNum2 = num2.substr(mid, len - mid);
    //Declare variable
    string quoLeft = karatsubaMultiplication(leftNum1, leftNum2);
    //Declare variable
    string quoRight = karatsubaMultiplication(rightNum1, rightNum2);
    //Declare variable
    string sum1 = schoolMethodAddition(rightNum1, leftNum1);
    //Declare variable
    string sum2 = schoolMethodAddition(rightNum2, leftNum2);
    //Declare variable
    string quoMix = karatsubaMultiplication(sum1, sum2);
    //Declare variable
    string quoRight1 = addZeroBehind(quoRight, 2*(len - mid));
    //Declare variable
    string quoRight2 = addZeroBehind(subtraction(subtraction(quoMix,quoRight), quoLeft), len - mid);
    //Return parameter
    return  schoolMethodAddition(schoolMethodAddition(quoRight1, quoRight2), quoLeft);
}

//Algorithm: Big number division***************************************************************************************
string division(string num1, string num2)
{
	//Declare variable
	long int len1 = num1.length();
	//Declare variable
	long int len2 = num2.length();
	//Declare variable
	string mid;
	//Declare variable
	string res; 
	//Test execution condition
	if(len2 == 1 && num2.at(0) == 48) 
	{
		return "Illegal parameter";
	}
	//Test execution condition
	if(compare(num1, num2) == 0) 
	{
		return "1";
	}
	//Test execution condition
	if(compare(num1, num2) ==-1)
	{
		return "0";
	}
	//Loop begin
	for(int i=0;i<num1.length();i++)
	{
		int j=0;
		mid = mid + num1.at(i);
		//Loop begin
		while(compare(mid, num2)>=0)
		{
			mid = subtraction(mid, num2);
			j++;
		}
		res = res + "0";
		res.at(i) = j;
	}//Loop finish
	//Loop begin
	for(int i=0;i < res.length();i++)
	{
		if(res.at(i) >= 10) res.at(i) += 87;
		if(res.at(i) < 10) res.at(i) += 48;
	}//Loop finish
	//Return parameter
	return res;
}

//Main method*********************************************************************************************************
int main()
{
    string I1, I2;
    int B;
    cin >> I1 >> I2 >> B;
    string decimalI1 = convertBase(I1, B, 10);
    string decimalI2 = convertBase(I2, B, 10);
    string decimalSum = schoolMethodAddition(decimalI1,decimalI2);
    string decimalMul = karatsubaMultiplication(decimalI1,decimalI2);
    string decimalQuo = division(decimalI1,decimalI2);
    string sum = convertBase(decimalSum, 10, B);
    string mul = convertBase(decimalMul, 10, B);
    string quo = convertBase(decimalQuo, 10, B);
    cout << sum << " " << mul << " " << quo << endl;
    return 0;
}
