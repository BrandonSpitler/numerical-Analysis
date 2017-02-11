function [ XI ] = compositeSimpsonRule( dataRange,a,b,h )
%UNTITLED Summary of this function goes here
%   Detailed explanation goes here

XI0=dataRange(a,2);
XI1=0;
XI2=0;

for i=a:1:b
   X=a+i;
   if(i/2==round(i/2))
      XI2=XI2+dataRange(X,2);
   else
      XI1=XI1+dataRange(X,2); 
   end
end
   XI=h*(XI0 + 2 * XI2+4*XI1)/3;

end

