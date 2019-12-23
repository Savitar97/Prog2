#include <iostream>
#include "perceptron.hpp"
#include <png++/png.hpp>
#include <fstream>

int main (int argc, char **argv)
{
   png::image <png::rgb_pixel> kep (argv[1]);
   
   int size = kep.get_height()*kep.get_width();
   
   Perceptron* p = new Perceptron(3, size, 256, size);
   
   double* image = new double[size+1];
   
   for (int i = 0; i < kep.get_width(); ++i)
      for (int j = 0; j < kep.get_height(); ++j)  
           
          image[i*kep.get_width()+j] = kep[i][j].blue;
       
   double* value = (*p)(image);

    for(int i = 0; i < kep.get_width(); ++i)
	for(int j = 0; j<  kep.get_height(); ++j){
	kep[i][j].green = value[i*kep.get_height()+j];
	}
	kep.write("visszakep.png");
   
   
   delete p;
   delete [] image;
}
