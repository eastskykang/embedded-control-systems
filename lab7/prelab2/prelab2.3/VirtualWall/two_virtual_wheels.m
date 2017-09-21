% Simulates the motion of a haptic wheel attached to a virtual wheel whose
% rotational intertia is J_w. The wheels are attached through a shaft
% with torsional spring constant k. 
% The simulation assumes that the wheel is turned through a fixed initial angle
% and then held constant.
k1 = .5*15;       % spring constant in N-mm/degree
Jw1 = .5*1.5/4;   % rotational inertia in N-mm/(degree/sec^2)

k2 = .5*15;           % spring constant in N-mm/degree
Jw2 = .5*.015/4;      % rotational inertia in N-mm/(degree/sec^2)
 
step_time = 1;    % time of step change in wheel position (seconds)
Theta_z_0 = 45;    % size of step change in wheel position (degrees) = theta_z_0

max_torque = k1*45;   % N-mm

omega_n1 = sqrt(k1/Jw1);   % frequency of oscillation in rad/sec
f_n1 = omega_n1/(2*pi);   % frequency of oscillation in Hz
T_n1 = 1/f_n1;            % period of oscillation in seconds

omega_n2 = sqrt(k2/Jw2);   % frequency of oscillation in rad/sec
f_n2 = omega_n2/(2*pi);   % frequency of oscillation in Hz
T_n2 = 1/f_n2;            % period of oscillation in seconds



Deltat = .0001;          % simulation step size    (seconds)  -- should be small with respect to T_n

tfinal = 5;             % final time for simulation (seconds)


% compute torque limits in N-mm 

dutycycle_max = .76;
motor_torque_max = (dutycycle_max-.5)*(5 ...   %Peak Voltage PWM [V] 
					                 * 2.5 ... %Gain Demodulator [V/V]  
									 * 1 ...   %Gain Maxon Amplifier [A/V]
									 * 253 ... %Torsional Constant [mNm/A]  RE63
									 ); 
                                

sim('two_virtual_wheel_analog')

clear torque_limit
for i = 1:length(tout)
   torque_limit(i) = motor_torque_max;
end
 
figure(1)
clf

plot(tout,yout(:,1),tout,yout(:,2),...
     tout,yout(:,3),tout,yout(:,4),tout,torque_limit,'k-',tout,-torque_limit,'k-')
xlabel('time, seconds')
h = title(['$k = $',num2str(k1),' Nmm/deg, $J_w = $',num2str(Jw1),' Nmm/(deg/sec$^2$), $f_n = $',num2str(f_n1,2),' Hz']);
set(h,'interpreter','latex','fontsize',14); 
h = legend('$\theta_{w1}$ (deg)','$d\theta_{w1}/dt$ (deg/sec)','torque$_{w1}$ (Nmm)', '$\theta_z$ (deg)','torque limit',3);
set(h,'interpreter','latex','fontsize',14); 
set(findall(gcf,'type','line'),'linewidth',2)
   
   
figure(2)
clf

plot(tout,yout(:,5),tout,yout(:,6),...
     tout,yout(:,7),tout,yout(:,4),tout,torque_limit,'k-',tout,-torque_limit,'k-')
 h = title(['$k = $',num2str(k2),' Nmm/deg, $J_w = $',num2str(Jw2),' Nmm/(deg/sec$^2$), $f_n = $',num2str(f_n2,2),' Hz']);
set(h,'interpreter','latex','fontsize',14); 
xlabel('time, seconds')
h = legend('$\theta_{w2}$ (deg)','$d\theta_{w2}/dt$ (deg/sec)','torque$_{w2}$ (Nmm)', '$\theta_z$ (deg)','torque limit',3);
set(h,'interpreter','latex','fontsize',14); 
set(findall(gcf,'type','line'),'linewidth',2)
   
figure(3)
clf

plot(tout,-yout(:,3)-yout(:,7),'-' ,tout,torque_limit,'k-',tout,-torque_limit,'k-')
h = title('reaction torque (analog model)');
set(h,'interpreter','latex','fontsize',14); 
xlabel('time, seconds')
%set(h,'interpreter','latex','fontsize',14); 
set(findall(gcf,'type','line'),'linewidth',2)

tsave = tout;ysave = yout(:,3)+yout(:,7);

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 

% sample time for slow subsystem
T1 = 1/50;
% add some damping to compensate for destabilizing effect of forward euler integration
b1 = T1*k1;

% sample time for fast subsystem
T2 = 1/500;
% add some damping to compensate for destabilizing effect of forward euler integration
b2 = T2*k2;

 


sim('two_virtual_wheel_discrete')

clear torque_limit
for i = 1:length(tout)
    torque_limit(i) = motor_torque_max;
end
 
figure(4)
clf

plot(theta1.time,theta1.signals.values,...
    theta1dot.time,theta1dot.signals.values,...
    wheel1_torque.time,wheel1_torque.signals.values,...
    tout,yout(:,1),...
    tout,torque_limit,'k-',tout,-torque_limit,'k-')
xlabel('time, seconds')
h = title(['$k = $',num2str(k1),' Nmm/deg, $J_w = $',num2str(Jw1),' Nmm/(deg/sec$^2$), $f_n = $',num2str(f_n1,2),' Hz']);
set(h,'interpreter','latex','fontsize',14); 
h = legend('$\theta_{w1}$ (deg)','$d\theta_{w1}/dt$ (deg/sec)','torque$_{w1}$ (Nmm)', '$\theta_z$ (deg)','torque limit',3);
set(h,'interpreter','latex','fontsize',14); 
set(findall(gcf,'type','line'),'linewidth',2)
   
figure(5)
clf

plot(tout,yout(:,2),...
    tout,yout(:,3),...
    tout,yout(:,4),...
    tout,yout(:,1),...
    tout,torque_limit,'k-',tout,-torque_limit,'k-')
xlabel('time, seconds')
h = title(['$k = $',num2str(k2),' Nmm/deg, $J_w = $',num2str(Jw2),' Nmm/(deg/sec$^2$), $f_n = $',num2str(f_n2,2),'$ Hz$']);
set(h,'interpreter','latex','fontsize',14); 
h = legend('$\theta_{w2}$ (deg)','$d\theta_{w2}/dt$ (deg/sec)','torque$_{w2}$ (Nmm)', '$\theta_z$ (deg)','torque limit',3);
set(h,'interpreter','latex','fontsize',14); 
set(findall(gcf,'type','line'),'linewidth',2)
   
   
figure(6)
clf


plot(tout,yout(:,5),'-' ,tout,torque_limit,'k-',tout,-torque_limit,'k-')
h = title('reaction torque (discrete model)');
set(h,'interpreter','latex','fontsize',14); 
xlabel('time, seconds')
set(findall(gcf,'type','line'),'linewidth',2)


 
 
