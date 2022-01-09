/**
 * generated using metalibm 1.1
 * sha1 git: b'"3a8e11d7eeadc3f3fd42553299da0f20a23ba55d"'(clean)
 *
 * INFO: git status was clean when file was generated.
 *
 * command used for generation:
 *   ../metalibm_functions/vla_function.py --extra-passes \
 *     optimization:table_linearization,optimization:basic_legalization,optimization:virtual_scalar_bool_legalization,optimization:fuse_fma,beforecodegen:rvv_legalization \
 *     --target rv64gv --precision single --function log --output \
 *     vla_log_single.c --fname vla_log_single
 *
 */
#include <riscv_vector.h>


static const float table[128]  = {
     0.0f, 0x1.5cd8p-1f, 0x1.58c8p-1f, 0x1.54bp-1f, 0x1.509p-1f, 0x1.4c68p-1f,
     0x1.4a5p-1f, 0x1.4618p-1f, 0x1.41d8p-1f, 0x1.3d9p-1f, 0x1.3b68p-1f, 0x1.371p-1f,
     0x1.32bp-1f, 0x1.308p-1f, 0x1.2c1p-1f, 0x1.2798p-1f, 0x1.2558p-1f, 0x1.20dp-1f,
     0x1.1e88p-1f, 0x1.19fp-1f, 0x1.17ap-1f, 0x1.12f8p-1f, 0x1.10ap-1f, 0x1.0be8p-1f,
     0x1.0988p-1f, 0x1.04cp-1f, 0x1.0258p-1f, 0x1.ffdp-2f, 0x1.f61p-2f, 0x1.f128p-2f,
     0x1.ec38p-2f, 0x1.e248p-2f, 0x1.dd48p-2f, 0x1.d84p-2f, 0x1.d33p-2f, 0x1.c9p-2f,
     0x1.c3ep-2f, 0x1.beb8p-2f, 0x1.b988p-2f, 0x1.b45p-2f, 0x1.a9dp-2f, 0x1.a488p-2f,
     0x1.9f3p-2f, 0x1.99d8p-2f, 0x1.9478p-2f, 0x1.8f1p-2f, 0x1.89ap-2f, 0x1.843p-2f,
     0x1.7ebp-2f, 0x1.7928p-2f, 0x1.73ap-2f, 0x1.6e08p-2f, 0x1.687p-2f, 0x1.62c8p-2f,
     0x1.5d18p-2f, 0x1.5768p-2f, 0x1.51a8p-2f, 0x1.4be8p-2f, 0x1.4618p-2f,
     0x1.404p-2f, 0x1.3a68p-2f, 0x1.348p-2f, 0x1.2e9p-2f, 0x1.2898p-2f, 0x1.2298p-2f,
     0x1.1c88p-2f, 0x1.1678p-2f, 0x1.1678p-2f, 0x1.1058p-2f, 0x1.0a3p-2f, 0x1.04p-2f,
     0x1.fb9p-3f, 0x1.ef08p-3f, 0x1.ef08p-3f, 0x1.e27p-3f, 0x1.d5cp-3f, 0x1.c9p-3f,
     0x1.bc28p-3f, 0x1.bc28p-3f, 0x1.af4p-3f, 0x1.a238p-3f, 0x1.9528p-3f,
     0x1.9528p-3f, 0x1.87f8p-3f, 0x1.7ab8p-3f, 0x1.6d6p-3f, 0x1.6d6p-3f, 0x1.5ffp-3f,
     0x1.527p-3f, 0x1.527p-3f, 0x1.44dp-3f, 0x1.372p-3f, 0x1.372p-3f, 0x1.2958p-3f,
     0x1.1b7p-3f, 0x1.1b7p-3f, 0x1.0d78p-3f, 0x1.fec8p-4f, 0x1.fec8p-4f, 0x1.e27p-4f,
     0x1.c5e8p-4f, 0x1.c5e8p-4f, 0x1.a928p-4f, 0x1.a928p-4f, 0x1.8c38p-4f,
     0x1.6f1p-4f, 0x1.6f1p-4f, 0x1.51bp-4f, 0x1.51bp-4f, 0x1.342p-4f, 0x1.165p-4f,
     0x1.165p-4f, 0x1.f0ap-5f, 0x1.f0ap-5f, 0x1.b43p-5f, 0x1.b43p-5f, 0x1.7748p-5f,
     0x1.39e8p-5f, 0x1.39e8p-5f, 0x1.f828p-6f, 0x1.f828p-6f, 0x1.7b9p-6f, 0x1.7b9p-6f,
     0x1.fc08p-7f, 0x1.fc08p-7f, 0x1.fep-8f, 0x1.fep-8f, 0.0f
};
static const float table1[128]  = {
     0.0f, -0x1.8248p-7f, -0x1.4328p-6f, -0x1.c64p-6f, -0x1.253p-5f, -0x1.67c8p-5f,
     -0x1.8948p-5f, -0x1.ccb8p-5f, -0x1.0858p-4f, -0x1.2aap-4f, -0x1.3bep-4f,
     -0x1.5e98p-4f, -0x1.8198p-4f, -0x1.9338p-4f, -0x1.b6bp-4f, -0x1.da7p-4f,
     -0x1.ec7p-4f, -0x1.0858p-3f, -0x1.1178p-3f, -0x1.23d8p-3f, -0x1.2d18p-3f,
     -0x1.3fb8p-3f, -0x1.491p-3f, -0x1.5bf8p-3f, -0x1.6578p-3f, -0x1.7898p-3f,
     -0x1.824p-3f, -0x1.8be8p-3f, -0x1.9f7p-3f, -0x1.a94p-3f, -0x1.b32p-3f,
     -0x1.c7p-3f, -0x1.d1p-3f, -0x1.db1p-3f, -0x1.e53p-3f, -0x1.f99p-3f,
     -0x1.01e8p-2f, -0x1.071p-2f, -0x1.0c4p-2f, -0x1.1178p-2f, -0x1.1bf8p-2f,
     -0x1.2148p-2f, -0x1.2698p-2f, -0x1.2bfp-2f, -0x1.315p-2f, -0x1.36b8p-2f,
     -0x1.3c28p-2f, -0x1.4198p-2f, -0x1.4718p-2f, -0x1.4cap-2f, -0x1.5228p-2f,
     -0x1.57cp-2f, -0x1.5d58p-2f, -0x1.63p-2f, -0x1.68bp-2f, -0x1.6e6p-2f,
     -0x1.742p-2f, -0x1.79ep-2f, -0x1.7fbp-2f, -0x1.8588p-2f, -0x1.8b6p-2f,
     -0x1.9148p-2f, -0x1.9738p-2f, -0x1.9d3p-2f, -0x1.a338p-2f, -0x1.a94p-2f,
     -0x1.af5p-2f, -0x1.af5p-2f, -0x1.b57p-2f, -0x1.bb98p-2f, -0x1.c1c8p-2f,
     -0x1.c8p-2f, -0x1.ce4p-2f, -0x1.ce4p-2f, -0x1.d49p-2f, -0x1.dae8p-2f,
     -0x1.e148p-2f, -0x1.e7b8p-2f, -0x1.e7b8p-2f, -0x1.ee28p-2f, -0x1.f4a8p-2f,
     -0x1.fb38p-2f, -0x1.fb38p-2f, -0x1.00e8p-1f, -0x1.0438p-1f, -0x1.0788p-1f,
     -0x1.0788p-1f, -0x1.0ae8p-1f, -0x1.0e48p-1f, -0x1.0e48p-1f, -0x1.11bp-1f,
     -0x1.152p-1f, -0x1.152p-1f, -0x1.189p-1f, -0x1.1c08p-1f, -0x1.1c08p-1f,
     -0x1.1f88p-1f, -0x1.2308p-1f, -0x1.2308p-1f, -0x1.2698p-1f, -0x1.2a28p-1f,
     -0x1.2a28p-1f, -0x1.2dcp-1f, -0x1.2dcp-1f, -0x1.316p-1f, -0x1.35p-1f,
     -0x1.35p-1f, -0x1.38bp-1f, -0x1.38bp-1f, -0x1.3c6p-1f, -0x1.4018p-1f,
     -0x1.4018p-1f, -0x1.43d8p-1f, -0x1.43d8p-1f, -0x1.47ap-1f, -0x1.47ap-1f,
     -0x1.4b7p-1f, -0x1.4f48p-1f, -0x1.4f48p-1f, -0x1.532p-1f, -0x1.532p-1f,
     -0x1.5708p-1f, -0x1.5708p-1f, -0x1.5af8p-1f, -0x1.5af8p-1f, -0x1.5ee8p-1f,
     -0x1.5ee8p-1f, -0x1.62e8p-1f
};
static const float table2[128]  = {
     0.0f, 0x1.8ee36p-16f, 0x1.6dae6cp-16f, 0x1.233cccp-16f, 0x1.3cc016p-17f,
     -0x1.940cc4p-19f, -0x1.e893fp-19f, 0x1.78438cp-18f, 0x1.fd08cep-18f,
     0x1.3538acp-20f, 0x1.128p-19f, 0x1.7b5474p-17f, 0x1.339122p-17f,
     -0x1.466588p-16f, -0x1.612bb8p-17f, -0x1.0f6bb2p-16f, -0x1.218b38p-16f,
     -0x1.19736ap-16f, -0x1.050c7ep-16f, -0x1.94b984p-17f, -0x1.544276p-17f,
     -0x1.cd4d82p-18f, -0x1.8c3a56p-18f, -0x1.a37b5ap-18f, -0x1.0b0a8cp-17f,
     -0x1.0312b6p-16f, -0x1.6ad2d2p-16f, 0x1.7042cp-17f, 0x1.1fd382p-17f,
     0x1.ebf5ep-19f, 0x1.9d2468p-18f, 0x1.034f8ep-19f, -0x1.5fb3e4p-18f,
     -0x1.8da75ep-18f, -0x1.81ff14p-22f, -0x1.070cacp-19f, -0x1.42c192p-17f,
     -0x1.9312c8p-17f, -0x1.3b4b68p-17f, -0x1.10866ep-19f, -0x1.36566p-18f,
     -0x1.fb78d2p-17f, 0x1.1f65fcp-17f, 0x1.58117ep-18f, 0x1.41c212p-18f,
     0x1.e87366p-18f, 0x1.9c360ap-17f, -0x1.712f0cp-17f, -0x1.f11f54p-20f,
     0x1.2afeeap-17f, -0x1.404a22p-17f, 0x1.d54574p-19f, -0x1.bf0b28p-17f,
     0x1.795ce4p-21f, 0x1.edfacp-17f, -0x1.1d1754p-19f, 0x1.6c397p-17f,
     -0x1.035444p-17f, 0x1.78438cp-19f, 0x1.843436p-17f, -0x1.9d54b6p-17f,
     -0x1.132b3cp-17f, -0x1.d451eep-18f, -0x1.2f610cp-17f, -0x1.f02184p-17f,
     0x1.8c169ap-18f, -0x1.1aa2a2p-17f, -0x1.1aa2a2p-17f, 0x1.7f35cap-19f,
     0x1.27139cp-17f, 0x1.2ca5a6p-17f, 0x1.86d5e4p-19f, 0x1.6e5ee2p-18f,
     0x1.6e5ee2p-18f, 0x1.db8abcp-21f, 0x1.0b5a7ep-18f, -0x1.070cacp-20f,
     0x1.9d0b64p-21f, 0x1.9d0b64p-21f, -0x1.b58bfap-18f, 0x1.e0ff16p-18f,
     -0x1.2b185ep-18f, -0x1.2b185ep-18f, 0x1.032906p-18f, 0x1.20421cp-20f,
     0x1.fce33ap-20f, 0x1.fce33ap-20f, 0x1.83853cp-18f, -0x1.a1c5e4p-19f,
     -0x1.a1c5e4p-19f, 0x1.5b665cp-18f, -0x1.eff0b8p-22f, -0x1.eff0b8p-22f,
     -0x1.683fp-18f, 0x1.56a97cp-18f, 0x1.56a97cp-18f, -0x1.832f72p-23f,
     0x1.131dbep-20f, 0x1.131dbep-20f, 0x1.db8abcp-22f, -0x1.5b8522p-19f,
     -0x1.5b8522p-19f, -0x1.2c5b52p-20f, -0x1.2c5b52p-20f, -0x1.d14e74p-19f,
     -0x1.6ba8d4p-19f, -0x1.6ba8d4p-19f, 0x1.cfc186p-22f, 0x1.cfc186p-22f,
     -0x1.434f22p-19f, 0x1.b7751cp-19f, 0x1.b7751cp-19f, 0x1.86008cp-20f,
     0x1.86008cp-20f, -0x1.147734p-20f, -0x1.147734p-20f, -0x1.384e6ap-20f,
     0x1.ee7fbp-23f, 0x1.ee7fbp-23f, 0x1.b0e784p-22f, 0x1.b0e784p-22f,
     0x1.b07d5cp-22f, 0x1.b07d5cp-22f, 0x1.4587ep-22f, 0x1.4587ep-22f,
     0x1.535884p-23f, 0x1.535884p-23f, 0.0f
};
static const float table3[128]  = {
     0.0f, 0x1.bae3bap-22f, -0x1.492ccp-21f, 0x1.689f5ap-21f, 0x1.9a0e5cp-22f,
     -0x1.4f2d4cp-21f, -0x1.50a4fep-20f, 0x1.86444ap-22f, -0x1.8b59e4p-20f,
     -0x1.2911c6p-22f, 0x1.4b05c2p-21f, 0x1.2d9344p-19f, 0x1.d0bf1cp-24f,
     0x1.0d1536p-19f, 0x1.bb9296p-19f, -0x1.3b1c22p-19f, -0x1.cc185p-19f,
     -0x1.8b59e4p-19f, -0x1.d044fcp-20f, 0x1.dab6c8p-20f, 0x1.ef3798p-19f,
     0x1.d2d336p-18f, -0x1.ec199ep-18f, 0x1.fca55ep-18f, 0x1.8a0bap-18f,
     -0x1.b0a88ap-20f, 0x1.f4d572p-18f, -0x1.7f59c8p-18f, 0x1.dfc7bcp-18f,
     0x1.2c3752p-19f, 0x1.3d4522p-18f, 0x1.0e43fcp-21f, -0x1.bf932ap-18f,
     -0x1.ed86a4p-18f, -0x1.dffce2p-20f, -0x1.c6cb3cp-19f, -0x1.72b136p-17f,
     -0x1.c3026ap-17f, -0x1.6b3b0cp-17f, -0x1.d044fcp-19f, -0x1.9635a6p-18f,
     0x1.d4978ap-17f, 0x1.deecb2p-18f, 0x1.f0646ep-19f, 0x1.c3c594p-19f,
     0x1.88941ep-18f, 0x1.6c4666p-17f, -0x1.a11ebp-17f, -0x1.b84e38p-19f,
     0x1.f61e8ep-18f, -0x1.7039c6p-17f, 0x1.1586e6p-19f, -0x1.eefacap-17f,
     -0x1.859d56p-21f, 0x1.be0b1cp-17f, -0x1.dcd5e4p-19f, 0x1.3c49ccp-17f,
     -0x1.3343e8p-17f, 0x1.7109fap-20f, 0x1.544492p-17f, -0x1.cd445ap-17f,
     -0x1.431aep-17f, -0x1.1a189ap-17f, -0x1.5f50bp-17f, 0x1.dfeed8p-17f,
     0x1.2c3752p-18f, -0x1.4a9246p-17f, -0x1.4a9246p-17f, 0x1.7eee76p-20f,
     0x1.ee47f2p-18f, 0x1.f96c06p-18f, 0x1.8e2eaap-20f, -0x1.78c032p-17f,
     -0x1.78c032p-17f, -0x1.236f7ep-21f, 0x1.56f66ep-19f, -0x1.4344e4p-19f,
     0x1.e9e112p-17f, 0x1.e9e112p-17f, -0x1.0ab5ap-17f, -0x1.3f7018p-17f,
     0x1.3a842ep-17f, 0x1.3a842ep-17f, 0x1.28d27p-16f, 0x1.f418ap-17f,
     -0x1.f8299ep-16f, -0x1.f8299ep-16f, 0x1.23a5f6p-18f, -0x1.30c23ap-18f,
     -0x1.30c23ap-18f, 0x1.f70e2ap-19f, 0x1.e0486cp-16f, 0x1.e0486cp-16f,
     0x1.1bf0dcp-17f, 0x1.ed9468p-19f, 0x1.ed9468p-19f, 0x1.ca039ep-17f,
     -0x1.86c5f6p-16f, -0x1.86c5f6p-16f, 0x1.deecb2p-17f, 0x1.e4bc5p-19f,
     0x1.e4bc5p-19f, 0x1.5509e4p-18f, 0x1.5509e4p-18f, 0x1.2dde6p-16f,
     -0x1.456cecp-16f, -0x1.456cecp-16f, 0x1.de8e68p-17f, 0x1.de8e68p-17f,
     -0x1.0186d8p-18f, -0x1.c2125cp-17f, -0x1.c2125cp-17f, -0x1.ff2f92p-17f,
     -0x1.ff2f92p-17f, -0x1.527e8ap-17f, -0x1.527e8ap-17f, 0x1.48347ap-20f,
     0x1.2be52ep-16f, 0x1.2be52ep-16f, -0x1.713434p-16f, -0x1.713434p-16f,
     0x1.76511cp-19f, 0x1.76511cp-19f, 0x1.fd1e4ep-16f, 0x1.fd1e4ep-16f,
     -0x1.55120cp-20f, -0x1.55120cp-20f, 0x1.e8082ep-16f
};

void vla_log_single(float* dst, float* src, uint32_t len){
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
        vint32m1_t tmp3;
        vint32m1_t tmp4;
        vfloat32m1_t _vx_mant;
        vbool32_t tho_cond;
        vint32m1_t tmp5;
        vuint32m1_t tmp6;
        vuint32m1_t tmp7;
        vint32m1_t tmp8;
        vint32m1_t table_index;
        vint32m1_t tmp9;
        vuint32m1_t tmp10;
        vfloat32m1_t tmp11;
        vint32m1_t tmp12;
        vuint32m1_t tmp13;
        vfloat32m1_t tmp14;
        vfloat32m1_t log_inv_hi;
        vfloat32m1_t tmp15;
        vint32m1_t tmp16;
        vuint32m1_t tmp17;
        vuint32m1_t tmp18;
        vint32m1_t tmp19;
        vint32m1_t tmp20;
        vint32m1_t _vx_exp;
        vfloat32m1_t tmp21;
        vfloat32m1_t tmp22;
        vfloat32m1_t tmp23;
        vfloat32m1_t tho;
        vfloat32m1_t corr_exp;
        vbool32_t index_comp_0;
        vfloat32m1_t seed;
        vint32m1_t tmp24;
        vint32m1_t tmp25;
        vfloat32m1_t pre_arg_red_index;
        vfloat32m1_t arg_red_index;
        vfloat32m1_t tmp26;
        vfloat32m1_t _red_vx;
        vfloat32m1_t tmp27;
        vfloat32m1_t pa_3;
        vfloat32m1_t tmp28;
        vfloat32m1_t pa_2;
        vfloat32m1_t tmp29;
        vfloat32m1_t tmp30;
        vfloat32m1_t poly;
        vfloat32m1_t tmp31;
        vfloat32m1_t tmp32;
        vfloat32m1_t tmp33;
        vfloat32m1_t tmp34;
        vfloat32m1_t tmp35;
        vfloat32m1_t tmp36;
        vfloat32m1_t tmp37;
        vfloat32m1_t tmp38;
        vfloat32m1_t tmp39;
        vfloat32m1_t m0h;
        vfloat32m1_t tmp40;
        vfloat32m1_t tmp41;
        vfloat32m1_t tmp42;
        vfloat32m1_t tmp43;
        vfloat32m1_t tmp44;
        vfloat32m1_t tmp45;
        vfloat32m1_t tmp46;
        vfloat32m1_t m0l;
        vfloat32m1_t tmp47;
        vfloat32m1_t tmp48;
        vfloat32m1_t rh0;
        vfloat32m1_t tmp49;
        vfloat32m1_t tmp50;
        vfloat32m1_t tmp51;
        vfloat32m1_t tmp52;
        vfloat32m1_t tmp53;
        vfloat32m1_t tmp54;
        vint32m1_t tmp55;
        vuint32m1_t tmp56;
        vfloat32m1_t tmp57;
        vint32m1_t tmp58;
        vuint32m1_t tmp59;
        vfloat32m1_t tmp60;
        vfloat32m1_t log_inv_lo;
        vfloat32m1_t tmp61;
        vfloat32m1_t tmp62;
        vfloat32m1_t rl0;
        vfloat32m1_t tmp63;
        vfloat32m1_t tmp64;
        vfloat32m1_t result;
        float* tmp65;
        int32_t tmp66;
        int32_t tmp67;
        int32_t tmp68;

        tmp = vsetvl_e32m1(remLen);
        l = tmp;
        tmp1 = src + offset;
        varg = vle32_v_f32m1(tmp1, l);
        vec_x = varg;
        tmp2 = vreinterpret_v_f32m1_i32m1(vec_x);
        tmp3 = vand_vx_i32m1(tmp2, INT32_C(2155872255), l);
        tmp4 = vor_vx_i32m1(tmp3, INT32_C(1065353216), l);
        _vx_mant = vreinterpret_v_i32m1_f32m1(tmp4);
        tho_cond = vmfgt_vf_f32m1_b32(_vx_mant, 0x1.6a09e6p0f, l);
        tmp5 = vreinterpret_v_f32m1_i32m1(_vx_mant);
        tmp6 = vreinterpret_v_i32m1_u32m1(tmp5);
        tmp7 = vsrl_vx_u32m1(tmp6, INT32_C(16), l);
        tmp8 = vreinterpret_v_u32m1_i32m1(tmp7);
        table_index = vand_vx_i32m1(tmp8, INT32_C(127), l);
        tmp9 = vmul_vx_i32m1(table_index, INT32_C(4), l);
        tmp10 = vreinterpret_v_i32m1_u32m1(tmp9);
        tmp11 = vluxei32_v_f32m1(table, tmp10, l);
        tmp12 = vmul_vx_i32m1(table_index, INT32_C(4), l);
        tmp13 = vreinterpret_v_i32m1_u32m1(tmp12);
        tmp14 = vluxei32_v_f32m1(table1, tmp13, l);
        log_inv_hi = vmerge_vvm_f32m1(tho_cond, tmp14, tmp11, l);
        tmp15 = vfneg_v_f32m1(log_inv_hi, l);
        tmp16 = vreinterpret_v_f32m1_i32m1(vec_x);
        tmp17 = vreinterpret_v_i32m1_u32m1(tmp16);
        tmp18 = vsrl_vx_u32m1(tmp17, INT32_C(23), l);
        tmp19 = vreinterpret_v_u32m1_i32m1(tmp18);
        tmp20 = vand_vx_i32m1(tmp19, INT32_C(255), l);
        _vx_exp = vadd_vx_i32m1(tmp20, INT32_C(-127), l);
        tmp21 = vfcvt_f_x_v_f32m1(_vx_exp, l);
        tmp22 = vfmv_v_f_f32m1(1.0f, l);
        tmp23 = vfmv_v_f_f32m1(0.0f, l);
        tho = vmerge_vvm_f32m1(tho_cond, tmp23, tmp22, l);
        corr_exp = vfadd_vv_f32m1(tmp21, tho, l);
        index_comp_0 = vmseq_vx_i32m1_b32(table_index, INT32_C(0), l);
        seed = vfrec7_v_f32m1(_vx_mant, l);
        tmp24 = vreinterpret_v_f32m1_i32m1(seed);
        tmp25 = vand_vx_i32m1(tmp24, INT32_C(-2), l);
        pre_arg_red_index = vreinterpret_v_i32m1_f32m1(tmp25);
        arg_red_index = vfmerge_vfm_f32m1(index_comp_0, pre_arg_red_index, 1.0f, l);
        tmp26 = vfmv_v_f_f32m1(-1.0f, l);
        _red_vx = vfmadd_vv_f32m1(arg_red_index, _vx_mant, tmp26, l);
        tmp27 = vfmv_v_f_f32m1(-0x1.000956p-2f, l);
        pa_3 = vfmadd_vf_f32m1(_red_vx, 0x1.99db04p-3f, tmp27, l);
        tmp28 = vfmv_v_f_f32m1(0x1.555554p-2f, l);
        pa_2 = vfmadd_vv_f32m1(_red_vx, pa_3, tmp28, l);
        tmp29 = vfmv_v_f_f32m1(-0x1p-1f, l);
        tmp30 = vfmadd_vv_f32m1(_red_vx, pa_2, tmp29, l);
        poly = vfmul_vv_f32m1(_red_vx, tmp30, l);
        tmp31 = vfmadd_vv_f32m1(_red_vx, poly, _red_vx, l);
        tmp32 = vfnmsub_vv_f32m1(_red_vx, poly, tmp31, l);
        tmp33 = vfsub_vv_f32m1(_red_vx, tmp32, l);
        tmp34 = vfsub_vv_f32m1(tmp31, tmp32, l);
        tmp35 = vfmsub_vv_f32m1(_red_vx, poly, tmp34, l);
        tmp36 = vfadd_vv_f32m1(tmp33, tmp35, l);
        tmp37 = vfmul_vv_f32m1(_red_vx, poly, l);
        tmp38 = vfmsub_vv_f32m1(_red_vx, poly, tmp37, l);
        tmp39 = vfadd_vv_f32m1(tmp36, tmp38, l);
        m0h = vfadd_vv_f32m1(tmp31, tmp39, l);
        tmp40 = vfmadd_vf_f32m1(corr_exp, 0x1.62e8p-1f, m0h, l);
        tmp41 = vfsub_vv_f32m1(tmp40, m0h, l);
        tmp42 = vfmsub_vf_f32m1(corr_exp, 0x1.62e8p-1f, tmp41, l);
        tmp43 = vfsub_vv_f32m1(tmp40, tmp41, l);
        tmp44 = vfsub_vv_f32m1(m0h, tmp43, l);
        tmp45 = vfadd_vv_f32m1(tmp42, tmp44, l);
        tmp46 = vfsub_vv_f32m1(m0h, tmp31, l);
        m0l = vfsub_vv_f32m1(tmp39, tmp46, l);
        tmp47 = vfmadd_vf_f32m1(corr_exp, -0x1.e8082ep-16f, m0l, l);
        tmp48 = vfadd_vv_f32m1(tmp45, tmp47, l);
        rh0 = vfadd_vv_f32m1(tmp40, tmp48, l);
        tmp49 = vfadd_vv_f32m1(tmp15, rh0, l);
        tmp50 = vfsub_vv_f32m1(tmp49, rh0, l);
        tmp51 = vfsub_vv_f32m1(tmp15, tmp50, l);
        tmp52 = vfsub_vv_f32m1(tmp49, tmp50, l);
        tmp53 = vfsub_vv_f32m1(rh0, tmp52, l);
        tmp54 = vfadd_vv_f32m1(tmp51, tmp53, l);
        tmp55 = vmul_vx_i32m1(table_index, INT32_C(4), l);
        tmp56 = vreinterpret_v_i32m1_u32m1(tmp55);
        tmp57 = vluxei32_v_f32m1(table2, tmp56, l);
        tmp58 = vmul_vx_i32m1(table_index, INT32_C(4), l);
        tmp59 = vreinterpret_v_i32m1_u32m1(tmp58);
        tmp60 = vluxei32_v_f32m1(table3, tmp59, l);
        log_inv_lo = vmerge_vvm_f32m1(tho_cond, tmp60, tmp57, l);
        tmp61 = vfneg_v_f32m1(log_inv_lo, l);
        tmp62 = vfsub_vv_f32m1(rh0, tmp40, l);
        rl0 = vfsub_vv_f32m1(tmp48, tmp62, l);
        tmp63 = vfadd_vv_f32m1(tmp61, rl0, l);
        tmp64 = vfadd_vv_f32m1(tmp54, tmp63, l);
        result = vfadd_vv_f32m1(tmp49, tmp64, l);
        tmp65 = dst + offset;
        vse32_v_f32m1(tmp65, result, l);
        tmp66 =  (int32_t) l;
        tmp67 = remLen - tmp66;
        remLen = tmp67;
        tmp68 = offset + tmp66;
        offset = tmp68;
    }
}
