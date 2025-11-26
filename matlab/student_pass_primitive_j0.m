%#codegen
%%
%          Agent Logic
%         Pass Primitive J0
%              2025
%
%
%%
function [coeffs_j0, sf_j0, tf_j0] = student_pass_primitive_j0( v0, a0, sf, vf_min, vf_max)
    T1 = final_opt_time_j0_1(v0, a0, sf);
    v1 = final_opt_vel_j0(v0, a0, sf, T1);
    if vf_min<v1<vf_max
        coeffs_j0 = coef_list(v0, a0, sf, v1, 0., T1);
    else
        T2 = final_opt_time_j0_2(v0, a0, sf);
        v2 = final_opt_vel_j0(v0, a0, sf, T2);
        if vf_min<v2<vf_max
            coeffs_j0 = coef_list(v0, a0, sf, v2, 0., T2);
        else
            coeffs_j0 = [0., 0., 0., 0., 0., 0.];
        end
    end
end