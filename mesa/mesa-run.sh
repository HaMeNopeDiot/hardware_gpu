#!/bin/sh

MESA=$HOME/mesa \
LD_LIBRARY_PATH=$MESA/lib64:$MESA/lib:$LD_LIBRARY_PATH \
LIBGL_DRIVERS_PATH=$MESA/lib64/dri:$MESA/lib/dri \
VK_ICD_FILENAMES=$MESA/share/vulkan/icd.d/lvp_icd.x86_64.json:$MESA/share/vulkan/icd.d/lvp_icd.x86_64.json \
LIBVA_DRIVERS_PATH=$MESA/lib64/dri:$MESA/lib/dri \
    exec "$@"
