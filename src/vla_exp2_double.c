/**
 * generated using metalibm 1.1
 * sha1 git: b'"3a8e11d7eeadc3f3fd42553299da0f20a23ba55d"'(clean)
 *
 * INFO: git status was clean when file was generated.
 *
 * command used for generation:
 *   ../metalibm_functions/vla_function.py --extra-passes \
 *     optimization:table_linearization,optimization:basic_legalization,optimization:virtual_scalar_bool_legalization,optimization:fuse_fma,beforecodegen:rvv_legalization \
 *     --target rv64gv --precision double --function exp2 --output \
 *     vla_exp2_double.c --fname vla_exp2_double
 *
 */
#include <riscv_vector.h>


static const double ml_exp2_exp2_table[9]  = {
     0x1p0, 0x1.172b83c7d517bp0, 0x1.306fe0a31b715p0, 0x1.4bfdad5362a27p0,
     0x1.6a09e667f3bcdp0, 0x1.8ace5422aa0dbp0, 0x1.ae89f995ad3adp0,
     0x1.d5818dcfba487p0, 0x1p1
};

void vla_exp2_double(double* dst, double* src, uint32_t len){
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
        vint64m1_t tmp2;
        vfloat64m1_t tmp3;
        vfloat64m1_t vx_r;
        vfloat64m1_t tmp4;
        vint64m1_t tmp5;
        vfloat64m1_t tmp6;
        vint64m1_t r_hi_int;
        vint64m1_t tmp7;
        vint64m1_t tmp8;
        vint64m1_t tmp9;
        vuint64m1_t tmp10;
        vfloat64m1_t hi_part_value;
        vint64m1_t vx_int;
        vint64m1_t tmp11;
        vint64m1_t tmp12;
        vfloat64m1_t exp_X;
        vfloat64m1_t tmp13;
        vfloat64m1_t r_lo;
        vfloat64m1_t tmp14;
        vfloat64m1_t pa_9;
        vfloat64m1_t tmp15;
        vfloat64m1_t pa_8;
        vfloat64m1_t tmp16;
        vfloat64m1_t pa_7;
        vfloat64m1_t tmp17;
        vfloat64m1_t pa_6;
        vfloat64m1_t tmp18;
        vfloat64m1_t pa_5;
        vfloat64m1_t tmp19;
        vfloat64m1_t pa_4;
        vfloat64m1_t tmp20;
        vfloat64m1_t pa_3;
        vfloat64m1_t tmp21;
        vfloat64m1_t pa_2;
        vfloat64m1_t tmp22;
        vfloat64m1_t tmp23;
        vfloat64m1_t poly;
        vfloat64m1_t tmp24;
        vfloat64m1_t result;
        double* tmp25;
        int32_t tmp26;
        int32_t tmp27;
        int32_t tmp28;

        tmp = vsetvl_e64m1(remLen);
        l = tmp;
        tmp1 = src + offset;
        varg = vle64_v_f64m1(tmp1, l);
        vec_x = varg;
        tmp2 = vfcvt_rtz_x_f_v_i64m1(vec_x, l);
        tmp3 = vfcvt_f_x_v_f64m1(tmp2, l);
        vx_r = vfsub_vv_f64m1(vec_x, tmp3, l);
        tmp4 = vfmul_vf_f64m1(vx_r, 8.0, l);
        tmp5 = vfcvt_x_f_v_i64m1(tmp4, l);
        tmp6 = vfcvt_f_x_v_f64m1(tmp5, l);
        r_hi_int = vfcvt_x_f_v_i64m1(tmp6, l);
        tmp7 = vmin_vx_i64m1(r_hi_int, INT64_C(9), l);
        tmp8 = vmax_vx_i64m1(tmp7, INT64_C(0), l);
        tmp9 = vmul_vx_i64m1(tmp8, INT64_C(8), l);
        tmp10 = vreinterpret_v_i64m1_u64m1(tmp9);
        hi_part_value = vluxei64_v_f64m1(ml_exp2_exp2_table, tmp10, l);
        vx_int = vfcvt_x_f_v_i64m1(tmp3, l);
        tmp11 = vadd_vx_i64m1(vx_int, INT64_C(1023), l);
        tmp12 = vsll_vx_i64m1(tmp11, INT64_C(52), l);
        exp_X = vreinterpret_v_i64m1_f64m1(tmp12);
        tmp13 = vfmul_vv_f64m1(hi_part_value, exp_X, l);
        r_lo = vfnmsub_vf_f64m1(tmp6, 0.125, vx_r, l);
        tmp14 = vfmv_v_f_f64m1(0x1.9de07f01b20bep-24, l);
        pa_9 = vfmadd_vf_f64m1(r_lo, 0x1.1907a8c1c78c1p-27, tmp14, l);
        tmp15 = vfmv_v_f_f64m1(0x1.62bcf28aeda6cp-20, l);
        pa_8 = vfmadd_vv_f64m1(r_lo, pa_9, tmp15, l);
        tmp16 = vfmv_v_f_f64m1(0x1.ffcdc44bc06d7p-17, l);
        pa_7 = vfmadd_vv_f64m1(r_lo, pa_8, tmp16, l);
        tmp17 = vfmv_v_f_f64m1(0x1.4309131068c2ap-13, l);
        pa_6 = vfmadd_vv_f64m1(r_lo, pa_7, tmp17, l);
        tmp18 = vfmv_v_f_f64m1(0x1.5d87fe6c9eeadp-10, l);
        pa_5 = vfmadd_vv_f64m1(r_lo, pa_6, tmp18, l);
        tmp19 = vfmv_v_f_f64m1(0x1.3b2ab6fba44fep-7, l);
        pa_4 = vfmadd_vv_f64m1(r_lo, pa_5, tmp19, l);
        tmp20 = vfmv_v_f_f64m1(0x1.c6b08d704a8c5p-5, l);
        pa_3 = vfmadd_vv_f64m1(r_lo, pa_4, tmp20, l);
        tmp21 = vfmv_v_f_f64m1(0x1.ebfbdff82c58fp-3, l);
        pa_2 = vfmadd_vv_f64m1(r_lo, pa_3, tmp21, l);
        tmp22 = vfmv_v_f_f64m1(0x1.62e42fefa39efp-1, l);
        tmp23 = vfmadd_vv_f64m1(r_lo, pa_2, tmp22, l);
        poly = vfmul_vv_f64m1(r_lo, tmp23, l);
        tmp24 = vfmul_vv_f64m1(hi_part_value, exp_X, l);
        result = vfmadd_vv_f64m1(tmp13, poly, tmp24, l);
        tmp25 = dst + offset;
        vse64_v_f64m1(tmp25, result, l);
        tmp26 =  (int32_t) l;
        tmp27 = remLen - tmp26;
        remLen = tmp27;
        tmp28 = offset + tmp26;
        offset = tmp28;
    }
}
