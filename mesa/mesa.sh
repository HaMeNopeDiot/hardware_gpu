#!/bin/sh

MESA=$HOME/mesa

export LD_LIBRARY_PATH=$MESA/lib64:$MESA/lib:$LD_LIBRARY_PATH
export LIBGL_DRIVERS_PATH=$MESA/lib64/dri:$MESA/lib/dri
export VK_ICD_FILENAMES=$MESA/share/vulkan/icd.d/lvp_icd.x86_64.json:$MESA/share/vulkan/icd.d/lvp_icd.x86_64.json
export LIBVA_DRIVERS_PATH=$MESA/lib64/dri:$MESA/lib/dri
