#include <iostream>

using namespace std;

class Fraction
{
private:
    int numerator;
    int denominator;

    int hcf(int a, int b)
    {
        if (a == 0) return b;
        if (b == 0) return a;

        if (a > b) return hcf(a-b, b);
        return hcf(a, b-a);
    }

public:
    Fraction()
    {
        numerator = 1;
        denominator = 1;
    }

    Fraction(int num, int den)
    {
        numerator = num;
        denominator = den;
    }

    Fraction reduce_fraction(Fraction &f)
    {
        Fraction frac;
        int gcd = hcf(f.numerator, f.denominator);
        frac.numerator = f.numerator / gcd;
        frac.denominator = f.denominator / gcd;

        return frac;
    }

    Fraction operator+(const Fraction &f)
    {
        Fraction frac;
        if (this->denominator != f.denominator)
        {
            frac.numerator = (this->numerator * f.denominator) + (this->denominator * f.numerator);
            frac.denominator = (this->denominator * f.denominator);
        }
        else
        {
            frac.numerator = this->numerator + f.numerator;
            frac.denominator = this->denominator;
        }

        return frac;
    }

    Fraction operator-(const Fraction &f)
    {
        Fraction frac;
        if (this->denominator != f.denominator)
        {
            frac.numerator = (this->numerator * f.denominator) - (this->denominator * f.numerator);
            frac.denominator = (this->denominator * f.denominator);
        }
        else
        {
            frac.numerator = this->numerator - f.numerator;
            frac.denominator = this->denominator;
        }

        return frac;
    }

    Fraction operator/(const Fraction &f)
    {
        Fraction frac;
        frac.numerator = this->numerator * f.denominator;
        frac.denominator = this->denominator * f.numerator;

        return reduce_fraction(frac);
    }

    Fraction operator*(const Fraction &f)
    {
        Fraction frac;
        frac.numerator = this->numerator * f.numerator;
        frac.denominator = this->denominator * f.denominator;

        return reduce_fraction(frac);
    }

    friend istream &operator>>(istream &input, Fraction &F)
    {
        input >> F.numerator >> F.denominator;
        return input;
    }

    friend ostream &operator<<(ostream &output, Fraction &F)
    {
        output << F.numerator << "/" << F.denominator;
        return output;
    }
};

int main()
{
    Fraction f1(4, 2), f2(4, 8), f3;
    f3 = f1 * f2;
    cout << f3 << endl;
    return 0;
}