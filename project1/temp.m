u1p='3*u1+2*u2-(2*t*t+1)*exp(2*t)';
u2p='4*u1+u2+(t*t+2*t-4)*exp(2*t)';
h=0.2;t=0;u1=1;u2=1;hs=h/2;
for i=1:5
  u1s=u1;u2s=u2;
  k11=eval(u1p);k12=eval(u2p);
  t=t+hs;u1=u1s+hs*k11;u2=u2s+hs*k12;
  k21=eval(u1p);k22=eval(u2p);
  u1=u1s+hs*k21;u2=u2s+hs*k22;
  k31=eval(u1p);k32=eval(u2p);
  t=t+hs;u1=u1s+h*k31;u2=u2s+h*k32;
  k41=eval(u1p);k42=eval(u2p);
  u1=u1s+h*(k11+2*k21+2*k31+k41)/6;
  u2=u2s+h*(k12+2*k22+2*k32+k42)/6;
end
fprintf('Calculated u1(1) = %8.6f , u2(1) = %8.6f\n',u1,u2)
u1c=exp(5)/3-exp(-1)/3+exp(2);
u2c=exp(5)/3+2*exp(-1)+exp(2);
fprintf('Actual     u1(1) = %8.6f , u2(1) = %8.6f\n',u1c,u2c)
