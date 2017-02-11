%1.3591
deltaPrime='1/(Delta*exp(theta)-theta)';
Delta=1;
h=0.01;hs=h/2;
theta=0;
y=zeros(100002,2);
y(1,1)=0;

for i=2:100000
  
  thetaStart=i*h;
  theta=thetaStart;
  k11=eval(deltaPrime); 
  
  theta=theta+hs*k11;
  k21=eval(deltaPrime);
  
  theta=thetaStart+hs*k21;
  k31=eval(deltaPrime);
  
  theta=thetaStart+h*k31;
  k41=eval(deltaPrime);
  y(i,2)=(k11+2*k21+2*k31+k41)/6;
  y(i,1)=y(i-1,1)+h*y(i,2);
end


simga_exp=compositeSimpsonRule(y,1,99999,.01);
longterm='simga_exp-1/(Delta*exp(theta))';
longTermData=zeros(100002,2);
for i=1:1:100000
   longTermData(i,2)=i*h;
   theta=i*h;
   longTermData(i,1)=eval(longterm); 
end
x=loopThroughUntilIndexIsLLLessThenTolv2(.0001,y);

shortTermData=zeros(100002,1);
shortTermData(:,1)=longTermData(:,2);
%plot(longTermData(1:10000,2),longTermData(1:x,1),longTermData(1:x,2),y(1:x,1))

% 
% syms d s;
% t=(d/(d-1))*(exp((d-1)*s)-1);
% div=diff(t,s)
