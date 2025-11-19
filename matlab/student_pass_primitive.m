%#codegenvfmin
%%
%           Agent Logic
%         Pass Primitive
%              2025
%
%
%%

function [coeffsT2, v2, T2, coeffsT1, v1, T1] = student_pass_primitive(v0, a0, sf, vf_min, vf_max, T_min, T_max)
    if a0>=0
        Tv_min = final_opt_time_pass(v0, a0, sf, vf_min);
        Tv_max = final_opt_time_pass(v0, a0, sf, vf_max);
    else
        T_star = time_min_vel_pass(a0, sf);
        v_star = min_vel(v0, a0, sf);
        if (v_star < vf_min) && (vf_min < vf_max)
            Tv_min = final_opt_time_pass(v0, a0, sf, vf_min);
            Tv_max = final_opt_time_pass(v0, a0, sf, vf_max);
        elseif (vf_min < v_star) && (v_star < vf_max)
            Tv_min = T_star;
            Tv_max = final_opt_time_pass(v0, a0, sf, vf_max);
        else
            Tv_min = 0.;
            Tv_max = 0.;
        end
    end

    %    [T1, T2] = [T_min, T_max] ∩ [Tvmax, Tvmin]
    if (T_min==0.) && (T_max==0.)
        T1 = Tv_min;
        T2 = Tv_max;
    else
        T1 = max(T_min, Tv_max);
        T2 = min(T_max, Tv_min);
    end

    if (0 < T1) && (T1 <= T2)
        v1 = final_opt_vel_pass(v0, a0, sf, T2);
        v2 = final_opt_vel_pass(v0, a0, sf, T1);
        coeffsT1 = coef_list(v0, a0, sf, v2, 0., T1);
        coeffsT2 = coef_list(v0, a0, sf, v1, 0., T2);
    else
        v1 = 0.;
        v2 = 0.;
        coeffsT1 = [0., 0., 0., 0., 0., 0.];
        coeffsT2 = [0., 0., 0., 0., 0., 0.];
        T1 = 0.;
        T2 = 0.;
    end
end
