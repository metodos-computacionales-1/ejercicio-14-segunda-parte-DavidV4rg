import numpy as np
import matplotlib.pylab as plt

data = np.genfromtxt("RungeKutta.dat")

time = data[:,0]
pos = data[:,1]
velo = data[:,2]

plt.figure(figsize=(10,8))
plt.plot(time, pos,label="$Posición$")
plt.grid()
plt.xlabel('$t(s)$')
plt.ylabel('$x(m)$')
plt.legend()
plt.savefig("RungePos")

plt.figure(figsize=(10,8))
plt.plot(time, velo,label="$Velocidad$")
plt.grid()
plt.xlabel('$t(s)$')
plt.ylabel('$v(m/s)$')
plt.legend()
plt.savefig("RungeVelo")

plt.figure(figsize=(10,8))
plt.plot(time, velo,label="$Velocidad$",c="r")
plt.plot(time, pos,label="$Posición$",c="g")
plt.grid()
plt.xlabel('$t(s)$')
plt.legend()
plt.savefig("Runge")