%#codegen
%%
%           Agent Logic
%         Stop Primitive J0
%              2025
%
%
%%
function [coeffs_j0, sf_j0, tf_j0] = student_stop_primitive_j0(v0, a0)
    if v0>0 && a<0
        tf_j0 = final_opt_time_stop_j0(v0, a0);
        sf_j0 = final_opt_pos_j0(v0, a0, tf_j0);
        coeffs_j0 = coef_list_fun(v0, a0, sf_j0, 0., 0., tf_j0);
    else
        tf_j0 = 0.;
        sf_j0 = 0.;
        coeffs_j0 = [0., 0., 0., 0., 0., 0.];
    end
end