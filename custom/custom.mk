include tools/scripts/config.mk

CUSTOM_DIR := custom

#application
APPLACTION_DIR := custom/applaction
OC_FILES +=  $(APPLACTION_DIR)/app.c
OC_FILES +=  $(APPLACTION_DIR)/main.c
INC      += -I'$(APPLACTION_DIR)'
