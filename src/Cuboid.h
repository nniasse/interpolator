#include <array>

/////////////////////////////////* 1D Cuboid Class *////////////////////////////////

template < typename T >
using Origin1d = T[1];

template < typename T >
using Spacing1d = T[1];

template < typename T >
using Data1d = T[2];


template < typename T >
class Cuboid1d
{
public:
	Cuboid1d(Origin1d<T> origin, Spacing1d<T> spacing, Data1d<T> cornerData);
	T operator()(T x);
	~Cuboid1d();
private:

	T xmin, xmax;
	T one_dx;
	Data1d<T>  data;
	static const T one;
};

template <>
const float Cuboid1d<float>::one = 1.0f;

template <>
const double Cuboid1d<double>::one = 1.0;


template < typename T >
Cuboid1d<T>::Cuboid1d(Origin1d<T> origin, Spacing1d<T> spacing, Data1d<T> cornerData)
	: xmin(origin[0]), xmax(origin[0] + spacing[0]),
	one_dx(one / spacing[0])
{
	memcpy(data, cornerData, sizeof(Data1d<T>));
}

/* The actual interpolator */
template < typename T >
T Cuboid1d<T>::operator()(T x)
{
	T x0, x1;

	x1 = std::min(std::max(x, xmin), xmax); // safety
	x1 = (x1 - xmin)*one_dx;

	x0 = one - x1;

	/* Note: we can speed it up by developing the coefficients */
	return  data[0] * x0 +
			data[1] * x1;
}


template < typename T >
Cuboid1d<T>::~Cuboid1d()
{
}
////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////* 2D Cuboid Class *////////////////////////////////

template < typename T >
using Origin2d = T[2]; 

template < typename T >
using Spacing2d = T[2];

template < typename T >
using Data2d = T[2][2];


template < typename T >
class Cuboid2d
{
public:
	Cuboid2d(Origin2d<T> origin, Spacing2d<T> spacing, Data2d<T> cornerData);
	T operator()(T x, T y);
	~Cuboid2d();
private:

	T xmin, xmax, ymin, ymax;
	T one_dx, one_dy;
	Data2d<T>  data;
	static const T one;
};

template <>
const float Cuboid2d<float>::one = 1.0f;

template <>
const double Cuboid2d<double>::one = 1.0;


template < typename T >
Cuboid2d<T>::Cuboid2d(Origin2d<T> origin, Spacing2d<T> spacing, Data2d<T> cornerData)
	: xmin(origin[0]), xmax(origin[0] + spacing[0]),
	ymin(origin[1]), ymax(origin[1] + spacing[1]),
	one_dx(one / spacing[0]), one_dy(one / spacing[1])
{
	memcpy(data, cornerData, sizeof(Data2d<T>));
}

/* The actual interpolator */
template < typename T >
T Cuboid2d<T>::operator()(T x, T y)
{
	T x0, x1, y0, y1;

	x1 = std::min(std::max(x, xmin), xmax); // safety
	y1 = std::min(std::max(y, ymin), ymax); // safety

	x1 = (x1 - xmin)*one_dx;
	y1 = (y1 - ymin)*one_dy;

	x0 = one - x1;
	y0 = one - y1;

	/* Note: we can speed it up by developing the coefficients */
	return  data[0][0] * x0*y0 +
			data[1][0] * x1*y0 +
			data[0][1] * x0*y1 +
			data[1][1] * x1*y1;
}


template < typename T >
Cuboid2d<T>::~Cuboid2d()
{
}
////////////////////////////////////////////////////////////////////////////////////



/////////////////////////////////* 3D Cuboid Class *////////////////////////////////

template < typename T >
using Origin3d  = T[3]; // origin[3];

template < typename T >
using Spacing3d = T[3];

template < typename T >
using Data3d = T[2][2][2];

//using Vector3d = std::vector<std::vector<std::vector<T>>>;

template < typename T >
class Cuboid3d
{
public:
	Cuboid3d(Origin3d<T> origin, Spacing3d<T> spacing, Data3d<T> cornerData);
	T operator()(T x, T y, T z);
	//T const & operator()(T x, T y, T z) const;
	//Cuboid3d(const T origin[3], const T spacing[3], const T data[2][2][2]);
	//Cuboid3d(const Vector3d<T> &values);
	//Cuboid3d(std::vector<T> &values);
	~Cuboid3d();

private:

	T xmin, xmax, ymin, ymax, zmin, zmax;
	T one_dx, one_dy, one_dz;
	Data3d<T>  data;

	static const T one;
	//std::vector<T> data;
};

template <>
const float Cuboid3d<float>::one = 1.0f;

template <>
const double Cuboid3d<double>::one = 1.0;


template < typename T >
Cuboid3d<T>::Cuboid3d(Origin3d<T> origin, Spacing3d<T> spacing, Data3d<T> cornerData)
	: xmin(origin[0]), xmax(origin[0] + spacing[0]),
	  ymin(origin[1]), ymax(origin[1] + spacing[1]),
	  zmin(origin[2]), zmax(origin[2] + spacing[2]),
	  one_dx(one / spacing[0]), one_dy(one / spacing[1]), one_dz(one / spacing[2])
//Cuboid3d<T>::Cuboid3d(const T origin[3], const T spacing[3], const T data[2][2][2])
{

	memcpy(data, cornerData, sizeof(Data3d<T>));

//	for (size_t k = 0; k < 2; k++)
//	{
//		for (size_t j = 0; j < 2; j++)
//		{
//			for (size_t i = 0; i < 2; i++)
//			{
//				data[k][j][i] = cornerData[k][j][i];
//			}
//		}
//	}

	//mydata = data;
	//std::array<T,sizeof(data)> mydata = data ;
//	system("pause");
}

/* The actual interpolator */
template < typename T >
T Cuboid3d<T>::operator()(T x, T y, T z)
{
	T x0, x1, y0, y1, z0, z1;
	
	x1 = std::min(std::max(x,xmin), xmax); // safety
	y1 = std::min(std::max(y, ymin), ymax); // safety
	z1 = std::min(std::max(z, zmin), zmax); // safety

	x1 = (x1 - xmin)*one_dx;
	y1 = (y1 - ymin)*one_dy;
	z1 = (z1 - zmin)*one_dz;

	x0 = one - x1;
	y0 = one - y1;
	z0 = one - z1;

	/* Note: we can speed it up by developing the coefficients */
	return  data[0][0][0] * x0*y0*z0 +
			data[1][0][0] * x1*y0*z0 +
			data[0][1][0] * x0*y1*z0 +
			data[1][1][0] * x1*y1*z0 +
			data[0][0][1] * x0*y0*z1 +
			data[1][0][1] * x1*y0*z1 +
			data[0][1][1] * x0*y1*z1 +
			data[1][1][1] * x1*y1*z1 ;
}

///* The actual interpolation */
//template < typename T >
//T const & Cuboid3d<T>::operator()(T x, T y, T z) const
//{
//	T x0, x1, y0, y1, z0, z1;
//
//	x1 = std::min(std::max(x, xmin), xmax); // safety
//	y1 = std::min(std::max(y, ymin), ymax); // safety
//	z1 = std::min(std::max(z, zmin), zmax); // safety
//
//	x1 = (x1 - xmin)*one_dx;
//	y1 = (y1 - ymin)*one_dy;
//	z1 = (z1 - zmin)*one_dz;
//
//	x0 = one - x1;
//	y0 = one - y1;
//	z0 = one - z1;
//
//	/* Note: we can speed it up by developing the coefficients but that's not the point of the exercise here*/
//	return  data[0][0][0] * x0*y0*z0 +
//		data[1][0][0] * x1*y0*z0 +
//		data[0][1][0] * x0*y1*z0 +
//		data[1][1][0] * x1*y1*z0 +
//		data[0][0][1] * x0*y0*z1 +
//		data[1][0][1] * x1*y0*z1 +
//		data[0][1][1] * x0*y1*z1 +
//		data[1][1][1] * x1*y1*z1;
//}


//template < typename T >
//Cuboid3d<T>::Cuboid3d()
//{
//}

template < typename T >
Cuboid3d<T>::~Cuboid3d()
{
}
////////////////////////////////////////////////////////////////////////////////////

//template < typename T >
//class CornerValues
//{
//public:
//	CornerValues();
//	~CornerValues();
//
//private:
//
//};
//
//CornerValues::CornerValues()
//{
//}
//
//template < typename T >
//CornerValues<T>::~CornerValues()
//{
//}
//
//
//
//
//
//
//template < typename T >
//class Cuboid
//{
//public:
//	Cuboid(T x0, T x1, T a0, T a1);
//	Cuboid(T x0, T x1, T y0, T z1, T a00, T a01, T a10, T a11);
//	Cuboid(T x0, T a000, T a001, T a010, T a011, T a100, T a101, T a110, T a111);
//
//	~Cuboid();
//
//private:
//	static const T one;
//	float c;
//};
//
//template <>
//const float Cuboid<float>::one = 1.0f;
//
//template <>
//const double Cuboid<double>::one = 1.0;
//
//template < typename T >
//Cuboid<T>::Cuboid(T a0, T a1)
//{
//}
//
//template < typename T >
//Cuboid<T>::Cuboid(T a00, T a01, T a10, T a11)
//{
//
//}
//
//template < typename T >
//Cuboid<T>::Cuboid(T a000, T a001, T a010, T a011, T a100, T a101, T a110, T a111)
//{
//}
//
//template < typename T >
//Cuboid<T>::~Cuboid()
//{
//}