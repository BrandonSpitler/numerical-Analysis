# numerical-Analysis
numerice methods written in c, c++, and matlab

Interpolaation 
 variables
  private
   NumberOfPoints - is the number of points in the array can be updated by calling setNumberOfPoints and passing in the number of points also set when object is constructed
   newtownsCoef - ceofients to a polynomial going through all of the points set calling setNetwonsCeof
  public
   pointsArray - the x and y cordinates 
   
 methods
  public
   interpolation - constructer takes the number of points in an x y array along with an xy array set up so that x is in the first collumn y is in the second collumn see example in main, and takes the xy array
   deconstructer - deletes all the variables made for this object
   setNumberOfPoints - sets the number of points in the xy array
   getNumberOfPoints - gets the number of points in the xy array
   lagrange - takes the value to evaluate at as alpha using the lagrange method creates a polynomial from the pointsArray and evalutates it at alpha
   nevilles -  takes the value to evaluate at as alpha using neville's method creates a polynomial from the pointsArray and evalutates it at alpha
   setNetwonsCeof - setNewtonsCeof for using netwonInterp so that they can be used at any alpha
   netwonsInterp -  takes the value to evaluate at as alpha using the ceof set up in setNetwonsCeof
   clampedCubiccSpline - prints out the bounds of and cubics that make the xy array into a cubicspline where the slopes at the bounds are equal the slope of the end points are equal to the slopes FPO and the begging and FPN at the end
   naturalCubicSpline -  prints out the bounds of and cubics that make the xy array into a cubicspline where the slopes at the bounds are equal the end and start slope are "free" meaning that the second derivative there is 0 so it is an inflection points

IntegrationAndDifferentiation
 methods
  compisiteMidPointRule - integrates a set of points using compsitemidPointRule
  simpComposite - integrates a set of points using simpsons compsite rule
  trapRule - integrates a set of points using the trapRule
