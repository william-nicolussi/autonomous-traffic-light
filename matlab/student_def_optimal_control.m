%%
%             Agent Logic
%       Optimal Control Solution
%                2025
%
%%
clear; clc; close all

%% Define the folder to put the matlabfunctions
nameExportFolder = 'functions_exported';
currentFolder = pwd;
exportFolder = fullfile(currentFolder, nameExportFolder); %...\matlab\def_functions
if ~exist(exportFolder, 'dir')
    mkdir(exportFolder);
end
addpath(exportFolder);

%% Define a symbolic variables use "syms" (e.g. syms s(t)) and the cost function.
% Symbolic variables
syms s(t) v(t) a(t) u(t) l1(t) l2(t) l3(t);

% Explanation:
% s, v, a are states; u is the control (jerk); l1..l3 are costates (Lagrange multipliers).
% This structure follows your template and the standard Pontryagin setup.  (Derived here)

%% Define the system model by mean the relation between the variables. 
% Plant equations
ode1 = diff(s,t) == v;        % ds/dt = v
ode2 = diff(v,t) == a;        % dv/dt = a
ode3 = diff(a,t) == u;        % da/dt = u

%% Define the Lagrangian and the Hamiltonian.
% Lagrangian (minimum jerk): L = u(t)^2
L = u^2;

% Hamiltonian: H = L + lambda^T f(x,u)
% rhs() extracts the right-hand-side of each ODE to avoid retyping -> part
% after the '==' -> so it is v, a, u.
H = L + l1*rhs(ode1) + l2*rhs(ode2) + l3*rhs(ode3);

% Explanation:
% L = u^2 is the smoothness cost, and H = L + λ·f is the standard Pontryagin Hamiltonian.

%% Solve the optimal control problem (Solving the Hamiltonian). 
% - use "functionalDerivative()" to derive a function with respect to another function (e.g. du = functionalDerivative(H,u)) 
% - Use "solve" and "subs()" to replace variable inside the equation ->
% subs(du, u, opt_u) converts du=2*u(t)+l3 into du=2*opt_u+l3

% Derivative of Hamiltonian w.r.t. the control
du = functionalDerivative(H,u);   % ∂H/∂u = 2u + l3
syms opt_u;
% Optimal solution (stationarity): ∂H/∂u = 0  =>  2u + l3 = 0
opt_u = solve(subs(du,u(t),opt_u)==0,opt_u);        % opt_u = -l3/2

% Explanation:
% Stationarity condition gives the optimal jerk u* = -l3/2.

%% Write the second optimality condition.
% Second Optimality Condition
Dl1 = diff(l1,t) == -functionalDerivative(H,s);  % dl1/dt = 0
Dl2 = diff(l2,t) == -functionalDerivative(H,v);  % dl2/dt = -l1
Dl3 = diff(l3,t) == -functionalDerivative(H,a);  % dl3/dt = -l2
% - Use "diff(,t)" to derive w.r.t. the time 
%   and "functionalDerivative()" to detive w.r.t. a variable

%% Substitute the optimal solution opt_u to state equations
% New system equation
ode3s = diff(a,t) == subs(rhs(ode3), u, opt_u);        % da/dt = -l3/2
% - Replace the ode3 equation with the solution of the optimal control problem

%% Define the Boundary condition on initial state and Boundary condition on final state
% Boundary condition on initial and final states
ICs = 's(0)=0, v(0)=v0, a(0)=a0';
FCs = 's(T)=sf, v(T)=vf, a(T)=af'; %T is the final time
% - Write the condition as a string

%% Find the solution of the OCP imposing the boundary condition
% Solution of the optimal control problem
sol_opt = dsolve([ode1, ode2, ode3s, Dl1, Dl2, Dl3], ICs,FCs);
% - Use the function "dsolve([], , )" to obtain a solution of the optimal
%   control problem

disp('Optimal polynomial longitudinal position:');
pretty(sol_opt.s)

disp('Optimal polynomial velocity:');
pretty(sol_opt.v)

disp('Optimal polynomial acceleration:');
pretty(sol_opt.a)

% Assign to functions the solutions found

%% Get the optimal control solution
% Obtain optimal control solution
sol_opt.j = subs(opt_u, l3(t), sol_opt.l3);
% - Use the "subs" function on the opt_u with the value of l3

%% Export the solution in a matlab function
syms v0 a0 sf vf af T  
% Create the matlab function for the solutions
s_opt_fun = matlabFunction(sol_opt.s,'Vars',[t,v0,a0,sf,vf,af,T],'File', fullfile(exportFolder, 's_opt.m'));
v_opt_fun = matlabFunction(sol_opt.v,'Vars',[t,v0,a0,sf,vf,af,T],'File', fullfile(exportFolder,'v_opt.m'));
a_opt_fun = matlabFunction(sol_opt.a,'Vars',[t,v0,a0,sf,vf,af,T],'File', fullfile(exportFolder,'a_opt.m'));
j_opt_fun = matlabFunction(sol_opt.j,'Vars',[t,v0,a0,sf,vf,af,T],'File', fullfile(exportFolder,'j_opt.m'));
% - Use the matlabFunction function to generate a matlab function using a
%   symbolic function
disp(['Solution saved into: ' exportFolder]);

%% Create the matlab function for the solution using the coeffs
c = sym('c',[1 6]);

coeffs_s_opt = c(1)*t + (1/2)*c(2)*t^2 + (1/6)*c(3)*t^3 + (1/24)*c(4)*t^4 + (1/120)*c(5)*t^5;
coeffs_v_opt = diff(coeffs_s_opt, t);
coeffs_a_opt = diff(coeffs_v_opt, t);
coeffs_j_opt = diff(coeffs_a_opt, t);

coeffs_s_opt_fun = matlabFunction(coeffs_s_opt,'Vars',{t, c},'File', fullfile(exportFolder,'s_from_coeffs.m'));
coeffs_v_opt_fun = matlabFunction(coeffs_v_opt,'Vars',{t, c},'File', fullfile(exportFolder,'v_from_coeffs.m'));
coeffs_a_opt_fun = matlabFunction(coeffs_a_opt,'Vars',{t, c},'File', fullfile(exportFolder,'a_from_coeffs.m'));
coeffs_j_opt_fun = matlabFunction(coeffs_j_opt,'Vars',{t, c},'File', fullfile(exportFolder,'j_from_coeffs.m'));

disp(['Coeffs saved into: ' exportFolder]);

%% Export the coefficent list in a matlab function
% the coeffs are moltiplied by [1,2,6,24,120] to obtain the value of c1, c2, c3, c4, c5
coef_list_var = [0,coeffs(sol_opt.s,t) .* [1,2,6,24,120]];
coef_list_fun = matlabFunction(coef_list_var,'Vars',[v0,a0,sf,vf,af,T],'File',fullfile(exportFolder,'coef_list.m'));
% - Use the matlabFunction function to generate a matlab function using a symbolic function 
disp(['Coefs list saved into: ' exportFolder]);

%% Export the total cost in a matlab function 
total_cost_var = simplify(int(sol_opt.j^2,t,0,T));
total_cost_fun = matlabFunction(total_cost_var,'Vars',[v0,a0,sf,vf,af,T],'File', fullfile(exportFolder,'total_cost_var.m'));
% - Use the matlabFunction function to generate a matlab function using a
%   symbolic function
disp(['Total cost saved into: ' exportFolder]);

%% Inspect solutions 

T_max  = 4.;
t_list = linspace(0,T_max,100);

v0_val = 10;
a0_val = 1;
sf_val = 90;
vf_val = 25;
af_val = 0.;

%% The functions work both for vector (t_list) or number (t)
s_list = s_opt_fun(t_list, v0_val, a0_val, sf_val, vf_val, af_val, T_max);
v_list = v_opt_fun(t_list, v0_val, a0_val, sf_val, vf_val, af_val, T_max);
a_list = a_opt_fun(t_list, v0_val, a0_val, sf_val, vf_val, af_val, T_max);
j_list = j_opt_fun(t_list, v0_val, a0_val, sf_val, vf_val, af_val, T_max);

%% The functions that used the coeflist
coeffs = coef_list_fun(v0_val, a0_val, sf_val, vf_val, af_val, T_max);
% coeffs_s_list = coeffs_s_opt_fun(t_list, coeffs);
coeffs_s_list = s_from_coeffs(t_list, coeffs);
coeffs_v_list = v_from_coeffs(t_list, coeffs);
coeffs_a_list = a_from_coeffs(t_list, coeffs);
coeffs_j_list = j_from_coeffs(t_list, coeffs);

%% Plots
figure(1)
%We now plot all the variables in a single figure.

%% Position
subplot(2,4,1)
plot(t_list, s_list,'b');hold on;
plot(t_list, coeffs_s_list,'r--');
grid on
xlabel('Time (s)','Interpreter','latex');
ylabel('Position $(m)$','Interpreter','latex');
    
%% Velocity
subplot(2,4,2)
plot(t_list, v_list,'b');hold on;
plot(t_list, coeffs_v_list,'r--');
grid on
xlabel('Time (s)','Interpreter','latex');
ylabel('Velocity $(m/s)$','Interpreter','latex');
    
%% Acceleration
subplot(2,4,3)
plot(t_list, a_list,'b');hold on;
plot(t_list, coeffs_a_list,'r--');
grid on
xlabel('Time (s)','Interpreter','latex');
ylabel('Acceleration $(m/s^2)$','Interpreter','latex');

%% Control
subplot(2,4,4)
plot(t_list, j_list,'b'); hold on;
plot(t_list, coeffs_j_list,'r--');
grid on
xlabel('Time (s)','Interpreter','latex');
ylabel('Jerk $(m/s^3)$','Interpreter','latex');
    
%% Velocity on position
subplot(2,4,6)
plot(s_list, v_list,'b'); grid on
xlabel('Position $(m)$','Interpreter','latex');
ylabel('Velocity $(m/s)$','Interpreter','latex');

%% Acceleration on position
subplot(2,4,7)
plot(s_list, a_list,'b'); grid on
xlabel('Position $(m)$','Interpreter','latex');
ylabel('Acceleration $(m/s^2)$','Interpreter','latex');


%% Control on position
subplot(2,4,8)
plot(s_list, j_list,'b'); grid on
xlabel('Position $(m)$','Interpreter','latex');
ylabel('Jerk $(m/s^3)$','Interpreter','latex');