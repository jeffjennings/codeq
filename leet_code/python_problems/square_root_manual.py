import numpy as np

def manual_sqrt(x, tol=1e-2, nsearch=100000):
  """Manual square root routine for positive input 'x'. 
  Determination of square root to within tolerance 'tol'."""
  
  search_space = np.linspace(0, x, nsearch)
  remainders = []

  for ii in search_space:
    remainders.append(x - ii * ii)
    if abs(remainders[-1]) < tol: 
      print(f"square root of {x} is {ii} within tolerance {tol}")
      return ii
  
  remainders = np.array(remainders)
  print("square root within tolerance not found. closest result "
        f"{search_space[np.argmin(abs(remainders))]} with remainder {min(abs(remainders))}")
