//#-------------------------------------------------
//#
//# File Noise.cpp created by cberry on 02-26-2015 at 12:59:48 PM
//#
//#-------------------------------------------------

#include "Noise.h"

namespace cbtek {
namespace common {
namespace math {
	
	//------------------------------------------PERMUTATION_TABLE---------------------------

    static double F4 =0.309016994; // F4  (Math.sqrt(5.0)-1.0)/4.0
    static double G4 =0.138196601; // G4  (5.0-Math.sqrt(5.0))/2=0.0
    static double F3 =0.333333333;
    static double G3 =0.166666667;
    static double F2 =0.366025403; // F2  =0.5*(sqrt(3.0)-1.0)
    static double G2 =0.211324865; // G2  (3.0-Math.sqrt(3.0))/6.0


      static unsigned char PERMUTATION_TABLE[512] =
      {
          151,160,137,91,90,15,
          131,13,201,95,96,53,194,233,7,225,140,36,103,30,69,142,8,99,37,240,21,10,23,
          190, 6,148,247,120,234,75,0,26,197,62,94,252,219,203,117,35,11,32,57,177,33,
          88,237,149,56,87,174,20,125,136,171,168, 68,175,74,165,71,134,139,48,27,166,
          77,146,158,231,83,111,229,122,60,211,133,230,220,105,92,41,55,46,245,40,244,
          102,143,54, 65,25,63,161, 1,216,80,73,209,76,132,187,208, 89,18,169,200,196,
          135,130,116,188,159,86,164,100,109,198,173,186, 3,64,52,217,226,250,124,123,
          5,202,38,147,118,126,255,82,85,212,207,206,59,227,47,16,58,17,182,189,28,42,
          223,183,170,213,119,248,152, 2,44,154,163, 70,221,153,101,155,167, 43,172,9,
          129,22,39,253, 19,98,108,110,79,113,224,232,178,185, 112,104,218,246,97,228,
          251,34,242,193,238,210,144,12,191,179,162,241, 81,51,145,235,249,14,239,107,
          49,192,214, 31,181,199,106,157,184, 84,204,176,115,121,50,45,127, 4,150,254,
          138,236,205,93,222,114,67,29,24,72,243,141,128,195,78,66,215,61,156,180,
          151,160,137,91,90,15,
          131,13,201,95,96,53,194,233,7,225,140,36,103,30,69,142,8,99,37,240,21,10,23,
          190, 6,148,247,120,234,75,0,26,197,62,94,252,219,203,117,35,11,32,57,177,33,
          88,237,149,56,87,174,20,125,136,171,168, 68,175,74,165,71,134,139,48,27,166,
          77,146,158,231,83,111,229,122,60,211,133,230,220,105,92,41,55,46,245,40,244,
          102,143,54, 65,25,63,161, 1,216,80,73,209,76,132,187,208, 89,18,169,200,196,
          135,130,116,188,159,86,164,100,109,198,173,186, 3,64,52,217,226,250,124,123,
          5,202,38,147,118,126,255,82,85,212,207,206,59,227,47,16,58,17,182,189,28,42,
          223,183,170,213,119,248,152, 2,44,154,163, 70,221,153,101,155,167, 43,172,9,
          129,22,39,253, 19,98,108,110,79,113,224,232,178,185, 112,104,218,246,97,228,
          251,34,242,193,238,210,144,12,191,179,162,241, 81,51,145,235,249,14,239,107,
          49,192,214, 31,181,199,106,157,184, 84,204,176,115,121,50,45,127, 4,150,254,
          138,236,205,93,222,114,67,29,24,72,243,141,128,195,78,66,215,61,156,180
      };


  // A lookup table to traverse the simplex around a given point in 4D.
  // Details can be found where this table is used, in the 4D noise method.
  /* TODO: This should not be required, backport it from Bill's GLSL code! */

    static unsigned char SIMPLEX_4D_TABLE[64][4] =
    {
        {0,1,2,3},{0,1,3,2},{0,0,0,0},{0,2,3,1},{0,0,0,0},{0,0,0,0},{0,0,0,0},{1,2,3,0},
        {0,2,1,3},{0,0,0,0},{0,3,1,2},{0,3,2,1},{0,0,0,0},{0,0,0,0},{0,0,0,0},{1,3,2,0},
        {0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},
        {1,2,0,3},{0,0,0,0},{1,3,0,2},{0,0,0,0},{0,0,0,0},{0,0,0,0},{2,3,0,1},{2,3,1,0},
        {1,0,2,3},{1,0,3,2},{0,0,0,0},{0,0,0,0},{0,0,0,0},{2,0,3,1},{0,0,0,0},{2,1,3,0},
        {0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},
        {2,0,1,3},{0,0,0,0},{0,0,0,0},{0,0,0,0},{3,0,1,2},{3,0,2,1},{0,0,0,0},{3,1,2,0},
        {2,1,0,3},{0,0,0,0},{0,0,0,0},{0,0,0,0},{3,1,0,2},{0,0,0,0},{3,2,0,1},{3,2,1,0}
    };


	
Noise::Noise(int octaves,double persistence,double zoom, int seed, bool cosinus)
{
	m_octaves=octaves;
	m_persistence=persistence;
	m_zoom=zoom;	
	m_random.reseed(seed);
	m_cosinus=cosinus;
}

double Noise::interpolateCos(double a, double b, double x) 
{
	if (!m_cosinus) 
	{
		return a * (1 - x) + b * x;
	}
	double f = (double) ((1 - std::cos(x * 3.1415926535f)) * 0.5f);
	return a * (1 - f) + b * f;
}

double Noise::getNoise(int x) 
{
	return getRandomNumber((x << 13) ^ x);
}

double Noise::getNoise(int x, int y) 
{
	int n = x + y * 57;
	return getRandomNumber((n << 13) ^ n);
}

double Noise::getSmoothedNoise(int x) 
{
	return getNoise(x) / 2 + getNoise(x - 1) / 4 + getNoise(x + 1) / 4;
}


double Noise::getSmoothedNoise(int x, int y) 
{
	double corners = (getNoise(x - 1, y - 1) + getNoise(x + 1, y - 1) + getNoise(x - 1, y + 1) + getNoise(x + 1, y + 1)) / 16.;
	double sides = (getNoise(x - 1, y) + getNoise(x + 1, y) + getNoise(x, y - 1) + getNoise(x, y + 1)) / 8.;
	double center = getNoise(x, y) / 4.;
	return corners + sides + center;
}


double Noise::getInterpolatedNoise(double x) 
{
	x /= m_zoom;
	double fx = std::fmod(x,1);
	int ix = (int) (x - fx);
	return interpolateCos(getSmoothedNoise(ix),getSmoothedNoise(ix + 1), fx);
}

double Noise::getInterpolatedNoise(double x, double y) 
{
	double fx = std::fmod(x,1);
	int ix = (int) (x - fx);
	double fy = std::fmod(y,1);
	int iy = (int) (y - fy);
	double v1 = getSmoothedNoise(ix, iy);
	double v2 = getSmoothedNoise(ix + 1, iy);
	double v3 = getSmoothedNoise(ix, iy + 1);
	double v4 = getSmoothedNoise(ix + 1, iy + 1);
	return interpolateCos(interpolateCos(v1, v2, fx),interpolateCos(v3, v4, fx), fy);
}

double Noise::getPerlinNoise(double x) 
{
	double total = 0;
	for (int i = 0; i < (m_octaves - 1); i++) 
	{
		double frequency = (double) std::pow(2, i);
		double amplitude = (double) std::pow(m_persistence, i);
		total += getInterpolatedNoise(x * frequency) * amplitude;
	}
	return total;
}

double Noise::getPerlinNoise(double x, double y) 
{
	x /= m_zoom;
	y /= m_zoom;
	double total = 0;
	for (int i = 0; i < m_octaves; i++) 
	{
		double frequency = (double) std::pow(2, i);
		double amplitude = (double) std::pow(m_persistence, i);
		total += getInterpolatedNoise(x * frequency, y * frequency) * amplitude;
	}
	return total;
}

int Noise::getFastFloor(double  x)
{
    return( ((x)>0) ? ((int)x) : (((int)x)-1) );
}

double Noise::getRandomNumber(int seed) 
{
	seed = m_seed ^ seed;
	seed = (seed >> 13) ^ seed;
	return (double) (1.0 - ((seed * (seed * seed * 15731 + 789221) + 1376312589) & 0x7fffffff) / 1073741824.0);
}

double  Noise::getGradient1d( int hash, double x )
{
    int h = hash & 15;
    double getGradient = 1.0f + (h & 7);   // Gradient value 1.0, 2.0, ..., 8.0
    if (h&8) getGradient = -getGradient;         // Set a random sign for the getGradientient
    return ( getGradient * x );           // Multiply the getGradientient with the distance
}

double  Noise::getGradient2d( int hash, double x, double y )
{
    int h = hash & 7;      // Convert low 3 bits of hash code
    double u = h<4 ? x : y;  // into 8 simple getGradientient directions,
    double v = h<4 ? y : x;  // and compute the dot product with (x,y).
    return ((h&1)? -u : u) + ((h&2)? -2.0f*v : 2.0f*v);
}

double  Noise::getGradient3d( int hash, double x, double y , double z )
{
    int h = hash & 15;     // Convert low 4 bits of hash code into 12 simple
    double u = h<8 ? x : y; // getGradientient directions, and compute dot product.
    double v = h<4 ? y : h==12||h==14 ? x : z; // Fix repeats at h = 12 to 15
    return ((h&1)? -u : u) + ((h&2)? -v : v);
}

double  Noise::getGradient4d( int hash, double x, double y, double z, double t ) 
{
    int h = hash & 31;      // Convert low 5 bits of hash code into 32 simple
    double u = h<24 ? x : y; // getGradientient directions, and compute dot product.
    double v = h<16 ? y : z;
    double w = h<8 ? z : t;
    return ((h&1)? -u : u) + ((h&2)? -v : v) + ((h&4)? -w : w);
}

// 1D simplex noise
double Noise::getSimplexNoise(double x)
{

  int i0 = getFastFloor(x);
  int i1 = i0 + 1;
  double x0 = x - i0;
  double x1 = x0 - 1.0f;

  double n0, n1;

  double t0 = 1.0f - x0*x0;
//  if(t0 < 0.0f) t0 = 0.0f; // this never happens for the 1D case
  t0 *= t0;
  n0 = t0 * t0 * getGradient1d( PERMUTATION_TABLE[i0 & 0xff], x0);

  double t1 = 1.0f - x1*x1;
//  if(t1 < 0.0f) t1 = 0.0f; // this never happens for the 1D case
  t1 *= t1;
  n1 = t1 * t1 * getGradient1d( PERMUTATION_TABLE[i1 & 0xff], x1);
  // The maximum value of this noise is 8*(3/4)^4 = 2.53125
  // A factor of 0.395 would scale to fit exactly within [-1,1], but
  // we want to match PRMan's 1D noise, so we scale it down some more.
  return 0.25f * (n0 + n1);

}

// 2D simplex noise
double Noise::getSimplexNoise(double x, double y)
{


    double n0, n1, n2; // Noise contributions from the three corners

    // Skew the input space to determine which simplex cell we're in
    double s = (x+y)*F2; // Hairy factor for 2D
    double xs = x + s;
    double ys = y + s;
    int i = getFastFloor(xs);
    int j = getFastFloor(ys);

    double t = (double)(i+j)*G2;
    double X0 = i-t; // Unskew the cell origin back to (x,y) space
    double Y0 = j-t;
    double x0 = x-X0; // The x,y distances from the cell origin
    double y0 = y-Y0;

    // For the 2D case, the simplex shape is an equilateral triangle.
    // Determine which simplex we are in.
    int i1, j1; // Offsets for second (middle) corner of simplex in (i,j) coords
    if(x0>y0) {i1=1; j1=0;} // lower triangle, XY order: (0,0)->(1,0)->(1,1)
    else {i1=0; j1=1;}      // upper triangle, YX order: (0,0)->(0,1)->(1,1)

    // A step of (1,0) in (i,j) means a step of (1-c,-c) in (x,y), and
    // a step of (0,1) in (i,j) means a step of (-c,1-c) in (x,y), where
    // c = (3-sqrt(3))/6

    double x1 = x0 - i1 + G2; // Offsets for middle corner in (x,y) unskewed coords
    double y1 = y0 - j1 + G2;
    double x2 = x0 - 1.0f + 2.0f * G2; // Offsets for last corner in (x,y) unskewed coords
    double y2 = y0 - 1.0f + 2.0f * G2;

    // Wrap the integer indices at 256, to avoid indexing  PERMUTATION_TABLE[] out of bounds
    int ii = i % 256;
    int jj = j % 256;

    // Calculate the contribution from the three corners
    double t0 = 0.5f - x0*x0-y0*y0;
    if(t0 < 0.0f) n0 = 0.0f;
    else {
      t0 *= t0;
      n0 = t0 * t0 * getGradient2d( PERMUTATION_TABLE[ii+ PERMUTATION_TABLE[jj]], x0, y0);
    }

    double t1 = 0.5f - x1*x1-y1*y1;
    if(t1 < 0.0f) n1 = 0.0f;
    else {
      t1 *= t1;
      n1 = t1 * t1 * getGradient2d( PERMUTATION_TABLE[ii+i1+ PERMUTATION_TABLE[jj+j1]], x1, y1);
    }

    double t2 = 0.5f - x2*x2-y2*y2;
    if(t2 < 0.0f) n2 = 0.0f;
    else {
      t2 *= t2;
      n2 = t2 * t2 * getGradient2d( PERMUTATION_TABLE[ii+1+PERMUTATION_TABLE[jj+1]], x2, y2);
    }

    // Add contributions from each corner to get the final noise value.
    // The result is scaled to return values in the interval [-1,1].
    return 40.0f * (n0 + n1 + n2); // TODO: The scale factor is preliminary!
  }

// 3D simplex noise
double Noise::getSimplexNoise(double x, double y, double z)
 {

// Simple skewing factors for the 3D case

    double n0, n1, n2, n3; // Noise contributions from the four corners

    // Skew the input space to determine which simplex cell we're in
    double s = (x+y+z)*F3; // Very nice and simple skew factor for 3D
    double xs = x+s;
    double ys = y+s;
    double zs = z+s;
    int i = getFastFloor(xs);
    int j = getFastFloor(ys);
    int k = getFastFloor(zs);

    double t = (double)(i+j+k)*G3;
    double X0 = i-t; // Unskew the cell origin back to (x,y,z) space
    double Y0 = j-t;
    double Z0 = k-t;
    double x0 = x-X0; // The x,y,z distances from the cell origin
    double y0 = y-Y0;
    double z0 = z-Z0;

    // For the 3D case, the simplex shape is a slightly irregular tetrahedron.
    // Determine which simplex we are in.
    int i1, j1, k1; // Offsets for second corner of simplex in (i,j,k) coords
    int i2, j2, k2; // Offsets for third corner of simplex in (i,j,k) coords

/* This code would benefit from a backport from the GLSL version! */
    if(x0>=y0) {
      if(y0>=z0)
        { i1=1; j1=0; k1=0; i2=1; j2=1; k2=0; } // X Y Z order
        else if(x0>=z0) { i1=1; j1=0; k1=0; i2=1; j2=0; k2=1; } // X Z Y order
        else { i1=0; j1=0; k1=1; i2=1; j2=0; k2=1; } // Z X Y order
      }
    else { // x0<y0
      if(y0<z0) { i1=0; j1=0; k1=1; i2=0; j2=1; k2=1; } // Z Y X order
      else if(x0<z0) { i1=0; j1=1; k1=0; i2=0; j2=1; k2=1; } // Y Z X order
      else { i1=0; j1=1; k1=0; i2=1; j2=1; k2=0; } // Y X Z order
    }

    // A step of (1,0,0) in (i,j,k) means a step of (1-c,-c,-c) in (x,y,z),
    // a step of (0,1,0) in (i,j,k) means a step of (-c,1-c,-c) in (x,y,z), and
    // a step of (0,0,1) in (i,j,k) means a step of (-c,-c,1-c) in (x,y,z), where
    // c = 1/6.

    double x1 = x0 - i1 + G3; // Offsets for second corner in (x,y,z) coords
    double y1 = y0 - j1 + G3;
    double z1 = z0 - k1 + G3;
    double x2 = x0 - i2 + 2.0f*G3; // Offsets for third corner in (x,y,z) coords
    double y2 = y0 - j2 + 2.0f*G3;
    double z2 = z0 - k2 + 2.0f*G3;
    double x3 = x0 - 1.0f + 3.0f*G3; // Offsets for last corner in (x,y,z) coords
    double y3 = y0 - 1.0f + 3.0f*G3;
    double z3 = z0 - 1.0f + 3.0f*G3;

    // Wrap the integer indices at 256, to avoid indexing PERMUTATION_TABLE[] out of bounds
    int ii = i % 256;
    int jj = j % 256;
    int kk = k % 256;

    // Calculate the contribution from the four corners
    double t0 = 0.6f - x0*x0 - y0*y0 - z0*z0;
    if(t0 < 0.0f) n0 = 0.0f;
    else {
      t0 *= t0;
      n0 = t0 * t0 * getGradient3d(PERMUTATION_TABLE[ii+PERMUTATION_TABLE[jj+PERMUTATION_TABLE[kk]]], x0, y0, z0);
    }

    double t1 = 0.6f - x1*x1 - y1*y1 - z1*z1;
    if(t1 < 0.0f) n1 = 0.0f;
    else {
      t1 *= t1;
      n1 = t1 * t1 * getGradient3d(PERMUTATION_TABLE[ii+i1+PERMUTATION_TABLE[jj+j1+PERMUTATION_TABLE[kk+k1]]], x1, y1, z1);
    }

    double t2 = 0.6f - x2*x2 - y2*y2 - z2*z2;
    if(t2 < 0.0f) n2 = 0.0f;
    else {
      t2 *= t2;
      n2 = t2 * t2 * getGradient3d(PERMUTATION_TABLE[ii+i2+PERMUTATION_TABLE[jj+j2+PERMUTATION_TABLE[kk+k2]]], x2, y2, z2);
    }

    double t3 = 0.6f - x3*x3 - y3*y3 - z3*z3;
    if(t3<0.0f) n3 = 0.0f;
    else {
      t3 *= t3;
      n3 = t3 * t3 * getGradient3d(PERMUTATION_TABLE[ii+1+PERMUTATION_TABLE[jj+1+PERMUTATION_TABLE[kk+1]]], x3, y3, z3);
    }

    // Add contributions from each corner to get the final noise value.
    // The result is scaled to stay just inside [-1,1]
    return 32.0f * (n0 + n1 + n2 + n3); // TODO: The scale factor is preliminary!
  }


// 4D simplex noise
double Noise::getSimplexNoise(double x, double y, double z, double w)
{

  // The skewing and unskewing factors are hairy again for the 4D case

    double n0, n1, n2, n3, n4; // Noise contributions from the five corners

    // Skew the (x,y,z,w) space to determine which cell of 24 simplices we're in
    double s = (x + y + z + w) * F4; // Factor for 4D skewing
    double xs = x + s;
    double ys = y + s;
    double zs = z + s;
    double ws = w + s;
    int i = getFastFloor(xs);
    int j = getFastFloor(ys);
    int k = getFastFloor(zs);
    int l = getFastFloor(ws);

    double t = (i + j + k + l) * G4; // Factor for 4D unskewing
    double X0 = i - t; // Unskew the cell origin back to (x,y,z,w) space
    double Y0 = j - t;
    double Z0 = k - t;
    double W0 = l - t;

    double x0 = x - X0;  // The x,y,z,w distances from the cell origin
    double y0 = y - Y0;
    double z0 = z - Z0;
    double w0 = w - W0;

    // For the 4D case, the simplex is a 4D shape I won't even try to describe.
    // To find out which of the 24 possible simplices we're in, we need to
    // determine the magnitude ordering of x0, y0, z0 and w0.
    // The method below is a good way of finding the ordering of x,y,z,w and
    // then find the correct traversal order for the simplex we�re in.
    // First, six pair-wise comparisons are performed between each possible pair
    // of the four coordinates, and the results are used to add up binary bits
    // for an integer index.
    int c1 = (x0 > y0) ? 32 : 0;
    int c2 = (x0 > z0) ? 16 : 0;
    int c3 = (y0 > z0) ? 8 : 0;
    int c4 = (x0 > w0) ? 4 : 0;
    int c5 = (y0 > w0) ? 2 : 0;
    int c6 = (z0 > w0) ? 1 : 0;
    int c = c1 + c2 + c3 + c4 + c5 + c6;

    int i1, j1, k1, l1; // The integer offsets for the second simplex corner
    int i2, j2, k2, l2; // The integer offsets for the third simplex corner
    int i3, j3, k3, l3; // The integer offsets for the fourth simplex corner

    // SIMPLEX_4D_TABLE[c] is a 4-vector with the numbers 0, 1, 2 and 3 in some order.
    // Many values of c will never occur, since e.g. x>y>z>w makes x<z, y<w and x<w
    // impossible. Only the 24 indices which have non-zero entries make any sense.
    // We use a thresholding to set the coordinates in turn from the largest magnitude.
    // The number 3 in the "simplex" array is at the position of the largest coordinate.
    i1 = SIMPLEX_4D_TABLE[c][0]>=3 ? 1 : 0;
    j1 = SIMPLEX_4D_TABLE[c][1]>=3 ? 1 : 0;
    k1 = SIMPLEX_4D_TABLE[c][2]>=3 ? 1 : 0;
    l1 = SIMPLEX_4D_TABLE[c][3]>=3 ? 1 : 0;
    // The number 2 in the "simplex" array is at the second largest coordinate.
    i2 = SIMPLEX_4D_TABLE[c][0]>=2 ? 1 : 0;
    j2 = SIMPLEX_4D_TABLE[c][1]>=2 ? 1 : 0;
    k2 = SIMPLEX_4D_TABLE[c][2]>=2 ? 1 : 0;
    l2 = SIMPLEX_4D_TABLE[c][3]>=2 ? 1 : 0;
    // The number 1 in the "simplex" array is at the second smallest coordinate.
    i3 = SIMPLEX_4D_TABLE[c][0]>=1 ? 1 : 0;
    j3 = SIMPLEX_4D_TABLE[c][1]>=1 ? 1 : 0;
    k3 = SIMPLEX_4D_TABLE[c][2]>=1 ? 1 : 0;
    l3 = SIMPLEX_4D_TABLE[c][3]>=1 ? 1 : 0;
    // The fifth corner has all coordinate offsets = 1, so no need to look that up.

    double x1 = x0 - i1 + G4; // Offsets for second corner in (x,y,z,w) coords
    double y1 = y0 - j1 + G4;
    double z1 = z0 - k1 + G4;
    double w1 = w0 - l1 + G4;
    double x2 = x0 - i2 + 2.0f*G4; // Offsets for third corner in (x,y,z,w) coords
    double y2 = y0 - j2 + 2.0f*G4;
    double z2 = z0 - k2 + 2.0f*G4;
    double w2 = w0 - l2 + 2.0f*G4;
    double x3 = x0 - i3 + 3.0f*G4; // Offsets for fourth corner in (x,y,z,w) coords
    double y3 = y0 - j3 + 3.0f*G4;
    double z3 = z0 - k3 + 3.0f*G4;
    double w3 = w0 - l3 + 3.0f*G4;
    double x4 = x0 - 1.0f + 4.0f*G4; // Offsets for last corner in (x,y,z,w) coords
    double y4 = y0 - 1.0f + 4.0f*G4;
    double z4 = z0 - 1.0f + 4.0f*G4;
    double w4 = w0 - 1.0f + 4.0f*G4;

    // Wrap the integer indices at 256, to avoid indexing PERMUTATION_TABLE[] out of bounds
    int ii = i % 256;
    int jj = j % 256;
    int kk = k % 256;
    int ll = l % 256;

    // Calculate the contribution from the five corners
    double t0 = 0.6f - x0*x0 - y0*y0 - z0*z0 - w0*w0;
    if(t0 < 0.0f) n0 = 0.0f;
    else {
      t0 *= t0;
      n0 = t0 * t0 * getGradient4d(PERMUTATION_TABLE[ii+PERMUTATION_TABLE[jj+PERMUTATION_TABLE[kk+PERMUTATION_TABLE[ll]]]], x0, y0, z0, w0);
    }

   double t1 = 0.6f - x1*x1 - y1*y1 - z1*z1 - w1*w1;
    if(t1 < 0.0f) n1 = 0.0f;
    else {
      t1 *= t1;
      n1 = t1 * t1 * getGradient4d(PERMUTATION_TABLE[ii+i1+PERMUTATION_TABLE[jj+j1+PERMUTATION_TABLE[kk+k1+PERMUTATION_TABLE[ll+l1]]]], x1, y1, z1, w1);
    }

   double t2 = 0.6f - x2*x2 - y2*y2 - z2*z2 - w2*w2;
    if(t2 < 0.0f) n2 = 0.0f;
    else {
      t2 *= t2;
      n2 = t2 * t2 * getGradient4d(PERMUTATION_TABLE[ii+i2+PERMUTATION_TABLE[jj+j2+PERMUTATION_TABLE[kk+k2+PERMUTATION_TABLE[ll+l2]]]], x2, y2, z2, w2);
    }

   double t3 = 0.6f - x3*x3 - y3*y3 - z3*z3 - w3*w3;
    if(t3 < 0.0f) n3 = 0.0f;
    else {
      t3 *= t3;
      n3 = t3 * t3 * getGradient4d(PERMUTATION_TABLE[ii+i3+PERMUTATION_TABLE[jj+j3+PERMUTATION_TABLE[kk+k3+PERMUTATION_TABLE[ll+l3]]]], x3, y3, z3, w3);
    }

   double t4 = 0.6f - x4*x4 - y4*y4 - z4*z4 - w4*w4;
    if(t4 < 0.0f) n4 = 0.0f;
    else {
      t4 *= t4;
      n4 = t4 * t4 * getGradient4d(PERMUTATION_TABLE[ii+1+PERMUTATION_TABLE[jj+1+PERMUTATION_TABLE[kk+1+PERMUTATION_TABLE[ll+1]]]], x4, y4, z4, w4);
    }

    // Sum up and scale the result to cover the range [-1,1]
    return 27.0f * (n0 + n1 + n2 + n3 + n4); // TODO: The scale factor is preliminary!
  }
//---------------------------------------------------------------------
}}} //namespace
