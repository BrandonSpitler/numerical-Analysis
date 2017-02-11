%tempTester2


id=loopThroughUntilIndexIsLLLessThenTolv2(.001,y);
id2=findDiverg(shortTermData,y,.05);
id3=findDivergRev(longTermData,y(1:id,1),y(id,1)*.05);
%id3=findDivergRev(longTermData,y(1:id,1),.05);
hold on
p=plot(y(1:id,1),longTermData(1:id,2),':',shortTermData(1:id2,1),longTermData(1:id2,2),'--',longTermData(id3:id),longTermData(id3:id,2),'--');
title('Non-Adiabatic Explosion Delta=1');
xlabel('Sigma')
ylabel('Theta')

p(1).LineWidth=2;
p(1).Color=[1,0,0];
p(2).LineWidth=4;
p(2).Color=[0,1,0];
p(3).LineWidth=4;
p(3).Color=[0,0,1];
hleg=legend('RK-4','Short Term','Long Term');
set(hleg,'FontSize',14)
legend('show')

hold off