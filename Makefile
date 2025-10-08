# Iridium library Makefile

##############################################
################ CONFIGURATION ###############
##############################################

# Software Version
MAJOR = 0
MINOR = 1
PATCH = 0

##############################################
################### MAKE #####################
##############################################

LIB_NAME = iridium

# Main recipe
all : build

##############################################
################## INCLUDES ##################
##############################################

include gen/paths.mk
include gen/settings.mk
include gen/build.mk
include gen/verification.mk