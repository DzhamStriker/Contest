#include <iostream>
#include <math.h>
using namespace std;

class Complex {
private:
    double R;
    double I;

public:
    Complex(double Re, double Im) {
        this->R = Re;
        this->I = Im;
    }

    Complex(double Re) {
        this->R = Re;
        this->I = 0;
    }

    double Re() const {
        return R;
    }

    double Im() const {
        return I;
    }

    Complex operator + (Complex com) {
        Complex result(R + com.Re(), I + com.Im());
        return result;
    }

    Complex operator + (double com) {
        Complex result(R + com, I);
        return result;
    }

    Complex operator + () {
        Complex result(R, I);
        return result;
    }

    Complex operator - (Complex com) {
        Complex result(R - com.Re(), I - com.Im());
        return result;
    }

    Complex operator - (double com) {
        Complex result(R - com, I);
        return result;
    }

    Complex operator - () {
        Complex result(-R, -I);
        return result;
    }

    Complex operator * (Complex com) {
        Complex result(R * com.Re() - I * com.Im(), R * com.Im() + I * com.Re());
        return result;
    }

    Complex operator * (double com) {
        Complex result(R * com, I * com);
        return result;
    }

    Complex operator / (Complex com) {
        Complex result((R * com.Re() + I * com.Im()) / (pow(com.Re(), 2) +
            pow(com.Im(), 2)), (I * com.Re() - R * com.Im()) / (pow(com.Re(), 2) +
            pow(com.Im(), 2)));
        return result;
    }

    Complex operator / (double com) {
        Complex result(R / com + I / com);
        return result;
    }

    bool operator == (Complex com) {
        return ((R == com.Re()) && (I == com.Im()));
    }

    bool operator != (Complex com) {
        return ((R != com.Re()) || (I != com.Im()));
    }
};

double abs(Complex com) {
    return sqrt(pow(com.Re(), 2) + pow(com.Im(), 2));
}

Complex operator * (double com, Complex c) {
    Complex result(c.Re() * com, c.Im() * com);
    return result;
}