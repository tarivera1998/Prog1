/*
    g++ drill13_1.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o drill13_1 `fltk-config --ldflags --use-images`
*/
#include "Simple_window.h"
#include "Graph.h"

int main()
{
    using namespace Graph_lib;

  //get the Window
  
    int xmax = 800;
    int ymax = 1000;

    int x_orig = xmax/2;
    int y_orig = ymax/2;

    int rmin = -11;
    int rmax = 11;
    
    int n_points = 400;

    Simple_window win {Point{100,100}, xmax, ymax, "Drill13"};
    
    int x_size = 800;
    int y_size = 800;
    int x_grid = 100;
    int y_grid = 100;
    
   // adding the grid
   
    Lines grid;
    for (int x = x_grid; x < x_size; x += x_grid)
        grid.add(Point{x, 0}, Point{x, y_size});   
    for (int y = y_grid; y < y_size; y += y_grid)
        grid.add(Point{0, y}, Point{x_size, y});
        
    grid.set_color(Color::red);
    win.attach(grid);
    win.wait_for_button();
    
    // adding the red rectangles
    Vector_ref<Rectangle> rect;
    for (int i = 0; i < x_size; i += x_grid) {
       rect.push_back(new Rectangle{Point{i,i}, Point{i+x_grid,i+x_grid}});
       rect[rect.size() - 1].set_color(Color::invisible);
       rect[rect.size() - 1].set_fill_color(Color::red);
       win.attach(rect[rect.size() - 1]);
    }

    win.wait_for_button();
    
 
    // adding the first image
    
    Image galaxy1 {Point{0,300}, "galaxy.jpg"};
    Image galaxy2 {Point{300,600}, "galaxy.jpg"};
    Image galaxy3 {Point{500,100}, "galaxy.jpg"};

    win.attach(galaxy1);
    win.attach(galaxy2);
    win.attach(galaxy3);
    win.wait_for_button();
    
    // adding the second image
    
    Image stars {Point{0,0}, "stars.jpg"};
    win.attach(stars);
    win.wait_for_button();

    //moving the image
    
   for(int i= 0; i< 6; ++i) {

		stars.move(100, 100);
		win.set_label("654321" +i);
		win.wait_for_button();
  

win.wait_for_button();
  }
}
