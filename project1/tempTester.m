id=loopThroughUntilIndexIsLLLessThenTolv2(.001,y);
id2=findDiverg(shortTermData,y,y(id,1)*.05);

longTermDataPart1=zeros(id,1);
longTermDataPart1(:)=y(id,1);
id3=findDivergRev(longTermDataPart1,y(1:id,1),y(id,1)*.05);
hold on
p=plot(shortTermData(1:id,2),y(1:id,1),':',shortTermData(1:id2,2),shortTermData(1:id2,1),'--',shortTermData(id3:id,2),longTermDataPart1(id3:id),'--');
title('Non-Adiabatic Explosion Delta=1/3');
xlabel('Sigma')
ylabel('Theta')

p(1).LineWidth=2;
p(1).Color=[1,0,0];
p(2).LineWidth=4;
p(2).Color=[0,1,0];
p(3).LineWidth=4;
p(3).Color=[0,0,1];
hleg=legend('Actual','Short Term','Long Term');
set(hleg,'FontSize',14)
legend('show')

hold off