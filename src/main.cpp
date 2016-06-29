// Cuboid Interpolator

#include <iostream>
#include <iomanip>
#include "Cuboid.h"
//#include "Vector.h"
using namespace std;

int main()
{

	size_t c = 0;

	//Origin3d<double> test;
	Origin1d<double> origin1d = { 0.0 };
	Spacing1d<double> spacing1d = { 1.0 };
	Data1d<double> data1d;

	Origin2d<double> origin2d = { 0.0, 0.0};
	Spacing2d<double> spacing2d = { 1.0, 1.0};
	Data2d<double> data2d;

	Origin3d<double> origin3d = { 0.0, 0.0, 0.0 };
	Spacing3d<double> spacing3d = { 1.0, 1.0, 1.0 };
	Data3d<double> data3d;

	// 1D data init
	data1d[0] = 0.0;
	data1d[1] = 1.0;

	// 2D data init
	data2d[0][0] = 0.0;
	data2d[1][0] = 1.0;
	data2d[0][1] = 2.0;
	data2d[1][1] = 3.0;


	// 3D data init
	for (size_t k = 0; k < 2; k++)
	{
		for (size_t j = 0; j < 2; j++)
		{
			for (size_t i = 0; i < 2; i++) // I know: not optimum
			{
				data3d[i][j][k] = double(c);
				c++;
			}
		}
	}

	Cuboid1d<double> cuboid1d(origin1d, spacing1d, data1d);
	Cuboid2d<double> cuboid2d(origin2d, spacing2d, data2d);
	Cuboid3d<double> cuboid3d(origin3d, spacing3d, data3d);

	cout << "1D Test:" << endl;
	cout << scientific << setprecision(17) << cuboid1d(0.0) << endl;
	cout << scientific << setprecision(17) << cuboid1d(0.5) << endl;
	cout << scientific << setprecision(17) << cuboid1d(1.5) << endl;

	cout << "2D Test:" << endl;
	cout << scientific << setprecision(17) << cuboid2d(0.0, 0.0) << endl;
	cout << scientific << setprecision(17) << cuboid2d(0.5, 0.0) << endl;
	cout << scientific << setprecision(17) << cuboid2d(0.0, 0.5) << endl;
	cout << scientific << setprecision(17) << cuboid2d(0.5, 0.5) << endl;

	cout << "3D Test:" << endl;
	cout << scientific << setprecision(17) << cuboid3d(0.0, 0.0, 0.0) << endl; // vec3d(0, 0, 0) << endl;
	cout << scientific << setprecision(17) << cuboid3d(0.5, 0.0, 0.0) << endl;
	cout << scientific << setprecision(17) << cuboid3d(0.0, 0.5, 0.0) << endl;
	cout << scientific << setprecision(17) << cuboid3d(0.5, 0.5, 0.0) << endl;
	cout << scientific << setprecision(17) << cuboid3d(0.0, 0.0, 0.5) << endl; // vec3d(0, 0, 0) << endl;
	cout << scientific << setprecision(17) << cuboid3d(0.5, 0.0, 0.5) << endl;
	cout << scientific << setprecision(17) << cuboid3d(0.0, 0.5, 0.5) << endl;
	cout << scientific << setprecision(17) << cuboid3d(0.5, 0.5, 0.5) << endl;

	//double extend3d[2][3] = { {0.0,0.0,0.0}, {1.0,1.0,1.0} };

	// double origin[3], spacing[3], data[2][2][2];

	//Cuboid3d<double> cuboid(xmin,xmax,ymin,ymax,zmin,zmax);

	//vector<vector<vector<float>>>;
	
	//Cuboid3d<float> cuboid(0.0, 0.0, 0.0, 1.0, 1.0, 1.0);

	//cuboid(0.5, 0.5, 0.5);

	//Vector3d<float> vec3_f(1,1,1,0.0f);
	//Vector3d<double> vec3_d(1,1,1,0.0);
	//
	//cout << scientific << setprecision(17) << vec3_f(0, 0, 0) << endl; // vec3d(0, 0, 0) << endl;
	//cout << scientific << setprecision(17) << vec3_d(0, 0, 0) << endl; // vec3d(0, 0, 0) << endl;

	cout << "Hello World !!! \n";
	//	system("pause");
	return 0;
}