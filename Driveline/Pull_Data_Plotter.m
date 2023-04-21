load("Pull_Data.mat");
time=Pull(1,:);
Engine_Power=Pull(2,:);
Engine_Power=Engine_Power/745.7;
Transmission_Power=Pull(3,:);
Transmission_Power=Transmission_Power/745.7;
Ground_Power=Pull(4,:);
Ground_Power=Ground_Power/745.7;
y_force=Pull(5,:);
x_force=Pull(6,:);
Speed=Pull(7,:);
Distance=Pull(8,:);
MP1_Torque=Pull(9,:);
MP2_Torque=Pull(10,:);
Carrier_Torque=Pull(11,:);
Output_Torque=Pull(12,:);
Pressure_B=Pull(13,:);
Pressure_A=Pull(14,:);
MP2_Speed=Pull(15,:);
MP1_Speed=Pull(16,:);

figure(17)
%plot(time,x_force,time,y_force);
subplot(3,1,1)
plot(time,x_force,time,y_force)
legend('show','Horizontal Force','Vertical Force')
xlabel('Time (s)')
ylabel('Force (lbf)')
title("Hitch Forces")
subplot(3,1,2)
plot(time,Speed)
xlabel('Time (s)')
ylabel('Speed (MPH)')
title("Ground Speed")
subplot(3,1,3)
plot(time,Engine_Power,time,Transmission_Power,time,Ground_Power)
legend('show','Engine Power','Transmission Power','Power To the Ground')
xlabel('Time (s)')
ylabel('Power HP')
title("Power Throughout Driveline")

figure(16);
subplot(4,1,1)
plot(time,MP1_Torque,time,MP2_Torque)
title("Motor Pump Torques")
xlabel("Time (s)")
ylabel("Torque (in*lb)")
legend('show','MP1 Torque','MP2 Torque')

subplot(4,1,2)
plot(time,Carrier_Torque,time,Output_Torque)
title("Carrier and Output Speed")
xlabel("Time (s)")
ylabel("Torque (ft*lbs)")
legend('show','Carrier Torque','Output Torque')

subplot(4,1,3)
plot(time,MP1_Speed,time,MP2_Speed)
title("MP1 and MP2 Speed")
xlabel('Time (s)')
ylabel("Speed (RPM)")
legend('show',"MP1 Speed","MP2 Speed")

subplot(4,1,4)
plot(time,Pressure_A,time,Pressure_B)
title("Pressure A and B")
xlabel('Time (s)')
ylabel('Pressure (PSI)')
legend("show","Pressure A","Pressure B")

