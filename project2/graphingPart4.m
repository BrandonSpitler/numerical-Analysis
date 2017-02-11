id =100;
hold on
horLine=zeros(size(prA(1,1:id,1)));
horLine(:)=2.7852813;
p=plot(prA(1,1:id,1),prA(1,1:id,5),prA(1,1:id,1),prA(2,1:id,5),prA(1,1:id,1),prA(3,1:id,5),prA(1,1:id,1),prA(4,1:id,5),2.2041088,.02,'r*',2.7852813,.02,'r*',4.6886,.02,'r*',8.6659,.02,'r*');
title('G(n) vs n');
xlabel('n')
ylabel('G(n)')

p(1).LineWidth=1;
p(1).Color=[1,0,0];
p(2).LineWidth=1;
p(2).Color=[0,1,0];
p(3).LineWidth=1;
p(3).Color=[0,0,1];
p(4).LineWidth=1;

p(5).Color=[0,0,0];
p(5).LineWidth=3;
p(6).Color=[0,0,0];
p(6).LineWidth=3;
p(7).Color=[0,0,0];
p(7).LineWidth=3;
p(8).Color=[0,0,0];
p(8).LineWidth=3;
hleg=legend('Pr=.2','Pr=1','Pr=4','Pr=8','n_t');
set(hleg,'FontSize',14)
legend('show')

hold off