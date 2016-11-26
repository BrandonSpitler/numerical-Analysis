# numerical-Analysis
numerice methods written in c, c++, and matlab

Interpolaation
 </t>variables 
  private: 
   NumberOfPoints - is the number of points in the array can be updated by calling setNumberOfPoints and passing in the number of points also set when object is constructed <br>
   newtownsCoef - ceofients to a polynomial going through all of the points set calling setNetwonsCeof <br>
   
  public
   pointsArray - the x and y cordinates <br>
   
 methods <br>
  public: <br>
   interpolation - constructer takes the number of points in an x y array along with an xy array set up so that x is in the first collumn y is in the second collumn see example in main, and takes the xy array <br>
   deconstructer - deletes all the variables made for this object <br>
   setNumberOfPoints - sets the number of points in the xy array <br>
   getNumberOfPoints - gets the number of points in the xy array <br>
   lagrange - takes the value to evaluate at as alpha using the lagrange method creates a polynomial from the pointsArray and evalutates it at alpha<br>
   nevilles -  takes the value to evaluate at as alpha using neville's method creates a polynomial from the pointsArray and evalutates it at alpha<br>
   setNetwonsCeof - setNewtonsCeof for using netwonInterp so that they can be used at any alpha<br>
   netwonsInterp -  takes the value to evaluate at as alpha using the ceof set up in setNetwonsCeof<br>
   clampedCubiccSpline - prints out the bounds of and cubics that make the xy array into a cubicspline where the slopes at the bounds are equal the slope of the end points are equal to the slopes FPO and the begging and FPN at the end <br>
   naturalCubicSpline -  prints out the bounds of and cubics that make the xy array into a cubicspline where the slopes at the bounds are equal the end and start slope are "free" meaning that the second derivative there is 0 so it is an inflection points <br>

IntegrationAndDifferentiation <br>
 methods <br>
  compisiteMidPointRule - integrates a set of points using compsitemidPointRule <br>
  simpComposite - integrates a set of points using simpsons compsite rule <br>
  trapRule - integrates a set of points using the trapRule <br>
