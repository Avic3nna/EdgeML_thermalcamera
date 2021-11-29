/**
  ******************************************************************************
  * @file    network.c
  * @author  AST Embedded Analytics Research Platform
  * @date    Mon Nov 15 23:32:39 2021
  * @brief   AI Tool Automatic Code Generator for Embedded NN computing
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */


#include "network.h"

#include "ai_platform_interface.h"
#include "ai_math_helpers.h"

#include "core_common.h"
#include "core_convert.h"

#include "layers.h"




#undef AI_NET_OBJ_INSTANCE
#define AI_NET_OBJ_INSTANCE g_network
 
#undef AI_NETWORK_MODEL_SIGNATURE
#define AI_NETWORK_MODEL_SIGNATURE     "efe3fecc321b20b8f03947eeef7b4b49"

#ifndef AI_TOOLS_REVISION_ID
#define AI_TOOLS_REVISION_ID     ""
#endif

#undef AI_TOOLS_DATE_TIME
#define AI_TOOLS_DATE_TIME   "Mon Nov 15 23:32:39 2021"

#undef AI_TOOLS_COMPILE_TIME
#define AI_TOOLS_COMPILE_TIME    __DATE__ " " __TIME__

#undef AI_NETWORK_N_BATCHES
#define AI_NETWORK_N_BATCHES         (1)




/**  Array declarations section  **********************************************/
/* Array#0 */
AI_ARRAY_OBJ_DECLARE(
  quantize_conv2d_input_output_array, AI_ARRAY_FORMAT_S8|AI_FMT_FLAG_IS_IO,
  NULL, NULL, 784, AI_STATIC)

/* Array#1 */
AI_ARRAY_OBJ_DECLARE(
  quantize_conv2d_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 21632, AI_STATIC)

/* Array#2 */
AI_ARRAY_OBJ_DECLARE(
  quantize_conv2d_1_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 9216, AI_STATIC)

/* Array#3 */
AI_ARRAY_OBJ_DECLARE(
  quantize_dense_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 128, AI_STATIC)

/* Array#4 */
AI_ARRAY_OBJ_DECLARE(
  quantize_dense_1_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 10, AI_STATIC)

/* Array#5 */
AI_ARRAY_OBJ_DECLARE(
  quantize_dense_1_fmt_conv_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 10, AI_STATIC)

/* Array#6 */
AI_ARRAY_OBJ_DECLARE(
  softmax_8_output_array, AI_ARRAY_FORMAT_FLOAT|AI_FMT_FLAG_IS_IO,
  NULL, NULL, 10, AI_STATIC)

/* Array#7 */
AI_ARRAY_OBJ_DECLARE(
  quantize_conv2d_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 288, AI_STATIC)

/* Array#8 */
AI_ARRAY_OBJ_DECLARE(
  quantize_conv2d_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 32, AI_STATIC)

/* Array#9 */
AI_ARRAY_OBJ_DECLARE(
  quantize_conv2d_1_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 18432, AI_STATIC)

/* Array#10 */
AI_ARRAY_OBJ_DECLARE(
  quantize_conv2d_1_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 64, AI_STATIC)

/* Array#11 */
AI_ARRAY_OBJ_DECLARE(
  quantize_dense_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1179648, AI_STATIC)

/* Array#12 */
AI_ARRAY_OBJ_DECLARE(
  quantize_dense_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)

/* Array#13 */
AI_ARRAY_OBJ_DECLARE(
  quantize_dense_1_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1280, AI_STATIC)

/* Array#14 */
AI_ARRAY_OBJ_DECLARE(
  quantize_dense_1_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 10, AI_STATIC)

/* Array#15 */
AI_ARRAY_OBJ_DECLARE(
  quantize_conv2d_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1060, AI_STATIC)

/* Array#16 */
AI_ARRAY_OBJ_DECLARE(
  quantize_conv2d_1_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 7168, AI_STATIC)

/* Array#17 */
AI_ARRAY_OBJ_DECLARE(
  quantize_conv2d_1_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3072, AI_STATIC)

/* Array#18 */
AI_ARRAY_OBJ_DECLARE(
  quantize_dense_scratch0_array, AI_ARRAY_FORMAT_S16,
  NULL, NULL, 9856, AI_STATIC)

/* Array#19 */
AI_ARRAY_OBJ_DECLARE(
  quantize_dense_1_scratch0_array, AI_ARRAY_FORMAT_S16,
  NULL, NULL, 178, AI_STATIC)

/**  Array metadata declarations section  *************************************/
/* Int quant #0 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(quantize_conv2d_input_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00392156862745098f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #1 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(quantize_conv2d_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.003308389233607872f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #2 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(quantize_conv2d_1_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.012067496542837106f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #3 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(quantize_dense_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0784285825841567f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #4 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(quantize_dense_1_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.2356340670118145f),
    AI_PACK_INTQ_ZP(-18)))

/* Int quant #5 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(quantize_conv2d_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 32,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0018421447887195376f, 0.0021836222626092864f, 0.002436667211412445f, 0.002294717811224029f, 0.002323966326676016f, 0.0012738528683429629f, 0.0013132043710843784f, 0.001645353483402823f, 0.002188276352844839f, 0.001481207219634469f, 0.0019420984927124864f, 0.002052845213356919f, 0.0013650581827313881f, 0.0018170736436768779f, 0.001000684429341414f, 0.0020324435290389174f, 0.0014086789268208302f, 0.0015945125987210612f, 0.0015754565948576439f, 0.0023736880989525264f, 0.0011673250536280355f, 0.001790216236602603f, 0.0017336428634763703f, 0.0013735538392555056f, 0.0022880045447762555f, 0.0018732409308275838f, 0.001863672742693443f, 0.0011683449031799798f, 0.0016961263155374f, 0.001526039768391707f, 0.0014471113681793213f, 0.0016795055368753868f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #6 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(quantize_conv2d_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 32,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(7.224097210664853e-06f, 8.563224559252103e-06f, 9.555557691813509e-06f, 8.998893377349133e-06f, 9.113593437945161e-06f, 4.995501444482207e-06f, 5.149821063075993e-06f, 6.452366601579698e-06f, 8.581475893509173e-06f, 5.8086557632724275e-06f, 7.616072520441123e-06f, 8.050373385713408e-06f, 5.353169344044659e-06f, 7.125778994811286e-06f, 3.924252664083976e-06f, 7.970366780544774e-06f, 5.524231085571883e-06f, 6.252990583219848e-06f, 6.178261156304485e-06f, 9.308580780205986e-06f, 4.577745308345237e-06f, 7.02045582981413e-06f, 6.798599464613217e-06f, 5.386485644139238e-06f, 8.972566842259825e-06f, 7.346042865990525e-06f, 7.3085205595821295e-06f, 4.5817447183528616e-06f, 6.65147574720549e-06f, 5.984469679967478e-06f, 5.674946541879691e-06f, 6.5862962230407324e-06f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #7 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(quantize_conv2d_1_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 64,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0015135799336621141f, 0.0021756002752799687f, 0.0020156310299250086f, 0.0017502246879217192f, 0.002111378851837999f, 0.002098438073330977f, 0.001486408780878923f, 0.0020176662704137365f, 0.0027025719796578717f, 0.00233811632854732f, 0.0018977096934956828f, 0.0014251215955403847f, 0.002920483275661318f, 0.001856788875549797f, 0.0016804174410076592f, 0.0026048797322070507f, 0.0021588459728271005f, 0.0017250865463196762f, 0.0019418773219341367f, 0.002097231196606253f, 0.002597068238446093f, 0.0016533256046415315f, 0.0028873792314153958f, 0.0022787836592967118f, 0.0020507090673671934f, 0.0021005608434752215f, 0.002240105407444511f, 0.0023017084504675677f, 0.001483030793235058f, 0.0025209728188402072f, 0.002679450540092048f, 0.00225616486992423f, 0.0018441806158681555f, 0.0024069329415719342f, 0.0017924150378685298f, 0.001949001367636553f, 0.0019322254760997502f, 0.0016878627416655773f, 0.0018486709106625534f, 0.002068471955502127f, 0.002648291390711867f, 0.0012722477668852318f, 0.0021894919121359276f, 0.0020406415143350916f, 0.0027332230815737264f, 0.0018224411123380886f, 0.0018594416342382356f, 0.0023731504838297684f, 0.0028492461039325385f, 0.0022871538879364493f, 0.0013543760447990237f, 0.0018880158428132064f, 0.0021817231272149274f, 0.001775223439134012f, 0.0018197190104507087f, 0.0022687792308687224f, 0.0014804243806778915f, 0.0024286215230235903f, 0.0020243135962899274f, 0.0021674980328777642f, 0.0024490304819242224f, 0.001392014969990948f, 0.0024070918090700164f, 0.0017691862395429235f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #8 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(quantize_conv2d_1_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 64,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(5.0075115567326555e-06f, 7.197732527370571e-06f, 6.6684919983298445e-06f, 5.790424513914913e-06f, 6.985263061488186e-06f, 6.94244992920105e-06f, 4.917618807400031e-06f, 6.675225366050555e-06f, 8.941160040550415e-06f, 7.735398888288719e-06f, 6.278362318474411e-06f, 4.714856943267881e-06f, 9.662095426129756e-06f, 6.142980324951815e-06f, 5.559474969796631e-06f, 8.617956060877163e-06f, 7.1423027735188915e-06f, 5.707257756885804e-06f, 6.424486024874186e-06f, 6.938457111238682e-06f, 8.592112599020014e-06f, 5.469844630044268e-06f, 9.552574362557667e-06f, 7.53910332413879e-06f, 6.784543799739662e-06f, 6.9494728790916935e-06f, 7.411140612136195e-06f, 7.614947456431158e-06f, 4.906443109447807e-06f, 8.34035933206903e-06f, 8.864665318825328e-06f, 7.464271564901627e-06f, 6.1012672943665405e-06f, 7.963071029912712e-06f, 5.93000661344109e-06f, 6.44805514097579e-06f, 6.392553962031258e-06f, 5.58410692233426e-06f, 6.116122937320052e-06f, 6.843310347603058e-06f, 8.761578724487559e-06f, 4.209090814444758e-06f, 7.243691469182016e-06f, 6.751236415679481e-06f, 9.042565816127047e-06f, 6.029344554943687e-06f, 6.151756683236005e-06f, 7.851305510433719e-06f, 9.426415134149586e-06f, 7.566795298453334e-06f, 4.4808031248695025e-06f, 6.246291287244305e-06f, 7.217989304791163e-06f, 5.873130113279304e-06f, 6.020338782366695e-06f, 7.50600478083923e-06f, 4.8978200822053374e-06f, 8.034825299279598e-06f, 6.697217307411628e-06f, 7.170927155839036e-06f, 8.102346079175594e-06f, 4.605327339739037e-06f, 7.963596625432937e-06f, 5.8531567071510055e-06f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #9 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(quantize_dense_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0014446340207978495f, 0.001508334372925946f, 0.0016213881922519113f, 0.0014649543940551638f, 0.0014748861939888301f, 0.0002467314617370996f, 0.0014998095007393304f, 0.00038621017313379f, 0.0013467319837705356f, 0.0014749652757419375f, 0.0005326037566492877f, 0.0013829137631288665f, 0.00162853112840277f, 0.0011587735470824354f, 0.001769631983726982f, 0.001945739655982791f, 0.0013233476032422284f, 0.0013593940988300354f, 0.0016413573908993578f, 0.0011756861303734967f, 0.0013126486868370237f, 0.001653047645185876f, 0.0016007570065851287f, 0.001527806435983012f, 0.001539736164836433f, 0.0014225391187067107f, 0.0017306493727240976f, 0.0014824522292520117f, 0.0017460368749663586f, 0.0002460400977237957f, 0.0014994254731756495f, 0.0016979759368370836f, 0.001785678187693198f, 0.0017711662166700589f, 0.0016350676928918193f, 0.0013565466863902536f, 0.001685117760042506f, 0.0016346066955506332f, 0.0002454187369018089f, 0.0015104157248819908f, 0.001183734400065865f, 0.0002460062034486786f, 0.001574168993732122f, 0.001326257788290189f, 0.0011596941337810728f, 0.0015591797162228683f, 0.0015414207000432052f, 0.0013984445277161485f, 0.0014262658169889074f, 0.0015483929181662132f, 0.0013500883823304665f, 0.001469457947363065f, 0.00025556488769260915f, 0.001403942234872833f, 0.0013654296557734332f, 0.0012107242749431941f, 0.0015223914478707501f, 0.0014011103102541346f, 0.0014793073802482424f, 0.001468051606275904f, 0.0014762113413472814f, 0.0013782108627905056f, 0.001341279918753256f, 0.001500077252312908f, 0.0014474983290424497f, 0.001625775821565643f, 0.0014029743633871003f, 0.001373722562639732f, 0.0013098276740922702f, 0.0014901995424210555f, 0.00151234172929929f, 0.00024651997084692705f, 0.002104674267956591f, 0.0016708611034032866f, 0.001472134876438952f, 0.000246557487746862f, 0.0016148868273562333f, 0.0016004231971079909f, 0.0003452189266681671f, 0.001591491300290025f, 0.001296745745215829f, 0.0015318101550650409f, 0.0002829453020583926f, 0.0014662669868919793f, 0.0015176092311153262f, 0.0014709001920354648f, 0.0002453184620601924f, 0.0015593188719486627f, 0.00024645391294336695f, 0.0015946529277666348f, 0.0002464402731009356f, 0.0016807025577139667f, 0.001559800402385982f, 0.0015904445817151408f, 0.000246625510961052f, 0.00037702214060805913f, 0.0014754791898051584f, 0.0014341795069026195f, 0.0015248865123808854f, 0.0015572175735563743f, 0.0013337782987459439f, 0.0016276401093625647f, 0.00038092131689777527f, 0.0014851097985515444f, 0.000246241102068443f, 0.0016732635929828554f, 0.00024636245266659054f, 0.0014625373553103348f, 0.0013725984049594308f, 0.0014507940669698039f, 0.001464429098790086f, 0.0016181669601305264f, 0.001518108596013287f, 0.0013178593999757541f, 0.001493848332269924f, 0.0002466558999433292f, 0.001647661051412267f, 0.0016946380767296617f, 0.0014205091581569883f, 0.001464315169439541f, 0.0014569652596796592f, 0.0014368224097049142f, 0.0014885199351573554f, 0.0015581678452454215f, 0.0016388072976915855f, 0.00024664836136374885f, 0.0016582821767161212f, 0.001514596615250655f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #10 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(quantize_dense_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 128,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(1.7433116051642916e-05f, 1.8201819830726226e-05f, 1.9566096404596845e-05f, 1.7678332085674717e-05f, 1.7798184047038384e-05f, 2.977431061521595e-06f, 1.8098945965086115e-05f, 4.660589929100531e-06f, 1.6251683558279096e-05f, 1.779913836582061e-05f, 6.427193992067334e-06f, 1.668830705559945e-05f, 1.965229376190304e-05f, 1.398349577334838e-05f, 2.1355027845719326e-05f, 2.348020657183339e-05f, 1.596949262709736e-05f, 1.6404483587984616e-05f, 1.980707464023813e-05f, 1.4187588313743706e-05f, 1.584038349036545e-05f, 1.9948146743425577e-05f, 1.9317129642888315e-05f, 1.843679888434928e-05f, 1.8580760846044918e-05f, 1.7166485897043773e-05f, 2.0884605322211252e-05f, 1.788948715141981e-05f, 2.1070293952322634e-05f, 2.969088028681208e-06f, 1.809431171378904e-05f, 2.0490318747602103e-05f, 2.1548665356607295e-05f, 2.137354219645581e-05f, 1.973117373127667e-05f, 1.6370122448211517e-05f, 2.033515274358635e-05f, 1.972561064745565e-05f, 2.9615897591100283e-06f, 1.8226936538260224e-05f, 1.4284710780432183e-05f, 2.9686790096334104e-06f, 1.8996278889703746e-05f, 1.600461127510264e-05f, 1.3994604950151567e-05f, 1.8815395835181204e-05f, 1.860108896882893e-05f, 1.6875724503564093e-05f, 1.721145781568038e-05f, 1.8685226186924237e-05f, 1.6292186886297445e-05f, 1.7732678699648297e-05f, 3.084028398701114e-06f, 1.6942068065670912e-05f, 1.6477317650533164e-05f, 1.4610411002205957e-05f, 1.8371453534025054e-05f, 1.6907893825125194e-05f, 1.785153669693908e-05f, 1.771570768344093e-05f, 1.7814175258205246e-05f, 1.6631554822024973e-05f, 1.618589078253175e-05f, 1.8102177056274604e-05f, 1.746768108148225e-05f, 1.961904410617155e-05f, 1.693038827986292e-05f, 1.6577392275472295e-05f, 1.5806340928820837e-05f, 1.7982977826303524e-05f, 1.825017858990747e-05f, 2.974878895935596e-06f, 2.5398149452364377e-05f, 2.0163110588880152e-05f, 1.7764982532016984e-05f, 2.975331630995859e-06f, 1.9487641206194526e-05f, 1.9313101398176988e-05f, 4.165928204090043e-06f, 1.920531576420521e-05f, 1.564847479733074e-05f, 1.848511375053015e-05f, 3.4144414544016534e-06f, 1.769417179519514e-05f, 1.8313744149861878e-05f, 1.7750082982246408e-05f, 2.9603796928054878e-06f, 1.8817075096421143e-05f, 2.9740817424127575e-06f, 1.9243468692848935e-05f, 2.9739171436613723e-06f, 2.0281872304750772e-05f, 1.8822885963308763e-05f, 1.9192684491421468e-05f, 2.9761525008979295e-06f, 4.549713378360799e-06f, 1.7805340022001843e-05f, 1.7306956241355186e-05f, 1.8401562716375265e-05f, 1.8791717685336734e-05f, 1.6095365009027832e-05f, 1.9641541392715757e-05f, 4.596766674756861e-06f, 1.7921557359754273e-05f, 2.971513647915335e-06f, 2.01921026235758e-05f, 2.9729780458389514e-06f, 1.764916447897759e-05f, 1.6563826506551656e-05f, 1.750745238752669e-05f, 1.767199308687942e-05f, 1.9527224197108355e-05f, 1.8319770234041632e-05f, 1.5903263753152795e-05f, 1.8027009585190282e-05f, 2.9765192198365003e-06f, 1.9883144041684883e-05f, 2.0450039132295314e-05f, 1.7141989355127904e-05f, 1.767061824483559e-05f, 1.7581923234218052e-05f, 1.7338849461784932e-05f, 1.79627091714555e-05f, 1.8803185085659065e-05f, 1.977630139926943e-05f, 2.9764282480534766e-06f, 2.0011314434570183e-05f, 1.8277389418330063e-05f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #11 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(quantize_dense_1_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 10,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.002325765729889156f, 0.002239717742589515f, 0.002414117178579015f, 0.002655174084535734f, 0.0026546230935674954f, 0.002655199662906917f, 0.0025727716017895797f, 0.0023984493702415405f, 0.002253495802090863f, 0.0020980290540560022f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #12 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(quantize_dense_1_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 10,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00018240650961801318f, 0.00017565788793988282f, 0.00018933578850801567f, 0.00020824153996432349f, 0.00020819832652366787f, 0.00020824354603972019f, 0.00020177883004112717f, 0.0001881069845079073f, 0.0001767384816173337f, 0.00016454544492999133f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #13 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(quantize_conv2d_1_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.012067496542837106f),
    AI_PACK_INTQ_ZP(-128)))

/**  Tensor declarations section  *********************************************/
/* Tensor #0 */
AI_TENSOR_OBJ_DECLARE(
  quantize_conv2d_input_output, AI_STATIC,
  0, 0x1,
  AI_SHAPE_INIT(4, 1, 1, 28, 28), AI_STRIDE_INIT(4, 1, 1, 1, 28),
  1, &quantize_conv2d_input_output_array, &quantize_conv2d_input_output_intq)

/* Tensor #1 */
AI_TENSOR_OBJ_DECLARE(
  quantize_conv2d_output, AI_STATIC,
  1, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 26, 26), AI_STRIDE_INIT(4, 1, 1, 32, 832),
  1, &quantize_conv2d_output_array, &quantize_conv2d_output_intq)

/* Tensor #2 */
AI_TENSOR_OBJ_DECLARE(
  quantize_conv2d_1_output, AI_STATIC,
  2, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 12, 12), AI_STRIDE_INIT(4, 1, 1, 64, 768),
  1, &quantize_conv2d_1_output_array, &quantize_conv2d_1_output_intq)

/* Tensor #3 */
AI_TENSOR_OBJ_DECLARE(
  quantize_conv2d_1_output0, AI_STATIC,
  3, 0x1,
  AI_SHAPE_INIT(4, 1, 9216, 1, 1), AI_STRIDE_INIT(4, 1, 1, 9216, 9216),
  1, &quantize_conv2d_1_output_array, &quantize_conv2d_1_output_intq)

/* Tensor #4 */
AI_TENSOR_OBJ_DECLARE(
  quantize_dense_output, AI_STATIC,
  4, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 1, 1, 128, 128),
  1, &quantize_dense_output_array, &quantize_dense_output_intq)

/* Tensor #5 */
AI_TENSOR_OBJ_DECLARE(
  quantize_dense_1_output, AI_STATIC,
  5, 0x1,
  AI_SHAPE_INIT(4, 1, 10, 1, 1), AI_STRIDE_INIT(4, 1, 1, 10, 10),
  1, &quantize_dense_1_output_array, &quantize_dense_1_output_intq)

/* Tensor #6 */
AI_TENSOR_OBJ_DECLARE(
  quantize_dense_1_fmt_conv_output, AI_STATIC,
  6, 0x0,
  AI_SHAPE_INIT(4, 1, 10, 1, 1), AI_STRIDE_INIT(4, 4, 4, 40, 40),
  1, &quantize_dense_1_fmt_conv_output_array, NULL)

/* Tensor #7 */
AI_TENSOR_OBJ_DECLARE(
  softmax_8_output, AI_STATIC,
  7, 0x0,
  AI_SHAPE_INIT(4, 1, 10, 1, 1), AI_STRIDE_INIT(4, 4, 4, 40, 40),
  1, &softmax_8_output_array, NULL)

/* Tensor #8 */
AI_TENSOR_OBJ_DECLARE(
  quantize_conv2d_weights, AI_STATIC,
  8, 0x1,
  AI_SHAPE_INIT(4, 1, 3, 3, 32), AI_STRIDE_INIT(4, 1, 1, 3, 9),
  1, &quantize_conv2d_weights_array, &quantize_conv2d_weights_intq)

/* Tensor #9 */
AI_TENSOR_OBJ_DECLARE(
  quantize_conv2d_bias, AI_STATIC,
  9, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &quantize_conv2d_bias_array, &quantize_conv2d_bias_intq)

/* Tensor #10 */
AI_TENSOR_OBJ_DECLARE(
  quantize_conv2d_1_weights, AI_STATIC,
  10, 0x1,
  AI_SHAPE_INIT(4, 32, 3, 3, 64), AI_STRIDE_INIT(4, 1, 32, 96, 288),
  1, &quantize_conv2d_1_weights_array, &quantize_conv2d_1_weights_intq)

/* Tensor #11 */
AI_TENSOR_OBJ_DECLARE(
  quantize_conv2d_1_bias, AI_STATIC,
  11, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 1, 1), AI_STRIDE_INIT(4, 4, 4, 256, 256),
  1, &quantize_conv2d_1_bias_array, &quantize_conv2d_1_bias_intq)

/* Tensor #12 */
AI_TENSOR_OBJ_DECLARE(
  quantize_dense_weights, AI_STATIC,
  12, 0x1,
  AI_SHAPE_INIT(4, 9216, 128, 1, 1), AI_STRIDE_INIT(4, 1, 9216, 1179648, 1179648),
  1, &quantize_dense_weights_array, &quantize_dense_weights_intq)

/* Tensor #13 */
AI_TENSOR_OBJ_DECLARE(
  quantize_dense_bias, AI_STATIC,
  13, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &quantize_dense_bias_array, &quantize_dense_bias_intq)

/* Tensor #14 */
AI_TENSOR_OBJ_DECLARE(
  quantize_dense_1_weights, AI_STATIC,
  14, 0x1,
  AI_SHAPE_INIT(4, 128, 10, 1, 1), AI_STRIDE_INIT(4, 1, 128, 1280, 1280),
  1, &quantize_dense_1_weights_array, &quantize_dense_1_weights_intq)

/* Tensor #15 */
AI_TENSOR_OBJ_DECLARE(
  quantize_dense_1_bias, AI_STATIC,
  15, 0x1,
  AI_SHAPE_INIT(4, 1, 10, 1, 1), AI_STRIDE_INIT(4, 4, 4, 40, 40),
  1, &quantize_dense_1_bias_array, &quantize_dense_1_bias_intq)

/* Tensor #16 */
AI_TENSOR_OBJ_DECLARE(
  quantize_conv2d_scratch0, AI_STATIC,
  16, 0x0,
  AI_SHAPE_INIT(4, 1, 1060, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1060, 1060),
  1, &quantize_conv2d_scratch0_array, NULL)

/* Tensor #17 */
AI_TENSOR_OBJ_DECLARE(
  quantize_conv2d_1_scratch0, AI_STATIC,
  17, 0x0,
  AI_SHAPE_INIT(4, 1, 7168, 1, 1), AI_STRIDE_INIT(4, 1, 1, 7168, 7168),
  1, &quantize_conv2d_1_scratch0_array, NULL)

/* Tensor #18 */
AI_TENSOR_OBJ_DECLARE(
  quantize_conv2d_1_scratch1, AI_STATIC,
  18, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 24, 2), AI_STRIDE_INIT(4, 1, 1, 64, 1536),
  1, &quantize_conv2d_1_scratch1_array, &quantize_conv2d_1_scratch1_intq)

/* Tensor #19 */
AI_TENSOR_OBJ_DECLARE(
  quantize_dense_scratch0, AI_STATIC,
  19, 0x0,
  AI_SHAPE_INIT(4, 1, 9856, 1, 1), AI_STRIDE_INIT(4, 2, 2, 19712, 19712),
  1, &quantize_dense_scratch0_array, NULL)

/* Tensor #20 */
AI_TENSOR_OBJ_DECLARE(
  quantize_dense_1_scratch0, AI_STATIC,
  20, 0x0,
  AI_SHAPE_INIT(4, 1, 178, 1, 1), AI_STRIDE_INIT(4, 2, 2, 356, 356),
  1, &quantize_dense_1_scratch0_array, NULL)



/**  Layer declarations section  **********************************************/


AI_TENSOR_CHAIN_OBJ_DECLARE(
  softmax_8_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &quantize_dense_1_fmt_conv_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &softmax_8_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  softmax_8_layer, 12,
  NL_TYPE, 0x0, NULL,
  nl, forward_sm,
  &softmax_8_chain,
  NULL, &softmax_8_layer, AI_STATIC, 
  .nl_params = NULL, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  quantize_dense_1_fmt_conv_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &quantize_dense_1_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &quantize_dense_1_fmt_conv_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  quantize_dense_1_fmt_conv_layer, 11,
  NL_TYPE, 0x0, NULL,
  nl, node_convert,
  &quantize_dense_1_fmt_conv_chain,
  NULL, &softmax_8_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  quantize_dense_1_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &quantize_dense_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &quantize_dense_1_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &quantize_dense_1_weights, &quantize_dense_1_bias),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &quantize_dense_1_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  quantize_dense_1_layer, 11,
  DENSE_TYPE, 0x0, NULL,
  dense, forward_dense_integer_SSSA_ch,
  &quantize_dense_1_chain,
  NULL, &quantize_dense_1_fmt_conv_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  quantize_dense_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &quantize_conv2d_1_output0),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &quantize_dense_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &quantize_dense_weights, &quantize_dense_bias),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &quantize_dense_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  quantize_dense_layer, 8,
  DENSE_TYPE, 0x0, NULL,
  dense, forward_dense_integer_SSSA_ch,
  &quantize_dense_chain,
  NULL, &quantize_dense_1_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  quantize_conv2d_1_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &quantize_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &quantize_conv2d_1_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &quantize_conv2d_1_weights, &quantize_conv2d_1_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &quantize_conv2d_1_scratch0, &quantize_conv2d_1_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  quantize_conv2d_1_layer, 5,
  OPTIMIZED_CONV2D_TYPE, 0x0, NULL,
  conv2d_nl_pool, forward_conv2d_nl_pool_integer_SSSA_ch,
  &quantize_conv2d_1_chain,
  NULL, &quantize_dense_layer, AI_STATIC, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .pool_size = AI_SHAPE_2D_INIT(2, 2), 
  .pool_stride = AI_SHAPE_2D_INIT(2, 2), 
  .pool_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .pool_func = pool_func_mp_array_integer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  quantize_conv2d_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &quantize_conv2d_input_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &quantize_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &quantize_conv2d_weights, &quantize_conv2d_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &quantize_conv2d_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  quantize_conv2d_layer, 1,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &quantize_conv2d_chain,
  NULL, &quantize_conv2d_1_layer, AI_STATIC, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)


AI_NETWORK_OBJ_DECLARE(
  AI_NET_OBJ_INSTANCE, AI_STATIC,
  AI_BUFFER_OBJ_INIT(AI_BUFFER_FORMAT_U8,
                     1, 1, 1200584, 1,
                     NULL),
  AI_BUFFER_OBJ_INIT(AI_BUFFER_FORMAT_U8,
                     1, 1, 32704, 1,
                     NULL),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_NETWORK_IN_NUM, &quantize_conv2d_input_output),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_NETWORK_OUT_NUM, &softmax_8_output),
  &quantize_conv2d_layer, 0, NULL)



AI_DECLARE_STATIC
ai_bool network_configure_activations(
  ai_network* net_ctx, const ai_network_params* params)
{
  AI_ASSERT(net_ctx)
  AI_UNUSED(net_ctx)

  ai_ptr activations_map[1] = AI_C_ARRAY_INIT;

  if (ai_platform_get_activations_map(activations_map, 1, params)) {
    /* Updating activations (byte) offsets */
    quantize_conv2d_input_output_array.data = AI_PTR(NULL);
    quantize_conv2d_input_output_array.data_start = AI_PTR(NULL);
    quantize_conv2d_output_array.data = AI_PTR(activations_map[0] + 832);
    quantize_conv2d_output_array.data_start = AI_PTR(activations_map[0] + 832);
    quantize_conv2d_1_output_array.data = AI_PTR(activations_map[0] + 0);
    quantize_conv2d_1_output_array.data_start = AI_PTR(activations_map[0] + 0);
    quantize_dense_output_array.data = AI_PTR(activations_map[0] + 28928);
    quantize_dense_output_array.data_start = AI_PTR(activations_map[0] + 28928);
    quantize_dense_1_output_array.data = AI_PTR(activations_map[0] + 356);
    quantize_dense_1_output_array.data_start = AI_PTR(activations_map[0] + 356);
    quantize_dense_1_fmt_conv_output_array.data = AI_PTR(activations_map[0] + 0);
    quantize_dense_1_fmt_conv_output_array.data_start = AI_PTR(activations_map[0] + 0);
    softmax_8_output_array.data = AI_PTR(NULL);
    softmax_8_output_array.data_start = AI_PTR(NULL);
    quantize_conv2d_scratch0_array.data = AI_PTR(activations_map[0] + 22464);
    quantize_conv2d_scratch0_array.data_start = AI_PTR(activations_map[0] + 22464);
    quantize_conv2d_1_scratch0_array.data = AI_PTR(activations_map[0] + 22464);
    quantize_conv2d_1_scratch0_array.data_start = AI_PTR(activations_map[0] + 22464);
    quantize_conv2d_1_scratch1_array.data = AI_PTR(activations_map[0] + 29632);
    quantize_conv2d_1_scratch1_array.data_start = AI_PTR(activations_map[0] + 29632);
    quantize_dense_scratch0_array.data = AI_PTR(activations_map[0] + 9216);
    quantize_dense_scratch0_array.data_start = AI_PTR(activations_map[0] + 9216);
    quantize_dense_1_scratch0_array.data = AI_PTR(activations_map[0] + 0);
    quantize_dense_1_scratch0_array.data_start = AI_PTR(activations_map[0] + 0);
    
    return true;
  }
  return false;
}



AI_DECLARE_STATIC
ai_bool network_configure_weights(
  ai_network* net_ctx, const ai_network_params* params)
{
  AI_ASSERT(net_ctx)
  AI_UNUSED(net_ctx)

  ai_ptr weights_map[1] = AI_C_ARRAY_INIT;

  if (ai_platform_get_weights_map(weights_map, 1, params)) {
    /* Updating weights with array addresses */
    
    quantize_conv2d_weights_array.format |= AI_FMT_FLAG_CONST;
    quantize_conv2d_weights_array.data = AI_PTR(weights_map[0] + 0);
    quantize_conv2d_weights_array.data_start = AI_PTR(weights_map[0] + 0);
    quantize_conv2d_bias_array.format |= AI_FMT_FLAG_CONST;
    quantize_conv2d_bias_array.data = AI_PTR(weights_map[0] + 288);
    quantize_conv2d_bias_array.data_start = AI_PTR(weights_map[0] + 288);
    quantize_conv2d_1_weights_array.format |= AI_FMT_FLAG_CONST;
    quantize_conv2d_1_weights_array.data = AI_PTR(weights_map[0] + 416);
    quantize_conv2d_1_weights_array.data_start = AI_PTR(weights_map[0] + 416);
    quantize_conv2d_1_bias_array.format |= AI_FMT_FLAG_CONST;
    quantize_conv2d_1_bias_array.data = AI_PTR(weights_map[0] + 18848);
    quantize_conv2d_1_bias_array.data_start = AI_PTR(weights_map[0] + 18848);
    quantize_dense_weights_array.format |= AI_FMT_FLAG_CONST;
    quantize_dense_weights_array.data = AI_PTR(weights_map[0] + 19104);
    quantize_dense_weights_array.data_start = AI_PTR(weights_map[0] + 19104);
    quantize_dense_bias_array.format |= AI_FMT_FLAG_CONST;
    quantize_dense_bias_array.data = AI_PTR(weights_map[0] + 1198752);
    quantize_dense_bias_array.data_start = AI_PTR(weights_map[0] + 1198752);
    quantize_dense_1_weights_array.format |= AI_FMT_FLAG_CONST;
    quantize_dense_1_weights_array.data = AI_PTR(weights_map[0] + 1199264);
    quantize_dense_1_weights_array.data_start = AI_PTR(weights_map[0] + 1199264);
    quantize_dense_1_bias_array.format |= AI_FMT_FLAG_CONST;
    quantize_dense_1_bias_array.data = AI_PTR(weights_map[0] + 1200544);
    quantize_dense_1_bias_array.data_start = AI_PTR(weights_map[0] + 1200544);
    return true;
  }
  return false;
}


/**  PUBLIC APIs SECTION  *****************************************************/
AI_DEPRECATED
AI_API_ENTRY
ai_bool ai_network_get_info(
  ai_handle network, ai_network_report* report)
{
  ai_network* net_ctx = AI_NETWORK_ACQUIRE_CTX(network);

  if (report && net_ctx)
  {
    ai_network_report r = {
      .model_name        = AI_NETWORK_MODEL_NAME,
      .model_signature   = AI_NETWORK_MODEL_SIGNATURE,
      .model_datetime    = AI_TOOLS_DATE_TIME,
      
      .compile_datetime  = AI_TOOLS_COMPILE_TIME,
      
      .runtime_revision  = ai_platform_runtime_get_revision(),
      .runtime_version   = ai_platform_runtime_get_version(),

      .tool_revision     = AI_TOOLS_REVISION_ID,
      .tool_version      = {AI_TOOLS_VERSION_MAJOR, AI_TOOLS_VERSION_MINOR,
                            AI_TOOLS_VERSION_MICRO, 0x0},
      .tool_api_version  = AI_STRUCT_INIT,

      .api_version            = ai_platform_api_get_version(),
      .interface_api_version  = ai_platform_interface_api_get_version(),
      
      .n_macc            = 12029716,
      .n_inputs          = 0,
      .inputs            = NULL,
      .n_outputs         = 0,
      .outputs           = NULL,
      .params            = AI_STRUCT_INIT,
      .activations       = AI_STRUCT_INIT,
      .n_nodes           = 0,
      .signature         = 0x0,
    };

    if (!ai_platform_api_get_network_report(network, &r)) return false;

    *report = r;
    return true;
  }
  return false;
}

AI_API_ENTRY
ai_bool ai_network_get_report(
  ai_handle network, ai_network_report* report)
{
  ai_network* net_ctx = AI_NETWORK_ACQUIRE_CTX(network);

  if (report && net_ctx)
  {
    ai_network_report r = {
      .model_name        = AI_NETWORK_MODEL_NAME,
      .model_signature   = AI_NETWORK_MODEL_SIGNATURE,
      .model_datetime    = AI_TOOLS_DATE_TIME,
      
      .compile_datetime  = AI_TOOLS_COMPILE_TIME,
      
      .runtime_revision  = ai_platform_runtime_get_revision(),
      .runtime_version   = ai_platform_runtime_get_version(),

      .tool_revision     = AI_TOOLS_REVISION_ID,
      .tool_version      = {AI_TOOLS_VERSION_MAJOR, AI_TOOLS_VERSION_MINOR,
                            AI_TOOLS_VERSION_MICRO, 0x0},
      .tool_api_version  = AI_STRUCT_INIT,

      .api_version            = ai_platform_api_get_version(),
      .interface_api_version  = ai_platform_interface_api_get_version(),
      
      .n_macc            = 12029716,
      .n_inputs          = 0,
      .inputs            = NULL,
      .n_outputs         = 0,
      .outputs           = NULL,
      .map_signature     = AI_MAGIC_SIGNATURE,
      .map_weights       = AI_STRUCT_INIT,
      .map_activations   = AI_STRUCT_INIT,
      .n_nodes           = 0,
      .signature         = 0x0,
    };

    if (!ai_platform_api_get_network_report(network, &r)) return false;

    *report = r;
    return true;
  }
  return false;
}

AI_API_ENTRY
ai_error ai_network_get_error(ai_handle network)
{
  return ai_platform_network_get_error(network);
}

AI_API_ENTRY
ai_error ai_network_create(
  ai_handle* network, const ai_buffer* network_config)
{
  return ai_platform_network_create(
    network, network_config, 
    &AI_NET_OBJ_INSTANCE,
    AI_TOOLS_API_VERSION_MAJOR, AI_TOOLS_API_VERSION_MINOR, AI_TOOLS_API_VERSION_MICRO);
}

AI_API_ENTRY
ai_handle ai_network_destroy(ai_handle network)
{
  return ai_platform_network_destroy(network);
}

AI_API_ENTRY
ai_bool ai_network_init(
  ai_handle network, const ai_network_params* params)
{
  ai_network* net_ctx = ai_platform_network_init(network, params);
  if (!net_ctx) return false;

  ai_bool ok = true;
  ok &= network_configure_weights(net_ctx, params);
  ok &= network_configure_activations(net_ctx, params);

  ok &= ai_platform_network_post_init(network);

  return ok;
}


AI_API_ENTRY
ai_i32 ai_network_run(
  ai_handle network, const ai_buffer* input, ai_buffer* output)
{
  return ai_platform_network_process(network, input, output);
}

AI_API_ENTRY
ai_i32 ai_network_forward(ai_handle network, const ai_buffer* input)
{
  return ai_platform_network_process(network, input, NULL);
}



#undef AI_NETWORK_MODEL_SIGNATURE
#undef AI_NET_OBJ_INSTANCE
#undef AI_TOOLS_DATE_TIME
#undef AI_TOOLS_COMPILE_TIME

