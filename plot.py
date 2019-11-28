import numpy as np
from matplotlib import pylab as pl
from mpl_toolkits.mplot3d import Axes3D
import matplotlib.pyplot as plt
from matplotlib import cm

nx=101
nt=300
dat = np.loadtxt("archivo.dat")
malla = np.reshape(dat, (nx, nt))

dx=10/101

X_=[]
Y_0=[]
Y_F=[]

#Grafica 

for ix in range(nx):
    X_.append(dx*ix)
    Y_0.append(malla[ix][0])
    Y_F.append(malla[ix][nt-1])

plt.plot(X_,Y_0)
plt.plot(X_,Y_F)
plt.xlabel("X(metros)")
plt.ylabel("Desplazamiento(metros)")

plt.gca().legend(('Conf inicial','Config final'))
plt.savefig("plot_simple.png")
