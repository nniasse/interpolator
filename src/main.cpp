/* Test of the Cuboid Interpolator*/
#include "gtest/gtest.h"
#include "stdio.h"
#include "Cuboid.h"

namespace {

	class Cuboid1dFloatTest : public ::testing::Test
	{
	protected:
		virtual void SetUp() {

			origin[0]  = 0.0f;
			spacing[0] = 1.0f;

			data[0] = 0.0f;
			data[1] = 1.0f;

			cuboid = Cuboid1d<float>(origin, spacing, data);

		}


		Origin1d<float> origin;
		Spacing1d<float> spacing;
		Data1d<float> data;
		Cuboid1d<float> cuboid;

		/* General Check function */
		float Analytic(float x) {

			float a = data[0], b = data[1];

			float	a0 = a,
				    a1 = -a + b;

			return a0 + a1*x;
		};

	};


	TEST_F(Cuboid1dFloatTest, DoesInterpolateCorrectlyInTheCorners){

		EXPECT_EQ(data[0], cuboid(origin[0]));
		EXPECT_EQ(data[1], cuboid(origin[0] + spacing[0]));

	}

	TEST_F(Cuboid1dFloatTest, IsExact){

		EXPECT_EQ(Analytic(0.5f), cuboid(0.5f));
		EXPECT_EQ(Analytic(0.314159f), cuboid(0.314159f));
	}

	TEST_F(Cuboid1dFloatTest, IsSafeFromBufferOverflow){
		EXPECT_EQ(data[0], cuboid(origin[0] - 1.0f));
		EXPECT_EQ(data[1], cuboid(origin[0] + spacing[0] + 1.0f));

	}
}

namespace {

	class Cuboid1dDoubleTest : public ::testing::Test
	{
	protected:
		virtual void SetUp() {

			origin[0] = 0.0;
			spacing[0] = 1.0; 

			data[0] = 0.0;
			data[1] = 1.0;

			cuboid = Cuboid1d<double>(origin, spacing, data);

		}


		Origin1d<double> origin;
		Spacing1d<double> spacing;
		Data1d<double> data;
		Cuboid1d<double> cuboid;

		/* General Check function */
		double Analytic(double x) {

			double a = data[0], b = data[1];

			double	a0 = a,
					a1 = -a + b;

			return a0 + a1*x;
		};

	};



	TEST_F(Cuboid1dDoubleTest, DoesInterpolateCorrectlyInTheCorners){

		EXPECT_EQ(data[0], cuboid(origin[0]));
		EXPECT_EQ(data[1], cuboid(origin[0] + spacing[0]));

	}

	TEST_F(Cuboid1dDoubleTest, IsExact){

		EXPECT_EQ(Analytic(0.5), cuboid(0.5));
		EXPECT_EQ(Analytic(0.314159265359), cuboid(0.314159265359));
	}

	TEST_F(Cuboid1dDoubleTest, IsSafeFromBufferOverflow){
		EXPECT_EQ(data[0], cuboid(origin[0] - 1.0));
		EXPECT_EQ(data[1], cuboid(origin[0] + spacing[0] + 1.0));

	}
}

namespace {

	class Cuboid2dFloatTest : public ::testing::Test
	{
	protected:
		virtual void SetUp() {

			origin[0] = 0.0f; origin[1] = 0.0f;
			spacing[0] = 1.0f; spacing[1] = 1.0f;

			data[0][0] = 0.0f;
			data[1][0] = 1.0f;
			data[0][1] = 2.0f;
			data[1][1] = 3.0f;

			cuboid = Cuboid2d<float>(origin, spacing, data);

		}


		Origin2d<float> origin;
		Spacing2d<float> spacing;
		Data2d<float> data;
		Cuboid2d<float> cuboid;

		/* General Check function */
		float Analytic(float x, float y) {

			float a = data[0][0], b = data[1][0], c = data[0][1], d = data[1][1];

				float	a0 = a,
						a1 = -a + b,
						a2 = -a + c,
						a4 = a - b - c + d;

			return a0 + a1*x + a2*y +  a4*x*y ;
		};

	};



	TEST_F(Cuboid2dFloatTest, DoesInterpolateCorrectlyInTheCorners){

		EXPECT_EQ(data[0][0], cuboid(origin[0]             , origin[1]             ));
		EXPECT_EQ(data[1][0], cuboid(origin[0] + spacing[0], origin[1]             ));
		EXPECT_EQ(data[0][1], cuboid(origin[0]             , origin[1] + spacing[1]));
		EXPECT_EQ(data[1][1], cuboid(origin[0] + spacing[0], origin[1] + spacing[1]));

	}

	TEST_F(Cuboid2dFloatTest, IsExact){

		EXPECT_EQ(Analytic(0.5f, 0.5f), cuboid(0.5f, 0.5f));
		EXPECT_EQ(Analytic(0.314159f, 0.314159f), cuboid(0.314159f, 0.314159f));
	}

	TEST_F(Cuboid2dFloatTest, IsSafeFromBufferOverflow){
		EXPECT_EQ(data[0][0], cuboid(origin[0] - 1.0f             , origin[1] - 1.0f             ));
		EXPECT_EQ(data[1][0], cuboid(origin[0] + spacing[0] + 1.0f, origin[1] - 1.0f             ));
		EXPECT_EQ(data[0][1], cuboid(origin[0] - 1.0f             , origin[1] + spacing[1] + 1.0f));
		EXPECT_EQ(data[1][1], cuboid(origin[0] + spacing[0] + 1.0f, origin[1] + spacing[1] + 1.0f));
	}
}

namespace {

	class Cuboid2dDoubleTest : public ::testing::Test
	{
	protected:
		virtual void SetUp() {

			origin[0] = 0.0; origin[1] = 0.0;
			spacing[0] = 1.0; spacing[1] = 1.0;

			data[0][0] = 0.0;
			data[1][0] = 1.0;
			data[0][1] = 2.0;
			data[1][1] = 3.0;

			cuboid = Cuboid2d<double>(origin, spacing, data);

		}


		Origin2d<double> origin;
		Spacing2d<double> spacing;
		Data2d<double> data;
		Cuboid2d<double> cuboid;

		/* General Check function */
		double Analytic(double x, double y) {

			double a = data[0][0], b = data[1][0], c = data[0][1], d = data[1][1];

			double	a0 = a,
					a1 = -a + b,
					a2 = -a + c,
					a4 = a - b - c + d;

			return a0 + a1*x + a2*y + a4*x*y;
		};

	};



	TEST_F(Cuboid2dDoubleTest, DoesInterpolateCorrectlyInTheCorners){

		EXPECT_EQ(data[0][0], cuboid(origin[0], origin[1]));
		EXPECT_EQ(data[1][0], cuboid(origin[0] + spacing[0], origin[1]));
		EXPECT_EQ(data[0][1], cuboid(origin[0], origin[1] + spacing[1]));
		EXPECT_EQ(data[1][1], cuboid(origin[0] + spacing[0], origin[1] + spacing[1]));

	}

	TEST_F(Cuboid2dDoubleTest, IsExact){

		EXPECT_EQ(Analytic(0.5, 0.5), cuboid(0.5, 0.5));
		EXPECT_EQ(Analytic(0.314159265359, 0.314159265359), cuboid(0.314159265359, 0.314159265359));
	}

	TEST_F(Cuboid2dDoubleTest, IsSafeFromBufferOverflow){
		EXPECT_EQ(data[0][0], cuboid(origin[0] - 1.0, origin[1] - 1.0));
		EXPECT_EQ(data[1][0], cuboid(origin[0] + spacing[0] + 1.0, origin[1] - 1.0));
		EXPECT_EQ(data[0][1], cuboid(origin[0] - 1.0, origin[1] + spacing[1] + 1.0));
		EXPECT_EQ(data[1][1], cuboid(origin[0] + spacing[0] + 1.0, origin[1] + spacing[1] + 1.0));
	}
}

namespace {

	class Cuboid3dFloatTest : public :: testing::Test
	{
	protected:
		virtual void SetUp() {

			origin[0]  = 0.0f; origin[1]  = 0.0f; origin[2]  = 0.0f;
			spacing[0] = 1.0f; spacing[1] = 1.0f; spacing[2] = 1.0f;

			data[0][0][0] = 0.0f;
			data[1][0][0] = 1.0f;
			data[0][1][0] = 2.0f;
			data[1][1][0] = 3.0f;
			data[0][0][1] = 4.0f;
			data[1][0][1] = 5.0f;
			data[0][1][1] = 6.0f;
			data[1][1][1] = 7.0f;

			cuboid = Cuboid3d<float>(origin, spacing, data);

		}


		Origin3d<float> origin;
		Spacing3d<float> spacing;
		Data3d<float> data;
		Cuboid3d<float> cuboid;

		/* General Check function */
		float Analytic(float x, float y, float z) {

			float a = data[0][0][0], b = data[1][0][0], c = data[0][1][0], d = data[1][1][0],
				  e = data[0][0][1], f = data[1][0][1], g = data[0][1][1], h = data[1][1][1];

			float	a0 =  a,
					a1 = -a + b,
					a2 = -a + c,
					a3 = -a + e,
					a4 = a -b -c + d,
					a5 = a -b -e + f,
					a6 = a -c -e + g,
					a7 = -a + b + c -d + e -f -g + h;

			return a0 + a1*x + a2*y + a3*z + a4*x*y + a5*x*z + a6*y*z + a7*x*y*z;
		};

	};



	TEST_F(Cuboid3dFloatTest, DoesInterpolateCorrectlyInTheCorners){

		EXPECT_EQ(data[0][0][0], cuboid(origin[0]             , origin[1]             , origin[2]             ));
		EXPECT_EQ(data[1][0][0], cuboid(origin[0] + spacing[0], origin[1]             , origin[2]             ));
		EXPECT_EQ(data[0][1][0], cuboid(origin[0]             , origin[1] + spacing[1], origin[2]             ));
		EXPECT_EQ(data[1][1][0], cuboid(origin[0] + spacing[0], origin[1] + spacing[1], origin[2]             ));
		EXPECT_EQ(data[0][0][1], cuboid(origin[0]             , origin[1]             , origin[2] + spacing[2]));
		EXPECT_EQ(data[1][0][1], cuboid(origin[0] + spacing[0], origin[1]             , origin[2] + spacing[2]));
		EXPECT_EQ(data[0][1][1], cuboid(origin[0]             , origin[1] + spacing[1], origin[2] + spacing[2]));
		EXPECT_EQ(data[1][1][1], cuboid(origin[0] + spacing[0], origin[1] + spacing[1], origin[2] + spacing[2]));
	}

	TEST_F(Cuboid3dFloatTest, IsExact){

		EXPECT_EQ(Analytic(0.5f, 0.5f, 0.5f), cuboid(0.5f, 0.5f, 0.5f));
		EXPECT_EQ(Analytic(0.314159f, 0.314159f, 0.314159f), cuboid(0.314159f, 0.314159f, 0.314159f));
	}

	TEST_F(Cuboid3dFloatTest, IsSafeFromBufferOverflow){
		EXPECT_EQ(data[0][0][0], cuboid(origin[0] - 1.0f             , origin[1] - 1.0f             , origin[2] - 1.0f              ));
		EXPECT_EQ(data[1][0][0], cuboid(origin[0] + spacing[0] + 1.0f, origin[1] - 1.0f             , origin[2] - 1.0f              ));
		EXPECT_EQ(data[0][1][0], cuboid(origin[0] - 1.0f             , origin[1] + spacing[1] + 1.0f, origin[2] - 1.0f              ));
		EXPECT_EQ(data[1][1][0], cuboid(origin[0] + spacing[0] + 1.0f, origin[1] + spacing[1] + 1.0f, origin[2] - 1.0f              ));
		EXPECT_EQ(data[0][0][1], cuboid(origin[0] - 1.0f             , origin[1] - 1.0f             , origin[2] + spacing[2]  + 1.0f));
		EXPECT_EQ(data[1][0][1], cuboid(origin[0] + spacing[0] + 1.0f, origin[1] - 1.0f             , origin[2] + spacing[2]  + 1.0f));
		EXPECT_EQ(data[0][1][1], cuboid(origin[0] - 1.0f             , origin[1] + spacing[1] + 1.0f, origin[2] + spacing[2]  + 1.0f));
		EXPECT_EQ(data[1][1][1], cuboid(origin[0] + spacing[0] + 1.0f, origin[1] + spacing[1] + 1.0f, origin[2] + spacing[2]  + 1.0f));
	}
}

namespace {

	class Cuboid3dDoubleTest : public ::testing::Test
	{
	protected:
		virtual void SetUp() {

			origin[0] = 0.0; origin[1] = 0.0; origin[2] = 0.0;
			spacing[0] = 1.0; spacing[1] = 1.0; spacing[2] = 1.0;

			data[0][0][0] = 0.0;
			data[1][0][0] = 1.0;
			data[0][1][0] = 2.0;
			data[1][1][0] = 3.0;
			data[0][0][1] = 4.0;
			data[1][0][1] = 5.0;
			data[0][1][1] = 6.0;
			data[1][1][1] = 7.0;

			cuboid = Cuboid3d<double>(origin, spacing, data);

		}


		Origin3d<double> origin;
		Spacing3d<double> spacing;
		Data3d<double> data;
		Cuboid3d<double> cuboid;

		/* General Check function */
		double Analytic(double x, double y, double z) {

			double a = data[0][0][0], b = data[1][0][0], c = data[0][1][0], d = data[1][1][0],
				  e = data[0][0][1], f = data[1][0][1], g = data[0][1][1], h = data[1][1][1];

			double	a0 = a,
					a1 = -a + b,
					a2 = -a + c,
					a3 = -a + e,
					a4 = a - b - c + d,
					a5 = a - b - e + f,
					a6 = a - c - e + g,
					a7 = -a + b + c - d + e - f - g + h;

			return a0 + a1*x + a2*y + a3*z + a4*x*y + a5*x*z + a6*y*z + a7*x*y*z;
		};

	};



	TEST_F(Cuboid3dDoubleTest, DoesInterpolateCorrectlyInTheCorners){

		EXPECT_EQ(data[0][0][0], cuboid(origin[0], origin[1], origin[2]));
		EXPECT_EQ(data[1][0][0], cuboid(origin[0] + spacing[0], origin[1], origin[2]));
		EXPECT_EQ(data[0][1][0], cuboid(origin[0], origin[1] + spacing[1], origin[2]));
		EXPECT_EQ(data[0][0][1], cuboid(origin[0], origin[1], origin[2] + spacing[2]));
		EXPECT_EQ(data[1][0][1], cuboid(origin[0] + spacing[0], origin[1], origin[2] + spacing[2]));
		EXPECT_EQ(data[0][1][1], cuboid(origin[0], origin[1] + spacing[1], origin[2] + spacing[2]));
		EXPECT_EQ(data[1][1][1], cuboid(origin[0] + spacing[0], origin[1] + spacing[1], origin[2] + spacing[2]));
	}

	TEST_F(Cuboid3dDoubleTest, IsExact){

		EXPECT_EQ(Analytic(0.5, 0.5, 0.5), cuboid(0.5, 0.5, 0.5));
		EXPECT_EQ(Analytic(0.314159265359, 0.314159265359, 0.314159265359), cuboid(0.314159265359, 0.314159265359, 0.314159265359));
	}

	TEST_F(Cuboid3dDoubleTest, IsSafeFromBufferOverflow){
		EXPECT_EQ(data[0][0][0], cuboid(origin[0] - 1.0, origin[1] - 1.0, origin[2] - 1.0));
		EXPECT_EQ(data[1][0][0], cuboid(origin[0] + spacing[0] + 1.0, origin[1] - 1.0, origin[2] - 1.0));
		EXPECT_EQ(data[0][1][0], cuboid(origin[0] - 1.0, origin[1] + spacing[1] + 1.0, origin[2] - 1.0));
		EXPECT_EQ(data[0][0][1], cuboid(origin[0] - 1.0, origin[1] - 1.0, origin[2] + spacing[2] + 1.0));
		EXPECT_EQ(data[1][0][1], cuboid(origin[0] + spacing[0] + 1.0, origin[1] - 1.0, origin[2] + spacing[2] + 1.0));
		EXPECT_EQ(data[0][1][1], cuboid(origin[0] - 1.0, origin[1] + spacing[1] + 1.0, origin[2] + spacing[2] + 1.0));
		EXPECT_EQ(data[1][1][1], cuboid(origin[0] + spacing[0] + 1.0, origin[1] + spacing[1] + 1.0, origin[2] + spacing[2] + 1.0));
	}
}


//TEST(SimpleTest, IsWorking) {
//	// This test is named "Negative", and belongs to the "FactorialTest"
//	// test case
//	EXPECT_EQ(1, 1);
//}


int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}


//// Cuboid Interpolator
//
//#include <iostream>
//#include <iomanip>
//#include "Cuboid.h"
////#include "Vector.h"
//using namespace std;
//
//int main()
//{
//
//	size_t c = 0;
//
//	//Origin3d<double> test;
//	Origin1d<double> origin1d = { 0.0 };
//	Spacing1d<double> spacing1d = { 1.0 };
//	Data1d<double> data1d;
//
//	Origin2d<double> origin2d = { 0.0, 0.0};
//	Spacing2d<double> spacing2d = { 1.0, 1.0};
//	Data2d<double> data2d;
//
//	Origin3d<double> origin3d = { 0.0, 0.0, 0.0 };
//	Spacing3d<double> spacing3d = { 1.0, 1.0, 1.0 };
//	Data3d<double> data3d;
//
//	// 1D data init
//	data1d[0] = 0.0;
//	data1d[1] = 1.0;
//
//	// 2D data init
//	data2d[0][0] = 0.0;
//	data2d[1][0] = 1.0;
//	data2d[0][1] = 2.0;
//	data2d[1][1] = 3.0;
//
//
//	// 3D data init
//	for (size_t k = 0; k < 2; k++)
//	{
//		for (size_t j = 0; j < 2; j++)
//		{
//			for (size_t i = 0; i < 2; i++) // I know: not optimum
//			{
//				data3d[i][j][k] = double(c);
//				c++;
//			}
//		}
//	}
//
//	Cuboid1d<double> cuboid1d(origin1d, spacing1d, data1d);
//	Cuboid2d<double> cuboid2d(origin2d, spacing2d, data2d);
//	Cuboid3d<double> cuboid3d(origin3d, spacing3d, data3d);
//
//	cout << "1D Test:" << endl;
//	cout << scientific << setprecision(17) << cuboid1d(0.0) << endl;
//	cout << scientific << setprecision(17) << cuboid1d(0.5) << endl;
//	cout << scientific << setprecision(17) << cuboid1d(1.5) << endl;
//
//	cout << "2D Test:" << endl;
//	cout << scientific << setprecision(17) << cuboid2d(0.0, 0.0) << endl;
//	cout << scientific << setprecision(17) << cuboid2d(0.5, 0.0) << endl;
//	cout << scientific << setprecision(17) << cuboid2d(0.0, 0.5) << endl;
//	cout << scientific << setprecision(17) << cuboid2d(0.5, 0.5) << endl;
//
//	cout << "3D Test:" << endl;
//	cout << scientific << setprecision(17) << cuboid3d(0.0, 0.0, 0.0) << endl; // vec3d(0, 0, 0) << endl;
//	cout << scientific << setprecision(17) << cuboid3d(0.5, 0.0, 0.0) << endl;
//	cout << scientific << setprecision(17) << cuboid3d(0.0, 0.5, 0.0) << endl;
//	cout << scientific << setprecision(17) << cuboid3d(0.5, 0.5, 0.0) << endl;
//	cout << scientific << setprecision(17) << cuboid3d(0.0, 0.0, 0.5) << endl; // vec3d(0, 0, 0) << endl;
//	cout << scientific << setprecision(17) << cuboid3d(0.5, 0.0, 0.5) << endl;
//	cout << scientific << setprecision(17) << cuboid3d(0.0, 0.5, 0.5) << endl;
//	cout << scientific << setprecision(17) << cuboid3d(0.5, 0.5, 0.5) << endl;
//
//	//double extend3d[2][3] = { {0.0,0.0,0.0}, {1.0,1.0,1.0} };
//
//	// double origin[3], spacing[3], data[2][2][2];
//
//	//Cuboid3d<double> cuboid(xmin,xmax,ymin,ymax,zmin,zmax);
//
//	//vector<vector<vector<float>>>;
//	
//	//Cuboid3d<float> cuboid(0.0, 0.0, 0.0, 1.0, 1.0, 1.0);
//
//	//cuboid(0.5, 0.5, 0.5);
//
//	//Vector3d<float> vec3_f(1,1,1,0.0f);
//	//Vector3d<double> vec3_d(1,1,1,0.0);
//	//
//	//cout << scientific << setprecision(17) << vec3_f(0, 0, 0) << endl; // vec3d(0, 0, 0) << endl;
//	//cout << scientific << setprecision(17) << vec3_d(0, 0, 0) << endl; // vec3d(0, 0, 0) << endl;
//
//	cout << "Hello World !!! \n";
//	//	system("pause");
//	return 0;
//}