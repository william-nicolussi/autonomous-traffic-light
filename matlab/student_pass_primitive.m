%#codegen
%%
%           Agent Logic
%         Pass Primitive
%              2025
%
%
%%

function [coeffsT2, v2, T2, coeffsT1, v1, T1] = student_pass_primitive(v0, a0, sf, vfmin, vfmax, Tmin, Tmax)
    if a0>=0
        Tv_min = final_opt_time_pass(v0,a0,sf,vfmin);
        Tv_max = final_opt_time_pass(v0,a0,sf,vfmax);
    else
        T_star = sqrt((15*sf)/(-a0));
        v_star = 1/8 * (2*sqrt(15)*sqrt(-a0*sf)-7*v0);
        if (v_star < vfmin) && (vfmin < vfmax)
            Tv_min = final_opt_time_pass(v0,a0,sf,vfmin);
            Tv_max = final_opt_time_pass(v0,a0,sf,vfmax);
        elseif (vfmin < v_star) && (v_star < vfmax)
            Tv_min = T_star;
            Tv_max = final_opt_time_pass(v0,a0,sf,vfmax);
        else
            Tv_min = 0;
            Tv_max = 0;
        end
    end
    %    [T1, T2] = [Tmin, Tmax] ∩ [Tvmax, Tvmin]
    T1 = max(Tmin, Tv_max);
    T2 = min(Tmax, Tv_min);

    if (0 < T1) && (T1 <= T2)
        v1 = final_opt_vel_pass(v0,a0,sf,T2);
        v2 = final_opt_vel_pass(v0,a0,sf,T1);
        coeffsT1 = coef_list(v0,a0,sf,v2,0,T1);
        coeffsT2 = coef_list(v0,a0,sf,v1,0,T2);
    else
        coeffsT1 = [0,0,0,0,0,0];
        coeffsT2 = [0,0,0,0,0,0];
    end
end
