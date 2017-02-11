function [ i ] = findDiverg( dataRangeA,dataRangeB,Tol )
%UNTITLED2 Summary of this function goes here
%   Detailed explanation goes here
[x,c]=size(dataRangeA);

for i=1:1:x
   if(abs(dataRangeA(i,1)- dataRangeB(i,1))>Tol)
       return
   end
end


end

