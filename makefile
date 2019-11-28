plot.png: archivo.dat plot.py
	python plot.py

%.dat : a.out
	./a.out 

a.out: ejercicio32.cpp
	g++ ejercicio32.cpp
