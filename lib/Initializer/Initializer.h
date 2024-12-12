#include "Data_Handler.h"
#include "Diagnostics.h"
#include "Products.h"
#include "Random.h"

#ifndef __Initializer_h
#define __Initializer_h

class Initializer {
  Data_Handler data_handler;
  Diagnostics diagnostics;
  Products products;
  Random random;

  public:

  vector<double> generate(int N, string config, vector<string> par);

  // Tools
  void set_random_generator(int seed, int pivot);

  void centralize(vector<double> &data);
  void normalize_to_nbody_units(vector<double> &data);
  void normalize_to_fraction_of_virial(vector<double> &data, double Q);  
  void normalize_to_boekholt_units(vector<double> &data);
  void rescale_position(vector<double> &data, double Cr);
  void rescale_mass_position(vector<double> &data, double Cm, double Cr);
  void rescale_velocity(vector<double> &data, double Cv);
  void make_cold(vector<double> &data);
  void rotate_x(vector<double> &data, double angle);
  void rotate_y(vector<double> &data, double angle);
  void rotate_z(vector<double> &data, double angle);
  void flip_z(vector<double> &data);
  void flip_v(vector<double> &data);

  double get_random_mass_ratio();
  double get_random_eccentricity();

  void add_random_perturbation(vector<double> &data, double magnitude);

  // From file
  bool get_from_file(vector<double> &data, string file);
  bool get_from_file_list(vector<double> &data, string file, int index);
  bool continue_from_file(vector<double> &data, string file);

  bool get_from_file_list_reversed(vector<double> &data, string file, int index);

  // N=2
  vector<double> get_circle(double m_ratio);

  vector<double> get_binary();
  vector<double> get_binary(double m_ratio, double eccentricity);
  vector<double> get_binary(double mu, double m_ratio, double semimajor_axis, double eccentricity);
  vector<double> get_binary_abs(double m1, double m2, double a, double e);
  vector<double> get_binary_perturbed(double mu, double m_ratio, double semimajor_axis, double eccentricity, double dm1, double dx1, double dy1, double dz1, double dvx1, double dvy1, double dvz1, double dm2, double dx2, double dy2, double dz2, double dvx2, double dvy2, double dvz2);

  vector<double> get_parabola(double m_ratio);
  vector<double> get_hyperbola(double m_ratio, double eccentricity);
  vector<double> get_radial(double m_ratio, double energy);

  // N=3
  vector<double> get_figure8();
  vector<double> get_figure8(int numDigits);
  vector<double> get_figure8_perturbed(double dr, int seed, int pivot, int index);
  vector<double> get_figure8_dr(int index, int coor, double dx);

  vector<double> get_triangle();
  vector<double> get_triangle(int numDigits);

  vector<double> get_butterfly();
  vector<double> get_butterfly(int numDigits);

  vector<double> get_pythagorean();
  vector<double> get_pythagorean_perturbed(int index, int coor, double delta);

  vector<double> get_sitnikov(double ecc, double vz0);
  vector<double> get_sitnikov(double ecc, double vz0, double angle);
  vector<double> get_sitnikov_mass(double ecc, double vz0, double m);

  vector<double> get_hierarchical_triple();
  vector<double> get_hierarchical_triple(double m1, double m2, double m3, double a_inner, double e_inner, double a_outer, double e_outer, double inclination);

  vector<double> get_N3_plummer_mass_ratio(int seed, int pivot, int index);
  vector<double> get_N3_cold_plummer_mass_ratio(int seed, int pivot, int index);
  vector<double> get_N3_democratic_plummer_mass_ratio(int seed, int pivot, int index);
  vector<double> get_N3_democratic_cold_plummer_mass_ratio(int seed, int pivot, int index);

  vector<double> get_sun_jupiter_halley(int N, int seed, int pivot, int index, double f_error);

  vector<double> get_sun_jupiter_asteroid(double da);

  // N=4
  vector<double> get_N4_plummer_mass_ratio(int seed, int pivot, int index);
  vector<double> get_N4_cold_plummer_mass_ratio(int seed, int pivot, int index);
  vector<double> get_N4_democratic_plummer_mass_ratio(int seed, int pivot, int index);
  vector<double> get_N4_democratic_cold_plummer_mass_ratio(int seed, int pivot, int index);

  vector<double> get_binary_collision(double mass_ratio, double a1, double e1, double a2, double e2, double p, double v);

  // N=5
  vector<double> get_nice_model();

  // N=9
  vector<double> get_solar_system_jpl_without_mercury(int index, int coor, double perturbation);
  vector<double> get_solar_system_jpl_without_mercury_reversed(int index, int coor, double perturbation);

  // N=10
  vector<double> get_solar_system_ito();
  vector<double> get_solar_system_jpl();
  vector<double> get_solar_system_jpl(double epsilon, int seed, int pivot, int index);
  vector<double> get_solar_system_jpl(int index, double perturbation);

  vector<double> get_solar_system_ito_backwards();
  vector<double> get_solar_system_jpl_backwards();
  vector<double> get_solar_system_jpl_backwards(double epsilon, int seed, int pivot, int index);
  vector<double> get_solar_system_jpl_backwards(int index, double perturbation);

  vector<double> get_solar_system_jpl_variable_N(bool Mercury, bool Venus, bool Earth, bool Mars, bool Jupiter, bool Saturn, bool Uranus, bool Neptune, bool Pluto, int index, int coor, double perturbation);

  // Exoplanets
  bool get_exo_64443(vector<double> &data, string file);
  bool get_exo_64443_perturbed(vector<double> &data, string file, int particle, int coor, double delta);
  bool get_exo_64443_unstable(vector<double> &data, string file);
  bool get_exo_64443_unstable_perturbed(vector<double> &data, string file, int particle, int coor, double delta);

  // Spherical clusters
  vector<double> get_plummer(int N, int seed, int pivot, int index);
  vector<double> get_cold_plummer(int N, int seed, int pivot, int index);
  vector<double> get_democratic_plummer(int N, int seed, int pivot, int index);
  vector<double> get_democratic_cold_plummer(int N, int seed, int pivot, int index);

  vector<double> get_cold_sphere(int N, int seed, int pivot, int index);
  vector<double> get_virial_sphere(int N, int seed, int pivot, int index, double Q);

  vector<double> get_plummer_perturbed(int N, int seed, int pivot, int index, double magnitude);

  // Dominant mass
  vector<double> get_bh_plummer(int N, int seed, int pivot, int index, double m_ratio);
  vector<double> get_bh_solar_systems(int Nstar, int Nplanet, double mass_ratio1, double Rsolar, int seed, int pivot, int index);
  vector<double> get_plummer_solar_systems(int Nstar, int Nplanet, double Rsolar, int seed, int pivot, int index);

  vector<double> get_full_solar_system(int N, int seed, int pivot, int index);
  vector<double> get_sun_torus(int N, int seed, int pivot, int index);
  vector<double> get_sun_jupiter_torus(int N, int seed, int pivot, int index);
  vector<double> get_sun_mars_jupiter_torus(int N, int seed, int pivot, int index);
  vector<double> get_sun_mars_jovian_torus(int N, int seed, int pivot, int index);

  vector<double> get_solar_system_halley(int N, int seed, int pivot, int index, int h_coor, double h_error, int j_coor, double j_error);

  // Disk
  vector<double> get_ring(int N, int seed, int pivot, int index, double m_ratio, double a_inner);  
  vector<double> get_disk(int N, int seed, int pivot, int index, double m_ratio);  

  // Torus
  vector<double> get_torus(int N, int seed, int pivot, int index, double m_ratio, double a_inner, double sigma);
};

#endif

