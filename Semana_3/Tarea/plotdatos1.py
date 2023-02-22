import numpy as np
import matplotlib.pylab as plt


datos=np.genfromtxt("datos1.dat")

plt.figure()
plt.plot(datos[:,0],datos[:,1])
plt.savefig("plot1.pdf")
