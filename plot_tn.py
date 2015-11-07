# -*- coding: utf-8 -*-
"""
Created on Sat Nov  7 11:01:04 2015

@author: rishiraj
"""
#%%
import matplotlib.pyplot as plt;
import numpy as np;
n = range(1,100);

plt.plot(n, np.log(np.log(n)));
plt.xticks(n)
plt.show();