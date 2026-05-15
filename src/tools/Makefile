
# ===============================================================================
# WARNING! You should leave this Makefile alone probably
#          To configure the build, you can edit config.mk, or else you export the 
#          equivalent shell variables prior to invoking 'make' to adjust the
#          build configuration. 
# ===============================================================================

include ../../config.mk

# ===============================================================================
# Specific build targets and recipes below...
# ===============================================================================

TOOLS = $(BIN)/iers-fetch

BIN ?= ../../bin
LIB ?= ../../lib

# Our own include directory
CPPFLAGS += -I../../include

# We'll need math functions to link
LDFLAGS += -lm -lcurl


# Shared libraries (versioned and unversioned)
.PHONY: all
all: $(TOOLS)

# Remove intermediates
.PHONY: clean
clean:
	@rm -rf $(OBJ)

# Remove all generated files
.PHONY: distclean
distclean: clean
	@rm -rf $(TOOLS)


# ----------------------------------------------------------------------------
# The nitty-gritty stuff below
# ----------------------------------------------------------------------------

$(BIN)/iers-fetch: iers-fetch.c | $(BIN)
	$(CC) -o $@ $(CPPFLAGS) -Iinclude $(CFLAGS) $< $(LDFLAGS) -L$(LIB) -lsupernovas

# ===============================================================================
# Generic targets and recipes below...
# ===============================================================================

include ../../build.mk
