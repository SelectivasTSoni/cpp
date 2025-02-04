# include <iostream>
# include <cmath>

double x;
double y;
double start;
double end;
double n_rectangles;
double width;
double areaUnderCurve;
double length;
double rectangleArea;
double area;

double curve_function(double x);
double integrate(double start, double end, double n_rectangles);


double curve_function(double x)
{
	y = 3 * pow(x, 2) + 1;
	return y;
}

double integrate(double start, double end, double n_rectangles)
{
	/* 
		Area under the curve is the sum of the areas of the rectangles under the curve. More rectangles give closer approximation of the true area.

		Here, we consider x values to be the point at the middle of the rectangle. So if we have n rectangles, the x value evolves according to:

			w/2 + w+w/2 + 2w+w/2 + ... + nw+w/2

		so something like this

			for (int i=0; i<n_rectangles; ++i){
				x = i * width + width/2;
			}

		gives us values for x at the top center of each rectangle under the curve.

		Our y values come from the curve_function(x) which takes x as an argument.
	*/

	/* 
		The width of each rectangle is the width of the region under the curve divided by the number of rectangles. Start and end are values of x: 
	*/
	width = (end - start)/n_rectangles;

	/* 
		This is the accumulator. It aggregates the areas of the individual rectangles into the total area. We initialize it to 0.0.
	*/ 
	areaUnderCurve = 0.0;

	/* 
		For each rectangle:

		1. Get our x value
		2. Get our y value from curve_function()
		3. Calculate area of rectangle i
		4. Add area of i to the accumulator
	*/
	for (int i=0; i<n_rectangles; ++i)
	{
		x = (i * width) + (width/2);
		y = length = curve_function(x);
		rectangleArea = length * width;
		areaUnderCurve += rectangleArea;
	}

	std::cout << std::endl;
	std::cout << std::fixed << "Number of Rectangles: " << n_rectangles << std::endl;
	std::cout << std::fixed << "Rectangle width: " << width << std::endl;
	std::cout << std::endl;
 
	return areaUnderCurve;
}


int main()
{
	area = integrate(0, 2, 1000000);

	std::cout << std::fixed << "The area under the curve is: " << area << std::endl;
	std::cout << std::endl;

	return 0;
}

