%#codegen
%%vf_min
%          Agent Logic
%         Pass Primitive J0
%              2025
%
%
%%
function [m, sf_j0, tf_j0] = pass_primitive_j0(v0, a0, sf, v_min, v_max)
    T1 = final_opt_time_j0_1(v0, a0, sf);
    v1 = final_opt_vel_j0(v0, a0, sf, T1);
    if (v_min<v1) && (v1<v_max)
        tf_j0 = T1;
        sf_j0 = v1; % (?)
        m = coef_list(v0, a0, sf, v1, 0., T1);
    else
        T2 = final_opt_time_j0_2(v0, a0, sf);
        v2 = final_opt_vel_j0(v0, a0, sf, T2);
        if (v_min<v2) && (v2<v_max)
            m = coef_list(v0, a0, sf, v2, 0., T2);
            sf_j0 = v2;
            tf_j0 = T2;
        else
            m = zeros(1,6);
            sf_j0 = 0.;
            tf_j0 = 0.;
        end
    end
end

% sf_j0 (?)
% tf_j0 (?)