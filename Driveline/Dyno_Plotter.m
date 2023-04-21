

Output_Torque=100;

%sim("Efficency_Benchmarking")
%%
load("Dyno_Data.mat")
Efficency_input_speed=4800;
Time=Dyno(1,:);
Output_Speed=Dyno(2,:);
MP1_Swash=Dyno(3,:).*100;
MP2_Swash=Dyno(4,:).*100;
Pressure_B=Dyno(5,:);
Pressure_A=Dyno(6,:);
num=10;
f=.1:.05:5;
noise_arr=zeros([num length(Time)]);
for i=1:num
    noise_arr(i,:)=sin(2*pi*Time*f(i));
end
noise=sum(noise_arr);
noise2=prod(noise_arr);
%noise3=noise2.*noise3;

%actual_b=Pressure_B+100*noise;
%actual_a=Pressure_A+(3e100*noise3)+100;
%figure(12)
%plot(Time,noise1)

figure(15)
subplot(2,1,1)
plot(Time,MP1_Swash,Time,MP2_Swash)
grid on
title("Pump Commands")
xlabel("Time (s)")
ylabel("Pump Swash Command (%)")
legend('show','MP1','MP2')
%text(12.5,20,'\leftarrow Reverse')
text(230,0,'\leftarrow Ring Gear Locked')
text(200,25,"Overdrive \rightarrow")
subplot(2,1,2)


plot(Time,medfilt1(Output_Speed,5))
grid on
title("Transmission Output Speed")
xlabel('Time (s)')
ylabel("Output Speed (RPM)")
%text(25,-300,"\leftarrow Reverse")
text(5,600,"Reverse")
text(15,200,"\downarrow")
text(60,100,"\leftarrow Foward")
%subplot(2,1,1)
%plot(Time,Pressure_A,Time,Pressure_B,Time,actual_a,Time,actual_b)

