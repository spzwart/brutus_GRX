#include <iostream>
using namespace std;

#include <vector>
#include <cmath>

#include "mpreal.h"
using namespace mpfr;

#ifndef __Delta_h
#define __Delta_h

class Delta {
  mpreal tolerance; 

 public:

  Delta();
  Delta(mpreal tolerance);

  void set_tolerance(mpreal tolerance);

  mpreal get_tolerance();

  mpreal get_phase_space_distance(vector<mpreal> &data1, vector<mpreal> &data2);
  mpreal get_phase_space_distance_normalized(vector<mpreal> &data1, vector<mpreal> &data2);

  mpreal get_position_space_distance(vector<mpreal> &data1, vector<mpreal> &data2);
  mpreal get_position_space_distance_normalized(vector<mpreal> &data1, vector<mpreal> &data2);

  mpreal get_velocity_space_distance(vector<mpreal> &data1, vector<mpreal> &data2);
  mpreal get_velocity_space_distance_normalized(vector<mpreal> &data1, vector<mpreal> &data2);

  vector<mpreal> get_all(vector<mpreal> &data1, vector<mpreal> &data2);

  vector< vector<mpreal> > get_all_individual(vector<mpreal> &data1, vector<mpreal> &data2);

  bool is_converged(vector<mpreal> &data1, vector<mpreal> &data2);
  mpreal get_estimate_new_tolerance(mpreal t_begin, mpreal t_end, mpreal t_div, mpreal tolerance_begin, mpreal tolerance_end);
};

#endif


