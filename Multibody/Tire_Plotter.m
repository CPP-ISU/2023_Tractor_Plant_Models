load("Tires.mat")

time=Tires(1,:);
left_Tire_NF=Tires(2,:)+Tires(4,:);
Right_Tire_NF=Tires(3,:)+Tires(5,:);

left_Tire_NF=medfilt1(left_Tire_NF,10);
Right_Tire_NF=medfilt1(Right_Tire_NF,10);


plot(time,left_Tire_NF,time,Right_Tire_NF)
xlim([0 5])
title("Tire Normal Force")
xlabel("Time (s)")
ylabel("Force (lbf)")
legend('show','Left Tire Normal Force','Right Tire Normal Force')