Fract-ol project developed for the 42School in a Ubuntu environment.

The purpose of this project is to create fractals, the program must offer the Julia set and the Mandelbrot set.

Fractals are formed by mathematical suites and are based on complex numbers (numbers with a real and imaginary part, like $z = a + bi$).

For example, the Julia and Mandelbrot sets are defined by the following suite:

$$
z_{n+1} = z_n^2 + c
$$

<img src="/img_readme/JMandelbrot_Set.png/">

In this project you will also be the opportunity for you to get familiar with the MiniLibX, the school graphical library: the MiniLibX!
This library was developed internally and includes basic necessary tools to open a window, create images and deal with keyboard and mouse events.

## Fractals available

```bash
./fractol Mandelbrot
./fractol Julia [real] [imaginary]
```

## Features available

> '+' or '-' to change Mandelbrot's color;

> zoom in and zoom out using the mouse wheel;

> The arrows change the position of the fractal.

<img src="/img_readme/Julia_Set_-0.70_0.35.png/">