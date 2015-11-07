# -*- coding: utf-8 -*-
"""
Created on Sat Nov  7 10:04:49 2015

@author: rishiraj
"""
#%% to compare number of comparisons for finding min-max in an array
#%% usual 3*n/2 vs. Heapify procedures 2*log(n)
import matplotlib.pyplot as plt;
import numpy as np;
n = range(1,100);

plt.plot(n, 2*np.log(n));
plt.plot(n,[1.5*i for i in n] );
plt.show();
