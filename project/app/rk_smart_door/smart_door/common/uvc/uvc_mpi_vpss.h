/*
 * Copyright (C) 2019 Rockchip Electronics Co., Ltd.
 *
 * This software is available to you under a choice of one of two
 * licenses.  You may choose to be licensed under the terms of the GNU
 * General Public License (GPL), available from the file
 * COPYING in the main directory of this source tree, or the
 * OpenIB.org BSD license below:
 *
 *     Redistribution and use in source and binary forms, with or
 *     without modification, are permitted provided that the following
 *     conditions are met:
 *
 *      - Redistributions of source code must retain the above
 *        copyright notice, this list of conditions and the following
 *        disclaimer.
 *
 *      - Redistributions in binary form must reproduce the above
 *        copyright notice, this list of conditions and the following
 *        disclaimer in the documentation and/or other materials
 *        provided with the distribution.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef __UVC_MPI_VPSS_H__
#define __UVC_MPI_VPSS_H__

#include "uvc_mpi_config.h"

typedef struct _uvcVpssChnCtx {
  RK_S32 group;
  RK_S32 channelId;
} UVC_VPSS_CHN_CTX_S;

typedef struct _rkVpssCfg {
  RK_U32 u32VpssChnCnt;
  VPSS_GRP_ATTR_S stGrpVpssAttr;
  VPSS_CHN_ATTR_S stVpssChnAttr[VPSS_MAX_CHN_NUM];
} VPSS_CFG_S;

typedef struct _rkMpiVpssCtx {
  UVC_VPSS_CHN_CTX_S stChnCtx;
  VPSS_CFG_S stVpssCfg;
} MPI_VPSS_CTX_S;

#ifdef __cplusplus
extern "C" {
#endif

RK_S32 uvc_vpss_config(UVC_MPI_CFG *uvcCfg, MpiVpssChannelType chnType);
RK_S32 uvc_vpss_config_crop(UVC_MPI_CFG uvcCfg, VPSS_CROP_INFO_S stCropInfo,
                            MpiVpssChannelType chnType);
RK_S32 uvc_vpss_start(UVC_MPI_CFG uvcCfg, MpiVpssChannelType chnType);
RK_S32 uvc_vpss_stop(UVC_MPI_CFG uvcCfg, MpiVpssChannelType chnType);
UVC_VPSS_CHN_CTX_S uvc_get_vpss_chn_ctx(UVC_MPI_CFG uvcCfg,
                                        MpiVpssChannelType chnType);

#ifdef __cplusplus
}
#endif

#endif