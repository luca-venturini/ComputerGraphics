/**************
 Function Triangle(float x1, float y1, float x2, float y2, float x3, float y3, float r, float g, float b)

 draws a triangle connecting points (x1,y1)  (x2, y2) and (x3, y3), colored with the (r,g,b) specified color.
 vertex are expressed in Normalized screen coordinates, (i.e. in range [-1,+1]), following the Vulkan convention.
 The red, green and blue (r,g,b) values are in the range [0,1].
 
 Using function Triangle(...) try to draw a children house, similar to the one below.
 
 First remove the two function below (given only as an example), and replace them with your own.
 Since it is a C program, you can use for loops if you think it can be helpful in your drawing.
 The for() command below that draws a sun like shape in exact center of the screen near the top,
 is an example on how you can use it: please remove it, and replace it with your own code.
 It is not necessery to use a for loop if you do not really need it: it has been put here only as
 an example to help students not familiar with C++.
***************/

Triangle(-0.03, 0.18, 0.35, -0.45, 0.72, 0.18, 1, 0, 0);	// Red roof
Triangle(0.08, 0.18, 0.08, 0.8, 0.63, 0.8, 0, 0, 1);	// House
Triangle(0.08, 0.18, 0.63, 0.18, 0.63, 0.8, 0, 0, 1);	// House
Triangle(-1, 1, 1, 1, 1, 0.8, 0, 1, 0);	// Ground
Triangle(-1, 1, -1, 0.8, 1, 0.8, 0, 1, 0);	// Ground
Triangle(0.3, 0.5, 0.3, 0.8, 0.4, 0.8, 1, 1, 0);	// Door
Triangle(0.3, 0.5, 0.4, 0.5, 0.4, 0.8, 1, 1, 0);	// Door
Triangle(0.45, 0.3, 0.45, 0.4, 0.55, 0.3, 1, 1, 0);	// Right window
Triangle(0.55, 0.4, 0.45, 0.4, 0.55, 0.3, 1, 1, 0);	// Right window
Triangle(0.15, 0.3, 0.15, 0.4, 0.25, 0.3, 1, 1, 0);	// Left window
Triangle(0.25, 0.4, 0.15, 0.4, 0.25, 0.3, 1, 1, 0);	// Left window

