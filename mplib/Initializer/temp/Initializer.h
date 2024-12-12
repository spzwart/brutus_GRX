#include <iostream>
using namespace std;

#include <fstream>
#include <vector>
#include <cmath>
#include <cstdlib>

#include "Data_Handler.h"
#include "Diagnostics.h"
#include "Products.h"
#include "Random.h"

#include "mpreal.h"
using namespace mpfr;

#ifndef __Initializer_h
#define __Initializer_h

class Initializer {
  Data_Handler data_handler;
  Diagnostics diagnostics;
  Products products;
  Random random;

  public:

  vector<mpreal> generate(int N, string config, vector<string> par);

  // Tools
  void set_random_generator(int seed, int pivot);

  void centralize(vector<mpreal> &data);
  void normalize_to_nbody_units(vector<mpreal> &data);
  void normalize_to_boekholt_units(vector<mpreal> &data);
  void rescale_position(vector<mpreal> &data, mpreal Cr);
  void rescale_mass_position(vector<mpreal> &data, mpreal Cm, mpreal Cr);
  void make_cold(vector<mpreal> &data);
  void rotate_x(vector<mpreal> &data, mpreal angle);
  void rotate_y(vector<mpreal> &data, mpreal angle);
  void rotate_z(vector<mpreal> &data, mpreal angle);
  void flip_z(vector<mpreal> &data);
  void flip_v(vector<mpreal> &data);

  mpreal get_random_mass_ratio();
  mpreal get_random_eccentricity();

  // From file
  bool get_from_file(vector<mpreal> &data, string file);
  bool get_from_file_list(vector<mpreal> &data, string file, int index);
  bool continue_from_file(vector<mpreal> &data, string file);

  // N=2
  vector<mpreal> get_circle(mpreal m_ratio);
  vector<mpreal> get_binary();
  vector<mpreal> get_binary(mpreal m_ratio, mpreal eccentricity);
  vector<mpreal> get_parabola(mpreal m_ratio);
  vector<mpreal> get_hyperbola(mpreal m_ratio, mpreal eccentricity);
  vector<mpreal> get_radial(mpreal m_ratio, mpreal energy);

  // N=3
  vector<mpreal> get_figure8();
  vector<mpreal> get_figure8(int numDigits);
  vector<mpreal> get_figure8_perturbed(mpreal dr, int seed, int pivot, int index);

  vector<mpreal> get_triangle();
  vector<mpreal> get_triangle(int numDigits);

  vector<mpreal> get_butterfly();
  vector<mpreal> get_butterfly(int numDigits);

  vector<mpreal> get_pythagorean();

  vector<mpreal> get_sitnikov(mpreal ecc, mpreal vz0);
  vector<mpreal> get_sitnikov(mpreal ecc, mpreal vz0, mpreal angle);

  // N=4


  // N=10
  vector<mpreal> get_solar_system();
};

#endif


