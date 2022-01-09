/**
 * generated using metalibm 1.1
 * sha1 git: b'"3a8e11d7eeadc3f3fd42553299da0f20a23ba55d"'(clean)
 *
 * INFO: git status was clean when file was generated.
 *
 * command used for generation:
 *   ../metalibm_functions/vla_function.py --extra-passes \
 *     optimization:table_linearization,optimization:basic_legalization,optimization:virtual_scalar_bool_legalization,optimization:fuse_fma,beforecodegen:rvv_legalization \
 *     --target rv64gv --precision double --function exp --output \
 *     vla_exp_double.c --fname vla_exp_double
 *
 */
#include <riscv_vector.h>


void vla_exp_double(double* dst, double* src, uint32_t len){
    int32_t remLen;
    int32_t offset;
    
    remLen = len;
    offset = UINT32_C(0);

    for (;(remLen > INT32_C(0));){
        size_t l;
        size_t tmp;
        vfloat64m1_t vec_x;
        double* tmp1;
        vfloat64m1_t varg;
        vfloat64m1_t unround_k;
        vint64m1_t ik;
        vint64m1_t tmp2;
        vint64m1_t tmp3;
        vfloat64m1_t exp_ik;
        vint64m1_t tmp4;
        vfloat64m1_t tmp5;
        vfloat64m1_t exact_hi;
        vfloat64m1_t tmp6;
        vfloat64m1_t exact_lo;
        vfloat64m1_t r;
        vfloat64m1_t r2_;
        vfloat64m1_t r4_;
        vfloat64m1_t r5_;
        vfloat64m1_t r3_;
        vfloat64m1_t tmp7;
        vfloat64m1_t tmp8;
        vfloat64m1_t tmp9;
        vfloat64m1_t tmp10;
        vfloat64m1_t tmp11;
        vfloat64m1_t tmp12;
        vfloat64m1_t tmp13;
        vfloat64m1_t tmp14;
        vfloat64m1_t tmp15;
        vfloat64m1_t tmp16;
        vfloat64m1_t tmp17;
        vfloat64m1_t tmp18;
        vfloat64m1_t tmp19;
        vfloat64m1_t tmp20;
        vfloat64m1_t tmp21;
        vfloat64m1_t tmp22;
        vfloat64m1_t tmp23;
        vfloat64m1_t tmp24;
        vfloat64m1_t pre_sub_poly;
        vfloat64m1_t tmp25;
        vfloat64m1_t tmp26;
        vfloat64m1_t tmp27;
        vfloat64m1_t std_result;
        double* tmp28;
        int32_t tmp29;
        int32_t tmp30;
        int32_t tmp31;

        tmp = vsetvl_e64m1(remLen);
        l = tmp;
        tmp1 = src + offset;
        varg = vle64_v_f64m1(tmp1, l);
        vec_x = varg;
        unround_k = vfmul_vf_f64m1(vec_x, 0x1.71547652b82fep0, l);
        ik = vfcvt_x_f_v_i64m1(unround_k, l);
        tmp2 = vadd_vx_i64m1(ik, INT64_C(1023), l);
        tmp3 = vsll_vx_i64m1(tmp2, INT64_C(52), l);
        exp_ik = vreinterpret_v_i64m1_f64m1(tmp3);
        tmp4 = vfcvt_x_f_v_i64m1(unround_k, l);
        tmp5 = vfcvt_f_x_v_f64m1(tmp4, l);
        exact_hi = vfnmsub_vf_f64m1(tmp5, 0x1.62e42fefa4p-1, vec_x, l);
        tmp6 = vfneg_v_f64m1(tmp5, l);
        exact_lo = vfmul_vf_f64m1(tmp6, -0x1.8432a1b0e2634p-43, l);
        r = vfadd_vv_f64m1(exact_hi, exact_lo, l);
        r2_ = vfmul_vv_f64m1(r, r, l);
        r4_ = vfmul_vv_f64m1(r2_, r2_, l);
        r5_ = vfmul_vv_f64m1(r, r4_, l);
        r3_ = vfmul_vv_f64m1(r, r2_, l);
        tmp7 = vfmul_vf_f64m1(r2_, 0x1.af7996ac10bccp-26, l);
        tmp8 = vfmul_vv_f64m1(r, tmp7, l);
        tmp9 = vfmadd_vf_f64m1(r2_, 0x1.28b437c81e5c5p-22, tmp8, l);
        tmp10 = vfmul_vf_f64m1(r2_, 0x1.71dde791e78c7p-19, l);
        tmp11 = vfmul_vf_f64m1(r2_, 0x1.a019916618836p-16, l);
        tmp12 = vfmul_vv_f64m1(r, tmp11, l);
        tmp13 = vfmadd_vf_f64m1(r2_, 0x1.a01a01b744dbfp-13, tmp12, l);
        tmp14 = vfmadd_vv_f64m1(r2_, tmp10, tmp13, l);
        tmp15 = vfmadd_vv_f64m1(r3_, tmp9, tmp14, l);
        tmp16 = vfmul_vf_f64m1(r2_, 0x1.6c16c188207c6p-10, l);
        tmp17 = vfmul_vv_f64m1(r, tmp16, l);
        tmp18 = vfmadd_vf_f64m1(r2_, 0x1.111111110e174p-7, tmp17, l);
        tmp19 = vfmul_vf_f64m1(r2_, 0x1.555555554efbbp-5, l);
        tmp20 = vfmul_vf_f64m1(r2_, 0x1.555555555555ep-3, l);
        tmp21 = vfmul_vv_f64m1(r, tmp20, l);
        tmp22 = vfmadd_vf_f64m1(r2_, 0x1.0000000000011p-1, tmp21, l);
        tmp23 = vfmadd_vv_f64m1(r2_, tmp19, tmp22, l);
        tmp24 = vfmadd_vv_f64m1(r3_, tmp18, tmp23, l);
        pre_sub_poly = vfmadd_vv_f64m1(r5_, tmp15, tmp24, l);
        tmp25 = vfadd_vv_f64m1(exact_lo, pre_sub_poly, l);
        tmp26 = vfadd_vv_f64m1(exact_hi, tmp25, l);
        tmp27 = vfadd_vf_f64m1(tmp26, 1.0, l);
        std_result = vfmul_vv_f64m1(exp_ik, tmp27, l);
        tmp28 = dst + offset;
        vse64_v_f64m1(tmp28, std_result, l);
        tmp29 =  (int32_t) l;
        tmp30 = remLen - tmp29;
        remLen = tmp30;
        tmp31 = offset + tmp29;
        offset = tmp31;
    }
}
