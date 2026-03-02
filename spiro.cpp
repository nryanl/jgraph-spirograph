#include <assert.h>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

int gcd(int a, int b) {
  while (b != 0) {
    int t = b;
    b = a % b;
    a = t;
  }
  return a;
}

int lcm(int a, int b) { return a * b / gcd(a, b); }

int main(int argc, char **argv) {
  int R_teeth;        // Fixed ring number of teeth
  int r_teeth;        // Rolling wheel number of teeth
  double r;           // Rolling wheel radius
  double R;           // Radius fixed ring
  double d;           // Distance of pen hole from wheel center
  double start_angle; // Starting angle in degrees
  double cr, cg, cb;  // RGB color

  // Usage
  if (argc != 3) {
    fprintf(stderr, "Usage: spiro <ring_teeth> <ring_radius>\n");
    fprintf(stderr, "On stdin, one drawing per line:\n");
    fprintf(stderr, "  r g b wheel_teeth start_angle hole_distance\n");
    return 1;
  }

  R_teeth = atoi(argv[1]);
  R = atof(argv[2]);

  if (R_teeth <= 0 || R <= 0) {
    fprintf(stderr, "Error: ring teeth and radius must be positive.\n");
    return 1;
  }

  double radius_per_tooth = R / (double)R_teeth;

  // Emit jgraph header
  printf("newgraph\n");
  printf("xaxis min %.4f max %.4f size 5 nodraw\n", -R * 1.1, R * 1.1);
  printf("yaxis min %.4f max %.4f size 5 nodraw\n", -R * 1.1, R * 1.1);

  // Read drawings from stdin
  while (scanf("%lf %lf %lf %d %lf %lf", &cr, &cg, &cb, &r_teeth, &start_angle,
               &d) == 6) {

    assert(r_teeth > 0 && r_teeth < R_teeth);

    r = r_teeth * radius_per_tooth;

    double hole_dist = d * r;
    int L = lcm(R_teeth, r_teeth);
    double full_angle = 2.0 * M_PI * ((double)L / (double)R_teeth);

    // Ensure sufficient points for visual continuity
    int num_points = L * 100;
    if (num_points < 5000)
      num_points = 5000;
    if (num_points > 100000)
      num_points = 100000;

    double dt = full_angle / (double)num_points;
    double start_rad = start_angle * M_PI / 180.0;

    printf("newline ");
    printf("color %.4f %.4f %.4f ", cr, cg, cb);
    printf("marktype none linetype solid\n");
    printf("pts\n");

    for (int i = 0; i <= num_points; i++) {
      double t = (double)i * dt + start_rad;
      double x = (R - r) * cos(t) + hole_dist * cos((R - r) * t / r);
      double y = (R - r) * sin(t) - hole_dist * sin((R - r) * t / r);
      printf("  %.6f %.6f\n", x, y);
    }
  }

  return 0;
}
