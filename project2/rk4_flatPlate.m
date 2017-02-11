function [ points ] = rk4_flatPlate( u1,u2,u3,u4,u5,Pr,maxIterations )
%UNTITLED Summary of this function goes here
%   Detailed explanation goes here
%maxIterations=100000;
h=.1;
hh=h/2;
% u1=0;
% u2=0;
% u3=0..3107835;
% u4=1;
% u5=.2;
% Pr=5;
points=zeros(maxIterations,6);
%set intial conditions
q1=u1;
q2=u2;
q3=u3;
q4=u4;
q5=u5;
for i=1:1:maxIterations
    %format of variables is u(v1)(v2) where v1 is the order u it is and v2
    %is the which k it is in rk4 going all the way forward then halfway
    %foward revelating going halfway forward then all the way forward with
    %the new slope
    %set points into array for latter use
    points(i,1)=i*h-.1;
    points(i,2)=q1;
    points(i,3)=q2;
    points(i,4)=q3;
    points(i,5)=q4;
    points(i,6)=q5;
    %find the slope at the point that is all the way forward
    u11=h*u_Prime1(q2);
    u21=h*u_Prime2(q3);
    u31=h*u_Prime3(q1,q3);
    u41=h*u_Prime4(q5);
    u51=h*u_Prime5(q1,q5,Pr);
    %find slope that is halfway forward
    u12=h*u_Prime1(q2+.5*u21);
    u22=h*u_Prime2(q3+.5*u31);
    u32=h*u_Prime3(q1+.5*u11,q3+.5*u31);
    u42=h*u_Prime4(q5+(.5*u51));
    u52=h*u_Prime5(q1+(.5*u11),q5+(.5*u51),Pr);
    %revaluate and find halp way slope again
    u13=h*u_Prime1(q2+.5*u22);
    u23=h*u_Prime2(q3+.5*u32);
    u33=h*u_Prime3(q1+.5*u12,q3+.5*u32);
    u43=h*u_Prime4(q5+(.5*u52));
    u53=h*u_Prime5(q1+(.5*u12),q5+(.5*u52),Pr);
    %revaluated going all the way forward
    u14=h*u_Prime1(q2+u23);
    u24=h*u_Prime2(q3+u33);
    u34=h*u_Prime3(q1+u13,q3+u33);
    u44=h*u_Prime4(q5+u53);
    u54=h*u_Prime5(q1+u13,q5+u53,Pr);
   
    q1=q1+(u11+2*(u12+u13)+u14)/6.0;
    q2=q2+(u21+2*(u22+u23)+u24)/6.0;
    q3=q3+(u31+2*(u32+u33)+u34)/6.0;
    q4=q4+(u41+2*(u42+u43)+u44)/6.0;
    q5=q5+(u51+2*(u52+u53)+u54)/6.0;
   
end


end

