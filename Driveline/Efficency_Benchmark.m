%Efficency_input_speed=1600;
%sim("Efficency_Benchmarking")
Output_Torque_list= 50:10:400;
Input_Speed_List=1600:200:3600;
Input_Speed_List=Input_Speed_List*(4/3);
j=5;
i=5;

Output_Speed_interp=0:5:2000;
Overall_Efficency=zeros([length(Output_Torque_list) length(Output_Speed_interp)]);
for i=1:length(Output_Torque_list)
    %Input_Speed=Input_Speed_List(j);
    %for j=1:length(Output_Torque_list)
        Efficency_input_speed=4800;%Input_Speed_List(j);
        Output_Torque=Output_Torque_list(i);
        sim("Efficency_Benchmarking")
        load("Efficency_mapping.mat")
        Output_Speed=zeros([1,length(Eff)]);
        Output_Speed(1,:)=Eff(2,:);
        Efficency=Eff(3,:);
        iter=1;

        for k=1:length(Output_Speed)
            if Output_Speed(k)>0&&Efficency(k)>0

                Output_Speed_Filtered(iter)=Output_Speed(k);
                Efficency_filtered(iter)=Efficency(k);
                iter=iter+1;
                
            end
    
        end
        Efficency_interp=interp1(Output_Speed_Filtered,Efficency_filtered,Output_Speed_interp);
        Overall_Efficency(i,:)=Efficency_interp(:);
        Overall_Efficency_smooth=medfilt2(Overall_Efficency,[10 10]);
        surf(Output_Speed_interp,Output_Torque_list,Overall_Efficency_smooth)
    end
%end
%plot(Output_Speed_Filtered,Efficency_filtered)
%%
%Output_Torque_list= 50:10:400;
Overall_Efficency_smooth=medfilt2(Overall_Efficency,[3 5]);
surf(Output_Speed_interp,Output_Torque_list,Overall_Efficency_smooth)
xlabel("Output Speed (RPM)")
ylabel("Output Torque (ft*lb)")
zlabel("Efficency")
