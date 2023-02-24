import numpy as np
import matplotlib.pylab as plt
from scipy.fftpack import fft, fftfreq, ifft

t = np.linspace( 0, 10, 1000)
y = np.sin(2 * np.pi * t)

for i in range(1000):
	print(t[i],y[i])
