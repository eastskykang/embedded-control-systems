
% Simulates the motion of a haptic wheel attached to a virtual wheel whose
% rotational intertia is J_w. The wheels are attached through a shaft
% with torsional spring constant k. 
% The simulation assumes that the wheel is turned through a fixed initial angle
% and then held constant.
k =  ????;  % spring constant in N-mm/degree
b = 0;   % no damping 
Jw =  ?????   % rotational inertia in N-mm/(degree/sec^2)

char_roots_B0_cont = roots([Jw b k]);    % characteristic roots

step_time = 1;    % time of step change in wheel position (seconds)
Theta_z_0 = 45;    % size of step change in wheel position (degrees) = theta_z_0

max_torque = k*45;   % N-mm

omega_n = sqrt(k/Jw);   % frequency of oscillation in rad/sec
f_n = omega_n/(2*pi);   % frequency of oscillation in Hz
T_n = 1/f_n;            % period of oscillation in seconds

tfinal = 10;             % final time for simulation (seconds)

Deltat = .001;          % simulation step size    (seconds)  -- should be small with respect to T_n
sim('virtual_wheel')

% compute torque limits in N-mm at wheel

dutycycle_max = .65;
motor_torque_max = (dutycycle_max-.5)*773.4;
wheel_torque_max = motor_torque_max*128/18;

clear torque_limit
for i = 1:length(tout)
    torque_limit(i) = wheel_torque_max;
end
 
figure(1)
clf

plot(tout,yout(:,1),'-',tout,yout(:,2),'--',...
     tout,yout(:,3),'-.',tout,yout(:,4),':',tout,torque_limit,'k-',tout,-torque_limit,'k-')
xlabel('time, seconds')
ylabel('continuous system, no damping')
title(['k = ',num2str(k),' N-mn/deg, J_w = ',num2str(Jw),' N-mn/(deg/sec^2), f_n = ',num2str(f_n),' Hz'])
legend('\theta_w (deg)','d\theta_w/dt (deg/sec)',...
       '\theta_z (deg)','torque (N-mm)','torque limit',3)


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
tfinal = 10;             % final time for simulation (seconds)
T = .001;

char_roots_B0_disc = 1+T*roots([Jw b k])    % characteristic roots of system discretized with
                                            % forward euler aproximation


sim('virtual_wheel_discrete')

clear torque_limit
for i = 1:length(tout)
    torque_limit(i) = wheel_torque_max;
end
 
figure(2)
clf

plot(tout,yout(:,1),'-',tout,yout(:,2),'--',...
     tout,yout(:,3),'-.',tout,yout(:,4),':',tout,torque_limit,'k-',tout,-torque_limit,'k-')
 ylabel('discrete system, no damping')
xlabel('time, seconds')
title(['k = ',num2str(k),' N-mm/deg, J_w = ',num2str(Jw),' N-mm/(deg/sec^2), f_n = ',num2str(f_n),' Hz'])
legend('\theta_w (deg)','d\theta_w/dt (deg/sec)',...
       '\theta_z (deg)','torque (N-mm)','torque limit',3)


   
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%55
 
 b = ????????;   % damping constant in N-mm/(degree/sec)
char_roots_Bn0_cont = roots([Jw b k]);    % characteristic roots
tfinal = 10;             % final time for simulation (seconds)
 
sim('virtual_wheel_damping')

clear torque_limit
for i = 1:length(tout)
    torque_limit(i) = wheel_torque_max;
end
 
figure(3)
clf

plot(tout,yout(:,1),'-',tout,yout(:,2),'--',...
     tout,yout(:,3),'-.',tout,yout(:,4),':',tout,torque_limit,'k-',tout,-torque_limit,'k-')
 ylabel('continuous system with damping b = kT')
xlabel('time, seconds')
title(['k = ',num2str(k),' N-mm/deg, J_w = ',num2str(Jw),' N-mm/(deg/sec^2), f_n = ',num2str(f_n),' Hz'])
legend('\theta_w (deg)','d\theta_w/dt (deg/sec)',...
       '\theta_z (deg)','torque (N-mm)','torque limit',3)
   
   
   %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%55

 

tfinal = 10;             % final time for simulation (seconds)
b
char_roots_Bn0_disc = 1+T*roots([Jw b k])    % characteristic roots of system discretized with
                                             % forward euler aproximation
 
sim('virtual_wheel_damping_discrete')

clear torque_limit
for i = 1:length(tout)
    torque_limit(i) = wheel_torque_max;
end
 
figure(4)
clf

plot(tout,yout(:,1),'-',tout,yout(:,2),'--',...
     tout,yout(:,3),'-.',tout,yout(:,4),':',tout,torque_limit,'k-',tout,-torque_limit,'k-')
xlabel('time, seconds')
ylabel('discrete system with damping b = kT')
title(['k = ',num2str(k),' N-mm/deg, J_w = ',num2str(Jw),' N-mm/(deg/sec^2), f_n = ',num2str(f_n),' Hz'])
legend('\theta_w (deg)','d\theta_w/dt (deg/sec)',...
       '\theta_z (deg)','torque (N-mm)','torque limit',3)
   
   
   
 