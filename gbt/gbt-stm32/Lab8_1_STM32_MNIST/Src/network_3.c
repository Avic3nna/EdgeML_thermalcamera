/**
  ******************************************************************************
  * @file    network_3.c
  * @author  AST Embedded Analytics Research Platform
  * @date    Wed Dec  8 22:06:41 2021
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


#include "network_3.h"

#include "ai_platform_interface.h"
#include "ai_math_helpers.h"

#include "core_common.h"
#include "core_convert.h"

#include "layers.h"




#undef AI_NET_OBJ_INSTANCE
#define AI_NET_OBJ_INSTANCE g_network_3
 
#undef AI_NETWORK_3_MODEL_SIGNATURE
#define AI_NETWORK_3_MODEL_SIGNATURE     "623d1110922034570ee58b1c3857e551"

#ifndef AI_TOOLS_REVISION_ID
#define AI_TOOLS_REVISION_ID     ""
#endif

#undef AI_TOOLS_DATE_TIME
#define AI_TOOLS_DATE_TIME   "Wed Dec  8 22:06:41 2021"

#undef AI_TOOLS_COMPILE_TIME
#define AI_TOOLS_COMPILE_TIME    __DATE__ " " __TIME__

#undef AI_NETWORK_3_N_BATCHES
#define AI_NETWORK_3_N_BATCHES         (1)




/**  Array declarations section  **********************************************/
/* Array#0 */
AI_ARRAY_OBJ_DECLARE(
  X_output_array, AI_ARRAY_FORMAT_FLOAT|AI_FMT_FLAG_IS_IO,
  NULL, NULL, 512, AI_STATIC)

/* Array#1 */
AI_ARRAY_OBJ_DECLARE(
  label_output0_array, AI_ARRAY_FORMAT_FLOAT|AI_FMT_FLAG_IS_IO,
  NULL, NULL, 1, AI_STATIC)

/* Array#2 */
AI_ARRAY_OBJ_DECLARE(
  label_output1_array, AI_ARRAY_FORMAT_FLOAT|AI_FMT_FLAG_IS_IO,
  NULL, NULL, 2, AI_STATIC)

/* Array#3 */
AI_ARRAY_OBJ_DECLARE(
  label_coefficients_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 14, AI_STATIC)

/* Array#4 */
AI_ARRAY_OBJ_DECLARE(
  label_support_vectors_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 7168, AI_STATIC)

/* Array#5 */
AI_ARRAY_OBJ_DECLARE(
  label_rho_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1, AI_STATIC)

/* Array#6 */
AI_ARRAY_OBJ_DECLARE(
  label_classlabels_ints_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 2, AI_STATIC)

/* Array#7 */
AI_ARRAY_OBJ_DECLARE(
  label_vectors_per_class_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 2, AI_STATIC)

/**  Tensor declarations section  *********************************************/
/* Tensor #0 */
AI_TENSOR_OBJ_DECLARE(
  X_output, AI_STATIC,
  0, 0x0,
  AI_SHAPE_INIT(4, 1, 512, 1, 1), AI_STRIDE_INIT(4, 4, 4, 2048, 2048),
  1, &X_output_array, NULL)

/* Tensor #1 */
AI_TENSOR_OBJ_DECLARE(
  label_output0, AI_STATIC,
  1, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 1), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &label_output0_array, NULL)

/* Tensor #2 */
AI_TENSOR_OBJ_DECLARE(
  label_output1, AI_STATIC,
  2, 0x0,
  AI_SHAPE_INIT(4, 1, 2, 1, 1), AI_STRIDE_INIT(4, 4, 4, 8, 8),
  1, &label_output1_array, NULL)

/* Tensor #3 */
AI_TENSOR_OBJ_DECLARE(
  label_coefficients, AI_STATIC,
  3, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 14), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &label_coefficients_array, NULL)

/* Tensor #4 */
AI_TENSOR_OBJ_DECLARE(
  label_support_vectors, AI_STATIC,
  4, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 7168), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &label_support_vectors_array, NULL)

/* Tensor #5 */
AI_TENSOR_OBJ_DECLARE(
  label_rho, AI_STATIC,
  5, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 1), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &label_rho_array, NULL)

/* Tensor #6 */
AI_TENSOR_OBJ_DECLARE(
  label_classlabels_ints, AI_STATIC,
  6, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 2), AI_STRIDE_INIT(4, 1, 1, 1, 1),
  1, &label_classlabels_ints_array, NULL)

/* Tensor #7 */
AI_TENSOR_OBJ_DECLARE(
  label_vectors_per_class, AI_STATIC,
  7, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 2), AI_STRIDE_INIT(4, 1, 1, 1, 1),
  1, &label_vectors_per_class_array, NULL)



/**  Layer declarations section  **********************************************/


AI_TENSOR_CHAIN_OBJ_DECLARE(
  label_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &X_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &label_output0, &label_output1),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 5, &label_coefficients, &label_support_vectors, &label_rho, &label_classlabels_ints, &label_vectors_per_class),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  label_layer, 0,
  SVC_TYPE, 0x0, NULL,
  svc, forward_svc,
  &label_chain,
  NULL, &label_layer, AI_STATIC, 
  .kernel_type = AI_SVC_KERNEL_RBF, 
  .gamma = 5.805517196655273, 
  .coef0 = 0.0, 
  .degree = 3.0, 
  .proba_support = 0, 
  .has_classlabels_int = 1, 
)


AI_NETWORK_OBJ_DECLARE(
  AI_NET_OBJ_INSTANCE, AI_STATIC,
  AI_BUFFER_OBJ_INIT(AI_BUFFER_FORMAT_U8,
                     1, 1, 28740, 1,
                     NULL),
  AI_BUFFER_OBJ_INIT(AI_BUFFER_FORMAT_U8,
                     1, 1, 0, 1,
                     NULL),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_NETWORK_3_IN_NUM, &X_output),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_NETWORK_3_OUT_NUM, &label_output0, &label_output1),
  &label_layer, 0, NULL)





AI_DECLARE_STATIC
ai_bool network_3_configure_weights(
  ai_network* net_ctx, const ai_network_params* params)
{
  AI_ASSERT(net_ctx)
  AI_UNUSED(net_ctx)

  ai_ptr weights_map[1] = AI_C_ARRAY_INIT;

  if (ai_platform_get_weights_map(weights_map, 1, params)) {
    /* Updating weights with array addresses */
    
    label_coefficients_array.format |= AI_FMT_FLAG_CONST;
    label_coefficients_array.data = AI_PTR(weights_map[0] + 0);
    label_coefficients_array.data_start = AI_PTR(weights_map[0] + 0);
    label_support_vectors_array.format |= AI_FMT_FLAG_CONST;
    label_support_vectors_array.data = AI_PTR(weights_map[0] + 56);
    label_support_vectors_array.data_start = AI_PTR(weights_map[0] + 56);
    label_rho_array.format |= AI_FMT_FLAG_CONST;
    label_rho_array.data = AI_PTR(weights_map[0] + 28728);
    label_rho_array.data_start = AI_PTR(weights_map[0] + 28728);
    label_classlabels_ints_array.format |= AI_FMT_FLAG_CONST;
    label_classlabels_ints_array.data = AI_PTR(weights_map[0] + 28732);
    label_classlabels_ints_array.data_start = AI_PTR(weights_map[0] + 28732);
    label_vectors_per_class_array.format |= AI_FMT_FLAG_CONST;
    label_vectors_per_class_array.data = AI_PTR(weights_map[0] + 28736);
    label_vectors_per_class_array.data_start = AI_PTR(weights_map[0] + 28736);
    return true;
  }
  return false;
}


/**  PUBLIC APIs SECTION  *****************************************************/
AI_DEPRECATED
AI_API_ENTRY
ai_bool ai_network_3_get_info(
  ai_handle network, ai_network_report* report)
{
  ai_network* net_ctx = AI_NETWORK_ACQUIRE_CTX(network);

  if (report && net_ctx)
  {
    ai_network_report r = {
      .model_name        = AI_NETWORK_3_MODEL_NAME,
      .model_signature   = AI_NETWORK_3_MODEL_SIGNATURE,
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
      
      .n_macc            = 71680,
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
ai_bool ai_network_3_get_report(
  ai_handle network, ai_network_report* report)
{
  ai_network* net_ctx = AI_NETWORK_ACQUIRE_CTX(network);

  if (report && net_ctx)
  {
    ai_network_report r = {
      .model_name        = AI_NETWORK_3_MODEL_NAME,
      .model_signature   = AI_NETWORK_3_MODEL_SIGNATURE,
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
      
      .n_macc            = 71680,
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
ai_error ai_network_3_get_error(ai_handle network)
{
  return ai_platform_network_get_error(network);
}

AI_API_ENTRY
ai_error ai_network_3_create(
  ai_handle* network, const ai_buffer* network_config)
{
  return ai_platform_network_create(
    network, network_config, 
    &AI_NET_OBJ_INSTANCE,
    AI_TOOLS_API_VERSION_MAJOR, AI_TOOLS_API_VERSION_MINOR, AI_TOOLS_API_VERSION_MICRO);
}

AI_API_ENTRY
ai_handle ai_network_3_destroy(ai_handle network)
{
  return ai_platform_network_destroy(network);
}

AI_API_ENTRY
ai_bool ai_network_3_init(
  ai_handle network, const ai_network_params* params)
{
  ai_network* net_ctx = ai_platform_network_init(network, params);
  if (!net_ctx) return false;

  ai_bool ok = true;
  ok &= network_3_configure_weights(net_ctx, params);

  ok &= ai_platform_network_post_init(network);

  return ok;
}


AI_API_ENTRY
ai_i32 ai_network_3_run(
  ai_handle network, const ai_buffer* input, ai_buffer* output)
{
  return ai_platform_network_process(network, input, output);
}

AI_API_ENTRY
ai_i32 ai_network_3_forward(ai_handle network, const ai_buffer* input)
{
  return ai_platform_network_process(network, input, NULL);
}



#undef AI_NETWORK_3_MODEL_SIGNATURE
#undef AI_NET_OBJ_INSTANCE
#undef AI_TOOLS_DATE_TIME
#undef AI_TOOLS_COMPILE_TIME

