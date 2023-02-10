

cd 'C:\Users\david\Downloads\IQS_2022_PullData'
direct= dir (['*Iowa*']);
%figure()
% hold on
% for i = 1 : length(direct)
%     b=direct(i,1);
%     a = readtable(b.name);
%     dist=a{:,10};
%     dist=smoothdata(dist);
%     force=a{:,5};
%     force=smoothdata(force);
% 
% 
% 
%     plot(dist,force)
%     ylim([0 3000])
%     xlim([0 300])
%     xlabel('Distance')
%     ylabel('Force')
%     title('Pull Force Over Distance')
% end
% hold off
% figure()
% hold on
% for i = 1 : length(direct)
%     b=direct(i,1);
%     a = readtable(b.name);
%     dist=a{:,10};
%     dist=smoothdata(dist);
%     Speed=a{:,7};
%     Speed=smoothdata(Speed);
% 
% 
% 
%     plot(dist,Speed)
%     ylim([0 7])
%     xlim([0 300])
%     xlabel('Distance')
%     ylabel('Speed')
%     title('Speed Over Distance')
% end
% hold off

figure()
hold on
for i = 1 : length(direct)
    b=direct(i,1);
    a = readtable(b.name);
    Force=a{:,5};
    Speed=a{:,7};
    Force=smoothdata(Force);
    Speed=smoothdata(Speed);

    

    plot(Speed,Force)
    ylim([0 2500])
    xlim([0 7])
    xlabel('Speed')
    ylabel('Force')
    title('Force Over Speed')
end
clear Speed_two;
clear Force_two;
Speed_two(1)=0;
Force_two(1)=0;
len=1;
Speed=round(Speed,3);
for i=2 : length(Speed)
    if ((Speed(i)-Speed(i-1))>0 && Speed(i)>0 && ~ismember(Speed(i),Speed_two))
        
        Speed_two(len)=Speed(i);
        Force_two(len)=Force(i);
        len = len +1;
    end
end
clear Speed_three;
clear Force_three;
Speed_three(1)=0;
Force_three(1)=0;
len=1;
for i=2 : length(Speed)
    if ((Speed(i)-Speed(i-1))<0 &&Speed(i) > .02 && ~ismember(Speed(i),Speed_three))
        
        Speed_three(len)=Speed(i);
        Force_three(len)=Force(i);
        len = len +1;
    end
end
Speed_three=flip(Speed_three);
Force_Three=flip(Force_three);


hold off
% figure()
% hold on
% for i = 1 : length(direct)
%     b=direct(i,1);
%     a = readtable(b.name);
%     Power=a{:,13};
%     Power=smoothdata(Power);
%     dist=a{:,10};
%     dist=smoothdata(dist);
% 
% 
% 
%     plot(dist,Power)
%     ylim([0 20])
%     xlim([0 400])
%     xlabel('Distance')
%     ylabel('Power')
%     title('Power Over Distance')
% end
% hold off