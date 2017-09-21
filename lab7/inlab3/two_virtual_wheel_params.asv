% Simulates the motion of a haptic wheel attached to a virtual wheel whose
% rotational intertia is J_w. The wheels are attached through a shaft
% with torsional spring constant k. 
% The simulation assumes that the wheel is turned through a fixed initial angle
% and then held constant.


Deltat = .0001;          % simulation step size    (seconds)  -- should be small with respect to T_n

tfinal = 5;             % final time for simulation (seconds)


% set parameters so that slow subsystem has frequency 1 Hz
% and so that total reaction torque does not exceed limit
k1 = .5*15;       % spring constant in N-mm/degree
Jw1 = .5*1.5/4;   % rotational inertia in N-mm/(degree/sec^2)



T1 = 1/50;   % sample time for first (slow) system in seconds
b1 =T1*k1;   % value of damping that cancels the destabilizing effects of forward euler 

% set parameters so that slow subsystem has frequency 10 Hz
k2 = .5*15;           % spring constant in N-mm/degree
% Jw2 = .5*.015/4;      % rotational inertia in N-mm/(degree/sec^2)
Jw2 =  0.1462;      % rotational inertia in N-mm/(degree/sec^2)

T2 = 1/500;  % sample time for second (fast) system in seconds
b2 =T2*k2;   % value of damping that cancels the destabilizing effects of forward euler 
 

step_time = 1;     % time of step change in wheel position (seconds)
Theta_z_0 = 45;    % size of step change in wheel position (degrees) = theta_z_0

max_torque = k1*45;   % N-mm

omega_n1 = sqrt(k1/Jw1);   % frequency of oscillation in rad/sec
f_n1 = omega_n1/(2*pi);    % frequency of oscillation in Hz
T_n1 = 1/f_n1;             % period of oscillation in seconds

omega_n2 = sqrt(k2/Jw2);   % frequency of oscillation in rad/sec
f_n2 = omega_n2/(2*pi);    % frequency of oscillation in Hz
T_n2 = 1/f_n2;             % period of oscillation in seconds


% compute torque limits in N-mm at wheel

dutycycle_max = .76;
motor_torque_max = (dutycycle_max-.5)*(5 ...   %Peak Voltage PWM [V] 
					                 * 2.5 ... %Gain Demodulator [V/V]  
									 * 1 ...   %Gain Maxon Amplifier [A/V]
									 * 257 ... %Torsional Constant [mNm/A]  RE63
									 ); 
wheel_torque_max = motor_torque_max;       % no gear transmission ratio

