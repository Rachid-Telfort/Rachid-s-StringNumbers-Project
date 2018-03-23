#include"StringNumber.h"

StringNumber::StringNumber()
{
    this->operand='0';
}

StringNumber::StringNumber(const long long int argument)
{
    bool isNegative=false;
    unsigned long long int copyArgument=0;
    unsigned char operandDigit='\0';

    if(argument<0)
    {
        isNegative=true;
        copyArgument=-((unsigned long long int)argument);///This avoids overflow.
    }

    else
    {
        copyArgument=argument;
    }

    while(copyArgument!=0)
    {
        operandDigit=copyArgument%10+'0';
        this->operand.insert(this->operand.begin(), operandDigit);
        copyArgument/=10;
    }

    if(isNegative)
    {
        this->operand.insert(this->operand.begin(), '-');
    }

    else if(this->operand.empty())
    {
        this->operand='0';
    }
}

StringNumber::StringNumber(const char* const argument)
{
    if(argument!=NULL)
    {
        bool isNegative=false;
        size_t characterCount=0;
        size_t argumentLength=strlen(argument);

        if(argument[0]=='-')
        {
            isNegative=true;
            ++characterCount;
            this->operand.push_back(argument[0]);
        }

        else if(argument[0]=='+')
        {
            ++characterCount;
        }

        if(isNegative)
        {
            for(; characterCount<argumentLength; ++characterCount)
            {
                if(!isdigit(argument[characterCount]))
                {
                    throw std::runtime_error("Error: Wrong number format from argument.");
                }

                else
                {
                    this->operand.push_back(argument[characterCount]);
                }
            }

            while(*(this->operand.begin()+1)=='0')///This removes any leading zeros from the operand.
            {
                this->operand.erase((this->operand.begin()+1));
            }

            if(this->operand.size()==1)///This is in case where the user inputs the string literal "-0".
            {
                this->operand='0';
            }
        }

        else
        {
            for(; characterCount<argumentLength; ++characterCount)
            {
                if(!isdigit(argument[characterCount]))
                {
                    throw std::runtime_error("Error: Wrong number format from argument.");
                }

                else
                {
                    this->operand.push_back(argument[characterCount]);
                }
            }

            while(*this->operand.begin()=='0')///This removes any leading zeros from the operand.
            {
                this->operand.erase(this->operand.begin());
            }

            if(this->operand.empty())///This is in case where the user inputs the string literals "0" or "+0".
            {
                this->operand='0';
            }
        }
    }

    else///This is like if the user inputs no arguments in the constructor.
    {
        this->operand='0';
    }
}

StringNumber::StringNumber(const std::string& argument)
{
    if(!argument.empty())
    {
        bool isNegative=false;
        std::string::const_iterator stringIterator=argument.begin();

        if(*argument.begin()=='-')
        {
            isNegative=true;
            ++stringIterator;
            this->operand.push_back(*argument.begin());
        }

        else if(*argument.begin()=='+')
        {
            ++stringIterator;
        }

        if(isNegative)
        {
            for(; stringIterator!=argument.end(); ++stringIterator)
            {
                if(!isdigit(*stringIterator))
                {
                    throw std::runtime_error("Error: Wrong number format from argument.");
                }

                else
                {
                    this->operand.push_back(*stringIterator);
                }
            }

            while(*(this->operand.begin()+1)=='0')///This removes any leading zeros from the operand.
            {
                this->operand.erase((this->operand.begin()+1));
            }

            if(this->operand.size()==1)///This is in case where the user inputs the string literal "-0".
            {
                this->operand='0';
            }
        }

        else
        {
            for(; stringIterator!=argument.end(); ++stringIterator)
            {
                if(!isdigit(*stringIterator))
                {
                    throw std::runtime_error("Error: Wrong number format from argument.");
                }

                else
                {
                    this->operand.push_back(*stringIterator);
                }
            }

            while(*this->operand.begin()=='0')///This removes any leading zeros from the operand.
            {
                this->operand.erase(this->operand.begin());
            }

            if(this->operand.empty())///This is in case where the user inputs the string literals "0" or "+0".
            {
                this->operand='0';
            }
        }
    }

    else///This is like if the user inputs no arguments in the constructor.
    {
        this->operand='0';
    }
}

StringNumber::StringNumber(const StringNumber& argument)
{
    this->operand=argument.operand;
}

StringNumber::~StringNumber()
{
    this->operand.clear();
}

const std::string StringNumber::toBinary() const
{
    StringNumber binaryStringNumber(*this);
    const StringNumber binaryStringNumberBase(2);
    std::string binaryString;
    bool isNegativeNumber=false;

    if(*binaryStringNumber.operand.begin()=='-')
    {
        isNegativeNumber=true;
        binaryStringNumber.operand.erase(binaryStringNumber.operand.begin());
    }

    while(binaryStringNumber.operand!="0")
    {
        binaryString.insert(binaryString.begin(), *(binaryStringNumber%binaryStringNumberBase).operand.begin());
        binaryStringNumber/=binaryStringNumberBase;
    }

    while(binaryString.size()%8!=0)///For the sign bit to show on some numbers, the binary representation has to be at least 8 bits long, this is the reason for this while loop.
    {
        binaryString.insert(binaryString.begin(), '0');
    }

    if(isNegativeNumber)///If the original String Number in decimal form was negative, we need to take the two's complement of the positive binary representation and add 1 to it for correct representation of the negative String Number in binary.
    {
        for(std::string::iterator stringIterator=binaryString.begin(); stringIterator!=binaryString.end(); ++stringIterator)
        {
            if(*stringIterator=='0')
            {
                *stringIterator='1';
            }

            else
            {
                *stringIterator='0';
            }
        }

        bool isCarry=true;

        for(std::string::reverse_iterator stringIterator=binaryString.rbegin(); stringIterator!=binaryString.rend(); ++stringIterator)
        {
            if(*stringIterator=='0'&&isCarry)
            {
                isCarry=false;
                *stringIterator='1';
            }

            else if(*stringIterator=='0'&&!isCarry)
            {
                *stringIterator='0';
            }

            else if(*stringIterator=='1'&&isCarry)
            {
                *stringIterator='0';
            }

            else
            {
                *stringIterator='1';
            }
        }

        if(isCarry)
        {
            binaryString.insert(binaryString.begin(), '1');
        }
    }

    else if(binaryString.empty())///This is the case were the String Number in decimal form is 0.
    {
        binaryString.push_back('0');
    }

    return binaryString;
}

const std::string StringNumber::toOctal() const
{
    StringNumber octalStringNumber;
    StringNumber octalStringNumberBase(1);
    std::string octalString;
    unsigned short int octalBitCount=0;

    std::string binaryString=this->toBinary();

    if(binaryString=="0")
    {
        octalString.push_back('0');
    }

    else
    {
        while(binaryString.size()%24!=0)///We are sign extending the binary string so it can fit octal numbers evenly, the reason for the number 24 is because we want at least 8 octal numbers as the octal representation and since each octal number has 3 bits, and we want to represent at least 8 of them we come to the conclusion 3*8=24.
        {
            binaryString.insert(binaryString.begin(), *binaryString.begin());
        }

        for(std::string::const_reverse_iterator stringIterator=binaryString.rbegin(); stringIterator!=binaryString.rend(); ++stringIterator)///Now we do the binary to octal conversion.
        {
            if(octalBitCount==3)
            {
                octalString.insert(octalString.begin(), *octalStringNumber.operand.begin());
                octalStringNumber.operand='0';
                octalStringNumberBase.operand='1';
                octalBitCount=0;
            }

            octalStringNumber+=octalStringNumberBase*StringNumber(std::string(1, *stringIterator));
            octalStringNumberBase*=StringNumber(2);
            ++octalBitCount;

            if(stringIterator==(binaryString.rend()-1)&&octalBitCount==3)
            {
                octalString.insert(octalString.begin(), *octalStringNumber.operand.begin());
                octalStringNumber.operand='0';
                octalStringNumberBase.operand='1';
                octalBitCount=0;
            }
        }
    }

    return octalString;
}

const std::string StringNumber::toHex() const
{
    StringNumber hexStringNumber;
    StringNumber hexStringNumberBase(1);
    std::string hexString;
    unsigned short int hexBitCount=0;

    std::string binaryString=this->toBinary();

    if(binaryString=="0")
    {
        hexString.push_back('0');
    }

    else
    {
        while(binaryString.size()%32!=0)///We are sign extending the binary string so it can fit hexadecimal numbers evenly, the reason for the number 32 is because we want at least 8 hexadecimal numbers as the hexadecimal representation and since each hexadecimal number has 4 bits, and we want to represent at least 8 of them we come to the conclusion 4*8=32.
        {
            binaryString.insert(binaryString.begin(), *binaryString.begin());
        }

        for(std::string::const_reverse_iterator stringIterator=binaryString.rbegin(); stringIterator!=binaryString.rend(); ++stringIterator)
        {
            if(hexBitCount==4)
            {
                if(hexStringNumber.operand=="10")
                {
                    hexString.insert(hexString.begin(), 'A');
                }

                else if(hexStringNumber.operand=="11")
                {
                    hexString.insert(hexString.begin(), 'B');
                }

                else if(hexStringNumber.operand=="12")
                {
                    hexString.insert(hexString.begin(), 'C');
                }

                else if(hexStringNumber.operand=="13")
                {
                    hexString.insert(hexString.begin(), 'D');
                }

                else if(hexStringNumber.operand=="14")
                {
                    hexString.insert(hexString.begin(), 'E');
                }

                else if(hexStringNumber.operand=="15")
                {
                    hexString.insert(hexString.begin(), 'F');
                }

                else
                {
                    hexString.insert(hexString.begin(), *hexStringNumber.operand.begin());
                }

                hexStringNumber.operand='0';
                hexStringNumberBase.operand='1';
                hexBitCount=0;
            }

            hexStringNumber+=hexStringNumberBase*StringNumber(std::string(1, *stringIterator));
            hexStringNumberBase*=StringNumber(2);
            ++hexBitCount;

            if(stringIterator==(binaryString.rend()-1)&&hexBitCount==4)
            {
                if(hexStringNumber.operand=="10")
                {
                    hexString.insert(hexString.begin(), 'A');
                }

                else if(hexStringNumber.operand=="11")
                {
                    hexString.insert(hexString.begin(), 'B');
                }

                else if(hexStringNumber.operand=="12")
                {
                    hexString.insert(hexString.begin(), 'C');
                }

                else if(hexStringNumber.operand=="13")
                {
                    hexString.insert(hexString.begin(), 'D');
                }

                else if(hexStringNumber.operand=="14")
                {
                    hexString.insert(hexString.begin(), 'E');
                }

                else if(hexStringNumber.operand=="15")
                {
                    hexString.insert(hexString.begin(), 'F');
                }

                else
                {
                    hexString.insert(hexString.begin(), *hexStringNumber.operand.begin());
                }

                hexStringNumber.operand='0';
                hexStringNumberBase.operand='1';
                hexBitCount=0;
            }
        }
    }

    return hexString;
}

const StringNumber StringNumber::operator++(int)
{
    const StringNumber postFixIncrement(*this);
    *this+=StringNumber(1);

    return postFixIncrement;
}

const StringNumber StringNumber::operator--(int)
{
    const StringNumber postFixDecrement(*this);
    *this-=StringNumber(1);

    return postFixDecrement;
}

const StringNumber& StringNumber::operator++()
{
    return *this+=StringNumber(1);
}

const StringNumber& StringNumber::operator--()
{
    return *this-=StringNumber(1);
}

const StringNumber StringNumber::operator+() const
{
    return *this;
}

const StringNumber StringNumber::operator-() const
{
    StringNumber unaryNegative(*this);

    if(unaryNegative.operand!="0")
    {
        if(*unaryNegative.operand.begin()!='-')
        {
            unaryNegative.operand.insert(unaryNegative.operand.begin(), '-');
        }

        else
        {
            unaryNegative.operand.erase(unaryNegative.operand.begin());
        }
    }

    return unaryNegative;
}

const StringNumber StringNumber::operator~() const
{
    StringNumber bitwiseNot;
    StringNumber binaryStringNumberBase(1);
    std::string binaryString=this->toBinary();

    for(std::string::reverse_iterator stringIterator=binaryString.rbegin(); stringIterator!=binaryString.rend(); ++stringIterator)
    {
        if(*stringIterator=='0')
        {
            *stringIterator='1';
        }

        else
        {
            *stringIterator='0';
        }

        bitwiseNot+=binaryStringNumberBase*StringNumber(std::string(1, *stringIterator));
        binaryStringNumberBase*=StringNumber(2);
    }

    if(*binaryString.begin()=='1')///You have a negative decimal number as the bitwise not since the sign bit, after NOTing the bits, is 1.
    {
        bitwiseNot-=binaryStringNumberBase;///You do this because you need to do the actual unsigned bit representation - 2^(number of bits) to represent the negative bitwise not due to the sign bit. If one implements an unsigned String Number, this step would not be needed.
    }

    return bitwiseNot;
}

const StringNumber StringNumber::operator*(const StringNumber& secondArgument) const
{
    StringNumber multiplicand(*this);
    StringNumber multiplier(secondArgument);
    StringNumber product;
    StringNumber tempProduct;

    bool isNegativeProduct=false;

    if(*multiplicand.operand.begin()=='-')
    {
        isNegativeProduct=true;
        multiplicand.operand.erase(multiplicand.operand.begin());
    }

    if(*multiplier.operand.begin()=='-')
    {
        isNegativeProduct=!isNegativeProduct;
        multiplier.operand.erase(multiplier.operand.begin());
    }

    if(multiplicand<multiplier)///This checks to see if the multiplicand's operand is the more positively greater operand. If not, we must swap the multiplicand and multiplier's operands to make sure that the multiplicand's operand is the positively greater one so the multiplication operation can work correctly.
    {
        multiplicand.operand.swap(multiplier.operand);
    }

    tempProduct.operand.clear();

    unsigned long long int fillerZeroCount=0;///Here we set up the helper variables that will help us calculate the product correctly.
    unsigned short int carry=0;
    unsigned short int currentProduct=0;
    unsigned char productOperandDigit='\0';

    for(std::string::const_reverse_iterator multiplierIterator=multiplier.operand.rbegin(); multiplierIterator!=multiplier.operand.rend(); ++multiplierIterator)///Here we perform the multiplication operation, performing the necessary integer <--> character conversions.
    {
        for(std::string::const_reverse_iterator multiplicandIterator=multiplicand.operand.rbegin(); multiplicandIterator!=multiplicand.operand.rend(); ++multiplicandIterator)
        {
            currentProduct=(*multiplicandIterator-'0')*(*multiplierIterator-'0')+carry;
            productOperandDigit=currentProduct%10+'0';
            carry=currentProduct/10;

            tempProduct.operand.insert(tempProduct.operand.begin(), productOperandDigit);
        }

        if(carry!=0)
        {
            productOperandDigit=carry%10+'0';
            tempProduct.operand.insert(tempProduct.operand.begin(), productOperandDigit);
            carry=0;
        }

        while(*tempProduct.operand.begin()=='0')///This is in case the tempProduct's operand has any leading zeros for examples such as 999*1000.
        {
            tempProduct.operand.erase(tempProduct.operand.begin());
        }

        if(tempProduct.operand.empty())
        {
            tempProduct.operand='0';
        }

        product+=tempProduct;

        tempProduct.operand.clear();

        ++fillerZeroCount;

        for(unsigned long long int fillerZero=0; fillerZero<fillerZeroCount; ++fillerZero)
        {
            tempProduct.operand.push_back('0');
        }
    }

    if(isNegativeProduct&&product.operand!="0")
    {
        product.operand.insert(product.operand.begin(), '-');
    }

    return product;
}

const StringNumber StringNumber::operator/(const StringNumber& secondArgument) const
{
    StringNumber dividend(*this);
    StringNumber divisor(secondArgument);
    StringNumber quotient;
    StringNumber remainder;
    StringNumber tempDividend;
    StringNumber tempQuotient;

    bool isNegativeQuotient=false;

    if(divisor.operand!="0")
    {
        if(*dividend.operand.begin()=='-')
        {
            isNegativeQuotient=true;
            dividend.operand.erase(dividend.operand.begin());
        }

        if(*divisor.operand.begin()=='-')
        {
            isNegativeQuotient=!isNegativeQuotient;
            divisor.operand.erase(divisor.operand.begin());
        }

        tempDividend.operand.clear();

        bool isDivisible=true;

        while(isDivisible)
        {
            for(std::string::const_iterator dividendIterator=dividend.operand.begin(); dividendIterator!=dividend.operand.end(); ++dividendIterator)
            {
                tempDividend.operand.push_back(*dividendIterator);

                if(tempDividend>=divisor)
                {
                    while(tempDividend>=divisor)
                    {
                        tempDividend-=divisor;
                        ++tempQuotient;
                    }

                    tempDividend+=tempQuotient*divisor;
                    remainder=tempDividend-tempQuotient*divisor;

                    for(std::string::const_iterator remainingDigitIterator=(dividendIterator+1); remainingDigitIterator!=dividend.operand.end(); ++remainingDigitIterator)
                    {
                        tempQuotient.operand.push_back('0');
                        remainder.operand.push_back(*remainingDigitIterator);
                    }

                    quotient+=tempQuotient;

                    while(*remainder.operand.begin()=='0')
                    {
                        remainder.operand.erase(remainder.operand.begin());
                    }

                    if(remainder.operand.empty())
                    {
                        remainder.operand='0';
                    }

                    tempDividend.operand.clear();
                    tempQuotient.operand='0';

                    dividend=remainder;

                    if(dividend<divisor)
                    {
                        isDivisible=false;
                    }

                    break;
                }

                else if(dividendIterator==(dividend.operand.end()-1))///We are about to go through all the digits of the dividend so the division is essentially done.
                {
                    isDivisible=false;
                }
            }
        }
    }

    else
    {
        throw std::runtime_error("Error: String Number division by zero.");
    }

    if(isNegativeQuotient&&quotient.operand!="0")
    {
        quotient.operand.insert(quotient.operand.begin(), '-');
    }

    return quotient;
}

const StringNumber StringNumber::operator%(const StringNumber& secondArgument) const
{
    StringNumber dividend(*this);
    StringNumber divisor(secondArgument);
    StringNumber remainder;
    StringNumber tempDividend;
    StringNumber tempQuotient;

    bool isNegativeRemainder=false;

    if(divisor.operand!="0")
    {
        if(*dividend.operand.begin()=='-')
        {
            isNegativeRemainder=true;
            dividend.operand.erase(dividend.operand.begin());
        }

        if(*divisor.operand.begin()=='-')
        {
            divisor.operand.erase(divisor.operand.begin());
        }

        tempDividend.operand.clear();

        bool isModulable=true;

        while(isModulable)
        {
            for(std::string::const_iterator dividendIterator=dividend.operand.begin(); dividendIterator!=dividend.operand.end(); ++dividendIterator)
            {
                tempDividend.operand.push_back(*dividendIterator);

                if(tempDividend>=divisor)
                {
                    while(tempDividend>=divisor)
                    {
                        tempDividend-=divisor;
                        ++tempQuotient;
                    }

                    tempDividend+=tempQuotient*divisor;
                    remainder=tempDividend-tempQuotient*divisor;

                    for(std::string::const_iterator remainingDigitIterator=(dividendIterator+1); remainingDigitIterator!=dividend.operand.end(); ++remainingDigitIterator)
                    {
                        remainder.operand.push_back(*remainingDigitIterator);
                    }

                    while(*remainder.operand.begin()=='0')
                    {
                        remainder.operand.erase(remainder.operand.begin());
                    }

                    if(remainder.operand.empty())
                    {
                        remainder.operand='0';
                    }

                    tempDividend.operand.clear();
                    tempQuotient.operand='0';

                    dividend=remainder;

                    if(dividend<divisor)
                    {
                        isModulable=false;
                    }

                    break;
                }

                else if(dividendIterator==(dividend.operand.end()-1))///We are about to go through all the digits of the dividend so the modulation is essentially done.
                {
                    remainder=dividend;
                    isModulable=false;
                }
            }
        }
    }

    else
    {
        throw std::runtime_error("Error: String Number modulation by zero.");
    }

    if(isNegativeRemainder&&remainder.operand!="0")
    {
        remainder.operand.insert(remainder.operand.begin(), '-');
    }

    return remainder;
}

const StringNumber StringNumber::operator+(const StringNumber& secondArgument) const
{
    StringNumber augend(*this);
    StringNumber addend(secondArgument);
    StringNumber sum;

    bool isNegativeSum=false;

    if((*augend.operand.begin()!='-'&&*addend.operand.begin()!='-')||(isNegativeSum=true, *augend.operand.begin()=='-'&&*addend.operand.begin()=='-'))
    {
        sum.operand.clear();///We need to clear the sum's operand because its operand was '0' by the default constructor.

        if(isNegativeSum)///If the sum is negative, then we need to erase the negative signs so as to not interfere when calculating the sum.
        {
            augend.operand.erase(augend.operand.begin());
            addend.operand.erase(addend.operand.begin());
        }

        long long int augendIndex=augend.operand.size()-1;///Here we set up the necessary variables that will help us calculate the sum correctly.
        long long int addendIndex=addend.operand.size()-1;
        unsigned short int carry=0;
        unsigned short int currentSum=0;
        unsigned char sumOperandDigit='\0';

        while(augendIndex>=0&&addendIndex>=0)///Here we calculate the sum, performing the necessary integer <--> character conversions.
        {
            currentSum=(augend.operand[augendIndex]-'0')+(addend.operand[addendIndex]-'0')+carry;
            sumOperandDigit=currentSum%10+'0';
            carry=currentSum/10;

            sum.operand.insert(sum.operand.begin(), sumOperandDigit);

            --augendIndex;
            --addendIndex;
        }

        while(augendIndex>=0)///The next while loop statements are the cases when the augend and addend's operands are not the same size, i.e. do not have the same number of digits. In those cases we must continue to do the addition algorithm and act as if either the augend or addend is zero. The program will only go through one of the loops in any of the aforementioned cases.
        {
            currentSum=(augend.operand[augendIndex]-'0')+carry;
            sumOperandDigit=currentSum%10+'0';
            carry=currentSum/10;

            sum.operand.insert(sum.operand.begin(), sumOperandDigit);

            --augendIndex;
        }

        while(addendIndex>=0)
        {
            currentSum=(addend.operand[addendIndex]-'0')+carry;
            sumOperandDigit=currentSum%10+'0';
            carry=currentSum/10;

            sum.operand.insert(sum.operand.begin(), sumOperandDigit);

            --addendIndex;
        }

        if(carry!=0)
        {
            sumOperandDigit=carry%10+'0';

            sum.operand.insert(sum.operand.begin(), sumOperandDigit);
        }

        if(isNegativeSum)
        {
            sum.operand.insert(sum.operand.begin(), '-');
        }
    }

    else if(*augend.operand.begin()=='-')///The else if and else statements are for when the augend and addend's operand signs are different. In those cases we have a subtraction problem and handle the cases appropriately.
    {
        augend.operand.erase(augend.operand.begin());

        return addend-augend;
    }

    else
    {
        addend.operand.erase(addend.operand.begin());

        return augend-addend;
    }

    return sum;
}

const StringNumber StringNumber::operator-(const StringNumber& secondArgument) const
{
    StringNumber minuend(*this);
    StringNumber subtrahend(secondArgument);
    StringNumber difference;

    bool isNegativeDifference=false;

    if((*minuend.operand.begin()!='-'&&*subtrahend.operand.begin()!='-')||(*minuend.operand.begin()=='-'&&*subtrahend.operand.begin()=='-'))
    {
        if(minuend<subtrahend)///This checks to see if the difference will be negative or not.
        {
            isNegativeDifference=true;
        }

        if(*minuend.operand.begin()=='-')///This removes the negative sign from both the operands of the minuend and subtrahend so as to not interference with subtraction operations.
        {
            minuend.operand.erase(minuend.operand.begin());
            subtrahend.operand.erase(subtrahend.operand.begin());
        }

        if(minuend<subtrahend)///This checks to see if the minuend's operand is the more positively greater operand. If not, we must swap the minuend and subtrahend's operands to make sure that the minuend's operand is the positively greater one so the subtraction operation can work correctly.
        {
            minuend.operand.swap(subtrahend.operand);
        }

        difference.operand.clear();

        long long int minuendIndex=minuend.operand.size()-1;///Here we set up the necessary variables that will help us calculate the difference correctly.
        long long int subtrahendIndex=subtrahend.operand.size()-1;
        unsigned short int borrow=0;
        short int currentMinuend=0;
        unsigned short int currentSubtrahend=0;
        unsigned short int currentDifference=0;
        unsigned char differenceOperandDigit='\0';

        while(minuendIndex>=0&&subtrahendIndex>=0)///Here we calculate the difference, performing the necessary integer <--> character conversions.
        {
            currentMinuend=(minuend.operand[minuendIndex]-'0');
            currentSubtrahend=(subtrahend.operand[subtrahendIndex]-'0');

            if(borrow!=0)
            {
                currentMinuend-=borrow;
            }

            if(currentMinuend<currentSubtrahend)
            {
                currentMinuend+=10;

                if(borrow==0)
                {
                    borrow=1;
                }
            }

            else if(borrow!=0)
            {
                borrow=0;
            }

            currentDifference=currentMinuend-currentSubtrahend;
            differenceOperandDigit=currentDifference%10+'0';

            difference.operand.insert(difference.operand.begin(), differenceOperandDigit);

            --minuendIndex;
            --subtrahendIndex;
        }

        while(minuendIndex>=0)///This is the case where the minuend has more digits than the subtrahend. If this case arises, then we must continue the subtraction algorithm and act as if the subtrahend is zero.
        {
            currentMinuend=(minuend.operand[minuendIndex]-'0');

            if(borrow!=0)
            {
                currentMinuend-=borrow;
            }

            if(currentMinuend<0)///We act as if current subtrahend is zero.
            {
                currentMinuend+=10;

                if(borrow==0)
                {
                    borrow=1;
                }
            }

            else if(borrow!=0)
            {
                borrow=0;
            }

            currentDifference=currentMinuend;
            differenceOperandDigit=currentDifference%10+'0';

            difference.operand.insert(difference.operand.begin(), differenceOperandDigit);

            --minuendIndex;
        }

        while(*difference.operand.begin()=='0')///This is done for some subtraction problems that would leave the difference with leading zeros, for example 99-98, which would lead to "01" without this check for example.
        {
            difference.operand.erase(difference.operand.begin());
        }

        if(difference.operand.empty())
        {
            difference.operand='0';
        }

        else if(isNegativeDifference)
        {
            difference.operand.insert(difference.operand.begin(), '-');
        }
    }

    else if(*minuend.operand.begin()=='-')///The else if and else statements are for when the operands have different signs. In these cases, we are dealing with an addition problem and we modify the operands of the minuend and subtrahend appropriately.
    {
        subtrahend.operand.insert(subtrahend.operand.begin(), '-');

        return minuend+subtrahend;
    }

    else
    {
        subtrahend.operand.erase(subtrahend.operand.begin());

        return subtrahend+minuend;
    }

    return difference;
}

std::istream& operator>>(std::istream& firstArgument, StringNumber& secondArgument)
{
    firstArgument>>secondArgument.operand;

    bool isNegative=false;

    if(*secondArgument.operand.begin()=='-')
    {
        isNegative=true;
    }

    else if(*secondArgument.operand.begin()=='+')
    {
        secondArgument.operand.erase(secondArgument.operand.begin());
    }

    if(isNegative)
    {
        for(std::string::const_iterator stringIterator=(secondArgument.operand.begin()+1); stringIterator!=secondArgument.operand.end(); ++stringIterator)
        {
            if(!isdigit(*stringIterator))
            {
                throw std::runtime_error("Error: Wrong number format from input stream.");
            }
        }

        while(*(secondArgument.operand.begin()+1)=='0')///This removes any leading zeros from the operand.
        {
            secondArgument.operand.erase((secondArgument.operand.begin()+1));
        }

        if(secondArgument.operand.size()==1)///This is in case where the user inputs the string literal "-0".
        {
            secondArgument.operand='0';
        }
    }

    else
    {
        for(std::string::const_iterator stringIterator=secondArgument.operand.begin(); stringIterator!=secondArgument.operand.end(); ++stringIterator)
        {
            if(!isdigit(*stringIterator))
            {
                throw std::runtime_error("Error: Wrong number format from input stream.");
            }
        }

        while(*secondArgument.operand.begin()=='0')///This removes any leading zeros from the operand.
        {
            secondArgument.operand.erase(secondArgument.operand.begin());
        }

        if(secondArgument.operand.empty())///This is in case where the user inputs the string literals "0" or "+0".
        {
            secondArgument.operand='0';
        }
    }

    return firstArgument;
}

std::ostream& operator<<(std::ostream& firstArgument, const StringNumber& secondArgument)
{
    return firstArgument<<secondArgument.operand;
}

const StringNumber StringNumber::operator<<(const StringNumber& secondArgument) const
{
    StringNumber bitwiseLeftShift;
    StringNumber binaryStringNumberBase(1);

    if(*secondArgument.operand.begin()!='-')
    {
        std::string binaryString=this->toBinary();

        for(StringNumber bitShiftCount; bitShiftCount<secondArgument; ++bitShiftCount)
        {
            binaryString.erase(binaryString.begin());
            binaryString.push_back('0');
        }

        for(std::string::const_reverse_iterator stringIterator=binaryString.rbegin(); stringIterator!=binaryString.rend(); ++stringIterator)
        {
            bitwiseLeftShift+=binaryStringNumberBase*StringNumber(std::string(1, *stringIterator));
            binaryStringNumberBase*=StringNumber(2);
        }

        if(*binaryString.begin()=='1')///You have a negative decimal number as the bitwise left shift since the sign bit after shifting is 1.
        {
            bitwiseLeftShift-=binaryStringNumberBase;///You do this because you need to do the actual unsigned bit representation - 2^(number of bits) to represent the negative bitwise left shift due to the sign bit. If one implements an unsigned String Number, this step would not be needed.
        }
    }

    else
    {
        return *this>>-secondArgument;
    }

    return bitwiseLeftShift;
}

const StringNumber StringNumber::operator>>(const StringNumber& secondArgument) const
{
    StringNumber bitwiseRightShift;
    StringNumber binaryStringNumberBase(1);

    if(*secondArgument.operand.begin()!='-')
    {
        std::string binaryString=this->toBinary();

        for(StringNumber bitShiftCount; bitShiftCount<secondArgument; ++bitShiftCount)
        {
            binaryString.erase((binaryString.end()-1));
            binaryString.insert(binaryString.begin(), *binaryString.begin());
        }

        for(std::string::const_reverse_iterator stringIterator=binaryString.rbegin(); stringIterator!=binaryString.rend(); ++stringIterator)
        {
            bitwiseRightShift+=binaryStringNumberBase*StringNumber(std::string(1, *stringIterator));
            binaryStringNumberBase*=StringNumber(2);
        }

        if(*binaryString.begin()=='1')///You have a negative decimal number as the bitwise right shift since the preserved sign bit before and after shifting is 1.
        {
            bitwiseRightShift-=binaryStringNumberBase;///You do this because you need to do the actual unsigned bit representation - 2^(number of bits) to represent the negative bitwise right shift due to the sign bit. If one implements an unsigned String Number, this step would not be needed.
        }
    }

    else
    {
        return *this<<-secondArgument;
    }

    return bitwiseRightShift;
}

const bool StringNumber::operator<(const StringNumber& secondArgument) const
{
    if(*this->operand.begin()=='-'&&*secondArgument.operand.begin()!='-')
    {
        return true;
    }

    else if(*this->operand.begin()!='-'&&*secondArgument.operand.begin()=='-')
    {
        return false;
    }

    else if(*this->operand.begin()=='-'&&*secondArgument.operand.begin()=='-')
    {
        if(this->operand.size()<secondArgument.operand.size())
        {
            return false;
        }

        else if(this->operand.size()>secondArgument.operand.size())
        {
            return true;
        }

        else
        {
            for(std::string::size_type digitCount=1; digitCount<this->operand.size(); ++digitCount)
            {
                if(this->operand[digitCount]<secondArgument.operand[digitCount])
                {
                    return false;
                }

                else if(this->operand[digitCount]>secondArgument.operand[digitCount])
                {
                    return true;
                }
            }

            return false;
        }
    }

    else
    {
        if(this->operand.size()<secondArgument.operand.size())
        {
            return true;
        }

        else if(this->operand.size()>secondArgument.operand.size())
        {
            return false;
        }

        else
        {
            for(std::string::size_type digitCount=0; digitCount<this->operand.size(); ++digitCount)
            {
                if(this->operand[digitCount]<secondArgument.operand[digitCount])
                {
                    return true;
                }

                else if(this->operand[digitCount]>secondArgument.operand[digitCount])
                {
                    return false;
                }
            }

            return false;
        }
    }
}

const bool StringNumber::operator>(const StringNumber& secondArgument) const
{
    return secondArgument<*this;
}

const bool StringNumber::operator<=(const StringNumber& secondArgument) const
{
    return !(*this>secondArgument);
}

const bool StringNumber::operator>=(const StringNumber& secondArgument) const
{
    return !(*this<secondArgument);
}

const bool StringNumber::operator==(const StringNumber& secondArgument) const
{
    return !(*this<secondArgument)&&!(*this>secondArgument);
}

const bool StringNumber::operator!=(const StringNumber& secondArgument) const
{
    return !(*this==secondArgument);
}

const StringNumber StringNumber::operator&(const StringNumber& secondArgument) const
{
    StringNumber bitwiseAnd;
    StringNumber binaryStringNumberBase(1);
    std::string firstArgumentBinaryString=this->toBinary();
    std::string secondArgumentBinaryString=secondArgument.toBinary();
    std::string bitwiseAndString;

    while(firstArgumentBinaryString.size()<secondArgumentBinaryString.size())///These two while loops are to make sure that the binary representations of the two arguments have the same number of bits so the AND operation can be done correctly.
    {
        firstArgumentBinaryString.insert(firstArgumentBinaryString.begin(), *firstArgumentBinaryString.begin());///We are sign extending the first argument binary number so it has the same number of bits as the second argument binary number.
    }

    while(firstArgumentBinaryString.size()>secondArgumentBinaryString.size())
    {
        secondArgumentBinaryString.insert(secondArgumentBinaryString.begin(), *secondArgumentBinaryString.begin());///We are sign extending the second argument binary number so it has the same number of bits as the first argument binary number.
    }

    for(std::string::size_type bitCount=0; bitCount<firstArgumentBinaryString.size(); ++bitCount)
    {
        if(firstArgumentBinaryString[bitCount]=='1'&&secondArgumentBinaryString[bitCount]=='1')
        {
            bitwiseAndString.push_back('1');
        }

        else
        {
            bitwiseAndString.push_back('0');
        }
    }

    for(std::string::const_reverse_iterator stringIterator=bitwiseAndString.rbegin(); stringIterator!=bitwiseAndString.rend(); ++stringIterator)
    {
        bitwiseAnd+=binaryStringNumberBase*StringNumber(std::string(1, *stringIterator));
        binaryStringNumberBase*=StringNumber(2);
    }

    if(*bitwiseAndString.begin()=='1')///You have a negative decimal number as the bitwise and since the sign bit after ANDing is 1.
    {
        bitwiseAnd-=binaryStringNumberBase;///You do this because you need to do the actual unsigned bit representation - 2^(number of bits) to represent the negative bitwise and due to the sign bit. If one implements an unsigned String Number, this step would not be needed.
    }

    return bitwiseAnd;
}

const StringNumber StringNumber::operator^(const StringNumber& secondArgument) const
{
    StringNumber bitwiseXor;
    StringNumber binaryStringNumberBase(1);
    std::string firstArgumentBinaryString=this->toBinary();
    std::string secondArgumentBinaryString=secondArgument.toBinary();
    std::string bitwiseXorString;

    while(firstArgumentBinaryString.size()<secondArgumentBinaryString.size())///These two while loops are to make sure that the binary representations of the two arguments have the same number of bits so the XOR operation can be done correctly.
    {
        firstArgumentBinaryString.insert(firstArgumentBinaryString.begin(), *firstArgumentBinaryString.begin());///We are sign extending the first argument binary number so it has the same number of bits as the second argument binary number.
    }

    while(firstArgumentBinaryString.size()>secondArgumentBinaryString.size())
    {
        secondArgumentBinaryString.insert(secondArgumentBinaryString.begin(), *secondArgumentBinaryString.begin());///We are sign extending the second argument binary number so it has the same number of bits as the first argument binary number.
    }

    for(std::string::size_type bitCount=0; bitCount<firstArgumentBinaryString.size(); ++bitCount)
    {
        if(firstArgumentBinaryString[bitCount]!=secondArgumentBinaryString[bitCount])
        {
            bitwiseXorString.push_back('1');
        }

        else
        {
            bitwiseXorString.push_back('0');
        }
    }

    for(std::string::const_reverse_iterator stringIterator=bitwiseXorString.rbegin(); stringIterator!=bitwiseXorString.rend(); ++stringIterator)
    {
        bitwiseXor+=binaryStringNumberBase*StringNumber(std::string(1, *stringIterator));
        binaryStringNumberBase*=StringNumber(2);
    }

    if(*bitwiseXorString.begin()=='1')///You have a negative decimal number as the bitwise xor since the sign bit after XORing is 1.
    {
        bitwiseXor-=binaryStringNumberBase;///You do this because you need to do the actual unsigned bit representation - 2^(number of bits) to represent the negative bitwise exclusive or. If one implements an unsigned String Number, this step would not be needed.
    }

    return bitwiseXor;
}

const StringNumber StringNumber::operator|(const StringNumber& secondArgument) const
{
    StringNumber bitwiseOr;
    StringNumber binaryStringNumberBase(1);
    std::string firstArgumentBinaryString=this->toBinary();
    std::string secondArgumentBinaryString=secondArgument.toBinary();
    std::string bitwiseOrString;

    while(firstArgumentBinaryString.size()<secondArgumentBinaryString.size())///These two while loops are to make sure that the binary representations of the two arguments have the same number of bits so the OR operation can be done correctly.
    {
        firstArgumentBinaryString.insert(firstArgumentBinaryString.begin(), *firstArgumentBinaryString.begin());///We are sign extending the first argument binary number so it has the same number of bits as the second argument binary number.
    }

    while(firstArgumentBinaryString.size()>secondArgumentBinaryString.size())
    {
        secondArgumentBinaryString.insert(secondArgumentBinaryString.begin(), *secondArgumentBinaryString.begin());///We are sign extending the second argument binary number so it has the same number of bits as the first argument binary number.
    }

    for(std::string::size_type bitCount=0; bitCount<firstArgumentBinaryString.size(); ++bitCount)
    {
        if(firstArgumentBinaryString[bitCount]=='1'||secondArgumentBinaryString[bitCount]=='1')
        {
            bitwiseOrString.push_back('1');
        }

        else
        {
            bitwiseOrString.push_back('0');
        }
    }

    for(std::string::const_reverse_iterator stringIterator=bitwiseOrString.rbegin(); stringIterator!=bitwiseOrString.rend(); ++stringIterator)
    {
        bitwiseOr+=binaryStringNumberBase*StringNumber(std::string(1, *stringIterator));
        binaryStringNumberBase*=StringNumber(2);
    }

    if(*bitwiseOrString.begin()=='1')///You have a negative decimal number as the bitwise or since the sign bit after ORing is 1.
    {
        bitwiseOr-=binaryStringNumberBase;///You do this because you need to do the actual unsigned bit representation - 2^(number of bits) to represent the negative bitwise or due to the sign bit. If one implements an unsigned String Number, this step would not be needed.
    }

    return bitwiseOr;
}

const StringNumber& StringNumber::operator=(const StringNumber& secondArgument)
{
    if(this!=&secondArgument)
    {
        this->operand=secondArgument.operand;
    }

    return *this;
}

const StringNumber& StringNumber::operator*=(const StringNumber& secondArgument)
{
    return *this=*this*secondArgument;
}

const StringNumber& StringNumber::operator/=(const StringNumber& secondArgument)
{
    return *this=*this/secondArgument;
}

const StringNumber& StringNumber::operator%=(const StringNumber& secondArgument)
{
    return *this=*this%secondArgument;
}

const StringNumber& StringNumber::operator+=(const StringNumber& secondArgument)
{
    return *this=*this+secondArgument;
}

const StringNumber& StringNumber::operator-=(const StringNumber& secondArgument)
{
    return *this=*this-secondArgument;
}

const StringNumber& StringNumber::operator<<=(const StringNumber& secondArgument)
{
    return *this=*this<<secondArgument;
}

const StringNumber& StringNumber::operator>>=(const StringNumber& secondArgument)
{
    return *this=*this>>secondArgument;
}

const StringNumber& StringNumber::operator&=(const StringNumber& secondArgument)
{
    return *this=*this&secondArgument;
}

const StringNumber& StringNumber::operator^=(const StringNumber& secondArgument)
{
    return *this=*this^secondArgument;
}

const StringNumber& StringNumber::operator|=(const StringNumber& secondArgument)
{
    return *this=*this|secondArgument;
}

const StringNumber absoluteValue(const StringNumber& argument)
{
    if(argument<StringNumber())
    {
        return -argument;
    }

    return argument;
}

const StringNumber exponent(const StringNumber& firstArgument, const long long int secondArgument)
{
    if(firstArgument==StringNumber()||secondArgument==1)
    {
        return firstArgument;
    }

    else if(secondArgument==0)
    {
        return StringNumber(1);
    }

    bool isNegativeExponent=false;
    long long int copySecondArgument=0;

    if(secondArgument<0)
    {
        isNegativeExponent=true;
        copySecondArgument=-((unsigned long long int)secondArgument);///This avoids overflow.
    }

    else
    {
        copySecondArgument=secondArgument;
    }

    StringNumber exponentStringNumber(1);
    StringNumber exponentStringNumberBase(firstArgument);

    while(copySecondArgument>=1)
    {
        if(copySecondArgument%2==1)
        {
            exponentStringNumber*=exponentStringNumberBase;
        }

        copySecondArgument/=2;
        exponentStringNumberBase*=exponentStringNumberBase;
    }

    if(isNegativeExponent)
    {
        exponentStringNumber=StringNumber(1)/exponentStringNumber;
    }

    return exponentStringNumber;
}

const StringNumber exponent(const StringNumber& firstArgument, const char* const secondArgument)
{
    StringNumber secondArgumentStringNumber(secondArgument);

    if(firstArgument==StringNumber()||secondArgumentStringNumber==StringNumber(1))
    {
        return firstArgument;
    }

    else if(secondArgumentStringNumber==StringNumber())
    {
        return StringNumber(1);
    }

    bool isNegativeExponent=false;

    if(secondArgumentStringNumber<StringNumber())
    {
        isNegativeExponent=true;
        secondArgumentStringNumber=-secondArgumentStringNumber;
    }

    StringNumber exponentStringNumber(1);
    StringNumber exponentStringNumberBase(firstArgument);

    while(secondArgumentStringNumber>=StringNumber(1))
    {
        if(secondArgumentStringNumber%StringNumber(2)==StringNumber(1))
        {
            exponentStringNumber*=exponentStringNumberBase;
        }

        secondArgumentStringNumber/=StringNumber(2);
        exponentStringNumberBase*=exponentStringNumberBase;
    }

    if(isNegativeExponent)
    {
        exponentStringNumber=StringNumber(1)/exponentStringNumber;
    }

    return exponentStringNumber;
}

const StringNumber exponent(const StringNumber& firstArgument, const std::string& secondArgument)
{
    StringNumber secondArgumentStringNumber(secondArgument);

    if(firstArgument==StringNumber()||secondArgumentStringNumber==StringNumber(1))
    {
        return firstArgument;
    }

    else if(secondArgumentStringNumber==StringNumber())
    {
        return StringNumber(1);
    }

    bool isNegativeExponent=false;

    if(secondArgumentStringNumber<StringNumber())
    {
        isNegativeExponent=true;
        secondArgumentStringNumber=-secondArgumentStringNumber;
    }

    StringNumber exponentStringNumber(1);
    StringNumber exponentStringNumberBase(firstArgument);

    while(secondArgumentStringNumber>=StringNumber(1))
    {
        if(secondArgumentStringNumber%StringNumber(2)==StringNumber(1))
        {
            exponentStringNumber*=exponentStringNumberBase;
        }

        secondArgumentStringNumber/=StringNumber(2);
        exponentStringNumberBase*=exponentStringNumberBase;
    }

    if(isNegativeExponent)
    {
        exponentStringNumber=StringNumber(1)/exponentStringNumber;
    }

    return exponentStringNumber;
}

const StringNumber exponent(const StringNumber& firstArgument, const StringNumber& secondArgument)
{
    StringNumber secondArgumentStringNumber(secondArgument);

    if(firstArgument==StringNumber()||secondArgumentStringNumber==StringNumber(1))
    {
        return firstArgument;
    }

    else if(secondArgumentStringNumber==StringNumber())
    {
        return StringNumber(1);
    }

    bool isNegativeExponent=false;

    if(secondArgumentStringNumber<StringNumber())
    {
        isNegativeExponent=true;
        secondArgumentStringNumber=-secondArgumentStringNumber;
    }

    StringNumber exponentStringNumber(1);
    StringNumber exponentStringNumberBase(firstArgument);

    while(secondArgumentStringNumber>=StringNumber(1))
    {
        if(secondArgumentStringNumber%StringNumber(2)==StringNumber(1))
        {
            exponentStringNumber*=exponentStringNumberBase;
        }

        secondArgumentStringNumber/=StringNumber(2);
        exponentStringNumberBase*=exponentStringNumberBase;
    }

    if(isNegativeExponent)
    {
        exponentStringNumber=StringNumber(1)/exponentStringNumber;
    }

    return exponentStringNumber;
}

const std::pair<const StringNumber, const StringNumber> nthRoot(const StringNumber& firstArgument, const long long int secondArgument)
{
    if(secondArgument==0)
    {
        throw std::runtime_error("Error: Zero nth root of a String Number.");
    }

    else if(secondArgument%2==0&&firstArgument<StringNumber())
    {
        throw std::runtime_error("Error: Even root of a negative String Number.");
    }

    else if(secondArgument==1)
    {
        return std::pair<const StringNumber, const StringNumber>(firstArgument, firstArgument);
    }

    else if(firstArgument==StringNumber()||firstArgument==StringNumber(1))
    {
        return std::pair<const StringNumber, const StringNumber>(firstArgument, firstArgument);
    }

    bool isNegativeRoot=false;
    bool isNegativeRootBase=false;
    long long int copySecondArgument=0;
    StringNumber copyFirstArgument;

    if(secondArgument<0)
    {
        isNegativeRoot=true;
        copySecondArgument=-((unsigned long long int)secondArgument);///This avoids overflow.
    }

    else
    {
        copySecondArgument=secondArgument;
    }

    if(firstArgument<StringNumber())
    {
        isNegativeRootBase=true;
        copyFirstArgument=-firstArgument;
    }

    else
    {
        copyFirstArgument=firstArgument;
    }

    StringNumber binarySearchStart;
    StringNumber binarySearchEnd(copyFirstArgument/StringNumber(copySecondArgument));///This is done for optimization purposes because given a number x when we find the nth root of x, the nth root will be no greater than x/n, where n is the degree. For example, the square root of x will be no greater than x/2.
    StringNumber binarySearchMiddle((binarySearchStart+binarySearchEnd)/StringNumber(2));

    while(binarySearchStart<=binarySearchEnd)
    {
        if(exponent(binarySearchMiddle, copySecondArgument)<copyFirstArgument)
        {
            binarySearchStart=binarySearchMiddle+StringNumber(1);
            binarySearchMiddle=(binarySearchStart+binarySearchEnd)/StringNumber(2);
        }

        else if(exponent(binarySearchMiddle, copySecondArgument)>copyFirstArgument)
        {
            binarySearchEnd=binarySearchMiddle-StringNumber(1);
            binarySearchMiddle=(binarySearchStart+binarySearchEnd)/StringNumber(2);
        }

        else
        {
            break;
        }
    }

    if(isNegativeRootBase&&secondArgument%2!=0)
    {
        binarySearchMiddle=-binarySearchMiddle;
    }

    if(isNegativeRoot)
    {
        binarySearchMiddle=StringNumber(1)/binarySearchMiddle;
    }

    if(copySecondArgument%2==0)///You have an even degree so the positive and negative root is returned since both could arrive to the original String Number by exponentiation.
    {
        return std::pair<const StringNumber, const StringNumber>(binarySearchMiddle, -binarySearchMiddle);
    }

    return std::pair<const StringNumber, const StringNumber>(binarySearchMiddle, binarySearchMiddle);
}

const std::pair<const StringNumber, const StringNumber> nthRoot(const StringNumber& firstArgument, const char* const secondArgument)
{
    StringNumber secondArgumentStringNumber(secondArgument);

    if(secondArgumentStringNumber==StringNumber())
    {
        throw std::runtime_error("Error: Zero nth root of a String Number.");
    }

    else if(secondArgumentStringNumber%StringNumber(2)==StringNumber()&&firstArgument<StringNumber())
    {
        throw std::runtime_error("Error: Even root of a negative String Number.");
    }

    else if(secondArgumentStringNumber==StringNumber(1))
    {
        return std::pair<const StringNumber, const StringNumber>(firstArgument, firstArgument);
    }

    else if(firstArgument==StringNumber()||firstArgument==StringNumber(1))
    {
        return std::pair<const StringNumber, const StringNumber>(firstArgument, firstArgument);
    }

    bool isNegativeRoot=false;
    bool isNegativeRootBase=false;
    StringNumber copyFirstArgument;

    if(secondArgumentStringNumber<StringNumber())
    {
        isNegativeRoot=true;
        secondArgumentStringNumber=-secondArgumentStringNumber;
    }

    if(firstArgument<StringNumber())
    {
        isNegativeRootBase=true;
        copyFirstArgument=-firstArgument;
    }

    else
    {
        copyFirstArgument=firstArgument;
    }

    StringNumber binarySearchStart;
    StringNumber binarySearchEnd(copyFirstArgument/secondArgumentStringNumber);///This is done for optimization purposes because given a number x when we find the nth root of x, the nth root will be no greater than x/n, where n is the degree. For example, the square root of x will be no greater than x/2.
    StringNumber binarySearchMiddle((binarySearchStart+binarySearchEnd)/StringNumber(2));

    while(binarySearchStart<=binarySearchEnd)
    {
        if(exponent(binarySearchMiddle, secondArgumentStringNumber)<copyFirstArgument)
        {
            binarySearchStart=binarySearchMiddle+StringNumber(1);
            binarySearchMiddle=(binarySearchStart+binarySearchEnd)/StringNumber(2);
        }

        else if(exponent(binarySearchMiddle, secondArgumentStringNumber)>copyFirstArgument)
        {
            binarySearchEnd=binarySearchMiddle-StringNumber(1);
            binarySearchMiddle=(binarySearchStart+binarySearchEnd)/StringNumber(2);
        }

        else
        {
            break;
        }
    }

    if(isNegativeRootBase&&secondArgumentStringNumber%StringNumber(2)!=StringNumber())
    {
        binarySearchMiddle=-binarySearchMiddle;
    }

    if(isNegativeRoot)
    {
        binarySearchMiddle=StringNumber(1)/binarySearchMiddle;
    }

    if(secondArgumentStringNumber%StringNumber(2)==StringNumber())///You have an even degree so the positive and negative root is returned since both could arrive to the original String Number by exponentiation.
    {
        return std::pair<const StringNumber, const StringNumber>(binarySearchMiddle, -binarySearchMiddle);
    }

    return std::pair<const StringNumber, const StringNumber>(binarySearchMiddle, binarySearchMiddle);
}

const std::pair<const StringNumber, const StringNumber> nthRoot(const StringNumber& firstArgument, const std::string& secondArgument)
{
    StringNumber secondArgumentStringNumber(secondArgument);

    if(secondArgumentStringNumber==StringNumber())
    {
        throw std::runtime_error("Error: Zero nth root of a String Number.");
    }

    else if(secondArgumentStringNumber%StringNumber(2)==StringNumber()&&firstArgument<StringNumber())
    {
        throw std::runtime_error("Error: Even root of a negative String Number.");
    }

    else if(secondArgumentStringNumber==StringNumber(1))
    {
        return std::pair<const StringNumber, const StringNumber>(firstArgument, firstArgument);
    }

    else if(firstArgument==StringNumber()||firstArgument==StringNumber(1))
    {
        return std::pair<const StringNumber, const StringNumber>(firstArgument, firstArgument);
    }

    bool isNegativeRoot=false;
    bool isNegativeRootBase=false;
    StringNumber copyFirstArgument;

    if(secondArgumentStringNumber<StringNumber())
    {
        isNegativeRoot=true;
        secondArgumentStringNumber=-secondArgumentStringNumber;
    }

    if(firstArgument<StringNumber())
    {
        isNegativeRootBase=true;
        copyFirstArgument=-firstArgument;
    }

    else
    {
        copyFirstArgument=firstArgument;
    }

    StringNumber binarySearchStart;
    StringNumber binarySearchEnd(copyFirstArgument/secondArgumentStringNumber);///This is done for optimization purposes because given a number x when we find the nth root of x, the nth root will be no greater than x/n, where n is the degree. For example, the square root of x will be no greater than x/2.
    StringNumber binarySearchMiddle((binarySearchStart+binarySearchEnd)/StringNumber(2));

    while(binarySearchStart<=binarySearchEnd)
    {
        if(exponent(binarySearchMiddle, secondArgumentStringNumber)<copyFirstArgument)
        {
            binarySearchStart=binarySearchMiddle+StringNumber(1);
            binarySearchMiddle=(binarySearchStart+binarySearchEnd)/StringNumber(2);
        }

        else if(exponent(binarySearchMiddle, secondArgumentStringNumber)>copyFirstArgument)
        {
            binarySearchEnd=binarySearchMiddle-StringNumber(1);
            binarySearchMiddle=(binarySearchStart+binarySearchEnd)/StringNumber(2);
        }

        else
        {
            break;
        }
    }

    if(isNegativeRootBase&&secondArgumentStringNumber%StringNumber(2)!=StringNumber())
    {
        binarySearchMiddle=-binarySearchMiddle;
    }

    if(isNegativeRoot)
    {
        binarySearchMiddle=StringNumber(1)/binarySearchMiddle;
    }

    if(secondArgumentStringNumber%StringNumber(2)==StringNumber())///You have an even degree so the positive and negative root is returned since both could arrive to the original String Number by exponentiation.
    {
        return std::pair<const StringNumber, const StringNumber>(binarySearchMiddle, -binarySearchMiddle);
    }

    return std::pair<const StringNumber, const StringNumber>(binarySearchMiddle, binarySearchMiddle);
}

const std::pair<const StringNumber, const StringNumber> nthRoot(const StringNumber& firstArgument, const StringNumber& secondArgument)
{
    StringNumber secondArgumentStringNumber(secondArgument);

    if(secondArgumentStringNumber==StringNumber())
    {
        throw std::runtime_error("Error: Zero nth root of a String Number.");
    }

    else if(secondArgumentStringNumber%StringNumber(2)==StringNumber()&&firstArgument<StringNumber())
    {
        throw std::runtime_error("Error: Even root of a negative String Number.");
    }

    else if(secondArgumentStringNumber==StringNumber(1))
    {
        return std::pair<const StringNumber, const StringNumber>(firstArgument, firstArgument);
    }

    else if(firstArgument==StringNumber()||firstArgument==StringNumber(1))
    {
        return std::pair<const StringNumber, const StringNumber>(firstArgument, firstArgument);
    }

    bool isNegativeRoot=false;
    bool isNegativeRootBase=false;
    StringNumber copyFirstArgument;

    if(secondArgumentStringNumber<StringNumber())
    {
        isNegativeRoot=true;
        secondArgumentStringNumber=-secondArgumentStringNumber;
    }

    if(firstArgument<StringNumber())
    {
        isNegativeRootBase=true;
        copyFirstArgument=-firstArgument;
    }

    else
    {
        copyFirstArgument=firstArgument;
    }

    StringNumber binarySearchStart;
    StringNumber binarySearchEnd(copyFirstArgument/secondArgumentStringNumber);///This is done for optimization purposes because given a number x when we find the nth root of x, the nth root will be no greater than x/n, where n is the degree. For example, the square root of x will be no greater than x/2.
    StringNumber binarySearchMiddle((binarySearchStart+binarySearchEnd)/StringNumber(2));

    while(binarySearchStart<=binarySearchEnd)
    {
        if(exponent(binarySearchMiddle, secondArgumentStringNumber)<copyFirstArgument)
        {
            binarySearchStart=binarySearchMiddle+StringNumber(1);
            binarySearchMiddle=(binarySearchStart+binarySearchEnd)/StringNumber(2);
        }

        else if(exponent(binarySearchMiddle, secondArgumentStringNumber)>copyFirstArgument)
        {
            binarySearchEnd=binarySearchMiddle-StringNumber(1);
            binarySearchMiddle=(binarySearchStart+binarySearchEnd)/StringNumber(2);
        }

        else
        {
            break;
        }
    }

    if(isNegativeRootBase&&secondArgumentStringNumber%StringNumber(2)!=StringNumber())
    {
        binarySearchMiddle=-binarySearchMiddle;
    }

    if(isNegativeRoot)
    {
        binarySearchMiddle=StringNumber(1)/binarySearchMiddle;
    }

    if(secondArgumentStringNumber%StringNumber(2)==StringNumber())///You have an even degree so the positive and negative root is returned since both could arrive to the original String Number by exponentiation.
    {
        return std::pair<const StringNumber, const StringNumber>(binarySearchMiddle, -binarySearchMiddle);
    }

    return std::pair<const StringNumber, const StringNumber>(binarySearchMiddle, binarySearchMiddle);
}

const StringNumber factorial(const StringNumber& argument)
{
    if(argument<StringNumber())
    {
        throw std::runtime_error("Error: Factorial of a negative String Number.");
    }

    else if(argument==StringNumber()||argument==StringNumber(1))
    {
        return StringNumber(1);
    }

    StringNumber factorialStringNumber(argument);
    StringNumber factorialStringNumberBase(argument-StringNumber(1));

    while(factorialStringNumberBase>StringNumber(1))
    {
        factorialStringNumber*=factorialStringNumberBase;
        --factorialStringNumberBase;
    }

    return factorialStringNumber;
}
