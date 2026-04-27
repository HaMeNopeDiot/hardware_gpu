RTL_NAME_FILE = rtl

IGNORE_WARNINGS = -Wno-ASCRANGE 	\
				  -Wno-UNUSEDPARAM

lint:
	verilator --lint-only -Wall -f $(RTL_NAME_FILE).f $(IGNORE_WARNINGS)

.PHONY: lint