%%
%           Agent Logic
%         Pass Primitive
%              2025
%
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

%% Determine the optimal final velocity to pass
syms v0 a0 sf vf tf;
J = total_cost_var(v0, a0, sf, vf, 0, tf);
dJvf = diff(J, vf);
vf_sol = solve(dJvf==0, vf);
disp('Optimal passing velocity vf* = ');
pretty(vf_sol);
% - Use functions 'solve', 'diff', 'subs', and 'matlabFunction'

%% Determine the optimal final velocity to pass
%final_opt_vel_pass_var = solve(diff(subs(total_cost_var,af,0),vf)==0,vf);
%final_opt_vel_pass_fun = matlabfunction(final_opt_vel_pass_var,'Vars',[v0,a0,sf,T],'File','final_opt_vel_pass.m');
% - Use functions 'solve', 'diff', 'subs', and 'matlabFunction'

%% Export solution
final_opt_vel_pass_fun = matlabFunction(vf_sol,'Vars',[v0,a0,sf,tf],'File', fullfile(exportFolder,'final_opt_vel_pass.m'));
disp(['Final opt velocity to pass saved to: ' exportFolder]);

%% Determine the optimal time to reach to final velocity
syms z; % We create this variable for more stable solution of the equations
vf_sol_z = subs(vf_sol, tf, 1/z);
z_all = solve(vf_sol_z==vf,z);
z_sol = z_all(1);
t_vf_sol = 1/z_sol;
disp('Optimal time to reach to final velocity t_vf* = ');
pretty(t_vf_sol);
% - Use the function solve 
%   Use 'subs' function to solve the system using the frequency instead of the time

%% Export solution
final_opt_time_pass_fun = matlabFunction(t_vf_sol,'Vars',[v0,a0,sf,vf],'File', fullfile(exportFolder,'final_opt_time_pass.m'));
disp(['Final opt velocity to pass saved to: ' exportFolder]);

%% Determine the optimal time to reach to final velocity
%sym z; % We create this variable for more stable solution of the equations

% final_opt_time_pass_var = 1 / solve(subs(final_opt_vel_pass_var,T,1/z)==vf,z);
% final_opt_time_pass_fun = matlabfunction(final_opt_vel_pass_var(2),'Vars',[v0,a0,sf,T],'File','final_opt_time_pass.m');
% - Use the function solve 
%   Use 'subs' function to solve the system using the frequency instead of the time

%% Determine the time to reach the minimum velocity
syms v_min;
T_star_all = solve(diff(vf_sol,tf)==0,tf);
T_star = T_star_all(1);
disp('Time to reach the minimum velocity T* = ');
pretty(T_star);

%% Export solution
time_min_vel_fun = matlabFunction(T_star,'Vars',[v0,a0,sf,v_min],'File', fullfile(exportFolder,'time_min_vel_pass.m'));
disp(['Time to reach the minimum velocity saved to: ' exportFolder]);
% time_min_vel_var = solve(diff(final_opt_vel_pass_var,T)==0,T);
% time_min_vel_fun = matlabfunction(time_min_vel_var(2),'Vars',[a0,sf],'File','time_min_vel.m');
% - Use functions 'solve', 'diff', 'subs', and 'matlabFunction'
