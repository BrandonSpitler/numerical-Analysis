function [  ] = RungeKutta_4( a ,b ,N, alpha )%endpoint are a and b Integer is N initial condition is alpha
%UNTITLED Summary of this function goes here
%   Detailed explanation goes here
h=(b-a)/N;
t=a;
w=alpha;


for i =1:1:N
    k1=h*fun_dir(t,w);
    k2=h*fun_dir(t+h/2,w+(k1)/2);
    k3=h*fun_dir(t+h/2,w+(k2)/2);
    k4=h*fun_dir(t+h,w+k3);
    
    w=w+(k1+2*(k2)+2*(k3)+k4)/6;
    t=a+i*h;
    disp('t is ');
    disp(t);
    disp('w is ');
    disp(w);
end


end

