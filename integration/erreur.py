import numpy as np
import matplotlib.pyplot as plt

# Lecture d'un fichier CSV ou texte séparé par des espaces
data = np.loadtxt("integration/mon_fichier.txt")

x    = data[:,0]        
Rec  = data[:,1] 
Trap = data[:,2]
Simp = data[:,3]

def error(x):
    int = np.cos(0) - np.cos(1)
    return np.abs(int-x)

plt.plot(x, error(Rec),  label="Erreur Rectangle")
plt.plot(x, error(Trap), label="Erreur Trapèze")
plt.plot(x, error(Simp), label="Erreur Simpson")
plt.xscale("log")
plt.yscale("log")
plt.xlabel("Nombre de subdivisions (log)")
plt.ylabel("Erreur")
plt.title("Comparaison des erreurs d'intégration numérique")
plt.legend()
plt.grid(True, which="both")  # grille adaptée à l'échelle log
plt.show()