//#-------------------------------------------------
//#
//# File Noise.h created by cberry on 02-26-2015 at 12:59:48 PM
//#
//#-------------------------------------------------

#ifndef _CBTEK_COMMON_MATH_NOISE
#define _CBTEK_COMMON_MATH_NOISE
#include <ctime>

#include "utility/inc/Random.h"

namespace cbtek {
namespace common {
namespace math {

class Noise
{

public:	
	Noise(int octaves=6,double persistence=.25,double zoom=1.,int seed=time(NULL),bool cosinus=true);
	
	double getNoise(int x);
	double getNoise(int x, int y);
	
	double getSmoothedNoise(int x);
	double getSmoothedNoise(int x, int y);
		
	double getPerlinNoise(double x);
	double getPerlinNoise(double x, double y);
	
	double getSimplexNoise(double x);
	double getSimplexNoise(double x, double y);
	double getSimplexNoise(double x, double y, double z);
	double getSimplexNoise(double x, double y, double z, double w);
	
	double getInterpolatedNoise(double x);
	double getInterpolatedNoise(double x, double y);
	
private:
	double getGradient1d(int hash, double x);
	double getGradient2d(int hash, double x,double y);
	double getGradient3d(int hash, double x,double y, double z);
	double getGradient4d(int hash, double x,double y, double z, double t);
	double interpolateCos(double a, double b, double x);
	double getRandomNumber(int seed);
	int getFastFloor(double n);
	int m_seed;
	common::utility::Random m_random;
	double m_persistence;
	int m_octaves;
	bool m_cosinus;
	double m_zoom;

};
}}} //namespace
#endif //_CBTEK_COMMON_MATH_NOISE
