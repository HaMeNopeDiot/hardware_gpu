RTL_NAME_FILE = rtl

IGNORE_WARNINGS =

LINT_DEFINES = -DLINT=1

lint:
	verilator --lint-only -Wall -f $(RTL_NAME_FILE).f $(IGNORE_WARNINGS) $(LINT_DEFINES)

.PHONY: lint

tb:
	cd tb/ && make && cd ../

.PHONY: tb

rebuild:
	cd tb/ && make clean && make && cd ../

.PHONY: rebuild
