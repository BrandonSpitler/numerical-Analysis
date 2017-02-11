
x=-3;
t=zeros(602,2);
index=0;
while(x<3.01)
    index=index+1;
    i=0;
    l=x/3;
while(i<10000)
  l=exp(l)/x;
    i=i+1;
end
t(round(x*100+1001),2)=x;
t(round(x*100+1001),1)=l;
    x=x+.01;
end
plot(t(:,2),t(:,1))