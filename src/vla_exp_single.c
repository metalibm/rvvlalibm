/**
 * generated using metalibm 1.1
 * sha1 git: b'"3a8e11d7eeadc3f3fd42553299da0f20a23ba55d"'(clean)
 *
 * INFO: git status was clean when file was generated.
 *
 * command used for generation:
 *   ../metalibm_functions/vla_function.py --extra-passes \
 *     optimization:table_linearization,optimization:basic_legalization,optimization:virtual_scalar_bool_legalization,optimization:fuse_fma,beforecodegen:rvv_legalization \
 *     --target rv64gv --precision single --function exp --output \
 *     vla_exp_single.c --fname vla_exp_single
 *
 */
#include <riscv_vector.h>


void vla_exp_single(float* dst, float* src, uint32_t len){
    int32_t remLen;
    int32_t offset;
    
    remLen = len;
    offset = UINT32_C(0);

    for (;(remLen > INT32_C(0));){
        size_t l;
        size_t tmp;
        vfloat32m1_t vec_x;
        float* tmp1;
        vfloat32m1_t varg;
        vfloat32m1_t unround_k;
        vint32m1_t ik;
        vint32m1_t tmp2;
        vint32m1_t tmp3;
        vfloat32m1_t exp_ik;
        vint32m1_t tmp4;
        vfloat32m1_t tmp5;
        vfloat32m1_t exact_hi;
        vfloat32m1_t tmp6;
        vfloat32m1_t exact_lo;
        vfloat32m1_t r;
        vfloat32m1_t r2_;
        vfloat32m1_t r3_;
        vfloat32m1_t tmp7;
        vfloat32m1_t tmp8;
        vfloat32m1_t tmp9;
        vfloat32m1_t tmp10;
        vfloat32m1_t tmp11;
        vfloat32m1_t tmp12;
        vfloat32m1_t tmp13;
        vfloat32m1_t tmp14;
        vfloat32m1_t pre_sub_poly;
        vfloat32m1_t tmp15;
        vfloat32m1_t tmp16;
        vfloat32m1_t tmp17;
        vfloat32m1_t std_result;
        float* tmp18;
        int32_t tmp19;
        int32_t tmp20;
        int32_t tmp21;

        tmp = vsetvl_e32m1(remLen);
        l = tmp;
        tmp1 = src + offset;
        varg = vle32_v_f32m1(tmp1, l);
        vec_x = varg;
        unround_k = vfmul_vf_f32m1(vec_x, 0x1.715476p0f, l);
        ik = vfcvt_x_f_v_i32m1(unround_k, l);
        tmp2 = vadd_vx_i32m1(ik, INT32_C(127), l);
        tmp3 = vsll_vx_i32m1(tmp2, INT32_C(23), l);
        exp_ik = vreinterpret_v_i32m1_f32m1(tmp3);
        tmp4 = vfcvt_x_f_v_i32m1(unround_k, l);
        tmp5 = vfcvt_f_x_v_f32m1(tmp4, l);
        exact_hi = vfnmsub_vf_f32m1(tmp5, 0x1.62ep-1f, vec_x, l);
        tmp6 = vfneg_v_f32m1(tmp5, l);
        exact_lo = vfmul_vf_f32m1(tmp6, 0x1.0bfbe8p-15f, l);
        r = vfadd_vv_f32m1(exact_hi, exact_lo, l);
        r2_ = vfmul_vv_f32m1(r, r, l);
        r3_ = vfmul_vv_f32m1(r, r2_, l);
        tmp7 = vfmul_vf_f32m1(r2_, 0x1.6d6748p-10f, l);
        tmp8 = vfmul_vv_f32m1(r, tmp7, l);
        tmp9 = vfmadd_vf_f32m1(r2_, 0x1.123d02p-7f, tmp8, l);
        tmp10 = vfmul_vf_f32m1(r2_, 0x1.5554cep-5f, l);
        tmp11 = vfmul_vf_f32m1(r2_, 0x1.55548cp-3f, l);
        tmp12 = vfmul_vv_f32m1(r, tmp11, l);
        tmp13 = vfmadd_vf_f32m1(r2_, 0x1p-1f, tmp12, l);
        tmp14 = vfmadd_vv_f32m1(r2_, tmp10, tmp13, l);
        pre_sub_poly = vfmadd_vv_f32m1(r3_, tmp9, tmp14, l);
        tmp15 = vfadd_vv_f32m1(exact_lo, pre_sub_poly, l);
        tmp16 = vfadd_vv_f32m1(exact_hi, tmp15, l);
        tmp17 = vfadd_vf_f32m1(tmp16, 1.0f, l);
        std_result = vfmul_vv_f32m1(exp_ik, tmp17, l);
        tmp18 = dst + offset;
        vse32_v_f32m1(tmp18, std_result, l);
        tmp19 =  (int32_t) l;
        tmp20 = remLen - tmp19;
        remLen = tmp20;
        tmp21 = offset + tmp19;
        offset = tmp21;
    }
}
