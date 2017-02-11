%Numerical Analysis Project 1


deltaPrime='Delta*exp(theta)-theta';
Delta=1/3;
h=0.001;t=0;u1=1;u2=1;hs=h/2;
theta=0;
y=zeros(100002,1);
for i=1:100000
  y(i)=theta;
  thetaStart=theta;
  k11=eval(deltaPrime);
  
  theta=theta+hs*k11;
  k21=eval(deltaPrime);
  
  theta=thetaStart+hs*k21;
  k31=eval(deltaPrime);
  
  theta=thetaStart+h*k31;
  k41=eval(deltaPrime);
    y(i,2)=(k11+2*k21+2*k31+k41)/6;

  theta=thetaStart+h*y(i,2);
end


index=loopThroughUntilIndexIsLLLessThenTol(.0001,y);


shortTerm='Delta/(Delta-1)*(exp((Delta-1)*sigma)-1)';

shortTermData=zeros(100002,2);
for i=1:1:100000
   shortTermData(i,2)=i*h;
   sigma=i*h;
   shortTermData(i,1)=eval(shortTerm); 
end


% id=loopThroughUntilIndexIsLLLessThenTolv2(.0001,y);
% id2=findDiverg(shortTermData,y,y(id,1)*.05);
% 
% longTermDataPart1=zeros(1:100002);
% longTermDataPart1(:)=1/Delta;
% id3=findDivergRev(longTermDataPart1,y(id,1)*.05);
% plot(shortTermData(1:id2,2),shortTermData(1:id2,1),shortTermData(1:id,2),y(1:id,1),longTermDataPart1(id3:id),y(id3:id,1));
% title('Non-adiabatic Explosion delta 1/3');
% xlabel('time')
% ylabel('energy')
% legend('shortTerm','actual');
% legend('show')