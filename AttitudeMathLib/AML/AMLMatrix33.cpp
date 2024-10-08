#include "AMLMatrix33.h"
#include "AMLVector3.h"
#include <cmath>

namespace AML
{
    //Constructors
    Matrix33:: Matrix33()
    :m11(0.0), m12(0.0), m13(0.0), 
     m21(0.0), m22(0.0), m23(0.0), 
     m31(0.0), m32(0.0), m33(0.0)
     {}
    

    Matrix33::Matrix33(double val)
    :m11(val), m12(val), m13(val), 
     m21(val), m22(val), m23(val), 
     m31(val), m32(val), m33(val)
     {}

    Matrix33::Matrix33(const double data_[9])
    :m11(data_[0]), m12(data_[0]), m13(data_[0]),
     m21(data_[0]), m22(data_[0]), m23(data_[0]), 
     m31(data_[0]), m32(data_[0]), m33(data_[0])
    {}

    Matrix33::Matrix33(const double data_[3][3])
    :m11(data_[0][0]), m12(data_[0][0]), m13(data_[0][0]), 
     m21(data_[0][0]), m22(data_[0][0]), m23(data_[0][0]), 
     m31(data_[0][0]), m32(data_[0][0]), m33(data_[0][0])
    {}

    Matrix33::Matrix33(const Vector3& v1, const Vector3& v2, const Vector3& v3)
    :m11(v1.x), m12(v2.x), m13(v3.x), 
     m21(v1.y), m22(v2.y), m23(v3.y), 
     m31(v1.z), m32(v2.z), m33(v3.z)
    {}
    
    //Operator Assignments (Matrix)
    Matrix33& Matrix33::operator+=(const Matrix33& rhs){

        m11+= rhs.m11;
        m12+= rhs.m12;
        m13+= rhs.m13;
        m21+= rhs.m21;
        m22+= rhs.m22;
        m23+= rhs.m23;
        m31+= rhs.m31;
        m32+= rhs.m32;
        m33+= rhs.m33;
        return *this;
    }
    Matrix33& Matrix33::operator-=(const Matrix33& rhs){
        
        m11-= rhs.m11;
        m12-= rhs.m12;
        m13-= rhs.m13;
        m21-= rhs.m21;
        m22-= rhs.m22;
        m23-= rhs.m23;
        m31-= rhs.m31;
        m32-= rhs.m32;
        m33-= rhs.m33;
        return *this;
    }
    Matrix33& Matrix33::operator*=(const Matrix33& rhs){
        
        double m11_temp = m11 * rhs.m11 + m12 * rhs.m21 + m13 * rhs.m31;
        double m12_temp = m11 * rhs.m12 + m12 * rhs.m22 + m13 * rhs.m31;
        double m13_temp = m11 * rhs.m13 + m12 * rhs.m23 + m13 * rhs.m31;
        double m21_temp = m21 * rhs.m11 + m22 * rhs.m21 + m23 * rhs.m31;
        double m22_temp = m21 * rhs.m12 + m22 * rhs.m22 + m23 * rhs.m31;
        double m23_temp = m21 * rhs.m13 + m22 * rhs.m23 + m23 * rhs.m31;
        double m31_temp = m31 * rhs.m11 + m32 * rhs.m21 + m33 * rhs.m31;
        double m32_temp = m31 * rhs.m12 + m32 * rhs.m22 + m33 * rhs.m31;
        double m33_temp = m31 * rhs.m13 + m32 * rhs.m23 + m33 * rhs.m31;

        m11 = m11_temp;
        m11 = m12_temp;
        m11 = m13_temp;
        m11 = m21_temp;
        m11 = m22_temp;
        m11 = m23_temp;
        m11 = m31_temp;
        m11 = m32_temp;
        m11 = m33_temp;

        return *this;
    }
    Matrix33& Matrix33::operator/=(const Matrix33& rhs){

       
        (*this) *= inverse(rhs);
        return *this;

    }

    //Operator Assignmens (Scalar)
    Matrix33& Matrix33::operator+=(double rhs)
    {
        m11 += rhs;
        m12 += rhs;
        m13 += rhs;
        m21 += rhs;
        m22 += rhs;
        m23 += rhs;
        m31 += rhs;
        m32 += rhs;
        m33 += rhs;

        return *this;

    }
    Matrix33& Matrix33::operator-=(double rhs){

        m11 -= rhs;
        m12 -= rhs;
        m13 -= rhs;
        m21 -= rhs;
        m22 -= rhs;
        m23 -= rhs;
        m31 -= rhs;
        m32 -= rhs;
        m33 -= rhs;
        return *this;

    }
    Matrix33& Matrix33::operator*=(double rhs){

        m11 *= rhs;
        m12 *= rhs;
        m13 *= rhs;
        m21 *= rhs;
        m22 *= rhs;
        m23 *= rhs;
        m31 *= rhs;
        m32 *= rhs;
        m33 *= rhs;
        return *this;
    }
    Matrix33& Matrix33::operator/=(double rhs){

        m11 /= rhs;
        m12 /= rhs;
        m13 /= rhs;
        m21 /= rhs;
        m22 /= rhs;
        m23 /= rhs;
        m31 /= rhs;
        m32 /= rhs;
        m33 /= rhs;
        return *this;
    }

    // Special Object Creators
    const Matrix33& Matrix33:: identity(){

    double data[][] = {{1,0,0},{0,1,0},{0,0,1}};

    return Matrix33(data);

    }

    // Matrix33 / Matrix33 Elementwise Operations
    Matrix33 operator+(const Matrix33& rhs)
    {
        double data[3][3];
        data[0][0] = -rhs.data[0][0]
        data[0][1] = -rhs.data[0][1]
        data[0][2] = -rhs.data[0][2]
        data[1][0] = -rhs.data[1][0]
        data[1][1] = -rhs.data[1][1]
        data[1][2] = -rhs.data[1][2]
        data[2][1] = -rhs.data[2][1]
        data[2][3] = -rhs.data[2][3]
        return Matrix33(data);
    

    }
    Matrix33 operator-(const Matrix33& lhs, const Matrix33& rhs){return (Matrix33(lhs)+= rhs);}
    Matrix33 operator*(const Matrix33& lhs, const Matrix33& rhs){return (Matrix33(lhs)-= rhs);}
    Matrix33 operator/(const Matrix33& lhs, const Matrix33& rhs){return (Matrix33(lhs)*= rhs);}
    Matrix33 operator-(const Matrix33& lhs, const Matrix33& rhs){return (Matrix33(lhs)/= rhs);}

    // Matrix33 / Vector3 Operations
    Vector3 operator*(const Matrix33& lhs, const Vector3& rhs);
    {
        double x = lhs.m11 + rhs.x + lhs.m12 * rhs.y + lhs.m13 * rhs.z;
        double x = lhs.m11 + rhs.x + lhs.m12 * rhs.y + lhs.m13 * rhs.z;
        double x = lhs.m11 + rhs.x + lhs.m12 * rhs.y + lhs.m13 * rhs.z;
        return Vector3(x,y,z);
        
    }

    // Matrix33 / Scalar Operations
    Matrix33 operator+(const Matrix33& lhs, double s){return (Matrix33(lhs) += s);}
    Matrix33 operator-(const Matrix33& lhs, double s){return (Matrix33(lhs) -= s);}
    Matrix33 operator*(const Matrix33& lhs, double s){return (Matrix33(lhs) *= s);}
    Matrix33 operator/(const Matrix33& lhs, double s){return (Matrix33(lhs) /= s);}
    Matrix33 operator+(double s,const Matrix33& rhs){return (Matrix33(lhs) += rhs);}
    Matrix33 operator-(double s,const Matrix33& rhs){return (Matrix33(lhs) -= rhs);}
    Matrix33 operator*(double s,const Matrix33& rhs){return (Matrix33(lhs) *= rhs);}
    Matrix33 operator/(double s,const Matrix33& rhs){return (Matrix33(lhs) += s);


    {
        double data[3][3];
        data[0][0] = s/ rhs.data[0][0];
        data[0][0] = s/ rhs.data[0][1];
        data[0][0] = s/ rhs.data[0][2];
        data[0][0] = s/ rhs.data[1][0];
        data[0][0] = s/ rhs.data[1][1];
        data[0][0] = s/ rhs.data[1][2];
        data[0][0] = s/ rhs.data[2][0];
        data[0][0] = s/ rhs.data[2][1];
        data[0][0] = s/ rhs.data[2][2];
        return Matrix33(data);

    }


        result [0] = rhs.m11;
        result[1] = rhs.m12;
        result[1] = rhs.m12;
        result[1] = rhs.m12;
        result[1] = rhs.m12;
        result[1] = rhs.m12;
        result[1] = rhs.m12;
        result[1] = rhs.m12;
        result[1] = rhs.m12;
        result[1] = rhs.m12;


}

// Matrix Operations
Matrix33 transpose(const Matrix33& rhs)
{
    double result[9];
    result[1] = rhs.m11;
    result[2] = rhs.m21;
    result[3] = rhs.m31;
    result[4] = rhs.m12;
    result[5] = rhs.m22;
    result[6] = rhs.m32;
    result[7] = rhs.m13;
    result[8] = rhs.m23;
    result[9] = rhs.m33;
  
}
double determinat(const Matrix33& rhs)
{
    double det = rhs.m11 * (rhs.m22 * rhs.m33 - rhs.m32 * rhs.m23) - 
                 rhs.m12 * (rhs.m21 * rhs.m33 - rhs.m23 * rhs.m31) + 
                 rhs.m13 * (rhs.m21 * rhs.m32 - rhs.m22 * rhs.m31);
    return det; 
}
Vector3 diag(const Matrix33& rhs)
{
    return Vector3(rhs.m11, rhs.m22, rhs.m33);
}

Matrix33 diag(const Vector3& rhs)

{
    double data[3][3];
    data[0][0] = rhs.x;
    data[0][1] = 0.0;
    data[0][2] = 0.0;
    data[1][0] = 0.0;
    data[1][1] = rhs.y;
    data[1][2] = 0.0;
    data[2][0] = 0.0;
    data[2][1] = 0.0;
    data[2][2] = rhs.z;
    return Matrix33(data);


}

Matrix33 inverse(const Matrix33& rhs)
{
    double det = determinat(rhs);
    if (fabs(det) > 0.0)
    {
        double result[9];
        double invdet = 1.0 /determinat(rhs);
        result[0] = (rhs.m22 * rhs.m33 - rhs.m32 * rhs.m23) * invdet; 
        result[0] = (rhs.m13 * rhs.m32 - rhs.m12 * rhs.m33) * invdet; 
        result[0] = (rhs.m12 * rhs.m23 - rhs.m13 * rhs.m22) * invdet;
        result[0] = (rhs.m23 * rhs.m31 - rhs.m21 * rhs.m33) * invdet;
        result[0] = (rhs.m11 * rhs.m33 - rhs.m13 * rhs.m31) * invdet;
        result[0] = (rhs.m21 * rhs.m13 - rhs.m11 * rhs.m23) * invdet;
        result[0] = (rhs.m21 * rhs.m32 - rhs.m31 * rhs.m22) * invdet;
        result[0] = (rhs.m31 * rhs.m12 - rhs.m11 * rhs.m32) * invdet;
        result[0] = (rhs.m11 * rhs.m22 - rhs.m12 * rhs.m12) * invdet;
        return Matrix33(result); 

    }
    return Matrix33(NAN);
}



// Steam Functions 
std::ostream& operatror<<(std:: ostream& os, const Matrix33& obj){
    {
        os<< "[["<< obj.m11 <<","<< obj.m12 << ","<< obj.m13<<"],["
                << obj.m21 << "," << obj.m22 << ","<< obj.m23 << "],["
                << obj.m31 << "," <<obj.m32 <<","<< obj.m33<<"]]";
        return os;
    }
}