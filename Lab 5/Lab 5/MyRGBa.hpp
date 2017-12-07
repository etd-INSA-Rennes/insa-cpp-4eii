
#ifndef MYRGBA_H
#define MYRGBA_H

class MyRGBa
 {
 public:
    MyRGBa() : R_(0), G_(0), B_(0), A_(0) {}
    MyRGBa(const unsigned char r, const unsigned char g, const unsigned char b, const unsigned char a = 0) : R_(r), G_(g), B_(b), A_(a) {}
    MyRGBa(const unsigned char v) : R_(v), G_(v), B_(v), A_(0) {}
    //rule of 3 : no copy ctor, no copy assigment, no dtor


    //accessors
    inline unsigned char getR() const {return R_;}
    inline unsigned char getG() const {return G_;}
    inline unsigned char getB() const {return B_;}
    inline unsigned char getA() const {return A_;}

    //operators
    bool operator==(const MyRGBa &v) const;
    bool operator!=(const MyRGBa &v) const;

    MyRGBa operator-(const MyRGBa &v) const;
    MyRGBa operator+(const MyRGBa &v) const;

    bool operator<(const MyRGBa &v) const;
    bool operator>(const MyRGBa &v) const;


    inline unsigned char getGreyValue() const {return R_*0.299 + G_*0.587 + B_*0.114;}

private:
    unsigned char R_ ;
    unsigned char G_ ;
    unsigned char B_ ;
    unsigned char A_ ;

 } ;

#endif


