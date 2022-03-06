/*
    g++ drill15_1.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o drill15_1 `fltk-config --ldflags --use-images`
*/

#include "Simple_window.h"
#include "Graph.h"

//declaring the functions for the second part of the drill
double one(double x) { return 1; }
double slope(double x) { return x/2; }
double square(double x) { return x*x; }
double sloping_cos(double x) { return cos(x) + slope(x); }

int main ()
{
  using namespace Graph_lib;

    //Function graphing drill first part
    
    const int xmax = 600;
    const int ymax = 600;

    const int x_orig = xmax/2;
    const int y_orig = ymax/2;

    const int r_min = -10;
    const int r_max = 11;
    
    const int n_points = 400;
    const int x_scale = 20;
    const int y_scale = 20;

    const Point orig {300, 300};

    const int xlength = xmax - 200;
    const int ylength = ymax - 200;
    
    //creating the window
    Simple_window win {Point{100,100}, xmax, ymax, "Function graphs"};
    
    //defining the axis
    Axis x(Axis::x,Point(100,y_orig),xlength,xlength/x_scale,"1 == 20 pixels");
    x.set_color(Color::red);
    win.attach(x);
    
    Axis y(Axis::y,Point(x_orig,500),ylength,ylength/y_scale,"1 == 20 pixels");
    y.set_color(Color::red);
    win.attach(y);
    
    win.wait_for_button();
    
    //second part of the drill
    
    Function fx (one,r_min,r_max,orig,n_points,x_scale,y_scale);
    win.attach(fx);
    
    win.wait_for_button();
    
    Function gx (slope,r_min,r_max,orig,n_points,x_scale,y_scale);
    win.attach(gx);
    
    win.wait_for_button();

    Text label (Point(100,y_orig+4*y_scale),"x/2");
    win.attach(label);
    
    win.wait_for_button();
    
    Function hx (square,r_min,r_max,orig,n_points,x_scale,y_scale);
    win.attach(hx);
    
    win.wait_for_button();

    Function ix (cos,r_min,r_max,orig,n_points,x_scale,y_scale);
    ix.set_color(Color::blue);
    win.attach(ix);
    
    win.wait_for_button();

    Function jx (sloping_cos,r_min,r_max,orig,n_points,x_scale,y_scale);
    win.attach(jx);
    
    win.wait_for_button();
    
    
  }
  
  
  
