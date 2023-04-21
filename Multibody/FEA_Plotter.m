load('FEA.mat')
time=FEA(1,:);
Right_Frame_Force_X=FEA(7,:);
Right_Frame_Force_Y=FEA(8,:);
Right_Frame_Force_Z=FEA(9,:);
Right_Cylinder_Force_X=FEA(13,:);
Right_Cylinder_Force_Y=FEA(14,:);
Right_Cylinder_Force_Z=FEA(15,:);

Right_Pressure_A=FEA(19,:);
Right_Pressure_B=FEA(20,:);
Right_Delta_Pressure=FEA(21,:);
Right_Cylinder_Actuator_Force=FEA(22,:);
Left_Cylinder_Actuator_Force=FEA(30,:);

Right_Frame_Force=sqrt(Right_Frame_Force_X.^2+Right_Frame_Force_Y.^2+Right_Frame_Force_Z.^2);
Right_Cylinder_Force=sqrt(Right_Cylinder_Force_X.^2+Right_Cylinder_Force_Y.^2+Right_Cylinder_Force_Z.^2);

Left_Frame_Force_X=FEA(19,:);
Left_Frame_Force_Y=FEA(20,:);
Left_Frame_Force_Z=FEA(21,:);

Left_Cylinder_Force_X=FEA(25,:);
Left_Cylinder_Force_Y=FEA(26,:);
Left_Cylinder_Force_Z=FEA(27,:);

Left_Frame_Force=sqrt(Left_Frame_Force_X.^2+Left_Frame_Force_Y.^2+Left_Frame_Force_Z.^2);
Left_Cylinder_Force=sqrt(Left_Cylinder_Force_X.^2+Left_Cylinder_Force_Y.^2+Left_Cylinder_Force_Z.^2);
filter_constant=20;
Left_Frame_Force=medfilt1(Left_Frame_Force,filter_constant);
Right_Frame_Force=medfilt1(Right_Frame_Force,filter_constant);
Left_Cylinder_Force=medfilt1(Left_Cylinder_Force,filter_constant);
Right_Cylinder_Force=medfilt1(Right_Cylinder_Force,filter_constant);
figure(10)
subplot(2,1,1)
plot(time,Right_Frame_Force,time,Left_Frame_Force)
xlabel('Time (s)')
ylabel('Force (lbf)')
legend('show','Right Side Frame Force','Left Side Frame Force')
xlim([0 3])
subplot(2,1,2)

plot(time,Right_Cylinder_Force,time,Left_Cylinder_Force)
xlabel('Time (s)')
ylabel('Force (lbf)')
legend('show','Right Side Cylinder Force','Left Side Cylinder Force')
xlim([0 3])

figure(13)
plot(time,Right_Cylinder_Actuator_Force)

right_cylinder_pressure=Right_Cylinder_Force*(pi()*.5^2);
right_cylinder_pressure=medfilt1(right_cylinder_pressure,50);
left_cylinder_pressure=Left_Cylinder_Force*(pi()*.5^2);
left_cylinder_pressure=medfilt1(left_cylinder_pressure,50);

figure(14)
plot(time,right_cylinder_pressure,time,left_cylinder_pressure)
xlim([0 5])
xlabel("Time (s)")
ylabel("Pressure (PSI)")
title("Suspension Pressure")
legend('show',"Right Suspension Pressure","Left Suspension Pressure")