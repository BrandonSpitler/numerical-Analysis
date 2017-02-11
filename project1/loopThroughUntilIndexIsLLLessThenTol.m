function [ index ] = loopThroughUntilIndexIsLLLessThenTol( tol, dataRange )
%have a data range with slope as second index
%loop though untill the slope is less then tolarance

[x,~]=size(dataRange(:,1));

index=round(x/2);

while(dataRange(index,2)>tol)
    index=ceil((x-index)/2+index);
    if(index==x)
        index=-1;
        return;
    end
end
    

end

