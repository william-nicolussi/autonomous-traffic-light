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
J = total_cost(v0, a0, sf, vf, 0, tf);
dJvf = diff(J, vf);
vf_sol = solve(dJvf==0, vf);
disp('Optimal passing velocity vf* = ');
pretty(vf_sol);

%% Export solution
final_opt_vel_pass_fun = matlabFunction(vf_sol,'Vars',[v0,a0,sf,tf],'File', fullfile(exportFolder,'final_opt_vel_pass.m'));
disp(['Final opt velocity to pass saved to: ' exportFolder]);

%% Determine the optimal time to reach to final velocity
syms z; % We create this variable for more stable solution of the equations
vf_sol_z = subs(vf_sol, tf, 1/z);
z_all = solve(vf_sol_z==vf,z);
z_sol = z_all(2);
t_vf_sol = 1/z_sol;
disp('Optimal time to reach to final velocity t_vf* = ');
pretty(t_vf_sol);

%% Export solution
final_opt_time_pass_fun = matlabFunction(t_vf_sol,'Vars',[v0,a0,sf,vf],'File', fullfile(exportFolder,'final_opt_time_pass.m'));
disp(['Final opt velocity to pass saved to: ' exportFolder]);

%% Determine the time to reach the minimum velocity and final velocity
T_star_all = solve(diff(vf_sol,tf)==0,tf);
T_star = simplify(T_star_all(1));
disp('Time to reach the minimum velocity T* = ');
pretty(T_star);

v_star = simplify(subs(vf_sol, tf, T_star));
disp('Value of final velocity v* = ');
pretty(v_star);

%% Export solutions
time_min_vel_fun = matlabFunction(T_star,'Vars',[a0,sf],'File', fullfile(exportFolder,'time_min_vel_pass.m'));
disp(['Time to reach the minimum velocity saved to: ' exportFolder]);
min_vel_fun = matlabFunction(v_star,'Vars',[v0,a0,sf],'File', fullfile(exportFolder,'min_vel.m'));
disp(['Value of minimum velocity saved to: ' exportFolder]);

