#!/usr/bin/env python
"""
@author: phdenzel

Julia set generator
"""
# Imports
import numpy as np
import matplotlib.pyplot as plt
import matplotlib.cm as cm

# initial values
c = complex(-0.1, 0.65)  # Re,Im in [-1.5, 1.5]
z_limit = 10
iterations = 1000
# image dimensions
w, h = 2000, 2000
xmin, xmax = -1.5, 1.5
ymin, ymax = -1.5, 1.5

# calculate map
julia = np.zeros((h, w))
for xi in range(w):
    for yi in range(h):
        z = complex(xi/w*(xmax-xmin)+xmin,
                    yi/h*(ymax-ymin)+ymin)
        i = 0
        while abs(z) <= z_limit and i < iterations:
            z = z*z + c
            i += 1
        ratio = i/iterations
        # shade = 1-np.sqrt(ratio)
        julia[yi, xi] = ratio

clr = cm.magma
fig, ax = plt.subplots()
ax.imshow(julia, interpolation='lanczos', cmap=clr)
plt.axis('off')
plt.imsave('julia.jpg', julia, cmap=clr)
plt.show()
