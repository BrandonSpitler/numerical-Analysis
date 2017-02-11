function [ newArray ] = returnIterations( point,array )
%UNTITLED Summary of this function goes here
%   Detailed explanation goes here
[x,~]=size(array)
index=1;
for i=1:x
    if(mod(array(i,1),point)==0)
      newArray(index,:)=array(i,:);
      index=index+1;
    end
end

end

