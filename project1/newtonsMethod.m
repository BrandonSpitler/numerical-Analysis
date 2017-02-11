function [ p ] = newtonsMethod( dataRange,Tol,p0,N )
%data range should have a rnage of value in 1 index a slope in the second
%slope
    i=0;
    
    [r,c]=size(dataRange);
    while(i<N)
         p=p0-round(dataRange(p0,1)/dataRange(p0,2)*stepSize);  
       if(abs(p-p0)<Tol)
          return;
       end
       p0=p;
       i=+1;
    end
        
end

