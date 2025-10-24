%#codegen
%%
%          Agent Logic
%         Stop Primitive
%              2025
%
%

%% Function
% This function must to be converted in c code using coder add-on.
% Copy from this path C:\Program Files\MATLAB\R2024a\extern\include

%% Stopping Primitive

function [coefs,maxsf,tf] = student_stop_primitive(v0,a0,sf)
    if v0<=0 || sf==0  % --- Early exits ---
        maxsf = 0;
        tf = 0.;
        coefs=[0,0,0,0,0,0];
        return
    end
    if 4*v0^2+5*a0*sf<0  % --- Unfeasible case ---
        maxsf = - (4*v0^2)/(5*a0);
        tf = (10*maxsf)/(2*v0);
    else  % --- Feasible case ---
        maxsf = sf;
        tf = final_opt_time_stop(v0, a0, maxsf);
    end
    coefs = coef_list(v0,a0,maxsf,0,0,tf);
end