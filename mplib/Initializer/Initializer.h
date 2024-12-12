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
  void normalize_to_fraction_of_virial(vector<mpreal> &data, mpreal Q);  
  void normalize_to_boekholt_units(vector<mpreal> &data);
  void rescale_position(vector<mpreal> &data, mpreal Cr);
  void rescale_mass_position(vector<mpreal> &data, mpreal Cm, mpreal Cr);
  void rescale_velocity(vector<mpreal> &data, mpreal Cv);
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

  bool get_from_file_list_reversed(vector<mpreal> &data, string file, int index);
  bool continue_from_file_reversed(vector<mpreal> &data, string file);

  bool get_from_file_perturbed(vector<mpreal> &data, string file, int index, int coor, mpreal perturbation); 

  // N=2
  vector<mpreal> get_circle(mpreal m_ratio);

  vector<mpreal> get_binary();
  vector<mpreal> get_binary(mpreal m_ratio, mpreal eccentricity);
  vector<mpreal> get_binary(mpreal mu, mpreal m_ratio, mpreal semimajor_axis, mpreal eccentricity);

  vector<mpreal> get_parabola(mpreal m_ratio);
  vector<mpreal> get_hyperbola(mpreal m_ratio, mpreal eccentricity);
  vector<mpreal> get_radial(mpreal m_ratio, mpreal energy);

  // N=3
  vector<mpreal> get_figure8();
  vector<mpreal> get_figure8(int numDigits);
  vector<mpreal> get_figure8_perturbed(int index, int coor, mpreal delta);

  vector<mpreal> get_triangle();
  vector<mpreal> get_triangle(int numDigits);
  vector<mpreal> get_triangle_perturbed(int index, int coor, mpreal dx);
  vector<mpreal> get_triangle_scaled_perturbed(mpreal Cm, mpreal Cr, mpreal Cv, int index, int coor, mpreal dx);

  vector<mpreal> get_butterfly();
  vector<mpreal> get_butterfly(int numDigits);

  vector<mpreal> get_pythagorean();
  vector<mpreal> get_pythagorean_perturbed(int index, int coor, mpreal delta);

  vector<mpreal> get_sitnikov(mpreal ecc, mpreal vz0);
  vector<mpreal> get_sitnikov(mpreal ecc, mpreal vz0, mpreal angle);

  vector<mpreal> get_sun_planet_comet_system(mpreal MA);
  vector<mpreal> get_sun_planet_comet_system_perturbed(mpreal MA, int index);
  vector<mpreal> get_sun_two_planets_system(mpreal m, mpreal MA);
  vector<mpreal> get_sun_two_planets_system_perturbed(mpreal m, mpreal MA, int index);

  vector<mpreal> get_solar_system_jpl_variable_N(bool Mercury, bool Venus, bool Earth, bool Mars, bool Jupiter, bool Saturn, bool Uranus, bool Neptune, bool Pluto, int index, int coor, mpreal perturbation);

  vector<mpreal> get_agekyan_triple(mpreal x, mpreal y, int seed, int pivot, int index);

  // Exoplanets
  bool get_exo_64443(vector<mpreal> &data, string file);
  bool get_exo_64443_perturbed(vector<mpreal> &data, string file, int particle, int coor, mpreal delta);

  // Clusters
  vector<mpreal> get_plummer(int N, int seed, int pivot, int index);
  vector<mpreal> get_plummer_perturbed(int N, int seed, int pivot, int index, int star, int coor, mpreal delta);

  vector<mpreal> get_static_plummer(int N, int seed, int pivot, int index, mpreal m0, mpreal x0, mpreal vz0, mpreal delta);
};

#endif


