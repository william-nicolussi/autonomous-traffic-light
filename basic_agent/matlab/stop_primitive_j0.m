%#codegen
%%
%           Agent Logic
%         Stop Primitive J0
%              2025
%
%
%%
function [m, sf_j0, tf_j0] = stop_primitive_j0(v0, a0)
    if (v0>0) && (a0<0)
        tf_j0 = final_opt_time_stop_j0(v0, a0);
        sf_j0 = final_opt_pos_j0(v0, a0, tf_j0);
        m = coef_list(v0, a0, sf_j0, 0., 0., tf_j0);
    else
        tf_j0 = 0.;
        sf_j0 = 0.;
        m = zeros(1,6);
    end
end