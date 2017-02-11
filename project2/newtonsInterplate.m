function [ inter ] = newtonsInterplate( newCoef,xyArray, alpha )
%UNTITLED4 Summary of this function goes here
%   Detailed explanation goes here
    [x,y]=size(newCoef);
    inter=newCoef(1,1);
    for i=2:1:y
        product=newCoef(1,i);
        for j=1:1:i-1
           product=(alpha-xyArray(j,1))*product; 
        end
        inter=inter+product;
        
    end
    
end

