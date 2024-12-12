#include "Star.h"
#include "Cluster.h"
#include "Timer.h"

#ifndef __Bulirsch_Stoer_h
#define __Bulirsch_Stoer_h

class Bulirsch_Stoer {
  mpreal tolerance;
  int n_max, k_max;

  vector< vector<mpreal> > x_sample, y_sample, z_sample, vx_sample, vy_sample, vz_sample;

  public:

  mpreal tcpu_step_k1, tcpu_step_kx;
  mpreal tcpu_step1, tcpu_step2, tcpu_extrapol, tcpu_ec, tcpu_step_x;  

  Bulirsch_Stoer();
  Bulirsch_Stoer(mpreal tolerance);
  Bulirsch_Stoer(mpreal tolerance, int n_max, int k_max);

  void set_tolerance(mpreal tolerance);
  void set_n_max(int n_max);
  void set_k_max(int k_max);

  mpreal get_tolerance();
  int get_n_max();
  int get_k_max();

  bool integrate(Cluster &cl, mpreal &dt);
  bool integrate(Cluster &cl, mpreal &t0, mpreal &t1);
  bool step(Cluster &cl, mpreal &dt);
  void extrapol(Cluster &cl_exp, vector<mpreal> &dt, vector<Cluster> &c);
  mpreal extrapolate(vector<mpreal> &x, vector<mpreal> &y);
  bool error_control(Cluster &c1, Cluster &c2);
};

#endif

