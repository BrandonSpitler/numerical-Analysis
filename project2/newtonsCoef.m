function [ newtonsOneDemCoef ] = newtonsCoef( xyArray )
%UNTITLED2 Summary of this function goes here
%   Detailed explanation goes here
[n,y]=size(xyArray);
newtonsCoef=zeros(n,n);
newtonsOneDemCoef=zeros(n,1);
newtonsOneDemCoef=xyArray(1,2);
for i=1:1:n
    newtonsCoef(i,1)=xyArray(i,2);
    for j=2:1:i
        newtonsCoef(i,j)=(newtonsCoef(i,j-1)-newtonsCoef(i-1,j-1))/(xyArray(i,1)-xyArray(i-j+1,1));
        if(j==i)
            newtonsOneDemCoef(j)=newtonsCoef(i,j);
        end
    end
end
end
