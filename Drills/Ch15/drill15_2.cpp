/*
    g++ drill15_2.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o drill15_2 `fltk-config --ldflags --use-images`
*/

#include "Simple_window.h"
#include "Graph.h"

int main ()
{
  using namespace Graph_lib;

    int xmax = 600;
    int ymax = 600;

    int x_orig = xmax/2;
    int y_orig = ymax/2;

    int rmin = -11;
    int rmax = 11;
    
    int n_points = 400;

    Simple_window win {Point{100,100}, xmax, ymax, "Canvas"};
    
    
     win.wait_for_button();
  }
  
  
  
