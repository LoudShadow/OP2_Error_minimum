APP_NAME := DemoOP2

APP_ENTRY := $(APP_NAME).cpp
APP_ENTRY_MPI := $(APP_NAME).cpp

include ${OP2_INSTALL_PATH}/makefiles/common.mk
include ${OP2_INSTALL_PATH}/makefiles/c_app.mk