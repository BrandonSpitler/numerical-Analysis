function [ i ] = findDivergRev( dataRangeA,dataRangeB,Tol )
%UNTITLED2 Summary of this function goes here
%   Detailed explanation goes here
[x,c]=size(dataRangeB);

for i=x:-1:1
   if((abs(dataRangeA(i,1)- dataRangeB(i,1)))/dataRangeB(i,1)>Tol)
       return
   end
end


end