#include "Initializer.h"

vector<double> Initializer::generate(int N, string config, vector<string> par) {
  if(config == "file") {
    vector<double> data;
    bool data_obtained = get_from_file(data, par[0]);
    if(data_obtained) return data;
  }
  if(config == "file_list") {  
    vector<double> data;
    bool data_obtained = get_from_file_list(data, par[0], atoi(par[1].c_str()));
    if(data_obtained) return data;
  }
  if(config == "continue_from_file") {  
    vector<double> data;
    bool data_obtained = continue_from_file(data, par[0]);
    if(data_obtained) return data;
  }
  if(config == "file_list_reversed") {  
    vector<double> data;
    bool data_obtained = get_from_file_list_reversed(data, par[0], atoi(par[1].c_str()));
    if(data_obtained) return data;
  }

  if(N == 2) {
    if(config == "circle") return get_circle( atof(par[0].c_str()) );
    if(config == "binary_random") return get_binary();
    if(config == "binary") {
      int M = par.size();
      if(M == 2) return get_binary(atof(par[0].c_str()), atof(par[1].c_str()));
      if(M == 4) return get_binary( atof(par[0].c_str()), atof(par[1].c_str()), atof(par[2].c_str()), atof(par[3].c_str()) );
      if(M == 18) return get_binary_perturbed(atof(par[0].c_str()), atof(par[1].c_str()), atof(par[2].c_str()), atof(par[3].c_str()), atof(par[4].c_str()), atof(par[5].c_str()), atof(par[6].c_str()), atof(par[7].c_str()), atof(par[8].c_str()), atof(par[9].c_str()), atof(par[10].c_str()), atof(par[11].c_str()), atof(par[12].c_str()), atof(par[13].c_str()), atof(par[14].c_str()), atof(par[15].c_str()), atof(par[16].c_str()), atof(par[17].c_str()));
    }
    if(config == "binary_abs") return get_binary_abs( atof(par[0].c_str()), atof(par[1].c_str()), atof(par[2].c_str()), atof(par[3].c_str()) );
    if(config == "parabola") return get_parabola(atof(par[0].c_str()));
    if(config == "hyperbola") return get_hyperbola(atof(par[0].c_str()), atof(par[1].c_str()));
    if(config == "radial") return get_radial( atof(par[0].c_str()), atof(par[1].c_str()) );
  }
  if(N == 3) {
    if(config == "figure8") return get_figure8();
    if(config == "figure8_precision") return get_figure8( atoi(par[0].c_str()) );
    if(config == "figure8_perturbed") {
      if(par.size() == 4) return get_figure8_perturbed( atof(par[0].c_str()), atoi(par[1].c_str()), atoi(par[2].c_str()), atoi(par[3].c_str()) );
      else return get_figure8_dr( atoi(par[0].c_str()), atoi(par[1].c_str()), atof(par[2].c_str()) );
    }

    if(config == "triangle") return get_triangle();
    if(config == "triangle_precision") return get_triangle( atoi(par[0].c_str()) );

    if(config == "butterfly") return get_butterfly();
    if(config == "butterfly_precision") return get_butterfly( atoi(par[0].c_str()) );

    if(config == "pythagorean") return get_pythagorean();
    if(config == "pythagorean_perturbed") return get_pythagorean_perturbed( atoi(par[0].c_str()), atoi(par[1].c_str()), atof(par[2].c_str()) );

    if(config == "sitnikov") {
      if(par.size() == 2) return get_sitnikov(atof(par[0].c_str()), atof(par[1].c_str()));
      else return get_sitnikov_mass(atof(par[0].c_str()), atof(par[1].c_str()), atof(par[2].c_str()));
    }
    if(config == "sitnikov_angle") return get_sitnikov(atof(par[0].c_str()), atof(par[1].c_str()), atof(par[2].c_str()));

    if(config == "hierarchical_triple") {
      if(par.size() == 0) return get_hierarchical_triple();
      else return get_hierarchical_triple(atof(par[0].c_str()), atof(par[1].c_str()), atof(par[2].c_str()), atof(par[3].c_str()), atof(par[4].c_str()), atof(par[5].c_str()), atof(par[6].c_str()), atof(par[7].c_str()) );
    }

    if(config == "plummer_mass_ratio") return get_N3_plummer_mass_ratio(atoi(par[0].c_str()), atoi(par[1].c_str()), atoi(par[2].c_str()));
    if(config == "cold_plummer_mass_ratio") return get_N3_cold_plummer_mass_ratio(atoi(par[0].c_str()), atoi(par[1].c_str()), atoi(par[2].c_str()));
    if(config == "democratic_plummer_mass_ratio") return get_N3_democratic_plummer_mass_ratio(atoi(par[0].c_str()), atoi(par[1].c_str()), atoi(par[2].c_str()));
    if(config == "democratic_cold_plummer_mass_ratio") return get_N3_democratic_cold_plummer_mass_ratio(atoi(par[0].c_str()), atoi(par[1].c_str()), atoi(par[2].c_str()));

    if(config == "sun_jupiter_halley") return get_sun_jupiter_halley( N, atoi(par[0].c_str()), atoi(par[1].c_str()), atoi(par[2].c_str()), atof(par[3].c_str()) );
  }
  if(N == 4) {
    if(config == "plummer_mass_ratio") return get_N4_plummer_mass_ratio(atoi(par[0].c_str()), atoi(par[1].c_str()), atoi(par[2].c_str()));
    if(config == "democratic_plummer_mass_ratio") return get_N4_democratic_plummer_mass_ratio(atoi(par[0].c_str()), atoi(par[1].c_str()), atoi(par[2].c_str()));
    if(config == "democratic_cold_plummer_mass_ratio") return get_N4_democratic_cold_plummer_mass_ratio(atoi(par[0].c_str()), atoi(par[1].c_str()), atoi(par[2].c_str()));
    if(config == "binary_collision") return get_binary_collision(atof(par[0].c_str()), atof(par[1].c_str()), atof(par[2].c_str()), atof(par[3].c_str()), atof(par[4].c_str()), atof(par[5].c_str()), atof(par[6].c_str()));
  }
  if(N == 9) {
    if(config == "solar_system_jpl") {
      return get_solar_system_jpl_without_mercury(atoi(par[0].c_str()), atoi(par[1].c_str()), atof(par[2].c_str()));
    }
    else if(config == "solar_system_jpl_reversed") {
      return get_solar_system_jpl_without_mercury_reversed(atoi(par[0].c_str()), atoi(par[1].c_str()), atof(par[2].c_str()));
    }
  }
  if(N == 10) {
    if(config == "solar_system_ito") return get_solar_system_ito();
    if(config == "solar_system_jpl") {
      if(par.size() == 2) {
        return get_solar_system_jpl(atoi(par[0].c_str()), atof(par[1].c_str()));
      }
      else return get_solar_system_jpl();
    }
    if(config == "solar_system_jpl_random") return get_solar_system_jpl( atof(par[0].c_str()), atoi(par[1].c_str()), atoi(par[2].c_str()), atoi(par[3].c_str()) );

    if(config == "solar_system_ito_backwards") return get_solar_system_ito_backwards();
    if(config == "solar_system_jpl_backwards") {
      if(par.size() == 2) {
        return get_solar_system_jpl_backwards(atoi(par[0].c_str()), atof(par[1].c_str()));
      }
      else return get_solar_system_jpl_backwards();
    }
    if(config == "solar_system_jpl_random_backwards") return get_solar_system_jpl_backwards( atof(par[0].c_str()), atoi(par[1].c_str()), atoi(par[2].c_str()), atoi(par[3].c_str()) );
  }
  if(N == 5) {
    if(config == "nice_model") return get_nice_model();
  }
  if(N == 20) {
    if(config == "solar_system_halley") return get_solar_system_halley( N, atoi(par[0].c_str()), atoi(par[1].c_str()), atoi(par[2].c_str()), atoi(par[3].c_str()), atof(par[4].c_str()), atoi(par[5].c_str()), atof(par[6].c_str()) );
  }

  if(config == "solar_system_jpl_variable_N") {
    return get_solar_system_jpl_variable_N(atoi(par[0].c_str()), atoi(par[1].c_str()), atoi(par[2].c_str()), atoi(par[3].c_str()), atoi(par[4].c_str()), atoi(par[5].c_str()), atoi(par[6].c_str()), atoi(par[7].c_str()), atoi(par[8].c_str()), atoi(par[9].c_str()), atoi(par[10].c_str()), atof(par[11].c_str()));
  }
  if(config == "full_solar_system") {
    return get_full_solar_system(N, atof(par[0].c_str()), atof(par[1].c_str()), atof(par[2].c_str()));
  }
  if(config == "sun_torus") {
    return get_sun_torus(N, atof(par[0].c_str()), atof(par[1].c_str()), atof(par[2].c_str()));
  }
  if(config == "sun_jupiter_torus") {
    return get_sun_jupiter_torus(N, atof(par[0].c_str()), atof(par[1].c_str()), atof(par[2].c_str()));
  }
  if(config == "sun_mars_jupiter_torus") {
    return get_sun_mars_jupiter_torus(N, atof(par[0].c_str()), atof(par[1].c_str()), atof(par[2].c_str()));
  }
  if(config == "sun_mars_jovian_torus") {
    return get_sun_mars_jovian_torus(N, atof(par[0].c_str()), atof(par[1].c_str()), atof(par[2].c_str()));
  }

  if(config == "exo_64443") {
    vector<double> data;
    bool data_obtained = get_exo_64443(data, par[0]);
    if(data_obtained) return data;
  }
  if(config == "exo_64443_perturbed") {
    vector<double> data;
    bool data_obtained = get_exo_64443_perturbed(data, par[0], atoi(par[1].c_str()), atoi(par[2].c_str()), atof(par[3].c_str()));
    if(data_obtained) return data;
  }

  if(config == "plummer") {
    return get_plummer(N, atof(par[0].c_str()), atof(par[1].c_str()), atof(par[2].c_str()));
  }
  if(config == "plummer_perturbed") {
    return get_plummer_perturbed(N, atof(par[0].c_str()), atof(par[1].c_str()), atof(par[2].c_str()), atof(par[3].c_str()));
  }

  if(config == "cold_plummer") {
    return get_cold_plummer(N, atof(par[0].c_str()), atof(par[1].c_str()), atof(par[2].c_str()));
  }

  if(config == "democratic_plummer") {
    return get_democratic_plummer(N, atof(par[0].c_str()), atof(par[1].c_str()), atof(par[2].c_str()));
  }
  if(config == "democratic_cold_plummer") {
    return get_democratic_cold_plummer(N, atof(par[0].c_str()), atof(par[1].c_str()), atof(par[2].c_str()));
  }
  if(config == "cold_sphere") {
    return get_cold_sphere(N, atof(par[0].c_str()), atof(par[1].c_str()), atof(par[2].c_str())); 
  }
  if(config == "virial_sphere") {
    return get_virial_sphere(N, atof(par[0].c_str()), atof(par[1].c_str()), atof(par[2].c_str()), atof(par[3].c_str())); 
  }

  if(config == "bh_plummer") {
    return get_bh_plummer(N, atof(par[0].c_str()), atof(par[1].c_str()), atof(par[2].c_str()), atof(par[3].c_str()));
  }
  if(config == "bh_solar_systems") {
    int numPlanets = atoi(par[0].c_str());
    int numBH = 1;
    int numStar = (N-numBH)/(numPlanets+1);
    return get_bh_solar_systems(numBH+numStar, numPlanets, atof(par[1].c_str()), atof(par[2].c_str()), atoi(par[3].c_str()), atoi(par[4].c_str()), atoi(par[5].c_str()));
  }
  if(config == "plummer_solar_systems") {
    int numPlanets = atoi(par[0].c_str());
    int numStar = N/(1+numPlanets);
    return get_plummer_solar_systems(numStar, numPlanets, atof(par[1].c_str()), atoi(par[2].c_str()), atoi(par[3].c_str()), atoi(par[4].c_str()));
  }

  cerr << "Invalid initial condition!" << endl;
  exit(1);
}

// Tools
void Initializer::set_random_generator(int seed, int pivot) {
  random.set_seed(seed);
  random.set_pivot(pivot);
}

void Initializer::centralize(vector<double> &data) {
  int N = data.size()/7;
  vector<double> rcm = diagnostics.get_rcm(data);
  vector<double> vcm = diagnostics.get_vcm(data);
  for(int i=0; i<N; i++) {
    data[i*7+1] -= rcm[0];
    data[i*7+2] -= rcm[1];
    data[i*7+3] -= rcm[2];
    data[i*7+4] -= vcm[0];
    data[i*7+5] -= vcm[1];
    data[i*7+6] -= vcm[2];
  }  
}
void Initializer::normalize_to_nbody_units(vector<double> &data) {
  int N = data.size()/7;
  if(N>1) {
    double M = diagnostics.get_mass(data);
    double Cm = 1.0/M;
    for(int i=0; i<N; i++) {
      data[i*7] *= Cm;
    }

    double r_vir = diagnostics.get_virial_radius(data);
    double Cr = 1.0/r_vir;
    for(int i=0; i<N; i++) {
      data[i*7+1] *= Cr;
      data[i*7+2] *= Cr;
      data[i*7+3] *= Cr;
    }

    double sigma = diagnostics.get_velocity_disperion(data);
    if(sigma > 0) {
      double Cv = 1.0/sqrt(2.0)/sigma;
      for(int i=0; i<N; i++) {
        data[i*7+4] *= Cv;
        data[i*7+5] *= Cv;
        data[i*7+6] *= Cv;
      }
    }   
  }
}
void Initializer::normalize_to_fraction_of_virial(vector<double> &data, double Q) {
  int N = data.size()/7;
  if(N>1) {
    double ek = diagnostics.get_kinetic_energy(data);
    double ep = diagnostics.get_potential_energy(data);

    double Cv = sqrt(-Q*ep/ek);
    for(int i=0; i<N; i++) {
      data[i*7+4] *= Cv;
      data[i*7+5] *= Cv;
      data[i*7+6] *= Cv;
    }

    ek = diagnostics.get_kinetic_energy(data);
    ep = diagnostics.get_potential_energy(data);

    double C = -0.25 / (ek+ep);
    double Cr = 1.0 / C;
    Cv = sqrt(C);

    for(int i=0; i<N; i++) {
      data[i*7+1] *= Cr;
      data[i*7+2] *= Cr;
      data[i*7+3] *= Cr;
      data[i*7+4] *= Cv;
      data[i*7+5] *= Cv;
      data[i*7+6] *= Cv;
    }   

    ek = diagnostics.get_kinetic_energy(data);
    ep = diagnostics.get_potential_energy(data);
    cerr << "e = " << ek+ep << endl;
    cerr << "q = " << ek/ep << endl;
  } 
}
void Initializer::normalize_to_boekholt_units(vector<double> &data) {
  int N = data.size()/7;
  double M = diagnostics.get_mass(data);
  double Cm = 1.0/M;
  for(int i=0; i<N; i++) {
    data[i*7] *= Cm;
  }
  double r_har = diagnostics.get_harmonic_radius(data);
  double Cr = 1.0/r_har;
  for(int i=0; i<N; i++) {
    data[i*7+1] *= Cr;
    data[i*7+2] *= Cr;
    data[i*7+3] *= Cr;
  }  

  double Cv = sqrt(Cm/Cr);
  for(int i=0; i<N; i++) {
    data[i*7+4] *= Cv;
    data[i*7+5] *= Cv;
    data[i*7+6] *= Cv;
  }  
}
void Initializer::rescale_position(vector<double> &data, double Cr) {
  int N = data.size()/7;
  for(int i=0; i<N; i++) {
    data[i*7+1] *= Cr;
    data[i*7+2] *= Cr;
    data[i*7+3] *= Cr;
  } 
}
void Initializer::rescale_mass_position(vector<double> &data, double Cm, double Cr) {
  int N = data.size()/7;
  for(int i=0; i<N; i++) {
    data[i*7] *= Cm;
  }
  for(int i=0; i<N; i++) {
    data[i*7+1] *= Cr;
    data[i*7+2] *= Cr;
    data[i*7+3] *= Cr;
  }  
  double Cv = sqrt(Cm/Cr);
  for(int i=0; i<N; i++) {
    data[i*7+4] *= Cv;
    data[i*7+5] *= Cv;
    data[i*7+6] *= Cv;
  }  
}
void Initializer::rescale_velocity(vector<double> &data, double Cv) {
  int N = data.size()/7;
  for(int i=0; i<N; i++) {
    data[i*7+4] *= Cv;
    data[i*7+5] *= Cv;
    data[i*7+6] *= Cv;
  } 
}
void Initializer::make_cold(vector<double> &data) {
  int N = data.size()/7;
  for(int i=0; i<N; i++) {
    data[i*7+4] = 0;
    data[i*7+5] = 0;
    data[i*7+6] = 0;
  } 
}
void Initializer::rotate_x(vector<double> &data, double angle) {
  int N = data.size()/7;
  for(int i=0; i<N; i++) {
    double xn  = data[i*7+1];
    double yn  = cos(angle)*data[i*7+2]-sin(angle)*data[i*7+3];
    double zn  = sin(angle)*data[i*7+2]+cos(angle)*data[i*7+3];
    double vxn = data[i*7+4];
    double vyn = cos(angle)*data[i*7+5]-sin(angle)*data[i*7+6];
    double vzn = sin(angle)*data[i*7+5]+cos(angle)*data[i*7+6];
    data[i*7+1] = xn;
    data[i*7+2] = yn;
    data[i*7+3] = zn;
    data[i*7+4] = vxn;
    data[i*7+5] = vyn;
    data[i*7+6] = vzn;
  }
}
void Initializer::rotate_y(vector<double> &data, double angle) {
  int N = data.size()/7;
  for(int i=0; i<N; i++) {
    double xn  = cos(angle)*data[i*7+1]+sin(angle)*data[i*7+3];
    double yn  = data[i*7+2];
    double zn  = -sin(angle)*data[i*7+1]+cos(angle)*data[i*7+3];
    double vxn = cos(angle)*data[i*7+4]+sin(angle)*data[i*7+6];
    double vyn = data[i*7+5];
    double vzn = -sin(angle)*data[i*7+4]+cos(angle)*data[i*7+6];
    data[i*7+1] = xn;
    data[i*7+2] = yn;
    data[i*7+3] = zn;
    data[i*7+4] = vxn;
    data[i*7+5] = vyn;
    data[i*7+6] = vzn;
  }
}
void Initializer::rotate_z(vector<double> &data, double angle) {
  int N = data.size()/7;
  for(int i=0; i<N; i++) {
    double xn  = cos(angle)*data[i*7+1]-sin(angle)*data[i*7+2];
    double yn  = sin(angle)*data[i*7+1]+cos(angle)*data[i*7+2];
    double zn  = data[i*7+3];
    double vxn = cos(angle)*data[i*7+4]-sin(angle)*data[i*7+5];
    double vyn = sin(angle)*data[i*7+4]+cos(angle)*data[i*7+5];
    double vzn = data[i*7+6];
    data[i*7+1] = xn;
    data[i*7+2] = yn;
    data[i*7+3] = zn;
    data[i*7+4] = vxn;
    data[i*7+5] = vyn;
    data[i*7+6] = vzn;
  }
}
void Initializer::flip_z(vector<double> &data) {
  int N = data.size()/7;
  for(int i=0; i<N; i++) {
    data[i*7+3] *= -1;
    data[i*7+6] *= -1;
  } 
}
void Initializer::flip_v(vector<double> &data) {
  int N = data.size()/7;
  for(int i=0; i<N; i++) {
    data[i*7+4] *= -1;
    data[i*7+5] *= -1;
    data[i*7+6] *= -1;
  } 
}

double Initializer::get_random_mass_ratio() {
  // f(m1/m2)=U(1,10)
  double m_ratio = random.uniform(1.0, 10.0);
  return m_ratio;
}
double Initializer::get_random_eccentricity() {
  // f(e)=2e
  bool accept = false;
  while(!accept) {
    double trial = random.uniform(0.0, 1.0);
    double p_accept = 2*trial;
    double p = 2*random.uniform(0.0, 1.0);
    if(p < p_accept) {
      return trial;
    }
  }
  cerr << "Should have returbed in look, rather than returning nothing ";
  cerr << "in Initializer::get_random_eccentricity" << endl;
  exit(1);
}

void Initializer::add_random_perturbation(vector<double> &data, double magnitude) {
  int N = data.size()/7;
  int index = (int)random.uniform(0, N);
  int coor  = 1 + (int)random.uniform(0, 3);
  int sgn;
  double dice = random.uniform(0, 1);
  if(dice < 0.5) sgn = 1;
  else sgn = -1; 
  data[index*7+coor] += sgn*magnitude;
}

// From file
bool Initializer::get_from_file(vector<double> &data, string file) {
  data.clear();
  bool file_read = data_handler.process(file);
  if(!file_read) return false;
  else {
    vector< vector<double> > file_data = data_handler.get_data();
    data = file_data[0];
    return true;
  }
}
bool Initializer::get_from_file_list(vector<double> &data, string file, int index) {
  data.clear();
  bool file_read = data_handler.process(file);
  if(!file_read) return false;
  else {
    vector< vector<double> > file_data = data_handler.get_data();
    data = file_data[index];
    return true;
  }
}
bool Initializer::continue_from_file(vector<double> &data, string file) {
  data.clear();
  bool file_read = data_handler.process(file);
  if(!file_read) return false;
  else {
    vector< vector<double> > file_data = data_handler.get_data();
    data = file_data[ file_data.size()-1 ];
    return true;
  }
}

bool Initializer::get_from_file_list_reversed(vector<double> &data, string file, int index) {
  data.clear();
  bool file_read = data_handler.process(file);
  if(!file_read) return false;
  else {
    vector< vector<double> > file_data = data_handler.get_data();
    data = file_data[index];
    flip_v(data);
    return true;
  }
}

// N=2
vector<double> Initializer::get_circle(double m_ratio) {
  vector<double> data;

  if(m_ratio < 1) m_ratio = 1.0/m_ratio;
  double m2 = 1.0/(1.0+m_ratio);
  double m1 = 1.0-m2;

  double a = 1;
  double v = 1;

  data.push_back(m1);
  data.push_back(0);
  data.push_back(0);
  data.push_back(0);
  data.push_back(0);
  data.push_back(0);
  data.push_back(0);

  data.push_back(m2);
  data.push_back(a);
  data.push_back(0);
  data.push_back(0);
  data.push_back(0);
  data.push_back(v);
  data.push_back(0);

  centralize(data);
  return data;
}
vector<double> Initializer::get_binary() {
  vector<double> data;

  double m_ratio = get_random_mass_ratio();
  double eccentricity = get_random_eccentricity();  

  if(m_ratio < 1) m_ratio = 1.0/m_ratio;
  double m2 = 1.0/(1.0+m_ratio);
  double m1 = 1.0-m2;

  double ra = 1+eccentricity;
  double rp = 1-eccentricity;

  double v_aph = 1;
  if(eccentricity != 0) {
    v_aph = sqrt( 2.0 * (1.0/rp-1.0/ra) / (ra*ra/(rp*rp)-1.0) );
  }

  data.push_back(m1);
  data.push_back(0);
  data.push_back(0);
  data.push_back(0);
  data.push_back(0);
  data.push_back(0);
  data.push_back(0);

  data.push_back(m2);
  data.push_back(ra);
  data.push_back(0);
  data.push_back(0);
  data.push_back(0);
  data.push_back(v_aph);
  data.push_back(0);

  centralize(data);

  return data;
}
vector<double> Initializer::get_binary(double m_ratio, double eccentricity) {
  vector<double> data;

  if(m_ratio < 1) m_ratio = 1.0/m_ratio;
  double m2 = 1.0/(1.0+m_ratio);
  double m1 = 1.0-m2;

  double ra = 1+eccentricity;
  double rp = 1-eccentricity;

  double v_aph = 1;
  if(eccentricity != 0) {
    v_aph = sqrt( 2.0 * (1.0/rp-1.0/ra) / (ra*ra/(rp*rp)-1.0) );
  }

  data.push_back(m1);
  data.push_back(0);
  data.push_back(0);
  data.push_back(0);
  data.push_back(0);
  data.push_back(0);
  data.push_back(0);

  data.push_back(m2);
  data.push_back(ra);
  data.push_back(0);
  data.push_back(0);
  data.push_back(0);
  data.push_back(v_aph);
  data.push_back(0);

  centralize(data);

  return data;
}
vector<double> Initializer::get_binary(double mu, double m_ratio, double semimajor_axis, double eccentricity) {
  vector<double> data;

  if(m_ratio < 1) m_ratio = 1.0/m_ratio;
  double m2 = 1.0/(1.0+m_ratio);
  double m1 = 1.0-m2;

  double ra = 1+eccentricity;
  double rp = 1-eccentricity;

  double v_aph = 1;
  if(eccentricity != 0) {
    v_aph = sqrt( 2.0 * (1.0/rp-1.0/ra) / (ra*ra/(rp*rp)-1.0) );
  }

  data.push_back(m1);
  data.push_back(0);
  data.push_back(0);
  data.push_back(0);
  data.push_back(0);
  data.push_back(0);
  data.push_back(0);

  data.push_back(m2);
  data.push_back(ra);
  data.push_back(0);
  data.push_back(0);
  data.push_back(0);
  data.push_back(v_aph);
  data.push_back(0);

  centralize(data);

  double Cm = mu;
  double Cr = semimajor_axis;
  rescale_mass_position(data, Cm, Cr);  

  return data;
}
vector<double> Initializer::get_binary_abs(double m1, double m2, double a, double e) {
  vector<double> data(14, 0);

  // M = 1
  double mu = m1+m2;
  data[0] = m1/mu;
  data[7] = m2/mu;

  // a = 1
  double ra = 1+e;
  double rp = 1-e;
  data[8] = ra;

  double v_aph = 1;
  if(e != 0) {
    v_aph = sqrt( 2.0 * (1.0/rp-1.0/ra) / (ra*ra/(rp*rp)-1.0) );
  }  
  data[12] = v_aph;

  centralize(data);

  // Renormalize to absolute units
  double Cm = mu;
  double Cr = a;
  rescale_mass_position(data, Cm, Cr);

  return data;
}
vector<double> Initializer::get_binary_perturbed(double mu, double m_ratio, double semimajor_axis, double eccentricity, double dm1, double dx1, double dy1, double dz1, double dvx1, double dvy1, double dvz1, double dm2, double dx2, double dy2, double dz2, double dvx2, double dvy2, double dvz2) {
  vector<double> data = get_binary(mu, m_ratio, semimajor_axis, eccentricity);
 
  data[0*7+0] += dm1;
  data[0*7+1] += dx1;
  data[0*7+2] += dy1;
  data[0*7+3] += dz1;
  data[0*7+4] += dvx1;
  data[0*7+5] += dvy1;
  data[0*7+6] += dvz1;

  data[1*7+0] += dm2;
  data[1*7+1] += dx2;
  data[1*7+2] += dy2;
  data[1*7+3] += dz2;
  data[1*7+4] += dvx2;
  data[1*7+5] += dvy2;
  data[1*7+6] += dvz2;

  return data;
}

vector<double> Initializer::get_parabola(double m_ratio) {
  vector<double> data;

  if(m_ratio < 1) m_ratio = 1.0/m_ratio;
  double m2 = 1.0/(1.0+m_ratio);
  double m1 = 1.0-m2;

  double rp = 2.0;
  double vp = 1.0;

  data.push_back(m1);
  data.push_back(0);
  data.push_back(0);
  data.push_back(0);
  data.push_back(0);
  data.push_back(0);
  data.push_back(0);

  data.push_back(m2);
  data.push_back(0);
  data.push_back(-rp);
  data.push_back(0);
  data.push_back(vp);
  data.push_back(0);
  data.push_back(0);

  centralize(data);  

  return data;
}
vector<double> Initializer::get_hyperbola(double m_ratio, double eccentricity) {
  vector<double> data;

  if(m_ratio > 1) m_ratio = 1.0/m_ratio;
  double m1 = 1.0/(1.0+m_ratio);
  double m2 = 1.0-m1;

  if(eccentricity <= 1) eccentricity = 1.0 + 1e-12;
  double e = 0.5;

  double vp = sqrt( 2.0*(e + 1.0/(1.0-eccentricity)) );
  double rp = 2.0 / (vp*vp - 1);

  data.push_back(m1);
  data.push_back(0);
  data.push_back(0);
  data.push_back(0);
  data.push_back(0);
  data.push_back(0);
  data.push_back(0);

  data.push_back(m2);
  data.push_back(0);
  data.push_back(-rp);
  data.push_back(0);
  data.push_back(vp);
  data.push_back(0);
  data.push_back(0);  

  centralize(data);

  return data;
}

vector<double> Initializer::get_radial(double m_ratio, double energy) {
  vector<double> data;

  if(m_ratio > 1) m_ratio = 1.0/m_ratio;
  double m1 = 1.0/(1.0+m_ratio);
  double m2 = 1.0-m1;

  double x1 = 0;
  double x2 = 1e-6;

  double vx1 = 0;
  double vx2 = sqrt(2.0*(energy+1.0/x2));

  data.push_back(m1);
  data.push_back(x1);
  data.push_back(0);
  data.push_back(0);
  data.push_back(vx1);
  data.push_back(0);
  data.push_back(0);

  data.push_back(m2);
  data.push_back(x2);
  data.push_back(0);
  data.push_back(0);
  data.push_back(vx2);
  data.push_back(0);
  data.push_back(0);

  centralize(data);

  return data;
}

// N=3
vector<double> Initializer::get_figure8() {
  vector<double> data;
  data.push_back(1);
  data.push_back(0);
  data.push_back(0);
  data.push_back(0);
  data.push_back(-0.93240737);
  data.push_back(-0.86473146);
  data.push_back(0);

  data.push_back(1);
  data.push_back(0.9700436);
  data.push_back(-0.24308753);
  data.push_back(0);
  data.push_back(0.466203685);
  data.push_back(0.43236573);
  data.push_back(0);

  data.push_back(1);
  data.push_back(-0.9700436);
  data.push_back(0.24308753);
  data.push_back(0);
  data.push_back(0.466203685);
  data.push_back(0.43236573);
  data.push_back(0);
  return data;
}
vector<double> Initializer::get_figure8(int numDigits) {
  vector<double> data;

  if(numDigits < 1) numDigits = 1;
  if(numDigits > 9) numDigits = 9;

  double precision = pow(10.0, -numDigits);

  string aa = "0.9324073700";
  string bb = "0.8647314600";
  string cc = "0.9700436000";
  string dd = "0.2430875300";
  string ee = "0.4662036850";
  string ff = "0.4323657300";

  string a1 = "0.";
  string b1 = "0.";
  string c1 = "0.";
  string d1 = "0.";
  string e1 = "0.";
  string f1 = "0.";
  for(int i=0; i<numDigits; i++) {
    a1 += aa[2+i];
    b1 += bb[2+i];
    c1 += cc[2+i];
    d1 += dd[2+i];
    e1 += ee[2+i];
    f1 += ff[2+i];
  }
  string a2 = "0.";
  string b2 = "0.";
  string c2 = "0.";
  string d2 = "0.";
  string e2 = "0.";
  string f2 = "0.";
  for(int i=0; i<numDigits+1; i++) {
    a2 += aa[2+i];
    b2 += bb[2+i];
    c2 += cc[2+i];
    d2 += dd[2+i];
    e2 += ee[2+i];
    f2 += ff[2+i];
  }

  double a3 = atof(a1.c_str());
  double b3 = atof(b1.c_str());
  double c3 = atof(c1.c_str());
  double d3 = atof(d1.c_str());
  double e3 = atof(e1.c_str());
  double f3 = atof(f1.c_str());
  double a4 = atof(a2.c_str());
  double b4 = atof(b2.c_str());
  double c4 = atof(c2.c_str());
  double d4 = atof(d2.c_str());
  double e4 = atof(e2.c_str());
  double f4 = atof(f2.c_str());

  double diffa = a4-a3;
  double diffb = b4-b3;
  double diffc = c4-c3;
  double diffd = d4-d3;
  double diffe = e4-e3;
  double difff = f4-f3;

  if(diffa > precision/2-precision/20) a3 += precision;
  if(diffb > precision/2-precision/20) b3 += precision;
  if(diffc > precision/2-precision/20) c3 += precision;
  if(diffd > precision/2-precision/20) d3 += precision;
  if(diffe > precision/2-precision/20) e3 += precision;
  if(difff > precision/2-precision/20) f3 += precision;

  data.push_back(1);
  data.push_back(0);
  data.push_back(0);
  data.push_back(0);
  data.push_back(-1*a3);
  data.push_back(-1*b3);
  data.push_back(0);

  data.push_back(1);
  data.push_back(c3);
  data.push_back(-1*d3);
  data.push_back(0);
  data.push_back(e3);
  data.push_back(f3);
  data.push_back(0);

  data.push_back(1);
  data.push_back(-1*c3);
  data.push_back(d3);
  data.push_back(0);
  data.push_back(e3);
  data.push_back(f3);
  data.push_back(0);

  centralize(data);

  return data;
}
vector<double> Initializer::get_figure8_perturbed(double dr, int seed, int pivot, int index) {
  vector<double> data;

  set_random_generator(seed, pivot);

  for(int i=0; i<=index; i++) {
    data = get_figure8();  
    double p = (random.uniform(0.0, 4.0)-2.0)/(dr/10.0);
    data[3] += dr+p;
  }

  centralize(data);

  return data;
}

vector<double> Initializer::get_figure8_dr(int index, int coor, double dx) {
  vector<double> data;

  data = get_figure8();
  data[index*7+coor] += dx;  

  return data;
}

vector<double> Initializer::get_triangle() {
  vector<double> data;

  data.push_back(1);
  data.push_back(0);
  data.push_back(0);
  data.push_back(0);
  data.push_back(-0.5);
  data.push_back(sqrt(0.75));
  data.push_back(0);

  data.push_back(1);
  data.push_back(1);
  data.push_back(0);
  data.push_back(0);
  data.push_back(-0.5);
  data.push_back(-sqrt(0.75));
  data.push_back(0);

  data.push_back(1);
  data.push_back(0.5);
  data.push_back(sqrt(0.75));
  data.push_back(0);
  data.push_back(1);
  data.push_back(0);
  data.push_back(0);

  centralize(data);

  return data;
}
vector<double> Initializer::get_triangle(int numDigits) {
  vector<double> data;

  if(numDigits < 1) numDigits = 1;
  if(numDigits > 15) numDigits = 15;

  double precision = pow(10.0, -numDigits);

  string cc = "0.8660254037844386";

  string c1 = "0.";
  for(int i=0; i<numDigits; i++) {
    c1 += cc[2+i];
  }
  string c2 = "0.";
  for(int i=0; i<numDigits+1; i++) {
    c2 += cc[2+i];
  }

  double c3 = atof(c1.c_str());
  double c4 = atof(c2.c_str());

  double diffc = c4-c3;

  if(diffc > precision/2-precision/20) c3 += precision;

  data.push_back(1);
  data.push_back(0);
  data.push_back(0);
  data.push_back(0);
  data.push_back(-0.5);
  data.push_back(c3);
  data.push_back(0);

  data.push_back(1);
  data.push_back(1);
  data.push_back(0);
  data.push_back(0);
  data.push_back(-0.5);
  data.push_back(-c3);
  data.push_back(0);

  data.push_back(1);
  data.push_back(0.5);
  data.push_back(c3);
  data.push_back(0);
  data.push_back(1);
  data.push_back(0);
  data.push_back(0);

  centralize(data);

  return data;
}

vector<double> Initializer::get_butterfly() {
  vector<double> data;

  double a = 0.306892758965492;
  double b = 0.125506782829762;

  data.push_back(1);
  data.push_back(-1);
  data.push_back(0);
  data.push_back(0);
  data.push_back(a);
  data.push_back(b);
  data.push_back(0);

  data.push_back(1);
  data.push_back(1);
  data.push_back(0);
  data.push_back(0);
  data.push_back(a);
  data.push_back(b);
  data.push_back(0);

  data.push_back(1);
  data.push_back(0);
  data.push_back(0);
  data.push_back(0);
  data.push_back(-2*a);
  data.push_back(-2*b);
  data.push_back(0);

  return data;
}
vector<double> Initializer::get_butterfly(int numDigits) {
  vector<double> data;

  if(numDigits < 1) numDigits = 1;
  if(numDigits > 15) numDigits = 15;

  double precision = pow(10.0, -numDigits);

  string aa = "0.306892758965492";
  string bb = "0.125506782829762";

  string a1 = "0.";
  string b1 = "0.";
  for(int i=0; i<numDigits; i++) {
    a1 += aa[2+i];
    b1 += bb[2+i];
  }
  string a2 = "0.";
  string b2 = "0.";
  for(int i=0; i<numDigits+1; i++) {
    a2 += aa[2+i];
    b2 += bb[2+i];
  }

  double a3 = atof(a1.c_str());
  double b3 = atof(b1.c_str());

  double a4 = atof(a2.c_str());
  double b4 = atof(b2.c_str());

  double diffa = a4-a3;
  double diffb = b4-b3;

  if(diffa > precision/2-precision/20) a3 += precision;
  if(diffb > precision/2-precision/20) b3 += precision;

  data.push_back(1);
  data.push_back(-1);
  data.push_back(0);
  data.push_back(0);
  data.push_back(a3);
  data.push_back(b3);
  data.push_back(0);

  data.push_back(1);
  data.push_back(1);
  data.push_back(0);
  data.push_back(0);
  data.push_back(a3);
  data.push_back(b3);
  data.push_back(0);

  data.push_back(1);
  data.push_back(0);
  data.push_back(0);
  data.push_back(0);
  data.push_back(-2*a3);
  data.push_back(-2*b3);
  data.push_back(0);

  return data;
}

vector<double> Initializer::get_pythagorean() {
  vector<double> data;
  data.push_back(3);
  data.push_back(1);
  data.push_back(3);
  data.push_back(0);
  data.push_back(0);
  data.push_back(0);
  data.push_back(0);

  data.push_back(4);
  data.push_back(-2);
  data.push_back(-1);
  data.push_back(0);
  data.push_back(0);
  data.push_back(0);
  data.push_back(0);

  data.push_back(5);
  data.push_back(1);
  data.push_back(-1);
  data.push_back(0);
  data.push_back(0);
  data.push_back(0);
  data.push_back(0);
  return data;
}
vector<double> Initializer::get_pythagorean_perturbed(int index, int coor, double delta) {
  vector<double> data = get_pythagorean();
  data[index*7 + coor] += delta;
  return data;
}

vector<double> Initializer::get_sitnikov(double ecc, double vz0) {
  vector<double> data = get_binary(1.0, ecc);
  data.push_back(0.0);
  data.push_back(0.0);
  data.push_back(0.0);
  data.push_back(0.0);
  data.push_back(0.0);
  data.push_back(0.0);
  data.push_back(vz0);
  return data;
}
vector<double> Initializer::get_sitnikov(double ecc, double vz0, double angle) {
  vector<double> data = get_binary(1.0, ecc);
  data.push_back(0.0);
  data.push_back(0.0);
  data.push_back(0.0);
  data.push_back(0.0);
  data.push_back(0.0);
  data.push_back(0.0);
  data.push_back(vz0);

  rotate_x(data, angle);
  centralize(data);

  return data;
}
vector<double> Initializer::get_sitnikov_mass(double ecc, double vz0, double m) {
  vector<double> data = get_binary(1.0, ecc);
  data.push_back(m);
  data.push_back(0.0);
  data.push_back(0.0);
  data.push_back(0.0);
  data.push_back(0.0);
  data.push_back(0.0);
  data.push_back(vz0);
  return data;
}

vector<double> Initializer::get_hierarchical_triple() {
  vector<double> data;

  vector<double> b1 = get_binary();
  vector<double> b2 = get_binary();

  double f_stab = random.uniform(1.0, 10.0);

  vector<double> bin_prop = products.get_binary_properties(b2, 0, 1);
  double e = bin_prop[1];

  double Cr = f_stab/(1.0-e);

  rescale_position(b2, Cr);

  data = b1;

  data[0*7+0] *= 0.5;
  data[1*7+0] *= 0.5;
  for(int i=1; i<7; i++) {
    data[0*7+i] += b2[0*7+i];
    data[1*7+i] += b2[0*7+i];
  }

  for(int i=0; i<7; i++) {
    data.push_back(b2[1*7+i]);
  }

  centralize(data);

  return data;
}
vector<double> Initializer::get_hierarchical_triple(double m1, double m2, double m3, double a_inner, double e_inner, double a_outer, double e_outer, double inclination) {
  vector<double> b_inner = get_binary(m2/m1, e_inner);
  vector<double> b_outer = get_binary(m3/(m1+m2), e_outer);

  double Cm = (m1+m2) / (m1+m2+m3);
  double Cr = a_inner / a_outer;
  rescale_mass_position(b_inner, Cm, Cr);  

  double angle = inclination / 360.0 * 2.0*acos(-1.0);
  rotate_y(b_inner, angle);

  vector<double> data = b_inner;
  for(int i=1; i<7; i++) {
    data[i] += b_outer[i];
    data[i+7] += b_outer[i];
  }
  for(int i=7; i<14; i++) data.push_back(b_outer[i]);

  centralize(data);

  return data;
}

vector<double> Initializer::get_N3_plummer_mass_ratio(int seed, int pivot, int index) {
  vector<double> data = get_plummer(3, seed, pivot, index);
  data[0*7] = 4;
  data[1*7] = 2;
  data[2*7] = 1;
  centralize(data);
  normalize_to_nbody_units(data);
  return data;
}
vector<double> Initializer::get_N3_cold_plummer_mass_ratio(int seed, int pivot, int index) {
  vector<double> data = get_cold_plummer(3, seed, pivot, index);
  data[0*7] = 4;
  data[1*7] = 2;
  data[2*7] = 1;
  centralize(data);
  double Cm = 1.0/(1+2+4);
  double Cr = 1.0;
  rescale_mass_position(data, Cm, Cr);
  return data;
}
vector<double> Initializer::get_N3_democratic_plummer_mass_ratio(int seed, int pivot, int index) {
  vector<double> data = get_democratic_plummer(3, seed, pivot, index);
  data[0*7] = 4;
  data[1*7] = 2;
  data[2*7] = 1;
  centralize(data);
  normalize_to_nbody_units(data);
  return data;
}
vector<double> Initializer::get_N3_democratic_cold_plummer_mass_ratio(int seed, int pivot, int index) {
  vector<double> data = get_democratic_cold_plummer(3, seed, pivot, index);
  data[0*7] = 4;
  data[1*7] = 2;
  data[2*7] = 1;
  centralize(data);
  double Cm = 1.0/(1+2+4);
  double Cr = 1.0;
  rescale_mass_position(data, Cm, Cr);

  double E = diagnostics.get_energy(data);
  double E0 = -0.25;
  Cr = E/E0;

  rescale_mass_position(data, 1.0, Cr);

  return data;
}

vector<double> Initializer::get_sun_jupiter_halley(int N, int seed, int pivot, int index, double f_error) {
  vector<double> data;

  data.push_back(1);
  data.push_back(2.460401724204089E-03);
  data.push_back(-1.296457510903158E-03);
  data.push_back(-1.280557668401947E-04);
  data.push_back(4.587732003425030E-06);
  data.push_back(4.654909129447831E-06);
  data.push_back(-1.110955702891871E-07);
     
  data.push_back(0.0009545940905009727);
  data.push_back(-3.211787993621413E+00);
  data.push_back(4.201506346143431E+00);
  data.push_back(5.434137703482850E-02);
  data.push_back(-6.085188929003960E-03);
  data.push_back(-4.227184133398781E-03);
  data.push_back(1.537379058870405E-04);
     
  // Halley
  set_random_generator(seed, pivot);
  double dx, dy, dz, dvx, dvy, dvz;
  for(int k=0; k<=index; k++) {
    dx  = (random.uniform(0.0, 2.0)-1.0)*f_error;
    dy  = (random.uniform(0.0, 2.0)-1.0)*f_error;
    dz  = (random.uniform(0.0, 2.0)-1.0)*f_error;
    //dvx = (random.uniform(0.0, 2.0)-1.0)*f_error;
    //dvy = (random.uniform(0.0, 2.0)-1.0)*f_error;
    //dvz = (random.uniform(0.0, 2.0)-1.0)*f_error;
  }
  data.push_back(1.1063355e-16);
  data.push_back(-2.046011952809097E+01+dx);
  data.push_back(2.513980121805306E+01+dy);
  data.push_back(-9.771054962044406E+00+dz);
  //data.push_back(-6.631852646093806E-05+dvx);
  //data.push_back(9.404758449357039E-04+dvy);
  //data.push_back(-1.740327105577856E-04+dvz);

  double Cv = 58.12435834603945838;
  for(int i=0; i<N; i++) {
    for(int j=4; j<7; j++) {
      data[i*7+j] *= Cv;
    }
  }

  return data;
}

vector<double> Initializer::get_sun_jupiter_asteroid(double da) {
  // M = 1
  double fm = 0.001;
  // a = 1
  double e = 0.;  
  vector<double> data = get_binary(fm, e);

  data.push_back(1e-12);
  data.push_back(1. + da);
  data.push_back(0);
  data.push_back(0);
  data.push_back(0);
  data.push_back(0);
  data.push_back(0);

  return data;
}

// N=4
vector<double> Initializer::get_N4_plummer_mass_ratio(int seed, int pivot, int index) {
  vector<double> data = get_plummer(4, seed, pivot, index);
  data[0*7] = 8;
  data[1*7] = 4;
  data[2*7] = 2;
  data[3*7] = 1;
  centralize(data);
  normalize_to_nbody_units(data);
  return data;
}
vector<double> Initializer::get_N4_cold_plummer_mass_ratio(int seed, int pivot, int index) {
  vector<double> data = get_cold_plummer(4, seed, pivot, index);
  data[0*7] = 8;
  data[1*7] = 4;
  data[2*7] = 2;
  data[3*7] = 1;
  centralize(data);
  double Cm = 1.0/(1+2+4+8);
  double Cr = 1.0;
  rescale_mass_position(data, Cm, Cr);
  return data;
}
vector<double> Initializer::get_N4_democratic_plummer_mass_ratio(int seed, int pivot, int index) {
  vector<double> data = get_democratic_plummer(4, seed, pivot, index);
  data[0*7] = 8;
  data[1*7] = 4;
  data[2*7] = 2;
  data[3*7] = 1;
  centralize(data);
  normalize_to_nbody_units(data);
  return data;
}
vector<double> Initializer::get_N4_democratic_cold_plummer_mass_ratio(int seed, int pivot, int index) {
  vector<double> data = get_democratic_cold_plummer(4, seed, pivot, index);
  data[0*7] = 8;
  data[1*7] = 4;
  data[2*7] = 2;
  data[3*7] = 1;
  centralize(data);
  double Cm = 1.0/(1+2+4+8);
  double Cr = 1.0;
  rescale_mass_position(data, Cm, Cr);

  double E = diagnostics.get_energy(data);
  double E0 = -0.25;
  Cr = E/E0;

  rescale_mass_position(data, 1.0, Cr);

  return data;
}

vector<double> Initializer::get_binary_collision(double mass_ratio, double a1, double e1, double a2, double e2, double p, double v) {
  vector<double> bin1 = get_binary(1.0, e1);
  vector<double> bin2 = get_binary(1.0, e2);

  double Cm = 0.5;
  double Cr = a1;
  rescale_mass_position(bin1, Cm, Cr);
  Cr = a2;
  rescale_mass_position(bin2, Cm, Cr);

  bin2[0*7+1] += 10.0;
  bin2[1*7+1] += 10.0;
  bin2[0*7+2] += p;
  bin2[1*7+2] += p;
  bin2[0*7+4] -= v;
  bin2[1*7+4] -= v;  
  
  vector<double> data = bin1;
  for(int i=0; i<bin2.size(); i++) {
    data.push_back(bin2[i]);
  }

  centralize(data);

  return data;
}

// N=5
vector<double> Initializer::get_nice_model() {
  vector<double> data;

  double m_sun = 1.;
  double m_jup = 0.0009545940905009727;
  double m_sat = 0.0002858150131819827;
  double m_ura = 4.3658047415668107e-5;
  double m_nep = 5.1503137142531555e-5;

  double a_jup = 6.;

  double res_sat = 3./2.;
  double res_ura = 3./2.;
  double res_nep = 5./4.;

  double pi = acos(-1.);

  data.push_back(m_sun);
  data.push_back(0.); 
  data.push_back(0.); 
  data.push_back(0.); 
  data.push_back(0.); 
  data.push_back(0.); 
  data.push_back(0.); 

  double mu_jup = m_sun + m_jup;
  double v_jup = sqrt(mu_jup/a_jup);
  double P_jup = 2.*pi*sqrt(pow(a_jup, 3.) / mu_jup);

  data.push_back(m_jup);
  data.push_back(a_jup); 
  data.push_back(0.); 
  data.push_back(0.); 
  data.push_back(0.); 
  data.push_back(v_jup); 
  data.push_back(0.); 

  double mu_sat = m_sun + m_sat;
  double P_sat = res_sat * P_jup;
  double a_sat = pow(mu_sat*P_sat*P_sat/(4.*pi*pi), 1./3.);
  double v_sat = sqrt(mu_sat/a_sat);

  data.push_back(m_sat); 	     
  data.push_back(a_sat); 
  data.push_back(0.); 
  data.push_back(0.); 
  data.push_back(0.); 
  data.push_back(v_sat); 
  data.push_back(0.); 

  double mu_ura = m_sun + m_ura;
  double P_ura = res_ura * P_sat;
  double a_ura = pow(mu_ura*P_ura*P_ura/(4.*pi*pi), 1./3.);
  double v_ura = sqrt(mu_ura/a_ura);

  data.push_back(m_ura); 
  data.push_back(a_ura); 
  data.push_back(0.); 
  data.push_back(0.); 
  data.push_back(0.); 
  data.push_back(v_ura); 
  data.push_back(0.); 

  double mu_nep = m_sun + m_nep;
  double P_nep = res_nep * P_ura;
  double a_nep = pow(mu_nep*P_nep*P_nep/(4.*pi*pi), 1./3.);
  double v_nep = sqrt(mu_nep/a_nep);

  data.push_back(m_nep); 
  data.push_back(a_nep); 
  data.push_back(0.); 
  data.push_back(0.); 
  data.push_back(0.); 
  data.push_back(v_nep); 
  data.push_back(0.); 

  centralize(data);

  return data;
}

// N=9
vector<double> Initializer::get_solar_system_jpl_without_mercury(int index, int coor, double perturbation) {
  vector<double> data;

  double m1  = 1;
  double x1  = 2.072946918590417E-03;
  double y1  = -1.643061287382110E-03;
  double z1  = -1.185823088540438E-04;
  double vx1 = 5.059930816518583E-06;
  double vy1 = 3.989470642047999E-06;
  double vz1 = -1.243838264183300E-07;

  double m2  = 1.6601375118291464e-7;
  double x2  = 3.574733791200970E-01;
  double y2  = -1.171187317227507E-02;
  double z2  = -3.354856363159710E-02;
  double vx2 = -4.633283577618537E-03;
  double vy2 = 2.938619087935777E-02;
  double vz2 = 2.826185769428105E-03;

  double mu = m1+m2;
  double xcm = (m1*x1+m2*x2)/mu;
  double ycm = (m1*y1+m2*y2)/mu;
  double zcm = (m1*z1+m2*z2)/mu;
  double vxcm = (m1*vx1+m2*vx2)/mu;
  double vycm = (m1*vy1+m2*vy2)/mu;
  double vzcm = (m1*vz1+m2*vz2)/mu;

  data.push_back(mu);
  data.push_back(xcm);
  data.push_back(ycm);
  data.push_back(zcm);
  data.push_back(vxcm);
  data.push_back(vycm);
  data.push_back(vzcm);
  	   	       
  data.push_back(2.44783857411814e-6);
  data.push_back(4.876790422110325E-01);
  data.push_back(5.332660900104316E-01);
  data.push_back(-2.081177373810901E-02);
  data.push_back(-1.503296302925791E-02);
  data.push_back(1.351327482426259E-02);
  data.push_back(1.052862263953481E-03);
 	  	         
  data.push_back(3.0404326668433355e-6);
  data.push_back(4.026754002834322E-01);
  data.push_back(-9.357700005133348E-01);
  data.push_back(-8.932490601085987E-05);
  data.push_back(1.553740564985712E-02);
  data.push_back(6.720378960900881E-03);
  data.push_back(-3.796916120995478E-07);
 	  	       
  data.push_back(3.227150370113422e-7);
  data.push_back(-5.844200241438797E-01);
  data.push_back(-1.390641490399950E+00);
  data.push_back(-1.482626102558087E-02);
  data.push_back(1.342616848375762E-02);
  data.push_back(-4.237723031036153E-03);
  data.push_back(-4.184228274540421E-04);

  data.push_back(0.0009545940905009727);
  data.push_back(-2.705363190538412E+00);
  data.push_back(4.511969711234348E+00);
  data.push_back(4.171926801427295E-02);
  data.push_back(-6.562761960592283E-03);
  data.push_back(-3.524082083761892E-03);
  data.push_back(1.615059047295873E-04);
 	   	       
  data.push_back(0.0002858150131819827);
  data.push_back(-6.120971157013838E+00);
  data.push_back(-7.799968424277239E+00);
  data.push_back(3.792260890576647E-01);
  data.push_back(4.084918553333202E-03);
  data.push_back(-3.458702472764618E-03);
  data.push_back(-1.026661638527525E-04);
  	   	        
  data.push_back(4.3658047415668107e-5);
  data.push_back(1.947563780483501E+01);
  data.push_back(4.637428187478366E+00);
  data.push_back(-2.350901336659057E-01);
  data.push_back(-9.397988346434892E-04);
  data.push_back(3.642810279796556E-03);
  data.push_back(2.574368503661651E-05);
 	  	       
  data.push_back(5.1503137142531555e-5);
  data.push_back(2.731924333900583E+01);
  data.push_back(-1.233234986862218E+01);
  data.push_back(-3.756379750691105E-01);
  data.push_back(1.270955946848631E-03);
  data.push_back(2.880167515810431E-03);
  data.push_back(-8.840273274466099E-05);
      	   	   
  data.push_back(7.3442323846354385e-9);
  data.push_back(6.872419409625540E+00);
  data.push_back(-3.192773277605658E+01);
  data.push_back(1.428555846904559E+00);
  data.push_back(3.130439755573468E-03);
  data.push_back(2.364247270061568E-05);
  data.push_back(-9.080391301223528E-04);
  
  //double Cv = 58.12435834603945838;
  double Cv = 365.242 / (2.*acos(-1.));

  int N = data.size()/7;
  for(int i=0; i<N; i++) {
    for(int j=4; j<7; j++) {
      data[i*7+j] *= Cv;
    }
  }

  data[index*7+coor] += perturbation;

  return data;
}

vector<double> Initializer::get_solar_system_jpl_without_mercury_reversed(int index, int coor, double perturbation) {
  vector<double> data = get_solar_system_jpl_without_mercury(index, coor, perturbation);
  flip_v(data);
  return data;
}

// N=10
vector<double> Initializer::get_solar_system_ito() {
  vector<double> data;

  data.push_back(1);
  data.push_back(-0.00712377699396443);
  data.push_back(-0.00283538985630487);
  data.push_back(-4.63675825294682e-06);
  data.push_back(0.000315043129753047);
  data.push_back(-0.000428788597909482);
  data.push_back(-8.53535576770256e-07);
      
  data.push_back(1.66013679527193e-07);
  data.push_back(-0.134041839403259);
  data.push_back(-0.450586209684483);
  data.push_back(-0.0317327781784651);
  data.push_back(1.24765113964416);
  data.push_back(-0.367348560236518);
  data.push_back(-0.11505457416379);
      
  data.push_back(2.44783833966455e-06);
  data.push_back(-0.726062021587661);
  data.push_back(-0.039665992657221);
  data.push_back(0.0218575042921458);
  data.push_back(0.0537323647367395);
  data.push_back(-1.17961128266637);
  data.push_back(-0.0273933407210185);
       
  data.push_back(3.04043264626853e-06);
  data.push_back(-0.189566509161968);
  data.push_back(0.963413224416489);
  data.push_back(0.00338899408041853);
  data.push_back(-0.998489725622231);
  data.push_back(-0.189356029048893);
  data.push_back(-0.0277905056358035);
      
  data.push_back(3.22715144505387e-07);
  data.push_back(1.38407082168322);
  data.push_back(-0.00854263708448956);
  data.push_back(0.00195338624778221);
  data.push_back(0.0339697602312997);
  data.push_back(0.882336954083445);
  data.push_back(0.0258975097250254);
      
  data.push_back(0.000954791938424327);
  data.push_back(3.97896476349658);
  data.push_back(2.95779610056192);
  data.push_back(0.0277878676318589);
  data.push_back(-0.267315308034173);
  data.push_back(0.372606717609675);
  data.push_back(0.000533607251937168);
      
  data.push_back(0.000285885980666131);
  data.push_back(6.37017339500169);
  data.push_back(6.60411921341949);
  data.push_back(-0.146003410253912);
  data.push_back(-0.2504985023359);
  data.push_back(0.224300955779407);
  data.push_back(0.00131013765082432);
      
  data.push_back(4.36625166911354e-05);
  data.push_back(14.502078723897);
  data.push_back(-13.6574724004636);
  data.push_back(0.0266710693728891);
  data.push_back(0.155097409556616);
  data.push_back(0.155754862016402);
  data.push_back(0.00394092485741823);
      
  data.push_back(5.15138902046612e-05);
  data.push_back(16.9343722652737);
  data.push_back(-24.904781203303);
  data.push_back(0.360719859921208);
  data.push_back(0.149752685968701);
  data.push_back(0.103693951061509);
  data.push_back(-0.000776459933629997);
      
  data.push_back(7.40740740830878e-09);
  data.push_back(-9.87695317832301);
  data.push_back(-28.0623724768707);
  data.push_back(5.35614463977912);
  data.push_back(0.177878490988979);
  data.push_back(-0.0885170840283217);
  data.push_back(-0.0375021230229398);
  
  return data;
}
vector<double> Initializer::get_solar_system_jpl() {
  vector<double> data;

  data.push_back(1);
  data.push_back(2.072946918590417E-03);
  data.push_back(-1.643061287382110E-03);
  data.push_back(-1.185823088540438E-04);
  data.push_back(5.059930816518583E-06);
  data.push_back(3.989470642047999E-06);
  data.push_back(-1.243838264183300E-07);
      
  data.push_back(1.6601375118291464e-7);
  data.push_back(3.574733791200970E-01);
  data.push_back(-1.171187317227507E-02);
  data.push_back(-3.354856363159710E-02);
  data.push_back(-4.633283577618537E-03);
  data.push_back(2.938619087935777E-02);
  data.push_back(2.826185769428105E-03);
  	   	       
  data.push_back(2.44783857411814e-6);
  data.push_back(4.876790422110325E-01);
  data.push_back(5.332660900104316E-01);
  data.push_back(-2.081177373810901E-02);
  data.push_back(-1.503296302925791E-02);
  data.push_back(1.351327482426259E-02);
  data.push_back(1.052862263953481E-03);
 	  	         
  data.push_back(3.0404326668433355e-6);
  data.push_back(4.026754002834322E-01);
  data.push_back(-9.357700005133348E-01);
  data.push_back(-8.932490601085987E-05);
  data.push_back(1.553740564985712E-02);
  data.push_back(6.720378960900881E-03);
  data.push_back(-3.796916120995478E-07);
 	  	       
  data.push_back(3.227150370113422e-7);
  data.push_back(-5.844200241438797E-01);
  data.push_back(-1.390641490399950E+00);
  data.push_back(-1.482626102558087E-02);
  data.push_back(1.342616848375762E-02);
  data.push_back(-4.237723031036153E-03);
  data.push_back(-4.184228274540421E-04);

  data.push_back(0.0009545940905009727);
  data.push_back(-2.705363190538412E+00);
  data.push_back(4.511969711234348E+00);
  data.push_back(4.171926801427295E-02);
  data.push_back(-6.562761960592283E-03);
  data.push_back(-3.524082083761892E-03);
  data.push_back(1.615059047295873E-04);
 	   	       
  data.push_back(0.0002858150131819827);
  data.push_back(-6.120971157013838E+00);
  data.push_back(-7.799968424277239E+00);
  data.push_back(3.792260890576647E-01);
  data.push_back(4.084918553333202E-03);
  data.push_back(-3.458702472764618E-03);
  data.push_back(-1.026661638527525E-04);
  	   	        
  data.push_back(4.3658047415668107e-5);
  data.push_back(1.947563780483501E+01);
  data.push_back(4.637428187478366E+00);
  data.push_back(-2.350901336659057E-01);
  data.push_back(-9.397988346434892E-04);
  data.push_back(3.642810279796556E-03);
  data.push_back(2.574368503661651E-05);
 	  	       
  data.push_back(5.1503137142531555e-5);
  data.push_back(2.731924333900583E+01);
  data.push_back(-1.233234986862218E+01);
  data.push_back(-3.756379750691105E-01);
  data.push_back(1.270955946848631E-03);
  data.push_back(2.880167515810431E-03);
  data.push_back(-8.840273274466099E-05);
      	   	   
  data.push_back(7.3442323846354385e-9);
  data.push_back(6.872419409625540E+00);
  data.push_back(-3.192773277605658E+01);
  data.push_back(1.428555846904559E+00);
  data.push_back(3.130439755573468E-03);
  data.push_back(2.364247270061568E-05);
  data.push_back(-9.080391301223528E-04);

  centralize(data);
  
  //double Cv = 58.12435834603945838;
  double Cv = 365.242 / (2.*acos(-1.));

  int N = data.size()/7;
  for(int i=0; i<N; i++) {
    for(int j=4; j<7; j++) {
      data[i*7+j] *= Cv;
    }
  }

  return data;
}
vector<double> Initializer::get_solar_system_jpl(double ferror, int seed, int pivot, int index) {
  vector<double> data = get_solar_system_jpl();

  set_random_generator(seed, pivot);

  for(int k=0; k<=index; k++) {

    int N = data.size()/7;
    for(int i=0; i<N; i++) {
      for(int j=0; j<7; j++) {
        double x = data[i*7+j];
        double dx = ferror * x;
        if(dx < 0) dx *= -1;
        double r = random.gaussian(x, dx);
        data[i*7+j] = r;
      }
    }

  }

  return data;
}
vector<double> Initializer::get_solar_system_jpl(int index, double perturbation) {
  vector<double> data = get_solar_system_jpl();

  data[index*7+1] += perturbation;

  return data;
}

vector<double> Initializer::get_solar_system_ito_backwards() {
  vector<double> data = get_solar_system_ito();
  flip_v(data);
  return data;
}
vector<double> Initializer::get_solar_system_jpl_backwards() {
  vector<double> data = get_solar_system_jpl();
  flip_v(data);
  return data;
}
vector<double> Initializer::get_solar_system_jpl_backwards(double epsilon, int seed, int pivot, int index) {
  vector<double> data = get_solar_system_jpl(epsilon, seed, pivot, index);
  flip_v(data);
  return data;
}
vector<double> Initializer::get_solar_system_jpl_backwards(int index, double perturbation) {
  vector<double> data = get_solar_system_jpl_backwards();

  data[index*7+1] += perturbation;

  return data;
}

vector<double> Initializer::get_full_solar_system(int N, int seed, int pivot, int index) {
  // Msun = 1, Rpluto = 1
  vector<double> ss = get_solar_system_ito();

  // Rescale so that Rearth = 1, or ~AU = 1
  int numPl = 3;
  double Rearth = sqrt(ss[numPl*7+1]*ss[numPl*7+1]+ss[numPl*7+2]*ss[numPl*7+2]+ss[numPl*7+3]*ss[numPl*7+3]);
  double Cr = 1.0/Rearth;
  double Cv = sqrt(1.0/Cr);
  for(int i=0; i<ss.size()/7; i++) {
    ss[i*7+1] *= Cr;
    ss[i*7+2] *= Cr;
    ss[i*7+3] *= Cr;
    ss[i*7+4] *= Cv;
    ss[i*7+5] *= Cv;
    ss[i*7+6] *= Cv;
  }

  // Pearth = 2 pi AU / v ~ 2pi / sqrt(G Msun / AU) ~ 2pi: 1 year = 2pi 

  // Mtorus = 1e-3 Mearth = 1e-3 1e-6 Msun = 1e-9 Msun
  double m_ratio = 1e-9;

  // a_inner = 1.8 au, a_outer = 4.8 au
  double a_inner_ring = 1.8;
  double a_outer_ring = 4.5;
  double a_inner = a_inner_ring/a_outer_ring; 
  double sigma = 0.0;
  vector<double> torus = get_torus(N, seed, pivot, index, m_ratio, a_inner, sigma);
  
  // Rescale to solar system units
  Cr = a_outer_ring;
  Cv = sqrt(1.0/Cr);
  for(int i=0; i<torus.size()/7; i++) {
    torus[i*7+1] *= Cr;
    torus[i*7+2] *= Cr;
    torus[i*7+3] *= Cr;
    torus[i*7+4] *= Cv;
    torus[i*7+5] *= Cv;
    torus[i*7+6] *= Cv;
  }
  
  // Sun is slightly offset from origin, correct for this
  for(int i=0; i<torus.size()/7; i++) {
    torus[i*7+1] += ss[0*7+1];
    torus[i*7+2] += ss[0*7+2];
    torus[i*7+3] += ss[0*7+3];
    torus[i*7+4] += ss[0*7+4];
    torus[i*7+5] += ss[0*7+5];
    torus[i*7+6] += ss[0*7+6];
  }  

  // Fuse solar system with torus
  vector<double> data = ss;
  for(int i=0; i<torus.size(); i++) {
    data.push_back(torus[i]);
  }  
  
  centralize(data);
  return data;
}
vector<double> Initializer::get_sun_torus(int N, int seed, int pivot, int index) {
  vector<double> fss = get_full_solar_system(N, seed, pivot, index);
  vector<double> data;
  for(int i=0; i<1; i++) {
    for(int j=0; j<7; j++) {
      data.push_back(fss[i*7+j]);
    }
  }
  for(int i=10; i<fss.size()/7; i++) {
    for(int j=0; j<7; j++) {
      data.push_back(fss[i*7+j]);
    }
  }
  centralize(data);
  return data;
}
vector<double> Initializer::get_sun_jupiter_torus(int N, int seed, int pivot, int index) {
  vector<double> fss = get_full_solar_system(N, seed, pivot, index);
  vector<double> data;
  for(int i=0; i<1; i++) {
    for(int j=0; j<7; j++) {
      data.push_back(fss[i*7+j]);
    }
  }
  for(int i=5; i<6; i++) {
    for(int j=0; j<7; j++) {
      data.push_back(fss[i*7+j]);
    }
  }
  for(int i=10; i<fss.size()/7; i++) {
    for(int j=0; j<7; j++) {
      data.push_back(fss[i*7+j]);
    }
  }
  centralize(data);
  return data;
}
vector<double> Initializer::get_sun_mars_jupiter_torus(int N, int seed, int pivot, int index) {
  vector<double> fss = get_full_solar_system(N, seed, pivot, index);
  vector<double> data;
  for(int i=0; i<1; i++) {
    for(int j=0; j<7; j++) {
      data.push_back(fss[i*7+j]);
    }
  }
  for(int i=4; i<6; i++) {
    for(int j=0; j<7; j++) {
      data.push_back(fss[i*7+j]);
    }
  }
  for(int i=10; i<fss.size()/7; i++) {
    for(int j=0; j<7; j++) {
      data.push_back(fss[i*7+j]);
    }
  }
  centralize(data);
  return data;
}
vector<double> Initializer::get_sun_mars_jovian_torus(int N, int seed, int pivot, int index) {
  vector<double> fss = get_full_solar_system(N, seed, pivot, index);
  vector<double> data;
  for(int i=0; i<1; i++) {
    for(int j=0; j<7; j++) {
      data.push_back(fss[i*7+j]);
    }
  }
  for(int i=4; i<10; i++) {
    for(int j=0; j<7; j++) {
      data.push_back(fss[i*7+j]);
    }
  }
  for(int i=10; i<fss.size()/7; i++) {
    for(int j=0; j<7; j++) {
      data.push_back(fss[i*7+j]);
    }
  }
  centralize(data);
  return data;
}

vector<double> Initializer::get_solar_system_halley(int N, int seed, int pivot, int index, int h_coor, double h_error, int j_coor, double j_error) {
  vector<double> data;

  // Sun
  data.push_back(1);
  data.push_back(2.460401724204089E-03);
  data.push_back(-1.296457510903158E-03);
  data.push_back(-1.280557668401947E-04);
  data.push_back(4.587732003425030E-06);
  data.push_back(4.654909129447831E-06);
  data.push_back(-1.110955702891871E-07);
       
  // Mercury
  data.push_back(1.6601375118291464e-7);
  data.push_back(3.296437666226646E-01);
  data.push_back(-2.305331200568514E-01);
  data.push_back(-4.887672789792401E-02);
  data.push_back(1.061082362225669E-02);
  data.push_back(2.434704693325687E-02);
  data.push_back(1.015757841274280E-03);
    
  // Venus
  data.push_back(2.44783857411814e-6);
  data.push_back(-7.154027730218678E-01);
  data.push_back(3.337539622810829E-02);
  data.push_back(4.177443581670932E-02);
  data.push_back(-1.086597212755203E-03);
  data.push_back(-2.028662925468785E-02);
  data.push_back(-2.152398820568715E-04);
     
  // Earth
  data.push_back(3.0404326668433355e-6);
  data.push_back(9.861920435383068E-01);
  data.push_back(1.809021561607287E-01);
  data.push_back(-1.365295985966051E-04);
  data.push_back(-3.408043124016021E-03);
  data.push_back(1.685664177398394E-02);
  data.push_back(-6.529742147600525E-07);
      
  // Mars
  data.push_back(3.227150370113422e-7);
  data.push_back(5.484577138401596E-01);
  data.push_back(-1.305198171408829E+00);
  data.push_back(-4.084956238141536E-02);
  data.push_back(1.344288466582773E-02);
  data.push_back(6.612217615823506E-03);
  data.push_back(-1.915033347255382E-04);
     
  // Jupiter
  data.push_back(0.0009545940905009727);
  data.push_back(-3.211787993621413E+00);
  data.push_back(4.201506346143431E+00);
  data.push_back(5.434137703482850E-02);
  data.push_back(-6.085188929003960E-03);
  data.push_back(-4.227184133398781E-03);
  data.push_back(1.537379058870405E-04);
  if(j_coor == 0) data[data.size()-7] += j_error;
  else if(j_coor == 1) data[data.size()-6] += j_error;
  else if(j_coor == 2) data[data.size()-5] += j_error;
  else if(j_coor == 3) data[data.size()-4] += j_error;
  else if(j_coor == 4) data[data.size()-3] += j_error;
  else if(j_coor == 5) data[data.size()-2] += j_error;
  else data[data.size()-1] += j_error;

  // Saturn
  data.push_back(0.0002858150131819827);
  data.push_back(-5.788398185748002E+00);
  data.push_back(-8.069056761371796E+00);
  data.push_back(3.706693349308769E-01);
  data.push_back(4.228964967570854E-03);
  data.push_back(-3.266678393918157E-03);
  data.push_back(-1.117677552850386E-04);
      
  // Uranus
  data.push_back(4.3658047415668107e-5);
  data.push_back(1.939815666659398E+01);
  data.push_back(4.928293091544985E+00);
  data.push_back(-2.330057456118213E-01);
  data.push_back(-9.972160175613773E-04);
  data.push_back(3.628663423752756E-03);
  data.push_back(2.631337365376518E-05);
      
  // Neptune
  data.push_back(5.1503137142531555e-5);
  data.push_back(2.741993616461276E+01);
  data.push_back(-1.210153890018418E+01);
  data.push_back(-3.827123750638945E-01);
  data.push_back(1.246157252751333E-03);
  data.push_back(2.890234553618175E-03);
  data.push_back(-8.815677984951996E-05);
     
  // Halley
  data.push_back(1.1063355e-16);
  data.push_back(-2.046011952809097E+01);
  data.push_back(2.513980121805306E+01);
  data.push_back(-9.771054962044406E+00);
  data.push_back(-6.631852646093806E-05);
  data.push_back(9.404758449357039E-04);
  data.push_back(-1.740327105577856E-04);
  if(h_coor == 0) data[data.size()-7] += h_error;
  else if (h_coor == 1) data[data.size()-6] += h_error;
  else if (h_coor == 2) data[data.size()-5] += h_error;
  else if (h_coor == 3) data[data.size()-4] += h_error;
  else if (h_coor == 4) data[data.size()-3] += h_error;
  else if (h_coor == 5) data[data.size()-2] += h_error;
  else data[data.size()-1] += h_error;

  data.push_back(7.3442323846354385e-9);
  data.push_back(7.122666062274392E+00);
  data.push_back(-3.192497611912020E+01);
  data.push_back(1.355874654192770E+00);
  data.push_back(3.125701787419049E-03);
  data.push_back(4.525786898345775E-05);
  data.push_back(-9.089817978909587E-04);
     
  data.push_back(4.76217602359e-10);
  data.push_back(-1.217169687718978E+00);
  data.push_back(-2.465636063956427E+00);
  data.push_back(1.473101680697350E-01);
  data.push_back(8.755087261370658E-03);
  data.push_back(-5.311151166961806E-03);
  data.push_back(-1.780476190521632E-03);
      
  data.push_back(2.01233807e-9);
  data.push_back(-4.196164608675372E+01);
  data.push_back(-1.599680114012784E+01);
  data.push_back(2.363517814256419E+01);
  data.push_back(1.010438028860980E-03);
  data.push_back(-1.942641685926145E-03);
  data.push_back(9.144806903013538E-05);
    
  data.push_back(2.01233807e-9);
  data.push_back(-4.599774871079143E+01);
  data.push_back(-1.576916380488405E-01);
  data.push_back(2.505135572118250E+01);
  data.push_back(-1.914643732584936E-04);
  data.push_back(-2.179803802609839E-03);
  data.push_back(-1.170721173488856E-04);
      
  data.push_back(8.40977102e-9);
  data.push_back(8.690485976580642E+01);
  data.push_back(3.582804997369133E+01);
  data.push_back(-2.129632616019580E+01);
  data.push_back(-3.527266000286885E-04);
  data.push_back(9.095072762867549E-04);
  data.push_back(9.106401746892221E-04);
    
  data.push_back(3.2234593e-10);
  data.push_back(-4.130600484504006E+01);
  data.push_back(1.883077591369915E+01);
  data.push_back(-1.566913996316666E+01);
  data.push_back(-8.552107026175210E-04);
  data.push_back(-1.993393227582727E-03);
  data.push_back(-3.023133808309448E-04);
      
  data.push_back(7.0403166e-10);
  data.push_back(-2.994444197751981E+00);
  data.push_back(-4.250770922683300E+01);
  data.push_back(5.829945301953601E+00);
  data.push_back(2.632453196488463E-03);
  data.push_back(-7.965615717057239E-05);
  data.push_back(6.830542475050562E-05);
     
  data.push_back(1.8606551e-10);
  data.push_back(-1.933562146042558E+01);
  data.push_back(3.897575135840104E+01);
  data.push_back(4.397374628559474E+00);
  data.push_back(-2.241720385638895E-03);
  data.push_back(-1.047345295579430E-03);
  data.push_back(7.283652106891438E-04);
      
  data.push_back(4.0878593e-10);
  data.push_back(-6.125382570365321E+00);
  data.push_back(-3.980623973718269E+01);
  data.push_back(-2.549135519485892E+00);
  data.push_back(2.532166793635817E-03);
  data.push_back(3.232772608180776E-04);
  data.push_back(-8.166464017923135E-04);
    
  data.push_back(5.9007694e-10);
  data.push_back(-3.726568434569603E+01);
  data.push_back(2.492283516782008E+01);
  data.push_back(-9.772286210217320E+00);
  data.push_back(-8.972817887316392E-04);
  data.push_back(-2.266321153745022E-03);
  data.push_back(-8.348299611992205E-04);

  double Cv = 365.242 / (2.*acos(-1.));
  for(int i=0; i<N; i++) {
    for(int j=4; j<7; j++) {
      data[i*7+j] *= Cv;
    }
  }

  return data;
}

vector<double> Initializer::get_solar_system_jpl_variable_N(bool Mercury, bool Venus, bool Earth, bool Mars, bool Jupiter, bool Saturn, bool Uranus, bool Neptune, bool Pluto, int index, int coor, double perturbation) {
  vector<double> data;

  data.push_back(1);
  data.push_back(2.072946918590417E-03);
  data.push_back(-1.643061287382110E-03);
  data.push_back(-1.185823088540438E-04);
  data.push_back(5.059930816518583E-06);
  data.push_back(3.989470642047999E-06);
  data.push_back(-1.243838264183300E-07);

  if(Mercury) {      
    data.push_back(1.6601375118291464e-7);
    data.push_back(3.574733791200970E-01);
    data.push_back(-1.171187317227507E-02);
    data.push_back(-3.354856363159710E-02);
    data.push_back(-4.633283577618537E-03);
    data.push_back(2.938619087935777E-02);
    data.push_back(2.826185769428105E-03);
  }
  if(Venus) {      	   	       
    data.push_back(2.44783857411814e-6);
    data.push_back(4.876790422110325E-01);
    data.push_back(5.332660900104316E-01);
    data.push_back(-2.081177373810901E-02);
    data.push_back(-1.503296302925791E-02);
    data.push_back(1.351327482426259E-02);
    data.push_back(1.052862263953481E-03);
  }
  if(Earth) {       	  	         
    data.push_back(3.0404326668433355e-6);
    data.push_back(4.026754002834322E-01);
    data.push_back(-9.357700005133348E-01);
    data.push_back(-8.932490601085987E-05);
    data.push_back(1.553740564985712E-02);
    data.push_back(6.720378960900881E-03);
    data.push_back(-3.796916120995478E-07);
  }	  	       
  if(Mars) {      
    data.push_back(3.227150370113422e-7);
    data.push_back(-5.844200241438797E-01);
    data.push_back(-1.390641490399950E+00);
    data.push_back(-1.482626102558087E-02);
    data.push_back(1.342616848375762E-02);
    data.push_back(-4.237723031036153E-03);
    data.push_back(-4.184228274540421E-04);
  }
  if(Jupiter) {      
    data.push_back(0.0009545940905009727);
    data.push_back(-2.705363190538412E+00);
    data.push_back(4.511969711234348E+00);
    data.push_back(4.171926801427295E-02);
    data.push_back(-6.562761960592283E-03);
    data.push_back(-3.524082083761892E-03);
    data.push_back(1.615059047295873E-04);
  }
  if(Saturn) {      	   	       
    data.push_back(0.0002858150131819827);
    data.push_back(-6.120971157013838E+00);
    data.push_back(-7.799968424277239E+00);
    data.push_back(3.792260890576647E-01);
    data.push_back(4.084918553333202E-03);
    data.push_back(-3.458702472764618E-03);
    data.push_back(-1.026661638527525E-04);
  }
  if(Uranus) {        	   	        
    data.push_back(4.3658047415668107e-5);
    data.push_back(1.947563780483501E+01);
    data.push_back(4.637428187478366E+00);
    data.push_back(-2.350901336659057E-01);
    data.push_back(-9.397988346434892E-04);
    data.push_back(3.642810279796556E-03);
    data.push_back(2.574368503661651E-05);
  }
  if(Neptune) {      	  	       
    data.push_back(5.1503137142531555e-5);
    data.push_back(2.731924333900583E+01);
    data.push_back(-1.233234986862218E+01);
    data.push_back(-3.756379750691105E-01);
    data.push_back(1.270955946848631E-03);
    data.push_back(2.880167515810431E-03);
    data.push_back(-8.840273274466099E-05);
  }
  if(Pluto) {          	   	   
    data.push_back(7.3442323846354385e-9);
    data.push_back(6.872419409625540E+00);
    data.push_back(-3.192773277605658E+01);
    data.push_back(1.428555846904559E+00);
    data.push_back(3.130439755573468E-03);
    data.push_back(2.364247270061568E-05);
    data.push_back(-9.080391301223528E-04);
  }

  //double Cv = 58.12435834603945838;
  double Cv = 365.242 / (2.*acos(-1.));

  int N = data.size()/7;
  for(int i=0; i<N; i++) {
    for(int j=4; j<7; j++) {
      data[i*7+j] *= Cv;
    }
  }

  centralize(data);

  data[index*7+coor] += perturbation;

  return data;
}

// Exoplanets
bool Initializer::get_exo_64443(vector<double> &data, string file) {
    bool loaded = get_from_file(data, file);
    if(loaded == true) {
        double Cv = 365.25 / (2*acos(-1.)); //"2"*acos("-1"); // x 2*pi*AU/yr = C*y AU/d, C = 365.25  
        rescale_velocity(data, Cv);
    }
    return loaded;
}
bool Initializer::get_exo_64443_perturbed(vector<double> &data, string file, int particle, int coor, double delta) {
    bool loaded = get_exo_64443(data, file);
    if(loaded == true) {
        data[particle*7+coor] += delta;
    }
    return loaded;
}

bool Initializer::get_exo_64443_unstable(vector<double> &data, string file) {
    bool loaded = get_from_file(data, file);
    if(loaded == true) {
        double Cv = 365.25 / (2*acos(-1.)); //"2"*acos("-1"); // x 2*pi*AU/yr = C*y AU/d, C = 365.25  
        rescale_velocity(data, Cv);
    }
    return loaded;
}
bool Initializer::get_exo_64443_unstable_perturbed(vector<double> &data, string file, int particle, int coor, double delta) {
    bool loaded = get_exo_64443(data, file);
    if(loaded == true) {
        data[particle*7+coor] += delta;
    }
    return loaded;
}

// Spherical clusters
vector<double> Initializer::get_plummer(int N, int seed, int pivot, int index) {
  vector<double> data(N*7);

  set_random_generator(seed, pivot);

  for(int i=0; i<=index; i++) {
    vector<double> m(N), x(N), y(N), z(N), vx(N), vy(N), vz(N);
    double pi = acos(-1.0);

    // Set masses
    for(int i=0; i<N; i++) {
      m[i] = 1.0/N;
    } 

    // Set positions
    for(int i=0; i<N; i++) {
      double r = 1.0 / sqrt( pow(random.uniform(0.0, 1.0), -2.0/3.0 ) - 1.0);
      double theta = acos( random.uniform(0.0, 1.0)*2.0 - 1.0);
      double phi = random.uniform(0.0, 1.0) * 2.0*pi;
      x[i] = r*sin(theta)*cos(phi);
      y[i] = r*sin(theta)*sin(phi);
      z[i] = r*cos(theta);
    } 

    // Set velocities
    for(int i=0; i<N; i++) {    
      double xx = 0.0;
      double yy = 0.1;
      while( yy > xx*xx*pow( (1.0-xx*xx), 3.5 ) ) {
        xx = random.uniform(0.0, 1.0);
        yy = random.uniform(0.0, 1.0) / 10.0;
      }
      double r2 = x[i]*x[i] + y[i]*y[i] + z[i]*z[i];
      double v = xx * sqrt(2.0) * pow( ( 1.0 + r2), -0.25 );

      double theta = acos( random.uniform(0.0, 1.0) * 2.0 - 1.0 );
      double phi = random.uniform(0.0, 1.0) * 2.0*pi;

      vx[i] = v*sin(theta)*cos(phi);
      vy[i] = v*sin(theta)*sin(phi);
      vz[i] = v*cos(theta);
    }

    for(int i=0; i<N; i++) {
      data[i*7] = m[i];
      data[i*7+1] = x[i];
      data[i*7+2] = y[i];
      data[i*7+3] = z[i];
      data[i*7+4] = vx[i];
      data[i*7+5] = vy[i];
      data[i*7+6] = vz[i];
    }
  } 

  centralize(data);
  normalize_to_nbody_units(data);
  return data;      
}
vector<double> Initializer::get_cold_plummer(int N, int seed, int pivot, int index) {
  vector<double> data = get_plummer(N, seed, pivot, index);
  make_cold(data);
  rescale_position(data, 2.0);
  return data;
}
vector<double> Initializer::get_democratic_plummer(int N, int seed, int pivot, int index) {
  double tolerance = 1.0/N; 
  bool accept = false;
  vector<double> data = get_plummer(N, seed, pivot, index);
  while(!accept) {
    vector<double> data = get_plummer(N, seed, pivot, index);
    double drmin = 1e100;
    int N = data.size()/7;
    for(int i=0; i<N-1; i++) {
      for(int j=i+1; j<N; j++) {
        double dx = data[j*7+1]-data[i*7+1];
        double dy = data[j*7+2]-data[i*7+2];
        double dz = data[j*7+3]-data[i*7+3];
        double dr2 = dx*dx + dy*dy + dz*dz;
        if(dr2<drmin) drmin = dr2;
      }
    }
    drmin = sqrt(drmin);
    if(drmin > tolerance) return data;
    seed++;
  }
  return data;
}
vector<double> Initializer::get_democratic_cold_plummer(int N, int seed, int pivot, int index) {
  vector<double> data = get_democratic_plummer(N, seed, pivot, index);
  make_cold(data);
  rescale_position(data, 2.0);
  return data;
}

vector<double> Initializer::get_cold_sphere(int N, int seed, int pivot, int index) {
  vector<double> data(N*7);

  set_random_generator(seed, pivot);

  for(int i=0; i<=index; i++) {
    vector<double> m(N), x(N), y(N), z(N), vx(N), vy(N), vz(N);
    double pi = acos(-1.0);

    // Set masses
    for(int i=0; i<N; i++) {
      m[i] = 1.0/N;
    } 

    // Set positions
    double pmin = 0;
    double pmax = 3;
    for(int i=0; i<N; i++) {
      double r = 0;
      bool accept = false;
      while(!accept) {
        double r_trial = random.uniform(0.0, 1.0);
        double p_trial = 3*r_trial*r_trial;
        double p = random.uniform(pmin, pmax);
        if(p < p_trial) {
          r = r_trial;
          accept = true;
        }
      }
      double theta = acos( random.uniform(0.0, 1.0)*2.0 - 1.0);
      double phi = random.uniform(0.0, 1.0) * 2.0*pi;
      x[i] = r*sin(theta)*cos(phi);
      y[i] = r*sin(theta)*sin(phi);
      z[i] = r*cos(theta);
    } 

    // Set velocities
    for(int i=0; i<N; i++) {    
      vx[i] = 0.0;
      vy[i] = 0.0;
      vz[i] = 0.0;
    }

    for(int i=0; i<N; i++) {
      data[i*7] = m[i];
      data[i*7+1] = x[i];
      data[i*7+2] = y[i];
      data[i*7+3] = z[i];
      data[i*7+4] = vx[i];
      data[i*7+5] = vy[i];
      data[i*7+6] = vz[i];
    }
  } 

  centralize(data);
  normalize_to_nbody_units(data);
  rescale_position(data, 2.0);

  return data;  
}
vector<double> Initializer::get_virial_sphere(int N, int seed, int pivot, int index, double Q) {
  vector<double> data = get_cold_sphere(N, seed, pivot, index);

  // Give random velocities
  double pi = acos(-1.0);
  for(int i=0; i<N; i++) {
    double v     = random.gaussian();
    double theta = acos( random.uniform(0.0, 1.0)*2.0 - 1.0);
    double phi   = random.uniform(0.0, 1.0) * 2.0*pi;

    data[i*7+4] += v*sin(theta)*cos(phi);
    data[i*7+5] += v*sin(theta)*sin(phi);
    data[i*7+6] += v*cos(theta);
  }

  // Normalize the energies to Q
  centralize(data); 
  normalize_to_fraction_of_virial(data, Q);  

  return data;
}

vector<double> Initializer::get_plummer_perturbed(int N, int seed, int pivot, int index, double magnitude) {
  vector<double> data = get_plummer(N, seed, pivot, index);
  add_random_perturbation(data, magnitude);
  return data;
}

// Dominant mass
vector<double> Initializer::get_bh_plummer(int N, int seed, int pivot, int index, double m_ratio) {
  vector<double> data_stars = get_plummer(N-1, seed, pivot, index);

  vector<double> data;
  data.push_back(1.0/(N-1));
  data.push_back(0);
  data.push_back(0);
  data.push_back(0);
  data.push_back(0);
  data.push_back(0);
  data.push_back(0);

  for(int i=0; i<data_stars.size(); i++) {
    data.push_back(data_stars[i]);
  }

  normalize_to_nbody_units(data);

  if(m_ratio < 1) m_ratio = 1.0/m_ratio;
  data[0] = m_ratio/N;

  double Mtot = 1.0 - 1.0/N + m_ratio/N;
  double Cv = sqrt(Mtot);
  for(int i=1; i<N; i++) {
    data[i*7+4] *= Cv;
    data[i*7+5] *= Cv;    
    data[i*7+6] *= Cv;        
  } 

  normalize_to_boekholt_units(data);

  return data; 
}
vector<double> Initializer::get_bh_solar_systems(int Nstar, int Nplanet, double mass_ratio1, double Rsolar, int seed, int pivot, int index) {
  vector<double> data = get_bh_plummer(Nstar, seed, pivot, index, mass_ratio1);

  vector<double> fdata;
  for(int i=0; i<7; i++) fdata.push_back(data[i]);

  set_random_generator(seed, pivot);
  double pi = acos(-1.0);

  for(int i=1; i<Nstar; i++) {
    vector<double> tdata = get_solar_system_ito();

    vector<double> ssdata;
    for(int j=0; j<=Nplanet; j++) {
      for(int k=0; k<7; k++) {
        ssdata.push_back(tdata[j*7+k]);
      }
    }    

    centralize(ssdata);

    double x_angle = random.uniform(0.0, 2.0*pi);
    double y_angle = random.uniform(0.0, 2.0*pi);
    double z_angle = random.uniform(0.0, 2.0*pi);
    rotate_x(ssdata, x_angle);
    rotate_y(ssdata, y_angle);  
    rotate_z(ssdata, z_angle);    

    normalize_to_boekholt_units(ssdata);    

    double Cm = data[i*7];
    double Cr = Rsolar;
    rescale_mass_position(ssdata, Cm, Cr);

    for(int j=0; j<ssdata.size()/7; j++) {
      ssdata[j*7+1] += data[i*7+1];
      ssdata[j*7+2] += data[i*7+2];
      ssdata[j*7+3] += data[i*7+3];
      ssdata[j*7+4] += data[i*7+4];
      ssdata[j*7+5] += data[i*7+5];
      ssdata[j*7+6] += data[i*7+6];
    }

    for(int j=0; j<ssdata.size(); j++) {
      fdata.push_back(ssdata[j]);
    }
  }

  return fdata;
}
vector<double> Initializer::get_plummer_solar_systems(int Nstar, int Nplanet, double Rsolar, int seed, int pivot, int index) {
  vector<double> data = get_plummer(Nstar, seed, pivot, index);

  set_random_generator(seed, pivot);
  double pi = acos(-1.0);

  vector<double> fdata;

  for(int i=0; i<Nstar; i++) {
    vector<double> tdata = get_solar_system_ito();

    vector<double> ssdata;
    for(int j=0; j<=Nplanet; j++) {
      for(int k=0; k<7; k++) {
        ssdata.push_back(tdata[j*7+k]);
      }
    } 

    centralize(ssdata);

    double x_angle = random.uniform(0.0, 2.0*pi);
    double y_angle = random.uniform(0.0, 2.0*pi);
    double z_angle = random.uniform(0.0, 2.0*pi);
    rotate_x(ssdata, x_angle);
    rotate_y(ssdata, y_angle);  
    rotate_z(ssdata, z_angle); 

    int numSS = ssdata.size()/7;
    double Router = sqrt(ssdata[(numSS-1)*7+1]*ssdata[(numSS-1)*7+1] + ssdata[(numSS-1)*7+2]*ssdata[(numSS-1)*7+2] + ssdata[(numSS-1)*7+3]*ssdata[(numSS-1)*7+3]);
    double Cr = 1.0 / Router;
    double Cv = sqrt(1.0/Cr);
    for(int j=0; j<numSS; j++) {
      ssdata[j*7+1] *= Cr;
      ssdata[j*7+2] *= Cr;
      ssdata[j*7+3] *= Cr;
      ssdata[j*7+4] *= Cv;
      ssdata[j*7+5] *= Cv;
      ssdata[j*7+6] *= Cv;
    }

    double Cm = data[i*7];
    Cr = Rsolar;
    rescale_mass_position(ssdata, Cm, Cr);

    for(int j=0; j<ssdata.size()/7; j++) {
      ssdata[j*7+1] += data[i*7+1];
      ssdata[j*7+2] += data[i*7+2];
      ssdata[j*7+3] += data[i*7+3];
      ssdata[j*7+4] += data[i*7+4];
      ssdata[j*7+5] += data[i*7+5];
      ssdata[j*7+6] += data[i*7+6];
    }

    for(int j=0; j<ssdata.size(); j++) {
      fdata.push_back(ssdata[j]);
    }    
  }

  return fdata;
}

// Disk
vector<double> Initializer::get_ring(int N, int seed, int pivot, int index, double m_ratio, double a_inner) {
  vector<double> data(N*7);

  set_random_generator(seed, pivot);
  for(int i=0; i<=index; i++) {
    vector<double> m(N), x(N), y(N), z(N), vx(N), vy(N), vz(N);
    double pi = acos(-1.0);

    // Set masses
    for(int i=0; i<N; i++) {
      m[i] = m_ratio/N;
    } 

    // Set positions and velocities
    for(int i=0; i<N; i++) {
      double r = a_inner + random.uniform(0.0, 1.0-a_inner);
      double phi = random.uniform(0.0, 1.0) * 2.0*pi;
      x[i] = r*cos(phi);
      y[i] = r*sin(phi);
      z[i] = 0.0;

      double vc = sqrt(1.0/r);
      double v_phi = phi + pi/2.0;
      vx[i] = vc*cos(v_phi);
      vy[i] = vc*sin(v_phi);
      vz[i] = 0.0;
    } 

    for(int i=0; i<N; i++) {
      data[i*7] = m[i];
      data[i*7+1] = x[i];
      data[i*7+2] = y[i];
      data[i*7+3] = z[i];
      data[i*7+4] = vx[i];
      data[i*7+5] = vy[i];
      data[i*7+6] = vz[i];
    }
  } 

  return data; 
}
vector<double> Initializer::get_disk(int N, int seed, int pivot, int index, double m_ratio) {
  vector<double> data = get_ring(N, seed, pivot, index, m_ratio, 0.0);
  return data;    
}  

// Torus
vector<double> Initializer::get_torus(int N, int seed, int pivot, int index, double m_ratio, double a_inner,  double sigma) {
  set_random_generator(seed, pivot);

  vector<double> data = get_ring(N, seed, pivot, index, m_ratio, a_inner);

  for(int i=0; i<N; i++) {
    double dz = random.uniform(0.0, 1.0) * 2.0*sigma - sigma;
    data[i*7+3] += dz;
  }
  return data;
}

  





