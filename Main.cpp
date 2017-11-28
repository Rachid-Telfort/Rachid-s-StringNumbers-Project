#include"StringNumber.h"

int main()
{
    ///This will show some examples of how one can use String Numbers. For the most part, they work like your normal integers except that you will be able to work with really large numbers.
    ///In addition, some examples will be used as test cases to check for the correctness of String Number operations.
    std::cout<<"Welcome to the String Numbers samples/tests!\n"<<std::endl;
    std::cout<<"We will get started...\n\n"<<std::endl;


    ///***Start Constructors examples
    ///NOTE: There will be no destructor example due to the destructor being accessed at the end of the scope of main() due to stack unwinding.
    std::cout<<"Entering Constructors examples...\n"<<std::endl;
    StringNumber firstSample;///Default constructor, firstSample should be 0.
    StringNumber secondSample(+256);///Long long int argument constructor, secondSample should be 256.
    StringNumber thirdSample("-500");///String literal a.k.a const char* const constructor, thirdSample should be -500.
    StringNumber fourthSample(secondSample);///Copy constructor, fourthSample should be equal to secondSample.
    std::cout<<"Printing Constructor examples...\n"<<std::endl;
    std::cout<<"Default constructor is "<<firstSample<<"\n"<<"Long long int argument constructor is "<<secondSample<<"\n"<<"String literal constructor is "<<thirdSample<<"\n"<<"Copy constructor is "<<fourthSample<<"\n"<<std::endl;
    std::cout<<"Exiting Constructors examples...\n\n"<<std::endl;
    ///***End Constructors examples


    ///***Start Bases examples
    ///These examples will show that you can get the result of a String Number other than base 10.
    std::cout<<"Entering Bases examples...\n"<<std::endl;
    StringNumber fifthSample(-123456789);
    std::cout<<"The sample for the base tests is "<<fifthSample<<".\n"<<std::endl;
    std::cout<<fifthSample<<" to binary: "<<fifthSample.toBinary()<<std::endl;
    std::cout<<fifthSample<<" to octal: "<<fifthSample.toOctal()<<std::endl;
    std::cout<<fifthSample<<" to hex: "<<fifthSample.toHex()<<"\n"<<std::endl;
    std::cout<<"Exiting Bases examples...\n\n"<<std::endl;
    ///***End Bases examples


    ///***Start Postfix/Prefix tests
    ///These tests will check the correctness of the postfix and prefix increment and decrement operators.
    std::cout<<"Entering Postfix/Prefix tests...\n"<<std::endl;
    StringNumber sixthSample;

    std::cout<<"Before postfix increment the sample is "<<sixthSample<<std::endl;
    for(; sixthSample<StringNumber(10000); sixthSample++){};
    std::cout<<"After postfix increment the sample is "<<sixthSample<<std::endl;
    if(sixthSample==StringNumber(10000))
    {
        std::cout<<"Postfix increment test passed!"<<"\n"<<std::endl;
    }

    else
    {
        std::cout<<"Postfix increment test failed!"<<"\n"<<std::endl;
    }

    std::cout<<"Before postfix decrement the sample is "<<sixthSample<<std::endl;
    for(; sixthSample>StringNumber(-10000); sixthSample--){};
    std::cout<<"After postfix decrement the sample is "<<sixthSample<<std::endl;
    if(sixthSample==StringNumber(-10000))
    {
        std::cout<<"Postfix decrement test passed!"<<"\n"<<std::endl;
    }

    else
    {
        std::cout<<"Postfix decrement test failed!"<<"\n"<<std::endl;
    }

    std::cout<<"Before prefix increment the sample is "<<sixthSample<<std::endl;
    for(; sixthSample<StringNumber(1000000); ++sixthSample){};
    std::cout<<"After prefix increment the sample is "<<sixthSample<<std::endl;
    if(sixthSample==StringNumber(1000000))
    {
        std::cout<<"Prefix increment test passed!"<<"\n"<<std::endl;
    }

    else
    {
        std::cout<<"Prefix increment test failed!"<<"\n"<<std::endl;
    }

    std::cout<<"Before prefix decrement the sample is "<<sixthSample<<std::endl;
    for(; sixthSample>StringNumber(-1000000); --sixthSample){};
    std::cout<<"After prefix decrement the sample is "<<sixthSample<<std::endl;
    if(sixthSample==StringNumber(-1000000))
    {
        std::cout<<"Prefix decrement test passed!"<<"\n"<<std::endl;
    }

    else
    {
        std::cout<<"Prefix decrement test failed!"<<"\n"<<std::endl;
    }
    std::cout<<"Exiting Postfix/Prefix tests...\n\n"<<std::endl;
    ///***End Postfix/Prefix increment tests


    ///***Start Arithmetic tests
    ///These tests will check the correctness of the arithmetic operators.
    std::cout<<"Entering Arithmatic tests...\n"<<std::endl;
    StringNumber eighthSample;

    std::cout<<"Before adding 145 the sample is "<<eighthSample<<std::endl;
    std::cout<<"After adding 145 the sample is "<<(eighthSample+=StringNumber(145))<<std::endl;
    if(eighthSample==StringNumber(145))
    {
        std::cout<<"Addition test passed!"<<"\n"<<std::endl;
    }

    else
    {
        std::cout<<"Addition test failed!"<<"\n"<<std::endl;
    }

    std::cout<<"Before subtracting 190 the sample is "<<eighthSample<<std::endl;
    std::cout<<"After subtracting 190 the sample is "<<(eighthSample-=StringNumber(190))<<std::endl;
    if(eighthSample==StringNumber(-45))
    {
        std::cout<<"Subtraction test passed!"<<"\n"<<std::endl;
    }

    else
    {
        std::cout<<"Subtraction test failed!"<<"\n"<<std::endl;
    }

    std::cout<<"Before multiplying by 190 the sample is "<<eighthSample<<std::endl;
    std::cout<<"After multiplying by 190 the sample is "<<(eighthSample*=StringNumber(190))<<std::endl;
    if(eighthSample==StringNumber(-8550))
    {
        std::cout<<"Multiplication test passed!"<<"\n"<<std::endl;
    }

    else
    {
        std::cout<<"Multiplication test failed!"<<"\n"<<std::endl;
    }

    std::cout<<"Before dividing by 200 the sample is "<<eighthSample<<std::endl;
    std::cout<<"After dividing by 200 the sample is "<<(eighthSample/=StringNumber(200))<<std::endl;
    if(eighthSample==StringNumber(-42))
    {
        std::cout<<"Division test passed!"<<"\n"<<std::endl;
    }

    else
    {
        std::cout<<"Division test failed!"<<"\n"<<std::endl;
    }

    std::cout<<"Before modulation by 11 the sample is "<<eighthSample<<std::endl;
    std::cout<<"After modulation by 11 the sample is "<<(eighthSample%=StringNumber(11))<<std::endl;
    if(eighthSample==StringNumber(-9))
    {
        std::cout<<"Modulation test passed!"<<"\n"<<std::endl;
    }

    else
    {
        std::cout<<"Modulation test failed!"<<"\n"<<std::endl;
    }
    std::cout<<"Exiting Arithmetic tests...\n\n"<<std::endl;
    ///***End Arithmetic tests


    ///***Start Bitwise tests
    ///These tests will check the correctness of the bitwise operators.
    std::cout<<"Entering Bitwise tests...\n"<<std::endl;
    StringNumber ninthSample(1);

    std::cout<<"Before shifting left 7 bits the sample is "<<ninthSample<<std::endl;
    std::cout<<"After shifting left 7 bits the sample is "<<(ninthSample<<=StringNumber(7))<<std::endl;
    if(ninthSample==StringNumber(-128))
    {
        std::cout<<"Bitwise left shift test passed!"<<"\n"<<std::endl;
    }

    else
    {
        std::cout<<"Bitwise left shift test failed!"<<"\n"<<std::endl;
    }

    std::cout<<"Before shifting right 7 bits the sample is "<<ninthSample<<std::endl;
    std::cout<<"After shifting right 7 bits the sample is "<<(ninthSample>>=StringNumber(7))<<std::endl;
    if(ninthSample==StringNumber(-1))
    {
        std::cout<<"Bitwise right shift test passed!"<<"\n"<<std::endl;
    }

    else
    {
        std::cout<<"Bitwise right shift test failed!"<<"\n"<<std::endl;
    }

    std::cout<<"Before ANDing by "<<-2<<" the sample is "<<ninthSample<<std::endl;
    std::cout<<"After ANDing by "<<-2<<" the sample is "<<(ninthSample&=StringNumber(-2))<<std::endl;
    if(ninthSample==StringNumber(-2))
    {
        std::cout<<"ANDing test passed!"<<"\n"<<std::endl;
    }

    else
    {
        std::cout<<"ANDing test failed!"<<"\n"<<std::endl;
    }

    std::cout<<"Before XORing by "<<-2<<" the sample is "<<ninthSample<<std::endl;
    std::cout<<"After XORing by "<<-2<<" the sample is "<<(ninthSample^=StringNumber(-2))<<std::endl;
    if(ninthSample==StringNumber())
    {
        std::cout<<"XORing test passed!"<<"\n"<<std::endl;
    }

    else
    {
        std::cout<<"XORing test failed!"<<"\n"<<std::endl;
    }

    std::cout<<"Before ORing by "<<256<<" the sample is "<<ninthSample<<std::endl;
    std::cout<<"After ORing by "<<256<<" the sample is "<<(ninthSample|=StringNumber(256))<<std::endl;
    if(ninthSample==StringNumber(256))
    {
        std::cout<<"ORing test passed!"<<"\n"<<std::endl;
    }

    else
    {
        std::cout<<"ORing test failed!"<<"\n"<<std::endl;
    }
     std::cout<<"Exiting Bitwise tests...\n\n"<<std::endl;
    ///***End Bitwise tests


    ///***Start Relational tests
    ///These tests will check for the correctness of the relational operators.
    std::cout<<"Entering relational tests...\n"<<std::endl;
    StringNumber tenthSample(500);
    StringNumber eleventhSample(700);

    std::cout<<"Testing if "<<tenthSample<<" is less than "<<eleventhSample<<std::endl;
    if(tenthSample<eleventhSample)
    {
        std::cout<<"Less than test passed!\n"<<std::endl;
    }

    else
    {
        std::cout<<"Less than test failed!\n"<<std::endl;
    }

    std::cout<<"Testing if "<<tenthSample<<" is greater than "<<eleventhSample-StringNumber(300)<<std::endl;
    if(tenthSample>eleventhSample-StringNumber(300))
    {
        std::cout<<"Greater than test passed!\n"<<std::endl;
    }

    else
    {
        std::cout<<"Greater than test failed!\n"<<std::endl;
    }

    std::cout<<"Testing if "<<tenthSample<<" is less than or equal to "<<eleventhSample<<std::endl;
    if(tenthSample<=eleventhSample)
    {
        std::cout<<"Less than or equal to test passed!\n"<<std::endl;
    }

    else
    {
        std::cout<<"Less than or equal to test failed!\n"<<std::endl;
    }

    std::cout<<"Testing if "<<tenthSample<<" is greater than or equal to "<<tenthSample<<std::endl;
    if(tenthSample>=tenthSample)
    {
        std::cout<<"Greater than or equal to test passed!\n"<<std::endl;
    }

    else
    {
        std::cout<<"Greater than or equal to test failed!\n"<<std::endl;
    }

    std::cout<<"Testing if "<<eleventhSample<<" is equal to "<<eleventhSample<<std::endl;
    if(eleventhSample==eleventhSample)
    {
        std::cout<<"Equal to test passed!\n"<<std::endl;
    }

    else
    {
        std::cout<<"Equal to test failed!\n"<<std::endl;
    }

    std::cout<<"Testing if "<<tenthSample<<" is not equal to "<<eleventhSample<<std::endl;
    if(tenthSample!=eleventhSample)
    {
        std::cout<<"Not equal to test passed!\n"<<std::endl;
    }

    else
    {
        std::cout<<"Not equal to test failed!\n"<<std::endl;
    }
    std::cout<<"Exiting Relational tests...\n\n"<<std::endl;
    ///***End Relational tests


    ///***Start Advanced Operations examples
    ///These examples will show some advanced operations one can do with String Numbers such as raising a String Number to a certain power and finding the nth root of a String Number.
    std::cout<<"Entering Advanced operations examples...\n"<<std::endl;
    StringNumber twelfthSample(30);
    StringNumber thirteenthSample("0123456789101112131415161718192021222324252627282930313233343536373839404142434445464748495051525354555657585960616263646566676869707172737475767778798081828384858687888990919293949596979899100");
    std::cout<<twelfthSample<<" raised to the 100th power is "<<exponent(twelfthSample, 100)<<"\n"<<std::endl;
    std::cout<<"The possible square roots of "<<thirteenthSample<<"\nare\n"<<nthRoot(thirteenthSample, 2).first<<"\nand\n"<<nthRoot(thirteenthSample, 2).second<<"\n"<<std::endl;
    std::cout<<twelfthSample<<"! is "<<factorial(twelfthSample)<<"\n"<<std::endl;
    std::cout<<"Exiting Advanced Operations examples...\n\n"<<std::endl;
    ///***End Advanced Operations examples


    ///Ending all tests
    std::cout<<"These were some of the ways one can use String Numbers. Hope you, the user, finds this project useful for your needs!\n"<<std::endl;

    while(true){};///This is to keep the executable from closing so one can scroll through the examples.

    return 0;
}
