# FRACT-OL (42 project)

### The goal was to generate some fractal's set, using the school's graphic library



## HOW TO INSTALL :

First, copy the repository wherever you want, using git clone
```
git clone https://github.com/Ordajeannin/fract-ol
```

Second, run 
```make```


## HOW TO LAUNCH :

Once you ran ```make```, a new file should have been created, named ```fractol```.
You are now able to use it! but not alone, you will have to add some params.
like this : ```./fractol <set> <options>```

Params :
-  <set> is the fractal's name you want to generate. 
	-> mandelbrot
	-> julia
	-> burningship
- <options> is only for julia. 
	Since it need coordonates on the complex plan to initialize, you are able
	to give yours. Real part first, Imaginary part then, both between -2.0/+2.0

You can modify the value ```IT_MAX``` in the  ```makefile``` . More iterations = more details.
Here is an example :
```./fractol julia -0.8696 0.26```   it_max = 60
![julia](/screenshots/julia_option.png)


```./fractol mandelbrot```       it_max = 100 000          zoom = 10^6
![mandelbrot](/screenshots/mandelbrot_it10%5E5_zoom10%5E6.png)


color palette can change a lot the view you can have, see :
```./fractol mandelbrot          it_max = 100 000          zoom = 5 * 10^11

![mandelbrot mc](/screenshots/mandelbrot_10%5E5_5*10%5E11mc.png)
![mandelbrot uc](/screenshots/mandelbrot10%5E5_5*10%5E11uc.png)
