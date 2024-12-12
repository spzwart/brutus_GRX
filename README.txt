- Arbitrary-precision libraries:

  gmp		: https://gmplib.org/
  mpfr		: http://www.mpfr.org/
  mpfr c++	: http://www.holoborodko.com/pavel/mpfr/

- Build the code

  1) Adjust the path to mpreal.h in makefile
  2) Type make

- Run the code:

  1) put the initial condition in a text file in the following format:

time0 N tcpu0
m1 x1 y1 z1 vx1 vy1 vz1
m2 x2 y2 z2 vx2 vy2 vz2
...

See example in solar_system_ito.ic

  2) in terminal run: ./main.exe file_out t_begin t_end dt eta e Lw nmax N file file_in 

file_out = output file for snapshots
t_begin  = begin time
t_end    = end time
dt       = snapshot time interval
eta      = timestep parameter
e        = bulirsch-stoer tolerance parameter (1e-6, 1e-8, 1e-10, ...)
Lw       = number of digits                   (  56,   64,    72, ...)
nmax     = maximum number of Bulirsch-Stoer iterations
N        = number of objects in the initial condition file
file     = tell Brutus we are reading the initial condition from a file
file_in  = text file holding the initial condition

Example: ./main.exe outfile 0 100 1.0 0.10 1e-6 56 64 10 file solar_system_ito.ic

This produces outfile.diag with all the snapshots, and outfile.log with some summarizing log data.

Enter speed of light value in c.par file

Enter desired PN terms in PN.order. Each 0 or 1 represents a PN term:
1PN-pair 1PN-cross 2PN 2.5PN 3PN 3.5PN

Example: if one wishes only 1PN pair and cross, the PN.order input should be:
1 1 0 0 0 0

Example: only radiative 2.5 and 3.5 PN terms:
0 0 0 1 0 1

Example: a binary (so no 1PN cross) with only conservative terms 1, 2 and 3 PN:
1 0 1 0 1 0

- Note:

  Feel free to adjust the code to suit your own input/output.

 



