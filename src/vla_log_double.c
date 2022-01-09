/**
 * generated using metalibm 1.1
 * sha1 git: b'"3a8e11d7eeadc3f3fd42553299da0f20a23ba55d"'(clean)
 *
 * INFO: git status was clean when file was generated.
 *
 * command used for generation:
 *   ../metalibm_functions/vla_function.py --extra-passes \
 *     optimization:table_linearization,optimization:basic_legalization,optimization:virtual_scalar_bool_legalization,optimization:fuse_fma,beforecodegen:rvv_legalization \
 *     --target rv64gv --precision double --function log --output \
 *     vla_log_double.c --fname vla_log_double
 *
 */
#include <riscv_vector.h>


static const double table[128]  = {
     0.0, 0x1.5cdb1dc6c2p-1, 0x1.58cadb5cd8p-1, 0x1.54b246799ap-1, 0x1.50913cc016p-1,
     0x1.4c679afccep-1, 0x1.4a4f85db04p-1, 0x1.4618bc21c6p-1, 0x1.41d8fe8468p-1,
     0x1.3d9026a716p-1, 0x1.3b6844ap-1, 0x1.37117b5474p-1, 0x1.32b1339122p-1,
     0x1.307d7334f2p-1, 0x1.2c0e9ed448p-1, 0x1.2795e1289cp-1, 0x1.2555bce99p-1,
     0x1.20cdcd192ap-1, 0x1.1e85f5e704p-1, 0x1.19ee6b467cp-1, 0x1.179eabbd8ap-1,
     0x1.12f719593ep-1, 0x1.109f39e2d4p-1, 0x1.0be72e4252p-1, 0x1.0986f4f574p-1,
     0x1.04bdf9da92p-1, 0x1.02552a5a5ep-1, 0x1.ffd2e0858p-2, 0x1.f6123fa702p-2,
     0x1.f128f5fafp-2, 0x1.ec399d2468p-2, 0x1.e24881a7c6p-2, 0x1.dd46a04c1cp-2,
     0x1.d83e7258a2p-2, 0x1.d32fe7e00ep-2, 0x1.c8ff7c79aap-2, 0x1.c3dd7a7cdap-2,
     0x1.beb4d9da72p-2, 0x1.b985896932p-2, 0x1.b44f77bcc8p-2, 0x1.a9cec9a9ap-2,
     0x1.a484090e5cp-2, 0x1.9f323ecbfap-2, 0x1.99d958117ep-2, 0x1.947941c212p-2,
     0x1.8f11e87366p-2, 0x1.89a3386c14p-2, 0x1.842d1da1e8p-2, 0x1.7eaf83b82ap-2,
     0x1.792a55fdd4p-2, 0x1.739d7f6bbep-2, 0x1.6e08eaa2bap-2, 0x1.686c81e9b2p-2,
     0x1.62c82f2b9cp-2, 0x1.5d1bdbf58p-2, 0x1.5767717456p-2, 0x1.51aad872ep-2,
     0x1.4be5f95778p-2, 0x1.4618bc21c6p-2, 0x1.404308686ap-2, 0x1.3a64c55694p-2,
     0x1.347dd9a988p-2, 0x1.2e8e2bae12p-2, 0x1.2895a13de8p-2, 0x1.22941fbcf8p-2,
     0x1.1c898c169ap-2, 0x1.1675cababap-2, 0x1.1675cababap-2, 0x1.1058bf9ae4p-2,
     0x1.0a324e273ap-2, 0x1.0402594b4ep-2, 0x1.fb9186d5e4p-3, 0x1.ef0adcbdc6p-3,
     0x1.ef0adcbdc6p-3, 0x1.e27076e2bp-3, 0x1.d5c216b4fcp-3, 0x1.c8ff7c79aap-3,
     0x1.bc286742d8p-3, 0x1.bc286742d8p-3, 0x1.af3c94e80cp-3, 0x1.a23bc1fe2cp-3,
     0x1.9525a9cf46p-3, 0x1.9525a9cf46p-3, 0x1.87fa06520cp-3, 0x1.7ab890210ep-3,
     0x1.6d60fe719ep-3, 0x1.6d60fe719ep-3, 0x1.5ff3070a7ap-3, 0x1.526e5e3a1cp-3,
     0x1.526e5e3a1cp-3, 0x1.44d2b6ccb8p-3, 0x1.371fc201e8p-3, 0x1.371fc201e8p-3,
     0x1.29552f82p-3, 0x1.1b72ad52f6p-3, 0x1.1b72ad52f6p-3, 0x1.0d77e7cd08p-3,
     0x1.fec9131dbep-4, 0x1.fec9131dbep-4, 0x1.e27076e2bp-4, 0x1.c5e548f5bcp-4,
     0x1.c5e548f5bcp-4, 0x1.a926d3a4aep-4, 0x1.a926d3a4aep-4, 0x1.8c345d631ap-4,
     0x1.6f0d28ae56p-4, 0x1.6f0d28ae56p-4, 0x1.51b073f062p-4, 0x1.51b073f062p-4,
     0x1.341d7961bep-4, 0x1.16536eea38p-4, 0x1.16536eea38p-4, 0x1.f0a30c0116p-5,
     0x1.f0a30c0116p-5, 0x1.b42dd71198p-5, 0x1.b42dd71198p-5, 0x1.77458f632ep-5,
     0x1.39e87b9fecp-5, 0x1.39e87b9fecp-5, 0x1.f829b0e784p-6, 0x1.f829b0e784p-6,
     0x1.7b91b07d5cp-6, 0x1.7b91b07d5cp-6, 0x1.fc0a8b0fcp-7, 0x1.fc0a8b0fcp-7,
     0x1.fe02a6b106p-8, 0x1.fe02a6b106p-8, 0.0
};
static const double table1[128]  = {
     0.0, -0x1.82448a388ap-7, -0x1.432a92598p-6, -0x1.c63d2ec14ap-6,
     -0x1.252f32f8d2p-5, -0x1.67c94f2d4cp-5, -0x1.894aa149fcp-5, -0x1.ccb73cdddcp-5,
     -0x1.08598b59e4p-4, -0x1.2aa04a4472p-4, -0x1.3bdf5a7d1ep-4, -0x1.5e95a4d97ap-4,
     -0x1.8197e2f40ep-4, -0x1.9335e5d594p-4, -0x1.b6ac88dad6p-4, -0x1.da72763844p-4,
     -0x1.ec739830a2p-4, -0x1.08598b59e4p-3, -0x1.1178e8227ep-3, -0x1.23d712a49cp-3,
     -0x1.2d1610c868p-3, -0x1.3fb45a5992p-3, -0x1.4913d8333cp-3, -0x1.5bf406b544p-3,
     -0x1.6574ebe8c2p-3, -0x1.7898d85444p-3, -0x1.823c16551ap-3, -0x1.8beafeb39p-3,
     -0x1.9f6c40708ap-3, -0x1.a93ed3c8aep-3, -0x1.b31d8575bcp-3, -0x1.c6ffbc6fp-3,
     -0x1.d1037f2656p-3, -0x1.db13db0d48p-3, -0x1.e530effe72p-3, -0x1.f991c6cb3cp-3,
     -0x1.01eae5626cp-2, -0x1.07138604d6p-2, -0x1.0c42d67616p-2, -0x1.1178e8227ep-2,
     -0x1.1bf99635a6p-2, -0x1.214456d0ecp-2, -0x1.269621134ep-2, -0x1.2bef07cdcap-2,
     -0x1.314f1e1d36p-2, -0x1.36b6776be2p-2, -0x1.3c25277334p-2, -0x1.419b423d5ep-2,
     -0x1.4718dc271cp-2, -0x1.4c9e09e172p-2, -0x1.522ae0738ap-2, -0x1.57bf753c8ep-2,
     -0x1.5d5bddf596p-2, -0x1.630030b3aap-2, -0x1.68ac83e9c6p-2, -0x1.6e60ee6af2p-2,
     -0x1.741d876c68p-2, -0x1.79e26687dp-2, -0x1.7fafa3bd82p-2, -0x1.85855776dcp-2,
     -0x1.8b639a88b2p-2, -0x1.914a8635cp-2, -0x1.973a343136p-2, -0x1.9d32bea15ep-2,
     -0x1.a33440225p-2, -0x1.a93ed3c8aep-2, -0x1.af5295248cp-2, -0x1.af5295248cp-2,
     -0x1.b56fa04462p-2, -0x1.bb9611b80ep-2, -0x1.c1c60693fap-2, -0x1.c7ff9c7456p-2,
     -0x1.ce42f18064p-2, -0x1.ce42f18064p-2, -0x1.d490246dfp-2, -0x1.dae75484cap-2,
     -0x1.e148a1a272p-2, -0x1.e7b42c3ddap-2, -0x1.e7b42c3ddap-2, -0x1.ee2a156b42p-2,
     -0x1.f4aa7ee032p-2, -0x1.fb358af7a4p-2, -0x1.fb358af7a4p-2, -0x1.00e5ae5b2p-1,
     -0x1.04360be76p-1, -0x1.078bf0533cp-1, -0x1.078bf0533cp-1, -0x1.0ae76e2d06p-1,
     -0x1.0e4898611cp-1, -0x1.0e4898611cp-1, -0x1.11af823c76p-1, -0x1.151c3f6f2ap-1,
     -0x1.151c3f6f2ap-1, -0x1.188ee40f24p-1, -0x1.1c07849ae6p-1, -0x1.1c07849ae6p-1,
     -0x1.1f8635fc62p-1, -0x1.230b0d8becp-1, -0x1.230b0d8becp-1, -0x1.269621134ep-1,
     -0x1.2a2786d0ecp-1, -0x1.2a2786d0ecp-1, -0x1.2dbf557b0ep-1, -0x1.2dbf557b0ep-1,
     -0x1.315da4434p-1, -0x1.35028ad9d8p-1, -0x1.35028ad9d8p-1, -0x1.38ae217198p-1,
     -0x1.38ae217198p-1, -0x1.3c6080c36cp-1, -0x1.4019c2125cp-1, -0x1.4019c2125cp-1,
     -0x1.43d9ff2f92p-1, -0x1.43d9ff2f92p-1, -0x1.47a1527e8ap-1, -0x1.47a1527e8ap-1,
     -0x1.4b6fd6f97p-1, -0x1.4f45a835a4p-1, -0x1.4f45a835a4p-1, -0x1.5322e26868p-1,
     -0x1.5322e26868p-1, -0x1.5707a26bb8p-1, -0x1.5707a26bb8p-1, -0x1.5af405c364p-1,
     -0x1.5af405c364p-1, -0x1.5ee82aa242p-1, -0x1.5ee82aa242p-1, -0x1.62e42fefa4p-1
};
static const double table2[128]  = {
     0.0, -0x1.136e612387452p-42, -0x1.9db3db43689b4p-43, -0x1.6d0add57ae978p-42,
     0x1.0d6979674b617p-42, 0x1.c7362d1d9ba63p-42, -0x1.44fdd840b8591p-45,
     -0x1.3d82f484c84ccp-45, -0x1.aa33736867a17p-42, -0x1.20ab7f7b385eap-42,
     -0x1.eea838909f3d3p-44, 0x1.ed71774092113p-43, -0x1.4766fd54a4c27p-44,
     -0x1.e83c094debc15p-42, 0x1.d1772f5386374p-42, -0x1.dca290f81848dp-42,
     -0x1.06987f78a4a5ep-42, 0x1.6db26a07a1eebp-42, 0x1.a07bd8b34be7cp-46,
     0x1.2dd98b97baefp-42, -0x1.97d00e7c6417ep-43, 0x1.f78a60246339p-42,
     0x1.92dfbc7d93617p-42, 0x1.5056d312f7668p-42, -0x1.5be8dc04ad601p-42,
     0x1.b4997f304022dp-43, -0x1.e0272c72d4502p-42, -0x1.6cf54d05f9367p-43,
     0x1.158c28ad8796ep-43, 0x1.bb2cd720ec44cp-44, 0x1.9802eb9dca7e7p-43,
     0x1.84c397b1e8b2bp-43, 0x1.282fb989a9274p-44, 0x1.e7ca0a2b745d9p-43,
     0x1.7aac3bd9197d8p-43, -0x1.7794f689f8434p-44, 0x1.a9ae7678296f5p-43,
     -0x1.21021e78b2151p-44, -0x1.e094ce09d60eep-43, 0x1.ec5197ddb55d3p-43,
     0x1.0931a909fea5ep-43, -0x1.3d7500d6523c5p-44, -0x1.ed03525ca2643p-44,
     0x1.1597525dd88fp-47, -0x1.20a8b6645d706p-43, 0x1.63bf0bb4eab4cp-45,
     0x1.2d5ad38c40882p-45, 0x1.62e927628cbc2p-43, 0x1.f86c9674bcf69p-43,
     0x1.e89f057691feap-44, -0x1.ff2c63b67580ap-43, 0x1.e38c139318d71p-46,
     -0x1.6a2777a83dfd6p-43, 0x1.e54bdbd7c8a98p-44, 0x1.394a11b1c1ee4p-43,
     -0x1.64ead9524d7cap-44, -0x1.f4bd8db0a7cc1p-44, -0x1.d7c92cd9ad824p-44,
     -0x1.3d82f484c84ccp-46, 0x1.f8ef43049f7d3p-44, 0x1.7a71cbcd735dp-44,
     -0x1.5594dd4c58092p-45, -0x1.67b1e99b72bd8p-45, 0x1.a8d7ad24c13fp-44,
     -0x1.a6976f5eb0963p-44, -0x1.81410e5c62affp-44, 0x1.8380e731f55c4p-44,
     0x1.8380e731f55c4p-44, 0x1.5aa313f415699p-43, -0x1.e39411810bfcfp-43,
     -0x1.f7e4a3b085e94p-43, -0x1.d572aab993c87p-47, -0x1.b26b79c86af24p-45,
     -0x1.b26b79c86af24p-45, -0x1.a342c2af0003cp-44, -0x1.1ba91bbca681bp-45,
     -0x1.7794f689f8434p-45, 0x1.9ac53f39d121cp-44, 0x1.9ac53f39d121cp-44,
     -0x1.a4e633fcd9066p-52, -0x1.539cd91dc9f0bp-44, -0x1.297137d9f158fp-44,
     -0x1.297137d9f158fp-44, 0x1.22120401202fcp-44, -0x1.bdb9072534a58p-45,
     -0x1.bc6e557134767p-44, -0x1.bc6e557134767p-44, -0x1.8586f183bebf2p-44,
     -0x1.790ba37fc5238p-44, -0x1.790ba37fc5238p-44, -0x1.70cc16135783cp-46,
     0x1.ee8779b2d8abcp-44, 0x1.ee8779b2d8abcp-44, -0x1.5b967f4471dfcp-44,
     0x1.e80a41811a396p-45, 0x1.e80a41811a396p-45, 0x1.cb2cd2ee2f482p-44,
     0x1.575545ca333f2p-45, 0x1.575545ca333f2p-45, -0x1.a342c2af0003cp-45,
     0x1.d0c57585fbe06p-46, 0x1.d0c57585fbe06p-46, -0x1.53935e85baac8p-45,
     -0x1.53935e85baac8p-45, -0x1.37c294d2f5668p-46, 0x1.69737c93373dap-45,
     0x1.69737c93373dap-45, -0x1.f025b61c65e57p-46, -0x1.f025b61c65e57p-46,
     -0x1.c5edaccf913dfp-45, -0x1.47c5e768fa309p-46, -0x1.47c5e768fa309p-46,
     0x1.5330be64b8b77p-48, 0x1.5330be64b8b77p-48, -0x1.c827ae5d6704cp-46,
     -0x1.c827ae5d6704cp-46, -0x1.81dce586af08ep-48, -0x1.502b7f526feaap-48,
     -0x1.502b7f526feaap-48, -0x1.9ff660e07d871p-47, -0x1.9ff660e07d871p-47,
     -0x1.dcaadb015671dp-47, -0x1.dcaadb015671dp-47, 0x1.f1e7cf6d3a69cp-50,
     0x1.f1e7cf6d3a69cp-50, 0x1.e23f0dda40e47p-50, 0x1.e23f0dda40e47p-50, 0.0
};
static const double table3[128]  = {
     0.0, -0x1.55104b16137f1p-50, -0x1.98139928637fep-47, -0x1.5e318fe7acbcap-47,
     0x1.f05947f792616p-47, 0x1.29efbec19afa2p-47, 0x1.97995d05a267dp-46,
     0x1.a68f247d82807p-46, 0x1.7e5dd7009902cp-46, 0x1.0b6e8ae9c697dp-45,
     -0x1.cc85ea5db4ed7p-45, 0x1.c69063c5d1d1ep-45, -0x1.f80dcf96ffdf7p-47,
     -0x1.3115c3abd47dap-45, 0x1.390802bf768e5p-46, -0x1.a89401fa71733p-46,
     0x1.dc068afe645ep-45, 0x1.7e5dd7009902cp-45, -0x1.1ef78ce2d07f2p-45,
     -0x1.00d238fd3df5cp-46, -0x1.39d6ccb81b4a1p-47, -0x1.19713c0cae559p-44,
     0x1.53e43558124c4p-44, 0x1.27023eb68981cp-46, 0x1.98c1d34f0f462p-44,
     -0x1.8e67be3dbaf3fp-44, -0x1.e0ddb9a631e83p-46, 0x1.73d54aae92cd1p-47,
     0x1.337d94bcd3f43p-44, 0x1.8724350562169p-45, -0x1.c794e562a63cbp-44,
     -0x1.ee138d3a69d43p-44, 0x1.84a7e75b6f6e4p-47, -0x1.2806a847527e6p-44,
     0x1.fdbdbb13f7c18p-44, 0x1.90d04cd7cc834p-44, -0x1.a43dcfade85aep-44,
     0x1.e76324e912b17p-44, -0x1.7188b163ceae9p-45, -0x1.1ef78ce2d07f2p-44,
     -0x1.729bb5451ef6ep-43, 0x1.caf0428b728a3p-44, 0x1.1b61f10522625p-44,
     0x1.958c16d6bfec3p-43, 0x1.8e27ad3213cb8p-45, 0x1.dd22649e1d107p-43,
     0x1.cf895693f2854p-43, -0x1.18e436ec90e0ap-43, -0x1.06c18fb4c14c5p-44,
     -0x1.877ddb93d49d7p-43, -0x1.ebe708164c759p-45, 0x1.c0a42423457e2p-43,
     0x1.a0b2a08a465dcp-47, -0x1.892770633948p-43, -0x1.42834c9d5bae8p-43,
     0x1.a37a6a0f7749ep-44, 0x1.13a7b5b11cfa7p-44, 0x1.309c168817444p-44,
     0x1.5c8243204959ap-43, -0x1.7f55bccccdde2p-43, -0x1.be94786863ee4p-43,
     0x1.2ecd6a5dcc61p-43, 0x1.2a46274a05b3ep-43, -0x1.a76187bcbcfd4p-43,
     0x1.61cdd40314305p-44, 0x1.8724350562169p-44, -0x1.ba0ceab622eeap-43,
     -0x1.ba0ceab622eeap-43, -0x1.212a4a5b08333p-43, -0x1.7d85bf40a666dp-45,
     -0x1.cec807fe8e18p-45, 0x1.66db77054926cp-43, -0x1.d0d0798270b2ap-44,
     -0x1.d0d0798270b2ap-44, 0x1.652280b2c4c2cp-44, 0x1.3d485ac1b8c2dp-43,
     -0x1.b36537e3375b2p-44, -0x1.ae6abeb2350bep-43, -0x1.ae6abeb2350bep-43,
     0x1.83602e96e3f6cp-43, 0x1.b4c86a43fad5dp-44, -0x1.1085fa3c16493p-43,
     -0x1.1085fa3c16493p-43, -0x1.eac45c4e8d84ep-43, -0x1.d6774030d58c4p-44,
     -0x1.5a048907b7d7fp-43, -0x1.5a048907b7d7fp-43, 0x1.60b794778181ep-42,
     -0x1.9c29980780174p-42, -0x1.9c29980780174p-42, 0x1.56191eee7772cp-43,
     0x1.3dbb2f45275c9p-42, 0x1.3dbb2f45275c9p-42, 0x1.accec41d52e6cp-44,
     -0x1.cacdeed70e667p-51, -0x1.cacdeed70e667p-51, 0x1.34e48593fd03ap-42,
     0x1.b40fe646de661p-44, 0x1.b40fe646de661p-44, 0x1.1b61f10522625p-43,
     -0x1.06d2be797882dp-45, -0x1.06d2be797882dp-45, 0x1.7a6e507b9dc11p-46,
     0x1.7a6e507b9dc11p-46, -0x1.a2c5b0e97c499p-43, -0x1.90b83f9527e6bp-42,
     -0x1.90b83f9527e6bp-42, 0x1.2316f576aad35p-42, 0x1.2316f576aad35p-42,
     0x1.2b7367cfe13c2p-47, -0x1.52630d9e1e717p-42, -0x1.52630d9e1e717p-42,
     -0x1.e267b0b7efae1p-44, -0x1.e267b0b7efae1p-44, -0x1.69a4a83594fabp-44,
     -0x1.69a4a83594fabp-44, -0x1.83ee22bda98a8p-42, -0x1.c3275d24d88e1p-42,
     -0x1.c3275d24d88e1p-42, 0x1.ea333ba2da8adp-43, 0x1.ea333ba2da8adp-43,
     -0x1.8ccc05ff9981fp-42, -0x1.8ccc05ff9981fp-42, -0x1.3bf4c7582193fp-42,
     -0x1.3bf4c7582193fp-42, 0x1.b7f71fcc96e51p-43, 0x1.b7f71fcc96e51p-43,
     0x1.8432a1b0e2634p-43
};

void vla_log_double(double* dst, double* src, uint32_t len){
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
        vint64m1_t tmp3;
        vint64m1_t tmp4;
        vfloat64m1_t _vx_mant;
        vbool64_t tho_cond;
        vint64m1_t tmp5;
        vuint64m1_t tmp6;
        vuint64m1_t tmp7;
        vint64m1_t tmp8;
        vint64m1_t table_index;
        vint64m1_t tmp9;
        vuint64m1_t tmp10;
        vfloat64m1_t tmp11;
        vint64m1_t tmp12;
        vuint64m1_t tmp13;
        vfloat64m1_t tmp14;
        vfloat64m1_t log_inv_hi;
        vfloat64m1_t tmp15;
        vint64m1_t tmp16;
        vuint64m1_t tmp17;
        vuint64m1_t tmp18;
        vint64m1_t tmp19;
        vint64m1_t tmp20;
        vint64m1_t _vx_exp;
        vfloat64m1_t tmp21;
        vfloat64m1_t tmp22;
        vfloat64m1_t tmp23;
        vfloat64m1_t tho;
        vfloat64m1_t corr_exp;
        vbool64_t index_comp_0;
        vfloat64m1_t seed;
        vint64m1_t tmp24;
        vint64m1_t tmp25;
        vfloat64m1_t pre_arg_red_index;
        vfloat64m1_t arg_red_index;
        vfloat64m1_t tmp26;
        vfloat64m1_t _red_vx;
        vfloat64m1_t tmp27;
        vfloat64m1_t pa_7;
        vfloat64m1_t tmp28;
        vfloat64m1_t pa_6;
        vfloat64m1_t tmp29;
        vfloat64m1_t pa_5;
        vfloat64m1_t tmp30;
        vfloat64m1_t pa_4;
        vfloat64m1_t tmp31;
        vfloat64m1_t pa_3;
        vfloat64m1_t tmp32;
        vfloat64m1_t pa_2;
        vfloat64m1_t tmp33;
        vfloat64m1_t tmp34;
        vfloat64m1_t poly;
        vfloat64m1_t tmp35;
        vfloat64m1_t tmp36;
        vfloat64m1_t tmp37;
        vfloat64m1_t tmp38;
        vfloat64m1_t tmp39;
        vfloat64m1_t tmp40;
        vfloat64m1_t tmp41;
        vfloat64m1_t tmp42;
        vfloat64m1_t tmp43;
        vfloat64m1_t m0h;
        vfloat64m1_t tmp44;
        vfloat64m1_t tmp45;
        vfloat64m1_t tmp46;
        vfloat64m1_t tmp47;
        vfloat64m1_t tmp48;
        vfloat64m1_t tmp49;
        vfloat64m1_t tmp50;
        vfloat64m1_t m0l;
        vfloat64m1_t tmp51;
        vfloat64m1_t tmp52;
        vfloat64m1_t rh0;
        vfloat64m1_t tmp53;
        vfloat64m1_t tmp54;
        vfloat64m1_t tmp55;
        vfloat64m1_t tmp56;
        vfloat64m1_t tmp57;
        vfloat64m1_t tmp58;
        vint64m1_t tmp59;
        vuint64m1_t tmp60;
        vfloat64m1_t tmp61;
        vint64m1_t tmp62;
        vuint64m1_t tmp63;
        vfloat64m1_t tmp64;
        vfloat64m1_t log_inv_lo;
        vfloat64m1_t tmp65;
        vfloat64m1_t tmp66;
        vfloat64m1_t rl0;
        vfloat64m1_t tmp67;
        vfloat64m1_t tmp68;
        vfloat64m1_t result;
        double* tmp69;
        int32_t tmp70;
        int32_t tmp71;
        int32_t tmp72;

        tmp = vsetvl_e64m1(remLen);
        l = tmp;
        tmp1 = src + offset;
        varg = vle64_v_f64m1(tmp1, l);
        vec_x = varg;
        tmp2 = vreinterpret_v_f64m1_i64m1(vec_x);
        tmp3 = vand_vx_i64m1(tmp2, INT64_C(9227875636482146303), l);
        tmp4 = vor_vx_i64m1(tmp3, INT64_C(4607182418800017408), l);
        _vx_mant = vreinterpret_v_i64m1_f64m1(tmp4);
        tho_cond = vmfgt_vf_f64m1_b64(_vx_mant, 0x1.6a09e667f3bcdp0, l);
        tmp5 = vreinterpret_v_f64m1_i64m1(_vx_mant);
        tmp6 = vreinterpret_v_i64m1_u64m1(tmp5);
        tmp7 = vsrl_vx_u64m1(tmp6, INT64_C(45), l);
        tmp8 = vreinterpret_v_u64m1_i64m1(tmp7);
        table_index = vand_vx_i64m1(tmp8, INT64_C(127), l);
        tmp9 = vmul_vx_i64m1(table_index, INT64_C(8), l);
        tmp10 = vreinterpret_v_i64m1_u64m1(tmp9);
        tmp11 = vluxei64_v_f64m1(table, tmp10, l);
        tmp12 = vmul_vx_i64m1(table_index, INT64_C(8), l);
        tmp13 = vreinterpret_v_i64m1_u64m1(tmp12);
        tmp14 = vluxei64_v_f64m1(table1, tmp13, l);
        log_inv_hi = vmerge_vvm_f64m1(tho_cond, tmp14, tmp11, l);
        tmp15 = vfneg_v_f64m1(log_inv_hi, l);
        tmp16 = vreinterpret_v_f64m1_i64m1(vec_x);
        tmp17 = vreinterpret_v_i64m1_u64m1(tmp16);
        tmp18 = vsrl_vx_u64m1(tmp17, INT64_C(52), l);
        tmp19 = vreinterpret_v_u64m1_i64m1(tmp18);
        tmp20 = vand_vx_i64m1(tmp19, INT64_C(2047), l);
        _vx_exp = vadd_vx_i64m1(tmp20, INT64_C(-1023), l);
        tmp21 = vfcvt_f_x_v_f64m1(_vx_exp, l);
        tmp22 = vfmv_v_f_f64m1(1.0, l);
        tmp23 = vfmv_v_f_f64m1(0.0, l);
        tho = vmerge_vvm_f64m1(tho_cond, tmp23, tmp22, l);
        corr_exp = vfadd_vv_f64m1(tmp21, tho, l);
        index_comp_0 = vmseq_vx_i64m1_b64(table_index, INT64_C(0), l);
        seed = vfrec7_v_f64m1(_vx_mant, l);
        tmp24 = vreinterpret_v_f64m1_i64m1(seed);
        tmp25 = vand_vx_i64m1(tmp24, INT64_C(-2), l);
        pre_arg_red_index = vreinterpret_v_i64m1_f64m1(tmp25);
        arg_red_index = vfmerge_vfm_f64m1(index_comp_0, pre_arg_red_index, 1.0, l);
        tmp26 = vfmv_v_f_f64m1(-1.0, l);
        _red_vx = vfmadd_vv_f64m1(arg_red_index, _vx_mant, tmp26, l);
        tmp27 = vfmv_v_f_f64m1(-0x1.001a684e63069p-3, l);
        pa_7 = vfmadd_vf_f64m1(_red_vx, 0x1.c7556c6215a3dp-4, tmp27, l);
        tmp28 = vfmv_v_f_f64m1(0x1.249247a899ca3p-3, l);
        pa_6 = vfmadd_vv_f64m1(_red_vx, pa_7, tmp28, l);
        tmp29 = vfmv_v_f_f64m1(-0x1.55555445b123ep-3, l);
        pa_5 = vfmadd_vv_f64m1(_red_vx, pa_6, tmp29, l);
        tmp30 = vfmv_v_f_f64m1(0x1.99999999a125cp-3, l);
        pa_4 = vfmadd_vv_f64m1(_red_vx, pa_5, tmp30, l);
        tmp31 = vfmv_v_f_f64m1(-0x1.0000000001a69p-2, l);
        pa_3 = vfmadd_vv_f64m1(_red_vx, pa_4, tmp31, l);
        tmp32 = vfmv_v_f_f64m1(0x1.5555555555555p-2, l);
        pa_2 = vfmadd_vv_f64m1(_red_vx, pa_3, tmp32, l);
        tmp33 = vfmv_v_f_f64m1(-0x1p-1, l);
        tmp34 = vfmadd_vv_f64m1(_red_vx, pa_2, tmp33, l);
        poly = vfmul_vv_f64m1(_red_vx, tmp34, l);
        tmp35 = vfmadd_vv_f64m1(_red_vx, poly, _red_vx, l);
        tmp36 = vfnmsub_vv_f64m1(_red_vx, poly, tmp35, l);
        tmp37 = vfsub_vv_f64m1(_red_vx, tmp36, l);
        tmp38 = vfsub_vv_f64m1(tmp35, tmp36, l);
        tmp39 = vfmsub_vv_f64m1(_red_vx, poly, tmp38, l);
        tmp40 = vfadd_vv_f64m1(tmp37, tmp39, l);
        tmp41 = vfmul_vv_f64m1(_red_vx, poly, l);
        tmp42 = vfmsub_vv_f64m1(_red_vx, poly, tmp41, l);
        tmp43 = vfadd_vv_f64m1(tmp40, tmp42, l);
        m0h = vfadd_vv_f64m1(tmp35, tmp43, l);
        tmp44 = vfmadd_vf_f64m1(corr_exp, 0x1.62e42fefa4p-1, m0h, l);
        tmp45 = vfsub_vv_f64m1(tmp44, m0h, l);
        tmp46 = vfmsub_vf_f64m1(corr_exp, 0x1.62e42fefa4p-1, tmp45, l);
        tmp47 = vfsub_vv_f64m1(tmp44, tmp45, l);
        tmp48 = vfsub_vv_f64m1(m0h, tmp47, l);
        tmp49 = vfadd_vv_f64m1(tmp46, tmp48, l);
        tmp50 = vfsub_vv_f64m1(m0h, tmp35, l);
        m0l = vfsub_vv_f64m1(tmp43, tmp50, l);
        tmp51 = vfmadd_vf_f64m1(corr_exp, -0x1.8432a1b0e2634p-43, m0l, l);
        tmp52 = vfadd_vv_f64m1(tmp49, tmp51, l);
        rh0 = vfadd_vv_f64m1(tmp44, tmp52, l);
        tmp53 = vfadd_vv_f64m1(tmp15, rh0, l);
        tmp54 = vfsub_vv_f64m1(tmp53, rh0, l);
        tmp55 = vfsub_vv_f64m1(tmp15, tmp54, l);
        tmp56 = vfsub_vv_f64m1(tmp53, tmp54, l);
        tmp57 = vfsub_vv_f64m1(rh0, tmp56, l);
        tmp58 = vfadd_vv_f64m1(tmp55, tmp57, l);
        tmp59 = vmul_vx_i64m1(table_index, INT64_C(8), l);
        tmp60 = vreinterpret_v_i64m1_u64m1(tmp59);
        tmp61 = vluxei64_v_f64m1(table2, tmp60, l);
        tmp62 = vmul_vx_i64m1(table_index, INT64_C(8), l);
        tmp63 = vreinterpret_v_i64m1_u64m1(tmp62);
        tmp64 = vluxei64_v_f64m1(table3, tmp63, l);
        log_inv_lo = vmerge_vvm_f64m1(tho_cond, tmp64, tmp61, l);
        tmp65 = vfneg_v_f64m1(log_inv_lo, l);
        tmp66 = vfsub_vv_f64m1(rh0, tmp44, l);
        rl0 = vfsub_vv_f64m1(tmp52, tmp66, l);
        tmp67 = vfadd_vv_f64m1(tmp65, rl0, l);
        tmp68 = vfadd_vv_f64m1(tmp58, tmp67, l);
        result = vfadd_vv_f64m1(tmp53, tmp68, l);
        tmp69 = dst + offset;
        vse64_v_f64m1(tmp69, result, l);
        tmp70 =  (int32_t) l;
        tmp71 = remLen - tmp70;
        remLen = tmp71;
        tmp72 = offset + tmp70;
        offset = tmp72;
    }
}
