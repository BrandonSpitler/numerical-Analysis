function [ index ] = loopThroughUntilIndexIsLLLessThenTolv2( tol, dataRange )
%have a data range with slope as second index
%loop though untill the slope is less then tolarance

[x,~]=size(dataRange(:,1));

index=round(x/2);
high=x;
low=1;
while(1)
    index=ceil((high+low)/2);
    if(index>=x)
        index=-1;
        return;
    end
    if(dataRange(index,2)<tol)
        high=index;
    elseif(dataRange(index,2)>tol)
        low=index;
    else
        return;
    end
    if(high-1<=low)
        
        return
    end    
    
end
    

end

