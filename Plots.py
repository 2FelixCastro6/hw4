import numpy as np
import matplotlib.pyplot as plt
import math as m

datos=np.loadtxt('map_data.txt', delimiter=" ", dtype=float)
datos1=np.loadtxt('temporal.txt', delimiter=" ", dtype=int)

#plt.imshow(datos)#, cmap='nipy_spectral')
#plt.savefig("PuntoNemo.pdf")


r=datos1[2]
x=datos1[1]
y=datos1[0]
if (x>744):
	x= x %744
elif(x<0.):
	x=744+x
if (y>500):
	x= x %500
elif(y<0.):
	y=500+y

t=np.linspace(0,8,500)
a=r*np.cos(t)+x
b=r*np.sin(t)+y

fig,ax=plt.subplots()
ax.add_artist(plt.imshow(datos))
plt.scatter(x,y, color= 'r')
plt.plot(a,b, color= 'r')
plt.savefig("PuntoNemo.pdf")
