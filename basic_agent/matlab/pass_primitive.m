%#codegenvfmin
%%
%           Agent Logic
%         Pass Primitive
%              2025
%
%
%%

function [m1, v1, T1, m2, v2, T2] = pass_primitive(v0, a0, sf, v_min, v_max, T_min, T_max)
    if a0 >= 0
        Tv_min = final_opt_time_pass(v0, a0, sf, v_min);
        Tv_max = final_opt_time_pass(v0, a0, sf, v_max);
    else
        T_star = time_min_vel_pass(a0, sf);
        v_star = min_vel(v0, a0, sf);
        if (v_star < v_min) && (v_min <= v_max)
            Tv_min = final_opt_time_pass(v0, a0, sf, v_min);
            Tv_max = final_opt_time_pass(v0, a0, sf, v_max);
        elseif (v_min < v_star) && (v_star < v_max)
            Tv_min = T_star;
            Tv_max = final_opt_time_pass(v0, a0, sf, v_max);
        else
            Tv_min = 0.;
            Tv_max = 0.;
        end
    end

    %    [T1, T2] = [T_min, T_max] ∩ [Tvmax, Tvmin]
    if (T_min==0.) && (T_max==0.)
        T1 = Tv_max;
        T2 = Tv_min;
    else
        T1 = max(T_min, Tv_max);
        T2 = min(T_max, Tv_min);
    end

    if (0 < T1) && (T1 <= T2)
        v1 = final_opt_vel_pass(v0, a0, sf, T2);
        v2 = final_opt_vel_pass(v0, a0, sf, T1);
        m1 = coef_list(v0, a0, sf, v2, 0., T1);
        m2 = coef_list(v0, a0, sf, v1, 0., T2);
    else
        v1 = 0.;
        v2 = 0.;
        m1 = zeros(1,6);
        m2 = zeros(1,6);
        T1 = 0.;
        T2 = 0.;
    end
end
