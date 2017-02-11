% rk4_shootingMethod_NumProject2_FlowOverAFlatPlate( input_args )
tol=0.01;
maxIterations=1000;
h=.1;
hh=h/2;
u1=0;
u2=0;
u3=0.33205;
u4=1;
u5=-.6624700;Pr=8; %        2.3177
%u5=-.52445;Pr=4;    % root at 2.9136

u5=-.3227;Pr=1;     %5.0931%4.6886
%u5=-.1805230;Pr=.2;  %root at 7.1312

p0=u3;
 points=rk4_flatPlate( u1,u2,u3,u4,u5,Pr,maxIterations );
lastChange=points(maxIterations-30,3)-1;
lastU3=u3;
u3=.3140363;
p1=u3;
i=0;
 points=rk4_flatPlate( u1,u2,u3,u4,u5,Pr,maxIterations );
thisChange=points(maxIterations-30,3)-1;
%  while (abs(points(maxIterations-30,3)-1)>tol && -(lastChange-thisChange)/(lastU3-u3)<0)
%  lastChange=points(maxIterations-30,3)-1;
%  lastU3=u3;
%  u3=u3+.00000001;
%  points=rk4_flatPlate( u1,u2,u3,u4,u5,Pr,maxIterations );
%  thisChange=points(maxIterations-30,3)-1;
%  i=i+1;
%  abs(points(maxIterations-30,3)-1)
% end

 while (abs(min(points(950,5)))>tol)% && (lastChange-thisChange)/(lastU3-u5)<0)
 lastChange=points(maxIterations-30,5);
 lastU3=u5;
 u5=u5-.00001;
 points=rk4_flatPlate( u1,u2,u3,u4,u5,Pr,maxIterations );
 thisChange=points(maxIterations-30,5);
 i=i+1;
 min(points(950,5))
 end
 points=rk4_flatPlate( u1,u2,u3,u4,u5,Pr,maxIterations );

newValue=((points(1:100,1).*points(1:100,3)-points(1:100,2)))./2;
plot(points(1:100,1),newValue,points(1:100,1),points(1:100,3));
xyArray=zeros(950,2);
xyArray(:,1)=points(1:950,1);
xyArray(:,2)=points(1:950,5)-.02;
newCoef=newtonsCoef(xyArray);
points(950,5)
%secant method
p0=8.7;
q0=newtonsInterplate( newCoef,xyArray, p0 );
p1=8.83;
q1=newtonsInterplate( newCoef,xyArray, p1 );
TOL=0.0001;
i=0;
while(i<maxIterations)
    p=p1-q1*(p1-p0)/(q1-q0);   
    if(abs(p-p1)<TOL)
        x='found'
        index=i;
        i=maxIterations+1;
    else
    i=i+1;
    p0=p1;
    q0=q1;
    p1=p;
    q1=newtonsInterplate( newCoef,xyArray, p );
    end
end
    
    
