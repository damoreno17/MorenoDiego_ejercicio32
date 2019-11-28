#include <cmath>
#include <fstream>
#include <iostream>
using namespace std;

int main() {
  
/*defino los parametros */
  
  double rho = 0.01;
  double T= 40;
  double L =1.0;
  int m = 1;
  int Nx =  101;
  int NT = 300;
  double c = sqrt(T / rho);
  double cl = c;
  double r = c * c / (cl * cl);
  double k[Nx][3];
  double Ktot[Nx][NT];
  double pi = 3.14159;

  for (int i = 0; i < Nx; i++) {
    for (int j = 0; j < 3; j++) {
      
      k[i][j] = sin(2.0 * pi * i * 0.005);
      
    }

    for (int k = 0; k < NT; k++) {
      Ktot[i][k] = 0.0;
    }
    Ktot[i][0] = k[i][0];
  }

  for (int t = 1; t < NT; t++) {
    if (t == 1) {
      for (int ix = 1; ix < Nx - 1; ix++) {
        k[ix][1] = k[ix][0] + 0.5 * r * (k[ix + 1][0] + k[ix - 1][0] - 2.0 * k[ix][0]);
      }
    } else {
      for (int ix = 1; ix < Nx - 1; ix++) {
        k[ix][2] = 2.0 * k[ix][1] - k[ix][0] + r * (k[ix + 1][1] + k[ix - 1][1] - 2. * k[ix][1]);
      }
    }
    if ((t % 1 == 0) || (t == 1)){
      for (int i = 1; i < Nx; i++) {
        Ktot[i][m] = k[i][2];
      }
      cout << m << endl;
      m += 1;
    }
    for (int ix = 1; ix < Nx - 1; ix++) {
      k[ix][0] = k[ix][1];
      k[ix][1] = k[ix][2];
    }
  }

  ofstream datos("archivo.dat");
  
  for (int x = 0; x < Nx; x++) {
    for (int t = 0; t < m; t++) {
      datos << Ktot[x][t] << endl;
    }
  }

  return 0;
}
