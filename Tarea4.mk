PuntoNemo.pdf: Plots.py GeographicPoint.c
	
Plots.py : map_data.txt a.out
	./a.out 
	python Plots.py	

a.out : map_data.txt GeographicPoint.c 
	cc GeographicPoint.c -lm
	
