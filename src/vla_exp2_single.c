/**
 * generated using metalibm 1.1
 * sha1 git: b'"3a8e11d7eeadc3f3fd42553299da0f20a23ba55d"'(clean)
 *
 * INFO: git status was clean when file was generated.
 *
 * command used for generation:
 *   ../metalibm_functions/vla_function.py --extra-passes \
 *     optimization:table_linearization,optimization:basic_legalization,optimization:virtual_scalar_bool_legalization,optimization:fuse_fma,beforecodegen:rvv_legalization \
 *     --target rv64gv --precision single --function exp2 --output \
 *     vla_exp2_single.c --fname vla_exp2_single
 *
 */
#include <riscv_vector.h>


static const float ml_exp2_exp2_table[9]  = {
     0x1p0f, 0x1.172b84p0f, 0x1.306fep0f, 0x1.4bfdaep0f, 0x1.6a09e6p0f,
     0x1.8ace54p0f, 0x1.ae89fap0f, 0x1.d5818ep0f, 0x1p1f
};

void vla_exp2_single(float* dst, float* src, uint32_t len){
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
        vint32m1_t tmp2;
        vfloat32m1_t tmp3;
        vfloat32m1_t vx_r;
        vfloat32m1_t tmp4;
        vint32m1_t tmp5;
        vfloat32m1_t tmp6;
        vint32m1_t r_hi_int;
        vint32m1_t tmp7;
        vint32m1_t tmp8;
        vint32m1_t tmp9;
        vuint32m1_t tmp10;
        vfloat32m1_t hi_part_value;
        vint32m1_t vx_int;
        vint32m1_t tmp11;
        vint32m1_t tmp12;
        vfloat32m1_t exp_X;
        vfloat32m1_t tmp13;
        vfloat32m1_t r_lo;
        vfloat32m1_t tmp14;
        vfloat32m1_t pa_5;
        vfloat32m1_t tmp15;
        vfloat32m1_t pa_4;
        vfloat32m1_t tmp16;
        vfloat32m1_t pa_3;
        vfloat32m1_t tmp17;
        vfloat32m1_t pa_2;
        vfloat32m1_t tmp18;
        vfloat32m1_t tmp19;
        vfloat32m1_t poly;
        vfloat32m1_t tmp20;
        vfloat32m1_t result;
        float* tmp21;
        int32_t tmp22;
        int32_t tmp23;
        int32_t tmp24;

        tmp = vsetvl_e32m1(remLen);
        l = tmp;
        tmp1 = src + offset;
        varg = vle32_v_f32m1(tmp1, l);
        vec_x = varg;
        tmp2 = vfcvt_rtz_x_f_v_i32m1(vec_x, l);
        tmp3 = vfcvt_f_x_v_f32m1(tmp2, l);
        vx_r = vfsub_vv_f32m1(vec_x, tmp3, l);
        tmp4 = vfmul_vf_f32m1(vx_r, 8.0f, l);
        tmp5 = vfcvt_x_f_v_i32m1(tmp4, l);
        tmp6 = vfcvt_f_x_v_f32m1(tmp5, l);
        r_hi_int = vfcvt_x_f_v_i32m1(tmp6, l);
        tmp7 = vmin_vx_i32m1(r_hi_int, INT32_C(9), l);
        tmp8 = vmax_vx_i32m1(tmp7, INT32_C(0), l);
        tmp9 = vmul_vx_i32m1(tmp8, INT32_C(4), l);
        tmp10 = vreinterpret_v_i32m1_u32m1(tmp9);
        hi_part_value = vluxei32_v_f32m1(ml_exp2_exp2_table, tmp10, l);
        vx_int = vfcvt_x_f_v_i32m1(tmp3, l);
        tmp11 = vadd_vx_i32m1(vx_int, INT32_C(127), l);
        tmp12 = vsll_vx_i32m1(tmp11, INT32_C(23), l);
        exp_X = vreinterpret_v_i32m1_f32m1(tmp12);
        tmp13 = vfmul_vv_f32m1(hi_part_value, exp_X, l);
        r_lo = vfnmsub_vf_f32m1(tmp6, 0.125f, vx_r, l);
        tmp14 = vfmv_v_f_f32m1(0x1.62554ap-10f, l);
        pa_5 = vfmadd_vf_f32m1(r_lo, 0x1.45fcf6p-13f, tmp14, l);
        tmp15 = vfmv_v_f_f32m1(0x1.3b2a6cp-7f, l);
        pa_4 = vfmadd_vv_f32m1(r_lo, pa_5, tmp15, l);
        tmp16 = vfmv_v_f_f32m1(0x1.c6afbap-5f, l);
        pa_3 = vfmadd_vv_f32m1(r_lo, pa_4, tmp16, l);
        tmp17 = vfmv_v_f_f32m1(0x1.ebfbep-3f, l);
        pa_2 = vfmadd_vv_f32m1(r_lo, pa_3, tmp17, l);
        tmp18 = vfmv_v_f_f32m1(0x1.62e43p-1f, l);
        tmp19 = vfmadd_vv_f32m1(r_lo, pa_2, tmp18, l);
        poly = vfmul_vv_f32m1(r_lo, tmp19, l);
        tmp20 = vfmul_vv_f32m1(hi_part_value, exp_X, l);
        result = vfmadd_vv_f32m1(tmp13, poly, tmp20, l);
        tmp21 = dst + offset;
        vse32_v_f32m1(tmp21, result, l);
        tmp22 =  (int32_t) l;
        tmp23 = remLen - tmp22;
        remLen = tmp23;
        tmp24 = offset + tmp22;
        offset = tmp24;
    }
}
