#Python libraries for math and graphics
import numpy as np
import mpmath as mp
import math as m
import random as r
import matplotlib.pyplot as plt
from numpy import linalg as LA
import sympy as sym
import math
import sympy
import sys      #for path to external scripts
sys.path.insert(0,'/home/hari/hari/optimization/CoordGeo')

#local imports
from line.funcs import *
from triangle.funcs import *
from conics.funcs import circ_gen
from sympy import Poly,roots,simplify
from sympy import*
#if using termux
import subprocess
import shlex
#end if


#Defining f(x)
def f(x,m):
  return np.sqrt((((m**2*x-2+m)/(m**2))**2)+(((m*2*np.sqrt(x)-2)/m)**2)) 

m=1
label_str = "$f(x)$"
#For minima using gradient ascent
cur_x = 0.1
alpha = 0.001 
precision = 0.00000001 
previous_step_size = 1
max_iters = 10000 
iters = 0

#Defining derivative of f(x)
df = lambda x: (m*x-2/m+1+2*m-2/np.sqrt(x))/(np.sqrt((m*x-2/m+1)**2)+(2*m*np.sqrt(x)-2)**2)           

#Gradient descent calculation
while (previous_step_size > precision) & (iters < max_iters) :
    prev_x = cur_x             
    cur_x -= alpha * df(prev_x)   
    previous_step_size = abs(cur_x - prev_x)   
    iters+=1  

min_val = f(cur_x,m)
print("Minimum value of f(x) is ", min_val, "at","x =",cur_x)

#Plotting f(x)
x=np.linspace(0,40,100)
y=f(x,m)
plt.plot(x,y,label=label_str)
#Labelling points
plt.plot(cur_x,min_val,'o')
plt.text(cur_x,min_val,f'P({cur_x:.4f},{min_val:.4f})')

plt.xlabel("x-axis")
plt.ylabel("y-axis")
plt.grid()
plt.legend()
plt.savefig('/home/hari/hari/optimization/opt1.pdf')
plt.show()
